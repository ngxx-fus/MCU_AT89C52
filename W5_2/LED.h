#include <REGX52.h>
#include "base_lib.h"

sbit GND0 = P2^2;
sbit GND1 = P2^3;
sbit GND2 = P2^4;
#define LED P0


const ubyte DIGIT_CODE[] = {0X3F, 0X06, 0X5B, 0X4F, 0X66, 0X6D,
                           0X7D, 0X07, 0X7F, 0X6F, 0X0, 0X1, 0x40, 0x8};

ubyte LED_CODE[8] = {0, 0, 0, 0, 0, 0, 0, 0};

void CHON_VITRI_LED7SEG(ubyte i){
    switch (i) {
        case 0x0:
            GND2 = 0; GND1 = 0; GND0 = 0; break; 
        case 0x1:
            GND2 = 0; GND1 = 0; GND0 = 1; break;
        case 0x2:
            GND2 = 0; GND1 = 1; GND0 = 0; break;
        case 0x3:
            GND2 = 0; GND1 = 1; GND0 = 1; break;
        case 0x4:
            GND2 = 1; GND1 = 0; GND0 = 0; break;
        case 0x5:
            GND2 = 1; GND1 = 0; GND0 = 1; break;
        case 0x6:
            GND2 = 1; GND1 = 1; GND0 = 0; break;
        case 0x7:
            GND2 = 1; GND1 = 1; GND0 = 1; break;
    }
}

void HIENTHI_8LED(){
    ubyte i = 0;
    ubyte j = 0;
    FOR(i, 0, 7){
        CHON_VITRI_LED7SEG(i);
        LED = LED_CODE[i];
        delay_us(50);
        LED = 0;
    }
}