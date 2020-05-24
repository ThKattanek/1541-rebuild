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

// MC_EXIT_MENU wird ausgeführt wenn ein KEY2_TIMEOUT1 kommt und das Menü schon im Hauptmenü befindet
enum MenuCommands {MC_NO_COMMAND, MC_EXIT_MENU, MC_SELECT_ENTRY, MC_CHANGE_ENTRY};
enum MenuTypes {ENTRY_NORMAL, ENTRY_MENU, ENTRY_TO_PARENT,ENTRY_ONOFF, ENTRY_BOOL, ENTRY_BIN, ENTRY_8BIT_DEC};

// MENU COMMANDS
// NO_COMMAND       -> Nicht ist passiert
// MC_SELECT_ENTRY  -> Menüpunkt wurde bestätigt  / Value: Menu Entry ID
// MC_CHANGE_ENTRY  -> Auswahlcursor wurde bewegt / Value: Menu Entry ID wo er jetzt drauf steht

typedef struct MENU_ENTRY MENU_ENTRY;
typedef struct MENU_STRUCT MENU_STRUCT;

struct MENU_ENTRY
{
    char *name;         // Name Menue Entry
    uint8_t id;         // Menu Entry ID
    uint8_t type;       // Menu Entry Type
    uint8_t var1;       // Menu Variable1
    MENU_STRUCT *menu;  // Zeiger auf Untermenu
};

struct MENU_STRUCT
{
    MENU_STRUCT *parent_menu;   // Zeiger auf Übergeordnetes Menü
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


void menu_init(MENU_STRUCT* menu, MENU_ENTRY *menu_entrys, uint8_t menu_entry_count, uint8_t lcd_row_count);
void menu_set_root(MENU_STRUCT* menu);

#ifdef MENU_SIMULATION_QT
    uint16_t menu_update(LCDWidget *lcd, uint8_t key_code);
    void menu_refresh(LCDWidget *lcd);
#else
    uint16_t menu_update(uint8_t key_code);
    void menu_refresh();
#endif

    void menu_set_entry_var1(MENU_STRUCT *menu, uint8_t id, uint8_t var1);
    uint8_t menu_get_entry_var1(MENU_STRUCT *menu, uint8_t id);

static MENU_STRUCT *current_menu;

#endif // MENUE_H

