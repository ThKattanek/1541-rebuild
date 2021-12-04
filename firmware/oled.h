/* routines for OLED display */
// header
// implementation: F00K42
// last change: 18/09/2021

#ifndef _OLED_H_INCLUDE_
#define _OLED_H_INCLUDE_

#include <avr/io.h>
#include "i2c.h"
#include <util/delay.h>

#define OLED_I2C_ADDR_0 (0x3C)
#define OLED_I2C_ADDR_1 (0x3D)

////////////////////////////////////////////////////////////////////////////////
// setup the display
void oled_setup( void );

////////////////////////////////////////////////////////////////////////////////
// clear display
void oled_clear( void );

////////////////////////////////////////////////////////////////////////////////
// place display cursor top left
void oled_home( void );

////////////////////////////////////////////////////////////////////////////////
// set cursor position
void oled_setcursor( uint8_t spalte, uint8_t zeile );

////////////////////////////////////////////////////////////////////////////////
// write 1 character
void oled_data( uint8_t data );

////////////////////////////////////////////////////////////////////////////////
// write a string
void oled_string( const char *data );

////////////////////////////////////////////////////////////////////////////////
// write a substring of "string" starting at "start" with size "length"
void oled_print(char *string, uint8_t start, uint8_t length);

////////////////////////////////////////////////////////////////////////////////
// specify user-defined characters with "data"-bitmap
void oled_generatechar( uint8_t code, const uint8_t *data );

////////////////////////////////////////////////////////////////////////////////
// SSD1306 I2C Modes

#define SSD1306_I2C_COMMAND         (0x80)
#define SSD1306_I2C_DATA            (0x40)

////////////////////////////////////////////////////////////////////////////////
// SSD1306 Commands

#define SSD1306_SETCONTRAST         (0x81)
#define SSD1306_ALLON_RESUME        (0xA4)
#define SSD1306_ALLON               (0xA5)
#define SSD1306_NORMALDISPLAY       (0xA6)
#define SSD1306_INVERTDISPLAY       (0xA7)
#define SSD1306_DISPLAYOFF          (0xAE)
#define SSD1306_DISPLAYON           (0xAF)
#define SSD1306_SCROLL_H            (0x26)
#define SSD1306_SCROLL_V            (0x27)
#define SSD1306_SCROLL_HR_V         (0x29)
#define SSD1306_SCROLL_HL_V         (0x2A)
#define SSD1306_SCROLLSTOP          (0x2E)
#define SSD1306_SCROLLSTART         (0x2F)
#define SSD1306_SCROLL_V_AREA       (0xA3)
#define SSD1306_COLUMN_START_L      (0x00)
#define SSD1306_COLUMN_START_H      (0x10)
#define SSD1306_ADDRESSING_MODE     (0x20)
#define SSD1306_COLUMN_RANGE        (0x21)
#define SSD1306_PAGE_ADDRESS        (0x22)
#define SSD1306_PAGE_START          (0xB0)
#define SSD1306_DSP_STARTLINE       (0x40)
#define SSD1306_SEG_REMAP_0         (0xA0)
#define SSD1306_SEG_REMAP_127       (0xA1)
#define SSD1306_MULTIPLEX           (0xA8)
#define SSD1306_COM_LITTLEENDIAN    (0xC0)
#define SSD1306_COM_BIGENDIAN       (0xC8)
#define SSD1306_DISPLAY_OFFSET      (0xD3)
#define SSD1306_COM_PINS            (0xDA)
#define SSD1306_CLOCK_DIV           (0xD5)
#define SSD1306_PRECHARGE           (0xD9)
#define SSD1306_VCOMH_DESELECT      (0xDB)
#define SSD1306_NOP                 (0xE3)
#define SSD1306_CHARGEPUMP          (0x8D)


#endif  // _OLED_H_INCLUDE_
