// #include "LCD16x2.h"
#include "IR_Reading.h"
#include "DS1302.h"
#include "XPT2046.h"
#include "UART.h"

sbit dev0 = P2^0;
sbit dev1 = P2^1;
sbit dev2 = P2^2;
sbit dev3 = P2^3;
sbit dev4 = P2^4;

/*
    MSB 7 6 5 4 3 2 1 0
        | | | | | | | |
        | | | | | | | -- 0-OFF/1:ON by system 
        | | | | | ------ 00:OFF/01:ON/11:NONE by user 
        ---------------- Reserve
*/
uint8 dev0_ctl = 0x6; // Auto based on REMOTE (POWER BUTTON)
uint8 dev1_ctl = 0x6; // Auto based on LIGHT
uint8 dev2_ctl = 0x6; // Auto based on TIMER
uint8 dev3_ctl = 0x6; // Auto based on TIMER
uint8 dev4_ctl = 0x6; // Auto based on TIMER

// code received from IR REMOTE
uint32 IR_data = 0;
TIME system_time = {0, 0, 0, 0, 13, 15, 35},
     dev2_time_on = {0, 0, 0, 0, 0, 0, 0},
     dev2_time_off = {0, 0, 0, 0, 0, 0, 0},
     dev3_time_on = {0, 0, 0, 0, 0, 0, 0},
     dev3_time_off = {0, 0, 0, 0, 0, 0, 0},
     dev4_time_on = {0, 0, 0, 0, 0, 0, 0},
     dev4_time_off = {0, 0, 0, 0, 0, 0, 0};

uint8 CURRENT_INDX = 0;

char temp_str[32];

enum MODEx{
    NORMAL=0,
    SETUP=1,
    SETUP_TIME_DISP=2,
    SETUP_DEV_DISP=3,
};

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
    SEND_BYTE_COMMAND(CLEAR_SCREEN);
}

uint8 YES_NO(){
    uint32 CODE = 0;
    LCD_Simple_Set_Text_2("SAVE? [Y|N]", 11, 0, 0);
    while(0x1){
        CODE = read_extracted_frame();
        switch (CODE) {
            //extend for more options :v
            case PLAY_PAUSE: return 1;
            case MODE: return 0;
            case ON_OFF: return 0;
            default: LCD_Simple_Set_Text_1("...", 3, 1, 0);
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

uint32 get_up_index(uint32 indx){
    if(indx == 0) return 1;
    return (indx/2);
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

void set_str(char str[], uint8 str_size, char dest[], uint8 offset_pos){
    uint8 i;
    REP(i, offset_pos, offset_pos+str_size-1){
        dest[i] = str[i];
    }
}

void hhmmss2str(char str[], TIME t, uint8 offset_pos){
    str[offset_pos+0] = '0'+(t.HOUR/10)%10;
    str[offset_pos+1] = '0'+(t.HOUR/1)%10;
    str[offset_pos+2] = ':';
    str[offset_pos+3] = '0'+(t.MINUTE/10)%10;
    str[offset_pos+4] = '0'+(t.MINUTE/1)%10;
    str[offset_pos+5] = ':';
    str[offset_pos+6] = '0'+(t.SECOND/10)%10;
    str[offset_pos+7] = '0'+(t.SECOND/1)%10;
}

void code_proc(uint32 CODE){
    switch (CODE) {
        case ON_OFF:
            // dev0_syst_ctl = (dev0_syst_ctl)?(0):(1);
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
        case NORMAL:
            LCD_Simple_Set_Text_1("[CONTROL CENTER]", 16, 0, 0);
            temp_str[0]='T'; temp_str[1]='I'; temp_str[2]='M'; temp_str[3]='E'; temp_str[4]=':';
            temp_str[5]=' ';
            hhmmss2str(temp_str, system_time, 6);
            LCD_Simple_Set_Text_1(temp_str, 14, 1, 0);
            return;
        case SETUP:

        default:
            LCD_Simple_Set_Text_2("ERROR!", 6, 0, 0);
    }
}

void Hello(){
    char str[] = "Hello! From ***NGXXFUS***";
    LCD_INITIAL();
    // LCD_Set_Text(str, sizeof(str)/sizeof(char)-1, true, true, 0, 0);
    LCD_Simple_Set_Text_1("[Hello!]", 8, 0, 0);
    LCD_Simple_Set_Text_1("From NGXXFUS!", 13, 1, 0);

    delay_ms(1000);     delay_ms(1000);
    LCD_Simple_Set_Text_2("[CONTROL CENTER]", 16, 0, 0);
    LCD_Simple_Set_Text_1("v.0.1.4", 10, 1, 0);

    delay_ms(1000);     delay_ms(1000);
    LCD_Simple_Set_Text_1("SYSTEM STARTUP...", 17, 1, 0);

    delay_ms(1000);     delay_ms(1000);
}

void System_Initial(){
    Hello();
    IR_Reading_Initial();
    UART_Initial();
    ds1302_initial();
    ds1302_write_time(&system_time, 0x7);
}