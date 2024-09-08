/*
DOCUMENTATIONS:
	https://developer.arm.com/documentation/101655/0961/Cx51-User-s-Guide/Language-Extensions/Data-Types/Special-Function-Registers/sbit
*/
#include <stdio.h>
#include <at89c51ed2.h>

void P2_SET(unsigned int LED){
	P2 = LED;
}

void delay_ms(unsigned int t){
	unsigned int i;
	for(i = 0; i < 12*t; i++);
}

void SANG_DAN_TAT_DAN(){
	unsigned int  LED = 0x0;
	while (1){
		if ( LED & 0x80) 
			LED = (LED<<1);
		else
			LED = (LED<<1) | 1U;
		P2_SET(LED);
		delay_ms(100);
	}
}

void SANG_DICH(){
	unsigned int LED = 0x1;
	while (1){
		if (LED == 0x0){
			LED = 0x1;
		}else{
			LED = LED << 0x1;
		}
		P2_SET(LED);
		delay_ms(100);
	}
	
}

void SANG_DOI_XUNG(){
	unsigned int SH = 0;
	while (1){
		if (SH & 0x4)
			P2_SET( (0x80>>(SH)) + (0x01<<(SH)));
		else
			P2_SET( (0x01<<(SH)) + (0x80>>(SH)));
		SH = (SH+0x1) % 8;
		delay_ms(400);
	}
	
}



void main(){
    SANG_DOI_XUNG();
}