#ifndef _L293_SHIELD_PINOUT_H
#define _L293_SHIELD_PINOUT_H

/*---------------------------------------------|Pins For Driving The Motors|---------------------------------------------*/
#define EN_1        7     // Enables pins 8 and 9
#define EN_2        10    // Enables pins 11 and 6
#define EN_3        4     // Enables pins 3 and 5
#define EN_4        2     // Enables pins A4 and A5

#define F_R_MOTOR0  8     // Drives motor backwords
#define F_R_MOTOR1  9     // Drives motor fowards
#define B_R_MOTOR0  6     // Drives motor backwards
#define B_R_MOTOR1  11    // Drives motor fowards

#define B_L_MOTOR1  5     // Drives motor fowards
#define B_L_MOTOR0  3     // Drives motor backwards 
#define F_L_MOTOR1  A5    // Drives motor fowards
#define F_L_MOTOR0  A4    // Drives motor backwards

/*---------------------------------------------|Pins For Controlling The LEDs|---------------------------------------------*/
#define LED_YELLOW  A15     //Turns yellow LED On
#define LED_RED     A14     //Turns red LED On
#define LED_GREEN   A13     //Turns green LED On
#define LED_WHITE   A12     //Turns white LED On

/*---------------------------------------------|Pins For Controlling The LCD|---------------------------------------------*/
#define LCD_RS      53;     // controls where in the LCD's memory you're writing data to.
//#define LCD_RW      GND;    // selects reading mode or writing mode (Is kept at 0V, read only mode, for the L293 shield)
#define LCD_EN      49;     // enables writing to the registers 
#define LCD_D0      47;     // D0 through D7 is the written / read data from the register 
#define LCD_D1      45;
#define LCD_D2      43;
#define LCD_D3      41;
#define LCD_D4      39;
#define LCD_D5      37;
#define LCD_D6      35;
#define LCD_D7      33;

/*---------------------------------------------|Pins For Controlling The Robot Through The HT12 Controller|---------------------------------------------*/
#define HT_PIN_D8   14
#define HT_PIN_D9   15
#define HT_PIN_D10  16
#define HT_PIN_D11  17

#endif 