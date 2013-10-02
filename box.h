#ifndef BOX_H
#define BOX_H

#include <QString>
#include <QList>
#include <qDebug>

/*!
 * \brief The Box class
 * is represantion of MP4 Box
 */

class Box
{
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
     * \param e extended_type
     */
    Box(const int& s, const QString& t, const long int& off, const int& e);
    /*!
     * \brief isContainer
     * \return true when box contains other boxes, false otherwise
     */
    virtual bool isContainer() { return false; }
    /*!
     * \brief getOffset
     * \return offset of child boxes
     */
    virtual unsigned int getOffset() { return 8; }
    /*!
     * \brief getType
     * \return type of the box
     */
    virtual QString getType() { return type; }
    /*!
     * \brief getFullName
     * \return fullName of the box, e.g. "Media Data Box"
     */
    virtual QString getFullName() { return QString(" "); }
    /*!
     * \brief getInfo
     * \return all the attributes fields in one formatted QString.
     */
    virtual QString getInfo() {return QString(" "); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////
class FullBox : public Box
{
private:
    int version;
    QList<int> flags;
public:
    FullBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString(" "); }

};
//////////////////////////////////////////////////////////////////////////////////////////////////
class FileTypeBox : public Box
{
private:
    QString majorBrand;
    QString minorVersion;
    QList<QString> compatibleBrands;
public:
    FileTypeBox(const int& s, const QString& t, const long int& off, const int& e, const QString& mb, const QString& mv, const QList<QString>& cb);
    virtual QString getFullName() { return QString("File Type Box"); }
    virtual QString getInfo();
};
/////////////////////////////////////////////////////////////////////////////////////////////////////
class MediaBox : public Box
{
public:
    MediaBox(const int& s, const QString& t, const long int& off, const int& e);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Media Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////
class MediaDataBox : public Box
{
public:
    MediaDataBox(const int& s, const QString& t, const long int& off, const int& e);
    virtual QString getFullName() { return QString("Media Data Box"); }
};
//////////////////////////////////////////////////////////////////////////////////////////////////////
class MediaHeaderBox : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    MediaHeaderBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString("Media Header Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class MovieBox : public Box
{
public:
    MovieBox(const int& s, const QString& t, const long int& off, const int& e);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Movie Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class MovieHeaderBox : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    MovieHeaderBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString("Movie Header Box "); }

};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class TrackBox : public Box
{
public:
    TrackBox(const int& s, const QString& t, const long int& off, const int& e);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Track Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class TrackHeaderBox : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    TrackHeaderBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString("Track Header Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class TrackReferenceBox : public Box
{
public:
    TrackReferenceBox(const int& s, const QString& t, const long int& off, const int& e);
    virtual QString getFullName() { return QString("Track Reference Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class HandlerBox : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    HandlerBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString("Handler Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class MediaInformationBox : public Box
{
public:
    MediaInformationBox(const int& s, const QString& t, const long int& off, const int& e);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Media Information Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class VideoMediaHeaderBox : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    VideoMediaHeaderBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString("Video Media Header Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SoundMediaHeaderBox : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    SoundMediaHeaderBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString("Sound Media Header Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class HintMediaHeaderBox : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    HintMediaHeaderBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString("Hint Media Header Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class NullMediaHeaderBox : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    NullMediaHeaderBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString("Null Media Header Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class DataInformationBox : public Box
{
public:
    DataInformationBox(const int& s, const QString& t, const long int& off, const int& e);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Data Information Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class DataEntryUrnBox : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    DataEntryUrnBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString("Data Entry URN Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class DataEntryUrlBox : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    DataEntryUrlBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString("Data Entry URL Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class DataReferenceBox : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    DataReferenceBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString("Data Reference Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
class FreeSpaceBox : public Box
{
private:
    bool container;
public:
    FreeSpaceBox(bool container,const int& s, const QString& t, const long int& off, const int& e);
    virtual bool isContainer() { return container; }
    virtual QString getFullName() { return QString("Free Space Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class EditBox : public Box
{
public:
    EditBox(const int& s, const QString& t, const long int& off, const int& e);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Edit Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class EditListBox : public Box
{
public:
    EditListBox(const int& s, const QString& t, const long int& off, const int& e);
    virtual QString getFullName() { return QString("Edit List Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class UserDataBox : public Box
{
public:
    UserDataBox(const int& s, const QString& t, const long int& off, const int& e);
    virtual QString getFullName() { return QString("User Data Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class CopyRightBox : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    CopyRightBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString("CopyRight Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class MovieExtendsBox : public Box
{
public:
    MovieExtendsBox(const int& s, const QString& t, const long int& off, const int& e);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Movie Extends Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class MovieExtendsHeaderBox : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    MovieExtendsHeaderBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString("Movie Extends Header Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class TrackExtendsBox : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    TrackExtendsBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString("Track Extends Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class MovieFragmentBox : public Box
{
public:
    MovieFragmentBox(const int& s, const QString& t, const long int& off, const int& e);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Movie Fragment Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class MovieFragmentHeaderBox : public FullBox
{
private:
    int sequenceNumber;
    int version;
    QList<int> flags;
public:
    MovieFragmentHeaderBox(const int& s, const QString& t, const long int& off, const int& e, const long& sn, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString("Movie Fragment Header Box"); }
    virtual QString getInfo();
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class TrackFragmentBox : public Box
{
public:
    TrackFragmentBox(const int& s, const QString& t, const long int& off, const int& e);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Track Fragment Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class TrackFragmentHeaderBox : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    TrackFragmentHeaderBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString("Track Fragment Header Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class TrackRunBox : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    TrackRunBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString("Track Run Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class MovieFragmentRandomAccessBox : public Box
{
public:
    MovieFragmentRandomAccessBox(const int& s, const QString& t, const long int& off, const int& e);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Movie Fragment Access Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class TrackFragmentRandomAccessBox : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    TrackFragmentRandomAccessBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString("Track Fragment Random Access Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class MovieFragmentRandomAccessOffsetBox : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    MovieFragmentRandomAccessOffsetBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString("Movie Fragment Random Access Offset Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SampleDependencyTypeBox : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    SampleDependencyTypeBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString("Sample Dependency Type Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SampleToGroupBox : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    SampleToGroupBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString("Sample To Group Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SampleGroupDescriptionBox : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    SampleGroupDescriptionBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString("Sample Group Description Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SampleScaleBox : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    SampleScaleBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString("sample Scale Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SubSampleInformationBox : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    SubSampleInformationBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString("Sub Sample Information Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class ProgressiveDownloadInfoBox : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    ProgressiveDownloadInfoBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString("Pogressive Donwload Info Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class MetaBox : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    MetaBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Meta Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class XMLBox : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    XMLBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString("XML Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class BinaryXMLBox : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    BinaryXMLBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString("Binary XML Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class ItemLocationBox : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    ItemLocationBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString("Item Location Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class PrimaryItemBox : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    PrimaryItemBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString("Primary Item Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class ItemProtectionBox : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    ItemProtectionBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Item Protection Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class ItemInfoEntry : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    ItemInfoEntry(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString("Item Intfo Entry"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class ItemInfoBox : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    ItemInfoBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString("Item Info Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class ProtectionSchemeInfoBox : public Box
{
public:
    ProtectionSchemeInfoBox(const int& s, const QString& t, const long int& off, const int& e);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Protection Scheme Info Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class OriginalFormatBox : public Box
{
public:
    OriginalFormatBox(const int& s, const QString& t, const long int& off, const int& e);
    virtual QString getFullName() { return QString("Original Format Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class IPMPInfoBox : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    IPMPInfoBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString("IPMP Info Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class IPMPControlBox : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    IPMPControlBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString("IPMP Control Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SchemeTypeBox : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    SchemeTypeBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString("Scheme Type Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SchemeInformationBox : public Box
{
public:
    SchemeInformationBox(const int& s, const QString& t, const long int& off, const int& e);
    virtual QString getFullName() { return QString("Scheme Information Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class TimeScaleEntry : public Box
{
public:
    TimeScaleEntry(const int& s, const QString& t, const long int& off, const int& e);
    virtual QString getFullName() { return QString("Time Scale Entry"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class TimeOffset : public Box
{
public:
    TimeOffset(const int& s, const QString& t, const long int& off, const int& e);
    virtual QString getFullName() { return QString("Time Offset"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SequenceOffset : public Box
{
public:
    SequenceOffset(const int& s, const QString& t, const long int& off, const int& e);
    virtual QString getFullName() { return QString("Sequence Offset"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SRTPProcessBox : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    SRTPProcessBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString("SRTP Process Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class MovieHintInformation : public Box
{
public:
    MovieHintInformation(const int& s, const QString& t, const long int& off, const int& e);
    virtual QString getFullName() { return QString("Movie Hint Information"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class RTPMovieHintInformation : public Box
{
public:
    RTPMovieHintInformation(const int& s, const QString& t, const long int& off, const int& e);
    virtual QString getFullName() { return QString("RTP Movie Hint Information"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class RTPTrackSDPHintInformation : public Box
{
public:
    RTPTrackSDPHintInformation(const int& s, const QString& t, const long int& off, const int& e);
    virtual QString getFullName() { return QString("RTP Track SDP Hint Information"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class HintStatisticsBox : public Box
{
public:
    HintStatisticsBox(const int& s, const QString& t, const long int& off, const int& e);
    virtual QString getFullName() { return QString("Hint Statistics Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
///mpeg dash
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SampleAuxiliaryInformationSizesBox : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    SampleAuxiliaryInformationSizesBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString("Sample Auxiliary Information Sizes Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SampleAuxiliaryInformationOffsetsBox : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    SampleAuxiliaryInformationOffsetsBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString("Sample Auxiliary Information Offsets Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class TrackFragmentBaseMediaDecodeTimeBox : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    TrackFragmentBaseMediaDecodeTimeBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString("Track Fragment Base Media Decode Time Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class LevelAssignmentBox : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    LevelAssignmentBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString("Level Assignment Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SegmentIndexBox : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    SegmentIndexBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString("Segment Index Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SubsegmentIndexBox : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    SubsegmentIndexBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString("Subsegment Index Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class ProducerReferenceTimeBox : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    ProducerReferenceTimeBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString("Producer Reference Time Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // BOX_H

