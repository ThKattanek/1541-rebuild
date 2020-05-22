/* Name: main.c
* Project: 1541-rebuild
* Author: Thorsten Kattanek
* Copyright: (c) 2020 by Thorsten Kattanek <thorsten.kattanek@gmx.de>
* License: GPL 2
*/

/// CPU Clock
#ifndef F_CPU
#define F_CPU 24000000UL
#endif

#include "./main.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

enum  MENU_IDS{M_BACK, M_IMAGE, M_SETTINGS, M_INFO, M_BACK_IMAGE, M_INSERT_IMAGE, M_REMOVE_IMAGE, M_WP_IMAGE, M_NEW_IMAGE, M_SAVE_IMAGE, \
               M_DEBUG_LED};

MENU_STRUCT main_menu;
MENU_STRUCT image_menu;
MENU_STRUCT settings_menu;

int main(void)
{
    reset();                // Alles initialisieren

    /// Menüs einrichten
    /// Hauptmenü
    MENU_ENTRY main_menu_entrys[] = {{"Back",M_BACK},{"Disk Image",M_IMAGE},{"Settings",M_SETTINGS},{"Info",M_INFO}};
    /// Image Menü
    MENU_ENTRY image_menu_entrys[] = {{"Back",M_BACK_IMAGE}, {"Insert Image",M_INSERT_IMAGE}, {"Remove Image",M_REMOVE_IMAGE}, {"Write Protect",M_WP_IMAGE,ENTRY_ONOFF,1}, {"New Image",M_NEW_IMAGE}, {"Save Image",M_SAVE_IMAGE}};
    /// Setting Menü
    MENU_ENTRY settings_menu_entrys[] = {{"Back",M_BACK_IMAGE}, {"Debug LED",M_DEBUG_LED,ENTRY_ONOFF,0}};

    main_menu.lcd_cursor_char = 2;  // 126 Standard Pfeil
    menu_init(&main_menu, main_menu_entrys, 4,4);

    image_menu.lcd_cursor_char = 2;  // 126 Standard Pfeil
    menu_init(&image_menu, image_menu_entrys, 6,4);

    settings_menu.lcd_cursor_char = 2;  // 126 Standard Pfeil
    menu_init(&settings_menu, settings_menu_entrys, 2,4);

    current_menu = &main_menu;

    // Zeichen für Menü More Top setzen
    uint8_t char00[] = {4,14,31,0,0,0,0,0};
    lcd_generatechar(0, char00);

    // Zeichen für Menü More Down setzen
    uint8_t char01[] = {0,0,0,0,31,14,4,0};
    lcd_generatechar(1, char01);

    // Zeichen für Menü Position setzen
    uint8_t arrow_char[] = {0,4,6,31,6,4,0,0};
    lcd_generatechar(2, arrow_char);

    //// MAIN LOOP /////
    while(1)
    {
        check_stepper_signals();
        check_motor_signal();
        update_gui();
    }
}

/////////////////////////////////////////////////////////////////////

void reset()
{
    // Debug LED initisalieren
    init_debug_led1();

    // SOE GateArray initialisieren
    soe_gatearry_init();
    soe_gatearry_lo();      // Damit die GateArray das Signal Byte_Ready auf Hi setzt
                            // Somit stört mich das Signal nicht mehr und ich muss Byte_Ready
                            // Nur auf Lo ziehen (hi = hiz und lo = gnd)

    // WPS PIN Enable
    endable_wps_port(1);

    // LCD Display intialisieren
    lcd_init();

    // Startmeldung ausgeben
    show_start_message();

    // Stepper Initialisieren
    init_stepper();

    // Motor Initialisieren
    init_motor();

    // Steursignale BYTE_READY, SYNC und SOE Initialisieren
    init_controll_signals();

    // Image Remove
    remove_image();

    // Timer0 --> GCR senden
    init_timer0();

    // Tasten Initialisieren
    init_keys();

    // Timer2 --> wird alle 1ms aufgerufen
    // z.B. zu Tasten entprellen
    init_timer2();

    // Meldung ausgeben, das auf SD Karte gewartet wird
    lcd_setcursor(0,2);
    lcd_string("Wait for SD-Karte...");

    // SD Karte initialisieren
    // Partition und Filesystem öffnen
    // Warten bis alles O.K. ist
    while(init_sd_card())
    {
        _delay_ms(1000);
    }

    // GUI Mode festlegen
    set_gui_mode(GUI_INFO_MODE);

    // Interrupts erlauben
    sei();

    debug_led1_off();
}

