#include "Base_Lib.h"
#include "DS1302.h"
#include "XPT2046.h"
#include "IR_Reading.h"
#include "LED7Seg_OnKit.h"

sbit dev0 = P2^5;
sbit dev1 = P2^6;
sbit dev2 = P2^7;

enum enum_modes{
    NORMAL_MODE = 0, 
    SETUP_MODE  = 1, 
    TIME_SETUP_MODE = 3, 
    DEV_CONTROL_MODE = 4,
    SYS_TIME_SETUP_MODE = 9,
    SYS_TIME_SETUP = 27,
    ON_TIME_SETUP_MODE = 10,
    ON_TIME_SETUP = 30,
    OFF_TIME_SETUP_MODE = 11,
    OFF_TIME_SETUP = 33,
    DEV0_SETUP_MODE = 12,
    DEV1_SETUP_MODE = 13, 
    DEV2_SETUP_MODE = 14,
    DEV0_ON_OFF =36,
    DEV1_ON_OFF =39,
    DEV2_ON_OFF =42
};

//Current screen :v
uint32 CURRENT_INDX = 0;
// uint8 MODE_TREE[250];
//Wait for yes_no?
uint8 WAIT_YES_NO = false;

/*
MSB  ... 2 1 0 LSB
         x x x
    H: Enable
    L: Disable
*/
uint8 dev0_user_ctl = 0;
uint8 dev1_user_ctl = 0;
uint8 dev2_user_ctl = 0;
uint8 dev0_syst_ctl = 0;
uint8 dev1_syst_ctl = 0;
uint8 dev2_syst_ctl = 0;
/*
MSB  ... 1 0 LSB
         | |
         | |
         | off 
         on timer
    H: Enable
    L: Disable
*/
uint8 timer_enable = 0;
// code received from IR REMOTE
uint32 IR_data = 0;
//System time
TIME system_time = {0, 0, 0, 0, 0, 0, 0};
//Turn-on device time
TIME time_on = {0, 0, 0, 0, 0, 0, 0};
//Turn-off device time
TIME time_off = {0, 0, 0, 0, 0, 0, 0};

//Remote code to number
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

void clear(){
    LED[0] = 0x0;
    LED[1] = 0x0;
    LED[2] = 0x0;
    LED[3] = 0x0;
    LED[4] = 0x0;
    LED[5] = 0x0;
    LED[6] = 0x0;
    LED[7] = 0x0;
}

