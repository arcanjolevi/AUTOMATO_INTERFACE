#include "conversao.h"


void showClosureGroup(vector<int> v[], int n){

   cout << "Conjunto de Epsilon Fechamentos" << endl;
    
   for(int i = 0;i < n; i++){
       cout << "Fechamento " << i << endl;
       showVector(v[i]);
   }
}

vector<int> epsilonClosure( Estado state, Automato * AFD, vector<int> Percorridos){
    char symbol = '@';
   vector<int> fechamentoAtual;
   vector<int> tempClosure;
   vector<Transicao*> trans;
   vector<int> EstadosPossiveis;
   Estado * EstadoTemp;
   int n, i;       
   
   fechamentoAtual.resize(1);
   fechamentoAtual[0] = state.getEstado(); 
    
   if(isInVetor(Percorridos, state.getEstado()))// verifica se o estado já passou pela recursão// retorna o fechamento atual se já passou. Caso contrário, adciona o estado atual em percorridos
       return fechamentoAtual;
   else 
       Percorridos = addInVector(Percorridos, state.getEstado());
    
   trans = state.getTransicoes();
   n = state.getNumeroDeTransicoes();   
    
   for(i=0;
       i < n && trans[i]->getSimboloLido() != symbol;
           i++);
            
   if(i >= n)
       return fechamentoAtual;
    
   n = trans[i]->getNDeEstadosPossiveis();
   EstadosPossiveis = trans[i]->getEstadosPossiveis();
   for(i=0 ;i < n; i++){
       EstadoTemp = AFD->returnState(EstadosPossiveis[i]);
       tempClosure = epsilonClosure(EstadoTemp, AFD, Percorridos);
       fechamentoAtual = plusVector(tempClosure, fechamentoAtual);
   }
   return fechamentoAtual;
}


vector<int> calculateClosure(int estado, Automato * AFE){
   vector<int> Percorridos;
   vector<int> Closure;
   Estado * a;
   a = AFE->returnState(estado);
   Percorridos.resize(0);
   Closure = epsilonClosure(a, AFE,  Percorridos);
   Closure = normalize(Closure);
   return Closure;    
}


vector<int> waySymbol(char symbol, int state, Automato * AFD){
   
    vector<Transicao*> transtemp;
   Estado * estadotemp;
   vector<int> caminho;
   int nTrans;
   estadotemp = AFD->returnState(state);
   transtemp = estadotemp ->getTransicoes();
   nTrans = transtemp.size();
   caminho.resize(0);
   for(int i = 0; i < nTrans; i++){
       if(symbol ==  transtemp[i]->getSimboloLido()){
           return transtemp[i]->getEstadosPossiveis();
       }
   }
   
    return caminho;
   
}

vector<int> somaFechamentos(vector<int> Conjuntos, vector<int> Fechamentos[]){
   int i, n;
   vector<int> soma;
   soma.resize(0);
   n = Conjuntos.size();
   for(i = 0; i < n; i++){
       soma = plusVector(soma, Fechamentos[Conjuntos[i]]);
   }
   soma = normalize(soma);
   return soma;
}


vector<int> calculateWaySymbol(char symbol, vector<int> state, Automato * AFD, vector<int> Fechamentos[]){
   
   vector<int> estadoTemp;
   vector<int> totalfechamentos;
   vector<int> novoEstado;
   int i, stateSize;
    
   stateSize = state.size(); 
   totalfechamentos.resize(0);
    
   for(i = 0;i < stateSize; i++){
       estadoTemp = waySymbol(symbol, state[i], AFD);  
       totalfechamentos = plusVector(totalfechamentos, estadoTemp);
   }
   
   
   totalfechamentos = normalize(totalfechamentos);
    
   novoEstado = somaFechamentos(totalfechamentos, Fechamentos);
    
   return novoEstado;
    
}

