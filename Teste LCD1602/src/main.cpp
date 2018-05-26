/*

Teste do display LCD1602



*/
#include <Arduino.h>
#include <butaovb.h>
// include the library code:
#include <LiquidCrystal.h>


/* Configuração da testes
B1=11, B2=10 , B3 =1
- LCD1602
Pins ( rs = 3, en = 4, d4 = 5, d5 = 6, d6 = 7, d7 = 8;

*/

#define  _B1 11
#define  _B2 10
#define  _B3 1

// inicializa os portos do LCD1602
const int rs = 3, en = 4, d4 = 5, d5 = 6, d6 = 7, d7 = 8;
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//inicializa os butões
//define o butão1 da breadboar de testes com INPUT_PULLUP como LOW
BUTAOVB mybutao1(_B1,LOW);
// teste butao 3
BUTAOVB mybutao3(_B3,LOW);

void setup() {

  // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);

  // configura os pins dos butões como INPUT_PULLUP
      pinMode(_B1, INPUT_PULLUP);
      pinMode(_B3, INPUT_PULLUP);
    // Print a message to the LCD.
    lcd.print("Teste Vasco!!");



}

void loop() {

// verifica os butões
int B1_pressed;
int B3_pressed;

// verifica o esta do b
B1_pressed = mybutao1.check_butao();
B3_pressed = mybutao3.check_butao();

  // set the cursor to column 0, line 1
// (note: line 1 is the second row, since counting begins with 0):
lcd.setCursor(0, 1);
// print the number of seconds since reset:
lcd.print(millis() / 1000);
}
