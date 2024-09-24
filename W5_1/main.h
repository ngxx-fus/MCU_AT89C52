//---------- Include -----------
#include "LED7Seg_OnKit.h"
#include <stdio.h>

void delay(unsigned int mili_sec) {
  UINT i;
  for (i = 0; i < 12 * mili_sec; i++);
}

UINT NUM;
