// Ansteuerung eines HD44780 kompatiblen LCD im 4-Bit-Interfacemodus
// http://www.mikrocontroller.net/articles/HD44780
// http://www.mikrocontroller.net/articles/AVR-GCC-Tutorial/LCD-Ansteuerung
//
// Die Pinbelegung ist über defines in lcd-routines.h einstellbar
//
// adoption for portexpander PCF8574 via I2C:
// implementation: F00K42
// last change: 03/09/2021
// todo: search for I2C device-adress between 0x20-0x27, 0x38-0x3f

#include <avr/io.h>
#include "lcd.h"
#include "i2c.h"
#include <util/delay.h>

// definition of LCD-ROW offsets .. needed for setcursor-routine
const uint8_t lcd_rowoffset[] = { 0, 0x40, LCD_COLS, 0x40+LCD_COLS };

uint8_t DEV_I2C_ADDR;

////////////////////////////////////////////////////////////////////////////////
// Sendet eine Ausgabeoperation an das LCD
static void lcd_out( uint8_t data )
{
    (void)i2c_start();
    (void)i2c_write( (DEV_I2C_ADDR<<1) | I2C_WRITE);
    (void)i2c_write( data );
    i2c_stop();
}

static void lcd_enable( uint8_t data )
{
    lcd_out( data | LCD_EN );   // Enable auf 1 setzen
    _delay_us( LCD_ENABLE_US ); // kurze Pause
    lcd_out( data );            // Enable auf 0 setzen
}

////////////////////////////////////////////////////////////////////////////////
// Erzeugt einen Enable-Puls zusammen mit den Daten
static void lcd_out_enable( uint8_t data )
{
    lcd_out( data );        // Enable auf 0 setzen
    lcd_enable( data );
}

////////////////////////////////////////////////////////////////////////////////
// Testet eine I2C-Addresse auf Antwort
static uint8_t i2c_test(uint8_t addr)
{
    if ( 0x08 == i2c_start() )
    {
        if ( 0x18 == i2c_write( (addr<<1) | I2C_WRITE ) )
        {
            i2c_stop();
            return 1;
        }
    }
    i2c_stop();
    return 0;
}


////////////////////////////////////////////////////////////////////////////////
// Initialisierung: muss ganz am Anfang des Programms aufgerufen werden.
uint8_t lcd_init( void )
{
    // find display
    DEV_I2C_ADDR = 0;
    for (uint8_t i2c_addr = 0x20; i2c_addr<=0x3f; ++i2c_addr)
    {
        if ((0x27 < i2c_addr) && (0x38 > i2c_addr)) { continue; }

        if (i2c_test(i2c_addr))
        {
            DEV_I2C_ADDR = i2c_addr;
            break;
        }
    }
    if (0 == DEV_I2C_ADDR)
    {
        return 0;
    }

    // ---
    // warten auf die Bereitschaft des LCD
    _delay_ms( LCD_BOOTUP_MS );

    lcd_out( 0 );   // init all PCF8574 outputs to 0
    _delay_ms( 20 );

    // Soft-Reset muss 3mal hintereinander gesendet werden zur Initialisierung
    lcd_out_enable( LCD_SOFT_RESET );
    _delay_ms( LCD_SOFT_RESET_MS1 );

    lcd_enable( LCD_SOFT_RESET );
    _delay_ms( LCD_SOFT_RESET_MS2 );

    lcd_enable( LCD_SOFT_RESET );
    _delay_ms( LCD_SOFT_RESET_MS3 );

    // 4-bit Modus aktivieren 
    lcd_out_enable( LCD_SET_FUNCTION | LCD_FUNCTION_4BIT );
    _delay_ms( LCD_SET_4BITMODE_MS );

    // 4-bit Modus / 2 Zeilen / 5x7
    lcd_command( LCD_SET_FUNCTION |
                 LCD_FUNCTION_4BIT |
                 LCD_FUNCTION_2LINE |
                 LCD_FUNCTION_5X7 );

    // Display aus
    lcd_command( LCD_SET_DISPLAY |
                 LCD_DISPLAY_OFF |
                 LCD_CURSOR_OFF |
                 LCD_BLINKING_OFF);

    // Cursor inkrement / kein Scrollen
    lcd_command( LCD_SET_ENTRY |
                 LCD_ENTRY_INCREASE |
                 LCD_ENTRY_NOSHIFT );

    // Display ein / Cursor aus / Blinken aus
    lcd_command( LCD_SET_DISPLAY |
                 LCD_DISPLAY_ON |
                 LCD_CURSOR_OFF |
                 LCD_BLINKING_OFF);

    lcd_clear();
    return 1;
}

