/** 
 * USART Communication
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
#include <stdio.h>
#include <avr/io.h>
#include "usart.h"
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
  UBRRH = (unsigned char) ((BAUDRATE) >> 8);
  //UBRRH = 0x00;
  // write low byte
  UBRRL = (unsigned char) BAUDRATE;
  //UBRRL = 0x67;
  // Enable receiving and transmitting
  UCSRB = (1 << RXEN) 
        | (1 << TXEN);
  // asynchronous operation
  // with frame format 8 bits, even parity, 2 stop bits 
  UCSRC = (1 << URSEL)  // select USCRC register
        | (1 << UCSZ0)  // 8 bits data
        | (1 << UCSZ1)  //   -||- -||-
        | (1 << UPM1)   // even parity
        | (1 << USBS);  // 2 stop bits
}

/**
 * @description USART max transmition 8 bits
 *
 * @param  unsigned char
 * @return void
 */
void UsartTransMax8bits (unsigned char data)
{
  // wait for transmit buffer empty
  while ((UCSRA & (1 << UDRE)) == 0);
  // write data to Usart transmitter register
  UDR = data;
}
         
/**
 * @description USART transmition 9 bits
 *
 * @param  unsigned int
 * @return void
 */
void UsartTrans9bits (unsigned int data)
{
  // wait for transmit buffer empty
  while ((UCSRA & (1 << UDRE)) == 0);
  // clear 8th bit
  UCSRB &= ~(1 << TXB8);
  // check if 9th bit is set
  if (data & 0x0100) {
    // write 9th bit
    UCSRB |= (1 << TXB8);
  }
  // write data to Usart transmitter register
  UDR = data;
}
         
/**
 * @description USART received max 8 bits
 *
 * @param  void
 * @return unsigned char
 */
unsigned char UsartReceiveMax8bits (void)
{
  // wait for transmit buffer empty
  while ((UCSRA & (1 << RXC)) == 0);
  // write data to Usart transmitter register
  return UDR;
}

/**
 * @description USART receive 9 bits
 *
 * @param  void
 * @return unsigned int
 */
unsigned int UsartReceive9bits (void)
{
  // store uscra
  unsigned char ucsra;
  // store uscrb
  unsigned char ucsrb;
  // init return value
  unsigned int result = 0x00;
  // wait for transmit buffer empty
  while ((UCSRA & (1 << RXC)) == 0);
  // store UCSRA register
  ucsra = UCSRA;
  // store UCSRB register
  ucsrb = UCSRB;
  // check erro flags
  if (ucsra & ((1 << PE) | (1 << DOR) | (1 << FE))) {
    // error occur
    return -1;
  }
  // write 9th bit
  result = ucsrb & (1 << RXB8);
  // return all 9 bits
  return ((result >> 1) | UDR);
}
