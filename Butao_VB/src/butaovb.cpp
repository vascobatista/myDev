/*
codigo para a gestão do butao
*/

#include "butaovb.h"

BUTAOVB::BUTAOVB(int PIN, int press_status) {

  // construtor, inicializa o butaovb, constante Objeto
  __butao_pin = PIN;
  pinMode(__butao_pin, INPUT);
  //define o estado do butaõ pressionado
  __butao_press=press_status;

  // inicializa contador que define o numero de vezes pressionado
  _cont = 0;
  // inicializa estado do ultima consulta
  _last_butao_status = 0;
  // inicializa tempo em milisegundos da ultima alteraç\ao
  _last_change_milis = 0;


}

void BUTAOVB::reset_butao() {
  // inicializa contador que define o numero de vezes pressionado
  _cont = 0;
  // inicializa estado do ultima consulta
  _last_butao_status = 0;
  // inicializa tempo em milisegundos da ultima alteraç\ao
  _last_change_milis = 0;




}


/*
#define BOATAOVB_CONTINUO 999 // pressionado continuamente
#define BOATAOVB_NOTPRESSED 0
#define BOATAOVB_PRESSED_1 1
#define BOATAOVB_PRESSED_2 2
#define BOATAOVB_PRESSED_3 3
#define BOATAOVB_PRESSED_4 4
#define BOATAOVB_PRESSED_5 5

_cont = 0;
// inicializa estado do ultima consulta
_last_butao_status = 0;
// inicializa tempo em milisegundos da ultima alteraç\ao
_last_change_milis = 0;

*/
int BUTAOVB::check_butao() {
  int butao_input; // verifica estado do butão
  long now_milis;  // tempo agora milis, milisegundos
  long delta_milis; // diferença de tempo em milisegundos
  int output; //variavel de output

  // parte principal da verificação do butaovb
  butao_input = digitalRead(__butao_pin);
  now_milis = millis();
  delta_milis = now_milis - _last_change_milis;

// verifica estados de error
// butao não primido e contador em BOATAOVB_CONTINUO
// butão pressionado e contado 0
if ( ((_last_butao_status != __butao_press) & (_cont == BOATAOVB_CONTINUO)) |
((_last_butao_status == __butao_press) & (_cont == 0)) ){
  return BOATAOVB_ERRO;
}


// primeira condição estado anterior do butao
if (_last_butao_status == __butao_press) {
  // 1 - ultimo estado do butão era pressionado
  // 2 condição estado atual do butão
  if (butao_input == __butao_press) {
  // 2 - butão esta pressionado
  //
    if (_cont == BOATAOVB_CONTINUO ) {
      // se butão estava carregado continuamente output = BOATAOVB_CONTINUO
      output = BOATAOVB_CONTINUO;
    } else
      if (delta_milis > BUTAO_T2) {
        // se delta > T2 output = cont = BOATAOVB_CONTINUO
        output = BOATAOVB_CONTINUO;
        _cont = BOATAOVB_CONTINUO;
      } else {
      // se delta < T2 contador não é alterado e output 0
        output = BOATAOVB_NOTPRESSED;
      }

    return output;
  } else {
    // 2 - butão NÂO esta pressionado
    // _last_butao_status é NÂO __butao_press
    _last_butao_status = !__butao_press;
    //reset do time
    _last_change_milis = now_milis;
    if (_cont == BOATAOVB_CONTINUO ) {
      // se butãi estava carregado continuamente _cont=0 e output = 0
      _cont = 0;
      output = BOATAOVB_NOTPRESSED;
    } else
      if (delta_milis > BUTAO_T1) {
        // se delta > T1 output = cont e _cont = 0
        output = _cont;
        _cont = 0;
      } else {
      // se delta < T1 contador não é alterado e output 0
        output = BOATAOVB_NOTPRESSED;
      }
    }
    return output;
  }


 else {
  // 1- ultimo estado do butão era NÃO pressionado
  // 2 condiç\ao estado atual do butão
  if (butao_input == __butao_press) {
    // 2 - butão esta pressionado
    // incrementa o contador, mantem o _last_butao_status
    _cont +=1;
    // reset do tempo
    _last_change_milis = now_milis;
    return BOATAOVB_NOTPRESSED; // 0

    } else {
      // 2 - butão NÂO esta pressionado
      // não altera o _last_butao_status e _cont, output = 0 excepto delta_milis > T2
      if (delta_milis > BUTAO_T2) {
        // retorna o contado, reset ao contador e ao tempo
        output = _cont;
        _cont = 0;
        _last_change_milis = now_milis;
        return output;
      } else {
        return BOATAOVB_NOTPRESSED; // 0
      }




    }
}


}
