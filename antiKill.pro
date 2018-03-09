#-------------------------------------------------
#
# Project created by QtCreator 2018-03-04T14:54:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = antiKill
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    passworddialog.cpp \
    antikill.cpp

HEADERS  += mainwindow.h \
    passworddialog.h \
    libraries.h \
    antikill.h

FORMS    += mainwindow.ui \
    passworddialog.ui
