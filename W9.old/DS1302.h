/*
    Project: Comunicate with real-time DS1302 using Three Wires Protocol
    Header-File title: DS1302
    Author: Ngxx.fus
    Based on: DS1302-DATASHEET-DOWNLOAD.pdf
    Note: For more functions, pls read DS1302 datasheet and change the cmd, addr.
*/
#ifndef _DS1302_H_
#define  _DS1302_H_

#include "Base_Lib.h"
#include "ThreeWiresProtocol.h"

//typedef unsigned int uint32;

enum enum_DAY{MON = 0, TUE, WED, THU, FRI, SAT, SUN};

#define ds1302_unlock_reg() single_byte_write(0x8E, 0x0)

typedef struct TIME{
    uint8 DAY; // mon, tue, wed, thu, ...
    uint8 DATE;
    uint8 MONTH;
    uint8 YEAR;
    uint8 HOUR;
    uint8 MINUTE;
    uint8 SECOND;
} TIME;

/*
Time comparision
Choose what will be compared by using bit in MASK
MASK: 
             7    6    5     4    3     2     1   0
    MSB  ... x    x    x     x    x     x     x   x    LSB 
description       day  year  mon  date  hour  min sec
*/
uint8 time_equal(TIME A, TIME B, uint32 MASK){
    return (A.MINUTE == B.MINUTE) && (A.HOUR == B.HOUR);
    // if( (MASK&0x01) && (A.SECOND != B.SECOND) ) return 0;
    // if( (MASK&0x02) && (A.MINUTE != B.MINUTE) ) return 0;
    // if( (MASK&0x04) && (A.HOUR != B.HOUR) ) return 0;
    // if( (MASK&0x08) && (A.DATE != B.DATE) ) return 0;
    // if( (MASK&0x10) && (A.MONTH != B.MONTH) ) return 0;
    // if( (MASK&0x20) && (A.YEAR != B.YEAR) ) return 0;
    // if( (MASK&0x40) && (A.DAY != B.DAY) ) return 0;
    // if( (MASK&0x80) && (A.DATE != B.DATE) ) return 0;

    // // if( MASK != 0 ) return 1;
    // return 0;
}

/*
Read time from DS1302
SEL: 
MSB  ... x    x    x    x    x    x   x   LSB 
         day  year mon  date hour min sec
x = 1: Choose
x = 0: Skip
*/
void ds1302_read_time(TIME* time, uint8 SEL){
    uint8 x10, x1, byte_data, AM_PM;
    //second
    if(SEL&0x1){
        ds1302_unlock_reg();
        byte_data = single_byte_read(0x81);
        x10 = ((byte_data & 0x70) >> 4)*10;
        x1  = (byte_data & 0x0F);
        time->SECOND = x1 + x10;
    }
    //minute
    if(SEL&0x2){
        ds1302_unlock_reg();
        byte_data = single_byte_read(0x83);
        x10 = ((byte_data & 0x70) >> 4)*10;
        x1  = (byte_data & 0x0F);
        time->MINUTE = x10 + x1;
    }
    //hour
    if(SEL&0x4){
        ds1302_unlock_reg();
        byte_data = single_byte_read(0x85);
        if( (byte_data & 0x80) == HIGH){
            //12-hour mode
            x10 = ((byte_data & 0x10)>>4)*10;
            x1  = (byte_data & 0x0F);
            AM_PM = (byte_data&0x20)>>5;
            time->HOUR = x10 + x1 + AM_PM * 12;
        }else{
            //24-hour mode
            uint8 x10 = ((byte_data & 0x30)>>4)*10;
            uint8 x1  = (byte_data & 0x0F);
            time->HOUR = x10 + x1;
        }
    }
    //date
    if(SEL&0x10){
        ds1302_unlock_reg();
        byte_data = single_byte_read(0x87);
        x10 = ((byte_data&0x30)>>4)*10;
        x1  = (byte_data&0x0F);
        time->DATE = x10 + x1;
    }
    //month
    if(SEL&0x20){
        ds1302_unlock_reg();
        byte_data = single_byte_read(0x89);
        x10 = ((byte_data&0x10)>>4)*10;
        x1  = (byte_data&0x0F);
        time->MONTH = x10 + x1;
    }
    //year
    if(SEL&0x40){
        ds1302_unlock_reg();
        byte_data = single_byte_read(0x87);
        x10 = ((byte_data&0xF0)>>4)*10;
        x1  = (byte_data&0x0F);
        time->YEAR = x10 + x1;
    }
}

void ds1302_write_time(TIME* const time, uint8 SEL){
    uint8 x10 = 0, x1 = 0, byte_data = 0;
    //second
    if(SEL&0x1){
        x10 = (((*time).SECOND)/10)%10;
        x1  = ((*time).SECOND)%10;
        byte_data = (x10<<4) + x1;
        ds1302_unlock_reg();
        single_byte_write(0x80, byte_data);
    }
    //minute
    if(SEL&0x2){
        x10 = ((time->MINUTE)/10)%10;
        x1  = (time->MINUTE)%10;
        byte_data = (x10<<4) + x1;
        ds1302_unlock_reg();
        single_byte_write(0x82, byte_data);
    }
    //hour
    if(SEL&0x4){
        x10 = ((time->HOUR)/10)%10;
        x1  = (time->HOUR)%10;
        byte_data = (x10<<4) + x1;
        ds1302_unlock_reg();
        single_byte_write(0x84, byte_data);
    }
    //date
    if(SEL&0x8){
        x10 = ((time->DATE)/10)%10;
        x1  = (time->DATE)%10;
        byte_data = (x10<<4) + x1;
        ds1302_unlock_reg();
        single_byte_write(0x86, byte_data);
    }
    //month
    if(SEL&0x10){
        x10 = ((time->MONTH)/10)%10;
        x1  = (time->MONTH)%10;
        byte_data = (x10<<4) + x1;
        ds1302_unlock_reg();
        single_byte_write(0x88, byte_data);
    }
    //year
    if(SEL&0x20){
        x10 = ((time->YEAR)/10)%10;
        x1  = (time->YEAR)%10;
        byte_data = (x10<<4) + x1;
        ds1302_unlock_reg();
        single_byte_write(0x9C, byte_data);
    }
    //day
    if(SEL&0x40){
        x1  = (time->DAY)%10;
        ds1302_unlock_reg();
        single_byte_write(0x9A, x1);
    }
}

void ds1302_initial(){
    ThreeWiresProtocol_Initial();
}
#endif