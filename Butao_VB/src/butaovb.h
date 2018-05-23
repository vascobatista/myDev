/*
 Butao VB

Projeto para definir objeto butao que valida se butao foi carregado
e quantas vezes

A consulta oa estado do butao indica se foi pressionada 1 ou mais vezes
clicks repetidos ou se está pressionado em continnui

      |---->     |t1>  |--t2-->   |--t2-->
    __  t2     __    __           _________
___|  |_______|  |__|  |_________|         |_________

   1 click -- depois de pressionado esta mais que t2 sem ser pressionado
   2 clicks -- depois do 1 click 2 click antes de t1
   n click  -- igual mas mais vezes

   continuo - pressionado mais que t2

NOTA: configuração do input PIN feita fora do package


Versao Batista 0.1 10-3-2018   Vasco Batista  - Draft
Vasco Batista 1.0 19-5-2018 - V 1.0  Butao VB a funcionar




 */

#ifndef __BUTAOVB
#define __BUTAOVB

#include <Arduino.h>

// Tempo T1 - tempo de espera para contar novo click
#define BUTAO_T1 50
// Tempo T2 - tempo para para contagem e dar resultado
#define BUTAO_T2 100

// Define tipo de açoes do butaovb
#define BOATAOVB_CONTINUO 999 // pressionado continuamente
#define BOATAOVB_NOTPRESSED 0
#define BOATAOVB_PRESSED_1 1
#define BOATAOVB_PRESSED_2 2
#define BOATAOVB_PRESSED_3 3
#define BOATAOVB_PRESSED_4 4
#define BOATAOVB_PRESSED_5 5
// esrado inconsistente
#define BOATAOVB_ERRO -1

class BUTAOVB {
public:
  // construtor, define o PIN e se pressionado é HIGH ou LOW
    BUTAOVB(int PIN, int press_status);
    // inicializa butao
     void reset_butao();
    // Verifica butao
    //
    // podemos ter o resultado:
    //
    //  0 - não foi pressionado
    //  1 - pressinado 1 vez
    //  2 - pressinado 2 vezes
    //  3 - pressinado 3 vezes
    //  999 - pressionado continuamente
     int check_butao();




private:
    // variaveis do butap
    //define o pin do butao, constante no Objeto
    int __butao_pin;

    //define o estado do butaõ pressionado, constante no Objeto
    int __butao_press;

    // contador que define o numero de vezes pressionado
    int _cont;

    // estado do ultima consulta
    int _last_butao_status;
    // tempo em milisegundos da ultima alteraç\ao
    long _last_change_milis;

};


#endif
