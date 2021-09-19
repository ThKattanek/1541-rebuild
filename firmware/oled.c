/* routines for OLED display */
//
// access OLED display controller SSD1306 via I2C 
//
// implementation: F00K42
// last change: 19/09/2021

#include <avr/io.h>
#include "i2c.h"
#include "oled.h"
#include "Font_c64_ascii.h"
#include <util/delay.h>

extern uint8_t DEV_I2C_ADDR;

////////////////////////////////////////////////////////////////////////////////
// lowlevel routines to access SSD1306 display controller

void ssd1306_command( uint8_t data )
{
    (void)i2c_start();
    (void)i2c_write( (DEV_I2C_ADDR<<1) | I2C_WRITE);
    (void)i2c_write( SSD1306_I2C_COMMAND );    // flashfloppy uses 0x80 for commands
    (void)i2c_write( data );
    i2c_stop();
}

void ssd1306_data( uint8_t data )
{
    (void)i2c_start();
    (void)i2c_write( (DEV_I2C_ADDR<<1) | I2C_WRITE);
    (void)i2c_write( SSD1306_I2C_DATA );
    (void)i2c_write( data );
    i2c_stop();
}

////////////////////////////////////////////////////////////////////////////////
// setup the display
// see datasheet SSD1306 - p.64
void oled_setup( void )
{
    ssd1306_command(SSD1306_DISPLAYOFF);
    ssd1306_command(SSD1306_MULTIPLEX); 
    ssd1306_command(0x3F);
    ssd1306_command(SSD1306_DISPLAY_OFFSET);    
    ssd1306_command(0x00);                          // no offset
    ssd1306_command(SSD1306_DSP_STARTLINE | 0x00);  // line 0
    ssd1306_command(SSD1306_SEG_REMAP_127);         // rotate screen 180
    ssd1306_command(SSD1306_COM_LITTLEENDIAN);      // rotate screen 180
    ssd1306_command(SSD1306_COM_PINS);
    ssd1306_command(0x02);
    ssd1306_command(SSD1306_SETCONTRAST);
    ssd1306_command(0x7F);
    ssd1306_command(SSD1306_ALLON_RESUME);
    ssd1306_command(SSD1306_NORMALDISPLAY);
    ssd1306_command(SSD1306_CLOCK_DIV);
    ssd1306_command(0x80);
    ssd1306_command(SSD1306_CHARGEPUMP);
    ssd1306_command(0x14);                          // using internal VCC
    ssd1306_command(SSD1306_DISPLAYON);             // switch on Display
}

////////////////////////////////////////////////////////////////////////////////
// clear display
void oled_clear( void )
{
    for(uint8_t rows=0; rows<8; ++rows)
    {
        oled_setcursor(0, rows);
        (void)i2c_start();
        (void)i2c_write( (DEV_I2C_ADDR<<1) | I2C_WRITE);
        (void)i2c_write( SSD1306_I2C_DATA );
        for(uint8_t cols=0; cols<(16*8); ++cols)
        {
            (void)i2c_write( 0x00 );
            //delay(10);
        }
        i2c_stop();
    }
}

////////////////////////////////////////////////////////////////////////////////
// place display cursor top left
void oled_home( void )
{
    ssd1306_command(SSD1306_PAGE_START );
    ssd1306_command(SSD1306_COLUMN_START_L );
    ssd1306_command(SSD1306_COLUMN_START_H );
}

////////////////////////////////////////////////////////////////////////////////
// set cursor position
void oled_setcursor( uint8_t spalte, uint8_t zeile )
{
    ssd1306_command(SSD1306_PAGE_START | (7-zeile));
    ssd1306_command(SSD1306_COLUMN_START_L |  ((FONT_WIDTH*spalte)     & 0x0f));
    ssd1306_command(SSD1306_COLUMN_START_H | (((FONT_WIDTH*spalte)>>4) & 0x0f));
}

////////////////////////////////////////////////////////////////////////////////
// write 1 character
void oled_data( uint8_t data )
{
    if ((FONT_MINCHAR > data) || (FONT_MAXCHAR < data))
    {
        data = '?';
    }

    (void)i2c_start();
    (void)i2c_write( (DEV_I2C_ADDR<<1) | I2C_WRITE);
    (void)i2c_write( SSD1306_I2C_DATA );

    for(uint8_t char_height=0; char_height<FONT_HEIGHT; ++char_height)
    {
        (void)i2c_write( FontData[data-FONT_MINCHAR][char_height] );
    }
    i2c_stop();
}

////////////////////////////////////////////////////////////////////////////////
// write a string
void oled_string( const char *data )
{
    while( *data != '\0' )
    {
        oled_data( *data++ );
    }
}

////////////////////////////////////////////////////////////////////////////////
// write a substring of "string" starting at "start" with size "length"
void oled_print(char *string, uint8_t start, uint8_t length)
{
    uint8_t char_counter = 1;
    uint8_t current_char = string[start];

    while((current_char != '\0') && ((char_counter-1) < length))
    {
        oled_data(current_char);
        current_char = string[start+char_counter++];
    }
}

////////////////////////////////////////////////////////////////////////////////
// specify user-defined characters with "data"-bitmap
void oled_generatechar( uint8_t code, const uint8_t *data )
{
}
