#include "./settings.h"
#include "./gui_constants.h"

void settings_set_default_values()
{
    eeprom_update_dword((uint32_t*)SETTINGS_IDENTIFIER,0x15411541);
    eeprom_update_word((uint16_t*)SETTINGS_VERSION,1);
    eeprom_update_byte((uint8_t*)SETTINGS_PIN_PB2,0);
    eeprom_update_byte((uint8_t*)SETTINGS_PIN_PB3,0);
    eeprom_update_byte((uint8_t*)SETTINGS_INPUT_MODE,INPUT_MODE_BUTTON);
}
