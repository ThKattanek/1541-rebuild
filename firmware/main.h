/* Name: main.h
* Project: 1541-rebuild
* Author: Thorsten Kattanek
* Copyright: (c) 2020 by Thorsten Kattanek <thorsten.kattanek@gmx.de>
* License: GPL 2
*/

// AVR Spezifische Headerdateien
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <avr/pgmspace.h>

// Für die LCD Ansteuerung
#include "./lcd.h"

// SDCard Lib
#include "./sd_card_lib/fat.h"
#include "./sd_card_lib/fat_config.h"
#include "./sd_card_lib/partition.h"
#include "./sd_card_lib/sd_raw.h"
#include "./sd_card_lib/sd_raw_config.h"

// Gui _ Menu
#include "./gui_constants.h"
#include "./menu.h"

// Enthält nur die Versionsnummer als String
#include "./version.h"

// Settings speichern in EEPROM und Import / Export
#include "./settings.h"

#define NULL    ((void *)0)

// Konfiguration /////////////////////////////////////////////////

// LCD
#define LCD_LINE_COUNT 4
#define LCD_LINE_SIZE 20

// Zeit in ms wie lange die Version nach dem Start angezeigt wird
#define START_MESSAGE_TIME 1500

// Spur auf dem der Lesekopf beim Start/Reset stehen soll
// Track 18 --> Directory
#define INIT_TRACK 18

// Zeit die nach der letzten Stepperaktivität vergehen muss, um einen neuen Track von SD Karte zu laden
// (1541 Original Rom schaltet STP1 alle 15ms)
// Default 15
#define STEPPER_DELAY_TIME 193  // zwischen 26µs*193=5,02ms bis 32µs*160=6,176ms

// SOE GATEWAY --> Ausgang
// LO wenn SD Karte laufen soll damit ByteReady High bleibt
#define SOE_GATEARRAY_DDR DDRC
#define SOE_GATEARRAY_PORT PORTC
#define SOE_GATEARRAY PC7

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

//DDxn = 0 , PORTxn = 0 --> HiZ
//DDxn = 1 , PORTxn = 0 --> Output Low (Sink)

#define set_byte_ready() BYTE_READY_DDR &= ~(1 << BYTE_READY)   // HiZ
#define clear_byte_ready() BYTE_READY_DDR |= (1 << BYTE_READY)  // auf Ground ziehen

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

// SO
#define SO_DDR DDRC
#define SO_PIN PINC
#define SO     PINC5

#define get_so_status() (SO_PIN & (1<<SO))

// WPS (Write Protection)
// PIN ist mit PIN14 U8 VIA6522 (Input) verbunden
// PIN ist mit PIN14 (A) GateArray (Input) verbunden
// PIN ist mit PIN8 LS04 DM74LS04N (Output) verbunden -> Einganag PIN9 hängt auf einen PullUp (47k)
#define WPS_DDR DDRC
#define WPS_PORT PORTC
#define WPS  PC4

#define set_wps() WPS_PORT |= 1 << WPS          // 5V Level = WritePotect
#define clear_wps() WPS_PORT &= ~(1 << WPS)     // 0V Level = Writetable

// Anschluss der Datenleitungen
#define DATA_DDR   DDRD
#define DATA_PORT  PORTD
#define DATA_PIN   PIND

#define out_gcr_byte(gcr_byte) DATA_PORT = gcr_byte
#define in_gcr_byte DATA_PIN

// Einabetasten
#define KEY0_DDR DDRB
#define KEY0_PORT PORTB
#define KEY0_PIN PINB
#define KEY0	 PINB0

#define KEY1_DDR DDRB
#define KEY1_PORT PORTB
#define KEY1_PIN PINB
#define KEY1	 PINB1

#define KEY2_DDR DDRC
#define KEY2_PORT PORTC
#define KEY2_PIN PINC
#define KEY2	 PINC3

#define get_key0() (~KEY0_PIN & (1<<KEY0))
#define get_key1() (~KEY1_PIN & (1<<KEY1))
#define get_key2() (~KEY2_PIN & (1<<KEY2))

// Drehimpulsgeber // Liegen immer auf KEY0 + KEY1
/// \brief Pin Nummer des Ports für Drehgeber PIN 1A
#define IMPULS_1A_PIN KEY1
/// \brief Port für Drehgeber PIN 1A
#define IMPULS_1A_PORT KEY1_PORT
/// \brief Datenrichtungsregister des Ports für Drehgeber PIN 1A
#define IMPULS_1A_DDR KEY1_DDR

