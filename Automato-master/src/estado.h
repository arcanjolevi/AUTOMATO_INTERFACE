#ifndef ESTADO_H
#define ESTADO_H

/* estado.h 
* VERSÃO: 3.0
* ULTIMO EDITOR: Caio
* DATA: 04/06/2019
* HORA: 16:51
* LISTA DE ARQUIVOS UTILIZADOS NA BIBLIOTECA:
*	- transicao.h
*/

#include <iostream>
#include <vector>
#include "transicao.h"

using namespace std;

class Estado{
private:
	string nome;
	int estado;
	int numeroDeTransicoes;
	int numeroDeSimbolosLidos;
	vector<char> simbolosLidos;
	vector<Transicao*> transicoes;
	bool final;
	bool inicial;
public:
	/* Construtor da classe Estado
	 * Entrada: Numero do estado, se é estado inicial, se é estado final, vetor de simbolos lidos, numero de simbolos lidos, vetor de ponteiros para transicoes e numero de transicoes
	 * Retorno: Nenhum
	 * Pré-condição: Nenhuma
	 * Pós-condição: A classe é instanciada
	*/
	Estado(string nome, int estado, bool inicial, bool final, vector<char> simbolosLidos, int nDeSimbolosLidos, vector<Transicao*> transicoes, int numeroDeTransicoes);
	/* Sobrecarga de construtor da classe Estado
	 * Entrada: Ponteiro para estado
	 * Retorno: Nenhum
	 * Pré-condição: Nenhuma
	 * Pós-condição: A classe é instanciada
	*/
	Estado(Estado * estado);
	/* Setter da variável nome
	 * Entrada: Nome do estado
	 * Retorno: Nenhum
	 * Pré-condição: Nenhuma
	 * Pós-condição: O nome do estado é atualizado
	*/
	void setNome(string nome);
	/* Setter da variável estado
	 * Entrada: Numero do estado
	 * Retorno: Nenhum
	 * Pré-condição: Nenhuma
	 * Pós-condição: O numero do estado é atualizado
	*/
	void setEstado(int estado);
	/* Setter da variável simbolosLidos
	 * Entrada: Vetor de simbolos lidos e numero de simbolos lidos
	 * Retorno: Nenhum
	 * Pré-condição: Nenhuma
	 * Pós-condição: O vetor de simbolos lidos é atualizado
	*/
	void setSimbolosLidos(vector<char> simbolosLidos);
	/* Setter da variável Transicoes
	 * Entrada: Vetor de ponteiros para transicoes e numero de transicoes
	 * Retorno: Nenhum
	 * Pré-condição: Nenhuma
	 * Pós-condição: O vetor de ponteiros para transicoes é atualizado
	*/
	void setTransicoes(vector<Transicao*> transicoes, int numeroDeTransicoes);
	/* Setter da variável final
	 * Entrada: Se é ou não estado final
	 * Retorno: Nenhum
	 * Pré-condição: Nenhuma
	 * Pós-condição: A condição de estado final é atualizada
	*/
	void setFinal(bool final);
	/* Setter da variável inicial
	 * Entrada: Se é ou não estado inicial
	 * Retorno: Nenhum
	 * Pré-condição: Nenhuma
	 * Pós-condição: A condição de estado inicial é atualizada
	*/
	void setInicial(bool inicial);
	/* Setter da variável numeroDeTransicoes
	 * Entrada: Numero de transicoes
	 * Retorno: Nenhum
	 * Pré-condição: Nenhuma
	 * Pós-condição: O numero de transições é atualizado
	*/
	void setNumeroDeTransicoes(int numeroDeTransicoes);
	/* Setter da variável numeroDeSimbolosLidos
	 * Entrada: Numero de simbolos lidos
	 * Retorno: Nenhum
	 * Pré-condição: Nenhuma
	 * Pós-condição: O numero de simbolos lidos é atualizado
	*/
	void setNumeroDeSimbolosLidos(int numeroDeSimbolosLidos);
	/* Getter da variável nome
	 * Entrada: Nenhuma
	 * Retorno: Nome do estado
	 * Pré-condição: Nenhuma
	 * Pós-condição: Nenhuma
	*/
	string getNome();
	/* Getter da variável estado
	 * Entrada: Nenhuma
	 * Retorno: Numero do estado
	 * Pré-condição: Nenhuma
	 * Pós-condição: Nenhuma
	*/
	int getEstado();
	/* Getter da variável simbolosLidos
	 * Entrada: Nenhuma
	 * Retorno: Vetor de símbolos lidos
	 * Pré-condição: Nenhuma
	 * Pós-condição: Nenhuma
	*/
	vector<char> getSimbolosLidos();
	/* Getter da variável transicoes
	 * Entrada: Nenhuma
	 * Retorno: Vetor de ponteiros de transicoes
	 * Pré-condição: Nenhuma
	 * Pós-condição: Nenhuma
	*/
	vector<Transicao*> getTransicoes();
	/* Getter da variável final
	 * Entrada: Nenhuma
	 * Retorno: Verdadeiro ou falso
	 * Pré-condição: Nenhuma
	 * Pós-condição: Nenhuma
	*/
	bool getFinal();
	/* Getter da variável inicial
	 * Entrada: Nenhuma
	 * Retorno: Verdadeiro ou falso
	 * Pré-condição: Nenhuma
	 * Pós-condição: Nenhuma
	*/
	bool getInicial();
	/* Getter da variável numeroDeTransicoes
	 * Entrada: Nenhuma
	 * Retorno: Numero de transições do estado
	 * Pré-condição: Nenhuma
	 * Pós-condição: Nenhuma
	*/
	int getNumeroDeTransicoes();
	/* Getter da variável numeroDeSimbolosLidos
	 * Entrada: Nenhuma
	 * Retorno: Numero de simbolos lidos do estado
	 * Pré-condição: Nenhuma
	 * Pós-condição: Nenhuma
	*/
	int getNumeroDeSimbolosLidos();
	/* Mostra os dados do estado
	 * Entrada: Nenhuma
	 * Retorno: Nenhum
	 * Pré-condição: Nenhuma
	 * Pós-condição: Os dados do estado são mostrados na tela
	*/
	void show();
	/* Compara se dois estados são iguais
	 * Entrada: Nenhuma
	 * Retorno: true se os esdados são iguais ou false caso contrário
	 * Pré-condição: Ponteiro não nulo para estado
	 * Pós-condição: Nenhuma
	*/
	bool equals(Estado *e);
	/* Compara se dois estados são iguais
	 * Entrada: Estado
	 * Retorno: true se os esdados são iguais ou false caso contrário
	 * Pré-condição: Nenhuma
	 * Pós-condição: Nenhuma
	*/
	bool equals(Estado e);
	/* Destrutor da classe Estado
	 * Entrada: Nenhuma
	 * Retorno: Nenhum
	 * Pré-condição: Nenhuma
	 * Pós-condição: Nenhuma
	*/
	~Estado();
};

#endif
