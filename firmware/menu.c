#include "./menu.h"
#include "./gui_constants.h"

void menu_init(MENU_STRUCT *menu, MENU_ENTRY *menu_entrys, uint8_t menu_entry_count, uint8_t lcd_row_count)
{
    menu->entry_list = menu_entrys;
    menu->entry_count = menu_entry_count;
    menu->lcd_row_count = lcd_row_count;

    menu->pos = 0;
    menu->lcd_cursor_pos = 0;
    menu->lcd_window_pos = 0;

    menu->lcd_more_top_char = 0;
    menu->lcd_more_down_char = 1;

    menu->view_obsolete = 1;
}

void menu_set_root(MENU_STRUCT *menu)
{
    current_menu = menu;
}

#ifdef MENU_SIMULATION_QT
uint16_t menu_update(LCDWidget *lcd, uint8_t key_code)
#else
uint16_t menu_update(uint8_t key_code)
#endif
{
    uint8_t command = MC_NO_COMMAND;
    uint8_t value = 0x00;

    switch(key_code)
    {
    case KEY0_DOWN:
        if(current_menu->lcd_cursor_pos > 0)
        {
            current_menu->lcd_cursor_pos--;
            current_menu->view_obsolete = 1;
            command = MC_CHANGE_ENTRY;
            value = current_menu->entry_list[current_menu->lcd_window_pos + current_menu->lcd_cursor_pos].id;
        }
        else
        {
            if(current_menu->lcd_window_pos > 0)
            {
                current_menu->lcd_window_pos--;
                current_menu->view_obsolete = 1;
                command = MC_CHANGE_ENTRY;
                value = current_menu->entry_list[current_menu->lcd_window_pos + current_menu->lcd_cursor_pos].id;
            }
        }
        break;

    case KEY1_DOWN:
        if((current_menu->lcd_cursor_pos < current_menu->lcd_row_count-1) && (current_menu->lcd_cursor_pos < current_menu->entry_count-1))
        {
            current_menu->lcd_cursor_pos++;
            current_menu->view_obsolete = 1;
            command = MC_CHANGE_ENTRY;
            value = current_menu->entry_list[current_menu->lcd_window_pos + current_menu->lcd_cursor_pos].id;
        }
        else
        {
            if(current_menu->lcd_window_pos < current_menu->entry_count - current_menu->lcd_row_count)
            {
                current_menu->lcd_window_pos++;
                current_menu->view_obsolete = 1;
                command = MC_CHANGE_ENTRY;
                value = current_menu->entry_list[current_menu->lcd_window_pos + current_menu->lcd_cursor_pos].id;
            }
        }
        break;

    case KEY2_UP:
        // menu->lcd_window_pos + menu->lcd_cursor_pos = index in MenuEntryList
        command = MC_SELECT_ENTRY;
        value = current_menu->entry_list[current_menu->lcd_window_pos + current_menu->lcd_cursor_pos].id;

        switch (current_menu->entry_list[current_menu->lcd_window_pos + current_menu->lcd_cursor_pos].type)
        {
        case ENTRY_MENU:
            current_menu->entry_list[current_menu->lcd_window_pos + current_menu->lcd_cursor_pos].menu->parent_menu = current_menu;
            current_menu = current_menu->entry_list[current_menu->lcd_window_pos + current_menu->lcd_cursor_pos].menu;
            current_menu->view_obsolete = 1;
            break;

        case ENTRY_TO_PARENT:
            current_menu = current_menu->parent_menu;
            current_menu->view_obsolete = 1;
            break;

        case ENTRY_ONOFF:
        case ENTRY_BOOL:
        case ENTRY_BIN:
            current_menu->entry_list[current_menu->lcd_window_pos + current_menu->lcd_cursor_pos].var1 ^= 1;
            current_menu->entry_list[current_menu->lcd_window_pos + current_menu->lcd_cursor_pos].var1 &= 1;
            break;
        }

        break;

    case KEY2_TIMEOUT1:
        if(current_menu->parent_menu != 0)
        {
            current_menu = current_menu->parent_menu;
            current_menu->view_obsolete = 1;
        }
        else command = MC_EXIT_MENU;
        break;

    case KEY2_TIMEOUT2:
        break;
    }

    if(current_menu->view_obsolete)
    {
        current_menu->view_obsolete = 0;

        #ifdef MENU_SIMULATION_QT
        menu_refresh(lcd);
        #else
        menu_refresh();
        #endif
    }

    return command << 8 | value;
}

#ifdef MENU_SIMULATION_QT
void menu_refresh(LCDWidget *lcd)
#else
void menu_refresh()
#endif
{
    // Menu Neu Zeichnen
    lcd_clear();

    for(int i=0; i<current_menu->lcd_row_count && i<current_menu->entry_count; i++)
    {
        lcd_setcursor(1,i+1);
        lcd_string(current_menu->entry_list[i+current_menu->lcd_window_pos].name);

        switch(current_menu->entry_list[i+current_menu->lcd_window_pos].type)
        {
        case ENTRY_ONOFF:
                if(current_menu->entry_list[i+current_menu->lcd_window_pos].var1)
                    lcd_string(" On");
                else
                    lcd_string(" Off");
            break;
        case ENTRY_BIN:
                if(current_menu->entry_list[i+current_menu->lcd_window_pos].var1)
                    lcd_string(" 0");
                else
                    lcd_string(" 1");
            break;
       case ENTRY_BOOL:
                if(current_menu->entry_list[i+current_menu->lcd_window_pos].var1)
                    lcd_string(" true");
                else
                    lcd_string(" false");
            break;
        }

    }

    lcd_setcursor(0,current_menu->lcd_cursor_pos+1);
    lcd_data(current_menu->lcd_cursor_char);

    if(current_menu->lcd_window_pos > 0)
    {
        lcd_setcursor(19,1);
        lcd_data(current_menu->lcd_more_top_char);
    }

    if(current_menu->lcd_window_pos+current_menu->lcd_row_count < current_menu->entry_count)
    {
        lcd_setcursor(19,current_menu->lcd_row_count);
        lcd_data(current_menu->lcd_more_down_char);
    }
}

void menu_set_entry_var1(MENU_STRUCT *menu, uint8_t id, uint8_t var1)
{
    for(int i=0; i<menu->entry_count; i++)
    {
        if(menu->entry_list[i].id == id)
        {
            menu->entry_list[i].var1 = var1;
            break;
        }
    }
}

uint8_t menu_get_entry_var1(MENU_STRUCT *menu, uint8_t id)
{
    for(int i=0; i<menu->entry_count; i++)
    {
        if(menu->entry_list[i].id == id)
        {
            return menu->entry_list[i].var1;
            break;
        }
    }
    return 0;
}
