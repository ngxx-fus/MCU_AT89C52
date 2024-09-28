#include "main.h"

void main(void){
    initial();
    delay_ms(5000);
    ds1302_read_datetime();
}