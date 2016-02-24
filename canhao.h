#pragma once
#include <QPainter>

class Canhao
{
public:
    Canhao();
    ~Canhao();

    void draw(int x, int y, QPainter& painter, const QBrush& brush);
    int x();
    int y();

private:
    int _pos_x;
    int _pos_y;
};
