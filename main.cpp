#include "janela.h"
#include "ranking.h"
#include <QtWidgets>
#include <QtGui>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Janela win;
    win.show();

return app.exec();
}
