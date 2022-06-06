#include "L293_Shield_Pinout.h"

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
