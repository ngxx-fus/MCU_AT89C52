#include "Time.h"
#include "String_Ultils.h"
#include "UART_BLE.h"
#include "DS1302.h"
#include "Utilities.h"
#include "XPT2046.h"
#include "UART_BLE.h"
#include "LCD_1602.h"
#include "LCD_1602.h"
#include "IR_Reading.h"

#define _1st_bit_mask 0x01
#define _2nd_bit_mask 0x02
#define _3rd_bit_mask 0x04
#define _4th_bit_mask 0x08
#define _5th_bit_mask 0x10
#define _6th_bit_mask 0x20
#define _7th_bit_mask 0x40
#define _8th_bit_mask 0x80

#define DEV1_MASK 0x003
#define DEV2_MASK 0x00C
#define DEV3_MASK 0x030
#define DEV4_MASK 0x0C0
#define DEV5_MASK 0x300

#define MODE_UP() DISP_MODE/=5
#define MODE_DOWN() if(DISP_MODE<170) DISP_MODE*=5

#define MODE_NORMAL 0
#define MODE_SETUP 1
#define MODE_SETUP_TIME 5
#define MODE_SETUP_TIME_SYSTEM_DISP  25
#define MODE_SETUP_TIME_SYSTEM_ACTION  125
#define MODE_SETUP_TIME_TIMER_1_DISP 26
#define MODE_SETUP_TIME_TIMER_1_ACTION 130
#define MODE_SETUP_TIME_TIMER_2_DISP 27
#define MODE_SETUP_TIME_TIMER_2_ACTION 135
#define MODE_SETUP_DEVICE 6
#define MODE_SETUP_DEVICE_1_DISP 30
#define MODE_SETUP_DEVICE_1_ACTION 150
#define MODE_SETUP_DEVICE_2_DISP 31
#define MODE_SETUP_DEVICE_2_ACTION 155
#define MODE_SETUP_DEVICE_3_DISP 32
#define MODE_SETUP_DEVICE_3_ACTION 160
#define MODE_SETUP_DEVICE_4_DISP 33
#define MODE_SETUP_DEVICE_4_ACTION 165
#define MODE_SETUP_DEVICE_5_DISP 34
#define MODE_SETUP_DEVICE_5_ACTION 170

sbit DEV1 = P2^0;
sbit DEV2 = P2^1;
sbit DEV3 = P2^2;
sbit DEV4 = P2^3;
sbit DEV5 = P2^4;

uint8 HOLD = 0;
uint8 DISP_MODE = 0;
uint8 SYST_TRIGGER = 0;
uint8 SYST_DEV_CTL = 0;
uint8 USER_DEV_CTL = 0; 
uint8 SYS_CTL_INV = 0;
uint16 CTL_DEV_SEL = 0; 

char time_disp_1[]="TIME:   XX:XX:XX";
char time_disp_2[]="DATE:   XX/XX/XX";

TIME    sys_t = {7  , 12, 11, 24, 21, 05, 45}, 
        timer_1 = {7  , 12, 11, 24, 21, 05, 55}, 
        timer_2 = {7  , 12, 11, 24, 21, 06, 5};

