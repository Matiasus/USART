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
 * @description Main function
 *
 * @param Void
 * @return Void
 */
int main(void)
{
  char i = 0;
  char val;
  char str[4];
  // init usart
  UsartInit(BR_9600, BIT_8, EVEN, STOP_1);
  // init screen
  St7735Init();
  // clear screen
  ClearScreen(0x0000);
  // set text position
  SetPosition(5, 10);
  // draw text
  DrawString("UBRRH ", 0xffff, X2);
  // zapis do retazca
  sprintf(str,"%d UBRRL ", UBRRH);
  // draw text
  DrawString(str, 0xffff, X2);
  // zapis do retazca
  sprintf(str,"%d", UBRRL);
  // draw text
  DrawString(str, 0xffff, X2);
  // show RAM content of display
  UpdateScreen();
  // set text position
  SetPosition(5, 30);
  // loop sending chars
  while (i++ < 10) {
    // get value
    val = UsartReceive();
    // write to string
    sprintf(str,"%d ", val);
    // draw text
    DrawString(str, 0xffff, X1);
    // send back received value
    UsartTransmit(val);
    // show RAM content of display
    UpdateScreen();
  }
  // set text position
  SetPosition(5, 50);
  // draw text
  DrawString("USART END", 0xffff, X1);
  // show RAM content of display 
  UpdateScreen();
  // return & exit
  return 0;
}
