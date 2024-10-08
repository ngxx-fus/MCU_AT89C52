#ifndef _MATRIX_BUTTON_H_
#define _MATRIX_BUTTON_H_

#include "Base_Lib.h"

//       COL0 COL1 COL2 COL3
// ROW0   x    x    x    x 
// ROW1   x    x    x    x 
// ROW2   x    x    x    x 
// ROW3   x    x    x    x 

sbit ROW0 = P1^7;
sbit ROW1 = P1^6;
sbit ROW2 = P1^5;
sbit ROW3 = P1^4;

sbit COL0 = P1^3;
sbit COL1 = P1^2;
sbit COL2 = P1^1;
sbit COL3 = P1^0;

uint32 BTN_MATRIX = 0;

void Row_Write(uint8 I){
    switch (I){
        case 0:
            ROW0 = 0;
            break;
        case 1:
            ROW1 = 0;
            break;
        case 2:
            ROW2 = 0;
            break;
        case 3:
            ROW3 = 0;
            break;
    }
}

uint32 Col_Read(){
    uint32 COL = 0;
    if(COL0 == 0) COL += 1;
    if(COL1 == 0) COL += 2;
    if(COL2 == 0) COL += 4;
    if(COL3 == 0) COL += 8;
    return COL&0x0F;
}

uint32 Get_BTN_MATRIX(){
    uint32 i = 0;
    BTN_MATRIX = 0;
    for(i = 0; i < 4; ++i){
        Row_Write(i);
        delay_us(10);
        BTN_MATRIX |= (Col_Read()<<(4*i));
    }
    return BTN_MATRIX;
}


#endif