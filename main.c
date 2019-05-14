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
int main(void)
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
