/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"

long map(long x, long in_min, long in_max, long out_min, long out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

int xA[5]={3,4,5,6,7};
int yA[4]={8,0,1,2};
int time = 100;
int board[5][4];
int posX,posY;
int bufor = 0;
int apple = 0;

void light(){
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      if(board[i][j]==1){
        gpio_put(xA[i],1);
        gpio_put(yA[j],1);
        sleep_ms(2);
        gpio_put(xA[i],0);
        gpio_put(yA[j],0);
      }
      else if(board[i][j]==2){
        gpio_put(xA[i],1);
        gpio_put(yA[j],1);
        sleep_ms(20);
        gpio_put(xA[i],0);
        gpio_put(yA[j],0);
      }
    }
    
  }
  
}


int main() {
    stdio_init_all();
    adc_init();
    adc_gpio_init(27);
    adc_gpio_init(26);
    for (int i = 0; i < 9; i++)
    {
    gpio_init(i);
    gpio_set_dir(i,GPIO_OUT);
    }
    
    for (int i = 0; i < 5; i++)
    {
      for (int j = 0; j < 4; j++)
      {
        board[i][j]=0;
      }
      
    }
    

    while (1) {
        adc_select_input(1);
        uint aY = adc_read();
        adc_select_input(0);
        uint aX = adc_read();
        aX = map(aX,0,4050,10,1);
        aY = map(aY,20,4095,10,1);
        board[posX][posY] = 0;

        if(bufor == 0){
          if(aY<6 && posY != 0){
            posY--;
            bufor=time;
          }
          else if(aY>6 && posY != 3){
            posY++;
            bufor=time;
          }
          else if(aX<6 && posX != 0){
            posX--;
            bufor=time;
          }
          else if(aX>6 && posX != 4){
            posX++;
            bufor=time;
          }
        }
        if(bufor>0){
          bufor--;
        }
      board[posX][posY] = 1;
      
      light();
    }
}
