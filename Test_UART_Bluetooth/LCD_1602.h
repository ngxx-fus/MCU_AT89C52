#ifndef _LCD_1602_H_
#define _LCD_1602_H_
/*
DOCUMENTATIONS:
	https://developer.arm.com/documentation/101655/0961/Cx51-User-s-Guide/Language-Extensions/Data-Types/Special-Function-Registers/sbit
	https://circuitdigest.com/article/16x2-lcd-display-module-pinout-datasheet
*/
/*
This lib was made to interfacing with LCD.
LCD's pin informatios:
  __ __ __ __ __ __ __ __ __ __ __ __ 
|  ################################   |
|  ################################   |
| __ __ __ __ __ __ __ __ __ __ __ __ |
    | | | | | | | | | |  |  |  |  |
    1 2 3 4 5 6 7 8 9 10 11 12 13 14

pin 0     - VSS - Connected to the ground of the MCU/ Power source
pin 1     - VDD - Connected to the supply pin of Power source
pin 2     - VEE - Connected to a variable POT that can source 0-5V
pin 3     - RS  - Toggles between Command/Data Register
pin 4     - RW  - Toggles the LCD between Read/Write Operation
pin 5     - E   - Must be held high to perform Read/Write Operation
Pin 7-14  - D   - Pins used to send Command or data to the LCD.

macro
*/

#include <stdio.h>
#include <REGX52.h>
#include "Utilities.h"

#define LCD_ON_CURSOR_ON            0x0F  //LCD ON, cursor ON
#define CLEAR_SCREEN                0x01  //Clear display screen
#define RETURN_HOME                 0x02  //Return home
#define LEFT_SHIFT_CURSOR           0x04  //Decrement cursor (shift cursor to left)
#define RIGHT_SHIFT_CURSOR          0x06  //Increment cursor (shift cursor to right)
#define LEFT_SHIFT_DISPLAY          0x05  //Shift display right
#define RIGHT_SHIFT_DISPLAY         0x07  //Shift display left
#define DISPLAY_ON_CURSOR_BLINKING  0x0E  //Display ON, cursor blinking
#define SET_CURSOR_0x_0y            0x80  //Force cursor to beginning of first line
#define SET_CURSOR_1x_0y            0xC0  //Force cursor to beginning of second line
#define LINEx2_MAT5x7               0x38  //2 lines and 5×7 matrix
#define CMD11                       0x83  //Cursor line 1 position 3
#define ACTIVATE_2nd_LINE           0x3C  //Activate second line
#define LCD_OFF_CURSOR_OFF          0x08  //Display OFF, cursor OFF
#define CMD14                       0xC1  //Jump to second line, position 1
#define LCD_ON_CURSOR_OFF           0x0C  //Display ON, cursor OFF
#define CMD16                       0xC1  //Jump to second line, position 1
#define CMD17       

#define WRITE_MODE 				0x0
#define READ_MODE 				0x1
#define SEND_CMD_MODE 			0x0
#define SEND_DISPLAY_DATA_MODE 	0x1


//	The variables bellow can be edited bases on
//  your circuit.
//	Set your LCD is in receiving command or receriving display data. 
sbit RS 		= P2^6; //RS pin
//	Set your LCD is READ mode or WRITE mode (usually write mode, be written by your MCU)
sbit RW 		  	= P2^5; //
//  Enable your LCD by a negedge pulse
sbit EN  			    = P2^7;

//  Receive or Transfer data (parallel)
#define DATA_PORT P0

//  Make a MONO pulse at EN pin
//  MONO pulse: LOW->HIGH (HIGH)*n HIGH->LOW :))
void LCD_ENABLE(){
	//Enable, a high to low pulse need to enable the LCD
	EN = 0x1;
	delay_us(50);
	EN = 0x0;
}


//	To sent command to the LCD.
void LCD_SEND_BYTE_COMMAND(unsigned char CMD){
	DATA_PORT = CMD;
	delay_us(50);
	RS = SEND_CMD_MODE;
	delay_us(50);
	RW   = WRITE_MODE;
	delay_us(50);
	LCD_ENABLE();
}

