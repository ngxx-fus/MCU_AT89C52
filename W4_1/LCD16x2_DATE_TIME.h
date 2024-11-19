/*
DOCUMENTATIONS:
	https://developer.arm.com/documentation/101655/0961/Cx51-User-s-Guide/Language-Extensions/Data-Types/Special-Function-Registers/sbit
*/
#ifndef _LCD16X2_DATE_TIME_H_
#define _LCD16X2_DATE_TIME_H_

#include <stdio.h>
#include <REGX52.h>
#include "LCD16x2.h"
#include "DS1307.h"

#define uchar unsigned char 
#define uint unsigned int  

uint DAY = 0;
uint MONTH = 0;
uint YEAR = 0;
uint SECOND = 0;
uint MINUTE = 0;
uint HOUR   = 0;

char DATE[] ="DATE: YYYY MM DD";
char TIME[] ="TIME: HH:MM:SS";

void GET_TIME_DATE(){
	//Get date/time from ds1307
	DS1307_READ(&YEAR, &MONTH, &DAY, &HOUR, &MINUTE, &SECOND);
	YEAR = (YEAR&0x0F) + ((YEAR>>4)&0x0F)*10;
	MONTH = (MONTH&0x0F) + (((MONTH>>4)&0x1))*10;
	DAY = (DAY&0x0F) + ((DAY>>4)&0x0F)*10;
	HOUR = (HOUR&0xF) + ((HOUR>>4)&0x3)*10;
	MINUTE = (MINUTE&0xF) + ((MINUTE>>4)&0x3)*10;
	SECOND = (SECOND&0xF) + ((SECOND>>4)&0x3)*10; 
}

void FORMAT_DATE(){
	DATE[9]  = (uchar)(YEAR%10) + '0';
	DATE[8]  = (uchar)((YEAR/10)%10) + '0';
	DATE[7]  = (uchar)((YEAR/100)%10) + '0';
	DATE[6]  = (uchar)((YEAR/1000)%10) + '0';
	DATE[12] = (uchar)(MONTH%10) + '0';
	DATE[11] = (uchar)((MONTH/10)%10) + '0';
	DATE[15] = (uchar)(DAY%10) + '0';
	DATE[14] = (uchar)((DAY/10)%10) + '0';
}

void FORMAT_TIME(){
	TIME[7] = (uchar)((HOUR/1)%10) + '0';
	TIME[6] = (uchar)((HOUR/10)%10) + '0';
	TIME[10] = (uchar)((MINUTE/1)%10) + '0';
	TIME[9] = (uchar)((MINUTE/10)%10) + '0';
	TIME[13] = (uchar)((SECOND/1)%10) + '0';
	TIME[12] = (uchar)((SECOND/10)%10) + '0';
}

void DISPLAY(){
	SET_CURSOR_POS(0, 0);
	FORMAT_DATE();
	SEND_BYTE_ARRAY_DISPLAY(DATE, 16);
	SET_CURSOR_POS(1, 0);
	FORMAT_TIME();
	SEND_BYTE_ARRAY_DISPLAY(TIME, 14);
}


#endif