/////////////////////////////////////////////////////////////////////

void check_stepper_signals()
{
    // Auf Steppermotor aktivität prüfen
    // und auswerten
    if(stepper_signal_r_pos != stepper_signal_w_pos)    // Prüfen ob sich was neues im Ringpuffer für die Steppersignale befindet
    {
            uint8_t stepper = stepper_signal_puffer[stepper_signal_r_pos]>>2 | stepper_signal_puffer[stepper_signal_r_pos-1];
            stepper_signal_r_pos++;

        switch(stepper)
        {
        case 0x30: case 0x40: case 0x90: case 0xE0:
        // DEC
        stepper_dec();
            stepper_signal_time = 0;
            stepper_signal = 1;
        break;

        case 0x10: case 0x60: case 0xB0: case 0xC0:
        // INC
        stepper_inc();
            stepper_signal_time = 0;
            stepper_signal = 1;
        break;
        }
    }
    else if(stepper_signal && (stepper_signal_time >= STEPPER_DELAY_TIME))
    {
        stepper_signal = 0;

        if(!(akt_half_track & 0x01))
        {
            stop_timer0();

            // Geschwindigkeit setzen
            OCR0A = timer0_orca0[d64_track_zone[akt_half_track>>1]];
            akt_track_pos = 0;

            if(track_is_written == 1)
            {
                no_byte_ready_send = 1;

                track_is_written = 0;
                write_disk_track(fd,akt_image_type,old_half_track>>1,gcr_track, &gcr_track_length);

                read_disk_track(fd,akt_image_type,akt_half_track>>1,gcr_track, &gcr_track_length);
                old_half_track = akt_half_track;    // Merken um evtl. dort zurück zu schreiben

                no_byte_ready_send = 0;
            }
            else
            {
                read_disk_track(fd,akt_image_type,akt_half_track>>1,gcr_track, &gcr_track_length);
                old_half_track = akt_half_track;    // Merken um evtl. dort zurück zu schreiben
            }
            start_timer0();
        }
    }
}

/////////////////////////////////////////////////////////////////////

void check_motor_signal()
{
    if(!get_motor_status())
    {
        // Sollte der aktuelle Track noch veränderungen haben so wird hier erstmal gesichert.
        if(track_is_written == 1)
        {
            stop_timer0();
            no_byte_ready_send = 1;
            track_is_written = 0;
            write_disk_track(fd,akt_image_type,old_half_track>>1,gcr_track, &gcr_track_length);
            no_byte_ready_send = 0;
            start_timer0();
        }
    }
}

/////////////////////////////////////////////////////////////////////

uint8_t get_key_from_buffer()
{
    if(key_buffer_r_pos != key_buffer_w_pos)
    {
        uint8_t val = key_buffer[key_buffer_r_pos++];
        key_buffer_r_pos &= 0x0f;
        return  val;
    }
    else
        return NO_KEY;
}

/////////////////////////////////////////////////////////////////////

void update_gui()
{
    static uint8_t old_half_track = 0;
    static uint8_t old_motor_status = 0;

    uint8_t key_code = get_key_from_buffer();

    switch (current_gui_mode)
    {
    case GUI_INFO_MODE:

        if(key_code == KEY2_DOWN)
            set_gui_mode(GUI_MENU_MODE);

        if(old_half_track != akt_half_track)
        {
            lcd_setcursor(7,1);
            lcd_string("   ");
            lcd_setcursor(7,1);
            sprintf (byte_str,"%d",akt_half_track >> 1);
            lcd_string(byte_str);
        }
        old_half_track = akt_half_track;

        if(old_motor_status != get_motor_status())
        {
            lcd_setcursor(7,2);
            if(get_motor_status())
                lcd_string("On ");
            else
                lcd_string("Off");
        }
        old_motor_status = get_motor_status();

        break;

    case GUI_MENU_MODE:
        check_menu_events(menu_update(current_menu, key_code));
        break;

    case GUI_FILE_BROWSER:
        select_image(key_code);
        break;

    default:
        break;
    }
}

/////////////////////////////////////////////////////////////////////

