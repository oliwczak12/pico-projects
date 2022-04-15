/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"

long map(long x, long in_min, long in_max, long out_min, long out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

int xA[3]={3,4,5};
int yA[3]={0,1,2};
int time = 2;
int board[3][3];
void light(){
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if(board[i][j]==1){
        gpio_put(xA[i],1);
        gpio_put(yA[j],1);
        sleep_ms(2);
        gpio_put(xexit
        A[i],0);
        gpio_put(yA[j],0);
      }
    }
    
  }
  
}



int main() {
    stdio_init_all();
    for (int i = 0; i < 6; i++)
    {
    gpio_init(i);
    gpio_set_dir(i,GPIO_OUT);
    }
    
    for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        board[i][j]=0;
      }
      
    }
    

    while (1) {
      board[0][0] = 1;
      board[1][1] = 1;
      board[2][2] = 1;
      light();
    }
}
