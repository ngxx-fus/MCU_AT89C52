#include "main.h"


void main(){
	
	INITIAL();
	SET_YELLOW_TIMER(5);
	SET_RED_GREEN_TIMER(17);
	SET_DISPLAY_PERIOD(12);

	while ( 0x1 ){
		if(!AUTO_MANUAL() ){
			SET_STATE(RED);
			SET_TIMER(0);
			SET_STATE(GREEN);
			SET_TIMER(1);
		}else{
			STOP_COUNT();
            while( !AUTO_MANUAL() == 0x0 ){
                SET_STATE(RED_GREEN());
                GND0 = 1; GND1 = 1; GND2 = 0; SET_LED(DIGIT(0));
                DELAY(SINGLE_LED_DISPLAY_T);
                GND0 = 1; GND1 = 1; GND2 = 1; SET_LED(DIGIT(1));
			    DELAY(SINGLE_LED_DISPLAY_T);
            }
		}
	}
	
	
}