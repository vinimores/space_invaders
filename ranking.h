#pragma once
#include <QFrame>
#include <QPushButton>
#include <QtWidgets>
#include <QtGui>

class Ranking : public QFrame
{
    Q_OBJECT

public:
    Ranking(QWidget *parent = 0);
    Ranking(int score);
    ~Ranking();
    QHBoxLayout* layoutH1;
    QHBoxLayout* layoutH2;
    QVBoxLayout* layoutV;
    QLabel* texto;
    QLineEdit* nome;
    QPushButton* ok;
    QPushButton* cancelar;
    int score;


public slots:
    void salvar();
};
