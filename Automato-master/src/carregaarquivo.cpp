#include "carregaarquivo.h"


using namespace std;

/* Removedor de virgula
 * Entrada: Vetor de char, uma matriz de char
 * Retorno: Vector preenchido com o alfabeto
 * Pré-condição: nenhuma
 * Pós-condição: Nenhum
*/

vector<char> ChangeChar(char enviador[],vector<char> recebedor){
    int n;
    n = strlen(enviador);
    recebedor.resize(n);
    for(int i=0;i<n;i++){
        recebedor[i] = enviador[i];
    }
    return recebedor;

}

/* Removedor de virgula
 * Entrada: Vetor de char, uma matriz de char
 * Retorno: tamanho da matriz
 * Pré-condição: nenhuma
 * Pós-condição: A matriz preenchida com as palavras entre as virgulas do vetor de char
*/
int RemoveComma(char *s,char *retorno[]){
	char *temp;
	int contador=0;
    temp = strtok(s,",{}");
    while(temp != NULL ){
        retorno[contador] = (char*)malloc(strlen(temp));
        strcpy(retorno[contador],temp);
        temp = strtok(NULL,",{}");
        contador++;
	}
	return contador;
}

/* Remove as virgulas e abre fecha chaves de uma string
 * Entrada: Vetor de char
 * Retorno: Nenhum
 * Pré-condição: nenhuma
 * Pós-condição: vetor sem virgulas , abre e fecha chaves
*/
void RemoveComma(char *s){
	char *temp;
    char retorno[50];
    retorno[0] = NULL;
	int contador=0;
    temp = strtok(s,",{}");
    while(temp != NULL ){
        strcat(retorno,temp);
        temp = strtok(NULL,",{}");
        contador++;
	}
    strcpy(s,retorno);
}

/* Selecionador de posição
 * Entrada: Ponteiro para char, Vetor de ponteiros para char, inteiro com quantidade de colunas da matriz
 * Retorno: posição do estado na matriz
 * Pré-condição: Palavra chave valida
 * Pós-condição: nenhuma
*/
int IntStateReturn(char *EstadoTokens,char *Estado[],int QuantidadeEstados){
    int i;
    for(i=0;i<QuantidadeEstados;i++){
        if(strcmp(EstadoTokens,Estado[i]) == 0) return i;
    }
    return i;
}

/* Concatena um inteiro num vector de char
 * Entrada: vector de char, e um inteiro
 * Retorno: nenhum
 * Pré-condição: Nenhuma
 * Pós-condição: Nenhuma
*/
void veccat(vector<char> Recebedora,int Enviadora){
    int max;
    max = Recebedora.size();
        Recebedora[max] = Enviadora;
}

/* Cria um vector de transiçoes auxiliar
 * Entrada: vector de ponteiro apra transicao,vector de ponteiro apra transicao,vetor de char com o nome do estado atual, uma matriz de char com os nomes dos estados, e um inteiro com a quantiade de estados
 * Retorno: Vector de Transicoes auxiliar
 * Pré-condição: Nenhum valor de entrada nullo
 * Pós-condição: Nenhuma
*/
vector<Transicao*> ConvertTransition(vector<Transicao*> Recebedor,vector<Transicao*>Enviador,char *NomeEstado,char **MatrizEstados,int QuantidadeEstados){
    int tamanho = Enviador.size();
    int n=0;
    vector<int> temp;
    int Posicaoestado = IntStateReturn(NomeEstado,MatrizEstados,QuantidadeEstados);
    for(int i=0;i<tamanho;i++){
        if(Posicaoestado == Enviador[i]->getEstadoAtual()){
            Recebedor.resize(n+1);
            temp =Enviador[i]->getEstadosPossiveis(); 
            Recebedor[n] = new Transicao(Enviador[i]->getSimboloLido(),temp,temp.size(),Posicaoestado);
            n++;
        }     
    }
    return Recebedor;
}
/* Removedor de espaços
 * Entrada: Vetor de char
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: O vetor sem espaços em branco.
*/
void removeSpaces(char s[]){
	char *temp;
	char novo[500];
    novo[0] = NULL;
	temp = strtok(s," ");
	while(temp != NULL){
		strcat(novo,temp);
		temp = strtok(NULL," ");
	}
	strcpy(s,novo);
}

