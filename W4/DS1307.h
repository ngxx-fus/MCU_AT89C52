#include <REGX52.h>
//#include "STACK_BUFFER.h"

#define uint unsigned int
#define uchar unsigned char

#define inverse(x) ((x>0)?(0):1)
#define pow2(x) (1U<<(x))

#define BIT_AT(x, i) (((x) & (1U<<(i)))?(1):(0))

// Config two pins suit for your demand.
// I2C pins
sbit SCL = P3^6;
sbit SDA = P3^7;

//              T_PEAK
// HIGH:        ______
//             /      \ T_PEAK /
// LOW :  ____/        \______/

uint T_PEAK = 3;
uint T_WAIT = 2;
uint PERIOD = 5;

void I2C_DELAY(uint t){
	uint i;
	for(i = 0; i < 12*t; i++);
}

// START CONDITION  
//             |---->|
// HIGH:     _________      
//        SCL  |     |\
// LOW :       |     | \_
// HIGH:     _____   |
//        SDA  |  \  |     
// LOW :       |   \_____         

void I2C_START(){
    SCL = 1; 
    SDA = 1;
    I2C_DELAY(T_WAIT);
    SDA = 0;
    I2C_DELAY(T_WAIT);
    SCL = 0; 
}

// STOP CONDITION 
//              |---->|
// HIGH:       _________    
//        SCL   |     |   
// LOW :        |     |
// HIGH:        |    ___
//        SDA   |   / |      
// LOW :       ____/  |       

void I2C_STOP(){
    uint i = 0;
    // initial
    SCL = 1;
    I2C_DELAY(T_WAIT);
    SDA = 0;
    I2C_DELAY(T_WAIT);
    SDA = 1;
    I2C_DELAY(T_WAIT);

}

void I2C_SDA_LOGIC_SET(unsigned int LOGIC_STATE){
    //I2C_DELAY(T_WAIT);
    SDA = (LOGIC_STATE)?(1):(0);
    //I2C_DELAY(T_WAIT);
}

void I2C_SCL_MONO_PULSE(){
    SCL = 0;
		I2C_DELAY(T_WAIT);
    SCL = 1;
    I2C_DELAY(T_PEAK);
		SCL = 0;
    I2C_DELAY(T_WAIT);
}

unsigned int I2C_SEND_BYTE(unsigned char DATA){
    uint i = 0;
    uint R_W = 0;
    uint pos = 0;
    for(i = 0; i < 7; i++){
        pos = 7-i;
        I2C_SDA_LOGIC_SET( BIT_AT(DATA, pos) );
        I2C_SCL_MONO_PULSE();
    }
    do{
        I2C_DELAY(T_WAIT);
        SCL = 1;
        R_W  = SDA;
        I2C_DELAY(T_WAIT);
        SCL = 0;
    } while(R_W);
}


unsigned int I2C_RECEIVE_BYTE(unsigned char NAK_ACK){
    uint res = 0;
    uint i = 0;
    uint RCV_BIT = 0;
    for( i = 0; i < 8; i++){
        SCL = 0;
        I2C_DELAY(T_WAIT);
        SCL = 1;
        RCV_BIT  = SDA;
        I2C_DELAY(T_WAIT);
        res += (RCV_BIT)*(pow2(7-i));
    }
    SDA = NAK_ACK;
    SCL = 0;
    I2C_DELAY(T_WAIT);
    SCL = 1;
    I2C_DELAY(T_WAIT);
    SCL = 0;
    return res;;
}