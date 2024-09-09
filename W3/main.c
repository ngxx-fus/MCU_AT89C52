#include "main.h"


void main(){
	INITIAL();
	DIRECT_SET(YELLOW);
	SET_LED(10);
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
				SET_LED(10);
				if(RED_GREEN_SET)
					DIRECT_SET(RED);
				else
					DIRECT_SET(GREEN);
			}
	}
}