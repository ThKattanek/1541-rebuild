#include "menu.h"

#ifdef MENU_SIMULATION_QT
    void MenuUpdate(LCDWidget *lcd)
#else
    void MenuUpdate()
#endif
{
    lcd_clear();
    lcd_setcursor(3,2);
    lcd_string("Test");
}
