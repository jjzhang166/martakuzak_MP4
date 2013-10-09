#include "analyzer.h"

////////////////////////////////////////////////////////////////////////////////////////////
Analyzer::Analyzer(const QString &fileName)
{
    this->fileName=fileName;
    this->arraySize = 0;
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        return ;
    }
    QByteArray array = file.readAll();
    tempArray= array;
}
////////////////////////////////////////////////////////////////////////////////////////////
unsigned long int Analyzer:: valueOfGroupOfFields(const int &begin, const int &end, QByteArray array) {
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
////////////////////////////////////////////////////////////////////////////////////////////
unsigned long int Analyzer:: valueOfBits(const int& begin, const int& end) {
    int firstByte = begin/8;
    int firstBit = begin - 8 * firstByte;
    int lastByte = end/8;
    int lastBit;
//    if((end == (8*(lastByte+1))-1))
//        lastBit = 7;
//    else {
        lastBit = end - lastByte*8;
        //lastByte ++;
    //}=
    int numOfBits = 8*(lastByte - 1) + lastBit - 8*(firstByte -1) -firstBit + 1;
    int numOfBytes = lastByte - firstByte + 1;
    int byteValue = this->valueOfGroupOfFields(firstByte,lastByte);
    QString tmpValue = QString::number(byteValue,2);
    int tmpSize = tmpValue.size();
    if(tmpSize < numOfBytes*8) {
        int delta = numOfBytes*8 - tmpSize;
        for (int i = 0; i<delta; ++i) {
            tmpValue = tmpValue.insert(0, "0");
        }
    }
    QString qstringBitsValue = tmpValue.mid(firstBit, numOfBits);
    return qstringBitsValue.toUInt(0,2);
}

////////////////////////////////////////////////////////////////////////////////////////////
bool Analyzer::bitValue(int byteId, int bitId) {
    int byte = tempArray[byteId];
    int retValue = QString::number(byte,2).at(bitId).digitValue();
    QString::number(byte,2).mid(2,4);
    bool ret(retValue);
    return ret;
}
////////////////////////////////////////////////////////////////////////////////////////////

QString Analyzer:: toQString(unsigned int num, int bytes) {
    QString result;
    for(int i=0; i<(bytes-1);i++){
        result.push_front(QChar((num-((num>>8)<<8))));
        num= num>>8;
    }
    result.push_front(QChar(num));
    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////

void Analyzer::setData(TreeItem* parent, QHash<long, TreeItem *>* items) {
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        return ;
    }
    QByteArray array = file.readAll();
    tempArray= array;
    arraySize = array.size();
    setData(array,parent,items, 0);
}
////////////////////////////////////////////////////////////////////////////////////////////

void Analyzer::setData(QByteArray array, TreeItem *&parent, QHash<long, TreeItem *>* items, long off) {
    tempArray= array;
    long offset= off;//offset tej array w pliku
    bool progress= true;
    int i=0; //cos jak offset w arrayu
    while(progress) {
        unsigned long int size; //rozmiar boxa
        unsigned long int type; //typ boxa
        //unsigned int [16] extendedType;//to-do

        size=valueOfGroupOfFields(i, i+3, array); //obliczenie wartosci rozmiaru i typu
        type= valueOfGroupOfFields(i+4, i+7, array); //w zadanej tablicy: zawsze na poczatku

        if(size == 0) { //gdy size = 0, to box ciągnie się do końca pliku
            size = arraySize - offset;  //nieprzetestowane!
        }
        else if(size == 1 ) { //dla size = 1, rozmiar przybiera wartość rozszerzoną int(64), po typie
            size = valueOfGroupOfFields(i+8, i+15, array);
        }

        if(toQString(type, 4) == QString("uuid")) {
            if(size == 1) {
                //to-do
            }
            else {

            }
        }

        QList<QVariant> columnData; //konstrukcja danych, ktore beda wyswietlane w drzewie
        columnData<<toQString(type,4);
        columnData<<QString::number(size);
        columnData<<QString::number(i+offset);

        TreeItem *newItem= new TreeItem(this,columnData,parent,i+offset);//tworzymy treeitem

        parent->appendChild(newItem);
        items->insert(i+offset, newItem);
        if(newItem->isContainer()){//gdy treeitem zawiera inne boxy, tworzymy subarray wycinajac offset na atrybuty
            //offset powiekszamy o offset atrybutowy i i
            setData(array.mid(i+newItem->getOffset(),size-newItem->getOffset()),
                    newItem,
                    items,
                    offset+i+newItem->getOffset());
        }
        i+=size;

        tempArray = array.mid(i);
        if(i>=array.size()) {//poki i jest nie wieksze od rozmiaru tablicy
            progress=false;
        }
    }

}
