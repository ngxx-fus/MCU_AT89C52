#include <REGX52.h>

void delay_ms(int t){
    int i;
    for( i = 0; i < t*12; i++);
}

void main(){
    int LEDs = 0;
    P2 = LEDs;
    delay_ms(500);
    do{
        LEDs = (LEDs<<1) + 1;
        P2 = LEDs;
        delay_ms(500);
    }while(LEDs < 0xFF);
    do{
        LEDs = (LEDs<<1);
        P2 = LEDs;
        delay_ms(500);
    }while(LEDs > 0);
}