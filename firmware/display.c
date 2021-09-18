/* general routines for display */
// implementation: F00K42
// last change: 18/09/2021

#include <avr/io.h>
#include "display.h"
#include "i2c.h"
#include "oled.h"
#include "lcd.h"

extern uint8_t DEV_I2C_ADDR;

uint8_t display_init(void)
{
    i2c_init();

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

    if ((OLED_I2C_ADDR_0 == DEV_I2C_ADDR) ||
        (OLED_I2C_ADDR_1 == DEV_I2C_ADDR))
    {
        // OLED attached via I2C
        display_setup       = &oled_setup;
        display_clear       = &oled_clear;
        display_data        = &oled_data;
        display_generatechar= &oled_generatechar;
        display_home        = &oled_home;
        display_print       = &oled_print;
        display_setcursor   = &oled_setcursor;
        display_string      = &oled_string;
    } else {
        // -> we may have an LCD attached
        display_setup       = &lcd_setup;
        display_clear       = &lcd_clear;
        display_data        = &lcd_data;
        display_generatechar= &lcd_generatechar;
        display_home        = &lcd_home;
        display_print       = &lcd_print;
        display_setcursor   = &lcd_setcursor;
        display_string      = &lcd_string;

        // select which low-level routines to use for communication with the display
        if (0 == DEV_I2C_ADDR)
        {
            // no answer from any I2C device
            // LCD may be directly attached via 10pin interface
            lcd_out = &par_lcd_out;
        } else {
            // LCD attached via PCF8574 / I2C
            lcd_out = &pcf_lcd_out;
        }
    }

    // call the right display setup routine.
    display_setup();

    return 1;
}
