/*
DOCUMENTATIONS:
    https://electronics.stackexchange.com/questions/29700/what-is-the-i2c-ack-and-how-do-i-detect-it
    https://stackoverflow.com/questions/37040696/nack-and-ack-responses-on-i2c-bus
    https://www.i2c-bus.org/repeated-start-condition/
NOTE:
    Using static keyword to make the function prevent conflict :v
*/

#ifndef _DS1307_H_
#define _DS1307_H_

#include <REGX52.h>
//#include "STACK_BUFFER.h"

typedef  unsigned int uint;
typedef  unsigned char uchar;

#define logic_inverse(x) ((x>0)?(0):1)
#define POW2(x) (1U<<(x))

#define bit_at(x, i) (((x) & (1U<<(i)))?(1):(0))

#define MASK_8BIT 0x0FF

//  |<-ADDR->   R
//  1101__000   0
#define SLAVE_ADDR_W 0xD0 //Slave addr of DS1307 <0x68> concat with #R bit <0>
//  |<-ADDR->   W
//  1101__000   1
#define SLAVE_ADDR_R 0xD1 //Slave addr of DS1307 <0x68> concat with W bit <1>
#define CONTROL_REG_ADDR 0x07

#define SET_SCL(LOGIC_STATE) SCL = (LOGIC_STATE)?(1):(0)
#define SET_SDA(LOGIC_STATE) SDA = (LOGIC_STATE)?(1):(0)
#define I2C_WRITE_TO_ADDR(ADDR)  ((ADDR<<1)|(0x1))
#define I2C_READ_FROM_ADDR(ADDR) ((ADDR<<1)|(0x0))

enum LOGIC_LEVEL {LOW = 0, HIGH = 1};
enum SLAVE_STATE  {ACK = 0, NAK  = 1};

// Config two pins suit for your demand.
// I2C pins
sbit SCL = P0^0;
sbit SDA = P0^1;

//              T_PEAK
// HIGH:        ______
//             /      \ T_PEAK /
// LOW :  ____/        \______/

uint T_PEAK = 5;
uint T_WAIT = 2;
uint PERIOD = 5;

// Do stuff things to make delay :v
static void DELAY(uint t){
	uint i;
	for(i = 0; i < 12*t; i++);
}

// START CONDITION  
//             |---->|
// HIGH:     ________      
//        SCL        |
// LOW :             |____
// HIGH:     _____ 
//        SDA     |     
// LOW :          |_______         
void I2C_START(){
    DELAY(T_PEAK);
    SET_SCL(HIGH); 
    SET_SDA(HIGH);
    DELAY(T_WAIT);
    SET_SDA(LOW);
    DELAY(T_WAIT);
    SET_SCL(LOW);
    DELAY(T_WAIT);
}

// STOP CONDITION 
// HIGH:                  ______
//        SCL            |
// LOW :             ____|
// HIGH:                     ___
//        SDA               |
// LOW :             _______|    
void I2C_STOP(){
    SET_SCL(LOW);
    SET_SDA(LOW);
    DELAY(T_WAIT);
    SET_SCL(HIGH);
    DELAY(T_WAIT);
    SET_SDA(HIGH);
    DELAY(T_PEAK);
}

//        |<-T1->|<-T2->|
// HIGH:  _______ ______
// SCL           |      |
// LOW :   _ _ _ |      |______
static void SCL_MONO_PULSE(){
	DELAY(T_WAIT);      // wait for somethings (T1)
    SET_SCL(HIGH);      // pull to high
    DELAY(T_PEAK);      // wait (T2) to make a peak of MOMO PULSE.
	SET_SCL(LOW);
    DELAY(T_WAIT);    // pull to  low
}

uint RECEIVE_BIT(){
    uint BIT_DATA;
    DELAY(T_WAIT);
    SET_SDA(HIGH); // release SDA line
    DELAY(T_WAIT);
    SET_SCL(HIGH);
    DELAY(T_WAIT);
	BIT_DATA = SDA;
    SET_SCL(LOW);
    return BIT_DATA;
}

uint I2C_SEND_BYTE(unsigned char DATA){
    uint i = 0;
    for( i = 0; i < 8; i++){
        SET_SDA( DATA & 0x80 );
        SCL_MONO_PULSE();
        DATA <<= 1;
    }
    return RECEIVE_BIT();
}

static void SEND_ACK(){
    SET_SDA(LOW);  // pull SDA to low level to indicate ACK.
    SCL_MONO_PULSE();
    SET_SDA(HIGH); // idle state
    DELAY(T_WAIT);
}

static void SEND_NAK(){
    SET_SDA(HIGH);  // pull SDA to low level to indicate No ACK.
    SCL_MONO_PULSE();
    SET_SDA(HIGH); // idle state
    DELAY(T_WAIT);
}

uint I2C_RECEIVE_BYTE(uint ACK_NAK){
    uint i = 0, RCV_DATA = 0;
    for(i = 0; i < 8; i++){
        DELAY(T_WAIT);
        RCV_DATA <<= 1;
        RCV_DATA = RCV_DATA | RECEIVE_BIT();
    }
    if( ACK_NAK == NAK ) SEND_NAK();
    if( ACK_NAK == ACK) SEND_ACK();
}

void DS1307_INIT(){
    I2C_START();
    I2C_SEND_BYTE(SLAVE_ADDR_W);
    I2C_SEND_BYTE(CONTROL_REG_ADDR);
    I2C_SEND_BYTE(0x0); // Disable the SQW/OUT pin.
    I2C_STOP();
}

void DS1307_READ(uint *YEAR, uint *MONTH, uint *DAY, 
                uint *HOUR, uint *MINUTE, uint *SECOND){
    I2C_START();
    I2C_SEND_BYTE(SLAVE_ADDR_W); // Connect to DS1307
    I2C_SEND_BYTE(0x0);       // Request Sec RAM address at 00H
    I2C_STOP();

    DELAY(T_WAIT);

    I2C_START();
    I2C_SEND_BYTE(SLAVE_ADDR_R); // Connect to DS1307
    (*SECOND) = I2C_RECEIVE_BYTE(ACK);
    (*MINUTE) = I2C_RECEIVE_BYTE(ACK);
    (*HOUR) = I2C_RECEIVE_BYTE(ACK);
    I2C_RECEIVE_BYTE(ACK);
    (*DAY) = I2C_RECEIVE_BYTE(ACK);
    (*YEAR) = I2C_RECEIVE_BYTE(ACK);
    (*MONTH) = I2C_RECEIVE_BYTE(NAK);
    I2C_STOP();
}

#endif //_DS1307_H_