/*
DOCUMENTATIONS:
	https://developer.arm.com/documentation/101655/0961/Cx51-User-s-Guide/Language-Extensions/Data-Types/Special-Function-Registers/sbit
*/
#include <stdio.h>
#include <REGX52.h>
#include "LCD16x2.h"

int DAY = 31;
int MONTH = 12;
int YEAR = 2023;
int SECOND = 55;
int MINUTE = 59;
int HOUR   = 23;

char DATE[] ="DATE: YYYY MM DD";
char TIME[] ="TIME: HH:MM:SS";
int  DAYS_OF_MON[]  ={-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void FORMAT_DATE(){
	DATE[9] = (unsigned char)(YEAR%10) + '0';
	DATE[8] = (unsigned char)((YEAR/10)%10) + '0';
	DATE[7] = (unsigned char)((YEAR/100)%10) + '0';
	DATE[6] = (unsigned char)((YEAR/1000)%10) + '0';
	DATE[12] = (unsigned char)(MONTH%10) + '0';
	DATE[11] = (unsigned char)((MONTH/10)%10) + '0';
	DATE[15] = (unsigned char)(DAY%10) + '0';
	DATE[14] = (unsigned char)((DAY/10)%10) + '0';
}

void FORMAT_TIME(){
	TIME[7] = (unsigned char)((HOUR/1)%10) + '0';
	TIME[6] = (unsigned char)((HOUR/10)%10) + '0';
	TIME[10] = (unsigned char)((MINUTE/1)%10) + '0';
	TIME[9] = (unsigned char)((MINUTE/10)%10) + '0';
	TIME[13] = (unsigned char)((SECOND/1)%10) + '0';
	TIME[12] = (unsigned char)((SECOND/10)%10) + '0';
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
	if(MONTH == 12){
		INCREASE_YEAR();
		MONTH = 1;
	}else{
		++MONTH;
	}
}

void INCREASE_DAY(){
	int LIM_DAY = DAYS_OF_MON[MONTH];
	if(MONTH == 2 && IS_LEAP_YEAR()) ++LIM_DAY;
	if(DAY == LIM_DAY){
		INCREASE_MONTH();
		DAY = 1;
	}else{
		++DAY;
	}
}

void INCREASE_HOUR(){
	if(HOUR == 23){
		HOUR = 0;
		INCREASE_DAY();
	}else{
		++HOUR;
	}
}

void INCREASE_MINUTE(){
	if(MINUTE == 59){
		MINUTE = 0;
		INCREASE_HOUR();
	}else{
		++MINUTE;
	}
}

void INCREASE_SECOND(){
	if(SECOND == 59){
		SECOND = 0;
		INCREASE_MINUTE();
	}else{
		++SECOND;
	}
}