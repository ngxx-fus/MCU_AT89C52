#include "main.h"


void main(){
	
	INITIAL();
	SET_YELLOW_TIMER(5);
	SET_RED_GREEN_TIMER(15);
	SET_DISPLAY_PERIOD(12);

	while ( 0x1 ){
		if( AUTO_MANUAL() ){
			SET_STATE(RED);
			SET_TIMER(0);
			SET_STATE(GREEN);
			SET_TIMER(1);
		}else{
			STOP_COUNT();
			SET_STATE(RED_GREEN());
		}
	}
	
	
}