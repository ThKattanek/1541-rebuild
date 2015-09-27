/* Name: main.c
* Project: 1541-rebuild
* Author: Thorsten Kattanek
* Copyright: (c) 2015 by Thorsten Kattanek <thorsten.kattanek@gmx.de>
* License: GPL 2
*/

/// CPU Clock
#define F_CPU 20000000L

#include "./main.h"

//#define DEBUG_MODE

int main(void)
{
    int8_t byte_str[4];	    // Wird benutzt um hier ein Byte als String abzulegen

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

    // Schreibschutz setzen
    clear_wps();

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
    while(init_sd_card()){}

    lcd_clear();

    view_dir_entry(0,&file_entry);

#ifdef DEBUG_MODE
    lcd_setcursor(0,4);
    lcd_string("T:");

    lcd_setcursor(5,4);
    lcd_string("M:");

    lcd_setcursor(9,4);
    lcd_string("K:");

    lcd_setcursor(2,4);
    sprintf(byte_str,"%d",akt_half_track >> 1);
    lcd_string(byte_str);
#endif

    // Interrupts erlauben
    sei();

    while(1)
    {
	// Auf Steppermotor aktivität prüfen
	// und auswerten

	if(stepper_signal_r_pos != stepper_signal_w_pos)
	{
	    uint8_t stepper = stepper_signal_puffer[stepper_signal_r_pos++]>>2 | stepper_signal_puffer[stepper_signal_r_pos-1];

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
#ifdef DEBUG_MODE
	    lcd_setcursor(2,4);
	    lcd_string("   ");
	    lcd_setcursor(2,4);
	    sprintf(byte_str,"%d",akt_half_track >> 1);
	    lcd_string(byte_str);
#endif
	}
	else if(stepper_signal && (stepper_signal_time >= 20))
	{
		stepper_signal = 0;

		stop_timer0();
		read_disk_track(fd,akt_image_type,akt_half_track>>1,gcr_track, &gcr_track_length);
		akt_track_pos = 0;

		// Geschwindigkeit setzen
		OCR0A = timer0_orca0[akt_half_track>>1];
		start_timer0();
	}

#ifdef DEBUG_MODE
	lcd_setcursor(11,4);
	if(get_key0_status())
	    lcd_string("1");
	else
	    lcd_string("0");

	lcd_setcursor(12,4);
	if(get_key1_status())
	    lcd_string("1");
	else
	    lcd_string("0");

	lcd_setcursor(13,4);
	if(get_key2_status())
	    lcd_string("1");
	else
	    lcd_string("0");	
#endif
	static uint16_t dir_pos = 0;

	/////////////////////////////////////////////////////////////////////////////////////////
	//// Image Auswahl

	// Runter
	if(get_key0_status() && !wait_key_counter0)
	{
	    wait_key_counter0 = PRELL_TIME;
	    if(dir_pos > 0)
	    {
		dir_pos--;
	    }
	    view_dir_entry(dir_pos,&file_entry);
	}

	// Hoch
	if(get_key1_status() && !wait_key_counter1)
	{
	    wait_key_counter1 = PRELL_TIME;
	    dir_pos++;
	    if(!view_dir_entry(dir_pos,&file_entry)) dir_pos--;
	}

	// Enter
	if(get_key2_status() && !wait_key_counter2)
	{
	    wait_key_counter2 = PRELL_TIME;

	    stop_timer0();
	    DATA_PORT = 0x00;

	    close_disk_image(fd);
	    fd = open_disk_image(fs, &file_entry, &akt_image_type);
	    if(!fd)
	    {
		lcd_setcursor( 0, 2);
		lcd_string("Image not open!");
	    }

	    read_disk_track(fd,akt_image_type,INIT_TRACK,gcr_track, &gcr_track_length);

	    stp_signals_old = STP_PIN >> 6;
	    akt_half_track = INIT_TRACK << 1;
	    akt_track_pos = 0;

	    start_timer0();
	    send_disk_change();
	}
    }
}

/////////////////////////////////////////////////////////////////////

