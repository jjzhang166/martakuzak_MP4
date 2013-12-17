#include "mainwindow.h"
#include <QApplication>
//#include "analyzer.h"
#include "boxfactory.h"
#include "exceptions.h"
#include "mpd.h"

int main(int argc, char *argv[])
{
    /*QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
    //Analyzer an("D:\\_Samples\\Beach.mp4");
    //qDebug()<<an.qstringValue(4,4);
    /*QFile* file = new QFile("D:\\_Samples\\Beach.mp4");
    if (!file->open(QIODevice::ReadOnly)) {

    }
    file->seek(4);
    QByteArray array = file->read(4);
    QString one(array);
    qDebug()<<one;
    /*unsigned long int num=0;

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
    qDebug()<<QString::number(wartoscBitow);*/
    /*QFile* file1 = new QFile("D:\\PDI\\Samples\\multi\\multi_ballroom_side_by_side_2048.mp4");
        if (!file1->open(QIODevice::ReadOnly)) {

        }
        int sync = 0 + 8 + 40;
        int size = 752549;
        int size2 = 28263;
        file1->seek(sync);
        QByteArray array = file1->read(size);
        //QByteArray arrau = file1->read(size2);
    QString filename = "Fragmencik";
    QFile file(filename);
    if (file.open(QIODevice::ReadWrite)) {
            //QTextStream stream(&file);
            //stream << "something" << endl;
        file.write(array);
        //file.write(arrau);
        file.close();
   }*/
    MPDWriter mpdwriter("dnsf");
    QFile* file = new QFile("D://mp.xml");
    mpdwriter.writeMPD(file);
    return 0;
}
