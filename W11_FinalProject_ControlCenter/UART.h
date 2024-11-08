// refs: https://www.electronicwings.com/8051/8051-uart
// refs: https://embetronicx.com/tutorials/microcontrollers/8051/8051-uart-tutorial-serial-communication/

#include "Base_Lib.h"
#include "LCD16x2.h"

int8 	rcv_size = 0;
char   	data_rcv[8];

void UART_Byte_Transmit(char transmit_data){
    // Copy data to BUFFER
    SBUF = transmit_data;
    // while for another Transmission until it end
    while (TI==0);
    // Reset TI flag to start this Transmission
    TI = 0;
}

void UART_Bytes_Transmit(char transmit_data[], int32 transmit_data_size){
	int32 i;
	if(transmit_data_size == -1){
		while(*transmit_data){
			UART_Byte_Transmit(*transmit_data);
			transmit_data++;
		}
	}else{
		REP(i, 1, transmit_data_size){
			UART_Byte_Transmit(transmit_data[i-1]);
		}
	}

}

void UART_Initial(){
    GLOBAL_INT(ENABLE);
    ES = 1; //Serial interrupt
    //----------------------//
    TMOD |= 0x20; //Set timer 2 mode 8bit
    TH1 = 0xFD; //load value for baud rate = 9600
    TL1 = 0xFD; //load value for baud rate = 9600
    SCON = 0x50;
    TR1 = 1; // start timer 1
    //----------------------//
	LCD_INITIAL();
}

void UART_Received() interrupt 4 {
	char hehe[10];
	if(RI == 1){
		char temp_char;
		temp_char = SBUF;
		rcv_size = (rcv_size + 1)%9;
		data_rcv[rcv_size-1] = temp_char;
		hehe[0] = '0' + (rcv_size)%10;
		UART_Byte_Transmit('<');
		UART_Byte_Transmit('-');
		UART_Byte_Transmit(' ');
		UART_Byte_Transmit(temp_char);
		UART_Byte_Transmit('\n');
		UART_Byte_Transmit('\r');
		LCD_Simple_Set_Text_2(hehe, 1, 0, 0);
		LCD_Simple_Set_Text_1(data_rcv, rcv_size, 1, 0);
		RI = 0;
	}else{
		LCD_Set_Text("Call for transfering", 20, 1, 0, 0, 0);
		//TI = 0;
	}
}