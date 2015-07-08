#-------------------------------------------------
#
# Project created by QtCreator 2015-07-06T02:35:07
#
#-------------------------------------------------
QMAKE_CXXFLAGS += -std=c++11
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dnd2e
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    character.cpp \
    characterclass.cpp \
    race.cpp

HEADERS  += mainwindow.h \
    character.h \
    characterclass.h \
    race.h

FORMS    += mainwindow.ui
