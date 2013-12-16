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
    mdatOffset = 0;
}
////////////////////////////////////////////////////////////////////////////////////////////
unsigned long int Analyzer:: valueOfGroupOfBytes(const int &length, const unsigned long int& offset) {
    QByteArray array;
    unsigned long int num = 0;
    file->seek(offset);
    array = file->read(length);
    for(int i = 0; i< length; ++i) {
        num |= static_cast<unsigned int>(array[i]) & 0xFF; //suma bit po bicie
        if(0!=length && i!=(length-1)) {
            num=(num<<8); //przesuniecie o 8 bitow w lewo
        }
    }
    return num;
}
////////////////////////////////////////////////////////////////////////////////////////////
signed long int Analyzer:: signedValueOfGroupOfBytes(const int &length, const unsigned long int& offset) {
    QByteArray array;
    signed long int num = 0;
    file->seek(offset);
    array = file->read(length);
    for(int i = 0; i< length; ++i) {
        num |= static_cast<unsigned int>(array[i]) & 0xFF; //suma bit po bicie
        if(0!=length && i!=(length-1)) {
            num=(num<<8); //przesuniecie o 8 bitow w lewo
        }
    }
    return num;
}
////////////////////////////////////////////////////////////////////////////////////////////
unsigned long int Analyzer::valueOfGroupOfBits(const int & length, const unsigned long int& offset) {
    int firstByteNum = offset/8;
    int lastByteNum = (offset + length)/8;

    unsigned long int byteValue = this->valueOfGroupOfBytes(lastByteNum - firstByteNum + 1, firstByteNum);
    int suffix = 8 - (offset + length)%8;

    unsigned long int bitValue = 0;
    int pattern = 0;

    for(int i = 0; i < length; ++i) { //utworzenie wzoru: liczby, ktora w reprezentacji binarnej ma jedynki tam, ktory fragment mamy wyciac
        //i zera w pozostalych przypadkach: wygenerowanie ciagu 1
        pattern |= 1;
        pattern = pattern << 1;
    }
    for(int i = 0; i < suffix; ++i) {//dodanie odpowiedniej ilosci zer
        pattern |= 0;
        if (!(i== suffix - 1))
            pattern = pattern << 1;
    }

    bitValue = (byteValue & pattern) >> suffix; //iloczyn logiczny bit po bicie i przesuniecie bitowe w prawo

    return bitValue;
}
////////////////////////////////////////////////////////////////////////////////////////////
QString Analyzer:: qstringValue(const unsigned int& length, const unsigned int& offset) {
    QByteArray array;
    file->seek(offset);
    array = file->read(length);
    return QString(array);
}
////////////////////////////////////////////////////////////////////////////////////////////

Analyzer::~Analyzer() {
}
////////////////////////////////////////////////////////////////////////////////////////////
void Analyzer::setData(TreeItem* parent, QHash<long, TreeItem *>* items) {
    file = new QFile(fileName);
    if (!file->open(QIODevice::ReadOnly)) {
        return ;
    }
    setData(parent, items, 0, fileSize); //zaczynamy od zerowego offsetu
}
////////////////////////////////////////////////////////////////////////////////////////////

