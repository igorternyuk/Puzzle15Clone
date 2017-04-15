#ifndef LCDCOUNTER_H
#define LCDCOUNTER_H

#include <QLCDNumber>
#include "puzzle15model.h"

class LCDCounter : public QLCDNumber
{
    Q_OBJECT
public:
    enum {NUM_DIGIT = 5};
    LCDCounter(Puzzle15Model *model, QWidget *parent = nullptr);
public slots:
    void displayMoveCount();
    void reset();
private:
    Puzzle15Model *model;
};

#endif // LCDCOUNTER_H