void check_menu_events(uint16_t menu_event)
{
    uint8_t command = menu_event >> 8;
    uint8_t value = menu_event & 0xff;

    switch(command)
    {
    case MC_SELECT_ENTRY:
        switch(value)
        {
        /// Main Menü
        case M_BACK:
            set_gui_mode(GUI_INFO_MODE);
            break;
        case M_IMAGE:
            current_menu = &image_menu;
            menu_refresh(&image_menu);
            break;
        case M_SETTINGS:
            current_menu = &settings_menu;
            menu_refresh(&settings_menu);
            break;
        case M_INFO:
            show_start_message();
            menu_refresh(&main_menu);
            break;

        /// Settings Menü
        case M_DEBUG_LED:
            if(menu_get_entry_var1(&settings_menu, M_DEBUG_LED))
                debug_led1_on();
            else
                debug_led1_off();
            menu_refresh(&settings_menu);
            break;

        /// Image Menü
        case M_BACK_IMAGE:
            current_menu = &main_menu;
            menu_refresh(&main_menu);
            break;
        case M_INSERT_IMAGE:
            set_gui_mode(GUI_FILE_BROWSER);
            break;
        case M_REMOVE_IMAGE:
            remove_image();
            set_gui_mode(GUI_INFO_MODE);
            break;
        case M_WP_IMAGE:
            if(akt_image_type != G64_IMAGE)
                menu_set_entry_var1(&image_menu, M_WP_IMAGE, 1);

            if(menu_get_entry_var1(&image_menu, M_WP_IMAGE))
                set_write_protection(1);
            else
                set_write_protection(0);
            menu_refresh(&image_menu);
            break;
        }
        break;
    }
}

/////////////////////////////////////////////////////////////////////

void set_gui_mode(uint8_t gui_mode)
{
    current_gui_mode = gui_mode;
    switch(gui_mode)
    {
    case GUI_INFO_MODE:
        lcd_clear();

        lcd_setcursor(0,1);
        lcd_string("Track:");

        lcd_setcursor(7,1);
        sprintf (byte_str,"%d",akt_half_track >> 1);
        lcd_string(byte_str);

        lcd_setcursor(0,2);
        lcd_string("Motor:");

        if(get_motor_status())
            lcd_string(" On ");
        else
            lcd_string(" Off");

        lcd_setcursor(12,1);
        lcd_string("WP:");

        if(floppy_wp)
            lcd_string(" On");
        else
            lcd_string(" Off");

        if(is_image_mount)
        {
            lcd_setcursor(0,4);
            lcd_string(image_filename);
        }

        lcd_setcursor(2,4);
        if(!is_image_mount)
            lcd_string("No Image Mounted");

        break;
    case GUI_MENU_MODE:
        menu_refresh(current_menu);
        break;
    case GUI_FILE_BROWSER:
        lcd_clear();
        view_dir_entry(dir_pos,&file_entry);
        break;
    default:
        break;
    }
}

/////////////////////////////////////////////////////////////////////

void select_image(uint8_t key)
{
    /////////////////////////////////////////////////////////////////////////////////////////
    //// Image Auswahl

    switch (key)
    {
    case KEY0_DOWN:
        if(dir_pos > 0)
        {
            dir_pos--;
        }
        view_dir_entry(dir_pos,&file_entry);
        break;
    case KEY1_DOWN:
        dir_pos++;
        if(!view_dir_entry(dir_pos,&file_entry)) dir_pos--;
        break;
    case KEY2_DOWN:
        stop_timer0();
        no_byte_ready_send = 1;

        close_disk_image(fd);

        fd = open_disk_image(fs, &file_entry, &akt_image_type);

        if(!fd)
        {
            is_image_mount = 0;
            return ;
        }

        read_disk_track(fd,akt_image_type,akt_half_track>>1,gcr_track, &gcr_track_length);
        akt_track_pos = 0;

        no_byte_ready_send = 0;
        start_timer0();

        is_image_mount = 1;
        send_disk_change();

        if(floppy_wp)
            menu_set_entry_var1(&image_menu, M_WP_IMAGE, 1);
        else
            menu_set_entry_var1(&image_menu, M_WP_IMAGE, 0);

        set_gui_mode(GUI_INFO_MODE);

        break;
    default:
        break;
    }
}

/////////////////////////////////////////////////////////////////////

void init_debug_led1()
{
    DEBUG_LED1_DDR |= 1 << PB2;
    debug_led1_on();
}

/////////////////////////////////////////////////////////////////////

