#pragma once
#include "tabuleiro.h"
#include <QtGui>
#include <QtWidgets>

class Janela : public QWidget
{
    Q_OBJECT

public:
    Janela();
    ~Janela();
    QLCDNumber* scoreNumber;
    QLCDNumber* livesNumber;
    QProgressBar* prog;
    Tabuleiro* tabuleiro;
    QLabel* scoreTxt;
    QLabel* liveTxt;
    QHBoxLayout* layoutH1;
    QHBoxLayout* layoutH2;
    QHBoxLayout* layoutH3;
    QVBoxLayout* mainLayout;
    QTimer *timer;
    void keyPressEvent(QKeyEvent* event);
    void paintEvent(QPaintEvent* event);
    Ranking* rank;
    int highScore;
    int valorProgressBar();
    int getHighScore();

public slots:
    void setarProg();


};

