
//TYPE: LCD
//SIZE: 16x2
//REFs: https://circuitdigest.com/article/16x2-lcd-display-module-pinout-datasheet
#define LCD_ON_CURSOR_ON  0x0F  //LCD ON, cursor ON
#define CLEAR_SCREEN  0x01  //Clear display screen
#define RETURN_HOME  0x02  //Return home
#define LEFT_SHIFT_CURSOR  0x04  //Decrement cursor (shift cursor to left)
#define RIGHT_SHIFT_CURSOR  0x06  //Increment cursor (shift cursor to right)
#define LEFT_SHIFT_DISPLAY  0x05  //Shift display right
#define RIGHT_SHIFT_DISPLAY  0x07  //Shift display left
#define DISPLAY_ON_CURSOR_BLINKING  0x0E  //Display ON, cursor blinking
#define CMD8  0x80  //Force cursor to beginning of first line
#define CMD9  0xC0  //Force cursor to beginning of second line
#define LINEx2_MAT5x7 0x38  //2 lines and 5×7 matrix
#define CMD11 0x83  //Cursor line 1 position 3
#define CMD12 0x3C  //Activate second line
#define LCD_OFF_CURSOR_OFF 0x08  //Display OFF, cursor OFF
#define CMD14 0xC1  //Jump to second line, position 1
#define LCD_ON_CURSOR_OFF 0x0C  //Display ON, cursor OFF
#define CMD16 0xC1  //Jump to second line, position 1
#define CMD17 0xC2  //Jump to second line, position 2

