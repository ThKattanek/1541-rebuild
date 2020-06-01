#ifndef SETTINGS_H
#define SETTINGS_H

#include <stdint.h>
#include <avr/eeprom.h>

#define SETTINGS_IDENTIFIER    0     // 4-Byte
#define SETTINGS_VERSION       4     // 2-Byte
#define SETTINGS_PIN_PB2       6     // 1-Byte
#define SETTINGS_PIN_PB3       7     // 1-Byte
#define SETTINGS_INPUT_MODE    8     // 1-Byte

void settings_set_default_values();

#endif // SETTINGS_H
