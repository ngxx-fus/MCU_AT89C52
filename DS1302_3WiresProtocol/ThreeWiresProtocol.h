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

typedef unsigned char ubyte;
typedef unsigned int uint;

static void delay_ms(uint t_mili_sec){
    uint i = 0; 
    for(i = 0; i < t_mili_sec*12; i = i + 1){
        // do nothin'
    }
}

enum enum_STATE{ LOW  = 0, HIGH = 1 };

sbit CE = P3^5;
sbit SCLK = P3^6;
sbit IO = P3^4;

ubyte T_PEAK = 1; //Unit: mili-sec
ubyte IDLE_T = 1;
ubyte READ_T = 0;

#define LH_MONO_PULSE(x) x = LOW; delay_ms(T_PEAK); x = HIGH; delay_ms(T_PEAK);
#define HL_MONO_PULSE(x) x = HIGH; delay_ms(T_PEAK); x = LOW; delay_ms(T_PEAK);

void single_byte_write(ubyte cmd, ubyte byte_data){
    ubyte nCLK = 0;
	//wait for sth un-finished to be finished :v
    delay_ms(IDLE_T);
    //Reset to Start comunication
    CE = LOW; SCLK = LOW;
    delay_ms(T_PEAK);
    //start comunication
    CE = HIGH;
    //wait for sth un-finished to be finished :v
    delay_ms(T_PEAK);
    // send cmd in 8 rasing edges 
    for(nCLK = 1; nCLK <= 8; nCLK++){
        IO = (cmd&0x1);
        HL_MONO_PULSE(SCLK);
        cmd = (cmd>>1);
    }
    // send byte_data in 8 rasing edges 
    for(nCLK = 1; nCLK <= 8; nCLK++){
        IO = (byte_data&0x1);
        HL_MONO_PULSE(SCLK);
        byte_data >>= 1;
    }

    //End write process
    CE = LOW; 
}

ubyte single_byte_read(ubyte cmd){
	ubyte nCLK;
    ubyte byte_data = 0, bit_data = 0;
    //wait for sth un-finished to be done :v
    delay_ms(IDLE_T);
    //Reset to Start comunication
    CE = LOW; 
    SCLK = LOW;
    delay_ms(T_PEAK);
    //starting comunication
    CE = HIGH;
    delay_ms(T_PEAK);
    //Send command at 8 rasing edge
    for(nCLK = 1; nCLK <= 7; nCLK++){
        IO = (cmd&0x1);
        HL_MONO_PULSE(SCLK);
        cmd = (cmd>>1);
    }
    // 8th rasing edge
    IO = (cmd&0x1);
    SCLK = HIGH; delay_ms(T_PEAK);
    //Receiving byte_data at 8 falling edge following
    for(nCLK = 0; nCLK <= 7; nCLK++){
        SCLK = LOW;  delay_ms(READ_T);
        bit_data = IO;
        byte_data = byte_data|((bit_data&0x1)<<nCLK);
        delay_ms(T_PEAK-READ_T);
        SCLK = HIGH; delay_ms(T_PEAK);
    }


    //End write process
    CE = LOW; 

    return byte_data;
}

void ThreeWiresProtocol_Initial(){
    IO = LOW;
    SCLK = LOW;
    CE = LOW;
}

#endif