////////////////////////////////////////////////////////////////////////////////
// Sendet ein Datenbyte an das LCD
void lcd_data( uint8_t data )
{
    lcd_out_enable( ( data     & 0xF0) | LCD_RS | LCD_BACKLIGHT );    // zuerst die oberen, 
    lcd_out_enable( ((data<<4) & 0xF0) | LCD_RS | LCD_BACKLIGHT );    // dann die unteren 4 Bit senden

    _delay_us( LCD_WRITEDATA_US );
}

////////////////////////////////////////////////////////////////////////////////
// Sendet einen Befehl an das LCD
void lcd_command( uint8_t data )
{
    lcd_out_enable( ( data     & 0xF0) | LCD_BACKLIGHT );    // zuerst die oberen, 
    lcd_out_enable( ((data<<4) & 0xF0) | LCD_BACKLIGHT );    // dann die unteren 4 Bit senden

    _delay_us( LCD_COMMAND_US );
}

////////////////////////////////////////////////////////////////////////////////
// Sendet den Befehl zur Löschung des Displays
void lcd_clear( void )
{
    lcd_command( LCD_CLEAR_DISPLAY );
    _delay_ms( LCD_CLEAR_DISPLAY_MS );
}

////////////////////////////////////////////////////////////////////////////////
// Sendet den Befehl: Cursor Home
void lcd_home( void )
{
    lcd_command( LCD_CURSOR_HOME );
    _delay_ms( LCD_CURSOR_HOME_MS );
}

////////////////////////////////////////////////////////////////////////////////
// Setzt den Cursor in Spalte x (0..LCD_COLS) & Zeile y (0..LCD_ROWS)

void lcd_setcursor( uint8_t x, uint8_t y )
{
    uint8_t offset;
    if (LCD_ROWS > y)
    {
        offset = (lcd_rowoffset[y] + x) & 0x7F;
        lcd_command( LCD_SET_DDADR | offset );
    }
}

////////////////////////////////////////////////////////////////////////////////
// Schreibt einen String auf das LCD

void lcd_string( const char *data )
{
    while( *data != '\0' )
    {
        lcd_data( *data++ );
    }
}

////////////////////////////////////////////////////////////////////////////////
// Schreibt einen String auf das LCD mit erweiterten Parametern
// start:   Position des erstes Zeichens im String was ausgegeben werden soll
// length:  Maximale Anzahl der Zeichen die Ausgegeben werden sollen

void lcd_print(char *string, uint8_t start, uint8_t length)
{
    uint8_t char_counter = 1;
    uint8_t current_char = string[start];

    while((current_char != '\0') && ((char_counter-1) < length))
    {
        lcd_data(current_char);
        current_char = string[start+char_counter++];
    }
}

////////////////////////////////////////////////////////////////////////////////
// Schreibt ein Zeichen in den Character Generator RAM

void lcd_generatechar( uint8_t code, const uint8_t *data )
{
    // Startposition des Zeichens einstellen
    lcd_command( LCD_SET_CGADR | (code<<3) );

    // Bitmuster übertragen
    for ( uint8_t i=0; i<8; ++i )
    {
        lcd_data( data[i] );
    }
}
