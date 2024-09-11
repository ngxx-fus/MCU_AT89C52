/*
DOCUMENTATIONS:
	https://developer.arm.com/documentation/101655/0961/Cx51-User-s-Guide/Language-Extensions/Data-Types/Special-Function-Registers/sbit
	https://circuitdigest.com/article/16x2-lcd-display-module-pinout-datasheet
*/
/*
This lib was made to interfacing with LCD.
LCD's pin informatios:
__ __ __ __ __ __ __ __ __ __ __ __ __
|  ################################  |
|  ################################  |
|                                    |
__ __ __ __ __ __ __ __ __ __ __ __ __
     | | | | | | | | | | | | | | | |
	 1 2 3 4 5 6 7 8 9 10111213141516 
	 
*/
#include <stdio.h>
#include <REGX52.h>
#include "LCD16x2_CMDs.h"

#define uint unsigned int

#define WRITE_MODE 0x0
#define READ_MODE 0x1
#define SEND_CMD_MODE 0x0
#define SEND_DISPLAY_DATA_MODE 0x1


//	The variables bellow can be edited bases on
//  your circuit.
//	Set your LCD is in receiving command or receriving display data. 
sbit REGISTER_SELECT 		= P1^5;
//	Set your LCD is READ mode or WRITE mode (usually write mode, be written by your MCU)
sbit READ_WRITE 		  	= P1^6;
//  Enable your LCD by a negedge pulse
sbit ENABLE  			    = P1^7;

//  Receive or Transfer data (parallel)
#define DATA_PORT P2

//	Make delay by do "nothing"
void DELAY(uint t){
	uint i;
	for(i = 0; i < 12*t; i++);
}
//  Make a MONO pulse at ENABLE pin
//  MONO pulse: LOW->HIGH (HIGH)*n HIGH->LOW :))
void ENABLE_LCD(){
	//Enable, a high to low pulse need to enable the LCD
	ENABLE = 0x1;
	DELAY(3);
	ENABLE = 0x0;
}
//	To sent command to the LCD.
void SEND_BYTE_COMMAND(unsigned char CMD){
	DATA_PORT = CMD;
	REGISTER_SELECT = SEND_CMD_MODE;
	READ_WRITE   = WRITE_MODE;
	ENABLE_LCD();
}
//	To sent a byte of DISPLAY DATA to the LCD.
void SEND_BYTE_DISPLAY(unsigned char BYTE){
	DATA_PORT = BYTE;
	REGISTER_SELECT = SEND_DISPLAY_DATA_MODE;
	READ_WRITE = WRITE_MODE;
	ENABLE_LCD();
}
//	To sent an array of byte of DISPLAY DATA to the LCD.
void SEND_BYTE_ARRAY_DISPLAY(unsigned char ARR[], uint SIZE){
    uint i = 0;
    while( i < SIZE ){
        SEND_BYTE_DISPLAY(ARR[i]);
        ++i;
    }
}
//	Set the position of the CURSOR in 16x2 LCD screen.
void SET_CURSOR_POS(uint ROW, uint COL){
    if(ROW == 0){
        SEND_BYTE_COMMAND(SET_CURSOR_0x_0y+COL);
    }
    if(ROW == 1){
        SEND_BYTE_COMMAND(SET_CURSOR_1x_0y+COL);
    }
}
//  Set up your LCD.
INITIAL(){
	SEND_BYTE_COMMAND(LCD_ON_CURSOR_OFF);
	DELAY(20);
	SEND_BYTE_COMMAND(LINEx2_MAT5x7);
    DELAY(20);
	SEND_BYTE_COMMAND(CLEAR_SCREEN);
}