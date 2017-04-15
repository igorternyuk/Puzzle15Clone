#include <QtWidgets>
#include "puzzle15controller.h"

Puzzle15Controller::Puzzle15Controller(QMainWindow *parent) :
    QMainWindow(parent)
{
    model = new Puzzle15Model(); // Модель
    //Три вьювера
    view = new Puzzle15View(model, false, this);
    timer = new LCDTimer();
    counter = new LCDCounter(model);
    connect(this, SIGNAL(puzzleStart()), timer, SLOT(startTimer()));
    connect(model, SIGNAL(puzzleSolved()), timer, SLOT(stopTimer()));
    connect(model, SIGNAL(gameBoardChanged()), counter, SLOT(displayMoveCount()));
    QMenu *fileMenu = menuBar()->addMenu("&File");
    QAction *newGameAction = fileMenu->addAction("&NewGame");
    QAction *quitAction = fileMenu->addAction("&Quit");
    QMenu *helpMenu = menuBar()->addMenu("&Help");
    QAction *helpAction = helpMenu->addAction("&Help");
    QAction *aboutGameAction = helpMenu->addAction("&About game");
    QAction *aboutAuthorAction = helpMenu->addAction("&About author");
    connect(newGameAction, SIGNAL(triggered(bool)), this, SLOT(newGame()));
    connect(quitAction, SIGNAL(triggered(bool)), this, SLOT(close()));
    connect(helpAction, SIGNAL(triggered(bool)), view, SLOT(showHelp()));
    connect(aboutGameAction, SIGNAL(triggered(bool)), view, SLOT(showInfoAboutGame()));
    connect(aboutAuthorAction, SIGNAL(triggered(bool)), view, SLOT(showInfoAboutAuthor()));
    connect(model, SIGNAL(puzzleSolved()), this, SLOT(showStats()));
    labelTimeElapsed = new QLabel("Time elapsed: ");
    labelNumberOfMoves = new QLabel("Number of moves");
    labelNumberOfRows = new QLabel("Tiles number across the field width");
    labelNumberOfColumns = new QLabel("Tiles number along the field height");
    spinBoxNumberOfRows = new QSpinBox();
    spinBoxNumberOfRows->setMinimum(MIN_ROW_COUNT);
    spinBoxNumberOfRows->setMaximum(MAX_ROW_COUNT);
    spinBoxNumberOfRows->setValue(4);
    spinBoxNumberOfColumns = new QSpinBox();
    spinBoxNumberOfColumns->setMinimum(MIN_COL_COUNT);
    spinBoxNumberOfColumns->setMaximum(MAX_COL_COUNT);
    spinBoxNumberOfColumns->setValue(4);

    QHBoxLayout *hLayout1 = new QHBoxLayout;
    hLayout1->addWidget(labelTimeElapsed);
    hLayout1->addSpacing(20);
    hLayout1->addWidget(timer);

    QHBoxLayout *hLayout2 = new QHBoxLayout;
    hLayout2->addWidget(labelNumberOfMoves);
    hLayout2->addSpacing(20);
    hLayout2->addWidget(counter);

    QHBoxLayout *hLayout3 = new QHBoxLayout;
    hLayout3->addWidget(labelNumberOfRows);
    hLayout3->addSpacing(20);
    hLayout3->addWidget(spinBoxNumberOfRows);

    QHBoxLayout *hLayout4 = new QHBoxLayout;
    hLayout4->addWidget(labelNumberOfColumns);
    hLayout4->addSpacing(20);
    hLayout4->addWidget(spinBoxNumberOfColumns);

    QHBoxLayout *hLayout5 = new QHBoxLayout;
    labelGameType = new QLabel("Game type");
    gameType = new QComboBox();
    gameType->addItem("Numbered tiles");
    gameType->addItem("Picture puzzle");
    hLayout5->addWidget(labelGameType);
    hLayout5->addSpacing(20);
    hLayout5->addWidget(gameType);

    QHBoxLayout *hLayout6 = new QHBoxLayout;
    labelChoosePicture = new QLabel("Choose picture");
    ComboBoxChoosingPicture = new QComboBox();
    ComboBoxChoosingPicture->addItem("Iris");
    ComboBoxChoosingPicture->addItem("Auto1");
    ComboBoxChoosingPicture->addItem("Auto2");
    ComboBoxChoosingPicture->addItem("Auto3");
    ComboBoxChoosingPicture->addItem("Helicopter");
    hLayout6->addWidget(labelChoosePicture);
    hLayout6->addSpacing(20);
    hLayout6->addWidget(ComboBoxChoosingPicture);

    QHBoxLayout *hLayout7 = new QHBoxLayout;
    labelPictPuzzleComplexity = new QLabel("Picture puzzle complexity");
    spinBoxPictPuzzleComplexity = new QSpinBox();
    spinBoxPictPuzzleComplexity->setMinimum(MIN_ROW_COUNT);
    spinBoxPictPuzzleComplexity->setMaximum(MAX_ROW_COUNT);
    spinBoxPictPuzzleComplexity->setValue(DEFAULT_ROW_COUNT);
    hLayout7->addWidget(labelPictPuzzleComplexity);
    hLayout7->addSpacing(20);
    hLayout7->addWidget(spinBoxPictPuzzleComplexity);

    QHBoxLayout *hLayout8 = new QHBoxLayout;
    newGameButton = new QPushButton("New game");
    connect(newGameButton, SIGNAL(clicked(bool)), this, SLOT(newGame()));
    exitButton = new QPushButton("Quit");
    connect(exitButton, SIGNAL(clicked(bool)), this, SLOT(close()));
    hLayout8->addWidget(newGameButton);
    hLayout8->addSpacing(20);
    hLayout8->addWidget(exitButton);

    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->addSpacing(0);
    vLayout->addLayout(hLayout1);
    vLayout->addLayout(hLayout2);
    vLayout->addLayout(hLayout3);
    vLayout->addLayout(hLayout4);
    vLayout->addLayout(hLayout5);
    vLayout->addLayout(hLayout6);
    vLayout->addLayout(hLayout7);
    vLayout->addLayout(hLayout8);
    vLayout->setAlignment(Qt::AlignTop);
    vLayout->setContentsMargins(5, 5, 5, 5);

    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget(view);
    hLayout->addLayout(vLayout);
    QWidget *widget = new QWidget();
    widget->setLayout(hLayout);
    setCentralWidget(widget);
    setFixedSize(MIN_FORM_WIDTH + BUTTON_WIDTH * model->getColumnCount(),
                 MIN_FORM_HEIGHT + BUTTON_HEIGHT * model->getRowCount());
    emit puzzleStart();
}