int8_t init_sd_card()
{
    set_sleep_mode(SLEEP_MODE_IDLE);

    // SD Karte initialisieren
    if(!sd_raw_init())
	return 1;

    // Eine Partition öffnen (die erste)
    partition = partition_open(sd_raw_read,sd_raw_read_interval,0,0,0);
    if(!partition)
    {
	partition = partition_open(sd_raw_read,sd_raw_read_interval,0,0,-1);
	if(!partition) return 2;
    }

    // FAT16/32 Filesystem versuchen zu öffnen
    fs = fat_open(partition);
    if(!fs) return 3;

    // Root Verzeichnis öffnen
    fat_get_dir_entry_of_path(fs, "/", &directory);
    dd = fat_open_dir(fs, &directory);
    if(!dd) return 4;

    return 0;
}

/////////////////////////////////////////////////////////////////////

void show_start_message()
{
    lcd_clear();
    lcd_setcursor( 1, 2);
    lcd_string("-- 1541-rebuild --");
    lcd_setcursor( 2,3);
    lcd_string("Firmware:  ");
    lcd_string(VERSION);
    _delay_ms(START_MESSAGE_TIME);
    lcd_clear();
}

/////////////////////////////////////////////////////////////////////

void init_stepper()
{
    // Stepper PINs als Eingang schalten
    STP_DDR &= ~(1<<STP0 | 1<<STP1);
    akt_half_track = INIT_TRACK << 1;

    // Pin Change Ineterrupt für beide PIN's aktivieren
    PCICR = 0x01;   // Enable PCINT0..7
    PCMSK0 = 0xc0;  // Set Mask Register für PCINT6 und PCINT7

    // Debug
    DDRC |= 1<<PC5;
    PORTC |= 1<<PC5;
}

/////////////////////////////////////////////////////////////////////

void stepper_inc()
{            
    if(akt_half_track == 83) return;
    akt_half_track++;
}

/////////////////////////////////////////////////////////////////////

void stepper_dec()
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

void init_controll_signals()
{
    // Als Ausgang schalten
    BYTE_READY_DDR |= 1<<BYTE_READY;
    SYNC_DDR |= 1<<SYNC;
    WPS_DDR |= 1<<WPS;

    // DATEN Leitungen als Ausgang schalten
    DATA_DDR = 0xff;

    // Als Eingang schalten
    SOE_DDR &= ~(1<<SOE);
}

/////////////////////////////////////////////////////////////////////

void init_timer0()
{
    TCCR0A = (1<<WGM01);    // CTC Modus
    TCCR0B |= (1<<CS00);    // Prescaler 1

    OCR0A = timer0_orca0[akt_half_track>>1];

    start_timer0();
}

/////////////////////////////////////////////////////////////////////

void start_timer0()
{
    // Compare Interrupt erlauben
    TIMSK0 |= (1<<OCIE0A);
}

/////////////////////////////////////////////////////////////////////

void stop_timer0()
{
    // Compare Interrupt verhindern
    TIMSK0 &= ~(1<<OCIE0A);
}

/////////////////////////////////////////////////////////////////////

void init_timer2()
{
    TCCR2A = (1<<WGM21);    // CTC Modus
    TCCR2B |= (1<<CS20) | (1<<CS21) | (1<<CS22);    // Prescaler 1024

    // jede ms aufrufen --> 1KHz
    // ((20000000/1024)/1000) = 20

    OCR2A = 20-1;

    start_timer2();
}
/////////////////////////////////////////////////////////////////////

void start_timer2()
{
    // Compare Interrupt erlauben
    TIMSK2 |= (1<<OCIE2A);
}

/////////////////////////////////////////////////////////////////////

void stop_timer2()
{
    // Compare Interrupt verhindern
    TIMSK2 &= ~(1<<OCIE2A);
}

/////////////////////////////////////////////////////////////////////

void init_keys()
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

