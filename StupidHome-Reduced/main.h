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


sbit DEV1 = P2^0;
sbit DEV2 = P2^1;
sbit DEV3 = P2^2;
sbit DEV4 = P2^3;
sbit DEV5 = P2^4;


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


void Main_Initial(){
    LCD_Initial();
    DS1302_Initial();
    IR_Reading_Initial();
    Bluetooth_UART_Initial();
    SPI_Initial();
    //--------------//
    Hello();
    //--------------//
    DS1302_Write_Time(&sys_t, 0x7F);
    //--------------//
    
}
