#include "ranking.h"
#include "tabuleiro.h"
#include <QtGui>
#include <QtWidgets>


Ranking::Ranking(int pScore)
    :QFrame()
{
    texto = new QLabel();
    nome = new QLineEdit();
    ok = new QPushButton();
    score = pScore;
    texto->setText("Digite seu nome: ");
    ok->setText("Salvar");
    QObject::connect(ok, SIGNAL(clicked()), this, SLOT(salvar()));
    layoutH1 = new QHBoxLayout();
    layoutH2 = new QHBoxLayout();
    layoutV = new QVBoxLayout();
    layoutH1->addWidget(texto);
    layoutH1->addWidget(nome);
    layoutH2->addWidget(ok);
    layoutH2->setAlignment(Qt::AlignRight);
    layoutV->addLayout(layoutH1);
    layoutV->addLayout(layoutH2);

    this->setLayout(layoutV);

}

Ranking::~Ranking()
{

}

void Ranking::salvar(){
    this->hide();
    QFile file("listaDeScores.txt");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
    return;

    QTextStream out(&file);
    out << nome->text() <<","<< score <<"\n";

    qDebug()<<"Funcionou!"<< nome->text() << "\n"<< score <<"\n";
}
