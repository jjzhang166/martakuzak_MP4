#include "sampletablebox.h"

SampleTableBox::SampleTableBox(const int& s, const QString& t, const long int& off, const int &  e): Box(s,t,off,e) {}
/////////////
/////////////
TimeToSampleBox::TimeToSampleBox(const int& s, const QString& t, const long int& off, const int &  e, const int& v, const QList<int>& f):
    FullBox(s,t,off,e, v, f) ,
    version(v),
    flags(f)
{}
/////////////
CompositionOffsetBox::CompositionOffsetBox(const int& s, const QString& t, const long int& off, const int &  e, const int& v, const QList<int>& f):
    FullBox(s,t,off,e, v, f) ,
    version(v),
    flags(f)
{}
/////////////
SampleDescriptionBox::SampleDescriptionBox(int s, QString t, long int off, int e, unsigned int ec):
    Box(s,t,off,e),
    entry_count(ec)
{}
/////////////
SampleSizeBox::SampleSizeBox(const int& s, const QString& t, const long int& off, const int &  e, const int& v, const QList<int>& f):
    FullBox(s,t,off,e, v, f) ,
    version(v),
    flags(f)
{}
/////////////
CompactSampleSizeBox::CompactSampleSizeBox(const int& s, const QString& t, const long int& off, const int &  e, const int& v, const QList<int>& f):
    FullBox(s,t,off,e, v, f) ,
    version(v),
    flags(f)
{}
/////////////
SampleToChunkBox::SampleToChunkBox(const int& s, const QString& t, const long int& off, const int &  e, const int& v, const QList<int>& f):
    FullBox(s,t,off,e, v, f) ,
    version(v),
    flags(f)
{}
/////////////
ChunkOffsetBox::ChunkOffsetBox(const int& s, const QString& t, const long int& off, const int &  e, const int& v, const QList<int>& f):
    FullBox(s,t,off,e, v, f) ,
    version(v),
    flags(f)
{}
/////////////
ChunkLargeOffsetBox::ChunkLargeOffsetBox(const int& s, const QString& t, const long int& off, const int &  e, const int& v, const QList<int>& f):
    FullBox(s,t,off,e, v, f) ,
    version(v),
    flags(f)
{}
/////////////
SyncSampleBox::SyncSampleBox(const int& s, const QString& t, const long int& off, const int &  e, const int& v, const QList<int>& f):
    FullBox(s,t,off,e, v, f) ,
    version(v),
    flags(f)
{}
/////////////
ShadowSyncSampleBox::ShadowSyncSampleBox(const int& s, const QString& t, const long int& off, const int &  e, const int& v, const QList<int>& f):
    FullBox(s,t,off,e, v, f) ,
    version(v),
    flags(f)
{}
////////////
DegradationPriorityBox::DegradationPriorityBox(const int& s, const QString& t, const long int& off, const int &  e, const int& v, const QList<int>& f):
    FullBox(s,t,off,e, v, f) ,
    version(v),
    flags(f)
{}
///////////////
PaddingBitsBox::PaddingBitsBox(const int& s, const QString& t, const long int& off, const int &  e, const int& v, const QList<int>& f):
    FullBox(s,t,off,e, v, f) ,
    version(v),
    flags(f)
{}
