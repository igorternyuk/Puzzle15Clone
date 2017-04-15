#include "puzzle15view.h"
#include <QMessageBox>
#include <QDebug>

namespace InfoMessages {
QString infoAboutGame = "The 15-puzzle is a sliding puzzle that consists of"
                        " a frame of numbered square tiles in random order with"
                        " one tile missing. The object of the puzzle is to place"
                        " the tiles in order or to assemble the puzzle by making"
                        " sliding moves that use the empty space.";
QString helpInfo =      "Move the tiles using left mouse click on corrensponding tile or "
                        "with hot keys: 'a' - to move left, 'd' - to move right, "
                        "'w' - to move up, 's' - to move down, 'n' - for starting new game, "
                        "q - for close application. You can change number of tile by using "
                        "spinbox";
QString infoAboutAuthor = "Ternyuk Igor Olexandrovytch, Ukraine";
}
Puzzle15View::Puzzle15View(Puzzle15Model *pm, bool isPicture, QWidget *parent) :
QWidget(parent), mPuzzle15(pm)
{
    grid = new QGridLayout(this);
    //grid->setSizeConstraint();
    grid->setContentsMargins(0, 0, 0, 0);
    grid->setSpacing(GRID_SPACING);
    init(isPicture, nullptr, DEFAULT_ROW_COUNT);
    connect(mPuzzle15, SIGNAL(gameBoardChanged()),
            this, SLOT(update()));
}

void Puzzle15View::init(bool isPicture, QPixmap *picture, int complexity)
{
    if(!cells.isEmpty())
    {
        int size = cells.size();
        for(int id = 1; id <= size; ++id)
            delete cells.take(id);
    }
    for(int r = 0; r < mPuzzle15->getRowCount(); ++r)
        for(int c = 0; c < mPuzzle15->getColumnCount(); ++c)
        {
            int id = mPuzzle15->getCell(r, c);
            if(id != 0)
            {
                Cell *cell;
                if(isPicture)
                {
                    int row = floor((id - 1) / complexity);
                    int col = (id - 1) % complexity;
                    cell = new Cell(id, picture, complexity, row, col);
                    grid->setSpacing(GRID_SPACING_BETWEEN_PICTURE_TILES);
                }
                else
                {
                    cell = new Cell(id);
                    grid->setSpacing(GRID_SPACING);
                }
                connect(cell, SIGNAL(clicked(bool)), this, SLOT(tryToMove()));
                cells.insert(id, cell);
                grid->addWidget(cells[id], r, c);
            }
        }
     qDebug() << "Количество кнопок : " << cells.size();
     mPuzzle15->printBoard();
}

void Puzzle15View::update()
{
    for(int id = 1; id < mPuzzle15->getRowCount() * mPuzzle15->getColumnCount(); ++id)
       grid->removeWidget(cells[id]);
    qDebug() << "Очитстка массива кнопок";
    fillGridByCells();
}

void Puzzle15View::fillGridByCells()
{
    for(int r = 0; r < mPuzzle15->getRowCount(); ++r)
        for(int c = 0; c < mPuzzle15->getColumnCount(); ++c)
        {
            int id = mPuzzle15->getCell(r, c);
            if(id != 0)
            {
                grid->addWidget(cells[id], r, c);
            }
        }
     qDebug() << "Количество кнопок : " << cells.size();
     mPuzzle15->printBoard();
}

void Puzzle15View::tryToMove()
{
    Cell* clickedCell = static_cast<Cell*>(sender());
    mPuzzle15->makeMoveByCellNumber(clickedCell->getCellNumber());
}

void Puzzle15View::showInfoAboutGame()
{
   QString text = InfoMessages::infoAboutGame;
   QMessageBox::about(this, "Information about game", text);
}

void Puzzle15View::showInfoAboutAuthor()
{
   QString text = InfoMessages::infoAboutAuthor;
   QMessageBox::about(this, "Information about author", text);
}

void Puzzle15View::showHelp()
{
   QString text = InfoMessages::helpInfo;
   QMessageBox::about(this, "Help", text);
}