void Time_Data_Display(char label_1[], char label_2[], TIME t, uint8 SEL){
    time_disp_1[0] = label_1[0];
    time_disp_1[1] = label_1[1];
    time_disp_1[2] = label_1[2];
    time_disp_1[3] = label_1[3];
    time_disp_1[4] = label_1[4];
    time_disp_1[5] = label_1[5];
    time_disp_1[6] = label_1[6];
    time_disp_1[7] = label_1[7];
    time_disp_2[0] = label_2[0];
    time_disp_2[1] = label_2[1];
    time_disp_2[2] = label_2[2];
    time_disp_2[3] = label_2[3];
    time_disp_2[4] = label_2[4];
    time_disp_2[5] = label_2[5];
    time_disp_2[6] = label_2[6];
    time_disp_2[7] = label_2[7];
    if(SEL & _1st_bit_mask){
        time_disp_1[8] = digit2char(x10_digit(t.HOUR));
        time_disp_1[9] = digit2char(x1_digit(t.HOUR));
        time_disp_1[11] = digit2char(x10_digit(t.MINUTE));
        time_disp_1[12] = digit2char(x1_digit(t.MINUTE));
        time_disp_1[14] = digit2char(x10_digit(t.SECOND));
        time_disp_1[15] = digit2char(x1_digit(t.SECOND));
        LCD_Simple_Set_Text_1(time_disp_1, 16, 0, 0);
    }
    if(SEL & _2nd_bit_mask){
        time_disp_2[8] = digit2char(x10_digit(t.DATE));
        time_disp_2[9] = digit2char(x1_digit(t.DATE));
        time_disp_2[11] = digit2char(x10_digit(t.MONTH));
        time_disp_2[12] = digit2char(x1_digit(t.MONTH));
        time_disp_2[14] = digit2char(x10_digit(t.YEAR));
        time_disp_2[15] = digit2char(x1_digit(t.YEAR));
        LCD_Simple_Set_Text_1(time_disp_2, 16, 1, 0);
    }
}

uint8 YES_NO(){
    uint8 ans = 0;
    LCD_Simple_Set_Text_2("CONFIRM?[YES/NO]", 0, 0, 0);
    while(0x1){
        // UART_Bytes_Transmit("\nConfirm?[YES/NO]\n", 0);
        // _string_to_lower_case(ble_rcv_data, ble_rcv_size);
        // if(ble_has_contained("yes", 3)) return 1;
        // if(ble_has_contained("no", 2)) return 0;
        if(ans)
            LCD_Simple_Set_Text_1("> YES", 0, 1, 0);
        else
            LCD_Simple_Set_Text_1("> NO ", 0, 1, 0);
        // delay_ms(1000);
        switch (read_extracted_frame()) {
            case PREV: ans=(ans+1)%2; break;
            case NEXT: ans=(ans+1)%2; break;
            case PLAY_PAUSE: return ans;
            case MODE:  return 0;
            case ON_OFF:  return 0;
        }
    }
    return 0;
}

uint8 Setup_Device(){
    /*
    Map of return value:
    MSB           4  3  2  1  0  LSB
        [x][x][x][x][x][x][x][x]
                  |  |  |  ^~~~~
                  |  |  |  Control mode (USER/LIGHT/TIMER_1/TIMER_2)
                  |  |  ^~
                  |  |  Invert trigger
                  |  ^~
                  |  Pre-set dev-state (ON/OFF)
                  ^~
                  Skip pre-set dev-state
    */
    uint8 pos = 0, res = 0;
    uint32 rm_code;
    LCD_Simple_Set_Text_2("Setup device:", 0, 0, 0);
    while(0x1){
        rm_code = read_extracted_frame();
        if(rm_code == MODE) return 0x8F;;
        if(rm_code == PLAY_PAUSE) break;
        if(rm_code == NEXT) pos=(pos+1)%4;
        if(rm_code == PREV) pos=(pos+3)%4;
        //if(ble_has_contained("next", 4))pos=(pos+1)%4;
        //if(ble_has_contained("prev", 4))pos=(pos+3)%4;
        //if(ble_has_contained("yes", 3))break;
        //if(ble_has_contained("no", 3))return 0x8F;
        ble_rcv_size = 0;
        switch (pos) {
            case 0:
                LCD_Simple_Set_Text_1("> MODE: USER   ", 0, 1, 0);
                break;
            case 1:
                LCD_Simple_Set_Text_1("> MODE: LIGHT  ", 0, 1, 0);
                break;
            case 2:
                LCD_Simple_Set_Text_1("> MODE: TIMER_1", 0, 1, 0);
                break;
            case 3:
                LCD_Simple_Set_Text_1("> MODE: TIMER_2", 0, 1, 0);
                break;
        }
    }
    res = pos;
    pos=1;
    if(res)
        while(0x1){
            rm_code = read_extracted_frame();
            if(rm_code == MODE) return 0x8F;;
            if(rm_code == PLAY_PAUSE) break;
            if(rm_code == NEXT) pos=(pos+1)%2;
            if(rm_code == PREV) pos=(pos+1)%2;
            //if(ble_has_contained("next", 4))pos=(pos+1)%2;
            //if(ble_has_contained("prev", 4))pos=(pos+1)%2;
            //if(ble_has_contained("yes", 3))break;
            //if(ble_has_contained("no", 3))return 0x8F;
            ble_rcv_size = 0;
            switch (pos) {
                case 0:
                    LCD_Simple_Set_Text_1("> TRIG: NONE INV", 0, 1, 0);
                    break;
                case 1:
                    LCD_Simple_Set_Text_1("> TRIG: INVERTED", 0, 1, 0);
                    break;
            }
        }
    res |= (pos<<2);
    pos=2;
    while(0x1){
        rm_code = read_extracted_frame();
        if(rm_code == MODE) return 0x8F;;
        if(rm_code == PLAY_PAUSE) break;
        if(rm_code == NEXT) pos=(pos+1)%3;
        if(rm_code == PREV) pos=(pos+2)%3;
        //if(ble_has_contained("next", 4))pos=(pos+1)%3;
        //if(ble_has_contained("prev", 4))pos=(pos+2)%3;
        //if(ble_has_contained("yes", 3))break;
        //if(ble_has_contained("no", 3))return 0x8F;
        ble_rcv_size = 0;
        switch (pos) {
            case 0:
                LCD_Simple_Set_Text_1("> STATE: ON     ", 0, 1, 0);
                break;
            case 1:
                LCD_Simple_Set_Text_1("> STATE: OFF    ", 0, 1, 0);
                break;
            case 2:
                LCD_Simple_Set_Text_1("> STATE: SKIP   ", 0, 1, 0);
                break;
        }
    }
    res |= (pos<<3);
    return res;
}

