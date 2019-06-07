#include "processa.h"

/* Processa uma palavra dado um autômato
* Entrada: Automato
* Retorno: Nenhum
* Pré-condição: O autômato deve existir e estar completo
* Pós-condição: A palavra é processada
*/
string process(char *palavra, Automato *a){
    string processada="";
    Estado *e = new Estado(a->getEstados()[a->getInitial()]);
    int i,k,novoEstado,controle=0;
    char *aux=palavra;
    processada +=  "\t\t\tProcessamento de: ";
    processada += palavra;
    processada += "\n\n";
    
     for(i=0;i<strlen(palavra);i++,aux++){
        for(k=0;k<e->getNumeroDeTransicoes();k++){
            if(palavra[i] == e->getTransicoes()[k]->getSimboloLido()){
                processada += "[";
                processada += e->getNome();
                processada += "]: ";
                processada += aux;
                processada += "\n";
                novoEstado = e->getTransicoes()[k]->getEstadoPossivel();
                delete e;
                e = new Estado(a->getEstados()[novoEstado]);
                break;
            }else if(palavra[i] != e->getTransicoes()[k]->getSimboloLido() && k == e->getNumeroDeTransicoes()-1){
                controle=1;
                break;
            }
        }
        if(controle==1) {
            //aux++;
            break;
        }
    }
    if(controle==0 && e->getFinal() == true){
        processada += "[";
        processada += e->getNome();
        processada += "]: \n";
        processada += "Palavra aceita\n";
    }else{
        processada += "[";
        processada += e->getNome();
        processada += "]: ";
        processada += aux;
        processada += "\n";
        processada += "Palavra rejeitada\n";
    }
    return processada;
}

