#include "main.h"
#include "LCD_1602.h"

int main(void){
    Main_Initial();
    while(0x1){
        Fetch_System_Control();
        Update_Device_State();
        Mode_Change();
        Mode_Process();
        delay_ms(1000);
    }
    return 0;
}