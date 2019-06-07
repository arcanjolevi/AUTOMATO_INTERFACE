#include "transicao.h"

/* Construtor da classe Transicao
 * Entrada: Simbolo lido pela transição e vetor contendo os possíves estados
 * Retorno: Nenhum
 * Pré-condição: Nenhuma
 * Pós-condição: A classe é instanciada
*/
Transicao::Transicao(char simbolo, vector<int> estados, int nDeEstadosPossiveis, int estadoAtual){
	int i;
	this->estadoAtual = estadoAtual;
	this->simboloLido = simbolo;
	this->nDeEstadosPossiveis = nDeEstadosPossiveis;
	this->estadosPossiveis.resize(nDeEstadosPossiveis);
	for(i=0;i<nDeEstadosPossiveis;i++){
		this->estadosPossiveis[i] = estados[i];
	}
}

Transicao::Transicao(Transicao *transicao){
	int i;
	this->estadoAtual = transicao->estadoAtual;
	this->simboloLido = transicao->simboloLido;
	this->nDeEstadosPossiveis = transicao->nDeEstadosPossiveis;
	this->estadosPossiveis.resize(this->nDeEstadosPossiveis);
	for(i = 0;i<this->nDeEstadosPossiveis;i++){
		this->estadosPossiveis[i] = transicao->estadosPossiveis[i];
	}
}

/* Setter da variável estadoAtual
* Entrada: Estado atual
* Retorno: Nenhum
* Pré-condição: Nenhuma
* Pós-condição: O estado atual é atualizado
*/
void Transicao::setEstadoAtual(int estadoAtual){
	this->estadoAtual = estadoAtual;
}

/* Setter da variável simboloLido
 * Entrada: Simbolo lido pela transição
 * Retorno: Nenhum
 * Pré-condição: Nenhuma
 * Pós-condição: O simbolo lido é atualizado
*/
void Transicao::setSimboloLido(char simbolo){
	this->simboloLido = simbolo;
}

/* Setter da variável estadosPossiveis
 * Entrada: Vetor contendo os possíves estados
 * Retorno: Nenhum
 * Pré-condição: Nenhuma
 * Pós-condição: Os estados possíveis são atualizados
*/
void Transicao::setEstadosPossiveis(vector<int> estados, int nDeEstadosPossiveis){
	int i;
	this->nDeEstadosPossiveis = nDeEstadosPossiveis;
	this->estadosPossiveis.resize(nDeEstadosPossiveis);
	for(i=0;i<nDeEstadosPossiveis;i++){
		this->estadosPossiveis[i] = estados[i];
	}
}

/* Setter da variável nDeEstadosPossiveis
 * Entrada: Numero de estados possiveis
 * Retorno: Nenhum
 * Pré-condição: Nenhuma
 * Pós-condição: O numero de estados possíveis é atualizados
*/
void Transicao::setNDeEstadosPossiveis(int nDeEstadosPossiveis){
	this->nDeEstadosPossiveis = nDeEstadosPossiveis;
}

/* Getter da variável estadoAtual
* Entrada: Nenhuma
* Retorno: Estado atual
* Pré-condição: Nenhuma
* Pós-condição: O estado atual é retornado
*/
int Transicao::getEstadoAtual(){
	return this->estadoAtual;
}

/* Getter da variável simboloLido
 * Entrada: Nenhuma
 * Retorno: simbolo lido
 * Pré-condição: Nenhuma
 * Pós-condição: Nenhuma
*/
char Transicao::getSimboloLido(){
	return this->simboloLido;
}

/* Getter da variável estadosPossiveis
 * Entrada: Nenhuma
 * Retorno: Ponteiro para vetor contendo os possíveis estados dessa trasição
 * Pré-condição: Nenhuma
 * Pós-condição: Nenhuma
*/
vector<int> Transicao::getEstadosPossiveis(){
	return this->estadosPossiveis;
}

/* Retorna o primeiro estado possívei de ir a partir dessa transição
* Entrada: Nenhuma
* Retorno: Número do estado possívei de ir
* Pré-condição: Nenhuma
* Pós-condição: Nenhuma
*/
int Transicao::getEstadoPossivel(){
	return this->getEstadosPossiveis()[0];
}

/* Getter da variável nDeEstadosPossiveis
 * Entrada: Nenhuma
 * Retorno: Numero de estados possíveis
 * Pré-condição: Nenhuma
 * Pós-condição: Nenhuma
*/
int Transicao::getNDeEstadosPossiveis(){
	return this->nDeEstadosPossiveis;
}

/* Compara se duas transições são iguais
 * Entrada: Nenhuma
 * Retorno: true se as transições são iguais ou false caso contrário
 * Pré-condição: Ponteiro não nulo para transição
 * Pós-condição: Nenhuma
*/
bool Transicao::equals(Transicao *t){
	int x = 0,i;
	if(this->simboloLido != t->simboloLido) x++;
	if(this->nDeEstadosPossiveis != t->nDeEstadosPossiveis) x++;
	for(i=0;i<this->nDeEstadosPossiveis;i++){
		if(this->estadosPossiveis[i] != t->estadosPossiveis[i]) x++;
	}
	return !!x;
}

/* Compara se duas transições são iguais
 * Entrada: transição
 * Retorno: true se as transições são iguais ou false caso contrário
 * Pré-condição: Nenhuma
 * Pós-condição: Nenhuma
*/
bool Transicao::equals(Transicao t){
	int x = 0,i;
	if(this->simboloLido != t.simboloLido) x++;
	if(this->nDeEstadosPossiveis != t.nDeEstadosPossiveis) x++;
	for(i=0;i<this->nDeEstadosPossiveis;i++){
		if(this->estadosPossiveis[i] != t.estadosPossiveis[i]) x++;
	}
	return !!x;
}

/* Destrutor da classe transicao
 * Entrada: Nenhuma
 * Retorno: Nenhum
 * Pré-condição: Nenhuma
 * Pós-condição: Nenhuma
*/
Transicao::~Transicao(){
	
}