QString Puzzle15Controller::getPictureName()
{
    if(gameType->currentIndex() == 0)
        return QString("");
    switch(ComboBoxChoosingPicture->currentIndex())
    {

       case 1: return QString(":/images/auto1.jpg");
       case 2: return QString(":/images/auto2.jpg");
       case 3: return QString(":/images/auto3.jpg");
       case 4: return QString(":/images/helicopter.jpg");
       case 0:
      default: return QString(":/images/iris.jpg");
    }
}

void Puzzle15Controller::keyPressEvent(QKeyEvent *event)
{
    int key = event->key();
    switch(key)
    {
        case Qt::Key_W: model->makeMoveByDirection(Direction::UP); break;
        case Qt::Key_S: model->makeMoveByDirection(Direction::DOWN); break;
        case Qt::Key_D: model->makeMoveByDirection(Direction::RIGHT); break;
        case Qt::Key_A: model->makeMoveByDirection(Direction::LEFT); break;
        case Qt::Key_N: newGame(); break;
        case Qt::Key_Q:
        case Qt::Key_Escape: close(); break;
        default: break;
    }
}

void Puzzle15Controller::newGame()
{
   int r = spinBoxNumberOfRows->value();
   int c = spinBoxNumberOfColumns->value();
   bool isPicture = gameType->currentIndex() == 0 ? false : true;
   timer->reset();
   counter->reset();
   if(isPicture)
   {
       int complexity = spinBoxPictPuzzleComplexity->value();
       model->newGame(complexity, complexity);
       QPixmap *picture = new QPixmap(getPictureName());
       view->init(isPicture, picture, complexity);
       setFixedSize(MIN_FORM_WIDTH + PUZZLE_PICTURE_SIZE,
                    MIN_FORM_HEIGHT + PUZZLE_PICTURE_SIZE - 10);
   }
   else
   {
       model->newGame(r, c);
       view->init(isPicture, nullptr, DEFAULT_ROW_COUNT);
       setFixedSize(MIN_FORM_WIDTH + BUTTON_WIDTH * model->getColumnCount(),
                   MIN_FORM_HEIGHT + BUTTON_HEIGHT * model->getRowCount());
   }
   //qDebug() << "ширина" << this->width();
   //qDebug() << "высота" << this->height();

}

void Puzzle15Controller::reset()
{
    timer->reset();
    counter->reset();
    model->reset();
    view->update();
}

void Puzzle15Controller::showStats()
{
   QMessageBox::StandardButton answer =
   QMessageBox::question(this, "Play again?",
   "Number of moves :" + QString::number(model->getMovesNumber()) +
   " Elapsed time : " + timer->time()->toString("hh:mm:ss"),
   QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
   if(answer == QMessageBox::Yes)
   {
       reset();
   }
   if(answer == QMessageBox::No)
   {
       qApp->quit();
   }
}
