/* Name: main.c
* Project: 1541-rebuild
* Author: Thorsten Kattanek
* Copyright: (c) 2015 by Thorsten Kattanek <thorsten.kattanek@gmx.de>
* License: GPL 2
*/

/// CPU Clock
#define F_CPU 20000000L

#include "./main.h"

#define DEBUG_MODE

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
	if(stepper_msg)
	{
	    uint8_t stp = stepper_msg;
	    stepper_msg = 0;		// Schnell auf Null setzten um nicht einen Step zu verpassen

	    if(stp == 1)
		stepper_dec();		// Spur Dekrementieren
	    else stepper_inc();		// Spur Inkrementieren

#ifdef DEBUG_MODE
	    lcd_setcursor(2,4);
	    lcd_string("   ");
	    lcd_setcursor(2,4);
	    sprintf(byte_str,"%d",akt_half_track >> 1);
	    lcd_string(byte_str);
#endif
	}

#ifdef DEBUG_MODE
	// Auf Laufwerksmotor prüfen
	lcd_setcursor(7,4);
	if(get_motor_status())
	    lcd_string("*");
	else
	    lcd_string("-");
#endif

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

	    fd = fat_open_file(fs, &file_entry);
	    if(!fd)
	    {
		lcd_setcursor( 0, 3);
		lcd_string("File not open!");
	    }
	    else
	    {
		/// Track18 eines G64 einlesen


		int32_t offset = 0x94;

		uint8_t is_read = 0;


		if(fat_seek_file(fd,&offset,FAT_SEEK_SET))
		{
		    if(fat_read_file(fd, &offset, sizeof(uint32_t)))
		    {
			if(fat_seek_file(fd,&offset,FAT_SEEK_SET))
			{
			    fat_read_file(fd, &gcr_track_length, sizeof(gcr_track_length));
			    int count = fat_read_file(fd, gcr_track, gcr_track_length);
			    akt_track_pos = 0;
			    is_read = 1;
			}
		    }
		}

		if(!is_read)
		{
		    lcd_setcursor( 0, 3);
		    lcd_string("Lesefehler !!");
		}
		else
		    send_disk_change();
	    }
	    fat_close(fd);
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

    // 35695 * 8 Hz entspr. 28µs / 8	// Spur18
    // ((20000000/1)/35695*8 / 1) = 70

    OCR0A = 70-1;

    // Compare Interrupt erlauben
    TIMSK0 |= (1<<OCIE0A);
}

/////////////////////////////////////////////////////////////////////

void init_timer2()
{
    TCCR2A = (1<<WGM21);    // CTC Modus
    TCCR2B |= (1<<CS20) | (1<<CS21) | (1<<CS22);    // Prescaler 1024

    // jede ms aufrufen --> 1KHz
    // ((20000000/1024)/1000) = 20

    OCR2A = 20-1;

    // Compare Interrupt erlauben
    TIMSK2 |= (1<<OCIE2A);
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

void send_disk_change()
{
    set_wps();
    _delay_ms(1);
    clear_wps();
}

/////////////////////////////////////////////////////////////////////

uint8_t find_file_in_dir(struct fat_fs_struct* fs, struct fat_dir_struct* dd, const char* name, struct fat_dir_entry_struct* dir_entry)
{
    while(fat_read_dir(dd, dir_entry))
    {
	if(strcmp(dir_entry->long_name, name) == 0)
	{
	    fat_reset_dir(dd);
	    return 1;
	}
    }

    return 0;
}

/////////////////////////////////////////////////////////////////////

struct fat_file_struct* open_file_in_dir(struct fat_fs_struct* fs, struct fat_dir_struct* dd, const char* name)
{
    struct fat_dir_entry_struct file_entry;
    if(!find_file_in_dir(fs, dd, name, &file_entry))
	return 0;

    return fat_open_file(fs, &file_entry);
}

/////////////////////////////////////////////////////////////////////

// Interrupt Service Routinen

ISR (PCINT0_vect)
{
    static uint8_t stp_signals_old = 0;

    uint8_t stp_signals = PINA >> 6;

    // Stepper Signale an PA6 und PA7
    stp_signals = PINA >> 6;

    if (stp_signals_old == ((stp_signals+1) & 3))
    {
	stepper_msg = 1;
    }
    else if (stp_signals_old == ((stp_signals-1) & 3))
    {
	stepper_msg = 2;
    }

    stp_signals_old = stp_signals;
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
    if(wait_key_counter0)
	wait_key_counter0--;
    if(wait_key_counter1)
	wait_key_counter1--;
    if(wait_key_counter2)
	wait_key_counter2--;
}