uint8 Setup_Time(TIME* t){
    TIME temp;
    uint8 pos = 0;
    uint8 found_pos = 0;
    uint32 REMOTE_CODE = 0;
    DS1302_Read_Time(&temp, 0x3F);
    while(0x1){
        // Direct
        // _string_to_lower_case(ble_rcv_data, ble_rcv_size);
        //if(ble_has_contained("next", 4)) pos = (pos+1)%6;
        //if(ble_has_contained("prev", 4)) pos = (pos-1+6)%6;
        //if(ble_has_contained("yes", 3)) break;
        //if(ble_has_contained("no", 2)) return 0;
        //if(ble_has_contained("exit", 4)) return 0;
        REMOTE_CODE = read_extracted_frame();
        if(REMOTE_CODE == PLAY_PAUSE) break;
        elif(REMOTE_CODE == MODE) return 0;
        elif(REMOTE_CODE == NEXT) pos = (pos+1)%6;
        elif(REMOTE_CODE == PREV)  pos = (pos-1+6)%6;
        found_pos = _string_find_pattern("incr", 4, ble_rcv_data, ble_rcv_size, 0);
        if(found_pos + 1 < ble_rcv_size){
            found_pos = ble_rcv_data[found_pos+4] - '0';
        }else{
            found_pos = 0;
        }
        ble_rcv_size = 0;//clear ble rcv data

        switch (pos) {
            case 0: 
                temp.SECOND = (temp.SECOND+CODE2NUM(REMOTE_CODE)+found_pos)%60; 
                break;
            case 1: 
                temp.MINUTE = (temp.MINUTE+CODE2NUM(REMOTE_CODE)+found_pos)%60;
                break;
            case 2: 
                temp.HOUR = (temp.HOUR+CODE2NUM(REMOTE_CODE)+found_pos)%24; 
                break;
            case 3: 
                temp.DATE = (temp.DATE+CODE2NUM(REMOTE_CODE)+found_pos)%31; 
                break;
            case 4: 
                temp.MONTH = (temp.MONTH+CODE2NUM(REMOTE_CODE)+found_pos)%12; 
                break;
            case 5: 
                temp.YEAR = (temp.YEAR+CODE2NUM(REMOTE_CODE)+found_pos)%100; 
                break;
        }

        // Current config pos
        (pos==0)?Time_Data_Display("SET     ", "SECCOND ", temp, 0x3):
        (pos==1)?Time_Data_Display("SET     ", "MINUTE  ", temp, 0x3):
        (pos==2)?Time_Data_Display("SET     ", "HOUR    ", temp, 0x3):
        (pos==3)?Time_Data_Display("SET     ", "DATE    ", temp, 0x3):
        (pos==4)?Time_Data_Display("SET     ", "MONTH   ", temp, 0x3):
        /*pos=5*/Time_Data_Display("SET     ", "YEAR    ", temp, 0x3);
        // UART_Bytes_Transmit("\nSet-up time:\n", 0);
        // UART_Bytes_Transmit(time_disp_1, 0);
        // UART_Bytes_Transmit("\n", 0);
        // UART_Bytes_Transmit(time_disp_2, 0);
        // delay_ms(500);
    }
    ble_rcv_size = 0;
    // UART_Bytes_Transmit("\nPLS confirm!\n your config!", 0);
    pos = YES_NO();
    if(pos) *t = temp;
    return pos;
}

