#ifndef PUZZLE15VIEW_H
#define PUZZLE15VIEW_H

#include <QWidget>
#include <QGridLayout>
#include <QAbstractButton>
#include <QPushButton>
#include <QButtonGroup>
#include <QMap>
#include "puzzle15model.h"
#include "defines.h"
#include "cell.h"

class Puzzle15View : public QWidget
{
    Q_OBJECT
public:
    Puzzle15View(Puzzle15Model *pm, bool isPicture, QWidget *parent = nullptr);
public slots:
    void init(bool isPicture, QPixmap *picture, int complexity);
    void update();
    void showInfoAboutGame();
    void showInfoAboutAuthor();
    void showHelp();
private slots:
    void fillGridByCells();
    void tryToMove();
private:
    Puzzle15Model *mPuzzle15;
    QGridLayout *grid;
    QMap<int, Cell*> cells;
};

#endif // PUZZLE15VIEW_H
