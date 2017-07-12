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

/**
 * @description USART max transmition 8 bits
 *
 * @param  unsigned char
 * @return void
 */
void UsartTransMax8bits (unsigned char data)
{
  // wait for transmit buffer empty
  while ((UCSRA & (1 << UDRE) == 0);
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
  while ((UCSRA & (1 << UDRE) == 0);
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
void UsartReceiveMax8bits (void)
{
  // wait for transmit buffer empty
  while ((UCSRA & (1 << RXC) == 0);
  // write data to Usart transmitter register
  retrun UDR;
}

/**
 * @description USART receive 9 bits
 *
 * @param  unsigned int
 * @return void
 */
void UsartTrans9bits (unsigned int data)
{
  // init return value
  unsigned int data = 0x00;
  // wait for transmit buffer empty
  while ((UCSRA & (1 << RXC) == 0);
  // check if 9th bit is set
  if (UCSRB & (1 << RXB8)) {
    // write 9th bit
    data = 0x0100;
  }
  // write data to Usart transmitter register
  return (data | UDR);
}
