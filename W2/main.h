#include <stdio.h>
#include <REGX52.h>
#define elif else if

typedef unsigned int UINT32;
#define DECREASE_ONE(VAR) VAR = (VAR>0?(VAR-1):VAR)
// Decreas VAR if VAR is greater than ZERO, else DO NOTHING!
#define GET_STATE(POS) ((POS>0)?((TRAFFIC_LIGHT & 0x38)>>0x3)*1U:(TRAFFIC_LIGHT & 0x7)*1U)
//POSITION DESCRIPTION:
//   0   : Traffic light 0
//   1   : Traffic light 1
//RETURN CODE DESCRIPTION:
//  0x1  : RED
//  0x2  : YELLOW
//  0x4  : GREEN

#define RED 0x1
#define YELLOW 0x2
#define GREEN 0x4
#define LED_OFF 0xA
#define MANUAL 0x0;
#define AUTO 0x1;

sbit M_A = P3^2;
//<INPUT> M_A: Manual/Auto mode
sbit R_G = P3^3;
//<INPUT> R_G: RED / GREEN (Only for *manual mode*)

sbit G0  = P2^2;
sbit G1  = P2^3;
sbit G2  = P2^4;

// Demultiplexer 2->4
// G0 G1   | GND3 GND2 GND1 GND0
//  0  0   |    H    H	  H    L
//  0  1   |    H    H	  L    H
//  1  0   |    H    L	  H    H
//  1  1   |    L    H	  H    H
// Note: Active-Low | MSB -> LSB

UINT32 STATE = RED;
// The state of traffic light (to prevent set the same state again)
UINT32 COUNT_0;
// Count for the main traffic light
UINT32 COUNT_1;
// Count for the order traffic light
UINT32 SINGLE_LED_DISPLAY_T = 50;
// The time use show a single 7-seg LED
UINT32 RED_T = 0;
UINT32 GREEN_T = 0;
UINT32 YELLOW_T = 3;
// The time (in seccond) for the YELLOW state while changes state 
// from GREEN->RED.

const UINT32 DIGIT_CODE[] = {0X3F, 0X06, 0X5B, 0X4F, 0X66, 0X6D, 0X7D, 
							0X07, 0X7F, 0XEF, 0X0};
// 7-seg LED CODE (Common Anode)

#define LED P0

// P2: [x][G][F][E][D][C][B][A]
// Note: Active-Hight | MSB -> LSB | Common Anode

#define TRAFFIC_LIGHT P2
//            | traffic light 1 | traffic light 0 |   
// P2: [x][x]      [G][Y][R]         [G][Y][R]
// Note: Active-Hight | MSB -> LSB | x : "don't care!"

void INITIAL(){
	/*Set initial state*/
	TRAFFIC_LIGHT = 0x12;
	COUNT_0 = 0x0;
	COUNT_1 = 0x0;
	LED = DIGIT_CODE[LED_OFF];
	G0 = G1 = 0;
}

UINT32 AUTO_MANUAL(){
	if (M_A) return AUTO;
	return MANUAL;
}

UINT32 RED_GREEN(){
	return (R_G)?(RED):(GREEN);
}

void DELAY(UINT32 t){
	/*Delay in mili-second*/
	UINT32 i;
	for(i = 0; i < 12*t; i++);
}

void SET_LED(UINT32 D){
	//CODE = 10 : turn off LED.
	LED = DIGIT_CODE[D];
}

void SET_YELLOW_TIMER(UINT32 _YELLOW_T){
	YELLOW_T = _YELLOW_T;
}

void SET_RED_GREEN_TIMER(UINT32 _RED_T){
	// RED_T = GREEN_T + YELLOW_T
	// NOTE: Delay in second
	COUNT_0 = RED_T = _RED_T;
	COUNT_1 = GREEN_T = RED_T - YELLOW_T;
}

void SET_DISPLAY_PERIOD(UINT32 T){
	//NOTE: Unit mili-second
	SINGLE_LED_DISPLAY_T = T;
}

void STOP_COUNT(){
	COUNT_0 = 0;
	COUNT_1 = 0;
	SET_LED(LED_OFF);
}

void SET_TIMER(UINT32 REV){
	//REV DESCRIPTION
	//REV = 0 : 
	//	Means Traffic Light 0 is currently RED and count
	//down to ZERO to change to GREEN. At the same time
	//Traffic Light 1 is counting down to ZERO to change 
	//to YELLOW then it will change to RED.
	//REV = 1 :
	//	The other side, Traffic Light 1 is currently GREEN,
	//and will be changed to YELLOW, then RED. 
	if(REV == 0){
		COUNT_0 = RED_T;
		COUNT_1 = GREEN_T;
	}else{
		COUNT_0 = GREEN_T;
		COUNT_1 = RED_T;
	}

}

