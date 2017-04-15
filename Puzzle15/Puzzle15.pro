#-------------------------------------------------
#
# Project created by QtCreator 2017-01-01T10:22:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Puzzle15
TEMPLATE = app


SOURCES += main.cpp\
    puzzle15controller.cpp \
    puzzle15model.cpp \
    puzzle15view.cpp \
    cell.cpp \
    lcdcounter.cpp \
    lcdtimer.cpp

HEADERS  += \
    puzzle15controller.h \
    puzzle15model.h \
    puzzle15view.h \
    defines.h \
    cell.h \
    lcdcounter.h \
    lcdtimer.h

FORMS    +=

RESOURCES += \
    images.qrc
