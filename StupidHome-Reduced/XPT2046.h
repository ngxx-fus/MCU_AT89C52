#ifndef	  __XPT2046_H_
#define   __XPT2046_H_

#include "Utilities.h"
#include<intrins.h>

sbit D_OUT = P3^7;
sbit D_IN  = P3^4;
sbit S_CLK  = P3^6;
sbit C_S   = P3^5;


void SPI_Initial(void)
{
	S_CLK = 0;
	C_S  = 1;
	D_IN = 1;
	S_CLK = 1;
	C_S  = 0;		
}

void SPI_Write(uint8 __data)
{
	uint8 i;
	S_CLK = 0;
	for(i=0; i<8; i++)
	{
		D_IN = __data >> 7; 
		__data <<= 1;
		S_CLK = 0;	
		delay_us(5);
		S_CLK = 1;

	}
}

uint32 SPI_Read(void)
{
	uint32 i, __data=0;
	S_CLK = 0;
	for(i=0; i<12; i++)	
	{
		__data <<= 1;

		S_CLK = 1;
		S_CLK = 0;

		__data |= D_OUT;

	}
	return __data;	
}

uint32 Read_AD_Data(uint8 __command)
{
	uint8 i;
	uint32 AD_Value;
	S_CLK = 0;
	C_S  = 0;
	SPI_Write(__command);
	for(i=6; i>0; i--); 
	S_CLK = 1;	
	S_CLK = 0;
	AD_Value=SPI_Read();
	C_S = 1;
	return AD_Value;	
}

#endif





