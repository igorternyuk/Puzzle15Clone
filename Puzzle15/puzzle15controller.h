#ifndef PUZZLE15CONTROLLER_H
#define PUZZLE15CONTROLLER_H

#include <QApplication>
#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QPushButton>
#include <QMessageBox>
#include <QKeyEvent>
#include <Qt>
#include "puzzle15model.h"
#include "puzzle15view.h"
#include "lcdtimer.h"
#include "lcdcounter.h"
#include "defines.h"

/*Это наш контроллер*/

class Puzzle15Controller: public QMainWindow
{
    Q_OBJECT
public:
    Puzzle15Controller(QMainWindow *parent = nullptr);
    QString getPictureName();
signals:
    void puzzleStart();
protected:
    void keyPressEvent(QKeyEvent *event);
private slots:
    void newGame();
    void reset();
    void showStats();
private:
    Puzzle15Model *model; // Модель
    // И три вьювера
    Puzzle15View *view;
    LCDTimer *timer;
    LCDCounter *counter;
    //Элементы интерфейса
    QLabel *labelTimeElapsed;
    QLabel *labelNumberOfMoves;
    QLabel *labelNumberOfRows;
    QLabel *labelNumberOfColumns;
    QSpinBox *spinBoxNumberOfRows;
    QSpinBox *spinBoxNumberOfColumns;
    QLabel *labelGameType;
    QComboBox *gameType;
    QLabel *labelChoosePicture;
    QComboBox *ComboBoxChoosingPicture;
    QPushButton *newGameButton;
    QPushButton *exitButton;
    QLabel *labelPictPuzzleComplexity;
    QSpinBox *spinBoxPictPuzzleComplexity;
};

#endif // PUZZLE15CONTROLLER_H
