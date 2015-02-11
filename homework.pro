#-------------------------------------------------
#
# Project created by QtCreator 2015-02-10T10:01:31
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = homework
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    filereader.cpp \
    glwidget.cpp

HEADERS  += widget.h \
    filereader.h \
    glwidget.h

FORMS    += widget.ui

OTHER_FILES += \
    ../SciVis/scalarGFull.raw \
    ../SciVis/table.txt
