#ifndef TRABALHO_LINGUAGENS_FORMAIS_E_AUTOMATOS_H
#define TRABALHO_LINGUAGENS_FORMAIS_E_AUTOMATOS_H

#include <QMainWindow>

namespace Ui {
class Trabalho_Linguagens_Formais_e_Automatos;
}

class Trabalho_Linguagens_Formais_e_Automatos : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Trabalho_Linguagens_Formais_e_Automatos(QWidget *parent = 0);
    ~Trabalho_Linguagens_Formais_e_Automatos();
    
private slots:
    void on_pushButton_clicked();
    
    void on_pushButton_3_clicked();
    
    void on_pushButton_2_clicked();
    
    void on_pushButton_4_clicked();
    
    void on_ButtonOk_clicked();
    
private:
    Ui::Trabalho_Linguagens_Formais_e_Automatos *ui;
};

#endif // TRABALHO_LINGUAGENS_FORMAIS_E_AUTOMATOS_H
