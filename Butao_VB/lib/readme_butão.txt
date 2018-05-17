Objeto para a gestão de butão, sem sleep/waits. em cada ciclo de processamento
verifica o estao do butão UO / DOWN e dependendo do tempo entre
UP / DOWN retona o numero de vezes que foi pressionado.

// podemos ter o resultado:
//
//  0 - não foi pressionado
//  1 - pressinado 1 vez
//  2 - pressinado 2 vezes
//  3 - pressinado 3 vezes
//  999 - pressionado continuamente

Objeto deteta o numero de vezes que o buão foi pressionado.
Numero de vezes depende do 2 valores de tempo T1 e T2ß

// Tempo T1 - tempo de espera para contar novo click
#define BUTAO_T1 50
// Tempo T2 - tempo para para contagem e dar resultado
#define BUTAO_T2 100

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

Versao 0.1 10-3-2018   Vasco Batista  - Draft




 */

#ifndef __BUTAOVB
#define __BUTAOVB

#include <Arduino.h>
