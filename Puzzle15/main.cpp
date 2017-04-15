#include <QtGui>
#include <QApplication>
#include <QMainWindow>
#include <QDesktopWidget>
#include "puzzle15controller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");
    Puzzle15Controller *controller = new Puzzle15Controller();
    QRect myScreenGeometry = QApplication::desktop()->geometry() ;
            int dx = (myScreenGeometry.width() - controller->width()) / 2;
            int dy = (myScreenGeometry.height() - controller->height()) / 2;
    controller->move(dx, dy);
    controller->show();
    return a.exec();
}
