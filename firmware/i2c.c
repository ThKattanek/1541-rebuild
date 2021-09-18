/* basic i2c routines for AVR */
// implementation: F00K42
// last change: 17/09/2021

#include "i2c.h"
#include <avr/io.h>
#include <util/delay.h>

void i2c_init(void)
{
    TWSR = (0<<TWPS1) | (0<<TWPS0); //set presca1er bits to zero = 1
    //    TWBR = 112; //SCL frequency 100Khz @ 24Mhz CPU
    //    TWBR = 22; //SCL frequency 400Khz @ 24Mhz CPU
    TWBR = (uint8_t) ((F_CPU/(2*SCL_FREQ))-8);
}

uint8_t i2c_start(void)
{
    TWCR = ((1<<TWINT) | (1<<TWEN)) | (1<<TWSTA);
    while (!(TWCR & (1<<TWINT)));
    return (uint8_t) (TWSR & 0xF8);
}

void i2c_stop(void)
{
    TWCR = ((1<<TWINT) | (1<<TWEN) | (1<<TWSTO));
    _delay_us(200);
    TWCR = 0;
}

uint8_t i2c_write(uint8_t data)
{
    TWDR = data;
    TWCR = ((1<<TWINT) | (1<<TWEN));
    while (!(TWCR & (1 <<TWINT)));
    return (uint8_t) (TWSR & 0xF8);
}

uint8_t i2c_read(uint8_t ack)
{
    TWCR = ((1<<TWINT) | (1<<TWEN) | (ack<<TWEA));
    while ( !(TWCR & (1 <<TWINT)));
    return TWDR;
}
