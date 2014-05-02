#-------------------------------------------------
#
# Project created by QtCreator 2014-04-19T21:49:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Endevour
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    coordinate.cpp \
    configurationmanager.cpp \
    ball.cpp \
    stage.cpp \
    brick.cpp \
    paddle.cpp

HEADERS  += dialog.h \
    coordinate.h \
    configurationmanager.h \
    ball.h \
    stage.h \
    singletone.h \
    brick.h \
    paddle.h

FORMS    += dialog.ui
