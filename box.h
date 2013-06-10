#ifndef BOX_H
#define BOX_H

#include <QString>
#include <qDebug>
#include <QMap>
#include <iostream>

/*!
 * \brief The Box class
 * is represantion of MP4 Box
 */

class Box {
private:
    /*!
     * \brief size size of the box
     */
    int size;
    /*!
     * \brief type type of the box
     */
    QString type;
    /*!
     * \brief offset bit offset of the box location
     */
    long int offset;
    /*!
     * \brief extended_type indicates whether the box has extended type (1) or not (0)
     */
    int extended_type;
    /*!
     * \brief otherBoxOffset bit byte distance between begin of box and the begin of boxes from the box
     * (for boxes who are containers)
     */
    long int otherBoxOffset;
public:
    /*!
     * \brief Box
     * constructor
     * \param s size
     * \param t type
     * \param off offset
     * \param e extended_type (0 or 1)
     */
    Box(int s=0,QString t="", long int off=0, int e=0);
    virtual bool isContainer() { return false; }
    virtual unsigned int getOffset() { return 8; }
    virtual QString getType() { return type; }
    virtual QString getFullName() { return QString(" "); }
    //Box(Box& box);
};
/////////////////////////////////////////////////////////////////////////////////////////////////
class FullBox : public Box
{
public:
    FullBox(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString(" "); }

};
//////////////////////////////////////////////////////////////////////////////////////////////////
class FileTypeBox : public Box
{
public:
    FileTypeBox(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("File Type Box"); }

};
/////////////////////////////////////////////////////////////////////////////////////////////////////
class MediaBox : public Box
{
public:
    MediaBox(int s=0,QString t="", long int off=0, int e=0);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Media Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////
class MediaDataBox : public Box
{
public:
    MediaDataBox(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("Media Data Box"); }
};
//////////////////////////////////////////////////////////////////////////////////////////////////////
class MediaHeaderBox : public FullBox
{
public:
    MediaHeaderBox(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("Media Header Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class MovieBox : public Box
{
public:
    MovieBox(int s=0,QString t="", long int off=0, int e=0);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Movie Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class MovieHeaderBox : public FullBox
{
public:
    MovieHeaderBox(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("Movie Header Box "); }

};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class TrackBox : public Box
{
public:
    TrackBox(int s=0,QString t="", long int off=0, int e=0);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Track Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class TrackHeaderBox : public FullBox
{
public:
    TrackHeaderBox(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("Track Header Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class TrackReferenceBox : public Box
{
public:
    TrackReferenceBox(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("Track Reference Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class HandlerBox : public FullBox
{
public:
    HandlerBox(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("Handler Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class MediaInformationBox : public Box
{
public:
    MediaInformationBox(int s=0,QString t="", long int off=0, int e=0);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Media Information Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class VideoMediaHeaderBox : public FullBox
{
public:
    VideoMediaHeaderBox(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("Video Media Header Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SoundMediaHeaderBox : public FullBox
{
public:
    SoundMediaHeaderBox(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("Sound Media Header Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class HintMediaHeaderBox : public FullBox
{
public:
    HintMediaHeaderBox(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("Hint Media Header Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class NullMediaHeaderBox : public FullBox
{
public:
    NullMediaHeaderBox(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("Null Media Header Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class DataInformationBox : public Box
{
public:
    DataInformationBox(int s=0,QString t="", long int off=0, int e=0);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Data Information Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class DataEntryUrnBox : public FullBox
{
public:
    DataEntryUrnBox(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("Data Entry URN Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class DataEntryUrlBox : public FullBox
{
public:
    DataEntryUrlBox(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("Data Entry URL Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class DataReferenceBox : public FullBox
{
public:
    DataReferenceBox(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("Data Reference Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
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
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class FreeSpaceBox : public Box
{
private:
    bool container;
public:
    FreeSpaceBox(bool container=false,int s=0,QString t="", long int off=0, int e=0);
    virtual bool isContainer() { return container; }
    virtual QString getFullName() { return QString("Free Space Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class EditBox : public Box
{
public:
    EditBox(int s=0,QString t="", long int off=0, int e=0);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Edit Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class EditListBox : public Box
{
public:
    EditListBox(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("Edit List Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class UserDataBox : public Box
{
public:
    UserDataBox(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("User Data Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class CopyRightBox : public FullBox
{
public:
    CopyRightBox(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("CopyRight Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class MovieExtendsBox : public Box
{
public:
    MovieExtendsBox(int s=0,QString t="", long int off=0, int e=0);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Movie Extends Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class MovieExtendsHeaderBox : public FullBox
{
public:
    MovieExtendsHeaderBox(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("Movie Extends Header Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class TrackExtendsBox : public FullBox
{
public:
    TrackExtendsBox(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("Track Extends Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class MovieFragmentBox : public Box
{
public:
    MovieFragmentBox(int s=0,QString t="", long int off=0, int e=0);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Movie Fragment Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class MovieFragmentHeaderBox : public FullBox
{
public:
    MovieFragmentHeaderBox(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("Movie Fragment Header Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class TrackFragmentBox : public Box
{
public:
    TrackFragmentBox(int s=0,QString t="", long int off=0, int e=0);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Track Fragment Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class TrackFragmentHeaderBox : public FullBox
{
public:
    TrackFragmentHeaderBox(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("Track Fragment Header Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class TrackRunBox : public FullBox
{
public:
    TrackRunBox(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("Track Run Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class MovieFragmentRandomAccessBox : public Box
{
public:
    MovieFragmentRandomAccessBox(int s=0,QString t="", long int off=0, int e=0);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Movie Fragment Access Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class TrackFragmentRandomAccessBox : public FullBox
{
public:
    TrackFragmentRandomAccessBox(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("Track Fragment Random Access Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class MovieFragmentRandomAccessOffsetBox : public FullBox
{
public:
    MovieFragmentRandomAccessOffsetBox(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("Movie Fragment Random Access Offset Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SampleDependencyTypeBox : public FullBox
{
public:
    SampleDependencyTypeBox(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("Sample Dependency Type Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SampleToGroupBox : public FullBox
{
public:
    SampleToGroupBox(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("Sample To Group Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SampleGroupDescriptionBox : public FullBox
{
public:
    SampleGroupDescriptionBox(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("Sample Group Description Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SampleScaleBox : public FullBox
{
public:
    SampleScaleBox(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("sample Scale Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SubSampleInformationBox : public FullBox
{
public:
    SubSampleInformationBox(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("Sub Sample Information Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class ProgressiveDownloadInfoBox : public FullBox
{
public:
    ProgressiveDownloadInfoBox(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("Pogressive Donwload Info Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class MetaBox : public FullBox
{
public:
    MetaBox(int s=0,QString t="", long int off=0, int e=0);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Meta Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class XMLBox : public FullBox
{
public:
    XMLBox(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("XML Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class BinaryXMLBox : public FullBox
{
public:
    BinaryXMLBox(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("Binary XML Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class ItemLocationBox : public FullBox
{
public:
    ItemLocationBox(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("Item Location Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class PrimaryItemBox : public FullBox
{
public:
    PrimaryItemBox(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("Primary Item Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class ItemProtectionBox : public FullBox
{
public:
    ItemProtectionBox(int s=0,QString t="", long int off=0, int e=0);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Item Protection Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class ItemInfoEntry : public FullBox
{
public:
    ItemInfoEntry(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("Item Intfo Entry"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class ItemInfoBox : public FullBox
{
public:
    ItemInfoBox(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("Item Info Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class ProtectionSchemeInfoBox : public Box
{
public:
    ProtectionSchemeInfoBox(int s=0,QString t="", long int off=0, int e=0);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Protection Scheme Info Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class OriginalFormatBox : public Box
{
public:
    OriginalFormatBox(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("Original Format Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class IPMPInfoBox : public FullBox
{
public:
    IPMPInfoBox(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("IPMP Info Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class IPMPControlBox : public FullBox
{
public:
    IPMPControlBox(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("IPMP Control Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SchemeTypeBox : public FullBox
{
public:
    SchemeTypeBox(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("Scheme Type Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SchemeInformationBox : public Box
{
public:
    SchemeInformationBox(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("Scheme Information Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class TimeScaleEntry : public Box
{
public:
    TimeScaleEntry(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("Time Scale Entry"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class TimeOffset : public Box
{
public:
    TimeOffset(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("Time Offset"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SequenceOffset : public Box
{
public:
    SequenceOffset(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("Sequence Offset"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SRTPProcessBox : public FullBox
{
public:
    SRTPProcessBox(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("SRTP Process Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class MovieHintInformation : public Box
{
public:
    MovieHintInformation(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("Movie Hint Information"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class RTPMovieHintInformation : public Box
{
public:
    RTPMovieHintInformation(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("RTP Movie Hint Information"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class RTPTrackSDPHintInformation : public Box
{
public:
    RTPTrackSDPHintInformation(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("RTP Track SDP Hint Information"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class HintStatisticsBox : public Box
{
public:
    HintStatisticsBox(int s=0,QString t="", long int off=0, int e=0);
    virtual QString getFullName() { return QString("Hint Statistics Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // BOX_H

