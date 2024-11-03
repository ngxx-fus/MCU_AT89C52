#include "main.h"
#include "IR_Reading.h"

int main(){
    main_intial();
    while(true){
        read_system_time();
        if(time_equal_cmp(system_time, time_on, 0x6))
            dev2_syst_ctl = HIGH;  
        if(time_equal_cmp(system_time, time_off, 0x6))
            dev2_syst_ctl = LOW; 
        if(have_daylight()){
            dev1_syst_ctl = LOW;   
        }else{
            dev1_syst_ctl = HIGH;   
        }
        update_dev_state();
        code_proc(read_extracted_frame());
        Disp8leds7seg(10);
    }
    return 0;
}