#ifndef _IF_READING_
#define _IF_READING_

#include "Base_Lib.h"
#include "REGX52.h"

/*
    Refs:
        https://embeddedflakes.com/interrupt-handling-in-8051/
        https://exploreembedded.com/wiki/NEC_IR_Remote_Control_Interface_with_8051
        https://embeddedflakes.com/8051-timers-vs-counters/
        https://exploreembedded.com/wiki/6.8051_Interrupts

*/

/*
    Delay computation:
        System specifications:
            Clock Freq  = 11.0592 Mhz 
                        = 11059200 Hz 
                        = 11059200 clock_period/second
            ---> Clock period =  1/11059200
            Machine Cycle = 12clock_period
        Computation:
            16bit -> Max value of timer: (2<<16)-1 = 65535
            Delay=1ms <-> 0.001second * 11059200(clock_period/second)
                    <-> 11059.2 clock_period.
            Bcz the machine_cycle = 12 clock_period
            So
            Delay=1ms <-> 11059.2clock_period / 12clock_period
                    <-> 921.6 machine_cycle (e.g ADD)
                    <-> count from 64615 -> 65535
                    <-> count from 0xFC67 -> 0xFFFF
            Keep in mind that 16bit counter mode has been devide into
            2 registers 4bit call 8bit HIGH (TH0) and 8bit LOW (TL0).
*/

/*
        To count the number of mili-second, we use Overflow Timer Interrupt.
    It means when you count to 0xFFFF (16bit counter mode), and continue count up,
    TF0 is set to HIGH, and Overflow Timer 0 Interrupt function is called. We 
    at this time increase one into mili-second counter variable.
*/

/*
    When a key is pressed on the remote controller, the message transmitted 
    consists of the following, in order:
        A 9ms leading pulse burst (16 times the pulse burst length used for 
        a logical data bit)
        A 4.5ms space
        The 8-bit address for the receiving device
        The 8-bit logical inverse of the address
        The 8-bit command
        The 8-bit logical inverse of the command
        A final 562.5µs pulse burst to signify the end of message transmission.

*/

/*
NEC IR Remote Codes (Size: 3bytes data)
    0xFFA25D: CH-       
    0xFF629D: CH        
    0xFFE21D: CH+       
    0xFF22DD: PREV      
    0xFF02FD: NEXT      
    0xFFC23D: PLAY/PAUSE
    0xFFE01F: VOL-      
    0xFFA857: VOL+      
    0xFF906F: EQ        
    0xFF6897: 0         
    0xFF9867: 100+      
    0xFFB04F: 200+      
    0xFF30CF: 1         
    0xFF18E7: 2         
    0xFF7A85: 3         
    0xFF10EF: 4         
    0xFF38C7: 5         
    0xFF5AA5: 6         
    0xFF42BD: 7         
    0xFF4AB5: 8         
    0xFF52AD: 9 
**************************/

// Reset timer at 0xFC67
#define RESET_TIMER_0() TH0=0xFC; TL0=0x67;
#define START_TIMER_0() TR0 = 1; 
#define STOP_TIMER() TR0 = 0; 
#define PUSH_BIT_1() buffer |=(uint32)1<<(31-negedge_count);
#define PUSH_BIT_0() /*do nothing*/;
#define RESET_BUFFER() buffer=0;
#define EXTRACT_FRAME() data_frame=buffer; buffer = 0; negedge_count = 0;

// Based on the diagram of "8051 Pro" Kit
sbit IR_RCV_PIN = P3^2;
sbit IndicatorLED = P2^7;
sbit DataRcv = P2^6;
sbit FrameExtracted = P2^5;
sbit L0 = P2^0;
sbit L1 = P2^1;
sbit L2 = P2^2;
// Final data_frame
uint32 data_frame = 0;
// Temporary storing unfinished  data-frame while receiving.
uint32 buffer = 0;
// Mili-second count
uint8 ms_count = 0;
// bit-count
int8 negedge_count = 0;


void IR_Reading_Initial(){
    // Enable the Global Interrupt bit
    EA  = 1;
    // Configure INT0 falling edge interrupt
    IT0 = 1;   
    // Enable the INT0 External Interrupt    
    EX0 = 1;
    // Enable Timer 1
    ET0 = 1;
    // Set mode Timer 1: 16 bits
    TMOD = TMOD|0x01;
    // Start timer1
    IndicatorLED = 1;
    DataRcv = 1;
    buffer = 0;
    data_frame = 0;
    negedge_count = 0;
    START_TIMER_0();

}

void Initial(){
    // Run initial 
    IR_Reading_Initial();
    // SET all LED-7seg OFF by set a->g = L.
    P0 = 0;
    // SET all LED OFF by set Port 2 = H.
    P2 = 0xFF;
}

void LED_Show(uint32 CODE){
		
    switch (CODE) {
        case 0xFF30CF:
            L0 = ~L0;
            break;
        case 0xFF18E7:
            L1 = ~L1;
            break;
        case 0xFF7A85:
            L2 = ~L2;
            break;
        default:
                P2 = 0xFF;
    }
}

void Timer0_OverFlow_Interrupt() interrupt 1 {
	IndicatorLED = ~IndicatorLED;
    RESET_TIMER_0();
    //A data-frame isn't longer than 67.5mili-sec.
    if(ms_count<50) ms_count = ms_count + 1;
}


void External0_Interrupt() interrupt 0 {
    uint32 current_mscount = 0; 
    current_mscount = ms_count;
    RESET_TIMER_0();
    ms_count=0;
    negedge_count +=1;
    DataRcv = ~DataRcv;
    // this neg-edge by SOF (start of frame)?
    if(current_mscount >= 50){
        negedge_count = -2;
        RESET_BUFFER();
    }else{
        if( negedge_count < 0)
            /*Do nothing, skip this neg-edge*/;
        if(0 <= negedge_count && negedge_count <= 31){
            if( current_mscount >= 2){
                PUSH_BIT_1();
			}else{
                PUSH_BIT_0();
			}
        }else if(negedge_count >= 32){
            EXTRACT_FRAME();
            FrameExtracted=0;
						LED_Show(data_frame);
            FrameExtracted=1;
        }
    }
    
}


#endif