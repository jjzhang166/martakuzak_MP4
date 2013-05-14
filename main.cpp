#include "mainwindow.h"
#include <QApplication>
#include "analyzer.h"
#include "boxfactory.h"
#include "exceptions.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    BoxFactory b;
    try{
        b.getBox(1,"ftyp");
    }
    catch(NoSuchABoxException m) {
        qDebug()<<"NoSuchABoxException";
    }

    return a.exec();
}
