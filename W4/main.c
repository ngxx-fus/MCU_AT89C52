#include "main.h"

void main(){
	INITIAL();
	DISPLAY();
	while(1){
		DISPLAY();
		INCREASE_SECOND();
		DELAY(1300);
	}
}