/* Cria um novo arquivo com tratamentos 
 * Entrada: Caminho do arquivo
 * Retorno: Caminho do novo arquivo tratado
 * Pré-condição: Caminho de arquivo valido
 * Pós-condição: Nenhum
*/
char* NewFile(char *OldArquivo){
    char Linha[500];
    FILE *arquivoantigo;
    FILE *arquivonovo;

    arquivoantigo = fopen(OldArquivo,"r");
    strcpy(strstr(OldArquivo,".txt"),"2newarq.txt");
    arquivonovo = fopen(OldArquivo,"w");
    if(arquivoantigo != NULL && arquivonovo != NULL)
    while(!feof(arquivoantigo)){
        fscanf(arquivoantigo,"%[^\n]%*r",Linha);
        if(Linha[0] != NULL){
            removeSpaces(Linha);
            if(strlen(Linha) > 7)
                fprintf(arquivonovo,"%s\n",Linha);
        }
    }
    fclose(arquivoantigo);
    fclose(arquivonovo);
    return OldArquivo;
}

/* Le o alfabeto
 * Entrada:arquivo a ser lido, vetor de char para armazenar o alfabeto
 * Retorno:Nenhum
 * Pré-condição:Arquivo FILE valido
 * Pós-condição:Nenhum
*/
void LoadAlphabet(FILE *arquivo,char *alfabeto){
    fscanf(arquivo,"alfabeto=%[^\n]%*r",alfabeto);
}

/* Le os estados
 * Entrada:arquivo a ser lido, vetor de ponteiros para char que armazena os estados,inteiro com a quantidade de estados na matriz
 * Retorno:Nenhum
 * Pré-condição:Arquivo FILE valido
 * Pós-condição:Nenhum
*/
void LoadState(FILE *arquivo,char *MatrizEstados[],int *QuantidadeEstados){
    char LinTemp[200];
    fscanf(arquivo,"estados={");
    fscanf(arquivo,"%[^}]%*c",LinTemp);
	fscanf(arquivo,"%*r");
    *QuantidadeEstados = RemoveComma(LinTemp,MatrizEstados);
}
/* Le o estado inicial do arquivo
 * Entrada:arquivo a ser lido, vetor de char para armazenar os estados
 * Retorno:Nenhum
 * Pré-condição:Arquivo FILE valido
 * Pós-condição:Nenhum
*/
void LoadInitialState(FILE *arquivo,char *EstadoInicial){
    fscanf(arquivo,"inicial=");
	fscanf(arquivo,"%[^\n]",EstadoInicial);
	fscanf(arquivo,"%*r");
}
/* Le os estados finais do arquivo
 * Entrada:arquivo a ser lido, vetor de char para armazenar os estados
 * Retorno:Nenhum
 * Pré-condição:Arquivo FILE valido
 * Pós-condição:Nenhum
*/
void LoadStateFinal(FILE *arquivo,char *EstadosFinais){
    fscanf(arquivo,"finais=%[^\n]%*r",EstadosFinais);

}

