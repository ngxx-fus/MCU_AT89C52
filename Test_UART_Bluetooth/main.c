#include "Base_Lib.h"
#include "UART.h"
#include "LCD16x2.h"
#include "String_Ultils.h"

void main_initial(){
    UART_Initial();
    LCD_Initial();
}

void Hello(){
    LCD_Simple_Set_Text_1("Hello!",5, 0, 0);
    LCD_Simple_Set_Text_1("From NGXXFUS!",13, 1, 0);
    delay_ms(2000);
    LCD_Initial();
    LCD_Simple_Set_Text_1("Hello!",5, 0, 0);
    LCD_Simple_Set_Text_1("From NGXXFUS!",13, 1, 0);
}

int main(void){
    main_initial();
    Hello();
    while(0x1){
        delay_ms(1000);
    };
    return 0;
}