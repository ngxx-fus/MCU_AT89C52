#include <REGX52.h>

// type define: "usigned int" -> "uint"
typedef unsigned int uint;

#define ABS(num) (((num)<0)?((num) * (-1)):(num))

int V;
sbit GND0 = P2^2;
sbit GND1 = P2^3;
sbit GND2 = P2^4;
#define LED P0

// Định nghĩa hàm DELAY_MILISEC
void delay_milisec(uint t){
    uint i;
    for(i = 0; i < t*12; ++i){
        //nothing
    }
}

uint DonVi[10] = {0X3F, 0X06, 0X5B, 0X4F, 0X66, 0X6D, 0X7D, 0X07, 0X7F, 0X6F};
uint Chuc[3]   = {0XBF, 0X86, 0XDB};
uint Dau[2]    = {0x0, 0x40};


void display(int V){
    uint i;
    uint delta_t = 14;
    for( i = 0; i < 24; ++i){
        GND2 = 0 ;GND1 = 0 ;GND0 = 0 ; // chonj led 7doan thu 1 (vitri 0)
        LED = DonVi[ ABS(V)%10 ];
        delay_milisec(delta_t);

        GND2 = 0 ;GND1 = 0 ;GND0 = 1 ;
        LED = Chuc[ (ABS(V)/10)%10 ];
        delay_milisec(delta_t);
        
        GND2 = 0 ;GND1 = 1 ;GND0 = 0 ;
        LED = Dau[ (V < 0)?(1):(0) ];
        delay_milisec(delta_t);
    }
}