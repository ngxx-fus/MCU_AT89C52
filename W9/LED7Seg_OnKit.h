//version: 0.1.3
//---------- Include -----------
#ifndef _LED7SEG_ONKIT_H_
#define _LED7SEG_ONKIT_H_
#include <REGX52.h>
// Thư viện cơ sở cho AT89C52
#include "Base_Lib.h"

//---------- Macros -----------


//Định nghĩa lại kiểu dữ liệu
//typedef unsigned int  uint;

//Các chân chọn vị trí LED.
sbit GND0 = P2^2;
sbit GND1 = P2^3;
sbit GND2 = P2^4;

//Chân điều khiển từng LED trong LED7seg
#define LED_7SEG P0

const uint8 DIGIT_CODE[] = {0X3F, 0X06, 0X5B, 0X4F, 0X66, 0X6D,
                           0X7D, 0X07, 0X7F, 0X6F, /*A*/0x77, 0x7C,
                           0x58, 0x5E, 0x79, 0x71};

uint8 LED[8] = {0, 0, 0, 0, 0, 0, 0, 0};

/*
  8   7   6   5   4   3   2   1  
  _   _   _   _   _   _   _   _  
 |_| |_| |_| |_| |_| |_| |_| |_|
 |_|.|_|.|_|.|_|.|_|.|_|.|_|.|_|.
Hàm này sẽ chọn LED ở vị trí POS, mã hiển thị là CODE.
VD: Hiển thị số "1", CODE = 0x06
*/
void led7seg_disp(uint8  POS, uint8  CODE){
    switch (POS) {
        case 0x1:
            { GND0 = 0; GND1 = 0; GND2 = 0; LED_7SEG = CODE; return;}
        case 0x2:
            { GND0 = 1; GND1 = 0; GND2 = 0; LED_7SEG = CODE; return;}
        case 0x3:
            { GND0 = 0; GND1 = 1; GND2 = 0; LED_7SEG = CODE; return;}
        case 0x4:
            { GND0 = 1; GND1 = 1; GND2 = 0; LED_7SEG = CODE; return;}
        case 0x5:
            { GND0 = 0; GND1 = 0; GND2 = 1; LED_7SEG = CODE; return;}
        case 0x6:
            { GND0 = 1; GND1 = 0; GND2 = 1; LED_7SEG = CODE; return;}
        case 0x7:
            { GND0 = 0; GND1 = 1; GND2 = 1; LED_7SEG = CODE; return;}
        case 0x8:
            { GND0 = 1; GND1 = 1; GND2 = 1; LED_7SEG = CODE; return;}
        default:
            LED_7SEG = 0x0;
    }
}


/*
Hiển thị trong ms_disp_t cả 8 LED7Seg.
Nội dung hiển thị của LED thứ i tuỳ thuộc vào 
giá trị chứa trong LED[i].

Giới hạn:
hz_freq =   24 Hz  --> 100Hz
ms_disp_t = 50 ms  --> 2500 ms

*/
void Disp8leds7seg(uint32 ms_disp_t){
    uint8 i = 0; 
    uint32 j = 0;
    REP(j, 1, ms_disp_t)
        REP(i, 0, 7){
            led7seg_disp(i+1, LED[i]);
            delay_us(5);
            LED_7SEG = 0x0;
        }
}

#endif