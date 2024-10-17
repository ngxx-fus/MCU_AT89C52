/*
    Note:
        Base_Lib.h is a lib that include all define, typedef,
        base function, ... It can be reused in many following project.
    Autor:
        Nguyen Thanh Phu
    Version:
        0.2.x
*/
/*
    Notification:
        1.  This version of this file is modified to be compiled
            by SDCC in (Ubuntu). It unable to be compiled in Keil C51.
        2.  To use this file, you must change something e.g:
            |     SDCC                       |       Keil C51           |
                #include <at89x52.h>           --->    #include <at89x52.h>
                __sbit __at (0xA0 + 7) LED  --->    __sbit __at() LED = P2^7;
                ...
        3.  Port addreses
            PORT                Address
            P0                  0x80            
            P1                  0x90
            P2                  0xA0
            P3                  0xB0
*/
#include <at89x52.h>


#ifndef _BASE_LIB_H_
#define _BASE_LIB_H_

#ifndef elif
#define elif else if
#endif
#ifndef DECREASE_ONE
#define DECREASE_ONE(VAR) VAR = (VAR>0?(VAR-1):VAR)
#endif
#ifndef REP
#define REP(i, a, b) for(i = (a); i <= (b); ++i)
#endif
#ifndef REV
#define REV(i, a, b) for(i = (a); i >= (b); --i)
#endif

#define p0_addr 0x80
#define p1_addr 0x90
#define p2_addr 0xA0
#define p3_addr 0xB0

typedef unsigned char uint8;
typedef unsigned int uint32;
typedef char int8;
typedef int int32;

enum enum_STATE{ LOW  = 0, HIGH = 1 };
enum enum_ENABLE{ DISABLE=0, ENABLE, START, 
    STOP, MODE_16BIT, RESET 
};

static void delay_us(uint32 us){
    uint32 i = 0; 
    for(i = 0; i < us; i = i + 1){
        // do nothin'
    }
}

void delay_ms(uint32 ms){
    uint32 i = 0; 
    for(i = 0; i < ms*12; i = i + 1){
        // do nothin'
    }
}

void eINT0_CTL(uint8 CONFIG){
    if( CONFIG == ENABLE){
        EX0 = 1;
        IT0 = 1;
    }
    if( CONFIG == DISABLE){
        EX0 = 0;
        IT0 = 0;
    }
}

void eINT1_CTL(uint8 CONFIG){
    if( CONFIG == ENABLE){
        // Configure INT1 falling edge interrupt
        IT1 = 1;   
        // Enable the INT1 External Interrupt    
        EX1 = 1;
    }
    if( CONFIG == DISABLE){
        // Configure INT1 falling edge interrupt
        IT1 = 0;   
        // Enable the INT1 External Interrupt    
        EX1 = 0;
    }
}

#define RESET_TH 0xFC 
#define RESET_TL 0x67
void TIMER0_CTL(uint8 CONFIG){
    switch (CONFIG) {
        case ENABLE:
            ET0 = 1;            return;
        case DISABLE:
            ET0 = 0;            return;
        case RESET:
            TL0 = RESET_TL;
            TH0 = RESET_TH;     return;
        case START:
            TR0 = 1;            return;
        case STOP:
            TR0 = 0;            return;
        case MODE_16BIT:
            TMOD = TMOD|0x01;   return;
    }
}

// #define GLOBAL_INT(CONFIG) 
void GLOBAL_INT(uint8 CONFIG){
    EA=(CONFIG==ENABLE)?(1):(0);
}


#endif