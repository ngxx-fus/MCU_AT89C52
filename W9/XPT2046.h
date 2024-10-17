#ifndef	  __XPT2046_H_
#define   __XPT2046_H_

#include "Base_Lib.h"
#include<intrins.h>

sbit DOUT = P3^7;
sbit CLK  = P3^6;
sbit DIN  = P3^4;
sbit CS   = P3^5;

uint32 Read_AD_Data(uint8 cmd);
uint32 SPI_Read(void);
void SPI_Write(uint8 dat);

void SPI_Start(void)
{
	CLK = 0;
	CS  = 1;
	DIN = 1;
	CLK = 1;
	CS  = 0;		
}

void SPI_Write(uint8 dat)
{
	uint8 i;
	CLK = 0;
	for(i=0; i<8; i++)
	{
		DIN = dat >> 7; 
		dat <<= 1;
		CLK = 0;	

		CLK = 1;

	}
}

uint32 SPI_Read(void)
{
	uint32 i, dat=0;
	CLK = 0;
	for(i=0; i<12; i++)	
	{
		dat <<= 1;

		CLK = 1;
		CLK = 0;

		dat |= DOUT;

	}
	return dat;	
}

uint32 Read_AD_Data(uint8 cmd)
{
	uint8 i;
	uint32 AD_Value;
	CLK = 0;
	CS  = 0;
	SPI_Write(cmd);
	for(i=6; i>0; i--); 
	CLK = 1;	
	CLK = 0;
	AD_Value=SPI_Read();
	CS = 1;
	return AD_Value;	
}



#endif





