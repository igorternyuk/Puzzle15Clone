#include "lcdtimer.h"

LCDTimer::LCDTimer(QWidget *parent):
    QLCDNumber(NUM_DIGIT, parent)
{
    timer = new QTimer(this);
    timeElapsed = new QTime(0,0,0);
    setFixedSize(120, 40);
    setAutoFillBackground(true);
    QPalette pal = palette();
    pal.setColor(QPalette::Normal, QPalette::WindowText, Qt::green);
    pal.setColor(QPalette::Normal, QPalette::Window, Qt::black);
    setPalette(pal);
    display("00:00:00");
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
}

LCDTimer::~LCDTimer()
{
    delete timeElapsed;
}

void LCDTimer::reset()
{
    timeElapsed->setHMS(0, 0, 0);
    display("00:00:00");
    timer->start(1000);
}

void LCDTimer::startTimer()
{
    timer->start(1000);
}

void LCDTimer::stopTimer()
{
    timer->stop();
}

void LCDTimer::update()
{
    *timeElapsed = timeElapsed->addMSecs(1000);
    QString timeStr = timeElapsed->toString("hh:mm:ss");
    display(timeStr);
}
