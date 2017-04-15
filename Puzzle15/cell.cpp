#include "cell.h"
#include "defines.h"

Cell::Cell(int cellNumber, QWidget *parent):
 QPushButton(QString::number(cellNumber),parent),
 cellNumber(cellNumber)
{    
    setFixedSize(BUTTON_WIDTH, BUTTON_HEIGHT);
    setColor(QColor(170,170,255));
}

Cell::Cell(int cellNumber, QPixmap *pict, int complexity, int row, int col, QWidget *parent):
 QPushButton(QString::number(cellNumber), parent), cellNumber(cellNumber)
{
   setPicture(pict, complexity, row, col);
}

void Cell::setColor(QColor color)
{
    setStyleSheet(QString("font-size: 20pt;font-weight:bold"));
    QPalette palette = this->palette();
    setAutoFillBackground(true);
    palette.setColor(QPalette::Button, color);
    setPalette(palette);
    update();
}

void Cell::setPicture(QPixmap *picture, int complexity, int row, int col)
{
   // QPixmap *picture = new QPixmap(":/images/iris.jpg");
    int iconSize = floor(PUZZLE_PICTURE_SIZE / complexity);
    QPixmap btnIcon = picture->copy(col * iconSize, row * iconSize,
                                    iconSize, iconSize);
    setFixedSize(iconSize, iconSize);
    QIcon ButtonIcon(btnIcon);
    setIcon(ButtonIcon);
    setIconSize(QSize(iconSize, iconSize));
    setText("");
}
