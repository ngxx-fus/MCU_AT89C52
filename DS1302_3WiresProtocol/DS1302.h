/*
    Project: Comunicate with real-time DS1302 using Three Wires Protocol
    Header-File title: DS1302
    Author: Ngxx.fus
    Based on: DS1302-DATASHEET-DOWNLOAD.pdf
    Note: For more functions, pls read DS1302 datasheet and change the cmd, addr.
*/
#ifndef _DS1302_H_
#define  _DS1302_H_

#include "ThreeWiresProtocol.h"

enum enum_DAY{
    MON = 0,
    TUE,
    WED,
    THU,
    FRI,
    SAT,
    SUN
};

typedef struct TIME{
    uint DAY; // mon, tue, wed, thu, ...
    uint DATE;
    uint MONTH;
    uint YEAR;
    uint HOUR;
    uint MINUTE;
    uint SECOND;
} TIME;

void ds1302_read_time(TIME* time){
    uint x10, x1, byte_data, AM_PM;
    //second
    byte_data = single_byte_read(0x81);
    x10 = ((byte_data & 0x70) >> 4)*10;
    x1  = (byte_data & 0x0F);
    time->SECOND = x1 + x10;
    //minute
    byte_data = single_byte_read(0x83);
    x10 = ((byte_data & 0x70) >> 4)*10;
    x1  = (byte_data & 0x0F);
    time->MINUTE = x10 + x1;
    //hour
	byte_data = single_byte_read(0x85);
    if( (byte_data & 0x80) == HIGH){
        //12-hour mode
        x10 = ((byte_data & 0x10)>>4)*10;
        x1  = (byte_data & 0x0F);
        AM_PM = (byte_data&0x20)>>5;
        time->HOUR = x10 + x1 + AM_PM * 12;
    }else{
        //24-hour mode
        uint x10 = ((byte_data & 0x30)>>4)*10;
        uint x1  = (byte_data & 0x0F);
        time->HOUR = x10 + x1;
    }
    //date
    byte_data = single_byte_read(0x87);
    x10 = ((byte_data&0x30)>>4)*10;
    x1  = (byte_data&0x0F);
    time->DATE = x10 + x1;
    //month
    byte_data = single_byte_read(0x89);
    x10 = ((byte_data&0x10)>>4)*10;
    x1  = (byte_data&0x0F);
    time->MONTH = x10 + x1;
    //year
    byte_data = single_byte_read(0x87);
    x10 = ((byte_data&0xF0)>>4)*10;
    x1  = (byte_data&0x0F);
    time->YEAR = x10 + x1;
}

void ds1302_write_time(TIME* const time){
    uint x10 = 0, x1 = 0, byte_data = 0;
    //second
    x10 = (((*time).SECOND)/10)%10;
    x1  = ((*time).SECOND)%10;
    byte_data = (x10<<4) + x1;
    single_byte_write(0x80, byte_data);
    //minute
    x10 = ((time->MINUTE)/10)%10;
    x1  = (time->MINUTE)%10;
    byte_data = (x10<<4) + x1;
    single_byte_write(0x82, byte_data);
    //hour
    x10 = ((time->HOUR)/10)%10;
    x1  = (time->HOUR)%10;
    byte_data = (x10<<4) + x1;
    single_byte_write(0x84, byte_data);
}

void ds1302_initial(){
    ThreeWiresProtocol_Initial();
    single_byte_write(0x90, 0x5A);
}
#endif