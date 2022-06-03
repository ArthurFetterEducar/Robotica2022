/*
  Arthur Fetter Dartora Machado
  ELO 13B

  Due: 
  - Terminar funções de comunicação para o robô
  - Separar as funções externas em arquivos específicos
  - Aprimorar funções para o uso do LCD
*/

#include<LiquidCrystal.h>
#include<SoftwareSerial.h>

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
//#define LCD_RW      GND;    // selects reading mode or writing mode
#define LCD_EN      49;     // enables writing to the registers 
#define LCD_D0      47;     // D0 through D7 writes is the written / read data from the register 
#define LCD_D1      45;
#define LCD_D2      43;
#define LCD_D3      41;
#define LCD_D4      39;
#define LCD_D5      37;
#define LCD_D6      35;
#define LCD_D7      33;

/*---------------------------------------------|Pins For Controlling The Robot Through The HT12 Controller|---------------------------------------------*/
//#define HT_PIN_D8   14
//#define HT_PIN_D9   15
//#define HT_PIN_D10  16
//#define HT_PIN_D11  17


void setup() {
  pinMode(EN_1, OUTPUT);
  pinMode(EN_2, OUTPUT);
  pinMode(EN_3, OUTPUT);
  pinMode(EN_4, OUTPUT);
  
  pinMode(F_R_MOTOR1, OUTPUT);
  pinMode(F_R_MOTOR0, OUTPUT);
  pinMode(B_R_MOTOR1, OUTPUT);
  pinMode(B_R_MOTOR1, OUTPUT);
  
  pinMode(B_L_MOTOR0, OUTPUT);
  pinMode(B_L_MOTOR1, OUTPUT);
  pinMode(F_L_MOTOR0, OUTPUT);
  pinMode(F_L_MOTOR1, OUTPUT);

  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_WHITE, OUTPUT);
}


void loop() {
  rideFowards(5000);
  rideBackwards(5000);
  turnLeft(5000);
  turnRight(5000);
}


void fullStop() // Stops all motors
{ 
  digitalWrite(EN_1, LOW); 
  digitalWrite(EN_2, LOW); 
  digitalWrite(EN_3, LOW); 
  digitalWrite(EN_4, LOW); 
}


void rideFowards(int period) // Robot rides fowards 
{ 
  int i = 0;
  
  digitalWrite(LED_RED, HIGH);
  
  digitalWrite(EN_1, HIGH); 
  digitalWrite(EN_2, HIGH); 
  digitalWrite(EN_3, HIGH); 
  digitalWrite(EN_4, HIGH); // Enable all motors

  for(i; i <= period; i++)
  {
    digitalWrite(F_R_MOTOR1, HIGH);
    digitalWrite(F_L_MOTOR1, HIGH);
    digitalWrite(B_R_MOTOR1, HIGH);
    digitalWrite(B_L_MOTOR1, HIGH); // Drive all motors fowards
    
    delay(1);
  }
  
  digitalWrite(LED_RED, LOW);
  
  digitalWrite(EN_1, LOW); 
  digitalWrite(EN_2, LOW); 
  digitalWrite(EN_3, LOW); 
  digitalWrite(EN_4, LOW);
}


void rideBackwards(int period) // Robot rides backwards 
{
  int i = 0;

  digitalWrite(LED_GREEN, HIGH);
  
  digitalWrite(EN_1, HIGH); 
  digitalWrite(EN_2, HIGH); 
  digitalWrite(EN_3, HIGH); 
  digitalWrite(EN_4, HIGH); // Enable all motors

  for(i; i <= period; i++)
  {
    
    digitalWrite(F_R_MOTOR0, HIGH);
    digitalWrite(F_L_MOTOR0, HIGH);
    digitalWrite(B_R_MOTOR0, HIGH);
    digitalWrite(B_L_MOTOR0, HIGH); // Drive all motors backwards
    
    delay(1);
  }
  digitalWrite(LED_GREEN, LOW);
  
  digitalWrite(EN_1, LOW); 
  digitalWrite(EN_2, LOW); 
  digitalWrite(EN_3, LOW); 
  digitalWrite(EN_4, LOW);   
}


void turnLeft(int period) // Robots turns left with its wheels riding fowards
{
  int i = 0;  

  digitalWrite(LED_WHITE, HIGH);

  digitalWrite(EN_1, HIGH); 
  digitalWrite(EN_2, HIGH); 
  digitalWrite(EN_3, HIGH); 
  digitalWrite(EN_4, HIGH); // Enable all motors 

  for(i; i <= period; i++)
  {    
    digitalWrite(F_R_MOTOR0, HIGH);
    digitalWrite(F_L_MOTOR1, HIGH);
    digitalWrite(B_R_MOTOR0, HIGH);
    digitalWrite(B_L_MOTOR1, HIGH);
  
    delay(1);   
  }
  
  digitalWrite(LED_WHITE, LOW);

  digitalWrite(EN_1, LOW); 
  digitalWrite(EN_2, LOW); 
  digitalWrite(EN_3, LOW); 
  digitalWrite(EN_4, LOW);
}


void turnRight(int period)
{
  int i = 0;  

  digitalWrite(LED_YELLOW, HIGH);

  digitalWrite(EN_1, HIGH); 
  digitalWrite(EN_2, HIGH); 
  digitalWrite(EN_3, HIGH); 
  digitalWrite(EN_4, HIGH); // Enable all motors 

  for(i; i <= period; i++)
  {    
    digitalWrite(F_R_MOTOR1, HIGH);
    digitalWrite(F_L_MOTOR0, HIGH);
    digitalWrite(B_R_MOTOR1, HIGH);
    digitalWrite(B_L_MOTOR0, HIGH);
  
    delay(1);   
  }

  digitalWrite(LED_YELLOW, LOW);

  digitalWrite(EN_1, LOW); 
  digitalWrite(EN_2, LOW); 
  digitalWrite(EN_3, LOW); 
  digitalWrite(EN_4, LOW);
}


void controllerRF(int pinD8, int pinD9, int pinD10, int pinD11)
{
    if(pinD8 == 1 
      && pinD9 == 0
      && pinD10 == 0
      && pinD11 == 0){
      rideFowards(50);
    }
    else if(pinD8 == 0 
           && pinD9 == 1
           && pinD10 == 0
           && pinD11 == 0){
      turnLeft(50);
    }
    else if(pinD8 == 0 
           && pinD9 == 0
           && pinD10 == 1
           && pinD11 == 0){
      turnRight(50);
    }
    else if(pinD8 == 0 
           && pinD9 == 0
           && pinD10 == 0
           && pinD11 == 1){
      turnLeft(50);
    }
}


void controllerBluetooth(int pinRX, int pinTX)
{
  
}
