
/*
 * Copyright (c) 2006-2012 by Roland Riegel <feedback@roland-riegel.de>
 *
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include <stdio.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/sfr_defs.h>
#include <avr/sleep.h>

#include "uart.h"

/* some mcus have multiple uarts */
#ifdef UDR0
#define UBRRH UBRR0H
#define UBRRL UBRR0L
#define UDR UDR0

#define UCSRA UCSR0A
#define UDRE UDRE0
#define RXC RXC0

#define UCSRB UCSR0B
#define RXEN RXEN0
#define TXEN TXEN0
#define RXCIE RXCIE0

#define UCSRC UCSR0C
#define URSEL 
#define UCSZ0 UCSZ00
#define UCSZ1 UCSZ01
#define UCSRC_SELECT 0
#else
#define UCSRC_SELECT (1 << URSEL)
#endif

#ifndef USART_RXC_vect
#if defined(UART0_RX_vect)
#define USART_RXC_vect UART0_RX_vect
#elif defined(UART_RX_vect)
#define USART_RXC_vect UART_RX_vect
#elif defined(USART0_RX_vect)
#define USART_RXC_vect USART0_RX_vect
#elif defined(USART_RX_vect)
#define USART_RXC_vect USART_RX_vect
#elif defined(USART0_RXC_vect)
#define USART_RXC_vect USART0_RXC_vect
#elif defined(USART_RXC_vect)
#define USART_RXC_vect USART_RXC_vect
#else
#error "Uart receive complete interrupt not defined!"
#endif
#endif

#define BAUD 9600UL
#define UBRRVAL (F_CPU/(BAUD*16)-1)
#define USE_SLEEP 1

void uart_init()
{
    /* set baud rate */
    UBRRH = UBRRVAL >> 8;
    UBRRL = UBRRVAL & 0xff;
    /* set frame format: 8 bit, no parity, 1 bit */
    UCSRC = UCSRC_SELECT | (1 << UCSZ1) | (1 << UCSZ0);
    /* enable serial receiver and transmitter */
#if !USE_SLEEP
    UCSRB = (1 << RXEN) | (1 << TXEN);
#else
    UCSRB = (1 << RXEN) | (1 << TXEN) | (1 << RXCIE);
#endif
}

void uart_putc(uint8_t c)
{
    if(c == '\n')
        uart_putc('\r');

    /* wait until transmit buffer is empty */
    while(!(UCSRA & (1 << UDRE)));

    /* send next byte */
    UDR = c;
}

void uart_putc_hex(uint8_t b)
{
    /* upper nibble */
    if((b >> 4) < 0x0a)
        uart_putc((b >> 4) + '0');
    else
        uart_putc((b >> 4) - 0x0a + 'a');

    /* lower nibble */
    if((b & 0x0f) < 0x0a)
        uart_putc((b & 0x0f) + '0');
    else
        uart_putc((b & 0x0f) - 0x0a + 'a');
}

void uart_putw_hex(uint16_t w)
{
    uart_putc_hex((uint8_t) (w >> 8));
    uart_putc_hex((uint8_t) (w & 0xff));
}

void uart_putdw_hex(uint32_t dw)
{
    uart_putw_hex((uint16_t) (dw >> 16));
    uart_putw_hex((uint16_t) (dw & 0xffff));
}

void uart_putw_dec(uint16_t w)
{
    uint16_t num = 10000;
    uint8_t started = 0;

    while(num > 0)
    {
        uint8_t b = w / num;
        if(b > 0 || started || num == 1)
        {
            uart_putc('0' + b);
            started = 1;
        }
        w -= b * num;

        num /= 10;
    }
}

void uart_putdw_dec(uint32_t dw)
{
    uint32_t num = 1000000000;
    uint8_t started = 0;

    while(num > 0)
    {
        uint8_t b = dw / num;
        if(b > 0 || started || num == 1)
        {
            uart_putc('0' + b);
            started = 1;
        }
        dw -= b * num;

        num /= 10;
    }
}

void uart_puts(const char* str)
{
    while(*str)
        uart_putc(*str++);
}

void uart_puts_p(PGM_P str)
{
    while(1)
    {
        uint8_t b = pgm_read_byte_near(str++);
        if(!b)
            break;

        uart_putc(b);
    }
}

uint8_t uart_getc()
{
    /* wait until receive buffer is full */
#if USE_SLEEP
    uint8_t sreg = SREG;
    sei();

    while(!(UCSRA & (1 << RXC)))
        sleep_mode();

    SREG = sreg;
#else
    while(!(UCSRA & (1 << RXC)));
#endif

    uint8_t b = UDR;
    if(b == '\r')
        b = '\n';

    return b;
}

EMPTY_INTERRUPT(USART_RXC_vect)

