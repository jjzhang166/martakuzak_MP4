#include "dashcreator.h"

DashCreator::DashCreator(const QString &fn, TreeModel* m): fileName(fn), model(m) {
    file = new QFile(fileName);
    if (!file->open(QIODevice::ReadOnly)) {
        return ;
    }
}
////////////////////////////////////////////////////////////////////////////////////////////
unsigned long int DashCreator::mdatSize(const unsigned long int& firstSample, const unsigned int& sampleNumber, std::shared_ptr<Box>& stsz) {
    unsigned long int mdatSize = 8;
    for (unsigned int i = firstSample; i< (firstSample + sampleNumber); ++i) {
        mdatSize += stsz->getSampleSize(i);
    }
    return mdatSize;
}
////////////////////////////////////////////////////////////////////////////////////////////
unsigned int DashCreator::writeMdat(const unsigned long int& firstSample, const unsigned int &sampleNumber, std::shared_ptr<Box>& stsz,
                                    QFile* dashFile) {
    unsigned long int size = mdatSize(firstSample, sampleNumber, stsz) - 8;
    QDataStream stream(dashFile);
    stream<<quint32(size); //4 bajty
    stream.writeRawData("mdat", 4); //4 bajty
    unsigned long int mdatOffset = model->getBoxes("mdat").at(0)->getOffset();
    QByteArray array;
    if(firstSample) {
        unsigned long int offset = mdatSize(0, firstSample - 1, stsz);
        file->seek(offset + mdatOffset + 8);
    }
    else {
        file->seek(mdatOffset + 8);
    }
    array = file->read(size);
    dashFile->write(array);
    return size + 8;
}
////////////////////////////////////////////////////////////////////////////////////////////
unsigned int DashCreator::writeMoof(const unsigned long int& sequenceNumber, const unsigned int& trackID,
                                    const unsigned long &baseMediaDecodeTime, const unsigned int& trunFlag2,const unsigned int& trunFlag3,
                                    const unsigned int& sampleCount, const signed int& dataOffset,const unsigned int& firstSampleFlags,
                                    const unsigned long int& firstSample, std::shared_ptr<Box>& stsz,
                                    QFile* dashFile) {
    QDataStream stream(dashFile);
    //obliczenie obrazu
    int size = 8;
    size += 64; //po 16 od mfhd, tfhd i tfdt, początek trun
    //poniżej dalej trun
    size += 8; //naglowek traf
    if(trunFlag2 == 2) //sample sizes are present
        size += sampleCount*4;
    if(trunFlag3 == 1 || trunFlag3 == 4) //1- data-offset, 4 - firstsampleflags
        size += 4;
    else if(trunFlag3 == 5) //oba
        size += 8;
    //
    stream<<quint32(size);
    stream.writeRawData("moof", 4);

    writeMfhd(sequenceNumber, dashFile);
    writeTraf(trackID, baseMediaDecodeTime, trunFlag2, trunFlag3, sampleCount, dataOffset, firstSampleFlags, firstSample,
              stsz, dashFile);

    return size;
}
////////////////////////////////////////////////////////////////////////////////////////////
unsigned int DashCreator::writeMfhd(const unsigned long int& sequenceNumber, QFile* dashFile) {
    QDataStream stream(dashFile);
    stream<<quint32(16); //size
    stream.writeRawData("mfhd", 4);
    stream<<quint8(0); //version
    stream<<quint8(0); //flags
    stream<<quint16(0);
    stream<<quint32(sequenceNumber);
    return 16;
}
////////////////////////////////////////////////////////////////////////////////////////////
unsigned int DashCreator::writeTraf(const unsigned int& trackID, const unsigned long &baseMediaDecodeTime, const unsigned int& flag2,
                                    const unsigned int& flag3, const unsigned int& sampleCount, const signed int& dataOffset,
                                    const unsigned int& firstSampleFlags, const unsigned long int& firstSample,
                                    std::shared_ptr<Box>& stsz, QFile* dashFile) {
    QDataStream stream(dashFile);
    //obliczenie rozmiaru
    int size = 8;
    size += 48; //po 16 od tfhd i tfdt, początek trun
    //poniżej dalej trun
    if(flag2 == 2) //sample sizes are present
        size += sampleCount*4;
    if(flag3 == 1 || flag3 == 4) //1- data-offset, 4 - firstsampleflags
        size += 4;
    else if(flag3 == 5) //oba
        size += 8;
    //
    stream<<quint32(size);
    stream.writeRawData("traf", 4);

    writeTfhd(trackID, dashFile);
    writeTfdt(baseMediaDecodeTime, dashFile);
    writeTrun(flag2, flag3, sampleCount, dataOffset, firstSampleFlags, firstSample, stsz, dashFile);

    return size;
}
////////////////////////////////////////////////////////////////////////////////////////////
unsigned int DashCreator::writeTfhd(const unsigned int& trackID, QFile* dashFile) {
    QDataStream stream(dashFile);
    stream<<quint32(16); //size
    stream.writeRawData("tfhd", 4);
    stream<<quint8(0); //version
    stream<<quint8(2); //flags //dlaczego 2?
    stream<<quint16(0);
    stream<<quint32(trackID);
    return 16;
}
////////////////////////////////////////////////////////////////////////////////////////////
unsigned int DashCreator::writeTfdt(const unsigned long int& baseMediaDecodeTime, QFile* dashFile) {
    QDataStream stream(dashFile);
    stream<<quint32(16); //size
    stream.writeRawData("tfdt", 4);
    int version;
    if(baseMediaDecodeTime > 65535)
        version = 1;
    else
        version = 0;
    stream<<quint8(version); //version
    stream<<quint8(0); //flags //dlaczego 2?
    stream<<quint16(0);
    if(version)
        stream<<quint64(baseMediaDecodeTime);
    else
        stream<<quint32(baseMediaDecodeTime);
    return 16;
}
////////////////////////////////////////////////////////////////////////////////////////////
unsigned int DashCreator::writeTrun(const unsigned int& flag2, const unsigned int& flag3, const unsigned int& sampleCount,
                                    const signed int& dataOffset, const unsigned int& firstSampleFlags, const unsigned long int& firstSample,
                                    std::shared_ptr<Box>& stsz, QFile* dashFile) {
    QDataStream stream(dashFile);
    int size = 16; //size + type + version + flags + sampleCount
    if(flag2 == 2) //sample sizes are present
        size += sampleCount*4;
    if(flag3 == 1 || flag3 == 4) //1- data-offset, 4 - firstsampleflags
        size += 4;
    else if(flag3 == 5) //oba
        size += 8;
    stream<<quint32(size); //size
    stream.writeRawData("trun", 4);
    stream<<quint8(0); //version
    stream<<quint8(0); //flags
    stream<<quint8(flag2);
    stream<<quint8(flag3);
    stream<<quint32(sampleCount); //sample count
    if(flag3 == 1 || flag3 == 5)
        stream<<qint32(dataOffset);
    if(flag3 == 2 || flag3 == 5)
        stream<<quint32(firstSampleFlags);
    if(flag2 == 2) {
        for(unsigned int i = firstSample; i< firstSample + sampleCount; ++i) {
            stream<<quint32(stsz->getSampleSize(i));
        }
    }
    return size;
}
////////////////////////////////////////////////////////////////////////////////////////////
unsigned int DashCreator::writeSidx(const unsigned short int& version, const unsigned int& referenceID, const unsigned int& timescale,
                                    const unsigned long int& earliestPresentationTime, const unsigned long int& firstOffset,
                                    const unsigned int& referenceCount, const QList<unsigned long int>& referenceType,
                                    const QList<unsigned long int>& referenceSize, const QList<unsigned long int>& subsegmentDuration,
                                    const QList <unsigned short int>& startsWithSAP, const QList <unsigned short int>& SAPType,
                                    const QList <unsigned long int>& SAPDeltaTime, QFile *dashFile) {
    qDebug()<<"referencecount"<<QString::number(referenceCount);
    QDataStream stream(dashFile);
    unsigned int size = 12; //bo dziedziczy po FullBox
    size += 8; //referenceID, timescale
    if(version)
        size += 16; //earliestPresentationTime, firstOffset
    else
        size += 8;
    size += 4; //reserved, referenceCount
    size += referenceCount*12;
    stream<<quint32(size);
    stream.writeRawData("sidx", 4);
    stream<<quint8(version); //version
    stream<<quint8(0); //flags
    stream<<quint16(0);
    stream<<quint32(referenceID);
    stream<<quint32(timescale);
    if(version) {
        stream<<quint64(earliestPresentationTime);
        stream<<quint64(firstOffset);
    }
    else {
        stream<<quint32(earliestPresentationTime);
        stream<<quint32(firstOffset);
    }
    stream<<quint16(0); //reserved
    stream<<quint16(referenceCount);
    for(unsigned int i = 0; i <referenceCount; ++i) {
        unsigned long int tmp = referenceType.at(i);
        tmp = tmp << 31;
        tmp += referenceSize.at(i);
        stream<<quint32(tmp);
        stream<<quint32(subsegmentDuration.at(i));
        tmp = startsWithSAP.at(i);
        tmp = tmp << 3;
        tmp += SAPType.at(i);
        tmp = tmp <<28;
        tmp += SAPDeltaTime.at(i);
        stream<<quint32(tmp);
    }
    return size;
}
