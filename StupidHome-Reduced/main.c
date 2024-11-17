#include "main.h"

int main(void){
    Main_Initial();
    while(0x1){
        Fetch_System_Time();
        Send_Report_To_Smartphone(0);
        Update_Device_State();
    }
    return 0;
}