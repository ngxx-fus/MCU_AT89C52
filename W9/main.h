#include "Base_Lib.h"
#include "DS1302.h"
#include "IR_Reading.h"
#include "LED7Seg_OnKit.h"

enum enum_MODE{
    REMOTE = 0,
    MANUAL,
    DEV_0_CTL,  // auto ON/OFF dev
    DEV_1_CTL,  // timer ON/OFF dev
    DEV_1_SET_ON_TIMER,
    DEV_1_SET_OFF_TIMER,
    SETUP_SYS_TIME
};

sbit DEV0 = P2^5;
sbit DEV1 = P2^6;
sbit DEV2 = P2^7;

uint8 CURRENT_MODE = REMOTE;

/*
DEV:
    MSB        ... 3 2 1 0 LSB
                   x x x x
1: Enable
0: Disable
*/

void DEV_CTL(uint8 DEV){
    if(DEV&0x1) DEV0 = 0; else DEV0 = 1;
    if(DEV&0x2) DEV1 = 0; else DEV1 = 1;
    if(DEV&0x4) DEV2 = 0; else DEV2 = 1;
}


uint8 DEV = 0;
TIME sys_time = {0, 0, 0, 0, 0, 0, 0};
TIME time_on = {0, 0, 0, 0, 0, 0, 0};
TIME time_off = {0, 0, 0, 0, 0, 0, 0};

uint8 CODE2NUM(uint32 CODE){
    switch (CODE) {
        case __0: return 0;
        case __1: return 1;
        case __2: return 2;
        case __3: return 3;
        case __4: return 4;
        case __5: return 5;
        case __6: return 6;
        case __7: return 7;
        case __8: return 8;
        case __9: return 9;
    }
    return 0;
}

uint8 SET_TIMER(TIME* t){
    uint8 POS = 0;
    // POS = 0: exit
    // POS = 1: set on minute _x1
    // POS = 2: set on minute _x10
    // POS = 3: set on hour _x1
    // POS = 4: set on hour _x10
    uint32 CODE = 0;
    TIME tmp = {0, 0, 0, 0, 0, 0, 0};
    ds1302_read_time(&tmp, 0x7);
    while(0x1){
        CODE = read_extracted_frame();
        if(CODE == PLAY_PAUSE) break;
        if(CODE == PREV) POS = (POS+1 + 2)%2;
        if(CODE == NEXT) POS = (POS-1 + 2)%2;
        switch (POS) {
            case 0:
                tmp.MINUTE += CODE2NUM(CODE)%10; tmp.MINUTE%=60; break;
            case 1:
                tmp.HOUR   += CODE2NUM(CODE); tmp.HOUR%=24; break;
        }
        LED[0] = DIGIT_CODE[tmp.MINUTE%10] + ((POS==0)?(0x80):(0));
        LED[1] = DIGIT_CODE[tmp.MINUTE/10];
        LED[2] = DIGIT_CODE[tmp.HOUR%10]   + ((POS==1)?(0x80):(0));
        LED[3] = DIGIT_CODE[tmp.HOUR/10];
        Disp8leds7seg(50);
    }
    while(0x1){
        CODE = read_extracted_frame();
        LED[7] = 0x6E;
        LED[6] = 0x37;
        LED[5] = 0xD3;
        LED[4] = 0x0;
        LED[0] = DIGIT_CODE[tmp.MINUTE%10] + ((POS==0)?(0x80):(0));
        LED[1] = DIGIT_CODE[tmp.MINUTE/10];
        LED[2] = DIGIT_CODE[tmp.HOUR%10]   + ((POS==1)?(0x80):(0));
        LED[3] = DIGIT_CODE[tmp.HOUR/10];
        Disp8leds7seg(50);
        if(CODE == PLAY_PAUSE){
            *t = tmp;
            return 1;
        }
        if(CODE == MODE) 
            return 0;
    }
    return 0;
}

uint8 SET_ENABLE_DISABLE(uint8 *val, uint8 dev){
    uint8 tmp = 0;
    uint32 CODE = 0;
    while(0x1){
        CODE = read_extracted_frame();
        if(CODE == PLAY_PAUSE) break;
        if(CODE == PREV) tmp = (tmp+1 + 2)%2;
        if(CODE == NEXT) tmp = (tmp-1 + 2)%2;
        switch (tmp) {
            case 0:
                LED[7] = DIGIT_CODE[13]; 
                LED[6] = DIGIT_CODE[dev]; 
                LED[5] = 0; 
                LED[4] = 0;
                LED[3] = DIGIT_CODE[0]; 
                LED[2] = 0x37;
                LED[1] = 0x0; 
                LED[0] = 0x0;
                break;
            case 1:
                LED[7] = DIGIT_CODE[13]; 
                LED[6] = DIGIT_CODE[dev]; 
                LED[5] = 0; 
                LED[4] = 0;
                LED[3] = DIGIT_CODE[0]; 
                LED[2] = DIGIT_CODE[15]; 
                LED[1] = DIGIT_CODE[15]; 
                LED[0] = 0;
                break;
        }
        Disp8leds7seg(50);
    }
    while(0x1){
        CODE = read_extracted_frame();
        LED[7] = 0x6E;
        LED[6] = 0x37;
        LED[5] = 0xD3;
        LED[4] = 0x0;
        switch (tmp) {
            case 0:
                LED[3] = DIGIT_CODE[0]; 
                LED[2] = 0x37;
                LED[1] = 0x0; 
                LED[0] = 0x0;
                break;
            case 1:
                LED[3] = DIGIT_CODE[0]; 
                LED[2] = DIGIT_CODE[15]; 
                LED[1] = DIGIT_CODE[15]; 
                LED[0] = 0;
                break;
        }
        Disp8leds7seg(50);
        if(CODE == PLAY_PAUSE){
            *val = tmp;
            return 1;
        }
        if(CODE == MODE) 
            return 0;
    }
    return 0;
}

