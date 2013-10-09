/*!
 * \file Box
 * \details
 * Box
 * FullBox
 * FileTypeBox
 * MovieBox
 * MovieExtendsBox
 * MovieExtendsHeaderBox
 * MovieFragmentBox
 * MovieFragmentHeaderBox
 * MovieFragmentRandomAccessBox
 * MovieFragmentRandomAccessOffsetBox
 * MovieHeaderBox
 * MovieHintInformation
 * MediaBox
 * MediaDataBox
 * MediaHeaderBox
 * MediaInformationBox
 * HandlerBox
 */

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
    unsigned  int size;
    /*!
     * \brief type type of the box
     */
    QString type;
    /*!
     * \brief offset bit offset of the box location
     */
    unsigned long int offset;
    /*!
     * \brief extended_type indicates whether the box has extended type (1) or not (0)
     */
    unsigned  int extended_type;
    /*!
     * \brief otherBoxOffset bit byte distance between begin of box and the begin of boxes from the box
     * (for boxes who are containers)
     */
    unsigned long int otherBoxOffset;
public:
    /*!
     * \brief Box
     * constructor
     * \param s size
     * \param t type
     * \param off offset
     * \param e extended_type
     */
    Box(const unsigned  int &s, const QString& t, const unsigned long &off, const unsigned  int &e);
    /*!
     * \brief isContainer
     * \return true when box contains other boxes, false otherwise
     */
    virtual bool isContainer() { return false; }
    /*!
     * \brief getOffset
     * \return offset of child boxes
     */
    virtual unsigned  int getOffset() { return 8; }
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
    unsigned  int version;
    QList<unsigned int> flags;
