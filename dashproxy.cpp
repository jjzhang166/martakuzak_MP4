#include "dashproxy.h"

DashProxy::DashProxy(const QString& fileName, TreeModel* model) {
    dashCreator = new DashCreator(fileName, model);
}

unsigned long int DashProxy::mdatSize(const unsigned long int& firstSample, const unsigned int& sampleNumber, std::shared_ptr<Box>& stsz) {
    return dashCreator->mdatSize(firstSample, sampleNumber, stsz);
}

unsigned int DashProxy::writeMdat(const unsigned long int& firstSample, const unsigned int& sampleNumber, std::shared_ptr<Box>& stsz,
                       QFile* dashFile) {
    return dashCreator->writeMdat(firstSample, sampleNumber, stsz, dashFile);
}

unsigned int DashProxy::writeMoof(const unsigned long int& sequenceNumber, const unsigned int& trackID,
                                  const unsigned long &baseMediaDecodeTime, const unsigned int& trunFlag2, const unsigned int& trunFlag3,
                                  const unsigned int& sampleCount, const signed int& dataOffset, const unsigned int& firstSampleFlags,
                                  const unsigned long int& firstSample, std::shared_ptr<Box>& stsz, QFile* dashFile) {
    return dashCreator->writeMoof(sequenceNumber, trackID, baseMediaDecodeTime, trunFlag2, trunFlag3, sampleCount, dataOffset,
                                  firstSampleFlags, firstSample, stsz, dashFile);
}

unsigned int DashProxy::writeMfhd(const unsigned long int& sequenceNumber, QFile* dashFile) {
    return dashCreator->writeMfhd(sequenceNumber, dashFile);
}

unsigned int DashProxy::writeTraf(const unsigned int& trackID, const unsigned long &baseMediaDecodeTime, const unsigned int& trunFlag2,
                                  const unsigned int& trunFlag3, const unsigned int& sampleCount, const signed int& dataOffset,
                                  const unsigned int& firstSampleFlags, const unsigned long int& firstSample, std::shared_ptr<Box>& stsz,
                                  QFile* dashFile) {
    return dashCreator->writeTraf(trackID, baseMediaDecodeTime, trunFlag2, trunFlag3, sampleCount, dataOffset, firstSampleFlags, firstSample,
                                  stsz, dashFile);
}

unsigned int DashProxy::writeTfhd(const unsigned int& trackID, QFile* dashFile) {
    return dashCreator->writeTfhd(trackID, dashFile);
}

unsigned int DashProxy::writeTfdt(const unsigned long &baseMediaDecodeTime, QFile* dashFile) {
    return dashCreator->writeTfdt(baseMediaDecodeTime, dashFile);
}

unsigned int DashProxy::writeTrun(const unsigned int& flag2, const unsigned int& flag3, const unsigned int& sampleCount,
                                  const signed int& dataOffset, const unsigned int& firstSampleFlags, const unsigned long int& firstSample,
                                  std::shared_ptr<Box>& stsz, QFile* dashFile) {
    return dashCreator->writeTrun(flag2, flag3, sampleCount, dataOffset, firstSampleFlags, firstSample, stsz, dashFile);
}
