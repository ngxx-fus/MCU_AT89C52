#include "String_Ultils.h"
#include "UART_BLE.h"
#include "DS1302.h"
#include "XPT2046.h"
#include "UART_BLE.h"
#include "LCD_1602.h"
#include "LCD_1602.h"
#include "IR_Reading.h"



#define digit2char(x) ((x)+'0')
#define str_len(x) sizeof(x)
#define x1_digit(x) ((x)%10)
#define x10_digit(x) (((x)/10)%10)
#define x100_digit(x) (((x)/100)%10)
#define x1000_digit(x) (((x)/1000)%10)


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

uint8 main_loop_hold;
uint8 DISP_MODE = 0;
uint8 SYST_DEV_CTL;
uint8 USER_DEV_CTL; 
uint16 CTL_DEV_SEL; 

TIME    sys_t = {7  , 10, 11, 24, 21, 05, 45}, 
        timer_1 = {0, 0, 0, 0, 0, 0, 0}, 
        timer_2 = {0, 0, 0, 0, 0, 0, 0};

void System_Time_Fetch(uint8 SEL){
    char time_disp_1[]="TIME:   XX:XX:XX";
    char time_disp_2[]="DATE:   XX/XX/XX";
    if(SEL & 0x1){
        DS1302_Read_Time(&sys_t, 0x7);
        time_disp_1[8] = digit2char(x10_digit(sys_t.HOUR));
        time_disp_1[9] = digit2char(x1_digit(sys_t.HOUR));
        time_disp_1[11] = digit2char(x10_digit(sys_t.MINUTE));
        time_disp_1[12] = digit2char(x1_digit(sys_t.MINUTE));
        time_disp_1[14] = digit2char(x10_digit(sys_t.SECOND));
        time_disp_1[15] = digit2char(x1_digit(sys_t.SECOND));
        LCD_Simple_Set_Text_1(time_disp_1, 16, 0, 0);
    }
    if(SEL & 0x2){
        DS1302_Read_Time(&sys_t, 0x38);
        time_disp_2[8] = digit2char(x10_digit(sys_t.DATE));
        time_disp_2[9] = digit2char(x1_digit(sys_t.DATE));
        time_disp_2[11] = digit2char(x10_digit(sys_t.MONTH));
        time_disp_2[12] = digit2char(x1_digit(sys_t.MONTH));
        time_disp_2[14] = digit2char(x10_digit(sys_t.YEAR));
        time_disp_2[15] = digit2char(x1_digit(sys_t.YEAR));
        LCD_Simple_Set_Text_1(time_disp_2, 16, 1, 0);
    }
}

uint8 YES_NO(){
    LCD_Simple_Set_Text_2("SAVE? [Y|N]", 11, 0, 0);
    while(0x1){
        if(data_frame)
            switch (data_frame) {
                //extend for more options :v
                case PLAY_PAUSE: data_frame = 0; return 1;
                case MODE: data_frame = 0;  return 0;
                case ON_OFF: data_frame = 0;  return 0;
            }
        if(ble_rcv_size){
            _string_to_lower_case(ble_rcv_data, ble_rcv_size);
            if(_string_find_pattern("yes", 3, ble_rcv_data, ble_rcv_size, 0))
                return 1;
            if(_string_find_pattern("no", 2, ble_rcv_data, ble_rcv_size, 0))
                return 1;
        }
    }
    return 0;
}

uint32 have_daylight(){
    Read_AD_Data(0xA4);
    if( (Read_AD_Data(0xA4)%1000) > 30)
        return true;
    return false;
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
                MODE_DOWN(); clear_frame(); break;
        case MODE:
            if(DISP_MODE == MODE_NORMAL) 
                MODE_DOWN(); clear_frame(); break;
            if(DISP_MODE == MODE_SETUP) 
                MODE_UP(); clear_frame(); break;
        case NEXT: MODE_RIGHT(); clear_frame(); break;
        case PREV: MODE_LEFT(); clear_frame(); break;
    }
    }elif(ble_rcv_size)
    {
        _string_to_lower_case(ble_rcv_data, ble_rcv_size);
        if(_string_find_pattern("setup", 5, ble_rcv_data, ble_rcv_size, 0)<ble_rcv_size)
        {
            DISP_MODE = MODE_SETUP; ble_rcv_size = 0; return;
        }
        elif(_string_find_pattern("exit", 4, ble_rcv_data, ble_rcv_size, 0)<ble_rcv_size)
        {
            DISP_MODE = MODE_NORMAL; ble_rcv_size = 0; return;
        }
        elif(_string_find_pattern("yes", 3, ble_rcv_data, ble_rcv_size, 0)<ble_rcv_size)
        {
            MODE_DOWN(); ble_rcv_size = 0; return;
        }
        elif(_string_find_pattern("no", 2, ble_rcv_data, ble_rcv_size, 0)<ble_rcv_size)
        {
            MODE_UP(); ble_rcv_size = 0; return;
        }
        elif(_string_find_pattern("next", 4, ble_rcv_data, ble_rcv_size, 0)<ble_rcv_size)
        {
            MODE_RIGHT(); ble_rcv_size = 0; return;
        }
        elif(_string_find_pattern("prev", 4, ble_rcv_data, ble_rcv_size, 0)<ble_rcv_size)
        {
            MODE_LEFT(); ble_rcv_size = 0; return;
        }
        elif((found=_string_find_pattern("dev", 3, ble_rcv_data, ble_rcv_size, 0))<ble_rcv_size)
        {
            if(found+3 < ble_rcv_size)  
                DISP_MODE = MODE_SETUP_DEVICE_1_DISP - 1 + (ble_rcv_data[found+3] - '0');
            ble_rcv_size = 0;
            return;
        }

    }
}

