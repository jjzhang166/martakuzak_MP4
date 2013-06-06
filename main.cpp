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

    return a.exec();
}
