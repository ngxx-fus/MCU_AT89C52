// refs: https://www.electronicwings.com/8051/8051-uart
// refs: https://embetronicx.com/tutorials/microcontrollers/8051/8051-uart-tutorial-serial-communication/

#include "Base_Lib.h"

char UART_Received_Data = 0;

void UART_Byte_Transmit(char transmit_data){
    // Copy data to BUFFER
    SBUF = transmit_data;
    // while for another Transmission until it end
    while (TI==0);
    // Reset TI flag to start this Transmission
    TI = 0;
}

void UART_Bytes_Transmit(char transmit_data[], uint8 transmit_data_size){
    uint8 i;
    REP(i, 1, transmit_data_size){
        UART_Byte_Transmit(transmit_data[i-1]);
    }

}

void UART_Initial(){
    GLOBAL_INT(ENABLE);
    ES = 1; //Serial interrupt
    //----------------------//
    TMOD |= 0x20; //Set timer 2 mode 8bit
    TH1 = 0xFD; //load value for baud rate = 9600
    SCON = 0x50;
    TR1 = 1; // start timer 1
}

void UART_Received() interrupt 4 {
    UART_Received_Data = SBUF;
}