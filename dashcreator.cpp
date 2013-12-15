#include "dashcreator.h"

DashCreator::DashCreator(const QString &fn, TreeModel* m): fileName(fn), model(m) {
    file = new QFile(fileName);
    if (!file->open(QIODevice::ReadOnly)) {
        return ;
    }
}
////////////////////////////////////////////////////////////////////////////////////////////
void DashCreator::closeFileStream() {
    file->close();
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
    unsigned long int size = mdatSize(firstSample, sampleNumber, stsz);
    if(dashFile == NULL)
        return size;
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
    if(size < 2028)
        array = file->read(size - 8);
    else {
        int number = (size - 8)/2028 + 1;
        int lastSize = (size - 8) % 2028;
        for(int i = 0; i < number; ++i) {
            if(i == number - 1 && lastSize) {
                array = file->read(lastSize);
            }
            else
                array = file->read(2028);
            dashFile->write(array);
        }
    }
    return size;
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
    if(dashFile == NULL)
        return size;
    stream<<quint32(size);
    stream.writeRawData("moof", 4);

    writeMfhd(sequenceNumber, dashFile);
    writeTraf(trackID, baseMediaDecodeTime, trunFlag2, trunFlag3, sampleCount, dataOffset, firstSampleFlags, firstSample,
              stsz, dashFile);

    return size;
}
////////////////////////////////////////////////////////////////////////////////////////////
unsigned int DashCreator::writeMfhd(const unsigned long int& sequenceNumber, QFile* dashFile) {
    if(dashFile == NULL)
        return 16;
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
    if(dashFile == NULL)
        return size;
    stream<<quint32(size);
    stream.writeRawData("traf", 4);

    writeTfhd(trackID, dashFile);
    writeTfdt(baseMediaDecodeTime, dashFile);
    writeTrun(flag2, flag3, sampleCount, dataOffset, firstSampleFlags, firstSample, stsz, dashFile);

    return size;
}
////////////////////////////////////////////////////////////////////////////////////////////
unsigned int DashCreator::writeTfhd(const unsigned int& trackID, QFile* dashFile) {
    if(dashFile == NULL)
        return 16;
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
    if(dashFile == NULL)
        return 16;
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
    if(dashFile == NULL)
        return size;
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
                                    const unsigned int& referenceCount, const QList<unsigned short int>& referenceType,
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
    if(dashFile == NULL)
        return size;
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
////////////////////////////////////////////////////////////////////////////////////////////
void DashCreator::writeSegments(const unsigned int& maxSampleNum, QFile* dashFile) {
    qDebug()<<"dash creator write segments"<<"0";
    std::shared_ptr<Box> stsz = model->getBoxes("stsz").at(0); //Sample Size Box
    std::shared_ptr<Box> stss = model->getBoxes("stss").at(0); //Sync Sample Box
    std::shared_ptr<Box> mdhd = model->getBoxes("mdhd").at(0); //Media Header Box
    std::shared_ptr<Box> tkhd = model->getBoxes("tkhd").at(0); //Track Header Box
    unsigned int maxSegmentNum = stss->getEntryCount(); //segmentow tyle co sync punktow?
    unsigned int segmentID = 0; //aktualny numer segmentu
    unsigned long int sequenceNumber = 0;
    unsigned long int baseMediaDecodeTime = 0;

    while(segmentID < maxSegmentNum) {
        unsigned int subsegmentID = 0; //numer podsegmentu
        unsigned int firstSample = stss->getSyncSample(subsegmentID); //numer pierwszej probki segmentu
        unsigned int secondSample = stss->getSyncSample(subsegmentID + 1); //numer pierwszej probki poza segmentem
        unsigned int samplesInSubsegmentNum = secondSample - firstSample; //ilosc probek w segmencie
        //qDebug()<<"dashcreator writeSeg"<<"subsegmentLen"<<QString::number(samplesInSubsegmentNum);
        unsigned int subsegmentNum = 1; //ilosc podsegmentow - co najmniej 1
        if(samplesInSubsegmentNum > maxSampleNum) { //jesli jest ich wiecej niz maxSampleNum
            subsegmentNum = samplesInSubsegmentNum/maxSampleNum; //to ilosc podsegmentow jest ilorazem wszystkich probek w segmencie i maxSampleNum
            if(samplesInSubsegmentNum % maxSampleNum) {//zaokraglone ku gorze
                ++ subsegmentNum;
            }
        }
        //write sidx
        //przygotowanie parametrow
        unsigned short int version = 0;
        unsigned int referenceID = tkhd->getTrackID(); //numer tracku z tkhd
        unsigned int timescale = mdhd->getMediaTimeScale(); //timescale z mdhd
        unsigned long int earliestPresentationTime = stss->getSyncSample(segmentID) - 1;//odleglosc od poprzedniej sync sample?
        unsigned long int firstOffset = 0; //?
        unsigned int referenceCount = subsegmentNum;
        QList <unsigned short int> referenceType;
        QList <unsigned long int> referenceSize;
        QList <unsigned long int> subsegmentDuration;
        QList <unsigned short int> startsWithSAP;
        QList <unsigned short int> SAPType;
        QList <unsigned long int> SAPDeltaTime;
        while(subsegmentID < subsegmentNum) { //dla wszystkich podsegmentow
            unsigned long int baseTMP = baseMediaDecodeTime;
            unsigned long int sequenceTMP = sequenceNumber;
            unsigned int subsegmentLen = maxSampleNum; //normalnie wynosi maxSampleNum
            if(subsegmentID + 1 == subsegmentNum) //ale dla ostatniego podsegmentu to jest tylko reszta z dzielenia
                subsegmentLen = samplesInSubsegmentNum % maxSampleNum;
            referenceType.append(0);
            //przygotowanie parametrow moof
            referenceSize.append(writeMoof(++sequenceTMP, referenceID, baseTMP, 2, 5, subsegmentLen, 0 /**/,
                                           0, baseTMP , stsz)
                                 +
                                 mdatSize(baseTMP, subsegmentLen, stsz));
            qDebug()<<"why"<<QString::number(baseTMP)<<QString::number(subsegmentLen)<<QString::number(mdatSize(baseMediaDecodeTime, subsegmentLen, stsz));
            subsegmentDuration.append(subsegmentLen);
            startsWithSAP.append(subsegmentID == 0);
            SAPType.append(subsegmentID == 0);
            SAPDeltaTime.append(0);
            baseTMP += subsegmentLen;
            ++ subsegmentID;
        }
        writeSidx(version, referenceID, timescale, earliestPresentationTime, firstOffset, referenceCount, referenceType,
                  referenceSize, subsegmentDuration, startsWithSAP, SAPType, SAPDeltaTime, dashFile);
        subsegmentID = 0;
        while(subsegmentID < subsegmentNum) { //dla wszystkich podsegmentow
            unsigned int subsegmentLen = maxSampleNum; //normalnie wynosi maxSampleNum
            if(subsegmentID + 1 == subsegmentNum) //ale dla ostatniego podsegmentu to jest tylko reszta z dzielenia
                subsegmentLen = samplesInSubsegmentNum % maxSampleNum;

            //write moof
            writeMoof(++sequenceNumber, referenceID, baseMediaDecodeTime, 2, 5, subsegmentLen, 0 /**/,
                                                       0, baseMediaDecodeTime, stsz, dashFile);
            //write mdat
            writeMdat(baseMediaDecodeTime, subsegmentLen, stsz, dashFile);
            baseMediaDecodeTime += subsegmentLen;
            ++ subsegmentID;
        }
        qDebug()<<"dashcreator writeSeg"<<"base"<<QString::number(baseMediaDecodeTime);
        segmentID++;
    }
    /*std::shared_ptr<Box> stsz = model->getBoxes("stsz").at(0); //Sample Size Box
    std::shared_ptr<Box> stss = model->getBoxes("stss").at(0); //Sync Sample Box
    std::shared_ptr<Box> mdhd = model->getBoxes("mdhd").at(0); //Media Header Box
    std::shared_ptr<Box> tkhd = model->getBoxes("tkhd").at(0); //Track Header Box
    unsigned long int segmentNumber = stss->getEntryCount();
    qDebug()<<"dash creator write segments"<<"1"<<QString::number(segmentNumber);
    unsigned int tmpSyncSample = 0;
    qDebug()<<"dash creator"<<"1.1";
    for(unsigned int i = 0; i < segmentNumber; ++i) {
        qDebug()<<"dash creator"<<"1.2";
        int mediaSegmentLen =  0;
        qDebug()<<"dash creator"<<"1.3";
        unsigned int subsegmentNum = 1;
        qDebug()<<"dash creator write segments"<<"2";
        if(tmpSyncSample != (segmentNumber)) {
            //mediaSegmentLen = stsz->getSampleSize(stss->getSyncSample(i + 1)) - stsz->getSampleSize(stss->getSyncSample(i));
            mediaSegmentLen = mdatSize(stss->getSyncSample(i), stss->getSyncSample(i + 1) - stss->getSyncSample(i), stsz);
            subsegmentNum = mediaSegmentLen/maxSampleNum + 1;
            qDebug()<<"dash creator write segments"<<"2"<<QString::number(mediaSegmentLen)<<QString::number(maxSampleNum)<<QString::number(subsegmentNum);
        }
        return;
        qDebug()<<"dash creator write segments"<<"3";
        QList<unsigned long int> referenceType;
        QList<unsigned long int> referenceSize;
        QList<unsigned long int> subsegmentDuration;
        QList<unsigned short int> startsWithSAP;
        QList <unsigned short int> SAPType;
        QList <unsigned long int> SAPDeltaTime;

        for (unsigned int k = 0; k <subsegmentNum; ++k) {
            qDebug()<<"dash creator write segments"<<"4";
            referenceType.append(0);//?
            int sampleNumber;
            if(k == subsegmentNum)
                sampleNumber = stsz->getSyncSample(i+1) - tmpSyncSample;
            else
                sampleNumber = maxSampleNum;
            qDebug()<<"dash creator write segments"<<"5";
            referenceSize.append(writeMoof(k, tkhd->getTrackID(), stss->getEntryCount() + k*maxSampleNum - 1, 2, 5,
                                           mediaSegmentLen, 0, 0, stsz->getSyncSample(i) + maxSampleNum*k, stsz)
                                 +
                                 writeMdat(stsz->getSyncSample(i) + maxSampleNum*k, sampleNumber, stsz));
            subsegmentDuration.append(sampleNumber);
            startsWithSAP.append(k == 0);
            qDebug()<<"dash creator write segments"<<"6";
            SAPType.append(k == 0);
            SAPDeltaTime.append(0);
            tmpSyncSample += sampleNumber;
        }
        qDebug()<<"dash creator write segments"<<"7";
        writeSidx(0, tkhd->getTrackID(), mdhd->getMediaTimeScale(), stss->getSyncSample(i), 0, subsegmentNum, referenceType,
                  referenceSize, subsegmentDuration, startsWithSAP, SAPType, SAPDeltaTime, dashFile);
        qDebug()<<"dash creator write segments"<<"8";
        subsegmentNum = 1;
        for (unsigned int k = 0; k <subsegmentNum; ++k) {
            int sampleNumber;
            if(k == subsegmentNum)
                sampleNumber = stsz->getSyncSample(i+1) - tmpSyncSample;
            else
                sampleNumber = maxSampleNum;
            writeMoof(k, tkhd->getTrackID(), stss->getEntryCount() + k*maxSampleNum - 1, 2, 5,
                                                       mediaSegmentLen, 0, 0, stsz->getSyncSample(i) + maxSampleNum*k, stsz, dashFile);
            writeMdat(stsz->getSyncSample(i) + maxSampleNum*k, sampleNumber, stsz, dashFile);

        }
    }*/
}

