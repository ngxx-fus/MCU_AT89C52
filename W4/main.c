#include "main.h"

void main(){
	INITIAL();
	DISPLAY();
	DELAY(1900);
	while(1){
		DISPLAY();
		INCREASE_SECOND();
		DELAY(900);
	}
}