/*
    Project: Comunicate with real-time DS1302 using Three Wires Protocol
    Header-File title: Three Wires Protocol
    Author: Ngxx.fus
    Based on: DS1302-DATASHEET-DOWNLOAD.pdf
    Note: This header built for '8051 PRO' kit, to re-use the header file, 
          you need to edit CE, SCLK, IO pin and check the algorithm before use!
*/

#ifndef _THREE_WIRES_PROTOCOL_H_
#define _THREE_WIRES_PROTOCOL_H_

#include <REGX52.h>

// type define: "usigned int" -> "uint"
// typedef unsigned int uint;

static void delay_ms(uint t_mili_sec){
    uint i = 0; 
    for(i = 0; i < t_mili_sec*12; i = i + 1){
        // do nothin'
    }
}

enum enum_STATE{
    LOW  = 0,
    HIGH = 1
};

sbit CE = P3^5;
sbit SCLK = P3^6;
sbit IO = P3^4;
uint T_PEAK = 1; //Unit: mili-sec
uint IDLE_T = 1;
uint READ_T = 0;

static uint inverse_bit_ordered(uint byte_data){
	uint res = 0;
	res +=(byte_data & 0x1)<<7; byte_data = (byte_data >> 1);
	res +=(byte_data & 0x1)<<6; byte_data = (byte_data >> 1);
	res +=(byte_data & 0x1)<<5; byte_data = (byte_data >> 1);
	res +=(byte_data & 0x1)<<4; byte_data = (byte_data >> 1);
	res +=(byte_data & 0x1)<<3; byte_data = (byte_data >> 1);
	res +=(byte_data & 0x1)<<2; byte_data = (byte_data >> 1);
	res +=(byte_data & 0x1)<<1; byte_data = (byte_data >> 1);
	res +=(byte_data & 0x1)   ; byte_data = (byte_data >> 1);
	return res;
}

void single_byte_write(uint cmd, uint byte_data){
    uint nCLK = 0;
	//wait for sth un-finished to be finished :v
    delay_ms(IDLE_T);
    //Reset to Start comunication
    CE = LOW; 
    SCLK = LOW;
    delay_ms(T_PEAK);
    //starting comunication
    CE = HIGH;
    //wait for sth un-finished to be finished :v
    delay_ms(T_PEAK);
    // send cmd in 8 rasing edges 
    for(nCLK = 1; nCLK <= 8; nCLK++){
        IO = (cmd&0x1);
        SCLK = HIGH; delay_ms(T_PEAK);
        SCLK = LOW; delay_ms(T_PEAK);
        cmd = (cmd>>1);
    }
    // send byte_data in 8 rasing edges 
    for(nCLK = 1; nCLK <= 8; nCLK++){
        IO = (byte_data&0x1);
        SCLK = HIGH; delay_ms(T_PEAK);
        SCLK = LOW; delay_ms(T_PEAK);
        byte_data = (byte_data>>1);
    }

    CE = LOW; 
}

uint single_byte_read(uint cmd){
	uint nCLK;
    uint byte_data = 0xFF;
    uint bit_data = 0;
    //wait for sth un-finished to be done :v
    delay_ms(IDLE_T);
    //Reset to Start comunication
    CE = LOW; 
    SCLK = LOW;
    delay_ms(T_PEAK);
    //starting comunication
    //Send command at 8 rasing edge
    CE = HIGH;
    delay_ms(T_PEAK);
    // 7 rasing edges 
    for(nCLK = 1; nCLK <= 7; nCLK++){
        IO = (cmd&0x1);
        SCLK = HIGH;
        delay_ms(T_PEAK);
        SCLK = LOW;
        delay_ms(T_PEAK);
        cmd = (cmd>>1);
    }
    // 8th rasing edge
    IO = (cmd&0x1);
    SCLK = HIGH;
    //Receiving byte_data at 7 falling edge following
    for(nCLK = 1; nCLK <= 7; nCLK++){
        delay_ms(T_PEAK);
        SCLK = LOW;
        delay_ms(READ_T);
        bit_data = IO;
        byte_data = (((byte_data<<1)&0XFE)|(bit_data&0x1));
        delay_ms(T_PEAK-READ_T);
        SCLK = HIGH;
    }
    delay_ms(T_PEAK);
    SCLK = LOW;
    delay_ms(READ_T);
    bit_data = IO;
    byte_data = (((byte_data<<1)&0XFE)|(bit_data&0x1));
    delay_ms(T_PEAK-READ_T);
    
    CE = LOW; 
    return inverse_bit_ordered(byte_data);
}

void ThreeWiresProtocol_Initial(){
    IO = LOW;
    SCLK = LOW;
    CE = LOW;
}

#endif