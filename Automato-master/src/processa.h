#ifndef PROCESSA_H
#define PROCESSA_H

/* processa.h 
* VERSÃO: 1.2
* ULTIMO EDITOR: Caio
* DATA: 05/06/2019
* HORA: 13:05
* LISTA DE ARQUIVOS UTILIZADOS NA BIBLIOTECA:
*	- transicao.h
* - estado.h
* - automato.h
* - menu.h
*/

#include <iostream>
#include <string.h>
#include <QString>
#include "automato.h"
#include "estado.h"
#include "transicao.h"
#include "menu.h"

using namespace std;

/* Processa uma palavra dado um autômato
* Entrada: Automato
* Retorno: String contendo todo o processamento da palavra
* Pré-condição: O autômato deve existir e estar completo
* Pós-condição: A palavra é processada
*/
string process(char *palavra, Automato *a);

#endif