/// \brief Pin Nummer des Ports für Drehgeber PIN 1B
#define IMPULS_1B_PIN KEY0
/// \brief Port für Drehgeber PIN 1B
#define IMPULS_1B_PORT KEY0_PORT
/// \brief Datenrichtungsregister des Ports für Drehgeber PIN 1B
#define IMPULS_1B_DDR KEY0_DDR

//////////////////////////////////////////////////////////////////
// #define __AVR_ATmega128__

enum {UNDEF_IMAGE, G64_IMAGE, D64_IMAGE};

void reset(void);
void check_stepper_signals(void);
void check_motor_signal(void);
uint8_t get_key_from_buffer(void);
void update_gui(void);
void check_menu_events(uint16_t menu_event);
void set_gui_mode(uint8_t gui_mode);
void filebrowser_update(uint8_t key_code);
void filebrowser_refresh(void);
void init_pb2_pb3(void);
int8_t init_sd_card(void);
void release_sd_card(void);
uint8_t change_dir(const char* path);
uint8_t find_file_in_dir(struct fat_fs_struct* fs, struct fat_dir_struct* dd, const char* name, struct fat_dir_entry_struct* dir_entry);
uint16_t get_dir_entry_count(void);
uint16_t seek_to_dir_entry(uint16_t entry_num);
void show_start_message(void);
void show_sdcard_info_message(void);
void init_stepper(void);
void stepper_inc(void);
void stepper_dec(void);
void init_motor(void);
void init_controll_signals(void);
void init_timer0(void);
void start_timer0(void);
void stop_timer0(void);
void init_timer2(void);
void start_timer2(void);
void stop_timer2(void);
void init_keys(void);
void soe_gatearry_init(void);
void soe_gatearry_lo(void);
void soe_gatearry_hi(void);

struct fat_file_struct* open_disk_image(struct fat_fs_struct *fs, struct fat_dir_entry_struct* file_entry, uint8_t *image_type);
void close_disk_image(struct fat_file_struct*);
int8_t open_g64_image(struct fat_file_struct *fd);
int8_t open_d64_image(struct fat_file_struct *fd);
int8_t read_disk_track(struct fat_file_struct *fd, uint8_t image_type, uint8_t track_nr, uint8_t* track_buffer, uint16_t *gcr_track_length); // Tracknummer 1-42
void write_disk_track(struct fat_file_struct *fd, uint8_t image_type, uint8_t track_nr, uint8_t* track_buffer, uint16_t *gcr_track_length); // Tracknummer 1-42

void remove_image(void);

inline void ConvertToGCR(uint8_t *source_buffer, uint8_t *destination_buffer);
inline void ConvertFromGCR(uint8_t *source_buffer, uint8_t *destination_buffer);

void endable_wps_port(uint8_t enable);  // 0 = WPS PIN HiZ (set_write_protection() ohne Wirkung) / 1 = WPS PIN als Ausgang
void set_write_protection(int8_t wp);   // wp=0 image nicht geschützt wp=1 image schreibgeschützt
void send_disk_change(void);

/////////////////////////////////////////////////////////////////
// Globale Variablen

// gui
char image_filename[32]; //Maximal 32 Zeichen

volatile uint8_t key_buffer[16];
volatile uint8_t key_buffer_r_pos;
volatile uint8_t key_buffer_w_pos;

uint8_t input_mode = INPUT_MODE_ENCODER;

uint8_t current_gui_mode;
int8_t byte_str[16];

uint8_t gui_current_line_offset;         // >0 dann ist der Name länger als die maximale Anzeigelaenge
uint8_t gui_line_scroll_pos;             // Kann zwischen 0 und fb_current_line_offset liegen
uint8_t gui_line_scroll_direction;       // Richtung des Scrollings
uint8_t gui_line_scroll_end_begin_wait;

// Alles für den Filebrowser
uint8_t fb_lcd_dir_char;            // Char Nummer für Directory Symbol
uint8_t fb_lcd_disk_char;           // Char Nummer für Diskimage Symbol
uint8_t fb_lcd_cursor_char;         // Char für Auswahl Cursor
uint8_t fb_lcd_more_top_char;
uint8_t fb_lcd_more_down_char;
uint16_t fb_dir_entry_count=0;      // Anzahl der Einträge im aktuellen Direktory
uint8_t fb_lcd_cursor_pos=0;        // Position des Cursors auf dem LCD Display
uint8_t fb_lcd_window_pos=0;        // Position des Anzeigebereichs innerhablb der Menüeinträge

uint8_t fb_current_line_offset = 0;         // >0 dann ist der Name länger als die maximale Anzeigelaenge
uint8_t fb_line_scroll_pos = 0;             // Kann zwischen 0 und fb_current_line_offset liegen
uint8_t fb_line_scroll_direction = 0;       // Richtung des Scrollings
uint8_t fb_line_scroll_end_begin_wait = 10;

