
#ifndef _CALENDAR_ONKIT_H_
#define  _CALENDAR_ONKIT_H_

#include "LED7Seg_OnKit.h"
#include "DS1302.h"

#define A_DIGIT 0x77
#define P_DIGIT 0x73

#define VIEW_DATE 0x0
#define VIEW_TIME 0x1
#define SETTING_DATE 0x2
#define SETTING_TIME 0x3

sbit TRIGGER0 = P3^2;
sbit TRIGGER1 = P3^3;

uint MODE = VIEW_TIME;
uint EDIT_POS = 1;
uint F_EXIT = 0;

TIME time;

static void delay(unsigned int mili_sec) {
  uint i;
  for (i = 0; i < 12 * mili_sec; i++)
    if(F_EXIT) return;
}

void calendar_disp(){
    uint DATE_TIME_DISP = 3;
    uint MAX_LOOP_DISP = 60;
    uint i = 0;
    //Update time
    led7seg_disp(1, 0x0);
    delay(300);
    ds1302_read_time(&time);
	//run in a seccond
    
    FOR(i, 1, MAX_LOOP_DISP){
        digit_disp(8, (((time.HOUR)/10)%10)); 
        delay(DATE_TIME_DISP);
        digit_disp(7, ((time.HOUR)%10));
        delay(DATE_TIME_DISP);

        digit_disp(6, (((time.MINUTE)/10)%10)); 
        delay(DATE_TIME_DISP);
        digit_disp(5, ((time.MINUTE)%10));
        delay(DATE_TIME_DISP);

        digit_disp(4, (((time.MONTH)/10)%10)); 
        delay(DATE_TIME_DISP);
        digit_disp(3, (((time.MONTH)/1)%10)); 
        delay(DATE_TIME_DISP);

        digit_disp(2, (((time.YEAR)/10)%10)); 
        delay(DATE_TIME_DISP);
        digit_disp(1, ((time.YEAR)%10));
        delay(DATE_TIME_DISP);
    }
}

void calendar_initial(){
    EA = 1; EX0 = 1; IT0 = 1;
    ds1302_initial();
    time.SECOND = 3;
    time.MINUTE = 2;
    time.HOUR = 17;
    ds1302_write_time(&time);
}

static void Interrupt_Action(void) interrupt 0 {
    MODE = (MODE == VIEW_DATE)?(VIEW_TIME): (VIEW_DATE);
}

#endif