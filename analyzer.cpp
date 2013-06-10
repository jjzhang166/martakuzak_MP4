#include "analyzer.h"

using namespace std;

Analyzer::Analyzer(const QString &fileName)
{
    this->fileName=fileName;
}

unsigned long int Analyzer:: valueOfGroupOfFields(int begin, int end, QByteArray array) {
    if(!array.size())
        array= tempArray;
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


void Analyzer::setData(TreeItem* parent, QHash<long,TreeItem*>* items) {
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        return ;
    }
    QByteArray array = file.readAll();
    tempArray= array;
    setData(array,parent,items, 0);
}

void Analyzer::setData(QByteArray array, TreeItem *&parent, QHash<long, TreeItem *> *items, long off) {
    tempArray= array;
    long offset= off;//offset tej array w pliku
    bool progress= true;
    int i=0; //cos jak offset w arrayu
    while(progress) {
        unsigned long int size; //rozmiar boxa
        unsigned long int type; //typ boxa

        size=valueOfGroupOfFields(i, i+3, array); //obliczenie wartosci rozmiaru i typu
        type= valueOfGroupOfFields(i+4, i+7, array); //w zadanej tablicy: zawsze na poczatku

        QList<QVariant> columnData; //konstrukcja danych, ktore beda wyswietlane w drzewie
        columnData<<toQString(type,4);
        columnData<<QString::number(size);
        columnData<<QString::number(i+offset);

        TreeItem *newItem= new TreeItem(this,columnData,parent,i+offset);//tworzymy treeitem

        parent->appendChild(newItem);
        items->insert(i+offset, newItem);
        //qDebug()<<"Insert "<<toQString(type,4)<<" "<<(i+offset);
        if(newItem->isContainer()){//gdy treeitem zawiera inne boxy, tworzymy subarray wycinajac offset na atrybuty
                                        //offset powiekszamy o offset atrybutowy i i
            setData(array.mid(i+newItem->getOffset(),size-newItem->getOffset()),
                newItem,
                items,
                offset+i+newItem->getOffset());
        }
        i+=size;


        if(i>=array.size()) {//poki i jest nie wieksze od rozmiaru tablicy
            progress=false;
        }
    }

}