int8_t init_sd_card(void)
{
    // LCD Fehlermeldung löschen
    lcd_setcursor( 0, 4);
    lcd_string("                    ");
    lcd_setcursor( 0, 4);

    set_sleep_mode(SLEEP_MODE_IDLE);

    // SD Karte initialisieren
    if(!sd_raw_init())
    {
        lcd_setcursor( 0, 4);
        lcd_string("err: sd_raw_init");
        return 1;
    }

    // Eine Partition öffnen (die erste)
    partition = partition_open(sd_raw_read,sd_raw_read_interval,sd_raw_write,sd_raw_write_interval,0);
    if(!partition)
    {
        partition = partition_open(sd_raw_read,sd_raw_read_interval,sd_raw_write,sd_raw_write_interval,-1);
        if(!partition)
        {
            lcd_setcursor( 0, 4);
            lcd_string("err: partition_open");
            return 2;
        }
    }

    // FAT16/32 Filesystem versuchen zu öffnen

    lcd_string("*");

    fs = fat_open(partition);

    lcd_string("*");

    if(!fs)
    {
        lcd_setcursor( 0, 4);
        lcd_string("err: fat_open");
        return 3;
    }

    // Root Verzeichnis öffnen
    fat_get_dir_entry_of_path(fs, "/", &directory);
    dd = fat_open_dir(fs, &directory);
    if(!dd)
    {
        lcd_setcursor( 0, 4);
        lcd_string("err: fat_open_root");
        return 4;
    }

    return 0;
}

/////////////////////////////////////////////////////////////////////

void show_start_message(void)
{
    lcd_clear();
    lcd_setcursor( 1, 1);
    lcd_string("-- 1541-rebuild --");
    lcd_setcursor( 2,2);
    lcd_string("Firmware:  ");
    lcd_string(VERSION);
    lcd_setcursor( 0,4);
    lcd_string("by thorsten kattanek");
    _delay_ms(START_MESSAGE_TIME);
    lcd_clear();
}

/////////////////////////////////////////////////////////////////////

void init_stepper(void)
{
    // Stepper PINs als Eingang schalten
    STP_DDR &= ~(1<<STP0 | 1<<STP1);
    akt_half_track = INIT_TRACK << 1;

    // Pin Change Ineterrupt für beide PIN's aktivieren
    PCICR = 0x01;   // Enable PCINT0..7
    PCMSK0 = 0xc0;  // Set Mask Register für PCINT6 und PCINT7
}

/////////////////////////////////////////////////////////////////////

void stepper_inc(void)
{            
    if(akt_half_track == 83) return;
    akt_half_track++;
}

/////////////////////////////////////////////////////////////////////

void stepper_dec(void)
{
    if(akt_half_track == 2) return;
    akt_half_track--;
}

/////////////////////////////////////////////////////////////////////

void init_motor()
{
    // Als Eingang schalten
    MTR_DDR &= ~(1<<MTR);
}

/////////////////////////////////////////////////////////////////////

void init_controll_signals(void)
{
    // Als Ausgang schalten
    //DDxn = 0 , PORTxn = 0 --> HiZ
    //DDxn = 1 , PORTxn = 0 --> Output Low (Sink)
    BYTE_READY_DDR &= ~(1<<BYTE_READY);             // Byte Ready auf HiZ
    BYTE_READY_PORT &= ~(1<<BYTE_READY);

    SYNC_DDR |= 1<<SYNC;

    // Als Eingang schalten
    DATA_DDR = 0x00;
    SOE_DDR &= ~(1<<SOE);
    SO_DDR &= ~(1<<SO);
}

/////////////////////////////////////////////////////////////////////

void init_timer0(void)
{
    TCCR0A = (1<<WGM01);    // CTC Modus
    TCCR0B |= (1<<CS01);    // Prescaler 8

    OCR0A = timer0_orca0[d64_track_zone[akt_half_track>>1]];
    start_timer0();
}

/////////////////////////////////////////////////////////////////////

void start_timer0(void)
{
    // Compare Interrupt erlauben
    TIMSK0 |= (1<<OCIE0A);
}

/////////////////////////////////////////////////////////////////////

void stop_timer0(void)
{
    // Compare Interrupt verhindern
    TIMSK0 &= ~(1<<OCIE0A);
}

/////////////////////////////////////////////////////////////////////

void init_timer2(void)
{
    TCCR2A = (1<<WGM21);    // CTC Modus
    TCCR2B |= (1<<CS20) | (1<<CS21) | (1<<CS22);    // Prescaler 1024

    // alle 10 ms aufrufen --> 100Hz
    // ((24000000/1024)/100) = 234

    OCR2A = 234-1;

    start_timer2();
}
/////////////////////////////////////////////////////////////////////

void start_timer2(void)
{
    // Compare Interrupt erlauben
    TIMSK2 |= (1<<OCIE2A);
}

