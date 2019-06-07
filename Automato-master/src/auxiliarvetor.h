#ifndef AUXILIARVETOR_H
#define AUXILIARVETOR_H

#include "automato.h"
#include <iostream>
#include <string>
using namespace std;

/* axiliarvetor.h 
* VERSÃO: 1.0
* ULTIMO EDITOR: Levi
* DATA: 05/06/2019
* HORA: 19:00
* LISTA DE ARQUIVOS UTILIZADOS NA BIBLIOTECA:
*	- automato.h
*   - <string>
*   - <iostreaam>
*/

/* Imprime um vetor de inteiros na tela
	 * Entrada: vector de int
	 * Retorno: Nenhum
	 * Pré-condição: Nenhuma
	 * Pós-condição: vetor impresso na tela
	*/
void showVector(vector<int> v);

/* Deleta uma occorerencia do elemento no vetor de inteiros
	 * Entrada: vector de int, inteiro a ser eliminado
	 * Retorno: Vetor alterado (Sem eo elemento)
	 * Pré-condição: Nenhuma
	 * Pós-condição: Elemento é eliminado
	*/
vector<int> deleteElement(vector<int> v, int element);

/* Retorna o maior elemento do Vetor
	 * Entrada: vector de int,
	 * Retorno: Maior elemento
	 * Pré-condição: Nenhuma
	 * Pós-condição: Nenhuma
	*/
int maior_elemento(vector<int> v);

/* Deleta Todas as repetições do vetor
	 * Entrada: vector de int
	 * Retorno: Vetor alterado (Sem Repetições)
	 * Pré-condição: Nenhuma
	 * Pós-condição: Vetor nao tem mais repetições
	*/
vector<int> deleteRepetions(vector<int> v);

/* Ordena um vetor de inteiros
	 * Entrada: vector de int
	 * Retorno: Vetor alterado (ordena)
	 * Pré-condição: Nenhuma
	 * Pós-condição: Vetor é ordenado
	*/
vector<int> order(vector<int> v);

/* Soma dois vetores de inteiros
	 * Entrada: vector de int, vector de int
	 * Retorno: Vetor resultante
	 * Pré-condição: Nenhuma
	 * Pós-condição: nenhuma
	*/
vector<int> plusVector(vector<int> Aclosure, vector<int> Bclosure);


/* Verifica se dois vetores são iguais,
	 * Entrada: vector de int, vector de int
	 * Retorno: True ou False (boolean)
	 * Pré-condição: Nenhuma
	 * Pós-condição: nenhuma
	*/
bool isEqual(vector<int> a, vector<int> b);



/* Verifica se o elemento está no vetor
	 * Entrada: vector de int, inteiro
	 * Retorno: True ou False (boolean)
	 * Pré-condição: Nenhuma
	 * Pós-condição: nenhuma
	*/
bool isInVetor(vector<int> v, int x);


/* Adiciona um inteiro no final do vetor
	 * Entrada: vector de int, inteiro
	 * Retorno: vetor alterado
	 * Pré-condição: Nenhuma
	 * Pós-condição: vetor alterado
	*/
vector<int> addInVector(vector<int> v, int x);

/* Adiciona um char no final do vetor
	 * Entrada: vector de int, inteiro
	 * Retorno: vetor alterado
	 * Pré-condição: Nenhuma
	 * Pós-condição: vetor alterado
	*/
vector<char> addCharInVector(vector<char> v, char x);

/* Mostra um vetor de char
	 * Entrada: vector dechar
	 * Retorno:  nenhum
	 * Pré-condição: Nenhuma
	 * Pós-condição: nenhuma
	*/
void showalfabeto(vector<char> v);

/* verifica se um vetor é vazio
	 * Entrada: vector de int
	 * Retorno:  true or false
	 * Pré-condição: Nenhuma
	 * Pós-condição: nenhuma
	*/
bool empty(vector<int> v);

/* Normaliza um vetor(ordena e elimina repetições
	 * Entrada: vector de int
	 * Retorno:  vetor normalizado
	 * Pré-condição: Nenhuma
	 * Pós-condição: nenhuma
	*/
vector<int> normalize(vector<int> v);
#endif // AUXILIARVETOR_H
