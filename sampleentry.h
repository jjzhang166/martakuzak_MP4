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
    QList<unsigned int> reserved;
    unsigned int data_reference_index;
public:
    SampleEntry(const unsigned int &s, const QString &t, const unsigned long int &off, const unsigned int &e, const QList<unsigned int>& res,
                const unsigned int &dri);
    virtual QString getFullName() { return QString("Sample Entry"); }
    virtual QString getInfo();
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class HintSampleEntry: public SampleEntry {
public:
    HintSampleEntry(const unsigned int &s, const QString &t, const unsigned long int &off, const unsigned int & e,
                    const QList<unsigned int>& res, const unsigned int &dri);
    virtual QString getFullName() { return QString("Hint Sample Entry"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class VisualSampleEntry: public SampleEntry {
private:
    unsigned int pre_defined;
    unsigned int reserved2;
    QList<unsigned int> pre_defined1;
    unsigned int width;
    unsigned int height;
    unsigned int horizresolution; // 72 dpi
    unsigned int vertresolution; // 72 dpi
    unsigned int reserved3;
    unsigned int frame_count;
    QString compressorname;
    unsigned int depth;
    int pre_defined2;
public:
    VisualSampleEntry(const unsigned int& s, const QString& t, const unsigned long int& off, const unsigned int &  e,
                      const QList<unsigned int>& res, const unsigned int &dri, const unsigned int &pd, const unsigned int& r2,
                      const QList<unsigned int>& pd1,const unsigned int& wdth, const unsigned int& hght, const unsigned  int& hr,
                      const unsigned int& vr, const unsigned int& r3, const unsigned int& fc, const QString & csn,
                      const unsigned int& dpth, const int &pd2);
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
private:
    QList<unsigned int> reserved1;
    unsigned int channelCount;
    unsigned int sampleSize;
    unsigned int predefined;
    unsigned int reserved2;
    unsigned int sampleRate;
public:
    AudioSampleEntry(const unsigned int &s, const QString &t, const unsigned long int &off, const unsigned int & e,
                     const QList<unsigned int>& res, const unsigned int &dri, const QList <unsigned int> & res1,
                     const unsigned int & chc, const unsigned int & ss, const unsigned int & pred, const unsigned int & res2,
                     const unsigned int & srate);
    virtual QString getFullName() { return QString("Audio Sample Entry"); }
    virtual QString getInfo();
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class MP4VisualSampleEntry : public VisualSampleEntry
{
public:
    MP4VisualSampleEntry(const unsigned int& s, const QString& t, const unsigned long int& off, const unsigned int &  e,
                         const QList<unsigned int>& res, const unsigned int &dri, const unsigned int &pd, const unsigned int& r2,
                         const QList<unsigned int>& pd1,const unsigned int& wdth, const unsigned int& hght, const unsigned  int& hr,
                         const unsigned int& vr, const unsigned int& r3, const unsigned int& fc, const QString & csn,
                         const unsigned int& dpth, const unsigned int &pd2);
    virtual bool isContainer() { return true; }
    virtual unsigned int getOffset() { return 86; }
    virtual QString getFullName() { return QString("MP4 Visual Sample Entry"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class MP4AudioSampleEntry : public AudioSampleEntry
{
public:
    MP4AudioSampleEntry(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int &  e,
                        const QList<unsigned int>& res, const unsigned int &dri, const QList<unsigned int> &res1,
                        const unsigned int &chc, const unsigned int &ss, const unsigned int &pred, const unsigned int &res2,
                        const unsigned int &srate);
    virtual bool isContainer() { return true; }
    virtual unsigned int getOffset() { return 36; }
    virtual QString getFullName() { return QString("MP4 Audio Sample Entry"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class MpegSampleEntry : public SampleEntry
{
public:
    MpegSampleEntry(const unsigned int& s, const QString& t, const unsigned long int& off, const unsigned int & e,
                    const QList<unsigned int> &res, const unsigned  int& dri);
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
