#include "sampletablebox.h"

SampleTableBox::SampleTableBox(const int& s, const QString& t, const long int& off, const int &  e): Box(s,t,off,e) {}
/////////////
/////////////
TimeToSampleBox::TimeToSampleBox(const int& s, const QString& t, const long int& off, const int &  e): FullBox(s,t,off,e) {}
/////////////
CompositionOffsetBox::CompositionOffsetBox(const int& s, const QString& t, const long int& off, const int &  e): FullBox(s,t,off,e) {}
/////////////
SampleDescriptionBox::SampleDescriptionBox(int s, QString t, long int off, int e, unsigned int ec):
    Box(s,t,off,e),
    entry_count(ec)
{}
/////////////
SampleSizeBox::SampleSizeBox(const int& s, const QString& t, const long int& off, const int &  e): FullBox(s,t,off,e) {}
/////////////
CompactSampleSizeBox::CompactSampleSizeBox(const int& s, const QString& t, const long int& off, const int &  e): FullBox(s,t,off,e) {}
/////////////
SampleToChunkBox::SampleToChunkBox(const int& s, const QString& t, const long int& off, const int &  e): FullBox(s,t,off,e) {}
/////////////
ChunkOffsetBox::ChunkOffsetBox(const int& s, const QString& t, const long int& off, const int &  e): FullBox(s,t,off,e) {}
/////////////
ChunkLargeOffsetBox::ChunkLargeOffsetBox(const int& s, const QString& t, const long int& off, const int &  e): FullBox(s,t,off,e) {}
/////////////
SyncSampleBox::SyncSampleBox(const int& s, const QString& t, const long int& off, const int &  e): FullBox(s,t,off,e) {}
/////////////
ShadowSyncSampleBox::ShadowSyncSampleBox(const int& s, const QString& t, const long int& off, const int &  e): FullBox(s,t,off,e) {}
/////////////
DegradationPriorityBox::DegradationPriorityBox(const int& s, const QString& t, const long int& off, const int &  e): FullBox(s,t,off,e) {}
///////////////
PaddingBitsBox::PaddingBitsBox(const int& s, const QString& t, const long int& off, const int &  e): FullBox(s,t,off,e) {}
