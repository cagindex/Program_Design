#-------------------------------------------------
#
# Project created by QtCreator 2016-05-12T21:35:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mydialog1
TEMPLATE = app


SOURCES += main.cpp\
        mywidget.cpp \
    mydialog.cpp \
    newdialog.cpp

HEADERS  += mywidget.h \
    mydialog.h \
    newdialog.h

FORMS    += mywidget.ui \
    mydialog.ui \
    newdialog.ui
