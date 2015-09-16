/// CPU Clock
//#undef  F_CPU
#define F_CPU 20000000L

#include <avr/io.h>
#include <avr/wdt.h>
#include <avr/interrupt.h>
#include <string.h>
#include <avr/pgmspace.h>
#include <avr/sleep.h>

#include <math.h>
#include <util/delay.h>

#include <stdio.h>
#include <string.h>

#include "./version.h"
#include "./lcd.h"
#include "./1541-rebuild.h"

#include "./sd_card_lib/fat.h"
#include "./sd_card_lib/fat_config.h"
#include "./sd_card_lib/partition.h"
#include "./sd_card_lib/sd_raw.h"
#include "./sd_card_lib/sd_raw_config.h"

#include "gcr_track18.h"

volatile unsigned char akt_half_track = 34;
//volatile unsigned char akt_sektor = 0;

unsigned char str00[10];

volatile unsigned char old_motor_status = 0;
volatile unsigned char motor_status = 0;

volatile unsigned char akt_track = 0;
volatile unsigned char akt_sektor = 0;

volatile unsigned char akt_gcr_byte = 0;
volatile unsigned short int akt_track_pos = 0;

volatile unsigned char bit_counter = 0;

int main(void)
{
    unsigned char old_stepper_status = 0;
    unsigned char stepper_status = 0;

    unsigned soe = 0;
    unsigned char old_soe_status  = 0;

    lcd_init();

    // Startmeldung mit Version ausgeben für 2 Sekunden
    lcd_setcursor( 3, 2);
    lcd_string("-- Mega1541 --");
    lcd_setcursor( 2,3);
    lcd_string("Firmware:  ");
    lcd_string(VERSION);
    _delay_ms(2000);

    lcd_clear();

    lcd_setcursor( 0, 1);
    lcd_string("MTR:*");

    lcd_setcursor( 6, 1);
    lcd_string("TRK:");

    lcd_setcursor( 14, 1);
    lcd_string("SKT:");

    /// PortB als Eingang schalten
    DDRB = 0x00;
    PORTB = 0x00;

    /// PortD als Eingang
    /// PIN #0 und #1 Ausgang
    DDRC = 0x03;
    PORTC = 0x02;
    PINC = 0x00;

    DDRD = 0xff;
    PORTD = 0xff;
    PIND = 0x00;

    PrintTrack();

    TCCR0A = (1<<WGM01); // CTC Modus
    TCCR0B |= (1<<CS00); // Prescaler 1
    // 35695 * 8 Hz entspr. 28µs / 8	// Spur18
    // ((20000000/1)/35695*8 / 1) = 70
    OCR0A = 70-1;

    // Compare Interrupt erlauben
    TIMSK0 |= (1<<OCIE0A);

    // Global Interrupts aktivieren
    sei();

    /// SD Karte ///

    unsigned char sd_found = 0;
    struct partition_struct* partition;

    set_sleep_mode(SLEEP_MODE_IDLE);

    while(1)
    {
	if(sd_found == 0)
	{
	    if(sd_raw_init())
	    {
		lcd_setcursor( 0, 4);
		lcd_string("SD Karte gefunden !");
		sd_found = 1;
	    }


	    if(!partition)
	    {
		partition = partition_open(sd_raw_read,sd_raw_read_interval,0,0,0);
	    }

	    if(!partition)
	    {
		partition = partition_open(sd_raw_read,sd_raw_read_interval,0,0,-1);
	    }

	    if(!partition)
	    {
		lcd_setcursor( 0, 4);
		lcd_string("Partition nicht gefunden !");
		sd_found = 1;
	    }
	    else
	    {
		lcd_setcursor( 0, 4);
		lcd_string("Partition gefunden !");
		sd_found = 1;
	    }
	}

	// Motor An oder Aus ?

	motor_status = (PINC & (1<<2)) >> 2;

	if(motor_status != old_motor_status)
	{
	    lcd_setcursor( 4, 1);
	    if(!motor_status)
		lcd_string("*");
	    else lcd_string(" ");

	    old_motor_status = motor_status;
	}

	// Steppermotor auswerten
	stepper_status = ~PINB & 0x0f;

	switch((stepper_status << 4) | (old_stepper_status))
	{
	case 0x18: case 0x21: case 0x42: case 0x84:
	    // STEPPER INC
	    StepperInc();
	    break;
	case 0x12: case 0x24: case 0x48: case 0x81:
	    // STEPPER DEC
	    StepperDec();
	    break;
	default:
	    break;
	}
	old_stepper_status = stepper_status;
    }
}

ISR (TIMER0_COMPA_vect)
{
    // BYTE READY auf HIGH
    PORTC |= 0x01;

    if(bit_counter == 8)
    {
	bit_counter = 0;

	if(!motor_status)
	{
	    akt_gcr_byte = gcr_track18[akt_track_pos++];
	    if(akt_track_pos == gcr_track18_length) akt_track_pos = 0;

	    if(akt_gcr_byte == 0xff)
		PORTC &= 0xfd;
	    else
		 PORTC |= 0x02;
	}
	else
	{
	    akt_gcr_byte = 0;
	}


	// SOE
	if(PINC & 0x40)
	{
	    // BYTE READY auf LOW
	    if(akt_gcr_byte != 0xff)
	    {
		PORTD = akt_gcr_byte;
		PORTC &= 0xfe;
	    }
	}

    }

    bit_counter++;
}

void StepperInc()
{
    akt_half_track++;
}

void StepperDec()
{
    if(akt_half_track == 0) return;

    akt_half_track--;
    PrintTrack();
}

void PrintTrack()
{
    lcd_setcursor( 10, 1);
    sprintf(str00,"%3.d",(akt_half_track>>1)+1);
    lcd_string(str00);
}
