#include "SnakeC.h"
#include "Base_Lib.h"
#include "IR_Reading.h"
#include<intrins.h>


sbit HC595_SRCLK=P3^6;
sbit HC595_RCLK=P3^5;
sbit HC595_SER=P3^4;

#define ROW	P0 // for ROW :v

void HC595_Send_Byte(uint8 DATA){ // for column
	uint8 a;
	HC595_SRCLK=0; HC595_RCLK=0;
	REP(a,0,7){
		HC595_SER=DATA>>7;DATA<<=1;
		HC595_SRCLK=1;
		_nop_(); _nop_();
		HC595_SRCLK=0;	
	}
	HC595_RCLK=1;
	_nop_(); _nop_();
	HC595_RCLK=0;
}


void print_a_frame(){
    int i, j, k;
    uint8 disp_data;
		REP(k, 0, 100)
				REP(i, 0, 7){
						disp_data = 0;
					  HC595_Send_Byte(0);
						REP(j, 0, 7){
								if(field[i][j]){
										disp_data += (1<<j);
										P0 = ~(1<<i);
										HC595_Send_Byte(1<<j);
								}
						}
						delay_ms(1);
				}
}

int main(){
    uint32 CODE;
    snake_initial();
		IR_Reading_Initial();
    while( !is_dead ){
        print_a_frame();
        CODE = read_extracted_frame();
        switch (CODE){          
        case __5:
            if(is_paused) break;
            direction_change(to_left);
            break;
        case __2:
            if(is_paused) break;
            direction_change(to_right);
            break; 
        case __4:
            if(is_paused) break;
            direction_change(to_down);
            break;
        case __6:
            if(is_paused) break;
            direction_change(to_up);
            break;
        }
        if(is_paused) continue;
        direction_update();
        snake_head_update();
        snake_body_update();
    }
    while(1);
}