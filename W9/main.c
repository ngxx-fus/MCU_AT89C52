#include "main.h"

void main(){
    main_intial();
    change_mode(REMOTE);
    while(0x1){
        ds1302_read_time(&sys_time, 0x7);

        if(new_dataframe()) 
            change_mode(read_extracted_frame());
        
        if((DEV&0x1) && time_equal(sys_time, time_on, 0x6))
            DEV_CTL(0x1);
        
        if((DEV&0x1) && time_equal(sys_time, time_off, 0x6))
            DEV_CTL(0x1);
        
        sys_time_disp(1);
    }
}