#-------------------------------------------------
#
# Project created by QtCreator 2016-10-08T16:51:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gomoku
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ai.cpp \
    board.cpp

HEADERS  += mainwindow.h \
    ai.h \
    board.h

FORMS    += mainwindow.ui
