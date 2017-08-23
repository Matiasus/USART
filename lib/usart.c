/** 
 * USART Communication
 *
 * Copyright (C) 2016 Marian Hrinko.
 * Written by Marian Hrinko (mato.hrinko@gmail.com)
 *
 * @author        Marian Hrinko
 * @datum         11.07.2017
 * @file          usart.c
 * @tested        AVR Atmega16
 * @inspiration
 * ---------------------------------------------------
 */
#include <stdio.h>
#include <avr/io.h>
#include "usart.h"

/**
 * @description Init UART
 * 
 * @param  Enum E_baudrate
 * @param  Enum E_bits
 * @param  Enum E_parity
 * @param  Enum E_stopbit   
 * @return void
 */
void UsartInit (E_baudrate baudrate, E_framebits framebits, E_parity parity, E_stopbits stopbits)
{
  // definition of baud rate - speed of transmition
  // write high byte 
  USART_UBRRH = (unsigned char) ((baudrate) >> 8);
  // write low byte
  USART_UBRRL = (unsigned char) baudrate;
  // Enable receiving and transmitting
  USART_UCSRB = (1 << RXEN) | (1 << TXEN);
  // check if selected 9 bits frame
  // high byte of "bits" carry information if 9 bits frame selected
  if (framebits & 0x40) {
    // set for 9 bits frame
    USART_UCSRB |= (1 << UCSZ2);
  }
  // write to register UCSRC
  USART_UCSRC = (1 << URSEL) | (framebits & 0x0f) | parity | stopbits;
}

/**
 * @description USART transmit data
 *
 * @param  unsigned int
 * @return void
 */
void UsartTransmit (unsigned int data)
{
  // wait for transmit buffer empty
  while ((USART_UCSRA & (1 << UDRE)) == 0);
  // clear 8th bit
  USART_UCSRB &= ~(1 << TXB8);
  // check if 9th bit is set
  if (data & 0x0100) {
    // write 9th bit
    USART_UCSRB |= (1 << TXB8);
  }
  // write data to Usart transmitter register
  USART_UDR = data;
}
         
/**
 * @description USART receive data
 *
 * @param  void
 * @return unsigned int
 */
unsigned int UsartReceive (void)
{
  // store uscra
  unsigned char ucsra;
  // store uscrb
  unsigned char ucsrb;
  // init return value
  unsigned int result = 0x00;
  // wait for transmit buffer empty
  while ((USART_UCSRA & (1 << RXC)) == 0);
  // store UCSRA register
  ucsra = USART_UCSRA;
  // store UCSRB register
  ucsrb = USART_UCSRB;
  // check error flags
  if (ucsra & ((1 << PE) | (1 << DOR) | (1 << FE))) {
    // error occur
    return -1;
  }
  // write 9th bit
  result = ucsrb & (1 << RXB8);
  // return all 9 bits
  return ((result >> 1) | USART_UDR);
}

/**
 * @description Flush buffered data from receive buffer
 *
 * @param  void
 * @return unsigned char
 */
unsigned char UsartFlush (void)
{
  // wait till receive complete
  while (USART_UCSRA & (1 << RXC));
  // flush the content of receive buffer
  return USART_UDR;
}
