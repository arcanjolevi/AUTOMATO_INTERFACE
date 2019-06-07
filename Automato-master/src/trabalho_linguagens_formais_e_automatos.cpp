#include "trabalho_linguagens_formais_e_automatos.h"
#include "ui_trabalho_linguagens_formais_e_automatos.h"
#include <QString>
#include <QFileDialog>
Automato * AFE;
Automato * AFD;

Trabalho_Linguagens_Formais_e_Automatos::Trabalho_Linguagens_Formais_e_Automatos(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Trabalho_Linguagens_Formais_e_Automatos)
{
    ui->setupUi(this);
}

Trabalho_Linguagens_Formais_e_Automatos::~Trabalho_Linguagens_Formais_e_Automatos()
{
    delete ui;
}


/* Função ativada quando o botao Carregar AFD for clicado
 * filename tem o diretorio do arquivo
  * se quizer transformar pra char, usar strcpy(sua variavel char, filename.toStdString().c_str());
 */
void Trabalho_Linguagens_Formais_e_Automatos::on_pushButton_clicked()
{
   QString filename;
    QByteArray temp;
    char * temp2;
    filename = QFileDialog::getOpenFileName(this, tr("Abrir ficheiro"), "/home/", tr("Text files (*.txt)"));
    temp = filename.toLocal8Bit();
    temp2 = temp.data();
    AFD = NULL; readfile(&AFD,temp2);
    //ui->textBrowser->setText(AFD->show);  
}


/* Função ativada quando o botao processar Palavra for clicado
 * Apenas irá aparecer a msg: "Digite a palavra"
 */
void Trabalho_Linguagens_Formais_e_Automatos::on_pushButton_3_clicked()//Processar palavra
{
    ui->label->setText("Digite a palavra");
}

/* Função ativada quando o botao Carregar e Converter Automato for clicado
 * filename tem o diretorio do arquivo
 * se quizer transformar pra char, usar strcpy(sua variavel char, filename.toStdString().c_str());
 * chamar função de conversão e o show do automato
 */
void Trabalho_Linguagens_Formais_e_Automatos::on_pushButton_2_clicked()
{
    QString filename;
    QByteArray temp;
    char * temp2;
    filename = QFileDialog::getOpenFileName(this, tr("Abrir ficheiro"), "/home/", tr("Text files (*.txt)"));
    temp = filename.toLocal8Bit();
    temp2 = temp.data();
    AFE = NULL; readfile(&AFE,temp2);
    AFD = convertAFEtoAFD(AFE);
    ui->textBrowser->setText(AFD->show());  
}


/* Botão Sair
 */
void Trabalho_Linguagens_Formais_e_Automatos::on_pushButton_4_clicked()
{
    this->close();
}


/* Função ativada quando o botao ok for clicado
 * char texto tem a palavra
 * chamar a função para processar a palavra e colocar 
 * na QString a para ser apresentada na tela
 */
void Trabalho_Linguagens_Formais_e_Automatos::on_ButtonOk_clicked()
{       
        char temp[1000];
        strcpy(temp,"/home/faculdade/automato.txt");
        readfile(&AFD,temp);
        char texto[1000];
        QString a;
        a = ui->lineEdit->text();
        strcpy(texto, a.toStdString().c_str());
        //colocar aqui função para processar palavra
        a = QString::fromStdString(process(texto,AFD));
        ui->textBrowser->setText(a);
}
