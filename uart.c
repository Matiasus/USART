/** 
 * UART Communication
 *
 * Copyright (C) 2016 Marian Hrinko.
 * Written by Marian Hrinko (mato.hrinko@gmail.com)
 *
 * @author      Marian Hrinko
 * @datum       11.07.2017
 * @file        usart.c
 * @tested      AVR Atmega16
 * @inspiration
 * ---------------------------------------------------
 */

#include <avr/io.h>
/**
 * @description Initialise USART communication
 *
 * @param  void
 * @return void
 */
void UsartInit (void)
{
  // definition of baud rate - speed of transmition
  // write high byte 
  UBRRH = (unsigned char) (UBRR_VAL >> 8);
  // write low byte
  UBRRL = (unsigned char) UBRR_VAL;
  // Enable receiving and transmitting
  USCRB = (1 << RXEN) 
        | (1 << TXEN);
  // asynchronous operation
  // with frame format 8 bits, even parity, 2 stop bits 
  UCSRC = (1 << URSEL)  // select USCRC register
        | (1 << UCSZ0)  // 8 bits data
        | (1 << UCSZ1)  //   -||- -||-
        | (1 << UPM1)   // even parity
        | (1 << USBS);  // 2 stop bits
}
