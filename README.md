# C USART Library for Atmega16

C library for USART communication of AVR microcontroller Atmega16. Support 7 preddefined baudrates with the smallest baud rate error (-0.1% to 0.2%) for 16 Mhz clock frequency.

## Enum types

Initialisation of USART communitaion is done by function <i><b>UsartInit()</b></i> with four mandatory parameters:
- [EBaudrate](#baudrate) - set baudrate
- [EFramebits](#framebits) - set data frame format
- [EParity](#paritybits) - set parity
- [EStopbits](#stopbits) - set number of stop bits

Detailed information about every enum types and values are described in the next section.
### Baudrate
Baudrate enum types calculate UBRR value for selected baudrate. There can be added more baudrates as neccessary. The defined baudrates were selected with respect to the smallest calculating baud rate error for 16 Mhz frequency. 
```c
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
  eBR_250000 = _UBRR(250000),
} EBaudrate;
```
### Framebits
Framebits enum type defines frame format - number of transmitted and received data bits. Admissible values are 5, 6, 7, 8 and 9 bits
```c
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
```
### Paritybits
Parity enum type defines parity of data frame. Allowable values are disable parity, even parity - add one if the number of ones in data data frame is odd, and odd parity - add one if number of ones in data frame is even.
```c
/** @enum parity - none, even, odd */
typedef enum {
  // none
  ePARITY_NONE = 0x00,
  // even
  ePARITY_EVEN = 0x20,
  // odd
  ePARITY_ODD  = 0x30
} EParity;
```
### Stopbits
The last mandatory parameter in init function for USART communication is number of stop bits. There are two allowable values - 1 stop bit, 2 stop bits.
```c
/** @enum stop bits - 1, 2 */
typedef enum {
  // 1 stop bit
  eSTOPBITS_1 = 0x00,
  // 2 stop bits
  eSTOPBITS_2 = 0x20
} EStopbits;
```
### Example
Simple example receving and transmitting characters displayed on lcd screen with st7735 driver.
```c
/** 
 * Example of USART
 *
 * Copyright (C) 2017 Marian Hrinko.
 * Written by Marian Hrinko (mato.hrinko@gmail.com)
 *
 * @author      Marian Hrinko
 * @datum       12.07.2017
 * @file        main.c
 * @tested      AVR Atmega16
 * @inspiration 
 * ----------------------------------------------------------------------------------
 */
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include "lib/st7735.h"
#include "lib/usart.h"

/**
 * @desc    Simple example receving and transmitting characters displayed on lcd screen with st7735 driver.
 *
 * @param   Void
 * @return  Void
 */
int example(void)
{
  char i = 0;
  char val;
  // init usart
  UsartInit(eBR_38400, eDATA_8, ePARITY_ODD, eSTOPBITS_1);
  // init screen
  St7735Init();
  // clear screen
  ClearScreen(0x0000);
  // set text position
  SetPosition(5, 10);
  // draw text
  DrawString("Usart initialise... ", 0xffff, X1);
  // show RAM content of display
  UpdateScreen();
  // set text position
  SetPosition(5, 25);
  // loop sending chars
  while (i++ < 26) {
    // get value
    val = UsartReceive();
    // draw char
    DrawChar(val, 0xffff, X1);
    // set text position
    SetPosition(5 + 6*i, 25);
    // send back received value
    UsartTransmit(val);
    // show RAM content of display
    UpdateScreen();
  }
  // set text position
  SetPosition(5, 40);
  // draw text
  DrawString("Usart end communication...", 0xffff, X1);
  // show RAM content of display 
  UpdateScreen();
  // return & exit
  return 0;
}
```
