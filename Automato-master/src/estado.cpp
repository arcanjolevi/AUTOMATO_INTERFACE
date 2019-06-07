#include "estado.h"

/* Construtor da classe Estado
 * Entrada: Numero do estado, se é estado inicial, se é estado final, vetor de simbolos lidos, vetor de ponteiros para transicoes e numero de transicoes
 * Retorno: Nenhum
 * Pré-condição: Nenhuma
 * Pós-condição: A classe é instanciada
*/
Estado::Estado(string nome, int estado, bool inicial, bool final, vector<char> simbolosLidos, int nDeSimbolosLidos, vector<Transicao*> transicoes, int numeroDeTransicoes){
	int i;
	this->nome = nome;
	this->estado = estado;
	this->inicial = inicial;
	this->final = final;
	this->numeroDeSimbolosLidos = nDeSimbolosLidos;
	this->simbolosLidos.resize(nDeSimbolosLidos);
	for(i=0;i<nDeSimbolosLidos;i++){
		this->simbolosLidos[i] = simbolosLidos[i];
	}
	this->numeroDeTransicoes = numeroDeTransicoes;
	this->transicoes.resize(numeroDeTransicoes);
	for(i=0;i<numeroDeTransicoes;i++){
		this->transicoes[i] = new Transicao(transicoes[i]);
	}
}

Estado::Estado(Estado * estado){
	int i;
	this->nome = estado->getNome();
	this->estado = estado->getEstado();
	this->inicial = estado->getInicial();
	this->final = estado->getFinal();
	this->numeroDeSimbolosLidos = estado->getNumeroDeSimbolosLidos();
	this->simbolosLidos.resize(this->numeroDeSimbolosLidos);
	for(i=0;i<this->numeroDeSimbolosLidos;i++){
		this->simbolosLidos[i] = estado->getSimbolosLidos()[i];
	}
	this->numeroDeTransicoes = estado->getNumeroDeTransicoes();
	this->transicoes.resize(this->numeroDeTransicoes);
	for(i=0;i<this->numeroDeTransicoes;i++){
 		this->transicoes[i] = new Transicao(estado->getTransicoes()[i]);
 	}
 }

/* Setter da variável nome
 * Entrada: Nome do estado
 * Retorno: Nenhum
 * Pré-condição: Nenhuma
 * Pós-condição: O nome do estado é atualizado
*/
void Estado::setNome(string nome){
	this->nome = nome;
}

/* Setter da variável estado
 * Entrada: Numero do estado
 * Retorno: Nenhum
 * Pré-condição: Nenhuma
 * Pós-condição: O numero do estado é atualizado
*/
void Estado::setEstado(int estado){
	this->estado = estado;
}

/* Setter da variável simbolosLidos
 * Entrada: Vetor de simbolos lidos
 * Retorno: Nenhum
 * Pré-condição: Nenhuma
 * Pós-condição: O vetor de simbolos lidos é atualizado
*/
void Estado::setSimbolosLidos(vector<char> simbolosLidos){
	int i;
	this->simbolosLidos.resize(this->numeroDeSimbolosLidos);
	for(i=0;i<this->numeroDeSimbolosLidos;i++){
		this->simbolosLidos[i] = simbolosLidos[i];
	}
}

/* Setter da variável Transicoes
 * Entrada: Vetor de ponteiros para transicoes
 * Retorno: Nenhum
 * Pré-condição: Nenhuma
 * Pós-condição: O vetor de ponteiros para transicoes é atualizado
*/
void Estado::setTransicoes(vector<Transicao*> transicoes, int numeroDeTransicoes){
	int i;
	this->numeroDeTransicoes = numeroDeTransicoes;
	this->transicoes.resize(numeroDeTransicoes);
	for(i=0;i<numeroDeTransicoes;i++){
		this->transicoes[i] = transicoes[i];
	}
}

/* Setter da variável final
 * Entrada: Se é ou não estado final
 * Retorno: Nenhum
 * Pré-condição: Nenhuma
 * Pós-condição: A condição de estado final é atualizada
*/
void Estado::setFinal(bool final){
	this->final = final;
}

/* Setter da variável inicial
 * Entrada: Se é ou não estado inicial
 * Retorno: Nenhum
 * Pré-condição: Nenhuma
 * Pós-condição: A condição de estado inicial é atualizada
*/
void Estado::setInicial(bool inicial){
	this->inicial = inicial;
}

