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
    result.push_front(QChar(num));
    return result;
}

/*QString Analyzer:: getData() {

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
}*/

void Analyzer::setData(TreeItem* parent) {
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        return ;
    }
    QByteArray array = file.readAll();
    setData(array,parent);
}

void Analyzer::setData(QByteArray array, TreeItem *&parent, long off) {
    //qDebug()<<"Na pocz "<<(0+array[6025912])<<" "<<(0+array[6025913])<<" "<<(0+array[6025914])<<" "<<(0+array[6025915]);
    long offset= off;
    bool progress= true;
    int i=0;
    while(progress) {
        /*QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
            return ;
        }
        QByteArray array_ = file.readAll();
        //qDebug()<<" hh "<<i<<" "<<(static_cast<unsigned int>(array_[i]) & 0xFF);
        /*for(int k=0; k<44; k++) {
            qDebug()<<"k  "<<k<<" arr "<<(0+array_[k+i]);
        }*/
        unsigned long int size;
        unsigned long int type;
        //qDebug()<<"Heeee "<<(i+3+parent->getOffset()-8);
        //qDebug()<<"Mlee "<<i;
        if(offset) {
            size=valueOfGroupOfFields(array, i, i+3+parent->getOffset()-8);
            type= valueOfGroupOfFields(array, i+4, i+7+parent->getOffset()-8);
        }
        else {
            size=valueOfGroupOfFields(array, i, i+3);
            type= valueOfGroupOfFields(array, i+4, i+7);
        }
        QList<QVariant> columnData;
        QVariant var(toQString(type,4));
        QVariant var2(QString::number(size));
        QVariant var3(QString::number(i+8));
        columnData<<var;
        columnData<<var2;
        columnData<<QString::number(i+offset);
        qDebug()<<"typ "<<toQString(type,4)<< " "<<type<< " size "<<size<<" i+8 "<<(i+offset);

        TreeItem *newItem= new TreeItem(columnData,parent,i+offset);
        if(newItem->isNull()) {
            //qDebug()<<"Nulltyp "<<toQString(type,4)<< " "<<type<< " size "<<size<<" i+8 "<<(i+offset);
            QList<QVariant> colDat;
            QVariant v1(toQString(type,4));
            QVariant v2(QString::number(size));
            QVariant v3(QString::number(i+8));
            colDat<<var;
            colDat<<var2;
            colDat<<QString::number(i+offset-8);
            qDebug()<<"typ "<<toQString(type,4)<< " "<<type<< " size "<<size<<" i+8 "<<(i+offset-8);
            TreeItem *newIt= new TreeItem(colDat,parent,i+offset-8);
           // QVariant v(QString::number(i+offset-8));
            //columnData.replace(3,v);
            parent->appendChild(newIt);
            i+=size;
            i+=(offset-8);
            qDebug()<<"jakie kurwa i "<<i;
        }
        else {
            parent->appendChild(newItem);
            if(newItem->isContainer()){
                setData(array.mid(i+8,size-8),newItem,offset+i+8+newItem->getOffset()-8);
            }
            i+=size;
            qDebug()<<"jakie kurwa i "<<i;
        }


        if(i>=array.size()) {
            progress=false;
        }
    }

}
