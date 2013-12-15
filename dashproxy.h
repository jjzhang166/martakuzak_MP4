#ifndef DASHPROXY_H
#define DASHPROXY_H

#include "dashcreator.h"
#include "treemodel.h"

class TreeModel;
class DashCreator;

class DashProxy
{
public:
    DashProxy(const QString& fileName, TreeModel* model);
    void closeFileStream();
    unsigned long int mdatSize(const unsigned long int& firstSample, const unsigned int& sampleNumber, std::shared_ptr<Box>& stsz);
    unsigned int writeMdat(const unsigned long int& firstSample, const unsigned int& sampleNumber, std::shared_ptr<Box>& stsz,
                           QFile* dashFile);
    unsigned int writeMoof(const unsigned long int& sequenceNumber, const unsigned int& trackID, const unsigned long &baseMediaDecodeTime,
                           const unsigned int& trunFlag2,const unsigned int& trunFlag3, const unsigned int& sampleCount,
                           const signed int& dataOffset,const unsigned int& firstSampleFlags, const unsigned long int& firstSample,
                           std::shared_ptr<Box>& stsz, QFile* dashFile);
    unsigned int writeMfhd(const unsigned long int& sequenceNumber, QFile* dashFile);
    unsigned int writeTraf(const unsigned int& trackID, const unsigned long &baseMediaDecodeTime, const unsigned int& trunFlag2,
                           const unsigned int& trunFlag3, const unsigned int& sampleCount, const signed int& dataOffset,
                           const unsigned int& firstSampleFlags, const unsigned long int& firstSample, std::shared_ptr<Box>& stsz,
                           QFile* dashFile);
    unsigned int writeTfhd(const unsigned int& trackID, QFile* dashFile);
    unsigned int writeTfdt(const unsigned long &baseMediaDecodeTime, QFile* dashFile);
    unsigned int writeTrun(const unsigned int& flag2, const unsigned int& flag3, const unsigned int& sampleCount,
                           const signed int& dataOffset, const unsigned int& firstSampleFlags, const unsigned long int& firstSample,
                           std::shared_ptr<Box>& stsz, QFile* dashFile);
    unsigned int writeSidx(const unsigned short int& version, const unsigned int& referenceID, const unsigned int& timescale,
                           const unsigned long int& earliestPresentationTime, const unsigned long int& firstOffset,
                           const unsigned int &referenceCount, const QList<unsigned short int>& referenceType,
                           const QList<unsigned long int>& referenceSize, const QList<unsigned long int>& subsegmentDuration,
                           const QList <unsigned short int>& startsWithSAP, const QList <unsigned short int>& SAPType,
                           const QList <unsigned long int>& SAPDeltaTime, QFile* dashFile);
    void writeSegments(const unsigned int &maxSampleNum, QFile* dashFile);

private:
    DashCreator* dashCreator;
};

#endif // DASHPROXY_H
