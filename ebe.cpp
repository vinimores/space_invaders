#include "ebe.h"
#include <QtGui>
#include <QtWidgets>

Ebe::Ebe()
{
    draw_shape1 = true;
}
Ebe::~Ebe()
{
}

void Ebe::draw(int x, int y, QPainter& painter, const QBrush& brush) {
    _pos_x = x;
    _pos_y = y;
    /* head */
    painter.fillRect(x+12, y, 8, 4, brush);
    painter.fillRect(x+8, y+4, (8*2), 4, brush);
    painter.fillRect(x+4, y+8, (8*3), 4, brush);
    /* eyes */
    painter.fillRect(x, y+12, 8, 4, brush);
    painter.fillRect(x+12, y+12, 8, 4, brush);
    painter.fillRect(x+24, y+12, 8, 4, brush);
    /* chin */
    painter.fillRect(x, y+16, (8*4), 4, brush);

    if (draw_shape1)
    {
    draw_shape1 = false;
    /* hips */
    painter.fillRect(x+8, y+20, 5, 4, brush);
    painter.fillRect(x+18, y+20, 5, 4, brush);
    /* legs part 1 */
    painter.fillRect(x+4, y+24, 5, 4, brush);
    painter.fillRect(x+12, y+24, 7, 4, brush);
    painter.fillRect(x+22, y+24, 5, 4, brush);
    /* legs part 2 */
    painter.fillRect(x, y+28, 5, 4, brush);
    painter.fillRect(x+8, y+28, 5, 4, brush);
    painter.fillRect(x+18, y+28, 5, 4, brush);
    painter.fillRect(x+26, y+28, 5, 4, brush);
    } else {
        draw_shape1 = true;
        /* hips */
        painter.fillRect(x+3, y+20, 5, 4, brush);
        painter.fillRect(x+12, y+20, 8, 4, brush);
        painter.fillRect(x+24, y+20, 5, 4, brush);
        /* legs part 1 */
        painter.fillRect(x, y+24, 5, 4, brush);
        painter.fillRect(x+27, y+24, 5, 4, brush);
        /* legs part 2 */
        painter.fillRect(x+3, y+28, 5, 4, brush);
        painter.fillRect(x+24, y+28, 5, 4, brush);
    }
}

int Ebe::x()
{
    return _pos_x;
}
int Ebe::y()
{
    return _pos_y;
}
