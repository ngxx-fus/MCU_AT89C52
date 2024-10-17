#include "main.h"

int main(){
    main_intial();
    change_mode(REMOTE);
    uint32 C;
    while(0x1){
        ds1302_read_time(&sys_time, 0x7);

        //if(new_dataframe()) 
        // change_mode(read_extracted_frame());
        C = read_extracted_frame();
        LED[7]= DIGIT_CODE[ (C) & 0xF];
        LED[6]= DIGIT_CODE[ (C>>4) & 0xF];
        LED[5]= DIGIT_CODE[ (C>>8) & 0xF];
        LED[4]= DIGIT_CODE[ (C>>12) & 0xF];
        LED[3]= DIGIT_CODE[ (C>>16) & 0xF];
        LED[2]= DIGIT_CODE[ (C>>20) & 0xF];
        LED[1]= DIGIT_CODE[ (C>>24) & 0xF];
        LED[0]= DIGIT_CODE[ (C>>28) & 0xF];
        Disp8leds7seg(1000);
        // sys_time_disp(10);
    }
return 0;
}