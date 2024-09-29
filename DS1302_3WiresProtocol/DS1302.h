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

typedef struct DATETIME{
    uint DAY;
    uint MONTH;
    uint YEAR;
    uint HOUR;
    uint MINUTE;
    uint SECOND;
} DATETIME;

DATETIME datetime;

void retrieve_second(){
	uint x10, x1;
    uint byte_data;
    byte_data = single_byte_read(0x81);
    x10 = ((byte_data & 0x70) >> 4)*10;
    x1  = (byte_data & 0x0F);
    datetime.SECOND = x1 + x10;
}

void retrieve_minute(){
    uint byte_data;
	uint x10, x1;
	byte_data = single_byte_read(0x83);
    x10 = ((byte_data & 0x70) >> 4)*10;
    x1  = (byte_data & 0x0F);
    datetime.MINUTE = x10 + x1;
}

void retrieve_hour(){
    uint byte_data;
	uint x10, x1, AM_PM;  
	byte_data = single_byte_read(0x85);
    if( (byte_data & 0x80) == LOW){
        //12-hour mode
        x10 = ((byte_data & 0x10)>>4)*10;
        x1  = (byte_data & 0x0F);
        AM_PM = (byte_data&0x20)>>5;
        datetime.HOUR = x10 + x1 + AM_PM * 12;
    }else{
        uint x10 = ((byte_data & 0x30)>>4)*10;
        uint x1  = (byte_data & 0x0F);
        datetime.HOUR = x10 + x1;
    }
}

void ds1302_read_datetime(){
    retrieve_second();
    retrieve_minute();
    retrieve_hour();
}



void ds1302_initial(){
    ThreeWiresProtocol_Initial();
}

#endif