/*
  Arthur Fetter Dartora Machado
  ELO 13B

  Due: 
  - Terminar funções de comunicação para o robô
  - Separar as funções externas em arquivos específicos
  - Aprimorar funções para o uso do LCD
*/

#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

#include "L293_Shield_Pinout.h"
#include "Movimentacao.h"

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