void Fetch_System_Time(){
    DS1302_Read_Time(&sys_t, 0x3F);
    if(HOLD == 0 && sys_t.SECOND==0){
            UART_Bytes_Transmit("\nSystem status:", 0);
            UART_Bytes_Transmit("\nDevice1: ", 0); UART_Byte_Transmit('0'+(uint8)DEV1);
            UART_Bytes_Transmit("\nDevice2: ", 0); UART_Byte_Transmit('0'+(uint8)DEV2);
            UART_Bytes_Transmit("\nDevice3: ", 0); UART_Byte_Transmit('0'+(uint8)DEV3);
            UART_Bytes_Transmit("\nDevice4: ", 0); UART_Byte_Transmit('0'+(uint8)DEV4);
            UART_Bytes_Transmit("\nDevice5: ", 0); UART_Byte_Transmit('0'+(uint8)DEV5);
            UART_Bytes_Transmit("\nNOTE: 1-off; 0-on\n", 0);
    }
    HOLD=(sys_t.SECOND)?0:HOLD+1;
}

void Fetch_User_Control(){
    if(data_frame==ON_OFF){
        USER_DEV_CTL = (USER_DEV_CTL&0xFE) | ((USER_DEV_CTL&_1st_bit_mask)?0:1);
    }
    // _string_to_lower_case(ble_rcv_data, ble_rcv_size);
    if(ble_has_contained("inv1", 4))
        ble_rcv_size = 0,
        USER_DEV_CTL = (USER_DEV_CTL&0x1)?(USER_DEV_CTL&0xFE):(USER_DEV_CTL|0x1);
    elif(ble_has_contained("inv2", 4))
        ble_rcv_size = 0,
        USER_DEV_CTL = (USER_DEV_CTL&0x2)?(USER_DEV_CTL&0xFD):(USER_DEV_CTL|0x2);
    elif(ble_has_contained("inv3", 4))
        ble_rcv_size = 0,
        USER_DEV_CTL = (USER_DEV_CTL&0x4)?(USER_DEV_CTL&0xFB):(USER_DEV_CTL|0x4);
    elif(ble_has_contained("inv4", 4))
        ble_rcv_size = 0,
        USER_DEV_CTL = (USER_DEV_CTL&0x8)?(USER_DEV_CTL&0xF7):(USER_DEV_CTL|0x8);
    elif(ble_has_contained("inv5", 4))
        ble_rcv_size = 0,
        USER_DEV_CTL = (USER_DEV_CTL&0x10)?(USER_DEV_CTL&0xEF):(USER_DEV_CTL|0x10);
}

