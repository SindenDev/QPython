#-------------------------------------------------
#
# Project created by QtCreator 2016-09-08T16:58:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QPython
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qpython.cpp

HEADERS  += mainwindow.h \
    qpython.h

FORMS    += mainwindow.ui

win32: LIBS += -L$$PWD/lib/ -lpython27

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include

DISTFILES += \
    testList.py

#LIBS += -L$$PWD/lib/ -lpython27

#INCLUDEPATH += $$PWD/include
#DEPENDPATH += $$PWD/include
