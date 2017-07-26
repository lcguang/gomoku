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
    board.cpp \
    people_ai.cpp \
    people_people.cpp

HEADERS  += mainwindow.h \
    board.h \
    people_ai.h \
    people_people.h

FORMS    += mainwindow.ui
