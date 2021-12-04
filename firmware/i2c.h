/* basic i2c routines for AVR */
// header
// implementation: F00K42
// last change: 17/09/2021

#ifndef _I2C_INCLUDE_
#define _I2C_INCLUDE_

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <avr/io.h>

#define I2C_READ    (1)
#define I2C_WRITE   (0)

#define I2C_DDR     DDRC
#define I2C_PORT    PORTC
#define I2C_SDA_PIN PC1
#define I2C_SCL_PIN PC0

#define SCL_FREQ    (100000)

#ifndef F_CPU
#define F_CPU 24000000UL
#endif

void i2c_init(void);

uint8_t i2c_start(void);

void i2c_stop(void);

uint8_t i2c_write(uint8_t data);

uint8_t i2c_read(uint8_t ack);

uint8_t i2c_test(uint8_t addr);

#endif
