/* Name: main.h
* Project: 1541-rebuild
* Author: Thorsten Kattanek
* Copyright: (c) 2015 by Thorsten Kattanek <thorsten.kattanek@gmx.de>
* License: GPL 2
*/

// AVR Spezifische Headerdateien
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>

// Für die LCD Ansteuerung
#include "./lcd.h"

// SDCard Lib
#include "./sd_card_lib/fat.h"
#include "./sd_card_lib/fat_config.h"
#include "./sd_card_lib/partition.h"
#include "./sd_card_lib/sd_raw.h"
#include "./sd_card_lib/sd_raw_config.h"

// Enthält nur die Versionsnummer als String
#include "./version.h"

#define NULL    ((void *)0)

// Konfiguration /////////////////////////////////////////////////

// Zeit in ms wie lange die Version nach dem Start angezeigt wird
#define START_MESSAGE_TIME 2000

// Spur auf dem der Lesekopf beim Start/Reset stehen soll
#define INIT_TRACK 18

// Anschluss der Stepper Signale
// Zwingend diese PINs wegen Extern Interrupts PCINT6/7
// Bei Änderung muss der Sourcecode angepasst werden !
#define STP_DDR  DDRA
#define STP_PIN PINA
#define STP1 PINA6
#define STP0 PINA7

// Anschluss des Laufwerkmotor Signals
#define MTR_DDR DDRC
#define MTR_PIN PINC
#define MTR	PINC2

#define get_motor_status() (MTR_PIN & (1<<MTR))

// Steuersignale
// BYTE READY
#define BYTE_READY_DDR DDRC
#define BYTE_READY_PORT PORTC
#define BYTE_READY  PC0

#define set_byte_ready() BYTE_READY_PORT |= 1 << BYTE_READY
#define clear_byte_ready() BYTE_READY_PORT &= ~(1 << BYTE_READY)

// SYNC
#define SYNC_DDR DDRC
#define SYNC_PORT PORTC
#define SYNC  PC1

#define set_sync() SYNC_PORT |= 1 << SYNC
#define clear_sync() SYNC_PORT &= ~(1 << SYNC)

// SOE
#define SOE_DDR DDRC
#define SOE_PIN PINC
#define SOE	PINC6

#define get_soe_status() (SOE_PIN & (1<<SOE))

// Anschluss der Datenleitungen
#define DATA_DDR   DDRD
#define DATA_PORT  PORTD

#define out_gcr_byte(gcr_byte) DATA_PORT = gcr_byte

//////////////////////////////////////////////////////////////////
// #define __AVR_ATmega128__

int8_t init_sd_card();
void show_start_message();
void init_stepper();
void stepper_inc();
void stepper_dec();
void init_motor();
void init_controll_signals();
void init_timer0();

uint8_t find_file_in_dir(struct fat_fs_struct* fs, struct fat_dir_struct* dd, const char* name, struct fat_dir_entry_struct* dir_entry);
struct fat_file_struct* open_file_in_dir(struct fat_fs_struct* fs, struct fat_dir_struct* dd, const char* name);

ISR (PCINT0_vect);

/////////////////////////////////////////////////////////////////
// Globale Variablen

struct partition_struct* partition = NULL;
struct fat_fs_struct* fs = NULL;
struct fat_dir_entry_struct directory;
struct fat_dir_struct* dd = NULL;

unsigned char gcr_track[8192];
const int gcr_track_length = 7139;
volatile unsigned char akt_gcr_byte = 0;
volatile unsigned short int akt_track_pos = 0;

uint8_t akt_half_track;

volatile stepper_msg = 0;   // 0-keine Stepperaktivität ; 1=StepperDec ; 2-255=StepperInc
