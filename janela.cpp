#include "janela.h"
#include "tabuleiro.h"
#include <iostream>
#include <QtGui>
#include <QtWidgets>

Janela::Janela()
{
    scoreNumber = new QLCDNumber();
    livesNumber = new QLCDNumber();
    prog = new QProgressBar();
    tabuleiro = new Tabuleiro();
    scoreTxt = new QLabel();
    liveTxt = new QLabel();
    highScore = this->getHighScore();
    scoreTxt->setText("Score: ");
    liveTxt->setText("Lives: ");
    scoreNumber->setSegmentStyle(QLCDNumber::Flat);
    livesNumber->setSegmentStyle(QLCDNumber::Flat);
    prog->setMaximum(this->getHighScore());

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(setarProg()));
    timer->start(200);

    layoutH1 = new QHBoxLayout;
    layoutH2 = new QHBoxLayout;
    layoutH3 = new QHBoxLayout;
    layoutH1->addWidget(scoreTxt);
    layoutH1->addWidget(scoreNumber);
    layoutH1->setAlignment(Qt::AlignLeft);
    layoutH2->addWidget(liveTxt);
    layoutH2->addWidget(livesNumber);
    layoutH2->setAlignment(Qt::AlignRight);
    layoutH3->addLayout(layoutH1);
    layoutH3->addLayout(layoutH2);
    mainLayout = new QVBoxLayout;
    mainLayout->addLayout(layoutH3);
    mainLayout->addWidget(tabuleiro);
    mainLayout->addWidget(prog);

    this->setLayout(mainLayout);

}

Janela::~Janela()
{
}

void Janela::keyPressEvent(QKeyEvent* event)
{
    QWidget::keyPressEvent(event); // Notificação para a superclasse
    switch (event->key())
    {
    case Qt::Key_Right:
        tabuleiro->moverCanhaoDireita();
        break;
    case Qt::Key_Left:
        tabuleiro->moverCanhaoEsquerda();
        break;
    case Qt::Key_Space:
        tabuleiro->dispararProjetil();
        break;
    case Qt::Key_R:
        tabuleiro->reset(0, 3);
        break;
    default:
        break;
    }
}

void Janela::paintEvent(QPaintEvent* event) {
    QWidget::paintEvent(event);

    scoreNumber->display(tabuleiro->getScore());
    livesNumber->display(tabuleiro->getVidas());
}

int Janela::getHighScore(){
    QFile file("listaDeScores.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    return 0;

    QTextStream in(&file);
    while (!in.atEnd()) {
    QString line = in.readLine();
    int temp;
    temp = line.section(',',1,1).toInt();
    if(temp>highScore)
        highScore = temp;
    }
    qDebug()<<highScore;
    return highScore;
}

void Janela::setarProg(){
    prog->setValue(tabuleiro->getScore());
}

/*
int Janela::valorProgressBar(){
    int valor = highScore;
    valor = valor * tabuleiro->getScore();
    valor = (int) valor/100;
    return valor;
}*/