/////////////////////////////////////////////////////////////////////

void stop_timer2(void)
{
    // Compare Interrupt verhindern
    TIMSK2 &= ~(1<<OCIE2A);
}

/////////////////////////////////////////////////////////////////////

void init_keys(void)
{
    // Entsprechende Ports auf Eingangschalten
    KEY0_DDR &= ~(1<<KEY0);
    KEY1_DDR &= ~(1<<KEY1);
    KEY2_DDR &= ~(1<<KEY2);

    // Interne Pullup Setzen
    KEY0_PORT |= 1<<KEY0;
    KEY1_PORT |= 1<<KEY1;
    KEY2_PORT |= 1<<KEY2;
}

/////////////////////////////////////////////////////////////////////

void soe_gatearry_init(void)
{
    //DDxn = 1 , PORTxn = 0 --> Lo
    //DDxn = 1 , PORTxn = 1 --> Hi

    SOE_GATEARRAY_DDR |= 1<<SOE_GATEARRAY;
    soe_gatearry_lo();
}

/////////////////////////////////////////////////////////////////////

void soe_gatearry_hi(void)
{
    SOE_GATEARRAY_PORT |= 1<<SOE_GATEARRAY;
}

/////////////////////////////////////////////////////////////////////

void soe_gatearry_lo(void)
{
    SOE_GATEARRAY_PORT &= ~(1<<SOE_GATEARRAY);
}

/////////////////////////////////////////////////////////////////////

int8_t view_dir_entry(uint16_t entry_start, struct fat_dir_entry_struct* dir_entry)
{
    uint16_t entry_pos = 0;

    fat_reset_dir(dd);
    while(fat_read_dir(dd, dir_entry) && (entry_pos < entry_start))
    {
	entry_pos++;
    }

    if((entry_pos == entry_start) && (dir_entry->attributes != FAT_ATTRIB_VOLUME))
    {
	if(dir_entry->attributes == FAT_ATTRIB_DIR)
	{
        image_filename[0] = '*';
        strcpy(image_filename+1, dir_entry->long_name);
        uint8_t len = strlen(image_filename);
	    if(len > 19)
        image_filename[32] = 0;
	    else
	    {
		for(int i=len; i<20; i++)
            image_filename[i] = ' ';
        image_filename[32] = 0;
	    }

	    lcd_setcursor(0,1);
        lcd_string(image_filename);
	}
	else
	{
        strcpy(image_filename, dir_entry->long_name);
        uint8_t len = strlen(image_filename);
	    if(len > 20)
        image_filename[32] = 0;
	    else
	    {
		for(int i=len; i<20; i++)
            image_filename[i] = ' ';
        image_filename[32] = 0;
	    }

	    lcd_setcursor(0,1);
        lcd_string(image_filename);
	}
	    return 1;

    }
    return 0;
}

/////////////////////////////////////////////////////////////////////

struct fat_file_struct* open_disk_image(struct fat_fs_struct* fs ,struct fat_dir_entry_struct* file_entry, uint8_t* image_type)
{
    if(strlen(file_entry->long_name) < 4) return NULL;

    struct fat_file_struct* fd = NULL;
    char extension[5];
    int i;

    // Extension überprüfen --> g64 oder d64
    strcpy(extension, file_entry->long_name+(strlen(file_entry->long_name)-4));

    i=0;
    while(extension[i] != 0)
    {
        extension[i] = tolower(extension[i]);
        i++;
    }

    fd = fat_open_file(fs, file_entry);
    if(!fd)
    {
        *image_type = UNDEF_IMAGE;
        return fd;
    }

    if(!strcmp(extension,".g64"))
    {
        // Laut Extension ein G64
        *image_type = G64_IMAGE;
        open_g64_image(fd);
        set_write_protection(1);
    }
    else if(!strcmp(extension,".d64"))
    {
        // Laut Extensions ein D64
        *image_type = D64_IMAGE;
        open_d64_image(fd);
        set_write_protection(1);
    }
    else
    {
        // Nicht unterstützt
        lcd_setcursor( 0, 3);
        lcd_string("Not Supported");
        fat_close_file(fd);
        fd = NULL;
        *image_type = UNDEF_IMAGE;
    }

    return fd;
}

/////////////////////////////////////////////////////////////////////

void close_disk_image(struct fat_file_struct* fd)
{
    fat_close_file(fd);
    fd = NULL;
}

/////////////////////////////////////////////////////////////////////

