#pragma once
#include <QPainter>

// Extraterrestrial Biological Entity
class Ebe
{
public:
    Ebe();
    ~Ebe();

    void draw(int x, int y, QPainter& painter, const QBrush& brush);
    int x();
    int y();

private:
    int _pos_x;
    int _pos_y;
    bool draw_shape1;
};
