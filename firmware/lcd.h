// Ansteuerung eines HD44780 kompatiblen LCD im 4-Bit-Interfacemodus
// http://www.mikrocontroller.net/articles/AVR-GCC-Tutorial/LCD-Ansteuerung
//
 
#ifndef LCD_ROUTINES_H
#define LCD_ROUTINES_H
 
////////////////////////////////////////////////////////////////////////////////
// Hier die verwendete Taktfrequenz in Hz eintragen, wichtig!
 
#ifndef F_CPU
#define F_CPU 24000000UL
#endif
 
////////////////////////////////////////////////////////////////////////////////
// Pinbelegung für das LCD, an verwendete Pins anpassen
// Alle LCD Pins müssen an einem Port angeschlossen sein und die 4
// Datenleitungen müssen auf aufeinanderfolgenden Pins liegen
 
//  LCD DB4-DB7 <-->  PORTB Bit PB0-PB3
#define LCD_PORT      PORTA
#define LCD_DDR       DDRA
#define LCD_DB        PA0
 
//  LCD RS      <-->  PORTB Bit PB4     (RS: 1=Data, 0=Command)
#define LCD_RS        PA4
 
//  LCD EN      <-->  PORTB Bit PB5     (EN: 1-Impuls für Daten)
#define LCD_EN        PA5
 
////////////////////////////////////////////////////////////////////////////////
// LCD Ausführungszeiten (MS=Millisekunden, US=Mikrosekunden)
 
#define LCD_BOOTUP_MS           15 	// 15
#define LCD_ENABLE_US           20	// 20
#define LCD_WRITEDATA_US        46	// 46
#define LCD_COMMAND_US          42	// 42
 
#define LCD_SOFT_RESET_MS1      5	// 5
#define LCD_SOFT_RESET_MS2      1	// 1
#define LCD_SOFT_RESET_MS3      1	// 1
#define LCD_SET_4BITMODE_MS     5	// 5
 
#define LCD_CLEAR_DISPLAY_MS    2	// 2	
#define LCD_CURSOR_HOME_MS      2	// 2
 
////////////////////////////////////////////////////////////////////////////////
// Zeilendefinitionen des verwendeten LCD
// Die Einträge hier sollten für ein LCD mit einer Zeilenlänge von 20 Zeichen passen
// Bei anderen Zeilenlängen müssen diese Einträge angepasst werden
 
#define LCD_DDADR_LINE1         0
#define LCD_DDADR_LINE2         64
#define LCD_DDADR_LINE3         20
#define LCD_DDADR_LINE4         84
 
////////////////////////////////////////////////////////////////////////////////
// Initialisierung: muss ganz am Anfang des Programms aufgerufen werden.
void lcd_init( void );
 
////////////////////////////////////////////////////////////////////////////////
// LCD löschen
void lcd_clear( void );
 
////////////////////////////////////////////////////////////////////////////////
// Cursor in die 1. Zeile, 0-te Spalte
void lcd_home( void );
 
////////////////////////////////////////////////////////////////////////////////
// Cursor an eine beliebige Position 
void lcd_setcursor( uint8_t spalte, uint8_t zeile );
 
////////////////////////////////////////////////////////////////////////////////
// Ausgabe eines einzelnen Zeichens an der aktuellen Cursorposition 
void lcd_data( uint8_t data );
 
////////////////////////////////////////////////////////////////////////////////
// Ausgabe eines Strings an der aktuellen Cursorposition 
void lcd_string( const char *data );
 
////////////////////////////////////////////////////////////////////////////////
// Schreibt einen String auf das LCD mit erweiterten Parametern
// start:   Position des erstes Zeichens im String was ausgegeben werden soll
// length:  Maximale Anzahl der Zeichen die Ausgegeben werden sollen
void lcd_print(char *string, uint8_t start, uint8_t length);

////////////////////////////////////////////////////////////////////////////////
// Definition eines benutzerdefinierten Sonderzeichens.
// data muss auf ein Array[8] mit den Zeilencodes des zu definierenden Zeichens
// zeigen
void lcd_generatechar( uint8_t code, const uint8_t *data );
 
////////////////////////////////////////////////////////////////////////////////
// Ausgabe eines Kommandos an das LCD.
void lcd_command( uint8_t data );
 
 
////////////////////////////////////////////////////////////////////////////////
// LCD Befehle und Argumente.
// Zur Verwendung in lcd_command
 
// Clear Display -------------- 0b00000001
#define LCD_CLEAR_DISPLAY       0x01
 
// Cursor Home ---------------- 0b0000001x
#define LCD_CURSOR_HOME         0x02
 
// Set Entry Mode ------------- 0b000001xx
#define LCD_SET_ENTRY           0x04
 
#define LCD_ENTRY_DECREASE      0x00
#define LCD_ENTRY_INCREASE      0x02
#define LCD_ENTRY_NOSHIFT       0x00
#define LCD_ENTRY_SHIFT         0x01
 
// Set Display ---------------- 0b00001xxx
#define LCD_SET_DISPLAY         0x08
 
#define LCD_DISPLAY_OFF         0x00
#define LCD_DISPLAY_ON          0x04
#define LCD_CURSOR_OFF          0x00
#define LCD_CURSOR_ON           0x02
#define LCD_BLINKING_OFF        0x00
#define LCD_BLINKING_ON         0x01
 
// Set Shift ------------------ 0b0001xxxx
#define LCD_SET_SHIFT           0x10
 
#define LCD_CURSOR_MOVE         0x00
#define LCD_DISPLAY_SHIFT       0x08
#define LCD_SHIFT_LEFT          0x00
#define LCD_SHIFT_RIGHT         0x04
 
// Set Function --------------- 0b001xxxxx
#define LCD_SET_FUNCTION        0x20
 
#define LCD_FUNCTION_4BIT       0x00
#define LCD_FUNCTION_8BIT       0x10
#define LCD_FUNCTION_1LINE      0x00
#define LCD_FUNCTION_2LINE      0x08
#define LCD_FUNCTION_5X7        0x00
#define LCD_FUNCTION_5X10       0x04
 
#define LCD_SOFT_RESET          0x30
 
// Set CG RAM Address --------- 0b01xxxxxx  (Character Generator RAM)
#define LCD_SET_CGADR           0x40
 
#define LCD_GC_CHAR0            0
#define LCD_GC_CHAR1            1
#define LCD_GC_CHAR2            2
#define LCD_GC_CHAR3            3
#define LCD_GC_CHAR4            4
#define LCD_GC_CHAR5            5
#define LCD_GC_CHAR6            6
#define LCD_GC_CHAR7            7
 
// Set DD RAM Address --------- 0b1xxxxxxx  (Display Data RAM)
#define LCD_SET_DDADR           0x80
 
#endif 
