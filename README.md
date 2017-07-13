<h1>C USART Library for Atmega16</h1>
<p>
C library for USART communication of AVR microcontroller Atmega16. Support 7 preddefined baudrates with the smallest baud rate error (-0.1% to 0.2%) for 16 Mhz clock frequency.
</p>
<h2>Enum types</h2>
<p>
Initialisation of USART communitaion is done by <i> UsartInit (E_baudrate, E_bits, E_parity, E_stopbit) </i> function where must be select four mandatory variables selected from defined enum types:
<ul>
  <li><b>E_baudrate</b> - set baudrate</li>
  <li><b>E_framebits</b> - set data frame format</li>
  <li><b>E_parity</b> - set parity</li>
  <li><b>E_stopbits</b> - set number of stop bits</li>  
</ul>
Detailed information about every enum types and values are described in the next section.
</p>
<p>
Baudrate enum types calculate UBRR value for selected baudrate. There can be added more baudrates as neccessary. The defined baudrates were selected with respect to the smallest calculating baud rate error for 16 Mhz frequency. 
</p>
<pre>
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
</pre>
<p>
Framebits enum type defines frame format - number of transmitted and received data bits. Admissible values are 5, 6, 7, 8 and 9 bits
</p>
<pre>
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
</pre>
<p>
Parity enum type defines parity of data frame. Allowable values are disable parity, even parity - add one if the number of ones in data data frame is odd, and odd parity - add one if number of ones in data frame is even.
</p>
<pre>
/** @enum parity - none, even, odd */
typedef enum {
  // none
  PARITY_NONE = 0x00,
  // even
  PARITY_EVEN = 0x20,
  // odd
  PARITY_ODD  = 0x30
} E_parity;
</pre>
<p>
The last mandatory parameter in init function for USART communication is number of stop bits. There are two allowable values - 1 stop bit, 2 stop bits.
</p>
<pre>
/** @enum stop bits - 1, 2 */
typedef enum {
  // 1 stop bit
  STOPBITS_1 = 0x00,
  // 2 stop bits
  STOPBITS_2 = 0x20
} E_stopbits;
</pre>
<h2>Function description</h2>

