#ifndef SAMPLETABLEBOX_H
#define SAMPLETABLEBOX_H

#include "box.h"
class SampleTableBox : public Box
{
public:
    SampleTableBox(int s=0,QString t="", long int off=0, int e=0);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Sample Table Box "); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class TimeToSampleBox : public FullBox
{
public:
    TimeToSampleBox(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("Time To Sample Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class CompositionOffsetBox : public FullBox
{
public:
    CompositionOffsetBox(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("Composition Offset Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SampleDescriptionBox : public Box
{
private:
    int i;
    int entry;
public:
    SampleDescriptionBox(int s=0,QString t="", long int off=0, int e=0);
    virtual bool isContainer() { return true; }
    virtual unsigned int getOffset() { return (16); }
    virtual QString getFullName() { return QString("Sample Description Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SampleSizeBox : public FullBox
{
public:
    SampleSizeBox(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("Sample Size Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class CompactSampleSizeBox : public FullBox
{
public:
    CompactSampleSizeBox(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("Compact Sample Size Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SampleToChunkBox : public FullBox
{
public:
    SampleToChunkBox(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("Sample To Chunk Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class ChunkOffsetBox : public FullBox
{
public:
    ChunkOffsetBox(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("Chunk Offset Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class ChunkLargeOffsetBox : public FullBox
{
public:
    ChunkLargeOffsetBox(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("Chunk Large Offset Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SyncSampleBox : public FullBox
{
public:
    SyncSampleBox(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("Sync Sample Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class ShadowSyncSampleBox : public FullBox
{
public:
    ShadowSyncSampleBox(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("Shadow Sync Sample Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class DegradationPriorityBox : public FullBox
{
public:
    DegradationPriorityBox(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("Degradation Priority Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class PaddingBitsBox : public FullBox
{
public:
    PaddingBitsBox(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("Padding Bits Box"); }
};
#endif // SAMPLETABLEBOX_H
