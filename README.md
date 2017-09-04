# C USART Library for Atmega16

C library for USART communication of AVR microcontroller Atmega16. Support 7 preddefined baudrates with the smallest baud rate error (-0.1% to 0.2%) for 16 Mhz clock frequency.

## Enum types

Initialisation of USART communitaion is done by function <i><b>UsartInit()</b></i> with four mandatory parameters:
- [E_baudrate](#baudrate) - set baudrate
- [E_framebits](#framebits) - set data frame format
- [E_parity](#paritybits) - set parity
- [E_stopbits](#stopbits) - set number of stop bits

Detailed information about every enum types and values are described in the next section.
### Baudrate
Baudrate enum types calculate UBRR value for selected baudrate. There can be added more baudrates as neccessary. The defined baudrates were selected with respect to the smallest calculating baud rate error for 16 Mhz frequency. 
```c
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
```
### Framebits
Framebits enum type defines frame format - number of transmitted and received data bits. Admissible values are 5, 6, 7, 8 and 9 bits
```c
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
} E_framebits;
```
### Paritybits
Parity enum type defines parity of data frame. Allowable values are disable parity, even parity - add one if the number of ones in data data frame is odd, and odd parity - add one if number of ones in data frame is even.
```c
/** @enum parity - none, even, odd */
typedef enum {
  // none
  PARITY_NONE = 0x00,
  // even
  PARITY_EVEN = 0x20,
  // odd
  PARITY_ODD  = 0x30
} E_parity;
```
### Stopbits
The last mandatory parameter in init function for USART communication is number of stop bits. There are two allowable values - 1 stop bit, 2 stop bits.
```c
/** @enum stop bits - 1, 2 */
typedef enum {
  // 1 stop bit
  STOPBITS_1 = 0x00,
  // 2 stop bits
  STOPBITS_2 = 0x20
} E_stopbits;
```
