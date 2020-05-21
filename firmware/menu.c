#include "./menu.h"
#include "./gui_constants.h"

#ifdef MENU_SIMULATION_QT
    uint16_t menu_update(LCDWidget *lcd, uint8_t key_code)
#else
    uint16_t menu_update(uint8_t key_code)
#endif
{
    switch(key_code)
    {
    case KEY2_DOWN:
        return 1;
        break;
    }

    lcd_clear();
    lcd_setcursor(3,2);
    lcd_string("Test");

    return 0;
}
