// refs: https://www.electronicwings.com/8051/8051-uart
// refs: https://embetronicx.com/tutorials/microcontrollers/8051/8051-uart-tutorial-serial-communication/

#ifndef _UART_H_
#define _UART_H_
#include "Base_Lib.h"
#include "String_Ultils.h"

/*
Valid msg from Bluetooth module:
	$DEV0
	$DEV1
	$DEV2
	$DEV3
	$DEV4
	$DEV5
	$ON__
	$OFF_
	$NONE
	$CLS_
	$EXIT
*/

#define _max_buffer_size 5 
#define _not_lower_case(x) (!('a' <= (x) && (x) <= 'z'))
#define _not_upper_case(x) (!('A' <= (x) && (x) <= 'Z'))
#define _not_digit(x) (!('0' <= (x) && (x) <= '9'))
#define _not_dollar_sign(x) (!((x)!='$'))
#define _not_underscore(x) (!((x)=='_'))
#define _is_new_line(x) ((x)=='\n')
#define _is_carriage_return(x) ((x)=='\r')
#define _bounded_y(x, y) ((x)%(y))

uint8 	rcv_size = 0;
char   	rcv_data[_max_buffer_size]; // DEV* or ON or OFF or NONE12

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
}

uint8 UART_Read_Data(char uart_data[], uint8 read_size){
	if(read_size == 0 || rcv_size == 0) return 0; // for read failed
	read_size = min_val(read_size, rcv_size);
	_string_copy(uart_data, rcv_data, read_size, 0);
	//reset buffer size (aka rcv_data)
	rcv_size = 0;
	return 1; // for read successful
}

void UART_Received() interrupt 4 {
	char temp_char;
	if(RI == 1){
		temp_char = SBUF;
		if( 
			_not_upper_case(temp_char)
			&& _not_digit(temp_char)
			&& _not_underscore(temp_char)
			&& _not_lower_case(temp_char)
		){
				// Reset buffer (aka rcv_data)
				RI = 0;
				return;
		}
		rcv_size = _bounded_y(rcv_size + 1, _max_buffer_size+1);
		rcv_data[rcv_size-1] = temp_char;
		RI = 0; 
	}else{
		// ...
	}
}

#endif