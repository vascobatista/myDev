#include <Arduino.h>
#include <BUTAOVB.h>

/*
programa simples para testar o codigo do butão

Versão VB butao 1.0  teste com butão port 3

*/

// Define os butoes de acordo com esquema teste
// butoes INPUT_PULLUP => config do BOATAOVB = LOW
#define  _B1 2
#define  _B2 3
#define  _B3 4


//define o butão1 da breadboar de testes com INPUT_PULLUP como LOW
BUTAOVB mybutao(_B1,LOW);





void setup() {

 // onfigura o butão1 B1 breadboar de testes com INPUT_PULLUP
 pinMode(_B1, INPUT_PULLUP);

 //config led TST - pin 13
 pinMode(13,OUTPUT);
 digitalWrite(13,HIGH);
 delay(200);
 digitalWrite(13,LOW);


  // inicializa porta serie
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  int B_pressed;

  // verifica o esta do b
  B_pressed = mybutao.check_butao();

  switch (B_pressed) {
    case BOATAOVB_CONTINUO: Serial.println("continuo");
    break;
    case BOATAOVB_PRESSED_1: Serial.println("1");
    break;
    case BOATAOVB_PRESSED_2: Serial.println("2");
    break;
    case BOATAOVB_PRESSED_3: Serial.println("3");
    break;
    case BOATAOVB_PRESSED_4: Serial.println("4");
    break;
  }
  /*
  #define BOATAOVB_CONTINUO 999 // pressionado continuamente
  #define BOATAOVB_NOTPRESSED 0
  #define BOATAOVB_PRESSED_1 1
  #define BOATAOVB_PRESSED_2 2
  #define BOATAOVB_PRESSED_3 3
  #define BOATAOVB_PRESSED_4 4
  #define BOATAOVB_PRESSED_5 5


  */

}
