#include "widget.h"
#include <QApplication>
#include <QDataStream>
#include <QFile>
#include <QDebug>
#include "filereader.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    filereader test = filereader(2000,2);
 //   Widget w;

    //filereader * tk_test = new filereader();
  //  w.show();
    return a.exec();
}
