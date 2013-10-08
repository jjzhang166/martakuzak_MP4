/*!
 * \file SampleEntry
 * \details
 * SampleEntry
 * HintSampleEntry
 * VisualSampleEntry
 * AudioSampleEntry
 * MP4AudioSampleEntry
 * MP4VisualSampleEntry
 * MpegSampleEntry
 * ObjectDescriptorBox
 * ESDBox
 */
#ifndef SAMPLEENTRY_H
#define SAMPLEENTRY_H

#include "box.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SampleEntry: public Box {
private:
    unsigned int* reserved;
    unsigned int data_reference_index;
public:
    SampleEntry(const unsigned int &s=0, const QString &t="", const unsigned long &off=0, unsigned int e=0, const unsigned int &dri=0);
    virtual QString getFullName() { return QString("Sample Entry"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class HintSampleEntry: public SampleEntry {
public:
    HintSampleEntry(const unsigned int &s=0, const QString &t="", const unsigned long &off=0, const unsigned int& e=0);
    virtual QString getFullName() { return QString("Hint Sample Entry"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class VisualSampleEntry: public SampleEntry {
private:
    unsigned int pre_defined;
    unsigned int reserved2;
    unsigned int pre_defined1;
    unsigned int width;
    unsigned int height;
    unsigned int horizresolution; // 72 dpi
    unsigned int vertresolution; // 72 dpi
    unsigned int reserved3;
    unsigned int frame_count;
    QString compressorname;
    unsigned int depth;
    unsigned int pre_defined2;
public:
    VisualSampleEntry(const unsigned int &s=0, const QString &t="", const unsigned long &off=0, const unsigned int& e=0, const unsigned int& dri=0,
                      const unsigned int pd=0, const unsigned int& r2=0, const unsigned int & pd1=0,
                      const unsigned int&wdth=0, const unsigned int& hght=0, const unsigned int& hr=72,
                      const unsigned int& vr=72, const unsigned int& r3=0, const unsigned int& fc=1,
                      QString csn="", const unsigned int& dpth=0x0018, unsigned int pd2=-1);
    virtual bool isContainer() { return true; }
    unsigned int getWidth() { return width; }
    QString getQStringWidth() { return QString::number(width); }
    unsigned int getHeight() { return height; }
    unsigned int hResolution() { return horizresolution; }
    unsigned int vResolution() { return vertresolution; }
    virtual QString getFullName() { return QString("Visual Sample Entry"); }
    virtual QString getInfo();
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class AudioSampleEntry: public SampleEntry{
public:
    AudioSampleEntry(const unsigned int &s=0, const QString &t="", const unsigned long &off=0, const unsigned int& e=0);
    virtual QString getFullName() { return QString("Audio Sample Entry"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class MP4VisualSampleEntry : public VisualSampleEntry
{
public:
    MP4VisualSampleEntry(const unsigned int &s=0, const QString &t="", const unsigned long &off=0, const unsigned int& e=0, const unsigned int& dri=0,
                         const unsigned int pd=0, const unsigned int& r2=0, const unsigned int & pd1=0,
                         const unsigned int&wdth=0, const unsigned int& hght=0, const unsigned int& hr=72,
                         const unsigned int& vr=72, const unsigned int& r3=0, const unsigned int& fc=1,
                         QString csn="", const unsigned int& dpth=0x0018, unsigned int pd2=-1);
    virtual bool isContainer() { return true; }
    virtual unsigned int getOffset() { return 86; }
    virtual QString getFullName() { return QString("MP4 Visual Sample Entry"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class MP4AudioSampleEntry : public AudioSampleEntry
{
public:
    MP4AudioSampleEntry(const unsigned int &s=0, const QString &t="", const unsigned long &off=0, const unsigned int& e=0);
    virtual bool isContainer() { return true; }
    virtual unsigned int getOffset() { return 36; }
    virtual QString getFullName() { return QString("MP4 Audio Sample Entry"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class MpegSampleEntry : public SampleEntry
{
public:
    MpegSampleEntry(const unsigned int &s, const QString& t, const unsigned long &off, const unsigned int &e);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Mpeg Sample Entry"); }
};
//////////////MP4//////
class ObjectDescriptorBox : public FullBox
{
private:
    unsigned int version;
    QList<unsigned int> flags;
public:
    ObjectDescriptorBox(const unsigned int& s, const QString& t, const unsigned long int& off, const unsigned int& e, const unsigned int& v, const QList<unsigned int>& f);
    virtual QString getFullName() { return QString("Object Descriptor Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class ESDBox : public FullBox
{
private:
    unsigned int version;
    QList<unsigned int> flags;
public:
    ESDBox(const unsigned int& s, const QString& t, const unsigned long int& off, const unsigned int& e, const unsigned int& v,const QList<unsigned int>& f);
    virtual unsigned int getOffset() { return 8; }
    virtual QString getFullName() { return QString("ESD Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif // SAMPLEENTRY_H
