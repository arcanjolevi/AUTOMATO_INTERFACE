#ifndef CONVERSAO_H
#define CONVERSAO_H
#include "automato.h"
#include "auxiliarvetor.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;
/* conversao.h 
* VERSÃO: 1.0
* ULTIMO EDITOR: Levi
* DATA: 05/06/2019
* HORA: 19:50
* LISTA DE ARQUIVOS UTILIZADOS NA BIBLIOTECA:
*	"auxiliarvetor.h"
*  <string>
* <iostream>
* <vector>
*/


/* Converte um AFE em AFD
	 * Entrada: Ponteiro para automato AFE
	 * Retorno:  Ponteiro para Automato
	 * Pré-condição: Endereço válido
	 * Pós-condição: nenhuma
	*/
Automato * convertAFEtoAFD(Automato * AFE);


/* Verifica se é um novo estado
	 * Entrada: Vetor com todos os estado Efecfamentos, novo estado(vetor de Efechamentos)
	 * Retorno:  true or false
	 * Pré-condição: nenhuma
	 * Pós-condição: nenhuma
	*/
bool verifyNewState(vector<vector<int>> v, vector<int> estado);


/*  Forma um estado recebendo parte de seus paramentros
	 * Entrada: inteiro, automato, simbolos lidos pelo automato, suas transições, e vetor de Efechamentos
	 * Retorno:  endereçoo de um estado estanciado
	 * Pré-condição: nenhuma
	 * Pós-condição: nenhuma
	*/
Estado *  buildState(int estado, Automato * AFE, vector<char> simbolosLidos, vector<Transicao*> transicoes, vector<int> Fechamentos);

/*  Verifica se o novo estado é final
	 * Entrada: Automato, E Fechamentos que compoem o novo estado
	 * Retorno:  true or false
	 * Pré-condição: Nenhuma
	 * Pós-condição: nenhuma
	*/
bool isFinal(Automato * AFE, vector<int> Fechamentos);

/*  Forma uma transição recebendo parte de seus paramentros
	 * Entrada:  vetor de todos os estados, estado atual, caracter lido, Estados pra onde ela vai
	 * Retorno:  transição estanciada
	 * Pré-condição: nenhuma
	 * Pós-condição: nenhuma
	*/
Transicao * buildTransition(vector<vector<int>> Estados, int estadoAtual, char symbol, vector<int> estadoSeguinte);

/*  Retorna o estado e quivalente em um vetor de estados formados por e Fechamentos
	 * Entrada: vetor de estados de E fechamentos, estado de E fechamentos
	 * Retorno:  inteiro que representa estado
	 * Pré-condição: nenhuma
	 * Pós-condição: nenhuma
	*/
int getStateEquivalet(vector<vector<int>> v, vector<int> u);

/*  Verifica se um estado pertence a um conjunto de estados Efechamentos
	 * Entrada: conjunto de estados Efecamentos, estado Efechamentos
	 * Retorno:  true or false
	 * Pré-condição: nenhuma
	 * Pós-condição: nenhuma
	*/
bool verifyNewState(vector<vector<int>> v, vector<int> estado);


/*  imprime novos estados Efechamentos
	 * Entrada: vetor de estados Efechamentos
	 * Retorno:  nenhum
	 * Pré-condição: nenhuma
	 * Pós-condição: nenhuma
	*/
void imprimeNovos(vector<vector<int>> v);

/*  calcula o caminho possivel, lendo o simbolo e indo para os estados do vetor
	 * Entrada: simbolo, vetor inteiros, automato, vetor de Efechamentos estados
	 * Retorno:  vetor de int que representa o caminho
	 * Pré-condição: nenhuma
	 * Pós-condição: nenhuma
	*/
vector<int> calculateWaySymbol(char symbol, vector<int> state, Automato * AFD, vector<int> Fechamentos[]);

/*  Soma dois conjuntos de Efechamentos
	 * Entrada: conjunto de fechamentos(vetor de int), conjunto de fechamentos(vetor de int)
	 * Retorno:  resultado da soma do dois vetores
	 * Pré-condição: nenhuma
	 * Pós-condição: nenhuma
	*/
vector<int> somaFechamentos(vector<int> Conjuntos, vector<int> Fechamentos[]);


/*  calcula possiveis caminhos lendo o simbolo e saindo desse estado
	 * Entrada: simbolo, inteiro do estado, automato
	 * Retorno:  vetor de int(representa o caminho possivel)
	 * Pré-condição: nenhuma
	 * Pós-condição: nenhuma
	*/
vector<int> waySymbol(char symbol, int state, Automato * AFD);

/*  Calcula o Efechamento
	 * Entrada: inteiro do estado, automato
	 * Retorno:  vetor de inteiros
	 * Pré-condição: nenhuma
	 * Pós-condição: nenhuma
	*/
vector<int> calculateClosure(int estado, Automato * AFE);

/*  Função auxiliar para calculo do Efechamento de um estado
	 * Entrada: estado, automato, estados ja percorridos
	 * Retorno:  vetor de int(Efechamento)
	 * Pré-condição: nenhuma
	 * Pós-condição: nenhuma
	*/
vector<int> epsilonClosure( Estado state, Automato * AFD, vector<int> Percorridos);
/*  Mostra o Efechamento atual
	 * Entrada: vetor de int(Efechamentos), tamanho do vetor
	 * Retorno:  nenhum
	 * Pré-condição: nenhuma
	 * Pós-condição: nenhuma
	*/
void showClosureGroup(vector<int> v[], int n);

#endif // CONVERSAO_H
