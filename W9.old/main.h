#include "Base_Lib.h"
#include "DS1302.h"
#include "IR_Reading.h"
#include "LED7Seg_OnKit.h"

enum enum_MODE{
    REMOTE = 0,
    SET_DEV_ENABLE,
    DEV_0_CTL,  // manual
    DEV_1_CTL,  // auto ON/OFF dev
    DEV_2_CTL,  // timer ON/OFF dev
    DEV_2_SET_ON_TIMER,
    DEV_2_SET_OFF_TIMER,
    SETUP_SYS_TIME
};

sbit DEV0 = P2^5;
sbit DEV1 = P2^6;
sbit DEV2 = P2^7;

uint8 CURRENT_MODE = REMOTE;

uint8 MANUAL_MODE = 0;
/*MANUAL_MODE:
  MSB             LSB
    DEV ... 2 1 0
            x x x   
    0: OFF, 1: ON
*/
uint8 DEV_ENABLE = 0;

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

uint8 YES_NO(){
    uint32 CODE = 0;
    LED[5] = 0; LED[4] = 0;
    LED[3] = 0; LED[2] = 0;
    LED[1] = 0; LED[0] = 0;
    while(0x1){
        CODE = read_extracted_frame();
        LED[7] = 0x6E; LED[6] = 0x37;
        Disp8leds7seg(1);
        switch (CODE) {
            //extend for more options :v
            case PLAY_PAUSE: return 1;
            case MODE: return 0;
            case ON_OFF: return 0;
        }
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
    TIME tmp;
	// tmp = *t;
    ds1302_read_time(&tmp, 0x7);
    while(0x1){
        CODE = read_extracted_frame();
        if(CODE == PLAY_PAUSE) break;
        if(CODE == PREV) POS = (POS+1 + 2)%2;
        if(CODE == NEXT) POS = (POS-1 + 2)%2;
        if(CODE == ON_OFF) return 0;
        if(CODE == MODE) return 0;
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
    if(YES_NO()){
        *t = tmp;
        return 1;
    }
    return 0;
}

uint8 SET_ON_OFF(uint8 *val, uint8 dev){
    uint8 tmp = 0;
    uint32 CODE = 0;
    while(0x1){
        CODE = read_extracted_frame();
        if(CODE == PLAY_PAUSE) break;
        if(CODE == PREV) tmp = (tmp+1 + 2)%2;
        if(CODE == NEXT) tmp = (tmp-1 + 2)%2;
        if(CODE == ON_OFF) return 0;
        if(CODE == MODE) return 0;
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
    if(YES_NO()){
        *val = tmp;
        return 1;
    }
    return 0;
}

void DEV_CTL(uint8 DEV, uint8 STATE){
    switch (DEV) {
        case 0: DEV0 = (STATE)?(HIGH):(LOW); break;
        case 1: DEV1 = (STATE)?(HIGH):(LOW); break;
        case 2: DEV2 = (STATE)?(HIGH):(LOW); break;
    }
}

void SHOW_MODE(uint8 M){
    LED[7] = 0x39; LED[5] = 0xF, LED[6] = DIGIT_CODE[M];
    Disp8leds7seg(1);
}

void change_mode(uint32 CODE){
    uint8 STATE = 0;

    switch (CODE) {
        case ON_OFF: CURRENT_MODE = REMOTE; break;
        case PREV: CURRENT_MODE = (CURRENT_MODE-1+8)%8; break;
        case NEXT: CURRENT_MODE = (CURRENT_MODE+1)%8; break;
        case MODE: CURRENT_MODE = (CURRENT_MODE+1)%8; break;
    }

    switch (CURRENT_MODE) {
        case REMOTE:
            SHOW_MODE(1);
            return;

        case SET_DEV_ENABLE:
            SHOW_MODE(2);
            return;

        case DEV_0_CTL:
            SHOW_MODE(3);
            if(CODE == PLAY_PAUSE){
                SET_ON_OFF(&STATE, 0x0);
                DEV_CTL(0x0, STATE);
            }
            SHOW_MODE(3);
            return;

        case DEV_1_CTL:
            SHOW_MODE(4);
            if(CODE == PLAY_PAUSE){
                SET_ON_OFF(&STATE, 0x1);
                DEV_CTL(0x1, STATE);
            }
            SHOW_MODE(4);
            return;

        case DEV_2_CTL:
            SHOW_MODE(5);
            if(CODE == PLAY_PAUSE){
                SET_ON_OFF(&STATE, 0x2);
                DEV_CTL(0x2, STATE);
            }
            SHOW_MODE(5);
            return;

        case DEV_2_SET_ON_TIMER:
            SHOW_MODE(6);
            if(CODE == PLAY_PAUSE) {
                LED[7] = DIGIT_CODE[0]; LED[6] = 0x37;
                LED[5] = 0x0;
                SET_TIMER(&time_on);
            }
            SHOW_MODE(6);
            return;

        case DEV_2_SET_OFF_TIMER:
            SHOW_MODE(7);
            if(CODE == PLAY_PAUSE){
                SET_TIMER(&time_off);
                LED[7] = DIGIT_CODE[0]; LED[6] = DIGIT_CODE[15]; 
                LED[5] = DIGIT_CODE[15];
            }
            SHOW_MODE(7);
            return;

        case SETUP_SYS_TIME:
            SHOW_MODE(8);
            if( CODE == PLAY_PAUSE && SET_TIMER(&sys_time) ){
                LED[7] = DIGIT_CODE[5]; LED[6] = 0x72; LED[5] = DIGIT_CODE[5];
                ds1302_write_time(&sys_time, 0x3F);
            }
            SHOW_MODE(8);
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
    sys_time.HOUR = 0;
    sys_time.MINUTE = 0;
    sys_time.SECOND = 0;
    sys_time.DATE = 0;
    sys_time.DAY = 0;
    sys_time.MONTH = 0;
    sys_time.YEAR = 0;
    ds1302_write_time(&sys_time, 0x7F);
}