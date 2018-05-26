/*

Teste do display LCD1602

Teste do display com o BUTAOVB



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
#define  _B3 2

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
    lcd.setCursor(2, 0);
    lcd.print("** BUTAO **");



}

void loop() {

// verifica os butões
int B1_pressed;
int B3_pressed;

// verifica o esta do b
B1_pressed = mybutao1.check_butao();
B3_pressed = mybutao3.check_butao();

// Butao 1 precionado
lcd.setCursor(14, 1);
switch (B1_pressed) {
  case BOATAOVB_ERRO: lcd.print("1Erro");
  break;
  case BOATAOVB_CONTINUO: lcd.print("1C");
  break;
  case BOATAOVB_PRESSED_1: lcd.print("11");
  break;
  case BOATAOVB_PRESSED_2: lcd.print("12");
  break;
  case BOATAOVB_PRESSED_3: lcd.print("13");
  break;
}


// Butao 3 precionado
lcd.setCursor(0, 1);
switch (B3_pressed) {
  case BOATAOVB_ERRO: lcd.print("3Erro");
  break;
  case BOATAOVB_CONTINUO: lcd.print("3C");
  break;
  case BOATAOVB_PRESSED_1: lcd.print("31");
  break;
  case BOATAOVB_PRESSED_2: lcd.print("32");
  break;
  case BOATAOVB_PRESSED_3: lcd.print("33");
  break;
}
//   TESTE LCD BASICO
// set the cursor to column 0, line 1
// (note: line 1 is the second row, since counting begins with 0):
//lcd.setCursor(0, 1);
// print the number of seconds since reset:
//lcd.print(millis() / 1000);
}
