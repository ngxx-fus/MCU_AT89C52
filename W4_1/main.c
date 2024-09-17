#include "DS1307.h"
#include "LCD16x2_DATE_TIME.h"

void main(){
	LCD_INITIAL();
	//SET_HH_MM_SS(23, 59, 55);
	//SET_DD_MM_YYYY(3, 2, 2004);
	DS1307_INIT();
	DISPLAY();
	while(1){
		GET_TIME_DATE();
		DISPLAY();
		MS_DELAY(100);
	}
}

