#include "sampletablebox.h"

SampleTableBox::SampleTableBox(const unsigned int& s, const QString& t, const unsigned long int& off, const unsigned int &  e): Box(s,t,off,e) {}
/////////////
/////////////
TimeToSampleBox::TimeToSampleBox(const unsigned int& s, const QString& t, const unsigned long int& off, const unsigned int &  e, const unsigned int& v, const QList<unsigned int>& f,
                                 unsigned int ec, QList<unsigned int> sc, QList<unsigned int> sd):
    FullBox(s,t,off,e, v, f) ,
    version(v),
    flags(f),
    entryCount(ec),
    sampleCount(sc),
    sampleDelta(sd)
{}
/////////////
CompositionOffsetBox::CompositionOffsetBox(const unsigned int& s, const QString& t, const unsigned long int& off, const unsigned int &  e, const unsigned int& v, const QList<unsigned int>& f):
    FullBox(s,t,off,e, v, f) ,
    version(v),
    flags(f)
{}
/////////////
SampleDescriptionBox::SampleDescriptionBox(unsigned int s, QString t, unsigned long int off, unsigned int e, unsigned  int ec):
    Box(s,t,off,e),
    entry_count(ec)
{}
/////////////
SampleSizeBox::SampleSizeBox(const unsigned int& s, const QString& t, const unsigned long int& off, const unsigned int &  e, const unsigned int& v, const QList<unsigned int>& f):
    FullBox(s,t,off,e, v, f) ,
    version(v),
    flags(f)
{}
/////////////
CompactSampleSizeBox::CompactSampleSizeBox(const unsigned int& s, const QString& t, const unsigned long int& off, const unsigned int &  e, const unsigned int& v, const QList<unsigned int>& f):
    FullBox(s,t,off,e, v, f) ,
    version(v),
    flags(f)
{}
/////////////
SampleToChunkBox::SampleToChunkBox(const unsigned int& s, const QString& t, const unsigned long int& off, const unsigned int &  e, const unsigned int& v, const QList<unsigned int>& f):
    FullBox(s,t,off,e, v, f) ,
    version(v),
    flags(f)
{}
/////////////
ChunkOffsetBox::ChunkOffsetBox(const unsigned int& s, const QString& t, const unsigned long int& off, const unsigned int &  e, const unsigned int& v, const QList<unsigned int>& f):
    FullBox(s,t,off,e, v, f) ,
    version(v),
    flags(f)
{}
/////////////
ChunkLargeOffsetBox::ChunkLargeOffsetBox(const unsigned int& s, const QString& t, const unsigned long int& off, const unsigned int &  e, const unsigned int& v, const QList<unsigned int>& f):
    FullBox(s,t,off,e, v, f) ,
    version(v),
    flags(f)
{}
/////////////
SyncSampleBox::SyncSampleBox(const unsigned int& s, const QString& t, const unsigned long int& off, const unsigned int &  e, const unsigned int& v, const QList<unsigned int>& f):
    FullBox(s,t,off,e, v, f) ,
    version(v),
    flags(f)
{}
/////////////
ShadowSyncSampleBox::ShadowSyncSampleBox(const unsigned int& s, const QString& t, const unsigned long int& off, const unsigned int &  e, const unsigned int& v, const QList<unsigned int>& f):
    FullBox(s,t,off,e, v, f) ,
    version(v),
    flags(f)
{}
////////////
DegradationPriorityBox::DegradationPriorityBox(const unsigned int& s, const QString& t, const unsigned long int& off, const unsigned int &  e, const unsigned int& v, const QList<unsigned int>& f):
    FullBox(s,t,off,e, v, f) ,
    version(v),
    flags(f)
{}
///////////////
PaddingBitsBox::PaddingBitsBox(const unsigned int& s, const QString& t, const unsigned long int& off, const unsigned int &  e, const unsigned int& v, const QList<unsigned int>& f):
    FullBox(s,t,off,e, v, f) ,
    version(v),
    flags(f)
{}
