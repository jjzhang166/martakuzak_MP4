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
    SampleTableBox(const unsigned int& s=0, const QString& t="", const unsigned long int& off=0, const unsigned int& e=0);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Sample Table Box "); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class TimeToSampleBox : public FullBox
{
private:
    unsigned int version;
    QList<unsigned int> flags;
    unsigned int entryCount;
    QList<unsigned int> sampleCount;
    QList<unsigned int> sampleDelta;
public:
    TimeToSampleBox(const unsigned int& s, const QString& t, const unsigned long int& off, const unsigned int& e, const unsigned int& v, const QList<unsigned int>& f,
                    unsigned int ec, QList<unsigned int> sc, QList<unsigned int> sd);
    virtual QString getFullName() { return QString("Time To Sample Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class CompositionOffsetBox : public FullBox
{
private:
    unsigned int version;
    QList<unsigned int> flags;
public:
    CompositionOffsetBox(const unsigned int& s, const QString& t, const unsigned long int& off, const unsigned int& e, const unsigned int& v, const QList<unsigned int>& f);
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
    unsigned int entry_count;
public:
    SampleDescriptionBox(unsigned int s=0, QString t="", unsigned long int off=0, unsigned int e=0, unsigned  int ec=1);
    virtual bool isContainer() { return true; }
    virtual unsigned  int getOffset() { return (16); }
    virtual QString getFullName() { return QString("Sample Description Box"); }
    /*!
     * \brief getEntryCount
     * \return entry_count
     */
    unsigned  int getEntryCount() { return entry_count; }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SampleSizeBox : public FullBox
{
private:
    unsigned int version;
    QList<unsigned int> flags;
public:
    SampleSizeBox(const unsigned int& s, const QString& t, const unsigned long int& off, const unsigned int& e, const unsigned int& v, const QList<unsigned int>& f);
    virtual QString getFullName() { return QString("Sample Size Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class CompactSampleSizeBox : public FullBox
{
private:
    unsigned int version;
    QList<unsigned int> flags;
public:
    CompactSampleSizeBox(const unsigned int& s, const QString& t, const unsigned long int& off, const unsigned int& e, const unsigned int& v, const QList<unsigned int>& f);
    virtual QString getFullName() { return QString("Compact Sample Size Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SampleToChunkBox : public FullBox
{
private:
    unsigned int version;
    QList<unsigned int> flags;
public:
    SampleToChunkBox(const unsigned int& s, const QString& t, const unsigned long int& off, const unsigned int& e, const unsigned int& v, const QList<unsigned int>& f);
    virtual QString getFullName() { return QString("Sample To Chunk Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class ChunkOffsetBox : public FullBox
{
private:
    unsigned int version;
    QList<unsigned int> flags;
public:
    ChunkOffsetBox(const unsigned int& s, const QString& t, const unsigned long int& off, const unsigned int& e, const unsigned int& v, const QList<unsigned int>& f);
    virtual QString getFullName() { return QString("Chunk Offset Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class ChunkLargeOffsetBox : public FullBox
{
private:
    unsigned int version;
    QList<unsigned int> flags;
public:
    ChunkLargeOffsetBox(const unsigned int& s, const QString& t, const unsigned long int& off, const unsigned int& e, const unsigned int& v, const QList<unsigned int>& f);
    virtual QString getFullName() { return QString("Chunk Large Offset Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SyncSampleBox : public FullBox
{
private:
    unsigned int version;
    QList<unsigned int> flags;
public:
    SyncSampleBox(const unsigned int& s, const QString& t, const unsigned long int& off, const unsigned int& e, const unsigned int& v, const QList<unsigned int>& f);
    virtual QString getFullName() { return QString("Sync Sample Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class ShadowSyncSampleBox : public FullBox
{
private:
    unsigned int version;
    QList<unsigned int> flags;
public:
    ShadowSyncSampleBox(const unsigned int& s, const QString& t, const unsigned long int& off, const unsigned int& e, const unsigned int& v, const QList<unsigned int>& f);
    virtual QString getFullName() { return QString("Shadow Sync Sample Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class DegradationPriorityBox : public FullBox
{
private:
    unsigned int version;
    QList<unsigned int> flags;
public:
    DegradationPriorityBox(const unsigned int& s, const QString& t, const unsigned long int& off, const unsigned int& e, const unsigned int& v, const QList<unsigned int>& f);
    virtual QString getFullName() { return QString("Degradation Priority Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class PaddingBitsBox : public FullBox
{
private:
    unsigned int version;
    QList<unsigned int> flags;
public:
    PaddingBitsBox(const unsigned int& s, const QString& t, const unsigned long int& off, const unsigned int& e, const unsigned int& v, const QList<unsigned int>& f);
    virtual QString getFullName() { return QString("Padding Bits Box"); }
};
#endif // SAMPLETABLEBOX_H
