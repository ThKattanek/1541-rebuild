#ifndef MENUE_H
#define MENUE_H

#include <stdint.h>

#ifdef MENU_SIMULATION_QT
    #include "../menu_sim/lcd_widget.h"
    #define lcd_clear() lcd->Clear()
    #define lcd_home() lcd->Home()
    #define lcd_setcursor(column, row) lcd->SetCursor(column, row)
    #define lcd_data(data) lcd->Data(data)
    #define lcd_string(string) lcd->String(string)
    #define lcd_generatechar(code, data) lcd->SetUserChar(code, data)
#endif

struct MENU_ENTRY
{
    char *name;      // Name Menue Entry
    uint8_t typ;     // Entry Typ
};
typedef struct MENU_ENTRY MENU_ENTRY;

struct MENU
{
    MENU_ENTRY *entry_list;     // Zeiger auf Array vom TYPE MENU_ENTRY
    unsigned char entry_count;	// Anzahl von UMemüs
    unsigned char pos;          // Was ist gerade ausgewählt
};
typedef struct MENU MENU;

#ifdef MENU_SIMULATION_QT
    uint16_t menu_update(LCDWidget *lcd, uint8_t key_code);
#else
    uint16_t menu_update(uint8_t key_code);
#endif

#endif // MENUE_H

