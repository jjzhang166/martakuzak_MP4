#include "analyzer.h"

using namespace std;

Analyzer::Analyzer(const QString &fileName)
{
    this->fileName=fileName;
}

unsigned long int Analyzer:: valueOfGroupOfFields(QByteArray array, int begin, int end) {
    unsigned long int num=0;
    for(int i=begin; i<(end+1); i++) {
        num |= static_cast<unsigned int>(array[i]) & 0xFF;
            if(begin!=end && i!=end) {
           num=(num<<8);
        }
    }
    return num;
}


QString Analyzer:: toQString(unsigned int num, int bytes) {
    QString result;
    for(int i=0; i<(bytes-1);i++){
        result.push_front(QChar((num-((num>>8)<<8))));
        num= num>>8;
    }
    qDebug()<<"D";
    result.push_front(QChar(num));
    return result;
}

QString Analyzer:: getData() {

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        return list;
    }
    QByteArray array = file.readAll();
    bool progress= true;
    int i=0;

    while(progress) {

        unsigned int size=valueOfGroupOfFields(array, i, i+3);
        //unsigned int ftype= valueOfGroupOfFields(array, i+4, i+7);
        QByteArray &arr= array;
        QString siz= arr.mid(i,4);
        QString type=arr.mid(i+4, 4);
        list.append(type);
        list.append("\t");
        list.append(siz);
        list.append("\n\t");
        //QString type= toQString(ftype,4);
        //vector.append(Box(size, type));
        i+=size;
        if(i>=array.size()) {
            progress=false;
        }
    }
    return list;
}

void Analyzer::setData(TreeItem* parent) {
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        return ;
    }
    QByteArray array = file.readAll();
    set(array,parent);
}

void Analyzer:: set(QByteArray& array, TreeItem* parent, long off) {
    long offset= off;
    bool progress= true;
    int i=0;
    while(progress) {
        //std::cout<<"off "<<offset<<std::endl;
        unsigned long int size=valueOfGroupOfFields(array, i, i+3);
        unsigned long int type= valueOfGroupOfFields(array, i+4, i+7);

        QList<QVariant> columnData;
        QVariant var(toQString(type,4));
        QVariant var2(QString::number(size));
        QVariant var3(QString::number(i+8));
        columnData<<var;
        columnData<<var2;
        columnData<<(i+offset);
        TreeItem* newItem= new TreeItem(columnData,parent,i+offset);
        parent->appendChild(newItem);

        if((type==1836019574) || (type==1953653099) || (type==1835297121) ||(type==1835626086) || (type==1684631142) || (type==1937007212)){
            set(array.mid(i+8,size-8),newItem,offset+i+8);
        }
        //else offset+=size;

        i+=size;
        if(i>=array.size()) {
            progress=false;
        }
    }

}
