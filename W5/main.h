// #ifdef _MAIN_H_
// #define _MAIN_H_

//---------- Include -----------
#include <REGX52.h>
#include <stdio.h>


//---------- Macros -----------
#define elif else if
#define DECREASE_ONE(VAR) VAR = (VAR>0?(VAR-1):VAR)

#define RED 0x1
#define YELLOW 0x2
#define GREEN 0x4
#define LED_OFF 0xA
#define MANUAL 0x0;
#define AUTO 0x1;

#define R_DIGIT 0xB
#define Y_DIGIT 0xC
#define G_DIGIT 0xD

//RETURN CODE DESCRIPTION:
//  0x1  : RED
//  0x2  : YELLOW
//  0x4  : GREEN

//---------- Type defines -----
typedef unsigned int UINT;

//---------- Delay ------------
static void DELAY_DISP(UINT mili_sec) {
  UINT i;
  for (i = 0; i < 3 * mili_sec; i++)
    ;
}
static void DELAY(UINT mili_sec) {
  UINT i;
  for (i = 0; i < 12 * mili_sec; i++)
    ;
}

//---------- Traffic Light Ports
// sbit RED0 = P1 ^ 0;
// sbit YELLOW0 = P1 ^ 1;
// sbit GREEN0 = P1 ^ 2;

// sbit RED1 = P2 ^ 5;
// sbit YELLOW1 = P2 ^ 6;
// sbit GREEN1 = P2 ^ 7;
UINT RED0;
UINT YELLOW0;
UINT GREEN0;
UINT RED1;
UINT YELLOW1;
UINT GREEN1;
//---------- Timer Ports --------
sbit GND0 = P2 ^ 2;
sbit GND1 = P2 ^ 3;
sbit GND2 = P2 ^ 4;

#define LED P0
// P2: [x][G][F][E][D][C][B][A]
// Note: Active-Hight | MSB -> LSB | Common Anode

//---------- Timer Ports --------
sbit M_A = P3^3;
sbit R_G = P3^2;
//---------- State VARs
UINT STATE_0 = RED;
UINT STATE_1 = RED;
// The state of traffic light (to prevent set the same state again)
UINT COUNT_0;
// Count for the main traffic light
UINT COUNT_1;
// Count for the order traffic light
UINT SINGLE_LED_DISPLAY_T = 1;
// The time use show a single 7-seg LED
UINT RED_T = 0;
UINT GREEN_T = 0;
UINT YELLOW_T = 0;
// The time (in seccond) for the YELLOW state while changes state
// from GREEN->RED.

//---------- CA LED CODE
const UINT DIGIT_CODE[] = {0X3F, 0X06, 0X5B, 0X4F, 0X66, 0X6D,
                             0X7D, 0X07, 0X7F, 0XEF, 0X0, 0X1,
							 0x40, 0x8};
// 7-seg LED CODE (Common Anode)

UINT AUTO_MANUAL() {
	UINT _M_A = M_A;
  if (_M_A)
    return AUTO;
  return MANUAL;
}

UINT RED_GREEN() { return (R_G) ? (RED) : (GREEN); }

void SET_LED(UINT D) {
  // CODE = 10 : turn off LED.
  LED = DIGIT_CODE[D];
}

void SET_DISPLAY_PERIOD(UINT T) {
  // NOTE: Unit mili-second
  SINGLE_LED_DISPLAY_T = T;
}

void STOP_COUNT() {
  COUNT_0 = 0;
  COUNT_1 = 0;
  SET_LED(LED_OFF);
}


void SET_YELLOW_TIMER(UINT _YELLOW_T){
	YELLOW_T = _YELLOW_T;
}


void SET_RED_GREEN_TIMER(UINT _RED_T){
	// RED_T = GREEN_T + YELLOW_T
	// NOTE: Delay in second
	COUNT_0 = RED_T = _RED_T;
	COUNT_1 = GREEN_T = RED_T - YELLOW_T;
}

void SET_TIMER(UINT PREVIOUS) {
  // PREVIOUS DESCRIPTION
  // PREVIOUS = 0 :
  //	Means Traffic Light 0 is currently RED and count
  // down to ZERO to change to GREEN. At the same time
  // Traffic Light 1 is counting down to ZERO to change
  // to YELLOW then it will change to RED.
  // PREVIOUS = 1 :
  //	The other side, Traffic Light 1 is currently GREEN,
  // and will be changed to YELLOW, then RED.
  if (PREVIOUS == 0) {
    COUNT_0 = RED_T;
    COUNT_1 = GREEN_T;
  } else {
    COUNT_0 = GREEN_T;
    COUNT_1 = RED_T;
  }
}

UINT DIGIT(UINT POS){
	if( POS == 0){
		if(RED0 == 1 && YELLOW0 == 0 && GREEN0 == 0) return R_DIGIT;
		if(RED0 == 0 && YELLOW0 == 1 && GREEN0 == 0) return Y_DIGIT;
		if(RED0 == 0 && YELLOW0 == 0 && GREEN0 == 1) return G_DIGIT;
	}else{
		if(RED1 == 1 && YELLOW1 == 0 && GREEN1 == 0) return R_DIGIT;
		if(RED1 == 0 && YELLOW1 == 1 && GREEN1 == 0) return Y_DIGIT;
		if(RED1 == 0 && YELLOW1 == 0 && GREEN1 == 1) return G_DIGIT;
	}
	return 0xA;
}

