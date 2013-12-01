#include "analyzer.h"

////////////////////////////////////////////////////////////////////////////////////////////
Analyzer::Analyzer() {}
////////////////////////////////////////////////////////////////////////////////////////////
Analyzer::Analyzer(const QString &fileName)
{
    this->fileName=fileName;
    this->fileSize = 0;
    file = new QFile(fileName);
    if (!file->open(QIODevice::ReadOnly)) {
        return ;
    }
    fileSize = file->size();
}
////////////////////////////////////////////////////////////////////////////////////////////
unsigned long int Analyzer:: valueOfGroupOfFields(const int &length, const unsigned long int& offset) {
    QByteArray array;
    unsigned long int num=0;
    if(offset != 0) {
        file->seek(offset - 1);
        array = file->read(length + 1);
        for(int i=0; i<(length+1); i++) {
            num |= static_cast<unsigned int>(array[i]) & 0xFF;
            if(0!=length && i!=length) {
                num=(num<<8);
            }
        }
    }
    else {
        array = file->read(length);
        for(int i=0; i<(length); i++) {
            qDebug()<<QString::number(num);
            num |= static_cast<unsigned int>(array[i]) & 0xFF;
            if(0!=(length-1) && i!=(length-1)) {
                num=(num<<8);
            }
        }
        qDebug()<<QString::number(num);

    }
    //qDebug()<<"vogf fileread";


    //qDebug()<<"vogf przed return";

    return num;
}
////////////////////////////////////////////////////////////////////////////////////////////
/*unsigned long int Analyzer:: valueOfBits(const int& begin, const int& end) {
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
}*/

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

Analyzer::~Analyzer() {
}
////////////////////////////////////////////////////////////////////////////////////////////
void Analyzer::setData(TreeItem* parent, QHash<long, TreeItem *>* items) {
    qDebug()<<"setData init";
    file = new QFile(fileName);
    if (!file->open(QIODevice::ReadOnly)) {
        return ;
    }
    maxTempOff = file->size();
    setData(parent, items, 0, fileSize); //zaczynamy od zerowego offsetu
}
////////////////////////////////////////////////////////////////////////////////////////////

void Analyzer::setData(TreeItem *&parent, QHash<long, TreeItem *>* items, const unsigned long &off, unsigned long int maxOff) {
    qDebug()<<"setData wywołanie!"<<maxOff;
    unsigned long int offset= off;//offset w pliku
    bool progress= true;
    while(progress) {
        unsigned long int size; //rozmiar boxa
        unsigned long int type; //typ boxa
        //unsigned int [16] extendedType;//to-do
        size = valueOfGroupOfFields(4, 0 + offset);
        type = valueOfGroupOfFields(4, 4 + offset);

        if(size == 0) { //gdy size = 0, to box ciągnie się do końca pliku
            size = fileSize - offset;  //nieprzetestowane!
        }
        if(size == 1 ) { //dla size = 1, rozmiar przybiera wartość rozszerzoną int(64), po typie
            size = valueOfGroupOfFields(8, 8 + offset);
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
        columnData<<QString::number(offset);

        TreeItem *newItem= new TreeItem(this,columnData,parent,offset);//tworzymy treeitem

        parent->appendChild(newItem);
        items->insert(offset, newItem);
        if(newItem->isContainer()){//gdy treeitem zawiera inne boxy, tworzymy subarray wycinajac offset na atrybuty
            qDebug()<<"tempSize"<<maxOff;

            setData(newItem,
                    items,
                    offset + newItem->getOffset(), offset + size);
        }

        offset += size;

        //maxTempOff += size;
        qDebug()<<"setData off temps"<<offset<<maxOff;
        if( offset >= fileSize )
            progress = false;
        if( offset >= maxOff ) {
            progress = false;
            //maxTempOff -= size;
            qDebug()<<"setData progress-false";
        }
    }
    /*while(progress) {
        unsigned long int size; //rozmiar boxa
        unsigned long int type; //typ boxa
        //unsigned int [16] extendedType;//to-do
        size=valueOfGroupOfFields(i, i+3, array); //obliczenie wartosci rozmiaru i typu
        type= valueOfGroupOfFields(i+4, i+7, array); //w zadanej tablicy: zawsze na poczatku

        if(size == 0) { //gdy size = 0, to box ciągnie się do końca pliku
            size = *arraySize - offset;  //nieprzetestowane!
        }
        else if(size == 1 ) { //dla size = 1, rozmiar przybiera wartość rozszerzoną int(64), po typie
            size = valueOfGroupOfFields(i+8, i+15, array);
        }
        //qDebug()<<"setData3"<<toQString(type,4);

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
    }*/

}
