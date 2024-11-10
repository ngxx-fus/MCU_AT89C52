// refs: https://www.electronicwings.com/8051/8051-uart
// refs: https://embetronicx.com/tutorials/microcontrollers/8051/8051-uart-tutorial-serial-communication/

#ifndef _BLUETOOTH_UART_H_
#define _BLUETOOTH_UART_H_
#include "LCD_1602.h"
#include "Utilities.h"
#include "String_Ultils.h"

/*
Valid msg from Bluetooth module:
	$DEV1$$$
	$DEV2$$$
	$DEV3$$$
	$DEV4$$$
	$DEV5$$$
	$ON$$$$$
	$OFF$$$$
	$NONE$$$
	$EXIT$$$
	$SETUP$$
	$PREV$$$
	$NEXT$$$
	$YES$$$$
	$NO$$$$$
	$HOUR**$
	$MIN**$$
	$SEC**$$
	$YEAR**$
	$MON**$$
	$DATE**$
*/

#define _max_buffer_size 8 
#define _bounded_y(x, y) ((x)%(y))

uint8 ble_rcv_size;
char  ble_rcv_data[_max_buffer_size];

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
	if(transmit_data_size == 0){
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

// uint8 UART_Read_Data(char uart_data[], char read_size){
// 	if(read_size == 0 || ble_rcv_size == 0) return false; // for read failed
// 	read_size = min_val(read_size, ble_rcv_size);
// 	_string_copy(uart_data, ble_rcv_data, read_size, 0);
// 	//reset buffer size (aka ble_rcv_data)
// 	ble_rcv_size = 0;
// 	return true; // for read successful
// }

void UART_Initial(){
    GLOBAL_INT(ENABLE);
    ES = 1; //Serial interrupt
    TMOD |= 0x20; //Set timer 2 mode 8bit
    TH1 = 0xFD; //load value for baud rate = 9600
    TL1 = 0xFD; //load value for baud rate = 9600
    SCON = 0x50;
    TR1 = 1; // start timer 1
}

void Bluetooth_Initial(){
	ble_rcv_size = 0;
	LCD_Simple_Set_Text_2("SEND <OK> FROM", 14, 0, 0);
	LCD_Simple_Set_Text_1("YOUR SMARTPHONE!", 16, 1, 0);
	do{		
		delay_ms(1000);
		if(ble_rcv_size >= 2){
			_string_to_lower_case(ble_rcv_data, ble_rcv_size);
			if(_string_find_pattern("ok", 2, ble_rcv_data, ble_rcv_size, 0)<ble_rcv_size){
				ble_rcv_size=0;// clear received data
				break;
			}
		}
	}while(1);
}

void Bluetooth_UART_Initial(){
	UART_Initial();
	Bluetooth_Initial();
}



void UART_Received() interrupt 4 {
	char temp_char;
	if(RI == 1){
		temp_char = SBUF;
		if( 
			_is_carriage_return(temp_char)
			|| _is_new_line(temp_char)
		){
				RI = 0;
				return;
		}
		ble_rcv_size = _bounded_y(ble_rcv_size, _max_buffer_size)+1;
		ble_rcv_data[ble_rcv_size-1] = temp_char;
		RI = 0; 
	}else{
		// TI = 0;
	}
}

#endif