/** 
 * USART Communication
 *
 * Copyright (C) 2016 Marian Hrinko.
 * Written by Marian Hrinko (mato.hrinko@gmail.com)
 *
 * @author      Marian Hrinko
 * @datum       11.07.2017
 * @file        usart.h
 * @tested      AVR Atmega16
 * @inspiration
 * ---------------------------------------------------
 */
 
#ifndef __USART_H__
#define __USART_H__

  #define F_CPU 16000000
  #define BAUD 9600
  #define BAUDRATE ((F_CPU)/(BAUD*16UL)-1)

  /**
   * @description Init UART
   * 
   * @param  void
   * @return void
   */
  void UsartInit (void);

  /**
   * @description USART transmit data
   *
   * @param  unsigned int
   * @return void
   */
  void UsartTransmit (unsigned int);

  /**
   * @description USART receive data
   *
   * @param  void
   * @return unsigned int
   */
  unsigned int UsartReceive (void);

  /**
   * @description Flush buffered data in receive buffer
   *
   * @param  void
   * @return void
   */
  void UsartFlush (void);

#endif
