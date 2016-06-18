#-------------------------------------------------
#
# Project created by QtCreator 2016-06-14T19:47:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = angrybird
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gameitem.cpp \
    redbird.cpp \
    ground.cpp \
    checkpage.cpp \
    barrier.cpp \
    collcheck.cpp \
    yellobird.cpp

HEADERS  += mainwindow.h \
    gameitem.h \
    redbird.h \
    ground.h \
    checkpage.h \
    barrier.h \
    collcheck.h \
    yellobird.h

FORMS    += mainwindow.ui \
    checkpage.ui

LIBS += -L. -lBox2D

RESOURCES += \
    resource.qrc
