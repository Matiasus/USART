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

  // define clock
  #if defined(__AVR_ATMEGA8__)
    #ifndef _FCPU
      #define _FCPU 8000000
    #endif
  #elif defined(__AVR_ATMEGA16__)
    #ifndef _FCPU
      #define _FCPU 16000000
    #endif
  #endif
  // UBRR value
  #define _UBRR(BAUD) ((_FCPU)/(BAUD*16UL)-1)
  // define register for uart/usart communication
  #if defined(__AVR_ATMEGA8__) || defined(__AVR_ATMEGA16__) 
    #define USART_UBRRH UBRRH
    #define USART_UBRRL UBRRL
    #define USART_UCSRA UCSRA
    #define USART_UCSRB UCSRB
    #define USART_UCSRC UCSRC
    #define USART_UDR   UDR
  #endif

  /** @enum UBRR values for different values */
  typedef enum {
    // baudrate  2400 / Error = -0.1% at 16Mhz
    eBR_2400 = _UBRR(2400),
    // baudrate  4800 / Error =  0.2% at 16Mhz
    eBR_4800 = _UBRR(4800),
    // baudrate  9600 / Error =  0.2% at 16Mhz
    eBR_9600 = _UBRR(9600),
    // baudrate  19200 / Error = 0.2% at 16Mhz
    eBR_19200 = _UBRR(19200),
    // baudrate  38400 / Error = 0.2% at 16Mhz
    eBR_38400 = _UBRR(38400),
    // baudrate  76800 / Error = 0.2% at 16Mhz
    eBR_76800 = _UBRR(76800),
    // baudrate 250000 / Error = 0.0% at 16Mhz
    eBR_250000 = _UBRR(250000)
  } EBaudrate;

  /** @enum number of bits - 5, 6, 7, 8, 9 */
  typedef enum {
    // 5 bits
    eDATA_5 = 0x00,
    // 6 bits
    eDATA_6 = 0x02,
    // 7 bits
    eDATA_7 = 0x04,
    // 8 bits
    eDATA_8 = 0x06,
    // 9 bits
    eDATA_9 = 0x43
  } EFramebits;

  /** @enum parity - none, even, odd */
  typedef enum {
    // none
    ePARITY_NONE = 0x00,
    // even
    ePARITY_EVEN = 0x20,
    // odd
    ePARITY_ODD  = 0x30
  } EParity;

  /** @enum stop bits - 1, 2 */
  typedef enum {
    // 1 stop bit
    eSTOPBITS_1 = 0x00,
    // 2 stop bits
    eSTOPBITS_2 = 0x20
  } EStopbits;

  /**
   * @description Init UART
   * 
   * @param  Enum EBaudrate
   * @param  Enum EFramebits
   * @param  Enum EParity
   * @param  Enum EStopbit   
   * @return void
   */
  void UsartInit (EBaudrate, EFramebits, EParity, EStopbits);

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
   * @description Flush buffered data from receive buffer
   *
   * @param  void
   * @return unsigned char
   */
  unsigned char UsartFlush (void);

#endif
