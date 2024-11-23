#include <REGX52.h>

#define RED 0x21
#define YELLOW 0x12
#define GREEN 0xC
#define MANUAL 0x0
#define AUTO 0x1
#define LED_OFF 0xa

sbit G0  = P3^6;
sbit G1  = P3^7;
sbit AutoIndicator = P3^5;

int Manual_Auto = AUTO;
int RED_GREEN_SET = RED;
int STATE	= RED;
int COUNT_0;
int COUNT_1;

const int DIGIT[] = {0X3F, 0X06, 0X5B, 0X4F, 0X66, 0X6D, 0X7D, 0X07, 0X4F, 0X0};

#define LED P1
// Note: Active-Hight

#define TRAFFIC_LIGHT P2
//            | traffic light 1 | traffic light 0 |   
// P2: [x][x]      [G][Y][R]         [G][Y][R]
// Note: Active-Hight

void delay(unsigned int t){
	unsigned int i;
	for(i = 0; i < 12*t; i++);
}

void INITIAL(){
	// Config <interrupt enable> for INT0 and INT1
	// NOTE:
	// 		INT0 - Manual/Auto
	// 		INT1 - RED/GREEN
	EX0 = 0x1; //8'b0000_0101
	EX1 = 0x1; //8'b0000_0101
	// Config <interrupt triger> for INT0 and INT1
	// NOTE: triggered at falling edge
	IT0 = 0x1;
	IT1 = 0x1;
	// Enable all interrupts according to individual enable bits
	EA  = 0x1;
	// Turn on AutoIndicator
	AutoIndicator = 1;
}

void eINT0_ACTION(void) interrupt 0 {
	Manual_Auto = (Manual_Auto==MANUAL)?(AUTO):(MANUAL);
	if(Manual_Auto == AUTO)
		AutoIndicator = 0x1;
	else
		AutoIndicator = 0x0;
}

void eINT1_ACTION(void) interrupt 2 {
	RED_GREEN_SET = (RED_GREEN_SET==RED)?(GREEN):(RED);
}

void SET_LED(unsigned int CODE){
	//CODE = 0x0 : turn off
	LED = DIGIT[CODE];
}

void DISPLAY(unsigned int second){
	unsigned int i;
	unsigned int k;
	unsigned int delay_t = 10;
	for(k = 0; k < second; k++){
		for(i = 0; i < 1200/(4*delay_t); i++){
			G0 = 0; G1 = 0; SET_LED((COUNT_0/10)%10);
			delay(delay_t);
			G0 = 0; G1 = 1; SET_LED((COUNT_1/10)%10);
			delay(delay_t);

			G0 = 1; G1 = 0; SET_LED(COUNT_0%10);
			delay(delay_t);
			G0 = 1; G1 = 1; SET_LED(COUNT_1);
			delay(delay_t);
		}
		if(COUNT_0 > 0){
			COUNT_0 = COUNT_0 - 1;
		}
		if(COUNT_1 > 0){
			COUNT_1 = COUNT_1 - 1;
		}
	}
}

void SET(int CODE){
	switch (CODE){
		// 0: GREEN -> YELLOW -> RED
		// 1: RED   -> RED    -> GREEN
		case RED:
			if (STATE == RED) return;
			if (STATE != YELLOW){ // -> GREEN
					TRAFFIC_LIGHT = 0xA;// -> Change to YELLOW
					COUNT_0 = 2;
					DISPLAY(2);// wait in 2 secconds
			}
			TRAFFIC_LIGHT = RED; //-> change to RED
			STATE = RED;
			break;
		
		// 0: YELLOW
		// 1: YELLOW
		case YELLOW:
			SET_LED(10);
			TRAFFIC_LIGHT = 0x12;
			STATE = YELLOW;
			COUNT_0 = 0;
			COUNT_1 = 0;
			break;
		
		// 0: RED   -> RED    -> GREEN
		// 1: GREEN -> YELLOW -> RED
		case GREEN:
			if (STATE == GREEN) return;
			if (STATE != YELLOW){// is RED
					TRAFFIC_LIGHT = 0x11;//00 010 001
					COUNT_1 = 2;
					DISPLAY(2);// wait in 2 secconds for Yellow
			}
			TRAFFIC_LIGHT = GREEN;
			STATE = GREEN;
			break;
	}
}
