<h1>C USART Library for Atmega16</h1>
<p>
C library for USART communication of AVR microcontroller Atmega16. Support 7 preddefined baudrates with the smallest baud rate error (-0.1% to 0.2%) for 16 Mhz clock frequency.
</p>
<h2>Enum types defined</h2>
<p>
Initialisation of USART communitaion is done with four enum types definition:
<ul>
  <li><b>E_baudrate</b></li>
  <li><b>E_framebits</b></li>
  <li><b>E_parity</b></li>
  <li><b>E_stopbits</b></li>  
</ul>
Detailed information about every enum types and values are described in next section.
<pre>
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
</p>
<h2>Function description</h2>

