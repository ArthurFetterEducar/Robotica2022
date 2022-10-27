#include <LiquidCrystal.h> 
#include <Keypad.h> 

// Pinos LCD
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

#define L1  28
#define L2  26
#define L3  24
#define L4  22

#define C1  30
#define C2  32
#define C3  34
#define C4  36

char keys[TOTAL_LINHAS][TOTAL_COLUNAS] = 
{
  {'1','2','3','A'},  
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[TOTAL_LINHAS] = { L1, L2, L3, L4 };
byte colPins[TOTAL_COLUNAS] = { C1, C2, C3, C4 }; 

Keypad teclado = Keypad( makeKeymap(keys), rowPins, colPins, TOTAL_LINHAS, TOTAL_COLUNAS ); 

String equation = "";
float num1, num2, result;
char op = ' ';
char key;


void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
}


void loop() {
  key = teclado.getKey(); 

  if (key!=NO_KEY) {
    DetectButtons();
    Serial.println(key);
  }
}


void DetectButtons()
{
  equation = equation + key;
  
  switch(key) {
  case '*': 
  {
    lcd.clear();
    lcd.home();
    
    result=num1=num2=0; 
    op = ' ';
    equation = "";

    break;
  }
  case 'A':
  {
    op = 'A';
    lcd.print('+');
    break;
  }
  case 'B':
  {
    op = 'B';
    lcd.print('-');
    break;
  }
  case 'C':
  {
    op = 'C';
    lcd.print('*');
    break;
  }
  case 'D': 
  {
    op = 'D';
    lcd.print('/');
    break;
  }
  case '#':
  {    
    num1 = equation.substring(0, equation.indexOf(op)).toFloat();
    num2 = equation.substring(equation.indexOf(op)+1, equation.indexOf('#')).toFloat();
    
    switch (op) {
    case 'A':
    {
      result = num1 + num2;
      break;
    }
    case 'B':
    {
      result = num1 - num2;
      break;
    }
    case 'C':
    {
      result = num1 * num2;
      break;
    }
    case 'D': 
    {
      result = num1 / num2;
      break;
    }   
    }
    
    lcd.setCursor(0, 0);
    lcd.print(result);

    break;
  }
  default: 
  {
    lcd.print(key);  
  } 
  }
}
