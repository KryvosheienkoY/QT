#-------------------------------------------------
#
# Project created by QtCreator 2019-05-21T14:40:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = practice1
TEMPLATE = app


SOURCES += main.cpp\
    adddialog.cpp \
    removedialog.cpp \
    phonebook.cpp \
    mainwindow.cpp

HEADERS  += \
    adddialog.h \
    removedialog.h \
    contact.h \
    phonebook.h \
    mainwindow.h

FORMS    += mainwindow.ui \
    adddialog.ui \
    removedialog.ui
