/*
codigo para a gestão do butao
*/

#include "butaovb.h"

BUTAOVB::BUTAOVB(int PIN, int press_status) {

// construtor, inicia liza o butaovb
_butao_pin = PIN;
pinMode(_butao_pin, INPUT);
//define o estado do butaõ pressionado
_butao_stat=press_status;

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
  int butao_input;
  // parte principal da verificação do butaovb
  butao_input = digitalRead(_butao_pin);


return 0;

}