void Fetch_System_Trigger(){
    /*
    SYST_TRIGGER
    MSB  7  6  5  4  3  2  1  0  LSB
        [x][x][x][x][x][x][x][x]
                        |  |  ^~
                        |  |  Trigger from Light-dependent resistor
                        |  ^~
                        |  Trigger from timer_1 (exist for a second)
                        ^~
                        Trigger from timer_1 (exist for a second)
    */
    Read_AD_Data(0xA4);
    SYST_TRIGGER = (SYST_TRIGGER&0xFE)|((Read_AD_Data(0xA4)%1000) > 30);
    if(time_equal_cmp(sys_t, timer_1, 0x3F))
        SYST_TRIGGER |= 0x2;
    else
        SYST_TRIGGER &= 0xFD;

    if(time_equal_cmp(sys_t, timer_2, 0x3F))
        SYST_TRIGGER |= 0x4;
    else
        SYST_TRIGGER &= 0xFB;
}

uint8 Update_A_Device_State(uint8 dev, uint8 dev_mask, uint16 clt_dev_sel_mask){
    uint8 res = 0;
    if((CTL_DEV_SEL&clt_dev_sel_mask) == 0){
        res = USER_DEV_CTL&(1<<(dev-1));
    }
    elif((CTL_DEV_SEL&clt_dev_sel_mask) == (0x1<<((dev-1)*2))){
        if(SYS_CTL_INV&dev_mask)//DAYLIGHT
            res = (SYST_TRIGGER&_1st_bit_mask)?(0):(1);
        else
            res = (SYST_TRIGGER&_1st_bit_mask)?(1):(0);
    }
    elif((CTL_DEV_SEL&clt_dev_sel_mask) == (0x2<<((dev-1)*2))){
        if((SYS_CTL_INV&dev_mask) && (SYST_TRIGGER&_2nd_bit_mask))//TIMER 1
            res = 0;
        else
            res = 1;
    }
    elif((CTL_DEV_SEL&clt_dev_sel_mask) == (0x3<<((dev-1)*2))){
        if((SYS_CTL_INV&dev_mask) && (SYST_TRIGGER&_3rd_bit_mask))//TIMER 2
            res = 0;
        else
            res = 1;
    }
    return res;
}

void Update_Device_State(){
    DEV1 = Update_A_Device_State(1, _1st_bit_mask, DEV1_MASK);
    DEV2 = Update_A_Device_State(2, _2nd_bit_mask, DEV2_MASK);
    DEV3 = Update_A_Device_State(3, _3rd_bit_mask, DEV3_MASK);
    DEV4 = Update_A_Device_State(4, _4th_bit_mask, DEV4_MASK);
    DEV5 = Update_A_Device_State(5, _5th_bit_mask, DEV5_MASK);
}

void MODE_RIGHT(){
    switch (DISP_MODE) {
        case MODE_NORMAL: return;
        case MODE_SETUP: return;
        case MODE_SETUP_TIME: DISP_MODE = MODE_SETUP_DEVICE; return;
        case MODE_SETUP_DEVICE: DISP_MODE = MODE_SETUP_TIME; return;
        case MODE_SETUP_DEVICE_1_DISP: ++DISP_MODE; return;
        case MODE_SETUP_DEVICE_2_DISP: ++DISP_MODE; return;
        case MODE_SETUP_DEVICE_3_DISP: ++DISP_MODE; return;
        case MODE_SETUP_DEVICE_4_DISP: ++DISP_MODE; return;
        case MODE_SETUP_DEVICE_5_DISP: DISP_MODE = MODE_SETUP_DEVICE_1_DISP; return;
        case MODE_SETUP_TIME_SYSTEM_DISP: ++DISP_MODE; return;
        case MODE_SETUP_TIME_TIMER_1_DISP: ++DISP_MODE; return;
        case MODE_SETUP_TIME_TIMER_2_DISP: DISP_MODE = MODE_SETUP_TIME_SYSTEM_DISP; return;
    }
}

