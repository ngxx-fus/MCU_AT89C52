#include "UART.h"

int main(void){
    UART_Initial();
    UART_Bytes_Transmit("\n\rHello!\nFrom ngxx.fus!", -1);
    while(0x1){
        delay_ms(1000);
    };
    return 0;
}