int8_t view_dir_entry(uint16_t entry_start, struct fat_dir_entry_struct* dir_entry)
{
    uint16_t entry_pos = 0;

    fat_reset_dir(dd);
    while(fat_read_dir(dd, dir_entry) && (entry_pos < entry_start))
    {
	entry_pos++;
    }

    if(entry_pos == entry_start)
    {
	strcpy(lcd_puffer, dir_entry->long_name);
	uint8_t len = strlen(lcd_puffer);
	if(len > 20)
	    lcd_puffer[20] = 0;
	else
	{
	    for(int i=len; i<20; i++)
		lcd_puffer[i] = ' ';
	    lcd_puffer[20] = 0;
	}

	lcd_setcursor(0,1);
	lcd_string(lcd_puffer);
	return 1;
    }
    return 0;
}

/////////////////////////////////////////////////////////////////////

struct fat_file_struct* open_disk_image(struct fat_fs_struct* fs ,struct fat_dir_entry_struct* file_entry, uint8_t* image_type)
{
    if(strlen(file_entry->long_name) < 4) return NULL;

    struct fat_file_struct* fd = NULL;
    int8_t extension[5];
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
	*image_type = 0;
	return fd;
    }

    if(!strcmp(extension,".g64"))
    {
	// Laut Extension ein G64
	*image_type = 1;
	open_g64_image(fd);
    }else if(!strcmp(extension,".d64"))
    {
	// Laut Extensions ein D64
	*image_type = 2;
	open_d64_image(fd);
    }else
    {
	// Nicht unterstützt
	lcd_setcursor( 0, 3);
	lcd_string("Not Supported");
	fat_close_file(fd);
	fd = NULL;
	*image_type = 0;
    }

    return fd;
}

/////////////////////////////////////////////////////////////////////

void close_disk_image(struct fat_file_struct* fd)
{
    fat_close(fd);
    fd = NULL;
    return 0;
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
    uint8_t is_read = 0;
    int32_t offset = 0;

    switch(image_type)
    {
    ///////////////////////////////////////////////////////////////////////////
    case 1:	// G64
	/// Track18 eines G64 einlesen

	offset = (int32_t)track_nr - 1;
	offset = (offset << 3) + 0x0c;

	if(fat_seek_file(fd,&offset,FAT_SEEK_SET))
	{
	    if(fat_read_file(fd, &offset, sizeof(uint32_t)))
	    {
		if(fat_seek_file(fd,&offset,FAT_SEEK_SET))
		{
		    fat_read_file(fd, &gcr_track_length, sizeof(gcr_track_length));

		    fat_read_file(fd, track_buffer, gcr_track_length);

		    is_read = 1;
		}
	    }
	}
	break;

    ///////////////////////////////////////////////////////////////////////////
    case 2:	// D64
	break;
    }
    return is_read;
}

/////////////////////////////////////////////////////////////////////

void send_disk_change()
{
    set_wps();
    _delay_ms(1);
    clear_wps();
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
    static uint8_t bit_counter = 0;

    // BYTE READY setzen (HIGH)
    set_byte_ready();

    if(bit_counter == 8)
    {
	bit_counter = 0;

	if(get_motor_status())	// Daten aus Ringpuffer senden wenn Motor an
	{
	    akt_gcr_byte = gcr_track[akt_track_pos++];
	    if(akt_track_pos == gcr_track_length) akt_track_pos = 0;

	    if(akt_gcr_byte == 0xff)
		clear_sync();
	    else
		 set_sync();
	}
	else			// Nullen senden wenn Motor aus
	{
	    akt_gcr_byte = 0x00;
	}

	// SOE
	if(get_soe_status())
	{
	    // BYTE READY löschen (LOW)
	    if(akt_gcr_byte != 0xff)
	    {
		out_gcr_byte(akt_gcr_byte);
		clear_byte_ready();
	    }
	}
    }
    bit_counter++;
}

ISR (TIMER2_COMPA_vect)
{
    stepper_signal_time++;

    if(wait_key_counter0)
	wait_key_counter0--;
    if(wait_key_counter1)
	wait_key_counter1--;
    if(wait_key_counter2)
	wait_key_counter2--;
}
