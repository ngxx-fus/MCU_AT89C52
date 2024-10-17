// #include "main.h"
// #include "Matrix_Button.h"
#include <8052.h>

__sbit __at (0xa0+7) P27;
__sbit __at (0xa0+3) P23;


void main(void);

void main(void){
    int t = 0;
    for(t = 0; t < 1000; t = t + 1);
    P2 = 0xFF;
    for(t = 0; t < 1000; t = t + 1);
    P2 = 0x00;
}