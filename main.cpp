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
    /*Analyzer an("D:\\_Samples\\Beach.mp4");*/
    /*QFile* file = new QFile("D:\\_Samples\\Beach.mp4");
    if (!file->open(QIODevice::ReadOnly)) {

    }
    file->seek(2);
    QByteArray array = file->read(8);
    unsigned long int num=0;

    int length = 4;
    file->seek(4);
    array = file->read(length);
    for(int i=0; i<(length); i++) {
        //qDebug()<<QString::number(static_cast<unsigned int>(array[i]))<<QString::number(num);
        num |= static_cast<unsigned int>(array[i]) & 0xFF;
        if(0!=length && i!=(length-1)) {
            num=(num<<8);
        }
    }
    /*for (int i = 0; i<8; ++i) {
        qDebug()<<QString::number(i)<<QString::number(array[i], 16);
    }

    qDebug()<<QString::number(num,2);
    qDebug()<<num;



    int wartoscBajtow = 67313493;
    int suffix = 6;
    int num = 0;
    int length = 26;

    for(int i = 0; i<length; ++i) {
        num|=1;
        num = num<<1;
    }
    for (int i = 0; i<suffix; ++i) {
        num|=0;
        num = num<<1;
    }
    num = num>>1;
    int wartoscBitow = wartoscBajtow & num;
    wartoscBitow = wartoscBitow >> suffix;
    qDebug()<<QString::number(wartoscBitow);

    return 0;*/
}
