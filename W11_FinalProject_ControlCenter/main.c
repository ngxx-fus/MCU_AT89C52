#include "main.h"

int main(void){
    System_Initial();
    delay_ms(1000);
    UART_Bytes_Transmit("Hello!", 6);
    while(1);
    return 0;
}