int8_t open_g64_image(struct fat_file_struct* fd)
{
    return 0;
}

/////////////////////////////////////////////////////////////////////

int8_t open_d64_image(struct fat_file_struct* fd)
{
    return 0;
}

/////////////////////////////////////////////////////////////////////

int8_t read_disk_track(struct fat_file_struct* fd, uint8_t image_type, uint8_t track_nr, uint8_t* track_buffer, uint16_t *gcr_track_length)
{
    uint8_t id1 = 0;
    uint8_t id2 = 0;

    uint8_t* P;
    uint8_t buffer[4];
    uint8_t d64_sector_puffer[D64_SECTOR_SIZE];
    uint8_t is_read = 0;
    int32_t offset = 0;
    uint8_t sector_nr;
    uint8_t SUM;

    switch(image_type)
    {
    ///////////////////////////////////////////////////////////////////////////
    case G64_IMAGE:	// G64
	/// Track18 eines G64 einlesen

	offset = (int32_t)track_nr - 1;
	offset = (offset << 3) + 0x0c;

	if(fat_seek_file(fd,&offset,FAT_SEEK_SET))
	{
        if(fat_read_file(fd, (uint8_t*)&offset, 4))
	    {
            if(fat_seek_file(fd,&offset,FAT_SEEK_SET))
            {
                        fat_read_file(fd, (uint8_t*)gcr_track_length, 2);
                        fat_read_file(fd, track_buffer, *gcr_track_length);

                is_read = 1;
            }
	    }
	}
	break;

    ///////////////////////////////////////////////////////////////////////////
    case D64_IMAGE:	// D64

	offset = d64_track_offset[track_nr];

	if(fat_seek_file(fd,&offset,FAT_SEEK_SET))
	{
	    P = track_buffer;

	    for(sector_nr=0;sector_nr<d64_sector_count[track_nr];sector_nr++)
	    {
            fat_read_file(fd, d64_sector_puffer, D64_SECTOR_SIZE);

            *P++ = 0xFF;								// SYNC
            *P++ = 0xFF;								// SYNC
            *P++ = 0xFF;								// SYNC
            *P++ = 0xFF;								// SYNC
            *P++ = 0xFF;								// SYNC

            buffer[0] = 0x08;							// Header Markierung
            buffer[1] = sector_nr ^ track_nr ^ id2 ^ id1;				// Checksumme
            buffer[2] = sector_nr;
            buffer[3] = track_nr;
            ConvertToGCR(buffer, P);
            buffer[0] = id2;
            buffer[1] = id1;
            buffer[2] = 0x0F;
            buffer[3] = 0x0F;
            ConvertToGCR(buffer, P+5);
            P += 10;

            // GAP Bytes als Lücke
            memset(P, 0x55, HEADER_GAP_BYTES);
            P += HEADER_GAP_BYTES;

            // SYNC
            *P++ = 0xFF;								// SYNC
            *P++ = 0xFF;								// SYNC
            *P++ = 0xFF;								// SYNC
            *P++ = 0xFF;								// SYNC
            *P++ = 0xFF;								// SYNC

            buffer[0] = 0x07;							// Data mark
            SUM = buffer[1] = d64_sector_puffer[0];
            SUM ^= buffer[2] = d64_sector_puffer[1];
            SUM ^= buffer[3] = d64_sector_puffer[2];
            ConvertToGCR(buffer, P);
            P += 5;

            for (int i=3; i<255; i+=4)
            {
                SUM ^= buffer[0] = d64_sector_puffer[i];
                SUM ^= buffer[1] = d64_sector_puffer[i+1];
                SUM ^= buffer[2] = d64_sector_puffer[i+2];
                SUM ^= buffer[3] = d64_sector_puffer[i+3];
                ConvertToGCR(buffer, P);
                P += 5;
            }

            SUM ^= buffer[0] = d64_sector_puffer[255];
            buffer[1] = SUM;							// Checksum
            buffer[2] = 0;
            buffer[3] = 0;
            ConvertToGCR(buffer, P);
            P += 5;

            // GCR Bytes als Lücken auffüllen (sorgt für eine Gleichverteilung)
            uint8_t gap_size = d64_sector_gap[d64_track_zone[track_nr]];
            memset(P, 0x55, gap_size);
            P += gap_size;

            //*gcr_track_length = d64_track_length[d64_track_zone[track_nr]];
            *gcr_track_length = P - gcr_track;
	    }
	}
	break;
    }
    return is_read;
}

/////////////////////////////////////////////////////////////////////

