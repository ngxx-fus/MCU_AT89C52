#include "base_lib.h"
#include "DS1302.h"
#include "LED.h"

TIME time;

void KHOITAO_LICH(){
    ds1302_initial();
    time.SECOND = 15;
    time.MINUTE = 39;
    time.HOUR = 9;
    time.DATE = 20;
    time.MONTH = 7;
    time.YEAR = 24;
}

void THIETLAP_NGAYGIO(){
    ds1302_write_time(&time, 0x3F);
}

void HT_LICHVANNIEN(){
    ds1302_read_time(&time, 0x3F);
    LED_CODE[7] = DIGIT_CODE[ ((time.MONTH)/10)%10];
    LED_CODE[6] = DIGIT_CODE[ ((time.MONTH)/1)%10];
    LED_CODE[5] = DIGIT_CODE[ ((time.DATE)/10)%10];
    LED_CODE[4] = DIGIT_CODE[ ((time.DATE)/1)%10];
    LED_CODE[3] = DIGIT_CODE[ ((time.HOUR)/10)%10];
    LED_CODE[2] = DIGIT_CODE[ ((time.HOUR)/1)%10];
    LED_CODE[1] = DIGIT_CODE[ ((time.MINUTE)/10)%10];
    LED_CODE[0] = DIGIT_CODE[ ((time.MINUTE)/1)%10];
    HIENTHI_8LED();
}