void imprimeNovos(vector<vector<int>> v){
        int i;
        int n;
        n = v.size();
        cout << "Novos" << endl;
        for(i=0; i < n; i++){
                showVector(v[i]);
        }
}
bool verifyNewState(vector<vector<int>> v, vector<int> estado){
   int i;
   int pertence = 0;
   bool x;
   estado = normalize(estado);
   for(i = 0; i < v.size();i++){
      if(isEqual(v[i], estado)){
           pertence = 1;
           break;
       }
   }   
   return pertence;
}

int getStateEquivalet(vector<vector<int>> v, vector<int> u){
    for(int i = 0;i < v.size();i++){
            if(isEqual(v[i], u))return i;
    }
}
Transicao * buildTransition(vector<vector<int>> Estados, int estadoAtual, char symbol, vector<int> estadoSeguinte){
    vector<int> destino;
    destino.resize(1);
    destino[0] = getStateEquivalet(Estados, estadoSeguinte);
    
    return new Transicao(symbol, destino, 1, estadoAtual );
}
bool isFinal(Automato * AFE, vector<int> Fechamentos){
    vector<int> Final = AFE->getFinals();
    for(int i = 0; i  < Final.size();i++){
        for(int j = 0;j < Fechamentos.size(); j++){
            if(Fechamentos[j] == Final[i])return true;
        }
    }
    return false;
    
}
Estado *  buildState(int estado, Automato * AFE, vector<char> simbolosLidos, vector<Transicao*> transicoes, vector<int> Fechamentos){
    string nome = "Q" + to_string(estado);
    return new Estado(nome, estado,  !estado, isFinal(AFE, Fechamentos), simbolosLidos, simbolosLidos.size(), transicoes, transicoes.size() );
}
Automato * convertAFEtoAFD(Automato * AFE){
    
   int i, E, contTrans, nEstados, alfabetoSize, sizeESTADOS, sizeTRANSICOES;
   int nStates = AFE->getnDeEstados();
   vector<int> Fechamentos[nStates];
   vector<char> ALFABETO;
   vector<int> EstadoTemp;
   vector<vector<int>> NovosEstados;
   vector<Estado*> ESTADOS;
   vector<Transicao*> TRANSICOES;
   vector<char> simbolosLidos;
   
   ALFABETO = AFE->getAlfabeto();
   alfabetoSize = ALFABETO.size();
   sizeESTADOS = 0;
   ESTADOS.resize(0);   
   
 
   for(i = 0;i < nStates;i++){
       Fechamentos[i] = calculateClosure(i, AFE);
   }
  //showClosureGroup(Fechamentos, nStates);
   
   nEstados = 1;
   NovosEstados.resize(nEstados);
   NovosEstados[0] = Fechamentos[0];    
   E = 0;

   while(E < nEstados){
    
       for(TRANSICOES.resize(0), simbolosLidos.resize(0), contTrans = i = 0;i < alfabetoSize;i++){        
           //Calcula o caminho que é possivel ser percorrido lendo um caracter do alfabeto e partido dos fechamentos que compoem o estado
           EstadoTemp = calculateWaySymbol(ALFABETO[i], NovosEstados[E], AFE, Fechamentos);
           sizeESTADOS++;
           //Verifica se o estado já existe. Caso nao exista, adciona ele no vetor de estados
           if(!empty(EstadoTemp) && !verifyNewState(NovosEstados, EstadoTemp)){               
               //getchar();
               nEstados++;
               NovosEstados.resize(nEstados);
               NovosEstados[nEstados - 1] = EstadoTemp;
           }              
           if(EstadoTemp.size()){
               simbolosLidos.resize(contTrans + 1);
               addCharInVector(simbolosLidos, ALFABETO[i]);
               TRANSICOES.resize(contTrans + 1);
               TRANSICOES[contTrans++] = buildTransition(NovosEstados, E, ALFABETO[i], EstadoTemp);
           }
         
           
       }
      // imprimeNovos(NovosEstados);
      
       ESTADOS.resize(E + 1);
       ESTADOS[E] = buildState(E , AFE, simbolosLidos, TRANSICOES, NovosEstados[E] );
       E++;
   }   
   return new Automato(ALFABETO, ESTADOS, ESTADOS.size());

}
