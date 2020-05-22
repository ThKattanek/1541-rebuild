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

enum MenuCommands {MC_NO_COMMAND, MC_SELECT_ENTRY, MC_CHANGE_ENTRY};

// MENU COMMANDS
// NO_COMMAND       -> Nicht ist passiert
// MC_SELECT_ENTRY  -> Menüpunkt wurde bestätigt  / Value: Menu Entry ID
// MC_CHANGE_ENTRY  -> Auswahlcursor wurde bewegt / Value: Menu Entry ID wo er jetzt drauf steht

struct MENU_ENTRY
{
    char *name;      // Name Menue Entry
    uint8_t id;      // Menu Entry ID
};
typedef struct MENU_ENTRY MENU_ENTRY;

struct MENU_STRUCT
{
    MENU_ENTRY *entry_list;     // Zeiger auf Array vom TYPE MENU_ENTRY
    uint8_t lcd_row_count;      // Anzahl der Zeilen des LCD Displays
    uint8_t lcd_cursor_char;    // Linkes Zeichen für die Auswahl
    uint8_t lcd_more_top_char;  // Zeichen wenn noch mehr Einträge sich oben befinden
    uint8_t lcd_more_down_char; // Zeichen wenn noch mehr Einträge sich unten befinden
    uint8_t entry_count;        // Anzahl von UMemüs
    uint8_t pos;                // Was ist gerade ausgewählt
    uint8_t lcd_cursor_pos;     // Position des Cursors auf dem LCD Display
    uint8_t lcd_window_pos;     // Position des Anzeigebereichs innerhablb der Menüeinträge
    uint8_t view_obsolete;      // 0=Anzeige ist noch aktuelle, 1=Anzeige muss neu aufgebaut werden
};
typedef struct MENU_STRUCT MENU_STRUCT;

void menu_init(MENU_STRUCT* menu, MENU_ENTRY *menu_entrys, uint8_t menu_entry_count, uint8_t lcd_row_count);

#ifdef MENU_SIMULATION_QT
    uint16_t menu_update(LCDWidget *lcd, MENU_STRUCT *menu, uint8_t key_code);
    void menu_refresh(LCDWidget *lcd, MENU_STRUCT *menu);
#else
    uint16_t menu_update(MENU_STRUCT *menu, uint8_t key_code);
    void menu_refresh(MENU_STRUCT *menu);
#endif

#endif // MENUE_H

