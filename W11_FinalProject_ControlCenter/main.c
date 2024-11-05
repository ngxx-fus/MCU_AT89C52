#include "main.h"

int main(void){
    System_Initial();
    UART_Bytes_Received[0] = 'R';
    UART_Bytes_Received[1] = ':';
    UART_Bytes_Received[2] = ' ';
    UART_Bytes_Received_Size = 3;
    delay_ms(1000);
    UART_Bytes_Transmit("Hello!", 7);
    while(1){
        UART_Bytes_Transmit("R: \n", 5);
        //UART_Bytes_Transmit(UART_Bytes_Received, UART_Bytes_Received_Size);
        // UART_Bytes_Transmit("\n\n", 4);
        while(1);
    };
    return 0;
}