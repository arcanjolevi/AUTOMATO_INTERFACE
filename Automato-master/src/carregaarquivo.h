#ifndef CARREGAARQUIVO_H
#define CARREGAARQUIVO_H 

/* carregaafd.h
* VERSÃO: 1.8
* ULTIMO EDITOR: Lucas
* DATA: 06/06/2019
* HORA: 21:24
* LISTA DE ARQUIVOS UTILIZADOS NA BIBLIOTECA:
* - automato.h
* - transicao.h
* - estado.h
*/

#include "automato.h"
#include "transicao.h"
#include "estado.h"
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

/* Copia tudo que contem em um vetor de char para um vector de char
 * Entrada: Vetor de char, vector de char
 * Retorno: Nenhum
 * Pré-condição: ventor enviador não nulo
 * Pós-condição: Nenhum
*/
vector<char> ChangeChar(char enviador[],vector<char> recebedor);

/* Removedor de virgula
 * Entrada: Vetor de char, uma matriz de char
 * Retorno: tamanho da matriz
 * Pré-condição: nenhuma
 * Pós-condição: A matriz preenchida com as palavras entre as virgulas do vetor de char
*/
int RemoveComma(char *s,char *retorno[]);


/* Remove as virgulas e abre fecha chaves de uma string
 * Entrada: Vetor de char
 * Retorno: Nenhum
 * Pré-condição: nenhuma
 * Pós-condição: vetor sem virgulas , abre e fecha chaves
*/
void RemoveComma(char *s);

/* Selecionador de posição
 * Entrada: Ponteiro para char, Vetor de ponteiros para char, inteiro com quantidade de colunas da matriz
 * Retorno: posição do estado na matriz
 * Pré-condição: Palavra chave valida
 * Pós-condição: nenhuma
*/

int IntStateReturn(char *EstadoTokens,char *Estado[],int QuantidadeEstados);

/* Concatena um inteiro num vector de char
 * Entrada: vector de char, e um inteiro
 * Retorno: nenhum
 * Pré-condição: Nenhuma
 * Pós-condição: Nenhuma
*/
void veccat(vector<char> Recebedora,int Enviadora);


/* Cria um vector de transiçoes auxiliar
 * Entrada: vector de ponteiro apra transicao,vector de ponteiro apra transicao,vetor de char com o nome do estado atual, uma matriz de char com os nomes dos estados, e um inteiro com a quantiade de estados
 * Retorno: Vector de Transicoes auxiliar
 * Pré-condição: Nenhum valor de entrada nullo
 * Pós-condição: Nenhuma
*/
vector<Transicao*> ConvertTransition(vector<Transicao*> Recebedor,vector<Transicao*>Enviador,char *NomeEstado,char **MatrizEstados,int QuantidadeEstados);


/* Removedor de espaços
 * Entrada: Vetor de char
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: O vetor sem espaços em branco.
*/
void removeSpaces(char s[]);

/* Cria um novo arquivo com tratamentos 
 * Entrada: Caminho do arquivo
 * Retorno: Caminho do novo arquivo tratado
 * Pré-condição: Caminho de arquivo valido
 * Pós-condição: Nenhum
*/
char* NewFile(char *OldArquivo);

/* Le o alfabeto
 * Entrada:arquivo a ser lido, vetor de char para armazenar o alfabeto
 * Retorno:Nenhum
 * Pré-condição:Arquivo FILE valido
 * Pós-condição:Nenhum
*/
void LoadAlphabet(FILE *arquivo,char *alfabeto);

/* Le os estados
 * Entrada:arquivo a ser lido, vetor de ponteiros para char que armazena os estados,inteiro com a quantidade de estados na matriz
 * Retorno:Nenhum
 * Pré-condição:Arquivo FILE valido
 * Pós-condição:Nenhum
*/
void LoadState(FILE *arquivo,char *MatrizEstados[],int *QuantidadeEstados);


/* Le o estado inicial do arquivo
 * Entrada:arquivo a ser lido, vetor de char para armazenar os estados
 * Retorno:Nenhum
 * Pré-condição:Arquivo FILE valido
 * Pós-condição:Nenhum
*/
void LoadInitialState(FILE *arquivo,char *EstadoInicial);

/* Le os estados finais do arquivo
 * Entrada:arquivo a ser lido, vetor de char para armazenar os estados
 * Retorno:Nenhum
 * Pré-condição:Arquivo FILE valido
 * Pós-condição:Nenhum
*/
void LoadStateFinal(FILE *arquivo,char *EstadosFinais);

/* Carrega o AFE do arquivo para a memoria
 * Entrada: Ponteiro para ponteoro para um automato, vetor de char
 * Retorno: Nenhum
 * Pré-condição: Arquivo não nulo, caminho valido
 * Pós-condição: Arquivo carregado para a memoria
*/
void readfile(Automato **AutomatoParametro,char caminho[]);

#endif
