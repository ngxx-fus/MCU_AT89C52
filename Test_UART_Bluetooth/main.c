#include "main.h"
#include "LCD_1602.h"

int main(void){
    Main_Initial();
    LCD_Simple_Set_Text_2("Stand by mode", 0, 0, 0);
    while(0x1){
        Mode_Change();
        Mode_Process();
        delay_ms(1000);
    }
    return 0;
}