void change_mode(uint32 CODE){
    uint8 DEV = 0;

    if(CODE == PREV)
        CURRENT_MODE = (CURRENT_MODE-1)%7;
    else
    if(CODE == NEXT)
        CURRENT_MODE = (CURRENT_MODE+1)%7;
    else
    if(CODE == ON_OFF)
        CURRENT_MODE = REMOTE;
    else
    if(CODE == MODE)
        CURRENT_MODE = (CURRENT_MODE+1)%7;
    switch (CURRENT_MODE) {
        case REMOTE:
            LED[7] = 0x39; LED[5] = 0xF, LED[6] = DIGIT_CODE[1];
            CURRENT_MODE = REMOTE;
            Disp8leds7seg(1);
        return;

        case MANUAL:
            LED[7] = 0x39; LED[5] = 0xF, LED[6] = DIGIT_CODE[2];
            CURRENT_MODE = MANUAL;
            Disp8leds7seg(1);
        return;

        case DEV_0_CTL:
            LED[7] = 0x39; LED[5] = 0xF, LED[6] = DIGIT_CODE[3];
            CURRENT_MODE = DEV_0_CTL;
            Disp8leds7seg(1);
            if(CODE == PLAY_PAUSE) SET_ENABLE_DISABLE(&DEV, 0);
            DEV_CTL((DEV)?(1):(0));
            LED[7] = 0x39; LED[5] = 0xF, LED[6] = DIGIT_CODE[3];
        return;

        case DEV_1_CTL:
            LED[7] = 0x39; LED[5] = 0xF, LED[6] = DIGIT_CODE[4];
            CURRENT_MODE = DEV_1_CTL;
            Disp8leds7seg(1);
            if(CODE == PLAY_PAUSE) SET_ENABLE_DISABLE(&DEV, 1);
            DEV_CTL((DEV)?(2):(0));
            LED[7] = 0x39; LED[5] = 0xF, LED[6] = DIGIT_CODE[4];
        return;

        case DEV_1_SET_ON_TIMER:
            LED[7] = 0x39; LED[5] = 0xF, LED[6] = DIGIT_CODE[5];
            CURRENT_MODE = DEV_1_SET_ON_TIMER;
            Disp8leds7seg(1);
            LED[7] = DIGIT_CODE[0]; LED[6] = 0x37;
            LED[5] = 0x0;
            if(CODE == PLAY_PAUSE) SET_TIMER(&time_on);
            LED[7] = 0x39; LED[5] = 0xF, LED[6] = DIGIT_CODE[5];
        return;

        case DEV_1_SET_OFF_TIMER:
            LED[7] = 0x39; LED[5] = 0xF, LED[6] = DIGIT_CODE[6];
            CURRENT_MODE = DEV_1_SET_OFF_TIMER;
            Disp8leds7seg(1);
            LED[7] = DIGIT_CODE[0]; LED[6] = DIGIT_CODE[15]; 
            LED[5] = DIGIT_CODE[15];
            if(CODE == PLAY_PAUSE) SET_TIMER(&time_off);
            LED[7] = 0x39; LED[5] = 0xF, LED[6] = DIGIT_CODE[6];
        return;

        case SETUP_SYS_TIME:
            LED[7] = 0x39; LED[5] = 0xF, LED[6] = DIGIT_CODE[7];
            CURRENT_MODE = SETUP_SYS_TIME;
            Disp8leds7seg(1);
            LED[7] = DIGIT_CODE[5]; LED[6] = 0x72; 
            LED[5] = DIGIT_CODE[5];
            if(CODE == PLAY_PAUSE) 
                if( SET_TIMER(&sys_time) )
                    ds1302_write_time(&sys_time, 0x3F);
            LED[7] = 0x39; LED[5] = 0xF, LED[6] = DIGIT_CODE[7];
        return;
    }
}

void sys_time_disp(uint32 mili_sec){
    LED[3] = DIGIT_CODE[sys_time.HOUR/10];
    LED[2] = DIGIT_CODE[sys_time.HOUR%10];
    LED[1] = DIGIT_CODE[sys_time.MINUTE/10];
    LED[0] = DIGIT_CODE[sys_time.MINUTE%10];
    Disp8leds7seg(mili_sec);
}

void main_intial(){
    ds1302_initial();
    IR_Reading_Initial();
    LED_7SEG = 0x0;
    sys_time.HOUR = 4;
    sys_time.MINUTE = 6;
    sys_time.SECOND = 30;
    sys_time.DATE = 0;
    sys_time.DAY = 0;
    sys_time.MONTH = 0;
    sys_time.YEAR = 0;
    ds1302_write_time(&sys_time, 0x7F);
}