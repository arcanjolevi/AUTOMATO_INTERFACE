#ifndef TRANSICAO_H
#define TRANSICAO_H

/* transicao.h 
* VERSÃO: 2.3
* ULTIMO EDITOR: Caio
* DATA: 04/06/2019
* HORA: 16:43
* LISTA DE ARQUIVOS UTILIZADOS NA BIBLIOTECA:
*/

#include <iostream>
#include <vector>

using namespace std;

class Transicao{
private:
	char simboloLido;
	vector<int> estadosPossiveis;
	int nDeEstadosPossiveis;
	int estadoAtual;
public:
	/* Construtor da classe Transicao
	 * Entrada: Simbolo lido pela transição e vetor contendo os possíves estados
	 * Retorno: Nenhum
	 * Pré-condição: Nenhuma
	 * Pós-condição: A classe é instanciada
	*/
	Transicao(char simbolo, vector<int> estados, int nDeEstadosPossiveis, int estadoAtual);
	/* Sobrecarga do construtor da classe Transicao
	 * Entrada: Ponteiro para transicao
	 * Retorno: Nenhum
	 * Pré-condição: Nenhuma
	 * Pós-condição: A classe é instanciada
	*/
	Transicao(Transicao *transicao);
	/* Setter da variável estadoAtual
	* Entrada: Estado atual
	* Retorno: Nenhum
	* Pré-condição: Nenhuma
	* Pós-condição: O estado atual é atualizado
	*/
	void setEstadoAtual(int estadoAtual);
	/* Setter da variável simboloLido
	 * Entrada: Simbolo lido pela transição
	 * Retorno: Nenhum
	 * Pré-condição: Nenhuma
	 * Pós-condição: O simbolo lido é atualizado
	*/
	void setSimboloLido(char simbolo);
	/* Setter da variável estadosPossiveis
	 * Entrada: Vetor contendo os possíves estados
	 * Retorno: Nenhum
	 * Pré-condição: Nenhuma
	 * Pós-condição: Os estados possíveis são atualizados
	*/
	void setEstadosPossiveis(vector<int> estados, int nDeEstadosPossiveis);
	/* Setter da variável nDeEstadosPossiveis
	 * Entrada: Numero de estados possiveis
	 * Retorno: Nenhum
	 * Pré-condição: Nenhuma
	 * Pós-condição: O numero de estados possíveis é atualizados
	*/
	void setNDeEstadosPossiveis(int nDeEstadosPossiveis);
	/* Getter da variável estadoAtual
	* Entrada: Nenhuma
	* Retorno: Estado atual
	* Pré-condição: Nenhuma
	* Pós-condição: O estado atual é retornado
	*/
	int getEstadoAtual();
	/* Getter da variável simboloLido
	 * Entrada: Nenhuma
	 * Retorno: simbolo lido
	 * Pré-condição: Nenhuma
	 * Pós-condição: Nenhuma
	*/
	char getSimboloLido();
	/* Getter da variável estadosPossiveis
	 * Entrada: Nenhuma
	 * Retorno: Ponteiro para vetor contendo os possíveis estados dessa trasição
	 * Pré-condição: Nenhuma
	 * Pós-condição: Nenhuma
	*/
	vector<int> getEstadosPossiveis();
	/* Retorna o primeiro estado possívei de ir a partir dessa transição
	* Entrada: Nenhuma
	* Retorno: Número do estado possívei de ir
	* Pré-condição: Nenhuma
	* Pós-condição: Nenhuma
	*/
	int getEstadoPossivel();
	/* Getter da variável nDeEstadosPossiveis
	 * Entrada: Nenhuma
	 * Retorno: Numero de estados possíveis
	 * Pré-condição: Nenhuma
	 * Pós-condição: Nenhuma
	*/
	int getNDeEstadosPossiveis();
	/* Compara se duas transições são iguais
	 * Entrada: Ponteiro para transição
	 * Retorno: true se as transições são iguais ou false caso contrário
	 * Pré-condição: Ponteiro não nulo para transição
	 * Pós-condição: Nenhuma
	*/
	bool equals(Transicao *t);
	/* Compara se duas transições são iguais
	 * Entrada: transição
	 * Retorno: true se as transições são iguais ou false caso contrário
	 * Pré-condição: Nenhuma
	 * Pós-condição: Nenhuma
	*/
	bool equals(Transicao t);
	/* Destrutor da classe transicao
	 * Entrada: Nenhuma
	 * Retorno: Nenhum
	 * Pré-condição: Nenhuma
	 * Pós-condição: A classe é destruida
	*/
	~Transicao();
};

#endif
