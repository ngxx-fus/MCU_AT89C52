#include "main.h"


void main(){
    FOR(NUM, 0, 10){
        UINT DON_VI = NUM%10;
        UINT CHUC = (NUM/10)%10;
        UINT i = 0;
        FOR(i, 1, 60){
            digit_disp(8, CHUC);
            delay(10);
            digit_disp(7, DON_VI);
            delay(10);
        }
    }
}