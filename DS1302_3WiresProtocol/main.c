#include "Calendar_OnKit.h"

#include "Calendar_OnKit.h"
#include "LED7Seg_OnKit.h"
#include "ThreeWiresProtocol.h"

void main(void){
	calendar_initial();
	while(0x1){
		calendar_disp();
	}
}