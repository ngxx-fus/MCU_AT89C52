#include "main.h"

int main(void){
    Main_Initial();
    while(0x1){
        Fetch_System_Time();
        Send_Report_To_Smartphone(0);
        Fetch_User_Control();
        Fetch_System_Trigger();
        Update_Device_State();
        Mode_Change();
        Mode_Process();
        // delay_ms(300);
    }
    return 0;
}