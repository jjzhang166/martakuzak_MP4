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
private:
    int version;
    QList<int> flags;
    int entryCount;
    QList<int> sampleCount;
    QList<int> sampleDelta;
public:
    TimeToSampleBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f,
                    int ec, QList<int> sc, QList<int> sd);
    virtual QString getFullName() { return QString("Time To Sample Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class CompositionOffsetBox : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    CompositionOffsetBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
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
private:
    int version;
    QList<int> flags;
public:
    SampleSizeBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString("Sample Size Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class CompactSampleSizeBox : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    CompactSampleSizeBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString("Compact Sample Size Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SampleToChunkBox : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    SampleToChunkBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString("Sample To Chunk Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class ChunkOffsetBox : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    ChunkOffsetBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString("Chunk Offset Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class ChunkLargeOffsetBox : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    ChunkLargeOffsetBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString("Chunk Large Offset Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SyncSampleBox : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    SyncSampleBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString("Sync Sample Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class ShadowSyncSampleBox : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    ShadowSyncSampleBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString("Shadow Sync Sample Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class DegradationPriorityBox : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    DegradationPriorityBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString("Degradation Priority Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class PaddingBitsBox : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    PaddingBitsBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString("Padding Bits Box"); }
};
#endif // SAMPLETABLEBOX_H
