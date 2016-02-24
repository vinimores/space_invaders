#include "tabuleiro.h"
#include "ranking.h"
#include <QVBoxLayout>
#include <QKeyEvent>
#include <iostream>
#include <QtGui>
#include <QtWidgets>


Tabuleiro::Tabuleiro(QWidget* parent)
    : QFrame(parent)
{
    setFixedSize(700,500);
    setFrameStyle(QFrame::Box);
    pos_x1 = 195;
    pos_x2 = 195;
    pos_y = 20;
    direcao_movimento = false;
    posicao_canhao = 325;
    disparar = false;
    pos_x_disparo = 700;
    pos_y_disparo = 500;
    contadorTempo = 0;
    score = 0;
    vidas = 1;

    for(int x=0; x < 8; x++){
            cores[0][x] = QBrush(Qt::red);
            cores[1][x] = QBrush(Qt::darkMagenta);
            cores[2][x] = QBrush(Qt::yellow);
            cores[3][x] = QBrush(Qt::blue);
            cores[4][x] = QBrush(Qt::lightGray);
    }

    for(int y=0; y < 5; y++){
        for(int x=0; x < 8; x++){
            mortos[y][x] = false;
        }
    }
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(10);
}

Tabuleiro::~Tabuleiro()
{

}

void Tabuleiro::paintEvent(QPaintEvent* event) {
    QFrame::paintEvent(event);

    QPainter painter(this);
    if(vidas <= 0){
        rank = new Ranking(this->getScore());
        reset(0, 3);
        rank->show();
    }

    if(direcao_movimento){
        pos_x1 -= 1;
        pos_x2 += 1;
    } else {
        pos_x1 += 1;
        pos_x2 -= 1;
    }

    if(pos_x1>=360){
        direcao_movimento = true;
    } else if(pos_x1<=20){
        direcao_movimento = false;
    }

    painter.fillRect(0, 0, 750, 500, Qt::black);

    for(int y=0; y < 5; y++){
    for(int x=0; x < 8; x++){
        if(!mortos[y][x]){
        if( pos_x_disparo >= alien[y][x].x() && pos_x_disparo <= (alien[y][x].x()+32) ){
            if( pos_y_disparo >= alien[y][x].y() && pos_y_disparo <= (alien[y][x].y()+28) ){
                //COLISÃO
                mortos[y][x] = true;
                destroiProjetil();
                incrementaScore();
            } else {
                if(y%2){
                if(!mortos[y][x]){
                    alien[y][x].draw(pos_x1+(x*40), pos_y+(y*40), painter, cores[y][x]);
                }
                } else {
                    if(!mortos[y][x]){
                        alien[y][x].draw(pos_x2+(x*40), pos_y+(y*40), painter, cores[y][x]);
                    }
                }
            }
         } else {
            if(y%2){
            if(!mortos[y][x]){
                alien[y][x].draw(pos_x1+(x*40), pos_y+(y*40), painter, cores[y][x]);
            }
            } else {
                if(!mortos[y][x]){
                    alien[y][x].draw(pos_x2+(x*40), pos_y+(y*40), painter, cores[y][x]);
                }
            }
        }
        //Verifica se atinge a linha verde
        if(alien[y][x].y()>436){
               decrementaVidas();
               reset(score, vidas);
        }
    }
    }
    }

    //Desenha o canhão
    canhao.draw(posicao_canhao, 440, painter, QBrush(Qt::green));
    //Desenha a linha
    painter.fillRect(20, 470, 660, 4, Qt::green);
    //Desenha o projetil e movimenta
    if(disparar == true){
       painter.fillRect(pos_x_disparo, pos_y_disparo, 2, 8, Qt::green);
       pos_y_disparo -= 9;
       if(pos_y_disparo<=8){
           disparar = false;
       }
    }
    //Controla velocidade de descida dos aliens
    if(score>=500 && score<1000){
        contadorTempo = contadorTempo + 80;
        if(contadorTempo>=3000){
            pos_y += 10;
            contadorTempo = 0;
        }
    } else if(score>=1000 && score<1600){
        contadorTempo = contadorTempo + 80;
        if(contadorTempo>=2400){
            pos_y += 10;
            contadorTempo = 0;
        }
    } else if (score>=1600 && score<2200){
        contadorTempo = contadorTempo + 80;
        if(contadorTempo>=1800){
            pos_y += 10;
            contadorTempo = 0;
        }
    } else if (score>=2200 && score<2900){
        contadorTempo = contadorTempo + 80;
        if(contadorTempo>=1400){
            pos_y += 10;
            contadorTempo = 0;
        }
    } else if (score>=2900){
        contadorTempo = contadorTempo + 80;
        if(contadorTempo>=1000){
            pos_y += 10;
            contadorTempo = 0;
        }
    }


}


void Tabuleiro::moverCanhaoDireita(){
    if(posicao_canhao<=630)
    posicao_canhao += 5;
}

void Tabuleiro::moverCanhaoEsquerda(){
    if(posicao_canhao>=20)
    posicao_canhao -= 5;
}

void Tabuleiro::dispararProjetil(){
    if(disparar==false){
    pos_x_disparo = canhao.x()+24;
    pos_y_disparo = canhao.y()-15;
    disparar = true;
    }
}

void Tabuleiro::destroiProjetil(){
    pos_x_disparo = 0;
    pos_y_disparo = 0;
}

void Tabuleiro::incrementaScore(){
    score += 100;
}

int Tabuleiro::getScore(){
    return score;
}

void Tabuleiro::decrementaVidas(){
    vidas -= 1;
}

int Tabuleiro::getVidas(){
    return vidas;
}

void Tabuleiro::reset(int nScore, int nVidas){
    pos_x1 = 190;
    pos_x2 = 190;
    pos_y = 20;
    direcao_movimento = false;
    posicao_canhao = 325;
    disparar = false;
    pos_x_disparo = 700;
    pos_y_disparo = 500;
    contadorTempo = 0;
    score = nScore;
    vidas = nVidas;
    for(int y=0; y < 5; y++){
        for(int x=0; x < 8; x++){
            mortos[y][x] = false;
        }
    }
}