//	To sent a byte of DISPLAY DATA to the LCD.
void LCD_SEND_BYTE_DISPLAY(unsigned char BYTE){
	// NOTE: BYTE is displayed in ASCII.
	DATA_PORT = BYTE;
	delay_us(50);
	RS = SEND_DISPLAY_DATA_MODE;
	delay_us(50);
	RW = WRITE_MODE;
	delay_us(50);
	LCD_ENABLE();
}
//	To sent an array of byte of DISPLAY DATA to the LCD.
void LCD_SEND_BYTE_ARRAY_DISPLAY(char ARR[], uint8 SIZE){
    uint32 i = 0;
	if(SIZE<0)
		while(*ARR){
			LCD_SEND_BYTE_DISPLAY(*ARR);
			ARR++;
		}
	else
		while( i < SIZE ){
			LCD_SEND_BYTE_DISPLAY(ARR[i]);
			++i;
		}
}
//	Set the position of the CURSOR in 16x2 LCD screen.
void LCD_SET_CURSOR_POS(uint32 ROW, uint32 COL){
    if(ROW == 0){
        LCD_SEND_BYTE_COMMAND(SET_CURSOR_0x_0y+COL);
    }
    if(ROW == 1){
        LCD_SEND_BYTE_COMMAND(SET_CURSOR_1x_0y+COL);
    }
}

/*	
Set TEXT in LCD.
Limits:
	size : [0-->31]
	row  : [0-->1]
	col  : [0-->15]
	warp_text 	: [0->1]
	clear_screen : [0->1]
	row_offset	: [0->1]
	col_offset	: [0->15]
*/

void LCD_Set_Text(
	char str[],	uint8 str_size, 
	uint8 warp_text, uint8 clear_screen, 
	uint8 row_offset, uint8 col_offset){
	uint8 displayed = 0;
	if(clear_screen == true){
		LCD_SEND_BYTE_COMMAND(0x01);
	}
	if(warp_text == true){
		if( col_offset+(str_size-1) <= 15 ){
			// TEXT can be displayed in A ROW
			LCD_SET_CURSOR_POS(row_offset, col_offset);
			LCD_SEND_BYTE_ARRAY_DISPLAY(str, str_size);
		}else{
			// TEXT can NOT be displayed in A ROW
			// Display a mount of TEXT (which can be displayed)
			displayed = 15-col_offset+1;
			LCD_SET_CURSOR_POS(row_offset, 0);
			LCD_SEND_BYTE_ARRAY_DISPLAY(str, displayed);
			if(row_offset == 0){
				// If can be display at 2nd row
				LCD_SET_CURSOR_POS(1, 0);
				LCD_SEND_BYTE_ARRAY_DISPLAY(str+displayed, str_size-displayed);
			}else{
				// do nothin'
			}
		}
	}else{
		//un-warp text
		LCD_SET_CURSOR_POS(row_offset, col_offset);
		LCD_SEND_BYTE_ARRAY_DISPLAY(str, min_val(15-col_offset+1, str_size));
	}
}

//Simple to set TEXT which to be displayed in LCD WITHOUT CLEAR previous screen
void LCD_Simple_Set_Text_1(
		char str[],	uint8 str_size, 
		uint8 row_offset, uint8 col_offset
	){
	if(str_size == 0) { while(str[str_size++]); --str_size;}
	LCD_Set_Text(str, str_size, 0, 0, row_offset, col_offset);
}

//Simple to set TEXT which to be displayed in LCD WITH CLEAR previous screen
void LCD_Simple_Set_Text_2(
		char str[],	uint8 str_size, 
		uint8 row_offset, uint8 col_offset
	){
	if(str_size == 0) { while(str[str_size++]); --str_size;} // Cannot disp '\0' --> remove it! 
	LCD_Set_Text(str, str_size, 0, 1, row_offset, col_offset);
}

void LCD_Clear_Screen(){
	LCD_SEND_BYTE_COMMAND(CLEAR_SCREEN);
}

//  Set up your LCD.
void LCD_Initial(){
	delay_us(50);
	LCD_SEND_BYTE_COMMAND(LINEx2_MAT5x7);
	LCD_SEND_BYTE_COMMAND(LCD_ON_CURSOR_OFF);
	LCD_SEND_BYTE_COMMAND(RIGHT_SHIFT_CURSOR);
	LCD_SEND_BYTE_COMMAND(CLEAR_SCREEN);
	LCD_SEND_BYTE_COMMAND(SET_CURSOR_0x_0y);
}


#endif