/* Carrega o AFE do arquivo para a memoria
 * Entrada: Ponteiro para ponteoro para um automato, vetor de char
 * Retorno: Nenhum
 * Pré-condição: Arquivo não nulo, caminho valido
 * Pós-condição: Arquivo carregado para a memoria
*/
void readfile(Automato **AutomatoParametro,char caminho[]){

    FILE *arquivo;//Variavel de abertura do arquivo
    char LinTemp[200];
    char caminhodeletar[100]="rm -r ";
    char alfabeto[100];
    char *MatrizEstados[100];
    int QuantidadeEstados=0;
    char EstadoInicial[100];
    char EstadosFinais[300];
    vector<Estado*> EstadoArquivo;
    vector<char> SimbolosLidos;
    vector<Transicao*> Enviador;
    char NomeEstadoAtual[100];
    int NAlfabeto = strlen(alfabeto);
    vector<char> alfabetovector;
    vector<Transicao*> transicoesarquivo;
    vector<int> parametro;
    int transicoes[100][3];
    char EstadoToken[100];
    int QuantidadeTransicoes = 0;

    system("clear");
    caminho = NewFile(caminho);
    arquivo = fopen(caminho,"r");
    system("clear");

	if(arquivo != NULL){
        LoadAlphabet(arquivo,alfabeto);
        RemoveComma(alfabeto);
        LoadState(arquivo,MatrizEstados,&QuantidadeEstados);
        LoadInitialState(arquivo,EstadoInicial);
        LoadStateFinal(arquivo,EstadosFinais);

        char temp;
        char *EstadosTokenTemp[200];
        int NEstadoToken;
        char EstadoTokenNew[100];

        while(!feof(arquivo)){
            fscanf(arquivo,"(%[^,],%c)=",EstadoToken,&temp);
            fscanf(arquivo,"%[^\n]%*r",EstadoTokenNew);
            NEstadoToken = RemoveComma(EstadoTokenNew,EstadosTokenTemp);
            transicoes[QuantidadeTransicoes][0] = IntStateReturn(EstadoToken,MatrizEstados,QuantidadeEstados);
            transicoes[QuantidadeTransicoes][1] = temp;
            transicoes[QuantidadeTransicoes][2] = IntStateReturn(EstadosTokenTemp[0],MatrizEstados,QuantidadeEstados);
            QuantidadeTransicoes++;
            for(int k=1;k<NEstadoToken;k++){
                transicoes[QuantidadeTransicoes][0] = -1;
                transicoes[QuantidadeTransicoes][1] = -1;
                transicoes[QuantidadeTransicoes][2] = IntStateReturn(EstadosTokenTemp[k],MatrizEstados,QuantidadeEstados);
                QuantidadeTransicoes++;
            }
		}
        char simboloparam;
        int esttemp;
        int j=0;
        int NreQuantidadeTransicoes=0;
        for(int i = 0;i<QuantidadeTransicoes;NreQuantidadeTransicoes++,j=0){
            transicoesarquivo.resize(NreQuantidadeTransicoes+1);
            esttemp = transicoes[i][0];
            simboloparam = transicoes[i][1];
            if(transicoes[i+1][1] == -1){
                parametro.resize(j+1);
                parametro[j] = transicoes[i][2];
                i++;
                for(j=1;transicoes[i][1] == -1;j++,i++){
                    parametro.resize(j+1);
                    parametro[j] = transicoes[i][2];
                }
            transicoesarquivo[NreQuantidadeTransicoes] = new Transicao(simboloparam,parametro,parametro.size(),esttemp);
            }else{
                parametro.resize(1);
                parametro[0] = transicoes[i][2];
                transicoesarquivo[NreQuantidadeTransicoes] = new Transicao(simboloparam,parametro,1,esttemp);
                i++;
            }
        }        
        QuantidadeTransicoes = NreQuantidadeTransicoes;        
        NAlfabeto= strlen(alfabeto);
        for(int i = 0;i<QuantidadeEstados;i++){
            strcpy(NomeEstadoAtual,MatrizEstados[i]);
            for(int j=0;j < NAlfabeto;j++){
                SimbolosLidos.resize(j+1);
                if(transicoes[j][0] == i)
                    veccat(SimbolosLidos,transicoes[j][1]);
            }
        Enviador = ConvertTransition(Enviador,transicoesarquivo,NomeEstadoAtual,MatrizEstados,QuantidadeEstados);
        EstadoArquivo.resize(i+1);
        if(strstr(EstadosFinais,NomeEstadoAtual) != NULL){
            if(strcmp(NomeEstadoAtual,EstadoInicial) == 0){
                EstadoArquivo[i] = new Estado(NomeEstadoAtual,i,true,true,SimbolosLidos,    SimbolosLidos.size(),Enviador,Enviador.size());
                }else{
                    EstadoArquivo[i] = new Estado(NomeEstadoAtual,i,false,true,SimbolosLidos,   SimbolosLidos.size(),Enviador,Enviador.size());
                    }
    			}else{
                    if(strcmp(NomeEstadoAtual,EstadoInicial) == 0){
                        EstadoArquivo[i] = new Estado(NomeEstadoAtual,i,true,false,SimbolosLidos,   SimbolosLidos.size(),Enviador,Enviador.size());
    				}else{
                        EstadoArquivo[i] = new Estado(NomeEstadoAtual,i,false,false,SimbolosLidos,  SimbolosLidos.size(),Enviador,Enviador.size());
                    }
    			}	
    		}
        alfabetovector = ChangeChar(alfabeto,alfabetovector);
        *AutomatoParametro = new Automato(alfabetovector,EstadoArquivo,EstadoArquivo.size());

	fclose(arquivo);
    strcat(caminhodeletar,caminho);
    system(caminhodeletar);
	}else{
        cout << "Erro ao abrir o arquivo" << endl;
        cout << "Clique qualquer botao para voltar ao menu"<<endl;
        getchar();
    }
}