void write_disk_track(struct fat_file_struct *fd, uint8_t image_type, uint8_t track_nr, uint8_t* track_buffer, uint16_t *gcr_track_length)
{
    int32_t offset = 0;

    switch(image_type)
    {
    ///////////////////////////////////////////////////////////////////////////
    case G64_IMAGE:	// G64
        /// Track18 eines G64 einlesen

        offset = (int32_t)track_nr - 1;
        offset = (offset << 3) + 0x0c;

        if(fat_seek_file(fd,&offset,FAT_SEEK_SET))
        {
            if(fat_read_file(fd, (uint8_t*)&offset, 4))
            {
                offset += 2;
                if(fat_seek_file(fd,&offset,FAT_SEEK_SET))
                {
                    fat_write_file(fd, track_buffer, *gcr_track_length);
                }
            }
        }
        break;

    ///////////////////////////////////////////////////////////////////////////
    case D64_IMAGE:	// D64
        break;
    }
}

/////////////////////////////////////////////////////////////////////

void remove_image()
{
    is_image_mount = 0;
    akt_image_type = UNDEF_IMAGE;
    set_write_protection(1);
    menu_set_entry_var1(&image_menu, M_WP_IMAGE, 1);
    send_disk_change();
}

/////////////////////////////////////////////////////////////////////

inline void ConvertToGCR(uint8_t *source_buffer, uint8_t *destination_buffer)
{
    const static uint8_t GCR_TBL[16] = {0x0a, 0x0b, 0x12, 0x13, 0x0e, 0x0f, 0x16, 0x17,0x09, 0x19, 0x1a, 0x1b, 0x0d, 0x1d, 0x1e, 0x15};
    uint16_t tmp;

    tmp = (GCR_TBL[*source_buffer >> 4] << 5) | GCR_TBL[*source_buffer & 15];
    *destination_buffer++ = tmp >> 2;
    *destination_buffer = (tmp << 6) & 0xc0;
    source_buffer++;

    tmp = (GCR_TBL[*source_buffer >> 4] << 5) | GCR_TBL[*source_buffer & 15];
    *destination_buffer++ |= (tmp >> 4) & 0x3f;
    *destination_buffer = (tmp << 4) & 0xf0;
    source_buffer++;

    tmp = (GCR_TBL[*source_buffer >> 4] << 5) | GCR_TBL[*source_buffer & 15];
    *destination_buffer++ |= (tmp >> 6) & 0x0f;
    *destination_buffer = (tmp << 2) & 0xfc;
    source_buffer++;

    tmp = (GCR_TBL[*source_buffer >> 4] << 5) | GCR_TBL[*source_buffer & 15];
    *destination_buffer++ |= (tmp >> 8) & 0x03;
    *destination_buffer = (uint8_t)tmp;
}

/////////////////////////////////////////////////////////////////////

///
/// \brief endable_wps_port
/// \param enable 0 == disable (WPS PIN wird auf Eingang HiZ gestellt)
///               0 != enable  (WPS PIN wird auf Ausgang gestellt, WP wird aktiviert)
///
void endable_wps_port(uint8_t enable)
{
    if(enable == 0)
    {
        // Pin auf HiZ
        is_wps_pin_enable = 0;
        WPS_DDR &= ~(1<<WPS);
        WPS_PORT &= ~(1<<WPS);
    }
    else
    {
        is_wps_pin_enable = 1;
        WPS_DDR |= 1<<WPS;
        set_write_protection(1);
    }
}

/////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////

void set_write_protection(int8_t wp)
{
    if(is_wps_pin_enable == 0) return;

    floppy_wp = wp;

    if(wp == 0)
    {
        set_wps();
    }
    else
    {
        clear_wps();
    }
}

/////////////////////////////////////////////////////////////////////

void send_disk_change(void)
{
    if(floppy_wp == 0)
    {
        clear_wps();
        _delay_ms(1);
        set_wps();
        _delay_ms(1);
        clear_wps();
        _delay_ms(1);
        set_wps();
    }
    else
    {
        set_wps();
        _delay_ms(1);
        clear_wps();
        _delay_ms(1);
        set_wps();
        _delay_ms(1);
        clear_wps();
    }
}

/////////////////////////////////////////////////////////////////////

// Interrupt Service Routinen

ISR (PCINT0_vect)
{
    // Stepper Signale an PA6 und PA7
    stepper_signal_puffer[stepper_signal_w_pos] = STP_PIN & 0xc0;
    stepper_signal_w_pos++;
}

