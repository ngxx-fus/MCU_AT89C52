#ifndef _MATRIX_BUTTON_H_
#define _MATRIX_BUTTON_H_

#include "Base_Lib.h"

//       COL0 COL1 COL2 COL3
// ROW0   x    x    x    x 
// ROW1   x    x    x    x 
// ROW2   x    x    x    x 
// ROW3   x    x    x    x 

__sbit __at(p1_addr + 7 ) ROW0;
__sbit __at(p1_addr + 6 ) ROW1;
__sbit __at(p1_addr + 5 ) ROW2;
__sbit __at(p1_addr + 4 ) ROW3;

__sbit __at(p1_addr + 3 ) COL0;
__sbit __at(p1_addr + 2 ) COL1;
__sbit __at(p1_addr + 1 ) COL2;
__sbit __at(p1_addr + 0 ) COL3;

uint32 BTN_MATRIX = 0;

void Row_Write(uint8 I){
    switch (I){
        case 0:
            ROW0 = 0; ROW1 = 1; ROW2 = 1; ROW3 = 1;
            break;
        case 1:
            ROW0 = 1; ROW1 = 0; ROW2 = 1; ROW3 = 1;
            break;
        case 2:
            ROW0 = 1;  ROW1 = 1; ROW2 = 0; ROW3 = 1;
            break;
        case 3:
            ROW0 = 1;  ROW1 = 1; ROW2 = 1; ROW3 = 0;
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
        // delay_us(30);
        BTN_MATRIX |= (Col_Read()<<(4*i));
    }
    return BTN_MATRIX;
}

//ONLY return when user (release/push) a button
uint32 Get_BTN_MATRIX_2(){
    uint32 current_btn_matrix = Get_BTN_MATRIX();
    while( current_btn_matrix == Get_BTN_MATRIX()){
        current_btn_matrix = Get_BTN_MATRIX();
    }
    return BTN_MATRIX;
}
#endif