struct fat_dir_entry_struct fb_dir_entry[LCD_LINE_COUNT];

// filesystem
struct partition_struct* partition = NULL;
struct fat_fs_struct* fs = NULL;
struct fat_dir_entry_struct dir_entry;
struct fat_dir_struct* dd = NULL;

struct fat_dir_entry_struct file_entry;
struct fat_file_struct* fd;

// floppydisk emulation
uint8_t akt_image_type = UNDEF_IMAGE;     // 0=kein Image, 1=G64, 2=D64
uint8_t is_image_mount;

uint8_t is_wps_pin_enable = 0; // 0=WPS PIN=HiZ / 1=WPS Output
int8_t floppy_wp = 0;          // Hier wird der aktuelle WriteProtection Zustand gespeichert / 0=Nicht Schreibgeschützt 1=Schreibgeschützt

volatile static uint8_t stp_signals_old = 0;

uint16_t gcr_track_length = 7139;

volatile uint8_t akt_gcr_byte = 0;
volatile uint16_t akt_track_pos = 0;

uint8_t akt_half_track;
uint8_t old_half_track;

volatile uint8_t old_motor_status;

const uint16_t d64_track_offset[41] = {0,0x0000,0x0015,0x002A,0x003F,0x0054,0x0069,0x007E,0x0093,
                                         0x00A8,0x00BD,0x00D2,0x00E7,0x00FC,0x0111,0x0126,0x013B,
                                         0x0150,0x0165,0x0178,0x018B,0x019E,0x01B1,0x01C4,0x01D7,
                                         0x01EA,0x01FC,0x020E,0x0220,0x0232,0x0244,0x0256,0x0267,
                                         0x0278,0x0289,0x029A,0x02AB,0x02BC,0x02CD,0x02DE,0x02EF};

const uint8_t d64_sector_count[4] = {21,        //Spuren 1-17
                                     19,        //Spuren 18-24
                                     18,        //Spuren 25-30
                                     17};       //Spuren 31-40

const uint8_t d64_track_zone[41] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,                    //Spuren 1-17
                               1,1,1,1,1,1,1,                                               //Spuren 18-24
                               2,2,2,2,2,2,                                                 //Spuren 25-30
                               3,3,3,3,3,3,3,3,3,3};                                        //Spuren 31-40

// Originale Bitraten
//Zone 0: 8000000/26 = 307692 Hz    (ByteReady 38461.5 Hz)
//Zone 1: 8000000/28 = 285714 Hz    (ByteReady 35714.25 Hz)
//Zone 2: 8000000/30 = 266667 Hz    (ByteReady 33333.375 Hz)
//Zone 3: 8000000/32 = 250000 Hz    (ByteReady 31250 Hz)

//Höhere Werte verlangsammen die Bitrate
//const uint8_t timer0_orca0[4] = {64,69,74,79};            // Diese Werte erzeugen den genausten Bittakt aber nicht 100% (Bei 20MHz)
const uint8_t timer0_orca0[4] = {77,83,89,95};              // Diese Werte erzeugen den genausten Bittakt aber nicht 100% (Bei 24MHz)

const uint8_t d64_sector_gap[4] = {12, 21, 16, 13}; // von GPZ Code übermommen imggen
#define HEADER_GAP_BYTES (9)


// use slices for d64-file-access.. size of slice depends on free atmega ram ! adjust in case of shortage

// -- save approach: use 3 slices, each 7*256 bytes
// #define NUM_OF_SLICES   (3)
// #define MAX_SLICE_SIZE  (7)
// const uint8_t track_slices_last[4] = { 7, 5, 4, 3 };    // 2*7 + x .. = sector_count

// -- performance approach: use 2 slices, each 17*256 bytes
#define NUM_OF_SLICES   (2)
#define MAX_SLICE_SIZE  (17)
const uint8_t track_slices_last[4] = { 4, 2, 1, 0 };    // 1*17 + x .. = sector_count

#define D64_SECTOR_SIZE (256)
uint8_t d64_sector_puffer[MAX_SLICE_SIZE*D64_SECTOR_SIZE+5];

// Ringpuffer für reinkommende Stepper Signale
uint8_t stepper_signal_puffer[0x100]; // Ringpuffer für Stepper Signale (256 Bytes)
volatile uint8_t stepper_signal_r_pos = 0;
volatile uint8_t stepper_signal_w_pos = 0;
volatile uint8_t stepper_signal_time = 0;
volatile uint8_t stepper_signal = 0;

volatile uint8_t track_is_written = 0;
volatile uint8_t track_is_written_old = 0;
volatile uint8_t no_byte_ready_send = 0;

uint8_t gcr_track[8192];
