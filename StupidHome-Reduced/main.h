#include "Time.h"
#include "String_Ultils.h"
#include "DS1302.h"
#include "Utilities.h"
#include "XPT2046.h"
#include "UART_BLE.h"
#include "LCD_1602.h"
#include "IR_Reading.h"



sbit DEV1 = P2^0;
sbit DEV2 = P2^1;
sbit DEV3 = P2^2;
sbit DEV4 = P2^3;
sbit DEV5 = P2^4;

uint32 HOLD;
char time_disp_1[]="TIME:   XX:XX:XX";
char time_disp_2[]="DATE:   XX/XX/XX";

TIME    sys_t = {7  , 12, 11, 24, 21, 05, 45}, 
        timer_1 = {7  , 12, 11, 24, 21, 05, 55}, 
        timer_2 = {7  , 12, 11, 24, 21, 06, 5};

void Time_Data_Display(char label_1[], char label_2[], TIME t, uint8 SEL){
    // Show date-time in LCD with label_1 and label_2 (width=8chars)
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

void Fetch_System_Time(){
    // Read time from DS1304 and update time in sys_t
    DS1302_Read_Time(&sys_t, 0x7F);
    // Show in LCD
    Time_Data_Display("TIME:   ", "DATE:   ", sys_t, 0x3);
}

void Send_Report_To_Smartphone(uint8 bypass){
    // Send report back to smartphone
    // This func is called several times in a minute, so we need a variable to help this
    // function only called one time in a minute.
    // bypass is a parametter to force send report without check HOLD variable.
    if(bypass || HOLD){
            UART_Bytes_Transmit("\n-------------------------", 0);
            UART_Bytes_Transmit("\nSystem time:\n", 0);
            UART_Bytes_Transmit(time_disp_1, 0);
            UART_Byte_Transmit('\n');
            UART_Bytes_Transmit(time_disp_2, 0);
            UART_Bytes_Transmit("\nSystem status:", 0);
            UART_Bytes_Transmit("\nDevice 1: ", 0); UART_Bytes_Transmit((DEV1)?"OFF":"ON", 0);
            UART_Bytes_Transmit("\nDevice 2: ", 0); UART_Bytes_Transmit((DEV2)?"OFF":"ON", 0);
            UART_Bytes_Transmit("\nDevice 3: ", 0); UART_Bytes_Transmit((DEV3)?"OFF":"ON", 0);
            UART_Bytes_Transmit("\nDevice 4: ", 0); UART_Bytes_Transmit((DEV4)?"OFF":"ON", 0);
            UART_Bytes_Transmit("\nDevice 5: ", 0); UART_Bytes_Transmit((DEV5)?"OFF":"ON", 0);
            UART_Byte_Transmit('\n');
    }
    HOLD =(sys_t.MINUTE && sys_t.SECOND)?0:(HOLD%100)+1;
}

void Update_Device_State(){
    // Update devices based on control (by user/timer);
    uint32 IR_CODE;
    // Read data received from Remote
    IR_CODE = read_extracted_frame();
    // Toggle state of DEV-5
    if(IR_CODE == ON_OFF) DEV5?(DEV5=0):(DEV5=1);
    // Toggle all state of DEVs
    if(IR_CODE == PLAY_PAUSE){
        DEV1?(DEV1=0):(DEV1=1);
        DEV2?(DEV2=0):(DEV2=1);
        DEV3?(DEV3=0):(DEV3=1);
        DEV4?(DEV4=0):(DEV4=1);
        DEV5?(DEV5=0):(DEV5=1);
    }
    // ON/OFF dev base on timer;
    if(time_equal_cmp(sys_t, timer_1, 0x7)) DEV3 = 1;
    if(time_equal_cmp(sys_t, timer_2, 0x7)) DEV4 = 0;
    // ON/OFF dev base on bluetooth command.
    if(ble_has_contained("ON1", 3)) DEV1 = 1, ble_rcv_size = 0;
    if(ble_has_contained("OFF1", 4)) DEV1 = 0, ble_rcv_size = 0;
    if(ble_has_contained("ON2", 3)) DEV2 = 1, ble_rcv_size = 0;
    if(ble_has_contained("OFF2", 4)) DEV2 = 0, ble_rcv_size = 0;
    if(ble_has_contained("REPORT", 6)) {Send_Report_To_Smartphone(1); ble_rcv_size = 0;};
}

void Main_Initial(){
    LCD_Initial();
    DS1302_Initial();
    IR_Reading_Initial();
    Bluetooth_UART_Initial();
    SPI_Initial();
    //--------------//
    DS1302_Write_Time(&sys_t, 0x7F);
    
}
