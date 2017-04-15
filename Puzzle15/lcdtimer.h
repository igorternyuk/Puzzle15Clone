#ifndef LCDTIMER_H
#define LCDTIMER_H

#include <QWidget>
#include <QLCDNumber>
#include <QTimer>
#include <QTime>

class LCDTimer : public QLCDNumber
{
    Q_OBJECT
public:
    enum {NUM_DIGIT = 8};
    LCDTimer(QWidget *parent = nullptr);
    ~LCDTimer();
    const QTime* time() const {return timeElapsed;}
    void reset();
private slots:
    void startTimer();
    void stopTimer();
    void update();
private:
    QTimer *timer;
    QTime *timeElapsed;
};

#endif // LCDTIMER_H
