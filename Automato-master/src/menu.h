#ifndef MENUS_H
#define MENUS_H
/* carregaafd.h
* VERSÃO: 1.3
* ULTIMO EDITOR: Lucas
* DATA: 04/06/2019
* HORA: 22:12
* LISTA DE ARQUIVOS UTILIZADOS NA BIBLIOTECA:
* automato.cpp
* carregaarquivo.cpp
* processa.cpp
*/


 
#define TECLAPARACIMA1 119
#define TECLAPARACIMA2 87
#define TECLAPARABAIXO1 115
#define TECLAPARABAIXO2 83
#define ENTER 10
#define SAIRDOPROGRAMA 0
#define MENUPRINCIPAL 1
#define CARREGAAFE 3
#define CARREGAAFD 2
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <iostream>
#include "automato.h"
#include "carregaarquivo.h"
#include "processa.h"
#include "conversao.h"


using namespace std;

/* Função que pega um digito sem a necessidade do enter (versao 2)
 * -> Sem entrada
 * <- Retorna o caractere pego
 * pre_condição: nenhuma
 * Pos_condição:nenhuma
 */
char getchChar();

/* Função auxiliar que ajuda a movimentação no menu
 * ->b = Ponteiro para variavel de controle,a = valor digitado, primeiro = primeiro elemento do menu e ultimo = ultimo elemento do menu
 * <- Retorna 1 caso o caractere seja enter e 0 caso não seja
 * Pré-condição: Nenhuma
 * Pós-condição: A posição correta do menu é retornada
 */
bool movmentMenu(int teclaPressionada, int *posicaoDoMenu, int primeiro, int ultimo);

/* Função que mostra na tela o menu base
 * -> Variavel de controle do menu
 * <- Sem retorno
 * Pré-condição: Nenhuma
 * Pós-condição: O menu base é executado
 */
void mainMenu(int *var);

/* Função que executa os menus
 * -> Automato que sera feito a leitura
 * <- Sem retorno
 * Pré-condição: Automato nulo
 * Pós-condição: O menu é executado
 */
void deciderMenu();
#endif
