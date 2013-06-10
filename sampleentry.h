#ifndef SAMPLEENTRY_H
#define SAMPLEENTRY_H

#include "box.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SampleEntry: public Box {
private:
    unsigned int* reserved;
    unsigned int data_reference_index;
public:
    SampleEntry(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("Sample Entry"); }
  //  void setReserved(cons)
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class HintSampleEntry: public SampleEntry {
public:
    HintSampleEntry(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("Hint Sample Entry"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class VisualSampleEntry: public SampleEntry {
private:
    unsigned int* reserved;
    unsigned int data_reference_index;
    unsigned int* pre_defined1 = 0;
    unsigned int reserved1 = 0;
    unsigned int pre_defined2;
    unsigned int width;
    unsigned int height;
    unsigned int horizresolution = 0x00480000; // 72 dpi
    unsigned int vertresolution = 0x00480000; // 72 dpi
    unsigned int reserved2 = 0;
    unsigned int frame_count = 1;
    QString compressorname;
    unsigned int depth = 0x0018;
    int pre_defined3 = -1;
public:
    VisualSampleEntry(int s=0,QString t="", long int off=0, int e=0);
    virtual bool isContainer() { return true; }
    virtual unsigned int getOffset() { return (16); }
    virtual QString getFullName() { return QString("Visual Sample Entry"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class AudioSampleEntry: public SampleEntry{
public:
    AudioSampleEntry(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("Audio Sample Entry"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class MP4VisualSampleEntry : public VisualSampleEntry
{
public:
    MP4VisualSampleEntry(int s=0,QString t="", long int off=0, int e=0);
    virtual bool isContainer() { return true; }
    virtual unsigned int getOffset() { return 86; }
    virtual QString getFullName() { return QString("MP4 Visual Sample Entry"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class MP4AudioSampleEntry : public AudioSampleEntry
{
public:
    MP4AudioSampleEntry(int s=0,QString t="", long int off=0, int e=0);
    virtual bool isContainer() { return true; }
    virtual unsigned int getOffset() { return 36; }
    virtual QString getFullName() { return QString("MP4 Audio Sample Entry"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class MpegSampleEntry : public SampleEntry
{
public:
    MpegSampleEntry(int s=0,QString t="", long int off=0, int e=0);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Mpeg Sample Entry"); }
};
//////////////MP4//////
class ObjectDescriptorBox : public FullBox
{
public:
    ObjectDescriptorBox(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("Object Descriptor Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class ESDBox : public FullBox
{
public:
    ESDBox(int s=0,QString t="", long int off=0, int e=0);
    virtual unsigned int getOffset() { return 8; }
    virtual QString getFullName() { return QString("ESD Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif // SAMPLEENTRY_H