uint8 YES_NO(){
    uint32 CODE = 0;
    while(0x1){
        CODE = read_extracted_frame();
        clear();
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
    ds1302_read_time(&tmp, 0x6);
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

uint8 SET_ON_OFF_NONE(uint8 *val, uint8 dev){
    uint8 tmp = 2;
    uint32 CODE = 0;
    while(0x1){
        CODE = read_extracted_frame();
        if(CODE == PLAY_PAUSE) break;
        if(CODE == PREV) tmp = (tmp+1 + 3)%3;
        if(CODE == NEXT) tmp = (tmp-1 + 3)%3;
        if(CODE == ON_OFF) return 0;
        if(CODE == MODE) return 0;
        switch (tmp) {
            case 0:
                LED[7] = DIGIT_CODE[13]; 
                LED[6] = DIGIT_CODE[dev]; 
                LED[5] = 0; 
                LED[4] = 0;
                LED[3] = DIGIT_CODE[0]; 
                LED[2] = DIGIT_CODE[15]; 
                LED[1] = DIGIT_CODE[15]; 
                LED[0] = 0;
                break;
            case 1:
                LED[7] = DIGIT_CODE[13]; 
                LED[6] = DIGIT_CODE[dev]; 
                LED[5] = 0; 
                LED[4] = 0;
                LED[3] = DIGIT_CODE[0]; 
                LED[2] = 0x37;
                LED[1] = 0x0; 
                LED[0] = 0x0;
                break;
            case 2:
                LED[7] = DIGIT_CODE[13]; 
                LED[6] = DIGIT_CODE[dev]; 
                LED[5] = 0; 
                LED[4] = 0;
                LED[3] = 0x37; 
                LED[2] = DIGIT_CODE[0]; 
                LED[1] = 0x37; 
                LED[0] = DIGIT_CODE[14];
                break;
        }
        Disp8leds7seg(50);
    }
    if(YES_NO()){
        *val = (tmp == 0 || tmp == 1)?(tmp):(Z);
        return 1;
    }
    return 0;
}

void read_system_time(){
    ds1302_read_time(&system_time, 0x7);
}

void update_dev_state(){
    if(dev0_user_ctl == Z)
        dev0 = (dev0_syst_ctl)?0:1;
    else
        dev0 = (dev0_user_ctl)?0:1;
    if(dev1_user_ctl == Z)
        dev1 = (dev1_syst_ctl)?0:1;
    else
        dev1 = (dev1_user_ctl)?0:1;    
    if(dev2_user_ctl == Z)
        dev2 = (dev2_syst_ctl)?0:1;
    else
        dev2 = (dev2_user_ctl)?0:1;    
}
/*
Time comparision
Choose what will be compared by using bit in MASK
MASK: 
             7    6    5     4    3     2     1   0
    MSB  ... x    x    x     x    x     x     x   x    LSB 
description       day  year  mon  date  hour  min sec
*/
uint8 time_equal_cmp(TIME a, TIME b, uint8 mask){
    if( ((mask&0x1)!=0) && (a.SECOND!=b.SECOND) ) 
        return false;
    if( ((mask&0x2)!=0) && (a.MINUTE!=b.MINUTE) ) 
        return false;
    if( ((mask&0x4)!=0) && (a.HOUR!=b.HOUR) ) 
        return false;
    return true;
}

uint32 have_daylight(){
    Read_AD_Data(0xA4);
    if( (Read_AD_Data(0xA4)%1000) > 30)
        return true;
    return false;
}

uint32 get_up_index(uint32 indx){
    if(indx == 0) return 1;
    return (indx/3);
}

uint32 get_down_index(uint32 indx){
    if(indx*3 > 42) return indx;
    return (indx*3);
}

uint32 get_left_index(uint32 indx){
    switch (indx) {
        case 3: return 4;
        case 4: return 3;
        case 10: return 9;
        case 11: return 10;
        case 9: return 11;
        case 12: return 14;
        case 13: return 12;
        case 14: return 13;
    }
    return indx;
}

uint32 get_right_index(uint32 indx){
    switch (indx) {
        case 3: return 4;
        case 4: return 3;
        case 9: return 10;
        case 10: return 11;
        case 11: return 9;
        case 12: return 13;
        case 13: return 14;
        case 14: return 12;
    }
    return indx;
}

void code_proc(uint32 CODE){
    uint32 tmp;
    switch (CODE) {
        case ON_OFF:
            dev0_syst_ctl = (dev0_syst_ctl)?(0):(1);
            return;
        case MODE:
            CURRENT_INDX = get_up_index(CURRENT_INDX);
            break;
        case PLAY_PAUSE:
            CURRENT_INDX = get_down_index(CURRENT_INDX);
            break;
        case PREV:
            CURRENT_INDX = get_left_index(CURRENT_INDX);
            break;
        case NEXT:
            CURRENT_INDX = get_right_index(CURRENT_INDX);
            break;
    }
    switch (CURRENT_INDX) {
        case NORMAL_MODE:
            LED[0] = DIGIT_CODE[(system_time.SECOND)%10];
            LED[1] = DIGIT_CODE[(system_time.SECOND/10)%10];
            LED[2] = 0x40;
            LED[3] = DIGIT_CODE[(system_time.MINUTE)%10];
            LED[4] = DIGIT_CODE[(system_time.MINUTE/10)%10];
            LED[5] = 0x40;
            LED[6] = DIGIT_CODE[(system_time.HOUR)%10];
            LED[7] = DIGIT_CODE[(system_time.HOUR/10)%10];
            return;
        case SETUP_MODE:
            LED[7] = DIGIT_CODE[5];
            LED[6] = DIGIT_CODE[14];
            LED[5] = 0x7;
            LED[4] = 0x3E;
            LED[3] = 0x73;
            LED[2] = 0x0;
            LED[1] = 0x0;
            LED[0] = 0;
            return;
        case TIME_SETUP_MODE:
            LED[7] = 0x31;
            LED[6] = 0x40;
            LED[5] = 0x39;
            LED[4] = 0x31;
            LED[3] = 0x38;
            LED[2] = 0x0;
            LED[1] = 0x0;
            LED[0] = 0x0;
            return;

        case SYS_TIME_SETUP_MODE:
            LED[7] = DIGIT_CODE[5];
            LED[6] = 0x6E;
            LED[5] = DIGIT_CODE[5];
            LED[4] = 0x0;
            LED[3] = 0x0;
            LED[2] = 0x0;
            LED[1] = 0x0;
            LED[0] = 0x0;
            return;

        case SYS_TIME_SETUP:
            if( SET_TIMER(&system_time))
                ds1302_write_time(&system_time, 0x7F);
            CURRENT_INDX = get_up_index(CURRENT_INDX);
            return;

        case ON_TIME_SETUP_MODE:
            LED[7] = DIGIT_CODE[0]; 
            LED[6] = 0x37;
            LED[5] = 0; 
            LED[4] = 0;
            LED[3] = 0x0;
            LED[2] = 0x0;
            LED[1] = 0x0;
            LED[0] = 0x0;
            return;

        case ON_TIME_SETUP:
            SET_TIMER(&time_on);
            CURRENT_INDX = get_up_index(CURRENT_INDX);
            return;

        case OFF_TIME_SETUP_MODE:
            LED[7] = DIGIT_CODE[0]; 
            LED[6] = DIGIT_CODE[15];
            LED[5] = DIGIT_CODE[15]; 
            LED[4] = 0;
            LED[3] = 0x0;
            LED[2] = 0x0;
            LED[1] = 0x0;
            LED[0] = 0x0;
            return;

        case OFF_TIME_SETUP:
            SET_TIMER(&time_off);
            CURRENT_INDX = get_up_index(CURRENT_INDX);
            return;

        case DEV_CONTROL_MODE:
            LED[7] = DIGIT_CODE[13];
            LED[6] = DIGIT_CODE[14];
            LED[5] = 0x3E;
            LED[4] = 0x39;
            LED[3] = 0x31;
            LED[2] = 0x38;
            LED[1] = 0x0;
            LED[0] = 0x0;
            return;
        
        case DEV0_SETUP_MODE:
            LED[7] = DIGIT_CODE[5];
            LED[6] = DIGIT_CODE[14];
            LED[5] = 0x7;
            LED[4] = 0x3E;
            LED[3] = 0x73;
            LED[2] = 0x0;
            LED[1] = DIGIT_CODE[13];
            LED[0] = DIGIT_CODE[0];
            return;

        case DEV1_SETUP_MODE:
            LED[7] = DIGIT_CODE[5];
            LED[6] = DIGIT_CODE[14];
            LED[5] = 0x7;
            LED[4] = 0x3E;
            LED[3] = 0x73;
            LED[2] = 0x0;
            LED[1] = DIGIT_CODE[13];
            LED[0] = DIGIT_CODE[1];
            return;

        case DEV2_SETUP_MODE:
            LED[7] = DIGIT_CODE[5];
            LED[6] = DIGIT_CODE[14];
            LED[5] = 0x7;
            LED[4] = 0x3E;
            LED[3] = 0x73;
            LED[2] = 0x0;
            LED[1] = DIGIT_CODE[13];
            LED[0] = DIGIT_CODE[2];
            return;

        case DEV0_ON_OFF:
            SET_ON_OFF_NONE(&dev0_user_ctl, 0);
            CURRENT_INDX = get_up_index(CURRENT_INDX);
            update_dev_state();
            return;

        case DEV1_ON_OFF:
            SET_ON_OFF_NONE(&dev1_user_ctl, 1);
            CURRENT_INDX = get_up_index(CURRENT_INDX);
            update_dev_state();
            return;

        case DEV2_ON_OFF:
            SET_ON_OFF_NONE(&dev2_user_ctl, 2);
            CURRENT_INDX = get_up_index(CURRENT_INDX);
            update_dev_state();
            return;

    }
}

void main_intial(){
    IR_Reading_Initial();
    ds1302_initial();
    dev0_user_ctl = Z;
    dev1_user_ctl = Z;
    dev2_user_ctl = Z;
    CURRENT_INDX = 0;
    ds1302_write_time(&system_time, 0x7F);

}