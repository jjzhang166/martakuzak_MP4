/*!
 * \file SampleTableBox
 * \details
 * ChunkLargeOffsetBox
 * ChunkOffsetBox
 * CompactSampleSizeBox
 * CompositionOffsetBox
 * DegradationPriorityBox
 * SampleDescriptionBox
 * SampleScaleBox
 * SampleSizeBox
 * SampleTableBox
 * SampleToChunkBox
 * ShadowSyncSampleBox
 * SyncSampleBox
 * TimeToSampleBox
 * PaddingBitsBox
 */
#ifndef SAMPLETABLEBOX_H
#define SAMPLETABLEBOX_H

#include "box.h"

class SampleTableBox : public Box
{
public:
    SampleTableBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Sample Table Box "); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class TimeToSampleBox : public FullBox
{
public:
    TimeToSampleBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("Time To Sample Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class CompositionOffsetBox : public FullBox
{
public:
    CompositionOffsetBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("Composition Offset Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/*!
 * \brief The SampleDescriptionBox class
 *
 *    -
 *    - Box Types: 'stsd'
 *    - Container: Sample Table Box('stbl')
 *    - Mandatory: Yes
 *    - Quantity: Exactly one
*/
class SampleDescriptionBox : public Box
{
private:
    int entry_count;
public:
    SampleDescriptionBox(int s=0, QString t="", long int off=0, int e=0, unsigned int ec=1);
    virtual bool isContainer() { return true; }
    virtual unsigned int getOffset() { return (16); }
    virtual QString getFullName() { return QString("Sample Description Box"); }
    /*!
     * \brief getEntryCount
     * \return entry_count
     */
    unsigned int getEntryCount() { return entry_count; }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SampleSizeBox : public FullBox
{
public:
    SampleSizeBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("Sample Size Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class CompactSampleSizeBox : public FullBox
{
public:
    CompactSampleSizeBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("Compact Sample Size Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SampleToChunkBox : public FullBox
{
public:
    SampleToChunkBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("Sample To Chunk Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class ChunkOffsetBox : public FullBox
{
public:
    ChunkOffsetBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("Chunk Offset Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class ChunkLargeOffsetBox : public FullBox
{
public:
    ChunkLargeOffsetBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("Chunk Large Offset Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SyncSampleBox : public FullBox
{
public:
    SyncSampleBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("Sync Sample Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class ShadowSyncSampleBox : public FullBox
{
public:
    ShadowSyncSampleBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("Shadow Sync Sample Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class DegradationPriorityBox : public FullBox
{
public:
    DegradationPriorityBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("Degradation Priority Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class PaddingBitsBox : public FullBox
{
public:
    PaddingBitsBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("Padding Bits Box"); }
};
#endif // SAMPLETABLEBOX_H