/* Setter da variável numeroDeTransicoes
 * Entrada: Numero de transicoes
 * Retorno: Nenhum
 * Pré-condição: Nenhuma
 * Pós-condição: O numero de transições é atualizado
*/
void Estado::setNumeroDeTransicoes(int numeroDeTransicoes){
	this->numeroDeTransicoes = numeroDeTransicoes;
}

/* Setter da variável numeroDeSimbolosLidos
 * Entrada: Numero de simbolos lidos
 * Retorno: Nenhum
 * Pré-condição: Nenhuma
 * Pós-condição: O numero de simbolos lidos é atualizado
*/
void Estado::setNumeroDeSimbolosLidos(int numeroDeSimbolosLidos){
	this->numeroDeSimbolosLidos = numeroDeSimbolosLidos;
}

/* Getter da variável nome
 * Entrada: Nenhuma
 * Retorno: Nome do estado
 * Pré-condição: Nenhuma
 * Pós-condição: Nenhuma
*/
string Estado::getNome(){
	return this->nome;
}

/* Getter da variável estado
 * Entrada: Nenhuma
 * Retorno: Numero do estado
 * Pré-condição: Nenhuma
 * Pós-condição: Nenhuma
*/
int Estado::getEstado(){
	return this->estado;
}

/* Getter da variável simbolosLidos
 * Entrada: Nenhuma
 * Retorno: Vetor de símbolos lidos
 * Pré-condição: Nenhuma
 * Pós-condição: Nenhuma
*/
vector<char> Estado::getSimbolosLidos(){
	return this->simbolosLidos;
}

/* Getter da variável transicoes
 * Entrada: Nenhuma
 * Retorno: Vetor de ponteiros de transicoes
 * Pré-condição: Nenhuma
 * Pós-condição: Nenhuma
*/
vector<Transicao*> Estado::getTransicoes(){
	return this->transicoes;
}

/* Getter da variável final
 * Entrada: Nenhuma
 * Retorno: Verdadeiro ou falso
 * Pré-condição: Nenhuma
 * Pós-condição: Nenhuma
*/
bool Estado::getFinal(){
	return this->final;
}

/* Getter da variável inicial
 * Entrada: Nenhuma
 * Retorno: Verdadeiro ou falso
 * Pré-condição: Nenhuma
 * Pós-condição: Nenhuma
*/
bool Estado::getInicial(){
	return this->inicial;
}

/* Getter da variável numeroDeTransicoes
 * Entrada: Nenhuma
 * Retorno: Numero de transições do estado
 * Pré-condição: Nenhuma
 * Pós-condição: Nenhuma
*/
int Estado::getNumeroDeTransicoes(){
	return this->numeroDeTransicoes;
}

/* Getter da variável numeroDeSimbolosLidos
 * Entrada: Nenhuma
 * Retorno: Numero de simbolos lidos do estado
 * Pré-condição: Nenhuma
 * Pós-condição: Nenhuma
*/
int Estado::getNumeroDeSimbolosLidos(){
	return this->numeroDeSimbolosLidos;
}

/* Mostra os dados do estado
 * Entrada: Nenhuma
 * Retorno: Nenhum
 * Pré-condição: Nenhuma
 * Pós-condição: Os dados do estado são mostrados na tela
*/
void Estado::show(){
	cout << this->nome;
}

/* Compara se dois estados são iguais
 * Entrada: Ponteiro para estado
 * Retorno: true se os esdados são iguais ou false caso contrário
 * Pré-condição: Ponteiro não nulo para estado
 * Pós-condição: Nenhuma
*/
bool Estado::equals(Estado *e){
	int x=0;
	if(this->nome != e->nome) x++;
	return !!x;
}

/* Compara se dois estados são iguais
 * Entrada: Estado
 * Retorno: true se os esdados são iguais ou false caso contrário
 * Pré-condição: Nenhuma
 * Pós-condição: Nenhuma
*/
bool Estado::equals(Estado e){
	int x=0;
	if(this->nome != e.nome) x++;
	return !!x;
}

/* Destrutor da classe Estado
 * Entrada: Nenhuma
 * Retorno: Nenhum
 * Pré-condição: Nenhuma
 * Pós-condição: Nenhuma
*/
Estado::~Estado(){
	int i;
	for(i=0;i<numeroDeTransicoes;i++){
		//cout << "Transições deletadas com sucesso!\n";
		delete this->transicoes[i];
	}
}
