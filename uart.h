/** 
 * UART Communication
 *
 * Copyright (C) 2016 Marian Hrinko.
 * Written by Marian Hrinko (mato.hrinko@gmail.com)
 *
 * @author      Marian Hrinko
 * @datum       11.07.2017
 * @file        uart.h
 * @tested      AVR Atmega16
 * @inspiration
 * ---------------------------------------------------
 */
 
#ifndef __UART_H__
#define __UART_H__

  #define FREQ 16000000
  #define BAUD 9600
  #define UBRR_VAL (FREQ/(16*BAUD))-1

  /**
   * @description Init UART
   * 
   * @param  void
   * @return void
   */
  void UartInit (void);

  /**
   * @description USART transmition max 8 bits 
   *
   * @param  unsigned char
   * @return void
   */
  void UsartTransMax8bits (unsigned char data);

  /**
   * @description USART transmition 9 bits 
   *
   * @param  unsigned int
   * @return void
   */
  void UsartTransMax8bits (unsigned int data);

#endif