ISR (TIMER0_COMPA_vect)
{
    // ISR wird alle 26,28,30 oder 32µs ausfgrufen
    // Je nach dem welche Spur gerade aktiv ist

    stepper_signal_time++;

    static uint8_t old_gcr_byte = 0;
    uint8_t is_sync;

    if(get_so_status())     // Wenn OE HI dann von Prot lesen
    {
        // LESE MODUS
        // Daten aus Ringpuffer senden wenn Motor an und ein Image gemountet ist
        if(get_motor_status() && is_image_mount)
        {                                                               // Wenn Motor läuft
            akt_gcr_byte = gcr_track[akt_track_pos++];                  // Nächstes GCR Byte holen
            if(akt_track_pos == gcr_track_length) akt_track_pos = 0;    // Ist Spurende erreicht? Zurück zum Anfang


            if((akt_gcr_byte == 0xff) && (old_gcr_byte == 0xff))        // Prüfen auf SYNC (mindesten 2 aufeinanderfolgende 0xFF)
            {                                                           // Wenn SYNC
                clear_sync();                                           // SYNC Leitung auf Low setzen
                is_sync = 1;                                            // SYNC Merker auf 1
            }
                else
            {                                                           // Wenn kein SYNC
                set_sync();                                             // SYNC Leitung auf High setzen
                is_sync = 0;                                            // SYNC Merker auf 0
            }
        }
        else
        {                                                               // Wenn Motor nicht läuft
            akt_gcr_byte = 0x00;                                        // 0 senden wenn Motor aus
            is_sync = 0;                                                // SYNC Merker auf 0
        }

        // SOE
        // Unabhängig ob der Motor läuft oder nicht
        if(get_soe_status())
        {
        if(!is_sync)
            {
                DATA_DDR = 0xff;
                out_gcr_byte(akt_gcr_byte);

                if(no_byte_ready_send == 0)
                {
                    // BYTE_READY für 3µs löschen
                    clear_byte_ready();
                    _delay_us(3);
                    set_byte_ready();
                }
            }
        // else --> kein Byte senden !!
        }
        old_gcr_byte = akt_gcr_byte;
    }
    else
    {
        // SCHREIB MODUS

        // SOE
        // Unabhängig ob der Motor läuft oder nicht
        if(get_soe_status())
        {
            DATA_DDR = 0x00;
            akt_gcr_byte = in_gcr_byte;

            // BYTE_READY für 3µs löschen
            if(no_byte_ready_send == 0)
            {
                clear_byte_ready();
                _delay_us(3);
                set_byte_ready();
            }
        }

        // Daten aus Ringpuffer senden wenn Motor an
        if(get_motor_status())
        {
            // Wenn Motor läuft
            gcr_track[akt_track_pos++] = akt_gcr_byte;                  // Nächstes GCR Byte schreiben
            track_is_written = 1;
            if(akt_track_pos == gcr_track_length) akt_track_pos = 0;    // Ist Spurende erreicht? Zurück zum Anfang
        }
    }
}

/////////////////////////////////////////////////////////////////////

ISR (TIMER2_COMPA_vect)
{
    volatile static uint8_t counter = 0;
    if(counter < 5)
    {
        counter++;
        return 0;
    }

    counter = 0;

    // ISR wird alle 10ms (100Hz) aufgerufen
    volatile static uint8_t old_key0 = 0;
    volatile static uint8_t old_key1 = 0;
    volatile static uint8_t old_key2 = 0;

    uint8_t key0 = get_key0();
    uint8_t key1 = get_key1();
    uint8_t key2 = get_key2();

    if(key0 != old_key0)
    {
        if(key0)
            key_buffer[key_buffer_w_pos++] = KEY0_DOWN;
        else
            key_buffer[key_buffer_w_pos++] = KEY0_UP;
    }
    key_buffer_w_pos &= 0x0f;

    if(key1 != old_key1)
    {
        if(key1)
            key_buffer[key_buffer_w_pos++] = KEY1_DOWN;
        else
            key_buffer[key_buffer_w_pos++] = KEY1_UP;
    }
    key_buffer_w_pos &= 0x0f;

    if(key2 != old_key2)
    {
        if(key2)
            key_buffer[key_buffer_w_pos++] = KEY2_DOWN;
        else
            key_buffer[key_buffer_w_pos++] = KEY2_UP;
    }
    key_buffer_w_pos &= 0x0f;

    old_key0 = key0;
    old_key1 = key1;
    old_key2 = key2;
}
