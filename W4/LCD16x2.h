/*
DOCUMENTATIONS:
	https://developer.arm.com/documentation/101655/0961/Cx51-User-s-Guide/Language-Extensions/Data-Types/Special-Function-Registers/sbit
	https://circuitdigest.com/article/16x2-lcd-display-module-pinout-datasheet
*/
#include <stdio.h>
#include <REGX52.h>
#include "LCD_CMDs.h"

#define WRITE_MODE 0x0
#define READ_MODE 0x1
#define SEND_CMD_MODE 0x0
#define SEND_DISPLAY_DATA_MODE 0x1


sbit REGISTER_SELECT 	= P1^5;
//Send command (0x0) or data to be display (0x1)
sbit READ_WRITE 		  = P1^6;
//Set READ/WRITE mode
sbit ENABLE  			    = P1^7;
//Negedge of pulse to enable LCD

#define DATA_PORT P2

void DELAY(unsigned int t){
	unsigned int i;
	for(i = 0; i < 12*t; i++);
}

void ENABLE_LCD(){
	//Enable, a high to low pulse need to enable the LCD
	ENABLE = 0x1;
	DELAY(5);
	ENABLE = 0x0;
}

void SEND_BYTE_COMMAND(unsigned char CMD){
	DATA_PORT = CMD;
	REGISTER_SELECT = SEND_CMD_MODE;
	READ_WRITE   = WRITE_MODE;
	ENABLE_LCD();
}

void SEND_BYTE_DISPLAY(unsigned char BYTE){
	DATA_PORT = BYTE;
	REGISTER_SELECT = SEND_DISPLAY_DATA_MODE;
	READ_WRITE = WRITE_MODE;
	ENABLE_LCD();
}

void SEND_BYTE_ARRAY_DISPLAY(unsigned char ARR[], unsigned int SIZE){
    unsigned int i = 0;
    while( i < SIZE ){
        SEND_BYTE_DISPLAY(ARR[i]);
        ++i;
    }
}

void SET_CURSOR_POS(unsigned int ROW, unsigned COL){
    if(ROW == 0){
        SEND_BYTE_COMMAND(CMD8+COL);
    }
    if(ROW == 1){
        SEND_BYTE_COMMAND(CMD9+COL);
    }
}

INITIAL(){
	SEND_BYTE_COMMAND(LCD_ON_CURSOR_OFF);
	DELAY(20);
	SEND_BYTE_COMMAND(LINEx2_MAT5x7);
    DELAY(20);
	SEND_BYTE_COMMAND(CLEAR_SCREEN);
}