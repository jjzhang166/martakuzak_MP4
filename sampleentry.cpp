#include "sampleentry.h"

/////////////
SampleEntry::SampleEntry(const unsigned int& s, const QString& t, const unsigned long int& off, unsigned int e, const unsigned  int& dri):
    Box(s,t,off,e),
    data_reference_index(dri)
{}
/////////////
VisualSampleEntry::VisualSampleEntry(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int &  e, const unsigned  int& dri,
                                     const unsigned  int pd, const unsigned  int& r2, const unsigned  int& pd1,
                                     const unsigned  int& wdth, const unsigned  int& hght, const unsigned  int& hr,
                                     const unsigned  int& vr, const unsigned  int& r3, const unsigned  int& fc,
                                     QString csn, const unsigned  int& dpth, unsigned int pd2):
    SampleEntry(s,t,off,e, dri),
    pre_defined(pd),
    reserved2(r2),
    pre_defined1(pd1),
    width(wdth),
    height(hght),
    horizresolution(hr),
    vertresolution(vr),
    reserved3(r3),
    frame_count(fc),
    compressorname(csn),
    depth(dpth),
    pre_defined2(pd2)
{}
QString VisualSampleEntry::getInfo() {
    QString tmp("");
    tmp.append("width\t\t");
    tmp.append(QString::number(width));
    tmp.append("\nheight\t\t");
    tmp.append(QString::number(height));
    tmp.append("\nhorizonresolution\t");
    tmp.append(QString::number(horizresolution));
    tmp.append("\nvertresolution\t\t");
    tmp.append(QString::number(vertresolution));
    return tmp;
}

/////////////
AudioSampleEntry::AudioSampleEntry(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int &  e): SampleEntry(s,t,off,e) {}
/////////////
HintSampleEntry::HintSampleEntry(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int &  e): SampleEntry(s,t,off,e) {}
/////////////
MP4VisualSampleEntry::MP4VisualSampleEntry(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int &  e, const unsigned  int& dri,
                                           const unsigned  int pd, const unsigned  int& r2, const unsigned  int& pd1,
                                           const unsigned  int& wdth, const unsigned  int& hght, const unsigned  int& hr,
                                           const unsigned  int& vr, const unsigned  int& r3, const unsigned  int& fc,
                                           QString csn, const unsigned  int& dpth, unsigned int pd2): VisualSampleEntry(s,t,off,e,dri,pd,r2,pd1, wdth,
                                                                                                              hght, hr,vr, r3, fc, csn, dpth,
                                                                                                              pd2)
{}
///////////////
MP4AudioSampleEntry::MP4AudioSampleEntry(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int &  e): AudioSampleEntry(s,t,off,e) {}
///////////////
MpegSampleEntry::MpegSampleEntry(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int &  e): SampleEntry(s,t,off,e) {}
///////////////
/////MP4///////
ObjectDescriptorBox::ObjectDescriptorBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int &  e, const unsigned  int& v,const QList<unsigned int>& f):
    FullBox(s,t,off,e, v, f) ,
    version(v),
    flags(f)
{}
///////////////
ESDBox::ESDBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int &  e, const unsigned  int& v,const QList<unsigned int>& f):
    FullBox(s,t,off,e, v, f) ,
    version(v),
    flags(f)
{}
///////////////