public:
    FullBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int& e, const unsigned  int& v, const QList<unsigned int>& f);
    virtual QString getFullName() { return QString(" "); }
    virtual QString getInfo();
};
//////////////////////////////////////////////////////////////////////////////////////////////////
class FileTypeBox : public Box
{
private:
    QString majorBrand;
    QString minorVersion;
    QList<QString> compatibleBrands;
public:
    FileTypeBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int &  e, const QString& mb, const QString& mv, const QList<QString>& cb);
    virtual QString getFullName() { return QString("File Type Box"); }
    virtual QString getInfo();
};
/////////////////////////////////////////////////////////////////////////////////////////////////////
class MediaBox : public Box
{
public:
    MediaBox(const unsigned  int &s, const QString& t, const unsigned long &off, const unsigned  int &e);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Media Box"); }
    virtual QString getInfo() {
        return QString("Media Box is a container for all objects that declare information about the media data within a track.");
    }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////
class MediaDataBox : public Box
{
public:
    MediaDataBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int &  e);
    virtual QString getFullName() { return QString("Media Data Box"); }
    virtual QString getInfo() {
        return QString("Media Box contains the media data.");
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////////////
class MediaHeaderBox : public FullBox
{
private:
    unsigned  int version;
    QList<unsigned int> flags;
    unsigned long int creationTime;
    unsigned long int modificationTime;
    unsigned int timescale;
    unsigned long int duration;
    bool pad;
    QList<unsigned int> language;
    unsigned int predefined;
public:
    MediaHeaderBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int& e, const unsigned  int& v,
                   const QList<unsigned int>& f, const unsigned long int& ct, const unsigned long int& mt, const unsigned int & ts,
                   const unsigned long int & dur, const bool & pad, const QList<unsigned int> & lan, const unsigned int & pd);
    virtual QString getFullName() { return QString("Media Header Box"); }
    virtual QString getInfo();
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class MovieBox : public Box
{
public:
    MovieBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int &  e);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Movie Box"); }
    virtual QString getInfo() {
        return QString("Movie Box is container box for all meta-data.");
    }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class MovieHeaderBox : public FullBox
{
private:
    unsigned  int version;
    QList<unsigned int> flags;
    unsigned int creationTime; //in seconds since midnight, Jan. 1, 1904, in UTC time
    unsigned int modificationTime;
    unsigned int timeScale; //ilosc jednostek w sekundzie
    unsigned int duration; //liczba jednostek czasu wynikajacych ze skali czasu
    unsigned int rate;
    unsigned int volume;
    unsigned int reserved16;
    unsigned int reserved32;
    QList<unsigned int> matrix;
    QList<unsigned int> predefined;
    unsigned int nextTrackId;
public:
    MovieHeaderBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int& e, const unsigned  int& v, const QList<unsigned int>& f,
                   unsigned int creationTime, unsigned int modificationTime, unsigned int timeScale, unsigned int duration, unsigned int rate=1, unsigned int volume=1, unsigned int reserved16=0,
                   unsigned int reserved32=0, QList<unsigned int> mx=QList<unsigned int>(), QList<unsigned int> pr=QList<unsigned int>(), unsigned int nextTrackId=0);
    virtual QString getFullName() { return QString("Movie Header Box "); }
    virtual QString getInfo();

};
/////////////////////////////////////////////////////////////////////////////////////////////////////////

class HandlerBox : public FullBox
{
private:
    unsigned  int version;
    QList<unsigned int> flags;
public:
    HandlerBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int& e, const unsigned  int& v, const QList<unsigned int>& f);
    virtual QString getFullName() { return QString("Handler Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class MediaInformationBox : public Box
{
public:
    MediaInformationBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int &  e);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Media Information Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class VideoMediaHeaderBox : public FullBox
{
private:
    unsigned  int version;
    QList<unsigned int> flags;
public:
    VideoMediaHeaderBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int& e, const unsigned  int& v, const QList<unsigned int>& f);
    virtual QString getFullName() { return QString("Video Media Header Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SoundMediaHeaderBox : public FullBox
{
private:
    unsigned  int version;
    QList<unsigned int> flags;
public:
    SoundMediaHeaderBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int& e, const unsigned  int& v, const QList<unsigned int>& f);
    virtual QString getFullName() { return QString("Sound Media Header Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class HintMediaHeaderBox : public FullBox
{
private:
    unsigned  int version;
    QList<unsigned int> flags;
public:
    HintMediaHeaderBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int& e, const unsigned  int& v, const QList<unsigned int>& f);
    virtual QString getFullName() { return QString("Hint Media Header Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class NullMediaHeaderBox : public FullBox
{
private:
    unsigned  int version;
    QList<unsigned int> flags;
public:
    NullMediaHeaderBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int& e, const unsigned  int& v, const QList<unsigned int>& f);
    virtual QString getFullName() { return QString("Null Media Header Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class DataInformationBox : public Box
{
public:
    DataInformationBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int &  e);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Data Information Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class DataEntryUrnBox : public FullBox
{
private:
    unsigned  int version;
    QList<unsigned int> flags;
public:
    DataEntryUrnBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int& e, const unsigned  int& v, const QList<unsigned int>& f);
    virtual QString getFullName() { return QString("Data Entry URN Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class DataEntryUrlBox : public FullBox
{
private:
    unsigned  int version;
    QList<unsigned int> flags;
public:
    DataEntryUrlBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int& e, const unsigned  int& v, const QList<unsigned int>& f);
    virtual QString getFullName() { return QString("Data Entry URL Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class DataReferenceBox : public FullBox
{
private:
    unsigned  int version;
    QList<unsigned int> flags;
public:
    DataReferenceBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int& e, const unsigned  int& v, const QList<unsigned int>& f);
    virtual QString getFullName() { return QString("Data Reference Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
class FreeSpaceBox : public Box
{
private:
    bool container;
public:
    FreeSpaceBox(bool container,const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int &  e);
    virtual bool isContainer() { return container; }
    virtual QString getFullName() { return QString("Free Space Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class EditBox : public Box
{
public:
    EditBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int &  e);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Edit Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class EditListBox : public Box
{
public:
    EditListBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int &  e);
    virtual QString getFullName() { return QString("Edit List Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class UserDataBox : public Box
{
public:
    UserDataBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int &  e);
    virtual QString getFullName() { return QString("User Data Box"); }
    virtual QString getInfo() { return QString("User Data Box is container for objects that declare user information about the containing box and its data (presentation or track)."); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class CopyRightBox : public FullBox
{
private:
    unsigned  int version;
    QList<unsigned int> flags;
public:
    CopyRightBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int& e, const unsigned  int& v, const QList<unsigned int>& f);
    virtual QString getFullName() { return QString("CopyRight Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class MovieExtendsBox : public Box
{
public:
    MovieExtendsBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int &  e);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Movie Extends Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class MovieExtendsHeaderBox : public FullBox
{
private:
    unsigned  int version;
    QList<unsigned int> flags;
public:
    MovieExtendsHeaderBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int& e, const unsigned  int& v, const QList<unsigned int>& f);
    virtual QString getFullName() { return QString("Movie Extends Header Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class MovieFragmentBox : public Box
{
public:
    MovieFragmentBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int &  e);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Movie Fragment Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class MovieFragmentHeaderBox : public FullBox
{
private:
    unsigned int sequenceNumber;
    unsigned  int version;
    QList<unsigned int> flags;
public:
    MovieFragmentHeaderBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int &  e, const long& sn, const unsigned int& v, const QList<unsigned int>& f);
    virtual QString getFullName() { return QString("Movie Fragment Header Box"); }
    virtual QString getInfo();
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////
class MovieFragmentRandomAccessBox : public Box
{
public:
    MovieFragmentRandomAccessBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int &  e);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Movie Fragment Access Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class MovieFragmentRandomAccessOffsetBox : public FullBox
{
private:
    unsigned  int version;
    QList<unsigned int> flags;
public:
    MovieFragmentRandomAccessOffsetBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int& e, const unsigned  int& v, const QList<unsigned int>& f);
    virtual QString getFullName() { return QString("Movie Fragment Random Access Offset Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SampleDependencyTypeBox : public FullBox
{
private:
    unsigned  int version;
    QList<unsigned int> flags;
public:
    SampleDependencyTypeBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int& e, const unsigned  int& v, const QList<unsigned int>& f);
    virtual QString getFullName() { return QString("Sample Dependency Type Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SampleToGroupBox : public FullBox
{
private:
    unsigned  int version;
    QList<unsigned int> flags;
public:
    SampleToGroupBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int& e, const unsigned  int& v, const QList<unsigned int>& f);
    virtual QString getFullName() { return QString("Sample To Group Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SampleGroupDescriptionBox : public FullBox
{
private:
    unsigned  int version;
    QList<unsigned int> flags;
public:
    SampleGroupDescriptionBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int& e, const unsigned  int& v, const QList<unsigned int>& f);
    virtual QString getFullName() { return QString("Sample Group Description Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SampleScaleBox : public FullBox
{
private:
    unsigned  int version;
    QList<unsigned int> flags;
public:
    SampleScaleBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int& e, const unsigned  int& v, const QList<unsigned int>& f);
    virtual QString getFullName() { return QString("sample Scale Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SubSampleInformationBox : public FullBox
{
private:
    unsigned  int version;
    QList<unsigned int> flags;
public:
    SubSampleInformationBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int& e, const unsigned  int& v, const QList<unsigned int>& f);
    virtual QString getFullName() { return QString("Sub Sample Information Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class ProgressiveDownloadInfoBox : public FullBox
{
private:
    unsigned  int version;
    QList<unsigned int> flags;
public:
    ProgressiveDownloadInfoBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int& e, const unsigned  int& v, const QList<unsigned int>& f);
    virtual QString getFullName() { return QString("Pogressive Donwload Info Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class MetaBox : public FullBox
{
private:
    unsigned  int version;
    QList<unsigned int> flags;
public:
    MetaBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int& e, const unsigned  int& v, const QList<unsigned int>& f);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Meta Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class XMLBox : public FullBox
{
private:
    unsigned  int version;
    QList<unsigned int> flags;
public:
    XMLBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int& e, const unsigned  int& v, const QList<unsigned int>& f);
    virtual QString getFullName() { return QString("XML Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class BinaryXMLBox : public FullBox
{
private:
    unsigned  int version;
    QList<unsigned int> flags;
public:
    BinaryXMLBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int& e, const unsigned  int& v, const QList<unsigned int>& f);
    virtual QString getFullName() { return QString("Binary XML Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class ItemLocationBox : public FullBox
{
private:
    unsigned  int version;
    QList<unsigned int> flags;
public:
    ItemLocationBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int& e, const unsigned  int& v, const QList<unsigned int>& f);
    virtual QString getFullName() { return QString("Item Location Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class PrimaryItemBox : public FullBox
{
private:
    unsigned  int version;
    QList<unsigned int> flags;
public:
    PrimaryItemBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int& e, const unsigned  int& v, const QList<unsigned int>& f);
    virtual QString getFullName() { return QString("Primary Item Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class ItemProtectionBox : public FullBox
{
private:
    unsigned  int version;
    QList<unsigned int> flags;
public:
    ItemProtectionBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int& e, const unsigned  int& v, const QList<unsigned int>& f);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Item Protection Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class ItemInfoEntry : public FullBox
{
private:
    unsigned  int version;
    QList<unsigned int> flags;
public:
    ItemInfoEntry(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int& e, const unsigned  int& v, const QList<unsigned int>& f);
    virtual QString getFullName() { return QString("Item unsigned intfo Entry"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class ItemInfoBox : public FullBox
{
private:
    unsigned  int version;
    QList<unsigned int> flags;
public:
    ItemInfoBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int& e, const unsigned  int& v, const QList<unsigned int>& f);
    virtual QString getFullName() { return QString("Item Info Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class ProtectionSchemeInfoBox : public Box
{
public:
    ProtectionSchemeInfoBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int &  e);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Protection Scheme Info Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class OriginalFormatBox : public Box
{
public:
    OriginalFormatBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int &  e);
    virtual QString getFullName() { return QString("Original Format Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class IPMPInfoBox : public FullBox
{
private:
    unsigned  int version;
    QList<unsigned int> flags;
public:
    IPMPInfoBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int& e, const unsigned  int& v, const QList<unsigned int>& f);
    virtual QString getFullName() { return QString("IPMP Info Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class IPMPControlBox : public FullBox
{
private:
    unsigned  int version;
    QList<unsigned int> flags;
public:
    IPMPControlBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int& e, const unsigned  int& v, const QList<unsigned int>& f);
    virtual QString getFullName() { return QString("IPMP Control Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SchemeTypeBox : public FullBox
{
private:
    unsigned  int version;
    QList<unsigned int> flags;
public:
    SchemeTypeBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int& e, const unsigned  int& v, const QList<unsigned int>& f);
    virtual QString getFullName() { return QString("Scheme Type Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SchemeInformationBox : public Box
{
public:
    SchemeInformationBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int &  e);
    virtual QString getFullName() { return QString("Scheme Information Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class TimeScaleEntry : public Box
{
public:
    TimeScaleEntry(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int &  e);
    virtual QString getFullName() { return QString("Time Scale Entry"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class TimeOffset : public Box
{
public:
    TimeOffset(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int &  e);
    virtual QString getFullName() { return QString("Time Offset"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SequenceOffset : public Box
{
public:
    SequenceOffset(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int &  e);
    virtual QString getFullName() { return QString("Sequence Offset"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SRTPProcessBox : public FullBox
{
private:
    unsigned  int version;
    QList<unsigned int> flags;
public:
    SRTPProcessBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int& e, const unsigned  int& v, const QList<unsigned int>& f);
    virtual QString getFullName() { return QString("SRTP Process Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class MovieHintInformation : public Box
{
public:
    MovieHintInformation(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int &  e);
    virtual QString getFullName() { return QString("Movie Hint Information"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class RTPMovieHintInformation : public Box
{
public:
    RTPMovieHintInformation(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int &  e);
    virtual QString getFullName() { return QString("RTP Movie Hint Information"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class RTPTrackSDPHintInformation : public Box
{
public:
    RTPTrackSDPHintInformation(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int &  e);
    virtual QString getFullName() { return QString("RTP Track SDP Hint Information"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class HintStatisticsBox : public Box
{
public:
    HintStatisticsBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int &  e);
    virtual QString getFullName() { return QString("Hint Statistics Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
///mpeg dash
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SampleAuxiliaryInformationSizesBox : public FullBox
{
private:
    unsigned  int version;
    QList<unsigned int> flags;
public:
    SampleAuxiliaryInformationSizesBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int& e, const unsigned  int& v, const QList<unsigned int>& f);
    virtual QString getFullName() { return QString("Sample Auxiliary Information Sizes Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SampleAuxiliaryInformationOffsetsBox : public FullBox
{
private:
    unsigned  int version;
    QList<unsigned int> flags;
public:
    SampleAuxiliaryInformationOffsetsBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int& e, const unsigned  int& v, const QList<unsigned int>& f);
    virtual QString getFullName() { return QString("Sample Auxiliary Information Offsets Box"); }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////
class LevelAssignmentBox : public FullBox
{
private:
    unsigned  int version;
    QList<unsigned int> flags;
public:
    LevelAssignmentBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int& e, const unsigned  int& v, const QList<unsigned int>& f);
    virtual QString getFullName() { return QString("Level Assignment Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SegmentIndexBox : public FullBox
{
private:
    unsigned  int version;
    QList<unsigned int> flags;
    unsigned  int referenceId;
    unsigned  int timescale;
    unsigned  int earliestPresentationTime;
    unsigned  int firstOffset;
    unsigned  int reserved;
    QList<bool> referenceType;
    QList<unsigned  int> referenceSize;
    QList<unsigned  int> subsegmentDuration;
    QList<bool> startsWithSAP;
    QList <unsigned  int> SAPType;
    QList <unsigned  int> SAPDeltaTime;

public:
    SegmentIndexBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int& e, const unsigned  int& v, const QList<unsigned int>& f, const unsigned int& referenceId,
                    const unsigned int& timescale,const unsigned int& myEarliestPresentationTime, const unsigned int& myFirstOffset, const unsigned int& myReserved,
                    const QList<bool>& referenceType, const QList<unsigned  int> referenceSize, const QList<unsigned  int> & subsegmentDuration,
                    const QList<bool> & startsWithSAP, const QList<unsigned  int>& SAPType, const QList<unsigned  int>& SAPDeltaTime);
    virtual QString getFullName() { return QString("Segment Index Box"); }
    virtual QString getInfo();
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SubsegmentIndexBox : public FullBox
{
private:
    unsigned  int version;
    QList<unsigned int> flags;
public:
    SubsegmentIndexBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int& e, const unsigned  int& v, const QList<unsigned int>& f);
    virtual QString getFullName() { return QString("Subsegment Index Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class ProducerReferenceTimeBox : public FullBox
{
private:
    unsigned  int version;
    QList<unsigned int> flags;
public:
    ProducerReferenceTimeBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int& e, const unsigned  int& v, const QList<unsigned int>& f);
    virtual QString getFullName() { return QString("Producer Reference Time Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // BOX_H

