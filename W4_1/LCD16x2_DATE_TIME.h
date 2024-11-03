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

int DAY = 0;
int MONTH = 0;
int YEAR = 0;
int SECOND = 0;
int MINUTE = 0;
int HOUR   = 0;

char DATE[] ="DATE: YYYY MM DD";
char TIME[] ="TIME: HH:MM:SS";
int  DAYS_OF_MON[]  ={-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

#define SET_DD_MM_YYYY(DD, MM, YYYY) {DAY = DD%31; MONTH = MM%12; YEAR = YYYY;}
#define SET_HH_MM_SS(HH, MM, SS) 	{HOUR = HH%24; MINUTE = MM%60; SECOND = SS%60;}

void GET_TIME_DATE(){
	//Get date/time from ds1307
	DS1307_READ(&YEAR, &MONTH, &DAY, &HOUR, &MINUTE, &SECOND);
	YEAR = (YEAR&0x0F) + (YEAR>>4)&0x0F;
	MONTH = (MONTH&0x0F) + ((MONTH>>4)&0x1)*10;
	DAY = (DAY&0x0F) + ((DAY>>4)&0x0F);
	HOUR = (HOUR&0xF) + ((HOUR>>4)&0x3);
	MINUTE = (MINUTE&0xF) + ((MINUTE>>4)&0x3);
	SECOND = (SECOND&0xF) + ((SECOND>>4)&0x3); 
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

int IS_LEAP_YEAR(){
	if( YEAR%100 == 0 ){
		if(YEAR%400 == 0)
			return 1;
		else
			return 0;
	}else{
		if(YEAR%4 == 0)
			return 1;
		else
			return 0;
	}
	return 0;
}

void INCREASE_YEAR(){
	++YEAR;
}

void INCREASE_MONTH(){
	if(MONTH >= 12){
		INCREASE_YEAR();
		MONTH = 1;
	}else{
		++MONTH;
	}
}

void INCREASE_DAY(){
	int LIM_DAY = DAYS_OF_MON[MONTH];
	if(MONTH >= 2 && IS_LEAP_YEAR()) ++LIM_DAY;
	if(DAY >= LIM_DAY){
		INCREASE_MONTH();
		DAY = 1;
	}else{
		++DAY;
	}
}

void INCREASE_HOUR(){
	if(HOUR >= 23){
		HOUR = 0;
		INCREASE_DAY();
	}else{
		++HOUR;
	}
}

void INCREASE_MINUTE(){
	if(MINUTE >= 59){
		MINUTE = 0;
		INCREASE_HOUR();
	}else{
		++MINUTE;
	}
}

void INCREASE_SECOND(){
	if(SECOND >= 59){
		SECOND = 0;
		INCREASE_MINUTE();
	}else{
		++SECOND;
	}
}

#endif