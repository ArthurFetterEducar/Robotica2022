#include <LiquidCrystal.h> 
#include <Keypad.h> 
#include <TimerThree.h>

// Definições para LCD
#define RW  8 // GND
#define RS  53
#define E   52
#define D4  10
#define D5  11
#define D6  12
#define D7  13

LiquidCrystal lcd(RS, E, D4, D5, D6, D7); // Gerar objeto Liquid Crystal para controle do lcd

// Pinos teclado matricial 
#define TOTAL_LINHAS  4
#define TOTAL_COLUNAS 4

#define L1  31
#define L2  33
#define L3  35
#define L4  37

#define C1  29
#define C2  27
#define C3  25
#define C4  23

char keys[TOTAL_LINHAS][TOTAL_COLUNAS] = // Matriz de valores do teclado
{
  {'1','2','3','A'},  
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[TOTAL_LINHAS] = { L1, L2, L3, L4 };    // Linhas do teclado
byte colPins[TOTAL_COLUNAS] = { C1, C2, C3, C4 };   // Colunas do teclado

Keypad teclado = Keypad( makeKeymap(keys), rowPins, colPins, TOTAL_LINHAS, TOTAL_COLUNAS ); // Inicialização do teclado

#define POT_PIN     A8
#define OUTPUT_PIN  2

char key;
String cmd = "";

float pot_v;
int duty_cycle;
long freq = 10000;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);  

  pinMode(POT_PIN, INPUT);

  Timer3.initialize((1.0/freq)*1000000);
  Serial.println((1.0/freq)*1000000);
}


void loop() {
  key = teclado.getKey();
  Serial.println(key);
  
  if (key != NO_KEY) {
    cmd = cmd + key;
    
    switch (key) {
    case 'A':
    {
      freq = cmd.substring(0, cmd.indexOf('A')).toFloat();
      Serial.println(freq);
      break;
    }
    case 'B': 
    {
      freq = cmd.substring(0, cmd.indexOf('A')).toFloat() * 100;
      Serial.println(freq);
      break;
    }
    case 'C': 
    {
      freq = cmd.substring(0, cmd.indexOf('A')).toFloat() * 1000;
      Serial.println(freq);
      break;
    }
    case 'D': 
    {
      freq = cmd.substring(0, cmd.indexOf('A')).toFloat() * 10000;
      Serial.println(freq);
      break;
    }
    case '*': 
    {
      cmd = "";

      lcd.setCursor(0, 0);
      lcd.print("0");

      break;
    }
    case '#':
    {
      Timer3.setPeriod((1.0/freq)*1000000);

      cmd = "";

      lcd.setCursor(0, 0);
      lcd.print(" ");

      break;
    }
    }
  }

  pot_v = analogRead(POT_PIN);
  duty_cycle = map(pot_v, 8, 1024, 0, 100);

  lcd.setCursor(1, 0);
  lcd.print("Freq:");
  lcd.print(freq);
  lcd.print("Hz");

  lcd.setCursor(0, 1);
  lcd.print("Duty:");
  lcd.print(duty_cycle);
  lcd.print("%");

  lcd.setCursor(10, 1);
  lcd.print("V:");
  lcd.print(((float)duty_cycle/100)*5);

  Timer3.pwm(OUTPUT_PIN, pot_v); 

  delay(100); 
  lcd.clear();
}
