#include "auxiliarvetor.h"

void showVector(vector<int> v){
    cout << "Vetor: ";    
    for(int i = 0; i < v.size() ; i++){
        cout << " V" << "[" << i << "] = "<< v[i]<< ",";
    }
    cout << endl;
}

void showalfabeto(vector<char> v){
    cout << "Vetor: ";    
    for(int i = 0; i < v.size() ; i++){
        cout << v[i]<< ",";
    }
    cout << endl;
}
vector<int> deleteElement(vector<int> v, int element){
    int i, k, Limit = v.size();
    vector <int> novo;
    int indexDeletet = -1;
    for(i = 0; i < Limit; i++){
       if(v[i] == element){
            indexDeletet = i;
            break;
       }       
    }
    if(indexDeletet == -1)return v;
    novo.resize(Limit - 1);
    for(i = k = 0; k < novo.size(); i++, k++){
       if(i == indexDeletet)i++;
       novo[k] = v[i];       
    }
    return novo;
}
int maior_elemento(vector<int> v){
    int i;
    int maior = 0;
    for(i = 0; i < v.size(); i++){
        if(v[i] > maior)maior = v[i];
    }
    return maior;
}
vector<int> deleteRepetions(vector<int> v){
    int size = maior_elemento(v) + 1;
    vector<int> vetor;
    vetor.resize(size);
    int i, k;
    int newSize = 0;
    for(i = 0; i < size; i++)//Joga zero em todas as posições
        vetor[i] = 0;
        
    for(i = 0; i < v.size(); i++)//taca 1 em cada posição valida
        vetor[v[i]] = 1;
    
    for(i = 0; i < size; i++)//Calcula quantas posições validas tem
        newSize += vetor[i];
        
    v.resize(newSize);
    for(i = k = 0; i < size; i++){
        if(vetor[i] == 1){
            v[k] = i;
            k++;
        }
    }
    return v;
}


vector<int> order(vector<int> v){
    int i,  k, aux;
    for(i = 0; i < v.size(); i++){
        for(k = 0; k < v.size(); k++){
            if(v[k] > v[i]){
                aux = v[k];
                v[k] = v[i];
                v[i] = aux;
            }
        }        
    }
    return v;
}


vector<int> plusVector(vector<int> Aclosure, vector<int> Bclosure){

    int i, j, k, tamanho;
    vector<int> soma;
    
    i = Aclosure.size();
    j = Bclosure.size();
    tamanho = i + j;
    soma.resize(tamanho);
    
    for(k = 0; k < i; k++){
        soma[k] = Aclosure[k];
    }
    for(; k < tamanho; k++){
        soma[k] = Bclosure[k-i];
    }
    return soma;
}

bool isInVetor(vector<int> v, int x){
    for(int i = 0;i < v.size(); i++){
        if(v[i] == x)return true;
    }
    return false;
}

bool isEqual(vector<int> a, vector<int> b){
    int i;
    
    if(a.size() != b.size()) return false;
    for(i=0; i < a.size() && i < b.size(); i++){
        if(a[i] != b[i])return false;
    }
    return true;
}
vector<char> addCharInVector(vector<char> v, char x){
    int tamanho;
    tamanho = v.size();
    v.resize(tamanho + 1);
    v[tamanho] = x;
    return v;
}
vector<int> addInVector(vector<int> v, int x){
    int tamanho;
    tamanho = v.size();
    v.resize(tamanho + 1);
    v[tamanho] = x;
    return v;
}

bool empty(vector<int> v){
        return (v.size() == 0);
}

vector<int> normalize(vector<int> v){
   v = order(v);
   v = deleteRepetions(v);
   return v;
}


