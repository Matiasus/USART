/** 
 * UART Communication
 *
 * Copyright (C) 2016 Marian Hrinko.
 * Written by Marian Hrinko (mato.hrinko@gmail.com)
 *
 * @author      Marian Hrinko
 * @datum       11.07.2017
 * @file        uart.c
 * @tested      AVR Atmega16
 * @inspiration
 * ---------------------------------------------------
 */

#include <avr/io.h>
/**
 * @description Initialise UART communication
 *
 * @param  void
 * @return void
 */
void UartInit (void)
{
  // definition of baud rate - speed of transmition
  // write high byte 
  UBRRH = (unsigned char) (UBRR_VAL >> 8);
  // write low byte
  UBRRL = (unsigned char) UBRR_VAL;
  // Enable receiving and transmitting
  USCRB = (1 << RXEN) 
        | (1 << TXEN);
  // set frame format 8 bits, even parity, 2 stop bits, 
  UCSRC = (1 << URSEL)
        | (1 << UCSZ0)
        | (1 << UCSZ1)
        | (1 << UPM1)
        | (1 << USBS);
}
