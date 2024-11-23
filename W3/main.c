#include "main.h"


void main(){
	INITIAL();
	delay(1000);
	while(1){
			if(Manual_Auto == AUTO){
				SET(RED);
				COUNT_0 = 7;
				COUNT_1 = 5;
				DISPLAY(5);
				
				SET(GREEN);
				COUNT_0 = 5;
				COUNT_1 = 7;
				DISPLAY(5);
			}else{
				LED = 0;
				if(RED_GREEN_SET == RED)
					SET(RED);
				else
					SET(GREEN);
				delay(100);
			}
	}
}