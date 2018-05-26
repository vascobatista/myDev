#include <Arduino.h>
#include <BUTAOVB.h>

/*
programa simples para testar o codigo do butão

Versão VB butao 1.0  teste com butão port 3
Versão VB butao 1.1  teste com butão port 2 LOW pullup, port 4 HIGH


*/

// Define os butoes de acordo com esquema teste
// butoes INPUT_PULLUP => config do BOATAOVB = LOW
#define  _B1 2
#define  _B2 3
#define  _B3 4


//define o butão1 da breadboar de testes com INPUT_PULLUP como LOW
BUTAOVB mybutao(_B1,LOW);
// teste butao 3
BUTAOVB mybutao3(_B3,LOW);





void setup() {

 // onfigura o butão1 B1 breadboar de testes com INPUT_PULLUP
 pinMode(_B1, INPUT_PULLUP);
 pinMode(_B3, INPUT_PULLUP);

 //config led TST - pin 13
 pinMode(13,OUTPUT);
 digitalWrite(13,HIGH);
 delay(200);
 digitalWrite(13,LOW);


  // inicializa porta serie
  Serial.begin(9600);
  Serial.println("Tete ButaoVB ...");
}

void loop() {
  // put your main code here, to run repeatedly:

  int B_pressed;
  int B3_pressed;

  // verifica o esta do b
  B_pressed = mybutao.check_butao();
  B3_pressed = mybutao3.check_butao();

// debug tempo entre tests
//delay(2000);

  switch (B_pressed) {
    case BOATAOVB_ERRO: Serial.println("1Erro");
    break;
    case BOATAOVB_CONTINUO: Serial.println("1c");
    break;
    case BOATAOVB_PRESSED_1: Serial.println("11");
    break;
    case BOATAOVB_PRESSED_2: Serial.println("12");
    break;
    case BOATAOVB_PRESSED_3: Serial.println("13");
    break;
    case BOATAOVB_PRESSED_4: Serial.println("14");
    break;
    case BOATAOVB_PRESSED_5: Serial.println("15");
    break;
    case BOATAOVB_PRESSED_6: Serial.println("16");
    break;
    case BOATAOVB_PRESSED_7: Serial.println("17");
    break;
    case BOATAOVB_PRESSED_8: Serial.println("18");
    break;

  }


  B3_pressed = mybutao3.check_butao();

// debug tempo entre tests
//delay(2000);

  switch (B3_pressed) {
    case BOATAOVB_ERRO: Serial.println("3Erro");
    break;
    case BOATAOVB_CONTINUO: Serial.println("3c");
    break;
    case BOATAOVB_PRESSED_1: Serial.println("31");
    break;
    case BOATAOVB_PRESSED_2: Serial.println("32");
    break;
    case BOATAOVB_PRESSED_3: Serial.println("33");
    break;
    case BOATAOVB_PRESSED_4: Serial.println("34");
    break;
    case BOATAOVB_PRESSED_5: Serial.println("35");
    break;
    case BOATAOVB_PRESSED_6: Serial.println("36");
    break;
  }
}