void Analyzer::setData(TreeItem *&parent, QHash<long, TreeItem *>* items, const unsigned long &off, unsigned long int maxOff) {
    // qDebug()<<"setData wywołanie!"<<maxOff;
    unsigned long int offset= off;//offset w pliku
    bool progress= true;
    while(progress) {
        unsigned long int size; //rozmiar boxa
        //unsigned long int type; //typ boxa
        QString type;
        //unsigned int [16] extendedType;//to-do
        size = valueOfGroupOfBytes(4, 0 + offset);
        //type = valueOfGroupOfBytes(4, 4 + offset);
        type = qstringValue(4, 4 + offset);

        if(size == 0) { //gdy size = 0, to box ciągnie się do końca pliku
            size = fileSize - offset;  //nieprzetestowane!
        }
        if(size == 1 ) { //dla size = 1, rozmiar przybiera wartość rozszerzoną int(64), po typie
            size = valueOfGroupOfBytes(8, 8 + offset);
        }

        if(type == QString("uuid")) {
            if(size == 1) {
                //to-do
            }
            else {

            }
        }

        if(type == QString("mdat"))
            mdatOffset = offset;

        QList<QVariant> columnData; //konstrukcja danych, ktore beda wyswietlane w drzewie
        columnData<<type;
        columnData<<QString::number(size);
        columnData<<QString::number(offset);

        TreeItem *newItem= new TreeItem(this,columnData,parent,offset);//tworzymy treeitem

        parent->appendChild(newItem);
        items->insert(offset, newItem);
        if(newItem->isContainer()){//gdy treeitem zawiera inne boxy, tworzymy subarray wycinajac offset na atrybuty
            //qDebug()<<"is container tempSize"<<offset + size;

            setData(newItem,
                    items,
                    offset + newItem->getOffset(), offset + size);
        }

        offset += size;

        //maxTempOff += size;
        //qDebug()<<"setData off temps"<<offset<<maxOff;
        if( offset >= fileSize )
            progress = false;
        if( offset >= maxOff ) {
            progress = false;
            //maxTempOff -= size;
            // qDebug()<<"setData progress-false";
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////
//unsigned long int Analyzer::mdatSize(const unsigned long int& firstSample, const unsigned int& sampleNumber, std::shared_ptr<Box>& stsz) {
//    unsigned long int mdatSize = 8;
//    for (unsigned int i = firstSample; i< (firstSample + sampleNumber); ++i) {
//        mdatSize += stsz->getSampleSize(i);
//    }
//    return mdatSize;
//}
//////////////////////////////////////////////////////////////////////////////////////////////
//unsigned int Analyzer::writeMdat(const unsigned long int& firstSample, const unsigned int &sampleNumber, std::shared_ptr<Box>& stsz,
//                         QFile* dashFile) {
//    unsigned long int size = mdatSize(firstSample, sampleNumber, stsz) - 8;
//    QDataStream stream(dashFile);
//    stream<<quint32(size); //4 bajty
//    stream.writeRawData("mdat", 4); //4 bajty
//    QByteArray array;
//    if(firstSample) {
//        unsigned long int offset = mdatSize(0, firstSample - 1, stsz);
//        file->seek(offset + mdatOffset + 8);
//    }
//    else {
//        file->seek(mdatOffset + 8);
//    }
//    array = file->read(size);
//    dashFile->write(array);
//    return size + 8;
//}
//////////////////////////////////////////////////////////////////////////////////////////////
//unsigned int Analyzer::writeMoof(const unsigned long int& sequenceNumber, const unsigned int& trackID,
//                                 const unsigned long &baseMediaDecodeTime, const unsigned int& trunFlag2,const unsigned int& trunFlag3,
//                                 const unsigned int& sampleCount, const signed int& dataOffset,const unsigned int& firstSampleFlags,
//                                 const unsigned long int& firstSample, std::shared_ptr<Box>& stsz,
//                                 QFile* dashFile) {
//    QDataStream stream(dashFile);
//    //obliczenie obrazu
//    int size = 8;
//    size += 64; //po 16 od mfhd, tfhd i tfdt, początek trun
//                //poniżej dalej trun
//    size += 8; //naglowek traf
//    if(trunFlag2 == 2) //sample sizes are present
//        size += sampleCount*4;
//    if(trunFlag3 == 1 || trunFlag3 == 4) //1- data-offset, 4 - firstsampleflags
//        size += 4;
//    else if(trunFlag3 == 5) //oba
//        size += 8;
//    //
//    stream<<quint32(size);
//    stream.writeRawData("moof", 4);

//    writeMfhd(sequenceNumber, dashFile);
//    writeTraf(trackID, baseMediaDecodeTime, trunFlag2, trunFlag3, sampleCount, dataOffset, firstSampleFlags, firstSample,
//              stsz, dashFile);

//    return size;
//}

//////////////////////////////////////////////////////////////////////////////////////////////
//unsigned int Analyzer::writeMfhd(const unsigned long int& sequenceNumber, QFile* dashFile) {
//    QDataStream stream(dashFile);
//    stream<<quint32(16); //size
//    stream.writeRawData("mfhd", 4);
//    stream<<quint8(0); //version
//    stream<<quint8(0); //flags
//    stream<<quint16(0);
//    stream<<quint32(sequenceNumber);
//    return 16;
//}
//////////////////////////////////////////////////////////////////////////////////////////////
//unsigned int Analyzer::writeTraf(const unsigned int& trackID, const unsigned long &baseMediaDecodeTime, const unsigned int& flag2,
//                       const unsigned int& flag3, const unsigned int& sampleCount, const signed int& dataOffset,
//                       const unsigned int& firstSampleFlags, const unsigned long int& firstSample,
//                       std::shared_ptr<Box>& stsz, QFile* dashFile) {
//    QDataStream stream(dashFile);
//    //obliczenie rozmiaru
//    int size = 8;
//    size += 48; //po 16 od tfhd i tfdt, początek trun
//                //poniżej dalej trun
//    if(flag2 == 2) //sample sizes are present
//        size += sampleCount*4;
//    if(flag3 == 1 || flag3 == 4) //1- data-offset, 4 - firstsampleflags
//        size += 4;
//    else if(flag3 == 5) //oba
//        size += 8;
//    //
//    stream<<quint32(size);
//    stream.writeRawData("traf", 4);

//    writeTfhd(trackID, dashFile);
//    writeTfdt(baseMediaDecodeTime, dashFile);
//    writeTrun(flag2, flag3, sampleCount, dataOffset, firstSampleFlags, firstSample, stsz, dashFile);

//    return size;
//}

//////////////////////////////////////////////////////////////////////////////////////////////
//unsigned int Analyzer::writeTfhd(const unsigned int& trackID, QFile* dashFile) {
//    QDataStream stream(dashFile);
//    stream<<quint32(16); //size
//    stream.writeRawData("tfhd", 4);
//    stream<<quint8(0); //version
//    stream<<quint8(2); //flags //dlaczego 2?
//    stream<<quint16(0);
//    stream<<quint32(trackID);
//    return 16;
//}
//////////////////////////////////////////////////////////////////////////////////////////////
//unsigned int Analyzer::writeTfdt(const unsigned long int& baseMediaDecodeTime, QFile* dashFile) {
//    QDataStream stream(dashFile);
//    stream<<quint32(16); //size
//    stream.writeRawData("tfdt", 4);
//    int version;
//    if(baseMediaDecodeTime > 65535)
//        version = 1;
//    else
//        version = 0;
//    stream<<quint8(version); //version
//    stream<<quint8(0); //flags //dlaczego 2?
//    stream<<quint16(0);
//    if(version)
//        stream<<quint64(baseMediaDecodeTime);
//    else
//        stream<<quint32(baseMediaDecodeTime);
//    return 16;
//}
//////////////////////////////////////////////////////////////////////////////////////////////
//unsigned int Analyzer::writeTrun(const unsigned int& flag2, const unsigned int& flag3, const unsigned int& sampleCount,
//                       const signed int& dataOffset, const unsigned int& firstSampleFlags, const unsigned long int& firstSample,
//                       std::shared_ptr<Box>& stsz, QFile* dashFile) {
//    QDataStream stream(dashFile);
//    int size = 16; //size + type + version + flags + sampleCount
//    if(flag2 == 2) //sample sizes are present
//        size += sampleCount*4;
//    if(flag3 == 1 || flag3 == 4) //1- data-offset, 4 - firstsampleflags
//        size += 4;
//    else if(flag3 == 5) //oba
//        size += 8;
//    stream<<quint32(size); //size
//    stream.writeRawData("trun", 4);
//    stream<<quint8(0); //version
//    stream<<quint8(0); //flags
//    stream<<quint8(flag2);
//    stream<<quint8(flag3);
//    stream<<quint32(sampleCount); //sample count
//    if(flag3 == 1 || flag3 == 5)
//        stream<<qint32(dataOffset);
//    if(flag3 == 2 || flag3 == 5)
//        stream<<quint32(firstSampleFlags);
//    if(flag2 == 2) {
//        for(unsigned int i = firstSample; i< firstSample + sampleCount; ++i) {
//            stream<<quint32(stsz->getSampleSize(i));
//        }
//    }
//    return size;
//}



