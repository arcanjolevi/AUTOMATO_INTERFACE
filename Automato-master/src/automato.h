#ifndef AUTOMATO_H
#define AUTOMATO_H

/* automato.h 
* VERSÃO: 3.2
* ULTIMO EDITOR: Caio
* DATA: 04/06/2019
* HORA: 16:43
* LISTA DE ARQUIVOS UTILIZADOS NA BIBLIOTECA:
*	- estado.h
*/

#include <iostream>
#include <vector>
#include "estado.h"

using namespace std;

class Automato{
private:
	vector<char> alfabeto;
	vector<Estado*> estados;
	int nDeEstados;
public:
	/* Construtor da classe Automato
	 * Entrada: Vetor do alfabeto, vetor de ponteiros para estados e numero de estados
	 * Retorno: Nenhum
	 * Pré-condição: Nenhuma
	 * Pós-condição: A classe é instanciada
	*/
	Automato(vector<char> alfabeto, vector<Estado*> estados, int nDeEstados);
	/* Setter da variável alfabeto
	 * Entrada: Vetor do alfabeto 
	 * Retorno: Nenhum
	 * Pré-condição: Nenhuma
	 * Pós-condição: O vetor do alfabeto é atualizado
	*/
	void setAlfabeto(vector<char> alfabeto);
	/* Setter da variável estados
	 * Entrada: Vetor de ponteiros para estados e número de estados
	 * Retorno: Nenhum
	 * Pré-condição: Nenhuma
	 * Pós-condição: O vetor de estados é atualizado
	*/
	void setEstados(vector<Estado*> estados, int nDeEstados);
	/* Setter da variável nDeEstados
	 * Entrada: Numero de estados
	 * Retorno: Nenhum
	 * Pré-condição: Nenhuma
	 * Pós-condição: O numero de estados é atualizado
	*/
	void setnDeEstados(int nDeEstados);
	/* Getter da variável alfabeto
	 * Entrada: Nenhuma
	 * Retorno: Vetor do alfabeto
	 * Pré-condição: Nenhuma
	 * Pós-condição: Nenhuma
	*/
	vector<char> getAlfabeto();
	/* Getter da variável estados
	 * Entrada: Nenhuma
	 * Retorno: Vetor de ponteiros para estados
	 * Pré-condição: Nenhuma
	 * Pós-condição: Nenhuma
	*/
	vector<Estado*> getEstados();
	/* Getter da variável nDeEstados
	 * Entrada: Nenhuma
	 * Retorno: Numero de estados
	 * Pré-condição: Nenhuma
	 * Pós-condição: Nenhuma
	*/
	int getnDeEstados();
	/* DEBUG:Mostra os dados de um automato na tela
	 * Entrada: Nenhuma
	 * Retorno: Nenhum
	 * Pré-condição: Nenhuma
	 * Pós-condição: O conteúdo do automato é mostrado na tela
	*/
	void show();
	/* Retorna um Estado especifico
	 * Entrada: inteiro que representa o estado
	 * Retorno: Ponteiro do estado especifico
	 * Pré-condição: Nenhuma
	 * Pós-condição: retorna -1 se nao existe
	*/
	Estado *returnState(int n);
	/* Retorna um Estado especifico
	 * Entrada: string que representa o estado
	 * Retorno: Ponteiro do estado especifico
	 * Pré-condição: Nenhuma
	 * Pós-condição: retorna NULL se nao existe
	*/
	Estado *returnState(string nome);
	/* Retorna os estados finais do automato
 	* Entrada: nenhuma
 	* Retorno: vetor de int, contendo os inteiros que representam os estados finais
 	* Pré-condição: O automato deve possuir no mínimo 1 estado final
 	* Pós-condição: nenhuma
	*/
	vector<int> getFinals();
	/* Retorna o estado inicial do automato
 	* Entrada: nenhuma
 	* Retorno:  int, que representa o estado inicial do automato. Retorna -1 caso não exista
 	* Pré-condição: Nenhuma
 	* Pós-condição: nenhuma
	*/
	int getInitial();
	/* Destrutor da classe automato
	 * Entrada: Nenhuma
	 * Retorno: Nenhum
	 * Pré-condição: Nenhuma
	 * Pós-condição: A classe é destruida
	*/
	~Automato();
};

#endif
