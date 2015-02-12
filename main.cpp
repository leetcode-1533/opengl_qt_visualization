#include "widget.h"
#include <QApplication>
#include <QDataStream>
#include <QFile>
#include <QDebug>
#include "filereader.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    filereader* tk = new filereader();
    //filereader * tk_test = new filereader();
    w.show();
    return a.exec();
}