void Mode_Process(){
    switch (DISP_MODE) {
        case MODE_NORMAL: System_Time_Fetch(0x3); return;
        case MODE_SETUP: 
            System_Time_Fetch(0x1); 
            UART_Bytes_Transmit("\nSETUP MODE\n", 0);
            LCD_Simple_Set_Text_1("SETUP MODE      ", 0, 1, 0); 
            return;
        case MODE_SETUP_TIME:
            System_Time_Fetch(0x1); 
            UART_Bytes_Transmit("\nSETUP TIME\n", 0);
            LCD_Simple_Set_Text_1("SETUP TIME      ", 0, 1, 0); 
            return;
        case MODE_SETUP_TIME_SYSTEM_DISP:
            System_Time_Fetch(0x1); 
            UART_Bytes_Transmit("\nSETUP SYSTEM_TIME\n", 0);
            LCD_Simple_Set_Text_1("SETUP SYS_TIME  ", 0, 1, 0); 
            return;
        case MODE_SETUP_TIME_SYSTEM_ACTION:
            //Call set up function!
            MODE_UP();
            return;
        case MODE_SETUP_TIME_TIMER_1_DISP:
            System_Time_Fetch(0x1); 
            UART_Bytes_Transmit("\nSETUP TIMER_1\n", 0);
            LCD_Simple_Set_Text_1("SETUP TIMER_1   ", 0, 1, 0); 
            return;
        case MODE_SETUP_TIME_TIMER_1_ACTION:
            //Call set up function!
            MODE_UP();
            return;
        case MODE_SETUP_TIME_TIMER_2_DISP:
            System_Time_Fetch(0x1);
            UART_Bytes_Transmit("\nSETUP TIMER_2\n", 0);
            LCD_Simple_Set_Text_1("SETUP TIMER_2   ", 0, 1, 0); 
            return;
        case MODE_SETUP_TIME_TIMER_2_ACTION:
            //Call set up function!
            MODE_UP();
            return;
        case MODE_SETUP_DEVICE:
            System_Time_Fetch(0x1); 
            UART_Bytes_Transmit("\nSETUP DEVICE\n", 0);
            LCD_Simple_Set_Text_1("SETUP DEVICE    ", 0, 1, 0); 
            return;
        case MODE_SETUP_DEVICE_1_DISP:
            System_Time_Fetch(0x1); 
            UART_Bytes_Transmit("\nSETUP DEVICE 1\n", 0);
            LCD_Simple_Set_Text_1("SETUP  DEVICE 1 ", 0, 1, 0); 
            return;
        case MODE_SETUP_DEVICE_1_ACTION:
            //Call set up function!
            MODE_UP();
            return;
        case MODE_SETUP_DEVICE_2_DISP:
            System_Time_Fetch(0x1); 
            UART_Bytes_Transmit("\nSETUP DEVICE 2\n", 0);
            LCD_Simple_Set_Text_1("SETUP  DEVICE 2 ", 0, 1, 0); 
            return;
        case MODE_SETUP_DEVICE_2_ACTION:
            //Call set up function!
            MODE_UP();
            return;
        case MODE_SETUP_DEVICE_3_DISP:
            System_Time_Fetch(0x1); 
            UART_Bytes_Transmit("\nSETUP DEVICE 3\n", 0);
            LCD_Simple_Set_Text_1("SETUP  DEVICE 3 ", 0, 1, 0); 
            return;
        case MODE_SETUP_DEVICE_3_ACTION:
            //Call set up function!
            MODE_UP();
            return;
        case MODE_SETUP_DEVICE_4_DISP:
            System_Time_Fetch(0x1); 
            UART_Bytes_Transmit("\nSETUP DEVICE 4\n", 0);
            LCD_Simple_Set_Text_1("SETUP  DEVICE 4 ", 0, 1, 0); 
            return;
        case MODE_SETUP_DEVICE_4_ACTION:
            //Call set up function!
            MODE_UP();
            return;
        case MODE_SETUP_DEVICE_5_DISP:
            System_Time_Fetch(0x1); 
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

void Hello(){
    char ble_transmit_text[] =  "\nHello!\nFrom ngxx.fus!\n";
	UART_Bytes_Transmit(ble_transmit_text, sizeof(ble_transmit_text)-1);
    LCD_Simple_Set_Text_2("Hello!",0, 0, 0);
    LCD_Simple_Set_Text_1("From NGXXFUS :>",0, 1, 0);
    delay_ms(2000);
}

void Main_Initial(){
    LCD_Initial();
    DS1302_Initial();
    IR_Reading_Initial();
    Bluetooth_UART_Initial();
    //--------------//
    DS1302_Write_Time(&sys_t, 0x7);
    //--------------//
    Hello();
}