void DISPLAY_LED(){
	/*This function only runs ONE SECOND*/
	UINT32 i = 0;
	for(i = 0; i < 1400/(4*SINGLE_LED_DISPLAY_T); i++){
			G0 = 1; G1 = 0; G2 = 0;
			if(COUNT_0 != 0) SET_LED((COUNT_0/10)%10);
			else SET_LED(LED_OFF);
			DELAY(SINGLE_LED_DISPLAY_T);

			G0 = 1; G1 = 0; G2 = 1; 
			if(COUNT_1 != 0)SET_LED((COUNT_1/10)%10);
			else SET_LED(LED_OFF);
			DELAY(SINGLE_LED_DISPLAY_T);
		
			G0 = 0; G1 = 0; G2 = 0;
			if(COUNT_0 != 0) SET_LED(COUNT_0%10);
			else SET_LED(LED_OFF);
			DELAY(SINGLE_LED_DISPLAY_T);
		
			G0 = 0; G1 = 0; G2 = 1;
			if(COUNT_1 != 0) SET_LED(COUNT_1%10);
			else SET_LED(LED_OFF);
			DELAY(SINGLE_LED_DISPLAY_T);
	}
}

void SET_TRAFFIC_LIGHT(UINT32 POS, UINT32 CODE){ 
	//CODE DESCRIPTION:
	//RED    : 0x1
	//YELLOW : 0x2
	//GREEN  : 0x4
	//POSITION DESCRIPTION:
	//   0   : Traffic light 0
	//   1   : Traffic light 1
	//POS = 0 --> Traffic light 0 --> 3 bits control locates at 3 last bit.
	//>	MSB [x][x][x][x] [x][G][Y][R] LSB
	//POS = 1 --> Traffic light 1 --> 3 bits control loacates from 5th bit down to 3rd bit.
	//> MSB [x][x][G][Y] [R][x][x][x] LSB

	UINT32 TL = TRAFFIC_LIGHT;
	UINT32 CURRENT_STATE = GET_STATE(POS) & 0x7;
	CODE = CODE & 0x7;
	// Standardizing CODE
	
	if( (CODE & CURRENT_STATE) == 0 ){
		//New state is the same with prev state --> abort!
		if(POS == 0)
			TRAFFIC_LIGHT = (TL & 0xF8) | CODE;
		else
			TRAFFIC_LIGHT = (TL & 0xC7) | (CODE << 0x3);
	}
}

void SET_STATE(UINT32 CODE){
	if(CODE == RED){
		if( GET_STATE(0) == YELLOW ){
			SET_TRAFFIC_LIGHT(0, RED);
			SET_TRAFFIC_LIGHT(1, GREEN);
		}
		elif( GET_STATE(0) == GREEN){
			while(COUNT_0){
				DISPLAY_LED();
				DECREASE_ONE(COUNT_0);
				DECREASE_ONE(COUNT_1);
			}
			SET_TRAFFIC_LIGHT(0, YELLOW);
			SET_TRAFFIC_LIGHT(1, RED);
			COUNT_0 = YELLOW_T;
			while(COUNT_0){
				DISPLAY_LED();
				DECREASE_ONE(COUNT_0);
				DECREASE_ONE(COUNT_1);
			}
			SET_TRAFFIC_LIGHT(0, RED);
			SET_TRAFFIC_LIGHT(1, GREEN);
		}
	}
	if(CODE == GREEN){
		if(GET_STATE(0) == YELLOW){
			SET_TRAFFIC_LIGHT(0, GREEN);
			SET_TRAFFIC_LIGHT(1, RED);
		}elif (GET_STATE(0) == RED){
			while(COUNT_1){
				DISPLAY_LED();
				DECREASE_ONE(COUNT_0);
				DECREASE_ONE(COUNT_1);
			}
			COUNT_1 = YELLOW_T;
			SET_TRAFFIC_LIGHT(0, RED);
			SET_TRAFFIC_LIGHT(1, YELLOW);
			while(COUNT_1){
				DISPLAY_LED();
				DECREASE_ONE(COUNT_0);
				DECREASE_ONE(COUNT_1);
			}
			SET_TRAFFIC_LIGHT(0, GREEN);
			SET_TRAFFIC_LIGHT(1, RED);
		}
	}
}