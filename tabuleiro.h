#pragma once
#include "ebe.h"
#include "canhao.h"
#include "ranking.h"
#include <QFrame>
#include <QPushButton>
#include <QtWidgets>

class Tabuleiro : public QFrame
{
    Q_OBJECT

public:
    Tabuleiro(QWidget *parent = 0);
    ~Tabuleiro();
    void paintEvent(QPaintEvent* event);
    void moverCanhaoDireita();
    void moverCanhaoEsquerda();
    void dispararProjetil();
    void destroiProjetil();
    void incrementaScore();
    void reset(int nScore, int nVidas);
    void decrementaVidas();
    int getScore();
    int getVidas();
    Ebe alien[5][8];
    Canhao canhao;
    int pos_x1;
    int pos_x2;
    int pos_y;
    int posicao_canhao;
    bool direcao_movimento;
    bool disparar;
    int pos_x_disparo;
    int pos_y_disparo;
    bool mortos[5][8];
    int score;
    int vidas;
    int contadorTempo;
    QBrush cores[5][8];
    Ranking* rank;


public slots:
};
