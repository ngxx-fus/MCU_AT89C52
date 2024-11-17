/*
    Project: Comunicate with real-time DS1302 using Three Wires Protocol
    Header-File title: DS1302
    Author: Ngxx.fus
    Based on: DS1302-DATASHEET-DOWNLOAD.pdf
    Note: For more functions, pls read DS1302 datasheet and change the cmd, addr.
*/
#ifndef _DS1302_H_
#define  _DS1302_H_

#include "Time.h"
#include "Utilities.h"
#include "ThreeWiresProtocol.h"

//typedef unsigned int uint32;

enum enum_DAY{MON = 0, TUE, WED, THU, FRI, SAT, SUN};

#define ds1302_unlock_reg() single_byte_write(0x8E, 0x0)

/*
Read time from DS1302
mask: 
MSB  ... x    x    x    x    x    x   x   LSB 
         day  year mon  date hour min sec
x = 1: Choose
x = 0: Skip
FULL: 0x7F
*/
void DS1302_Read_Time(TIME* time, uint8 mask){
    uint8 x10, x1, byte_data, AM_PM;
    //second
    if(mask&0x1){
        ds1302_unlock_reg();
        byte_data = single_byte_read(0x81);
        x10 = ((byte_data & 0x70) >> 4)*10;
        x1  = (byte_data & 0x0F);
        time->SECOND = x1 + x10;
    }
    //minute
    if(mask&0x2){
        ds1302_unlock_reg();
        byte_data = single_byte_read(0x83);
        x10 = ((byte_data & 0x70) >> 4)*10;
        x1  = (byte_data & 0x0F);
        time->MINUTE = x10 + x1;
    }
    //hour
    if(mask&0x4){
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
    if(mask&0x8){
        ds1302_unlock_reg();
        byte_data = single_byte_read(0x87);
        x10 = ((byte_data&0x30)>>4)*10;
        x1  = (byte_data&0x0F);
        time->DATE = x10 + x1;
    }
    //month
    if(mask&0x10){
        ds1302_unlock_reg();
        byte_data = single_byte_read(0x89);
        x10 = ((byte_data&0x10)>>4)*10;
        x1  = (byte_data&0x0F);
        time->MONTH = x10 + x1;
    }
    //year
    if(mask&0x20){
        ds1302_unlock_reg();
        byte_data = single_byte_read(0x8D);
        x10 = ((byte_data&0xF0)>>4)*10;
        x1  = (byte_data&0x0F);
        time->YEAR = x10 + x1;
    }
    // //day
    // if(mask&0x40){
    //     x1  = (time->DAY)%10;
    //     ds1302_unlock_reg();
    //     single_byte_write(0x9A, x1);
    // }
}

void DS1302_Write_Time(TIME* const time, uint8 mask){
    uint8 x10 = 0, x1 = 0, byte_data = 0;
    //second
    if(mask&0x1){
        x10 = (((*time).SECOND)/10)%10;
        x1  = ((*time).SECOND)%10;
        byte_data = (x10<<4) + x1;
        ds1302_unlock_reg();
        single_byte_write(0x80, byte_data);
    }
    //minute
    if(mask&0x2){
        x10 = ((time->MINUTE)/10)%10;
        x1  = (time->MINUTE)%10;
        byte_data = (x10<<4) + x1;
        ds1302_unlock_reg();
        single_byte_write(0x82, byte_data);
    }
    //hour
    if(mask&0x4){
        x10 = ((time->HOUR)/10)%10;
        x1  = (time->HOUR)%10;
        byte_data = (x10<<4) + x1;
        ds1302_unlock_reg();
        single_byte_write(0x84, byte_data);
    }
    //date
    if(mask&0x8){
        x10 = ((time->DATE)/10)%10;
        x1  = (time->DATE)%10;
        byte_data = (x10<<4) + x1;
        ds1302_unlock_reg();
        single_byte_write(0x86, byte_data);
    }
    //month
    if(mask&0x10){
        x10 = ((time->MONTH)/10)%10;
        x1  = (time->MONTH)%10;
        byte_data = (x10<<4) + x1;
        ds1302_unlock_reg();
        single_byte_write(0x88, byte_data);
    }
    //year
    if(mask&0x20){
        x10 = ((time->YEAR)/10)%10;
        x1  = (time->YEAR)%10;
        byte_data = (x10<<4) + x1;
        ds1302_unlock_reg();
        single_byte_write(0x8C, byte_data);
    }
    //day
    if(mask&0x40){
        x1  = (time->DAY)%10;
        ds1302_unlock_reg();
        single_byte_write(0x9A, x1);
    }
}

void DS1302_Initial(){
    ThreeWiresProtocol_Initial();
}
#endif