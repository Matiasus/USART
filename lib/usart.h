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

  #define _FCPU 16000000
  #define _UBRR(BAUD) ((_FCPU)/(BAUD*16UL)-1)

  /** @enum UBRR values for different values */
  typedef enum {
    // baudrate  2400 / Error = -0.1% at 16Mhz
    BR_2400 = _UBRR(2400),
    // baudrate  4800 / Error =  0.2% at 16Mhz
    BR_4800 = _UBRR(4800),
    // baudrate  9600 / Error =  0.2% at 16Mhz
    BR_9600 = _UBRR(9600),
    // baudrate  19200 / Error = 0.2% at 16Mhz
    BR_19200 = _UBRR(19200),
    // baudrate  38400 / Error = 0.2% at 16Mhz
    BR_38400 = _UBRR(38400),
    // baudrate  76800 / Error = 0.2% at 16Mhz
    BR_76800 = _UBRR(76800),
    // baudrate 250000 / Error = 0.0% at 16Mhz
    BR_250000 = _UBRR(250000),
  } E_baudrate;

  /** @enum number of bits - 5, 6, 7, 8, 9 */
  typedef enum {
    // 5 bits
    DATA_5 = 0x00,
    // 6 bits
    DATA_6 = 0x02,
    // 7 bits
    DATA_7 = 0x04,
    // 8 bits
    DATA_8 = 0x06,
    // 9 bits
    DATA_9 = 0x43
  } E_bitsframe;

  /** @enum parity - none, even, odd */
  typedef enum {
    // none
    PARITY_NONE = 0x00,
    // even
    PARITY_EVEN = 0x20,
    // odd
    PARITY_ODD  = 0x30
  } E_parity;

  /** @enum stop bits - 1, 2 */
  typedef enum {
    // 1 stop bit
    STOPBITS_1 = 0x00,
    // 2 stop bits
    STOPBITS_2 = 0x20
  } E_stopbit;

  /**
   * @description Init UART
   * 
   * @param  Enum E_baudrate
   * @param  Enum E_bits
   * @param  Enum E_parity
   * @param  Enum E_stopbit   
   * @return void
   */
  void UsartInit (E_baudrate, E_bits, E_parity, E_stopbit);

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
   * @return void
   */
  void UsartFlush (void);

#endif