void MODE_LEFT(){
    switch (DISP_MODE) {
        case MODE_NORMAL: return;
        case MODE_SETUP: return;
        case MODE_SETUP_TIME: DISP_MODE = MODE_SETUP_DEVICE; return;
        case MODE_SETUP_DEVICE: DISP_MODE = MODE_SETUP_TIME; return;
        case MODE_SETUP_DEVICE_1_DISP: DISP_MODE = MODE_SETUP_DEVICE_5_DISP; return;
        case MODE_SETUP_DEVICE_2_DISP: --DISP_MODE; return;
        case MODE_SETUP_DEVICE_3_DISP: --DISP_MODE; return;
        case MODE_SETUP_DEVICE_4_DISP: --DISP_MODE; return;
        case MODE_SETUP_DEVICE_5_DISP: --DISP_MODE; return;
        case MODE_SETUP_TIME_SYSTEM_DISP: DISP_MODE = MODE_SETUP_TIME_TIMER_2_DISP; return;
        case MODE_SETUP_TIME_TIMER_1_DISP: --DISP_MODE; return;
        case MODE_SETUP_TIME_TIMER_2_DISP: --DISP_MODE; return;
    }
}

void Mode_Change(){
    //uint8 found;
    uint32 REMOTE_CODE = read_extracted_frame();

    if(REMOTE_CODE){
        switch (REMOTE_CODE) {
            case PLAY_PAUSE:
                if(DISP_MODE != MODE_NORMAL) 
                    MODE_DOWN(); break;
            case MODE:
                if(DISP_MODE == MODE_NORMAL){
                    DISP_MODE = MODE_SETUP; break;
                } elif(DISP_MODE == MODE_SETUP){
                    DISP_MODE = MODE_NORMAL; break;
                } else{
                    MODE_UP(); break;
                }
            case NEXT: MODE_RIGHT(); break;
            case PREV: MODE_LEFT(); break;
        }
    }
    // elif(ble_rcv_size)
    // {
    //     // _string_to_lower_case(ble_rcv_data, ble_rcv_size);
    //     if(_string_find_pattern("setup", 5, ble_rcv_data, ble_rcv_size, 0)<ble_rcv_size){
    //         DISP_MODE = MODE_SETUP; ble_rcv_size = 0; return;
    //     }
    //     elif(_string_find_pattern("exit", 4, ble_rcv_data, ble_rcv_size, 0)<ble_rcv_size){
    //         // UART_Bytes_Transmit("Backed to NORMAL MODE!", 0);
    //         DISP_MODE = MODE_NORMAL; ble_rcv_size = 0; return;
    //     }
    //     elif(_string_find_pattern("yes", 3, ble_rcv_data, ble_rcv_size, 0)<ble_rcv_size){
    //         MODE_DOWN(); ble_rcv_size = 0; return;
    //     }
    //     elif(_string_find_pattern("no", 2, ble_rcv_data, ble_rcv_size, 0)<ble_rcv_size){
    //         MODE_UP(); ble_rcv_size = 0; return;
    //     }
    //     elif(_string_find_pattern("next", 4, ble_rcv_data, ble_rcv_size, 0)<ble_rcv_size){
    //         MODE_RIGHT(); ble_rcv_size = 0; return;
    //     }
    //     elif(_string_find_pattern("prev", 4, ble_rcv_data, ble_rcv_size, 0)<ble_rcv_size){
    //         MODE_LEFT(); ble_rcv_size = 0; return;
    //     }
    //     elif((found=_string_find_pattern("dev", 3, ble_rcv_data, ble_rcv_size, 0))<ble_rcv_size){
    //         if(found+3 < ble_rcv_size)  
    //             DISP_MODE = MODE_SETUP_DEVICE_1_DISP - 1 + (ble_rcv_data[found+3] - '0');
    //         ble_rcv_size = 0;
    //         return;
    //     }

    // }
}

