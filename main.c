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
 * @inspiration http://www.displayfuture.com/Display/datasheet/controller/ST7735.pdf
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
  char i = 64;
  //char val = 0x00;
  char str[4];
  // init usart
  UsartInit();
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
  // zobrazenie 
  UpdateScreen();
  // set text position
  SetPosition(5, 30);
  // loop sending chars
  while (i++ < 68) {
    // zapis do retazca
    sprintf(str,"%d ", UsartReceiveMax8bits());
    // draw text
    DrawString(str, 0xffff, X1);
    // zobrazenie 
    UpdateScreen();
  }
  // set text position
  SetPosition(5, 50);
  // draw text
  DrawString("USART END", 0xffff, X2);
  // zobrazenie 
  UpdateScreen();
  // return & exit
  return 0;
}
