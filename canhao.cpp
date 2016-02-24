#include "canhao.h"
#include <QtGui>
#include <QtWidgets>

Canhao::Canhao()
{
}
Canhao::~Canhao()
{
}

void Canhao::draw(int x, int y, QPainter& painter, const QBrush& brush) {
    _pos_x = x;
    _pos_y = y;
    /* ponta */
    painter.fillRect(x+24, y-11, 2, 4, brush);
    /* meio 1 */
    painter.fillRect(x+20, y-7, 10, 4, brush);
    /* meio 2 */
    painter.fillRect(x+5, y-3, 40, 3, brush);
    /* base */
    painter.fillRect(x, y, 50, 13, brush);
}

int Canhao::x()
{
    return _pos_x;
}
int Canhao::y()
{
    return _pos_y;
}
