#include "menu.h"


Automato *Aut;//Automato que recebera o conteudo do arquivo

/* Função que pega um digito sem a necessidade do enter
 * Entrada: Nenhum
 * Retorno: Caracatere pego
 * Pré-condição: Nenhum
 * Pós-condição: Nenhum
*/
char getchChar(){
    char buf=0;
    struct termios old={0};
    fflush(stdout);
    if(tcgetattr(0, &old)<0)
        perror("tcsetattr()");
    old.c_lflag&=~ICANON;
    old.c_lflag&=~ECHO;
    old.c_cc[VMIN]=1;
    old.c_cc[VTIME]=0;
    if(tcsetattr(0, TCSANOW, &old)<0)
        perror("tcsetattr ICANON");
    if(read(0,&buf,1)<0)
        perror("read()");
    old.c_lflag|=ICANON;
    old.c_lflag|=ECHO;
    if(tcsetattr(0, TCSADRAIN, &old)<0)
        perror ("tcsetattr ~ICANON");
    return buf;
}


/* Função auxiliar que ajuda a movimentação no menu
 * Entrada: Ponteiro para variavel de controle, valor digitado, primeiro elemento do menu e ultimo elemento do menu
 * Retorno: true caso caractere seja enter e false caso não seja
 * Pré-condição: Nenhum
 * Pós-condição: A posição correta do menu é retornada
*/
bool movmentMenu(int teclaPressionada, int *posicaoDoMenu, int primeiro, int ultimo){
    if( (teclaPressionada == TECLAPARACIMA1 || teclaPressionada == TECLAPARACIMA2) && *posicaoDoMenu != primeiro){
        *posicaoDoMenu-=1;
    }else if( (teclaPressionada == TECLAPARABAIXO1 || teclaPressionada == TECLAPARABAIXO2) && *posicaoDoMenu != ultimo){
        *posicaoDoMenu+=1;
    }else if( (teclaPressionada == TECLAPARACIMA1 || teclaPressionada == TECLAPARACIMA2) && *posicaoDoMenu == primeiro){
        *posicaoDoMenu = ultimo;
    }else if( (teclaPressionada == TECLAPARABAIXO1 || teclaPressionada == TECLAPARABAIXO2) && *posicaoDoMenu == ultimo){
        *posicaoDoMenu = primeiro;
    }else if(teclaPressionada == ENTER){
        return true;
    }else
        return false;
}


/* Função que mostra na tela o menu base
 * Entrada: Variavel de controle do menu
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: O menu base é executado
*/
void mainMenu(int *var){
    char teclaPressionada = 0;
    int parteDoMenu = 0;
    int inicioMenu = 0; int fimMenu = 2;
    while(teclaPressionada != 10){
        system("clear");
        printf("\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t\t\t\t ________________________________________________________\n\t\t\t\t\t\t\t\t| \t\t\t\t\t\t\t |\n");
        printf("\t\t\t\t\t\t\t\t|\tUtilize w e s para se movimentar no menu         |\n");
        printf("\t\t\t\t\t\t\t\t|________________________________________________________|\n\t\t\t\t\t\t\t\t| \t\t\t\t\t\t\t |\n\t\t\t\t\t\t\t\t| \t\t\t\t\t\t\t |\n");
        if(parteDoMenu == 0){
            printf("\t\t\t\t\t\t\t\t|-> Carregar e executar AFD. %-25s[%c]|\n"," ",'*');
            printf("\t\t\t\t\t\t\t\t|-> Carregar e exibe AFE. %-28s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Sair %-45s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|________________________________________________________|\n\n\n");

            teclaPressionada = getchChar();
            if(movmentMenu(teclaPressionada,&parteDoMenu,inicioMenu,fimMenu)){
                *var = CARREGAAFD;
            }
        }else if(parteDoMenu == 1){
            printf("\t\t\t\t\t\t\t\t|-> Carregar e executar AFD. %-25s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Carregar e exibe AFE. %-28s[%c]|\n"," ",'*');
            printf("\t\t\t\t\t\t\t\t|-> Sair %-45s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|________________________________________________________|\n\n\n");

            teclaPressionada = getchChar();
            if(movmentMenu(teclaPressionada,&parteDoMenu,inicioMenu,fimMenu)){
                *var = CARREGAAFE;
            }
        }else if(parteDoMenu == 2){
            printf("\t\t\t\t\t\t\t\t|-> Carregar e executar AFD. %-25s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Carregar e exibe AFE. %-28s[%c]|\n"," ",' ');
            printf("\t\t\t\t\t\t\t\t|-> Sair %-45s[%c]|\n"," ",'*');
            printf("\t\t\t\t\t\t\t\t|________________________________________________________|\n\n\n");

            teclaPressionada = getchChar();
            if(movmentMenu(teclaPressionada,&parteDoMenu,inicioMenu,fimMenu)){
                *var = SAIRDOPROGRAMA;
            }                
        }
    }
}

/* Função que executa os menus
 * Entrada: Nenhum
 * Retorno: Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: O menu é executado
*/
void deciderMenu(){
    int MENU = 1; //Variável de decisão do menu
    char decide=NULL;
    while(MENU != SAIRDOPROGRAMA){ //Enquanto var for diferente de 0
        if(MENU == MENUPRINCIPAL){ //Entra no menu principal
            mainMenu(&MENU);
        }else if(MENU == CARREGAAFD){ //Carrega e executa AFD                    *função
            readfile(&Aut);
            //process(Aut);
            MENU = MENUPRINCIPAL;
        }else if(MENU == CARREGAAFE){ //Carrega converte e executa AFE           *função
            readfile(&Aut);
            Aut = convertAFEtoAFD(Aut);
            Aut->show();
            while(1){
            cout << endl <<"Aperte r se deseja processar a cadeia ou aperte q para voltar ao menu\n:";
            decide = getchChar();
            if(decide == 'q')
                break;
            else if(decide == 'a'){
                //process(Aut); 
            }
            decide = NULL;
            MENU = MENUPRINCIPAL;
        }
    }
    system("clear");

    cout << "Clique qualquer tecla para fechar" << endl;
}}
