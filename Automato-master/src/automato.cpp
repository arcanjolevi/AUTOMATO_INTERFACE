#include "automato.h"

/* Construtor da classe Automato
 * Entrada: Vetor do alfabeto, vetor de ponteiros para estados e numero de estados
 * Retorno: Nenhum
 * Pré-condição: Nenhuma
 * Pós-condição: A classe é instanciada
*/
Automato::Automato(vector<char> alfabeto, vector<Estado*> estados, int nDeEstados){
	int i;
	this->alfabeto = alfabeto;
	this->estados.resize(nDeEstados);
	this->nDeEstados = nDeEstados;
	for(i=0;i<nDeEstados;i++){
		this->estados[i] = estados[i];
	}
}

/* Setter da variável alfabeto
 * Entrada: Vetor do alfabeto 
 * Retorno: Nenhum
 * Pré-condição: Nenhuma
 * Pós-condição: O vetor do alfabeto é atualizado
*/
void Automato::setAlfabeto(vector<char> alfabeto){
	this->alfabeto = alfabeto;
}

/* Setter da variável estados
 * Entrada: Vetor de ponteiros para estados e numero de estados
 * Retorno: Nenhum
 * Pré-condição: Nenhuma
 * Pós-condição: O vetor de estados é atualizado
*/
void Automato::setEstados(vector<Estado*> estados, int nDeEstados){
	int i;
	this->estados.resize(nDeEstados);
	this->nDeEstados = nDeEstados;
	for(i=0;i<nDeEstados;i++){
		this->estados[i] = estados[i];
	}
}

/* Setter da variável nDeEstados
 * Entrada: Numero de estados
 * Retorno: Nenhum
 * Pré-condição: Nenhuma
 * Pós-condição: O numero de estados é atualizado
*/
void Automato::setnDeEstados(int nDeEstados){
	this->nDeEstados = nDeEstados;
}

/* Getter da variável alfabeto
 * Entrada: Nenhuma
 * Retorno: Vetor do alfabeto
 * Pré-condição: Nenhuma
 * Pós-condição: Nenhuma
*/
vector<char> Automato::getAlfabeto(){
	return this->alfabeto;
}

/* Getter da variável estados
 * Entrada: Nenhuma
 * Retorno: Vetor de ponteiros para estados
 * Pré-condição: Nenhuma
 * Pós-condição: Nenhuma
*/
vector<Estado*> Automato::getEstados(){
	return this->estados;
}

/* Getter da variável nDeEstados
 * Entrada: Nenhuma
 * Retorno: Numero de estados
 * Pré-condição: Nenhuma
 * Pós-condição: Nenhuma
*/
int Automato::getnDeEstados(){
	return this->nDeEstados;
}

/* DEBUG:Mostra os dados de um automato na tela
 * Entrada: Nenhuma
 * Retorno: Nenhum
 * Pré-condição: Nenhuma
 * Pós-condição: O conteúdo do automato é mostrado na tela
*/
void Automato::show(){
	system("clear");
	int i,k;
	cout << "alfabeto={";
	for(i=0;i<this->alfabeto.size();i++){
		cout << this->alfabeto[i];
		if(i != alfabeto.size()-1){
			cout << ",";
		}
	}
	cout << "}\n";
	cout << "estados={";
	for(i=0;i<this->nDeEstados;i++){
		this->estados[i]->show();
		if(i != this->nDeEstados-1){
			cout << ",";
		}
	}
	cout << "}\n";
	cout << "inicial=" << this->estados[this->getInitial()]->getNome() << endl;
	cout << "finais={";
	for(i=0;i<this->getFinals().size();i++){
		this->estados[this->getFinals()[i]]->show();
		if(i != this->getFinals().size()-1){
			cout << ",";
		}
	}
	cout << "}\n";
	for(i=0;i<this->nDeEstados;i++){
		for(k=0;k<this->estados[i]->getNumeroDeTransicoes();k++){
			cout << "(" << this->estados[i]->getNome() << ",";
			cout << this->estados[i]->getTransicoes()[k]->getSimboloLido() << ") = ";
			cout << this->estados[this->estados[i]->getTransicoes()[k]->getEstadoPossivel()]->getNome() << endl;
		}
	}
}

/* Retorna um Estado especifico
 * Entrada: inteiro que representa o estado
 * Retorno: Ponteiro do estado especifico
 * Pré-condição: Nenhuma
 * Pós-condição: retorna NULL se nao existe
*/
Estado *Automato::returnState(int n){
	int i;
	for(i=0;i<this->nDeEstados;i++){
		if(this->estados[i]->getEstado() == n) return this->estados[i];
	}	
	return NULL;
}

/* Retorna um Estado especifico
 * Entrada: string que representa o estado
 * Retorno: Ponteiro do estado especifico
 * Pré-condição: Nenhuma
 * Pós-condição: retorna NULL se nao existe
*/
Estado *Automato::returnState(string nome){
	int i;
	for(i=0;i<this->nDeEstados;i++){
		if(this->estados[i]->getNome() == nome) return this->estados[i];
	}
	return NULL;
}

/* Retorna os estados finais do automato
* Entrada: nenhuma
* Retorno: vetor de int, contendo os inteiros que representam os estados finais
* Pré-condição: O automato deve possuir no mínimo 1 estado final
* Pós-condição: nenhuma
*/
vector<int> Automato::getFinals(){
	vector<int> finais;
	int i,k;
	for(i=0,k=1;i<this->nDeEstados;i++){
		if(this->estados[i]->getFinal() == true){
			finais.resize(k);
			finais[k-1] = this->estados[i]->getEstado();
			k++;
		}
	}
	return finais;
}

/* Retorna o estado inicial do automato
* Entrada: nenhuma
* Retorno:  int, que representa o estado inicial do automato. Retorna -1 caso não exista
* Pré-condição: Nenhuma
* Pós-condição: nenhuma
*/
int Automato::getInitial(){
	int i;
	for(i=0;i<this->nDeEstados;i++){
		if(this->estados[i]->getInicial() == true) return this->estados[i]->getEstado();
	}
	return -1;
}

/* Destrutor da classe automato
 * Entrada: Nenhuma
 * Retorno: Nenhum
 * Pré-condição: Nenhuma
 * Pós-condição: A classe é destruida
*/
Automato::~Automato(){
	int i;
	for(i=0;i<this->nDeEstados;i++){
		//cout << "deletando estado\n";
		delete this->estados[i];
	}
}
