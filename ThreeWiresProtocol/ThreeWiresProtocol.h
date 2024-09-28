#ifndef _THREE_WIRES_PROTOCOL_H_
#define _THREE_WIRES_PROTOCOL_H_

#include <REGX52.h>

// type define: "usigned int" -> "uint"
typedef unsigned int uint;

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

void single_byte_write(uint cmd, uint byte_data){
    uint nCLK = 0;
	//wait for sth un-finished to be finished :v
    delay_ms(10);
    //Reset to Start comunication
    CE = LOW; 
    IO = LOW;
    SCLK = LOW;
    delay_ms(10);
    //starting comunication
    CE = HIGH;
    //wait for sth un-finished to be finished :v
    delay_ms(10);
    // send cmd in 8 rasing edges 
    for(nCLK = 1; nCLK <= 8; nCLK++){
        IO = (cmd&0x1);
        SCLK = HIGH; delay_ms(10);
        SCLK = LOW; delay_ms(10);
        cmd = (cmd>>1);
    }
    // send byte_date in 8 rasing edges 
    for(nCLK = 1; nCLK <= 8; nCLK++){
        IO = (byte_data&0x1);
        SCLK = HIGH; delay_ms(10);
        SCLK = LOW; delay_ms(10);
        byte_data = (byte_data>>1);
    }
}

uint single_byte_read(uint cmd){
		uint nCLK;
    uint byte_date = 0;
    //wait for sth un-finished to be done :v
    delay_ms(10);
    //Reset to Start comunication
    CE = LOW; 
    IO = LOW;
    SCLK = LOW;
    delay_ms(10);
    //starting comunication
    //Send command at 8 rasing edge
    CE = HIGH;
    // 7 rasing edges 
    for(nCLK = 1; nCLK <= 7; nCLK++){
        IO = (cmd&0x1);
        SCLK = HIGH;
        delay_ms(10);
        SCLK = LOW;
        delay_ms(10);
        cmd = (cmd>>1);
    }
    // 8th rasing edge
    IO = (cmd&0x1);
    SCLK = HIGH;
    //Receiving byte_date at 8 falling edge following
    for(nCLK = 1; nCLK <= 7; nCLK++){
        delay_ms(10);
        SCLK = LOW;
        byte_date = ((byte_date<<1)|IO);
        delay_ms(10);
        SCLK = HIGH;
    }
    delay_ms(10);
    SCLK = LOW;
    CE = LOW;
    delay_ms(10);
    return byte_date;
}

void ThreeWiresProtocol_Initial(){
    IO = LOW;
    SCLK = LOW;
    CE = LOW;
}

#endif