#include "String_Ultils.h"
#include "UART_BLE.h"
#include "DS1302.h"
#include "Utilities.h"
#include "XPT2046.h"
#include "UART_BLE.h"
#include "LCD_1602.h"
#include "LCD_1602.h"
#include "IR_Reading.h"

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

uint8 SYS_CTL;
uint8 DISP_MODE = 0;
uint8 SYST_DEV_CTL;
uint8 USER_DEV_CTL; 
uint8 SYS_CTL_INV;
uint16 CTL_DEV_SEL; 

char time_disp_1[]="TIME:   XX:XX:XX";
char time_disp_2[]="DATE:   XX/XX/XX";

TIME    sys_t = {7  , 10, 11, 24, 21, 05, 45}, 
        timer_1 = {0, 0, 0, 0, 0, 0, 0}, 
        timer_2 = {0, 0, 0, 0, 0, 0, 0};

uint8 time_equal_cmp(TIME a, TIME b, uint8 mask){
    if( ((mask&0x1)!=0) && (a.SECOND!=b.SECOND) ) 
        return false;
    if( ((mask&0x2)!=0) && (a.MINUTE!=b.MINUTE) ) 
        return false;
    if( ((mask&0x4)!=0) && (a.HOUR!=b.HOUR) ) 
        return false;
    return true;
}

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
    if(SEL & 0x1){
        DS1302_Read_Time(&t, 0x7);
        time_disp_1[8] = digit2char(x10_digit(t.HOUR));
        time_disp_1[9] = digit2char(x1_digit(t.HOUR));
        time_disp_1[11] = digit2char(x10_digit(t.MINUTE));
        time_disp_1[12] = digit2char(x1_digit(t.MINUTE));
        time_disp_1[14] = digit2char(x10_digit(t.SECOND));
        time_disp_1[15] = digit2char(x1_digit(t.SECOND));
        LCD_Simple_Set_Text_1(time_disp_1, 16, 0, 0);
    }
    if(SEL & 0x2){
        DS1302_Read_Time(&t, 0x38);
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
        if(ans)
            LCD_Simple_Set_Text_1("> YES", 0, 1, 0);
        else
            LCD_Simple_Set_Text_1("> NO ", 0, 1, 0);
        delay_ms(1000);
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

uint8 Setup_Time(TIME* t){
    TIME temp;
    uint8 pos = 0;
    uint32 REMOTE_CODE = 0;
    //DS1302_Read_Time(&temp, 0x3F);
    LCD_Simple_Set_Text_1("TIME SETUP >", 0, 0, 0);
    while(0x1){
        // Direct
        REMOTE_CODE = read_extracted_frame();
        switch (REMOTE_CODE) {
            case MODE: return 0;
            case NEXT: pos = (pos+1)%6; break;
            case PREV: pos = (pos-1+6)%6; break;
            case PLAY_PAUSE: break;
        }
        switch (pos) {
            case 0: 
                temp.SECOND = (temp.SECOND+CODE2NUM(REMOTE_CODE))%60; 
                break;
            case 1: 
                temp.MINUTE = (temp.MINUTE+CODE2NUM(REMOTE_CODE))%60; 
                break;
            case 2: 
                temp.HOUR = (temp.HOUR+CODE2NUM(REMOTE_CODE))%24; 
                break;
            case 3: 
                temp.DATE = (temp.DATE+CODE2NUM(REMOTE_CODE))%31+1; 
                break;
            case 4: 
                temp.MONTH = (temp.MONTH+CODE2NUM(REMOTE_CODE))%31+1; 
                break;
        }

        // Current config pos
        (pos==0)?Time_Data_Display("SET     ", "SEC     ", temp, 0x3):
        (pos==1)?Time_Data_Display("SET     ", "MIN     ", temp, 0x3):
        (pos==2)?Time_Data_Display("SET     ", "HOUR    ", temp, 0x3):
        (pos==3)?Time_Data_Display("SET     ", "DATE    ", temp, 0x3):
        (pos==4)?Time_Data_Display("SET     ", "MON     ", temp, 0x3):
        /*pos=5*/Time_Data_Display("SET     ", "year    ", temp, 0x3);
    }
    pos = YES_NO();
    if(pos) *t = temp;
    return pos;
}

void Fetch_System_Control(){
    Read_AD_Data(0xA4);
    SYS_CTL = (SYS_CTL&0xFE)|((Read_AD_Data(0xA4)%1000) > 30);
    SYS_CTL = (SYS_CTL&0xFD)|(time_equal_cmp(sys_t, timer_1, 0x7));
    SYS_CTL = (SYS_CTL&0xFB)|(time_equal_cmp(sys_t, timer_1, 0x7));
}

void Update_Device_State(){
    //DEV1
    switch (CTL_DEV_SEL&0x3) {
        case 0x0:
            DEV1 = USER_DEV_CTL&0x1;
            break;
        case 0x1:
            if(SYS_CTL&0x1)//DAYLIGHT
                DEV1 = (SYS_CTL_INV&0x1)?(0):(1);
            break;
        case 0x2:
            if(SYS_CTL&0x2)//TIMER_1
                DEV1 = (SYS_CTL_INV&0x1)?(0):(1);
            break;
        case 0x3:
            if(SYS_CTL&0x3)//TIMER_2
                DEV1 = (SYS_CTL_INV&0x1)?(0):(1);
            break;
    }
    //DEV2
    switch (CTL_DEV_SEL&0xA) {
        case 0x0:
            DEV2 = USER_DEV_CTL&0x2;
            break;
        case 0x4:
            if(SYS_CTL&0x1)//DAYLIGHT
                DEV2 = (SYS_CTL_INV&0x2)?(0):(1);
            break;
        case 0x8:
            if(SYS_CTL&0x2)//TIMER_1
                DEV2 = (SYS_CTL_INV&0x2)?(0):(1);
            break;
        case 0xA:
            if(SYS_CTL&0x3)//TIMER_2
                DEV2 = (SYS_CTL_INV&0x2)?(0):(1);
            break;
    }
    //DEV3
    switch (CTL_DEV_SEL&0x30) {
        case 0x0:
            DEV3 = USER_DEV_CTL&0x4;
            break;
        case 0x10:
            if(SYS_CTL&0x1)//DAYLIGHT
                DEV3 = (SYS_CTL_INV&0x4)?(0):(1);
            break;
        case 0x20:
            if(SYS_CTL&0x2)//TIMER_1
                DEV3 = (SYS_CTL_INV&0x4)?(0):(1);
            break;
        case 0x30:
            if(SYS_CTL&0x3)//TIMER_2
                DEV3 = (SYS_CTL_INV&0x4)?(0):(1);
            break;
    }
    //DEV4
    switch (CTL_DEV_SEL&0xA0) {
        case 0x0:
            DEV4 = USER_DEV_CTL&0x8;
            break;
        case 0x40:
            if(SYS_CTL&0x1)//DAYLIGHT
                DEV4 = (SYS_CTL_INV&0x8)?(0):(1);
            break;
        case 0x80:
            if(SYS_CTL&0x2)//TIMER_1
                DEV4 = (SYS_CTL_INV&0x8)?(0):(1);
            break;
        case 0xA0:
            if(SYS_CTL&0x3)//TIMER_2
                DEV4 = (SYS_CTL_INV&0x8)?(0):(1);
            break;
    }
    //DEV5
    switch (CTL_DEV_SEL&0x300) {
        case 0x0:
            DEV5 = USER_DEV_CTL&0x10;
            break;
        case 0x100:
            if(SYS_CTL&0x1)//DAYLIGHT
                DEV5 = (SYS_CTL_INV&0x10)?(0):(1);
            break;
        case 0x200:
            if(SYS_CTL&0x2)//TIMER_1
                DEV5 = (SYS_CTL_INV&0x10)?(0):(1);
            break;
        case 0x300:
            if(SYS_CTL&0x3)//TIMER_2
                DEV5 = (SYS_CTL_INV&0x10)?(0):(1);
            break;
    }
}

void MODE_UP(){
    DISP_MODE/=5;
}

void MODE_DOWN(){
    if(DISP_MODE > 170) return;
    DISP_MODE*=5;
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
    uint8 found;
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
    }elif(ble_rcv_size)
    {
        _string_to_lower_case(ble_rcv_data, ble_rcv_size);
        if(_string_find_pattern("setup", 5, ble_rcv_data, ble_rcv_size, 0)<ble_rcv_size){
            DISP_MODE = MODE_SETUP; ble_rcv_size = 0; return;
        }
        elif(_string_find_pattern("exit", 4, ble_rcv_data, ble_rcv_size, 0)<ble_rcv_size){
            UART_Bytes_Transmit("Backed to NORMAL MODE!", 0);
            DISP_MODE = MODE_NORMAL; ble_rcv_size = 0; return;
        }
        elif(_string_find_pattern("yes", 3, ble_rcv_data, ble_rcv_size, 0)<ble_rcv_size){
            MODE_DOWN(); ble_rcv_size = 0; return;
        }
        elif(_string_find_pattern("no", 2, ble_rcv_data, ble_rcv_size, 0)<ble_rcv_size){
            MODE_UP(); ble_rcv_size = 0; return;
        }
        elif(_string_find_pattern("next", 4, ble_rcv_data, ble_rcv_size, 0)<ble_rcv_size){
            MODE_RIGHT(); ble_rcv_size = 0; return;
        }
        elif(_string_find_pattern("prev", 4, ble_rcv_data, ble_rcv_size, 0)<ble_rcv_size){
            MODE_LEFT(); ble_rcv_size = 0; return;
        }
        elif((found=_string_find_pattern("dev", 3, ble_rcv_data, ble_rcv_size, 0))<ble_rcv_size){
            if(found+3 < ble_rcv_size)  
                DISP_MODE = MODE_SETUP_DEVICE_1_DISP - 1 + (ble_rcv_data[found+3] - '0');
            ble_rcv_size = 0;
            return;
        }

    }
}

