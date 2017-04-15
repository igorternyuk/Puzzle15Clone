#include "lcdcounter.h"

LCDCounter::LCDCounter(Puzzle15Model *model, QWidget *parent) :
QLCDNumber(NUM_DIGIT, parent), model(model)
{
    setFixedSize(120,40);
    setAutoFillBackground(true);
    QPalette pal= palette();
    pal.setColor(QPalette::Normal, QPalette::WindowText, Qt::green);
    pal.setColor(QPalette::Normal, QPalette::Window, Qt::black);
    setPalette(pal);
}

void LCDCounter::displayMoveCount()
{
    display(model->getMovesNumber());
}

void LCDCounter::reset()
{
    display(0);
}
