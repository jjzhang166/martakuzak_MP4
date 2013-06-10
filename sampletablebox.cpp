#include "sampletablebox.h"

SampleTableBox::SampleTableBox(int s,QString t, long int off, int e): Box(s,t,off,e) {}
/////////////
/////////////
TimeToSampleBox::TimeToSampleBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
/////////////
CompositionOffsetBox::CompositionOffsetBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
/////////////
SampleDescriptionBox::SampleDescriptionBox(int s,QString t, long int off, int e): Box(s,t,off,e) {}
/////////////
SampleSizeBox::SampleSizeBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
/////////////
CompactSampleSizeBox::CompactSampleSizeBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
/////////////
SampleToChunkBox::SampleToChunkBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
/////////////
ChunkOffsetBox::ChunkOffsetBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
/////////////
ChunkLargeOffsetBox::ChunkLargeOffsetBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
/////////////
SyncSampleBox::SyncSampleBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
/////////////
ShadowSyncSampleBox::ShadowSyncSampleBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
/////////////
DegradationPriorityBox::DegradationPriorityBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
///////////////
PaddingBitsBox::PaddingBitsBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