void DISPLAY_LED(){
	/*This function only runs ONE SECOND*/
	UINT i = 0;
	for(i = 0; i < 2800/(6*SINGLE_LED_DISPLAY_T); i++){
			GND0 = 1; GND1 = 0; GND2 = 0;
			if(COUNT_0 != 0) SET_LED((COUNT_0/10)%10);
			else SET_LED(LED_OFF);
			DELAY_DISP(SINGLE_LED_DISPLAY_T);

			GND0 = 1; GND1 = 0; GND2 = 1; 
			if(COUNT_1 != 0)SET_LED((COUNT_1/10)%10);
			else SET_LED(LED_OFF);
			DELAY_DISP(SINGLE_LED_DISPLAY_T);
			

      GND0 = 1; GND1 = 1; GND2 = 0; SET_LED(DIGIT(0));
			DELAY_DISP(SINGLE_LED_DISPLAY_T);
		
			GND0 = 0; GND1 = 0; GND2 = 0;
			if(COUNT_0 != 0) SET_LED(COUNT_0%10);
			else SET_LED(LED_OFF);
			DELAY_DISP(SINGLE_LED_DISPLAY_T);
		
			GND0 = 0; GND1 = 0; GND2 = 1;
			if(COUNT_1 != 0) SET_LED(COUNT_1%10);
			else SET_LED(LED_OFF);
			DELAY_DISP(SINGLE_LED_DISPLAY_T);

			GND0 = 1; GND1 = 1; GND2 = 1; SET_LED(DIGIT(1));
			DELAY_DISP(SINGLE_LED_DISPLAY_T);
	}
}

void SET_TRAFFIC_LIGHT(UINT POS, UINT CODE) {
  // CODE DESCRIPTION:
  // RED    : 0x1
  // YELLOW : 0x2
  // GREEN  : 0x4
  // POSITION DESCRIPTION:
  //    0   : Traffic light 0
  //    1   : Traffic light 1
  // POS = 0 --> Traffic light 0 --> 3 bits control locates at 3 last bit.
  //>	MSB [x][x][x][x] [x][G][Y][R] LSB
  // POS = 1 --> Traffic light 1 --> 3 bits control loacates from 5th bit down
  // to 3rd bit. >   MSB [x][x][G][Y] [R][x][x][x] LSB
  if (POS)
    CODE = (CODE << 3)&0x38;
  // NOTE: MASK = 0011_1000 in BIN equiv 0x38 in HEX
  switch (CODE) {
	case 0x01: //0000_0001
		RED0 = 1, YELLOW0 = 0, GREEN0 = 0, STATE_0 = RED;
		break;
	case 0x02: //0000_0010
		RED0 = 0, YELLOW0 = 1, GREEN0 = 0, STATE_0 = YELLOW;
		break;
	case 0x04: //0000_0100
		RED0 = 0, YELLOW0 = 0, GREEN0 = 1, STATE_0 = GREEN;
		break;
	case 0x08: //0000_1000
		RED1 = 1, YELLOW1 = 0, GREEN1 = 0, STATE_1 = RED;
		break;
	case 0x10: //0001_0000
		RED1 = 0, YELLOW1 = 1, GREEN1 = 0, STATE_1 = YELLOW;
		break;
	case 0x20: //0010_0000
		RED1 = 0, YELLOW1 = 0, GREEN1 = 1, STATE_1 = GREEN;
		break;
  }
}

UINT GET_STATE(UINT POS){
	return (POS)?(STATE_1):(STATE_0);
}

void SET_STATE(UINT CODE) {
  if (CODE == RED) {
    if (GET_STATE(0) == YELLOW) {
      SET_TRAFFIC_LIGHT(0, RED);
      SET_TRAFFIC_LIGHT(1, GREEN);
    }
    elif (GET_STATE(0) == GREEN) {
      while (COUNT_0) {
        DISPLAY_LED();
        DECREASE_ONE(COUNT_0);
        DECREASE_ONE(COUNT_1);
      }
      SET_TRAFFIC_LIGHT(0, YELLOW);
      SET_TRAFFIC_LIGHT(1, RED);
      COUNT_0 = YELLOW_T;
      while (COUNT_0) {
        DISPLAY_LED();
        DECREASE_ONE(COUNT_0);
        DECREASE_ONE(COUNT_1);
      }
      SET_TRAFFIC_LIGHT(0, RED);
      SET_TRAFFIC_LIGHT(1, GREEN);
    }
  }
  if (CODE == GREEN) {
    if (GET_STATE(0) == YELLOW) {
      SET_TRAFFIC_LIGHT(0, GREEN);
      SET_TRAFFIC_LIGHT(1, RED);
    }
    elif (GET_STATE(0) == RED) {
      while (COUNT_1) {
        DISPLAY_LED();
        DECREASE_ONE(COUNT_0);
        DECREASE_ONE(COUNT_1);
      }
      COUNT_1 = YELLOW_T;
      SET_TRAFFIC_LIGHT(0, RED);
      SET_TRAFFIC_LIGHT(1, YELLOW);
      while (COUNT_1) {
        DISPLAY_LED();
        DECREASE_ONE(COUNT_0);
        DECREASE_ONE(COUNT_1);
      }
      SET_TRAFFIC_LIGHT(0, GREEN);
      SET_TRAFFIC_LIGHT(1, RED);
    }
  }
}

void INITIAL(){
	/*Set initial state*/
	SET_TRAFFIC_LIGHT(0, YELLOW);
	SET_TRAFFIC_LIGHT(1, YELLOW);
	COUNT_0 = 0x0;
	COUNT_1 = 0x0;
	LED = DIGIT_CODE[LED_OFF];
	GND0 = GND1 = GND2 = 0;
}

// #endif