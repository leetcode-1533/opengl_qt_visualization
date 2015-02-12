#include "widget.h"
#include <QApplication>
#include <QDataStream>
#include <QFile>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    //filereader * tk_test = new filereader();
    w.show();
    return a.exec();
}
