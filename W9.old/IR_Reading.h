#ifndef _IF_READING_
#define _IF_READING_

#include "REGX52.h"
#include "Base_Lib.h"
#include "DS1302.h"
#include "LED7Seg_OnKit.h"
#include "Matrix_Button.h"

/*
    Refs:
        https://embeddedflakes.com/interrupt-handling-in-8051/
        https://exploreembedded.com/wiki/NEC_IR_Remote_Control_Interface_with_8051
        https://embeddedflakes.com/8051-timers-vs-counters/
        https://exploreembedded.com/wiki/6.8051_Interrupts

*/


#define ON_OFF 0xA25D
#define MODE  0x629D
#define MUTE  0xE21D
#define PREV  0x02FD  // PREV
#define NEXT  0xC23D  // NEXT
#define PLAY_PAUSE  0x22DD  // PLAY/PAUSE
#define VOL_DOWN  0xA857  // VOL-
#define VOL_UP  0x906F  // VOL+
#define EQ  0xE01F  // EQ   
#define __0  0xFF6897  // 0   
#define __1  0xFF30CF  // 1  
#define __2  0xFF18E7  // 2   
#define __3  0xFF7A85  // 3   
#define __4  0xFF10EF  // 4   
#define __5  0xFF38C7  // 5  
#define __6  0xFF5AA5  // 6   
#define __7  0xFF42BD  // 7   
#define __8  0xFF4AB5  // 8   
#define __9  0xFF52AD  // 9 



// Reset timer at 0xFC67
#define PUSH_BIT_1() buffer |=(uint32)1<<(31-negedge_count);
#define PUSH_BIT_0() /*do nothing*/;
#define RESET_BUFFER() buffer=0;
#define EXTRACT_FRAME() data_frame=buffer; buffer = 0; negedge_count = 0;

// Based on the diagram of "8051 Pro" Kit
// sbit IR_RCV_PIN = P3^2;
// sbit IndicatorLED = P2^7;
// sbit DataRcv = P2^6;
sbit FrameExtracted = P2^0;
// sbit MR = P2^4;
// Final data_frame
uint32 data_frame = 0;
// Temporary storing unfinished  data-frame while receiving.
uint32 buffer = 0;
// Mili-second count
uint8 ms_count = 0;
// bit-count
int8 negedge_count = 0;

//check if we have a new data_frame or not?
uint8 new_dataframe(){
    return (data_frame!=0)?1:0;
}

//clear frame after read!
uint32 read_extracted_frame(){
    uint32 frame = data_frame;
    data_frame = 0;
    return frame;
}

void IR_Reading_Initial(){
    // IndicatorLED = 1;
    // DataRcv = 1;
    buffer = 0;
    data_frame = 0;
    negedge_count = 0;
    GLOBAL_INT(ENABLE);
    eINT0_CTL(ENABLE);
    TIMER0_CTL(ENABLE);
    TIMER0_CTL(MODE_16BIT);
    TIMER0_CTL(START);
    TIMER0_CTL(RESET);
}

void Timer0_OverFlow_Interrupt() interrupt 1 {
	// IndicatorLED = ~IndicatorLED;
    TIMER0_CTL(RESET);
    //A data-frame isn't longer than 67.5mili-sec.
    if(ms_count<67) ms_count = ms_count + 1;
}

void External0_Interrupt() interrupt 0 {
    uint32 current_mscount = 0;

    current_mscount = ms_count;
    TIMER0_CTL(RESET);
    ms_count=0;
    negedge_count +=1;
    // DataRcv = ~DataRcv;
    // this neg-edge by SOF (start of frame)?
    if(current_mscount >= 67){
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
            delay_ms(1);
            FrameExtracted=1;
        }
    }
}

#endif