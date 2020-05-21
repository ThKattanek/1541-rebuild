#include "./menu.h"
#include "./gui_constants.h"

void menu_init(MENU_STRUCT *menu, MENU_ENTRY *menu_entrys, uint8_t lcd_row_count)
{
    menu->lcd_row_count = lcd_row_count;
    menu->entry_list = menu_entrys;

    menu->pos = 0;
    menu->entry_count = 10;

    menu->view_obsolete = 1;
}

#ifdef MENU_SIMULATION_QT
    uint16_t menu_update(LCDWidget *lcd, MENU_STRUCT *menu, uint8_t key_code)
#else
    uint16_t menu_update(MENU_STRUCT *menu, uint8_t key_code)
#endif
{
    switch(key_code)
    {
    case KEY0_DOWN:
        break;

    case KEY1_DOWN:
        break;

    case KEY2_DOWN:
        break;
    }

    if(menu->view_obsolete)
    {
        menu->view_obsolete = 0;

        // Menu Neu Zeichnen
        lcd_clear();

        for(int i=0; i<menu->lcd_row_count; i++)
        {
            lcd_setcursor(1,i+1);
            lcd_string(menu->entry_list[i].name);
        }
    }

    return 0;
}
