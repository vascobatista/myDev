#include <Arduino.h>
#include <BUTAOVB.h>

/*
programa simples para testar o codigo do butão

*/


BUTAOVB mybutao(3,HIGH);

void setup() {
  // put your setup code here, to run once:

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
