#include "LCD16x2_DATE_TIME.h"

void main(){
	INITIAL();
	SET_HH_MM_SS(23, 59, 55);
	SET_DD_MM_YYYY(3, 2, 2004);
	DISPLAY();
	while(1){
		DISPLAY();
		INCREASE_SECOND();
		DELAY(1300);
	}
}

