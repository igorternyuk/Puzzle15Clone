#ifndef CELL_H
#define CELL_H

#include <QPushButton>

class Cell : public QPushButton
{
   Q_OBJECT

private:
    void setColor(QColor color);
    void setPicture(QPixmap *picture, int complexity, int row, int col);
public:
    Cell(int cellNumber, QWidget *parent = nullptr);
    Cell(int cellNumber, QPixmap *pict, int complexity,
         int row,  int col, QWidget *parent = nullptr);
    int getCellNumber() {return cellNumber;}
    //QPixmap *getPicture() {return picture;}
private:
    int cellNumber;
};

#endif // CELL_H