void Mode_Process(){
    switch (DISP_MODE) {
        case MODE_NORMAL: Time_Data_Display("TIME:   ", "DATE:   ", sys_t, 0x3); return;
        case MODE_SETUP: 
            Time_Data_Display("TIME:   ", "DATE:   ", sys_t, 0x1); 
            UART_Bytes_Transmit("\nSETUP MODE\n", 0);
            LCD_Simple_Set_Text_1("SETUP MODE      ", 0, 1, 0); 
            return;
        case MODE_SETUP_TIME:
            Time_Data_Display("TIME:   ", "DATE:   ", sys_t, 0x1); 
            UART_Bytes_Transmit("\nSETUP TIME\n", 0);
            LCD_Simple_Set_Text_1("SETUP TIME      ", 0, 1, 0); 
            return;
        case MODE_SETUP_TIME_SYSTEM_DISP:
            Time_Data_Display("TIME:   ", "DATE:   ", sys_t, 0x1); 
            UART_Bytes_Transmit("\nSETUP SYSTEM_TIME\n", 0);
            LCD_Simple_Set_Text_1("SETUP SYS_TIME  ", 0, 1, 0); 
            return;
        case MODE_SETUP_TIME_SYSTEM_ACTION:
            if(Setup_Time(&sys_t)) DS1302_Write_Time(&sys_t, 0x37);
            MODE_UP();
            return;
        case MODE_SETUP_TIME_TIMER_1_DISP:
            Time_Data_Display("TIME:   ", "DATE:   ", sys_t, 0x1); 
            UART_Bytes_Transmit("\nSETUP TIMER_1\n", 0);
            LCD_Simple_Set_Text_1("SETUP TIMER_1   ", 0, 1, 0); 
            return;
        case MODE_SETUP_TIME_TIMER_1_ACTION:
            Setup_Time(&timer_1);
            MODE_UP();
            return;
        case MODE_SETUP_TIME_TIMER_2_DISP:
            Time_Data_Display("TIME:   ", "DATE:   ", sys_t, 0x1);
            UART_Bytes_Transmit("\nSETUP TIMER_2\n", 0);
            LCD_Simple_Set_Text_1("SETUP TIMER_2   ", 0, 1, 0); 
            return;
        case MODE_SETUP_TIME_TIMER_2_ACTION:
            Setup_Time(&timer_2);
            MODE_UP();
            return;
        case MODE_SETUP_DEVICE:
            Time_Data_Display("TIME:   ", "DATE:   ", sys_t, 0x1); 
            UART_Bytes_Transmit("\nSETUP DEVICE\n", 0);
            LCD_Simple_Set_Text_1("SETUP DEVICE    ", 0, 1, 0); 
            return;
        case MODE_SETUP_DEVICE_1_DISP:
            Time_Data_Display("TIME:   ", "DATE:   ", sys_t, 0x1); 
            UART_Bytes_Transmit("\nSETUP DEVICE 1\n", 0);
            LCD_Simple_Set_Text_1("SETUP  DEVICE 1 ", 0, 1, 0); 
            return;
        case MODE_SETUP_DEVICE_1_ACTION:
            //Call set up function!
            MODE_UP();
            return;
        case MODE_SETUP_DEVICE_2_DISP:
            Time_Data_Display("TIME:   ", "DATE:   ", sys_t, 0x1); 
            UART_Bytes_Transmit("\nSETUP DEVICE 2\n", 0);
            LCD_Simple_Set_Text_1("SETUP  DEVICE 2 ", 0, 1, 0); 
            return;
        case MODE_SETUP_DEVICE_2_ACTION:
            //Call set up function!
            MODE_UP();
            return;
        case MODE_SETUP_DEVICE_3_DISP:
            Time_Data_Display("TIME:   ", "DATE:   ", sys_t, 0x1); 
            UART_Bytes_Transmit("\nSETUP DEVICE 3\n", 0);
            LCD_Simple_Set_Text_1("SETUP  DEVICE 3 ", 0, 1, 0); 
            return;
        case MODE_SETUP_DEVICE_3_ACTION:
            //Call set up function!
            MODE_UP();
            return;
        case MODE_SETUP_DEVICE_4_DISP:
            Time_Data_Display("TIME:   ", "DATE:   ", sys_t, 0x1); 
            UART_Bytes_Transmit("\nSETUP DEVICE 4\n", 0);
            LCD_Simple_Set_Text_1("SETUP  DEVICE 4 ", 0, 1, 0); 
            return;
        case MODE_SETUP_DEVICE_4_ACTION:
            //Call set up function!
            MODE_UP();
            return;
        case MODE_SETUP_DEVICE_5_DISP:
            Time_Data_Display("TIME:   ", "DATE:   ", sys_t, 0x1); 
            UART_Bytes_Transmit("\nSETUP DEVICE 5\n", 0);
            LCD_Simple_Set_Text_1("SETUP  DEVICE 5 ", 0, 1, 0); 
            return;
        case MODE_SETUP_DEVICE_5_ACTION:
            //Call set up function!
            MODE_UP();
            return;
        default:
            UART_Bytes_Transmit("\nWrong MODE...\nPLS press RESET\n", 0);
            LCD_Simple_Set_Text_2("Wrong MODE...", 0, 0, 0);
            LCD_Simple_Set_Text_1("PLS press RESET", 0, 1, 0);
    }
}

// void Hello(){
//     char ble_transmit_text[] =  "\nHello!\nFrom ngxx.fus!\n";
// 	UART_Bytes_Transmit(ble_transmit_text, sizeof(ble_transmit_text)-1);
//     LCD_Simple_Set_Text_2("Hello!",0, 0, 0);
//     LCD_Simple_Set_Text_1("From NGXXFUS :>",0, 1, 0);
//     delay_ms(2000);
// }

void Main_Initial(){
    LCD_Initial();
    DS1302_Initial();
    IR_Reading_Initial();
    Bluetooth_UART_Initial();
    SPI_Initial();
    //--------------//
    DS1302_Write_Time(&sys_t, 0x7);
    //--------------//
    // Hello();
}
