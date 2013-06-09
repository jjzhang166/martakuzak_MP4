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
    long offset= off;//offset tej array w pliku
    bool progress= true;
    int i=0; //cos jak offset w arrayu
    while(progress) {
        unsigned long int size; //rozmiar boxa
        unsigned long int type; //typ boxa

        size=valueOfGroupOfFields(array, i, i+3); //obliczenie wartosci rozmiaru i typu
        type= valueOfGroupOfFields(array, i+4, i+7); //w zadanej tablicy: zawsze na poczatku

        QList<QVariant> columnData; //konstrukcja danych, ktore beda wyswietlane w drzewie
        columnData<<toQString(type,4);
        columnData<<QString::number(size);
        columnData<<QString::number(i+offset);

        TreeItem *newItem= new TreeItem(columnData,parent,i+offset);//tworzymy treeitem
        /*if(newItem->isNull()) {// gdy box jest nieznany
            /*QList<QVariant> colDat; //????
            colDat<<toQString(type,4);
            colDat<<QString::number(size);
            colDat<<QString::number(i+offset);
            TreeItem *newIt= new TreeItem(colDat,parent,i+offset);
            parent->appendChild(newItem);
            i+=size;
            //i+=(offset);//przesuwamy i o rozmiar, i offset(??)
        }*/
        //else {
            parent->appendChild(newItem);
            if(newItem->isContainer()){//gdy treeitem zawiera inne boxy, tworzymy subarray wycinajac offset na atrybuty
                                        //offset powiekszamy o offset atrybutowy i i
                setData(array.mid(i+newItem->getOffset(),size-newItem->getOffset()),newItem,offset+i+newItem->getOffset());
            }
            i+=size;
        //}


        if(i>=array.size()) {//poki i jest nie wieksze od rozmiaru tablicy
            progress=false;
        }
    }

}
