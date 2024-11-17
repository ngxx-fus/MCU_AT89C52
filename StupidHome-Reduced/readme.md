## Hi. From ngxx.fus !
### Preamble
To easier to understand "StupidHome", i have made reduced version. In this version, i have specified:
+   Default time: 21:15:45 (HH:MM:SS)
+   DEV-1: Controlled by bluetooth with two commands (are ON1/OFF1); Initial-value: OFF
+   DEV-2: Controlled by bluetooth with two commands (are ON2/OFF2); Initial-value: OFF
+   DEV-3: Controlled by **timer** (is set ON at 21:15:45); Initial-value: OFF 
+   DEV-4: Controlled by **timer** (is set OFF at 21:16:00); Initial-value: ON
+   DEV-5: Controlled by remote (press ON_OFF button to toggle DEV-5's state); Initial-value: ON
+   PLAY_PAUSE button on remote: TURN-ON **ALL** devices or TURN-OFF **ALL** devices.
+   "REPORT" commands (bluetooth) witll receive a report of all devices state (ON/OFF) and sys_time.

### Libs
| Lib | Functions | Note |
| :--: | :-- | :-- |
| Utilities.h | This lib is renamed from Base_Lib.h. It provides macros (REP, REV, ...), typedefs (uint8, uint32, ...), set-up functions (eINT0_CTL(), ...), delay functions (delay_us(), delay_ms(), ...), so on... | |
| Time.h | The defination of TIME data-type. <br>time_equal_cmp() : compare to TIME object. | |
| String_Ultils.h |  _string_equal_compare() : compare two string <br>_string_find_pattern() : find a pattern in given string | |
| XPT2046.h | Includes some functions (SPI_Initial(), SPI_Write(), SPI_Read(), Read_AD_Data()) to communicate with XPT2046. | Read ADC value from  Light - dependent resistor. |
| ThreeWiresProtocol.h | Includes some functions (single_byte_write(), single_byte_read(), ThreeWiresProtocol_Initial()) to comunicate with realtime IC (DS1302) using 3wires protocol. | |
| DS1302.h | Provides read/write method base on TIME datatype (defined in Time.h) (DS1302_Read_Time(), DS1302_Write_Time()) and Initial function (DS1302_Initial). | DS1302.h has included ThreeWiresProtocol.h |
| LCD_1602.h | Provides display function in LCD 16x2.<br>LCD_Simple_Set_Text_1() : Simple to set TEXT which to be displayed in LCD WITHOUT CLEAR previous screen<br> LCD_Simple_Set_Text_2() : Simple to set TEXT which to be displayed in LCD WITH CLEAR previous screen. | The lib also contains the other function to other task (send a byte to be displayed, ...)|
| IR_Reading.h | Read IR's code from REMOTE (include external interrupt 1). <br>read_extracted_frame(): Return a number (uint32) is IR-code from remote, and clear data_frame (return 0 if there is no any new frame).<br>CODE2NUM() : Convert ir-code that is a number to a number. | |
| UART_BLE.h | Communication with smartphone via bluetooth.<br>UART_Bytes_Transmit() : Send a several bytes to smartphone.<br> UART_Received() : Receive one or several bytes from smartphone, then pushback to stack-buffer (size: 8bytes)<br> ble_has_contained() : Find a pattern in bluetooth received data.| If stack-buffer is full, it will be reset automaticly; UART_Received() do not accept '\n', '\r'. |
| main.h | Include all needed libs, and define main-functions. | |
| main.c | Only main-loop. | |

### Connection Diagram

External Bluetooth 5.0 module: Bluetooth 5.0 BLE JDY-24M
| 8051 Pro Kit | Ble 5.0 BLE JDY-24M | Note |
| :--: | :--: | :--: |
| P3.1 (TX) | RXD   | |
| P3.0 (RX) | TXD   | |
| 5V   | VCC | |
| 5V   | EN  | LOW: AT mode - for config ble module<br> HIGH: send data |
| GND  | GND | |
<br>
![alt text](https://github.com/ngxx-fus/MCU_AT89C52/blob/main/StupidHome-Reduced/image.png)