void Mode_Process(){
    uint8 regx;
    switch (DISP_MODE) {
        case MODE_NORMAL: Time_Data_Display("TIME:   ", "DATE:   ", sys_t, 0x3); return;
        case MODE_SETUP: 
            Time_Data_Display("TIME:   ", "DATE:   ", sys_t, 0x1); 
            // UART_Bytes_Transmit("\nSETUP MODE\n", 0);
            LCD_Simple_Set_Text_1("SETUP MODE      ", 0, 1, 0); 
            return;
        case MODE_SETUP_TIME:
            Time_Data_Display("TIME:   ", "DATE:   ", sys_t, 0x1); 
            // UART_Bytes_Transmit("\nSETUP TIME\n", 0);
            LCD_Simple_Set_Text_1("SETUP TIME      ", 0, 1, 0); 
            return;
        case MODE_SETUP_TIME_SYSTEM_DISP:
            Time_Data_Display("TIME:   ", "DATE:   ", sys_t, 0x1); 
            // UART_Bytes_Transmit("\nSETUP SYSTEM_TIME\n", 0);
            LCD_Simple_Set_Text_1("SETUP SYS_TIME  ", 0, 1, 0); 
            return;
        case MODE_SETUP_TIME_SYSTEM_ACTION:
            MODE_UP();
            if(Setup_Time(&sys_t)) DS1302_Write_Time(&sys_t, 0x37);
            return;
        case MODE_SETUP_TIME_TIMER_1_DISP:
            Time_Data_Display("TIME:   ", "DATE:   ", sys_t, 0x1); 
            // UART_Bytes_Transmit("\nSETUP TIMER_1\n", 0);
            LCD_Simple_Set_Text_1("SETUP TIMER_1   ", 0, 1, 0); 
            return;
        case MODE_SETUP_TIME_TIMER_1_ACTION:
            MODE_UP();
            Setup_Time(&timer_1);
            return;
        case MODE_SETUP_TIME_TIMER_2_DISP:
            Time_Data_Display("TIME:   ", "DATE:   ", sys_t, 0x1);
            // UART_Bytes_Transmit("\nSETUP TIMER_2\n", 0);
            LCD_Simple_Set_Text_1("SETUP TIMER_2   ", 0, 1, 0); 
            return;
        case MODE_SETUP_TIME_TIMER_2_ACTION:
            MODE_UP();
            Setup_Time(&timer_2);
            return;
        case MODE_SETUP_DEVICE:
            Time_Data_Display("TIME:   ", "DATE:   ", sys_t, 0x1); 
            // UART_Bytes_Transmit("\nSETUP DEVICE\n", 0);
            LCD_Simple_Set_Text_1("SETUP DEVICE    ", 0, 1, 0); 
            return;
        case MODE_SETUP_DEVICE_1_DISP:
            Time_Data_Display("TIME:   ", "DATE:   ", sys_t, 0x1); 
            // UART_Bytes_Transmit("\nSETUP DEVICE 1\n", 0);
            LCD_Simple_Set_Text_1("SETUP  DEVICE 1 ", 0, 1, 0); 
            return;
        case MODE_SETUP_DEVICE_1_ACTION:
            //Call set up function!
            MODE_UP();
            regx = Setup_Device();
            if(regx&0x80) return;
            CTL_DEV_SEL = (CTL_DEV_SEL&0xFFFC) | (regx&0x3);
            SYS_CTL_INV = (SYS_CTL_INV&0xFE) | ((regx>>2)&0x1);
            if(regx&0x10) return; //not set dev-state
            USER_DEV_CTL = (USER_DEV_CTL&0xFE) | ((regx>>3)&0x1);
            return;
        case MODE_SETUP_DEVICE_2_DISP:
            Time_Data_Display("TIME:   ", "DATE:   ", sys_t, 0x1); 
            // UART_Bytes_Transmit("\nSETUP DEVICE 2\n", 0);
            LCD_Simple_Set_Text_1("SETUP  DEVICE 2 ", 0, 1, 0); 
            return;
        case MODE_SETUP_DEVICE_2_ACTION:
            //Call set up function!
            MODE_UP();
            regx = Setup_Device();
            if(regx&0x80) return;
            CTL_DEV_SEL = (CTL_DEV_SEL&0xFFF3) | ((regx&0x3)<<2);
            SYS_CTL_INV = (SYS_CTL_INV&0xFD) | ((regx>>1)&0x2);
            if(regx&0x10) return; //not set dev-state
            USER_DEV_CTL = (USER_DEV_CTL&0xFD) | ((regx>>2)&0x2);
            return;
        case MODE_SETUP_DEVICE_3_DISP:
            Time_Data_Display("TIME:   ", "DATE:   ", sys_t, 0x1); 
            // UART_Bytes_Transmit("\nSETUP DEVICE 3\n", 0);
            LCD_Simple_Set_Text_1("SETUP  DEVICE 3 ", 0, 1, 0); 
            return;
        case MODE_SETUP_DEVICE_3_ACTION:
            MODE_UP();
            regx = Setup_Device();
            if(regx&0x80) return;
            CTL_DEV_SEL = (CTL_DEV_SEL&0xFFCF) | ((regx&0x3)<<4);
            SYS_CTL_INV = (SYS_CTL_INV&0xFB) | ((regx)&0x4);
            if(regx&0x10) return; //not set dev-state
            USER_DEV_CTL = (USER_DEV_CTL&0xFB) | ((regx>>1)&0x4);
            return;
        case MODE_SETUP_DEVICE_4_DISP:
            Time_Data_Display("TIME:   ", "DATE:   ", sys_t, 0x1); 
            // UART_Bytes_Transmit("\nSETUP DEVICE 4\n", 0);
            LCD_Simple_Set_Text_1("SETUP  DEVICE 4 ", 0, 1, 0); 
            return;
        case MODE_SETUP_DEVICE_4_ACTION:
            MODE_UP();
            regx = Setup_Device();
            if(regx&0x80) return;
            CTL_DEV_SEL = (CTL_DEV_SEL&0xFF3F) | ((regx&0x3)<<6);
            SYS_CTL_INV = (SYS_CTL_INV&0xF7) | ((regx<<1)&0x8);
            if(regx&0x10) return; //not set dev-state
            USER_DEV_CTL = (USER_DEV_CTL&0xF7) | ((regx)&0x8);
            return;
        case MODE_SETUP_DEVICE_5_DISP:
            Time_Data_Display("TIME:   ", "DATE:   ", sys_t, 0x1); 
            // UART_Bytes_Transmit("\nSETUP DEVICE 5\n", 0);
            LCD_Simple_Set_Text_1("SETUP  DEVICE 5 ", 0, 1, 0); 
            return;
        case MODE_SETUP_DEVICE_5_ACTION:
            MODE_UP();
            regx = Setup_Device();
            if(regx&0x80) return;
            CTL_DEV_SEL = (CTL_DEV_SEL&0xFCFF) | ((regx&0x3)<<8);
            SYS_CTL_INV = (SYS_CTL_INV&0xEF) | ((regx<<2)&0x10);
            if(regx&0x10) return; //not set dev-state
            USER_DEV_CTL = (USER_DEV_CTL&0xEF) | ((regx<<1)&0x10);
            return;
        default:
            UART_Bytes_Transmit("\nSYSTEM FAULT!!!\nPLS PRESS RESET!!!\n", 0);
            LCD_Simple_Set_Text_2("Wrong MODE...", 0, 0, 0);
            LCD_Simple_Set_Text_1("PLS press RESET", 0, 1, 0);
    }
}

void Hello(){
	UART_Bytes_Transmit("\nHello!\nFrom ngxx.fus!\n", 0);
    LCD_Simple_Set_Text_2("Hello!",0, 0, 0);
    LCD_Simple_Set_Text_1("From NGXXFUS :>",0, 1, 0);
    delay_ms(2000);
}

void Main_Initial(){
    LCD_Initial();
    DS1302_Initial();
    IR_Reading_Initial();
    Bluetooth_UART_Initial();
    SPI_Initial();
    //--------------//
    DS1302_Write_Time(&sys_t, 0x7F);
    //--------------//
    Hello();
    //--------------//
    CTL_DEV_SEL=0x0E4;
    SYS_CTL_INV=0x0;
    SYST_DEV_CTL=0x0;
    USER_DEV_CTL=0x0;
}
