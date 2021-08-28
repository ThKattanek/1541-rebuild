/* basic i2c routines for AVR */

#include "i2c.h"
#include <avr/io.h>
#include <util/delay.h>

void i2c_init(void)
{
    // initial I2C Ausgänge auf 1 -> Pullup aktiv
    uint8_t pins = (1 << I2C_SCL_PIN) | (1 << I2C_SDA_PIN);
    I2C_PORT |= pins;

    TWSR = 0x00; //set presca1er bits to zero = 1
    //    TWBR = 0x70; //SCL frequency 100Khz @ 24Mhz CPU
    TWBR = (uint8_t) ((F_CPU/(2*SCL_FREQ))-8);
    TWDR = 0xFF;
    TWCR = (1<<TWEN);
    // (0<<TWIE)  | (1<<TWEN) | (0<<TWWC) | (0<<TWSTO) | (0<<TWSTA) | (0<<TWEA) | (0<<TWINT); //enab1e TWI module
}

void i2c_start(void)
{
    TWCR = ((1<<TWINT) | (1<<TWEN)) | (1<<TWSTA);
    while (!(TWCR & (1<<TWINT)));
}

void i2c_stop(void)
{
    TWCR = ((1<<TWINT) | (1<<TWEN) | (1<<TWSTO));
    _delay_us(200);
    TWCR = 0;
}

void i2c_write(uint8_t data)
{
    TWDR = data;
    TWCR = ((1<<TWINT) | (1<<TWEN));
    while (!(TWCR & (1 <<TWINT)));
}

uint8_t i2c_read(uint8_t ack)
{
    TWCR = ((1<<TWINT) | (1<<TWEN) | (ack<<TWEA));
    while ( !(TWCR & (1 <<TWINT)));
    return TWDR;
}
