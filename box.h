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
    Box(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual bool isContainer() { return false; }
    virtual unsigned int getOffset() { return 8; }
    virtual QString getType() { return type; }
    virtual QString getFullName() { return QString(" "); }
    virtual QString getInfo() {return QString(" "); }
    //Box(Box& box);
};
/////////////////////////////////////////////////////////////////////////////////////////////////
class FullBox : public Box
{
public:
    FullBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString(" "); }

};
//////////////////////////////////////////////////////////////////////////////////////////////////
class FileTypeBox : public Box
{
public:
    FileTypeBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("File Type Box"); }

};
/////////////////////////////////////////////////////////////////////////////////////////////////////
class MediaBox : public Box
{
public:
    MediaBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Media Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////
class MediaDataBox : public Box
{
public:
    MediaDataBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("Media Data Box"); }
};
//////////////////////////////////////////////////////////////////////////////////////////////////////
class MediaHeaderBox : public FullBox
{
public:
    MediaHeaderBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("Media Header Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class MovieBox : public Box
{
public:
    MovieBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Movie Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class MovieHeaderBox : public FullBox
{
public:
    MovieHeaderBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("Movie Header Box "); }

};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class TrackBox : public Box
{
public:
    TrackBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Track Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class TrackHeaderBox : public FullBox
{
public:
    TrackHeaderBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("Track Header Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class TrackReferenceBox : public Box
{
public:
    TrackReferenceBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("Track Reference Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class HandlerBox : public FullBox
{
public:
    HandlerBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("Handler Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class MediaInformationBox : public Box
{
public:
    MediaInformationBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Media Information Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class VideoMediaHeaderBox : public FullBox
{
public:
    VideoMediaHeaderBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("Video Media Header Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SoundMediaHeaderBox : public FullBox
{
public:
    SoundMediaHeaderBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("Sound Media Header Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class HintMediaHeaderBox : public FullBox
{
public:
    HintMediaHeaderBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("Hint Media Header Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class NullMediaHeaderBox : public FullBox
{
public:
    NullMediaHeaderBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("Null Media Header Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class DataInformationBox : public Box
{
public:
    DataInformationBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Data Information Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class DataEntryUrnBox : public FullBox
{
public:
    DataEntryUrnBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("Data Entry URN Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class DataEntryUrlBox : public FullBox
{
public:
    DataEntryUrlBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("Data Entry URL Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class DataReferenceBox : public FullBox
{
public:
    DataReferenceBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("Data Reference Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
class FreeSpaceBox : public Box
{
private:
    bool container;
public:
    FreeSpaceBox(bool container=false,const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual bool isContainer() { return container; }
    virtual QString getFullName() { return QString("Free Space Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class EditBox : public Box
{
public:
    EditBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Edit Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class EditListBox : public Box
{
public:
    EditListBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("Edit List Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class UserDataBox : public Box
{
public:
    UserDataBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("User Data Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class CopyRightBox : public FullBox
{
public:
    CopyRightBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("CopyRight Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class MovieExtendsBox : public Box
{
public:
    MovieExtendsBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Movie Extends Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class MovieExtendsHeaderBox : public FullBox
{
public:
    MovieExtendsHeaderBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("Movie Extends Header Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class TrackExtendsBox : public FullBox
{
public:
    TrackExtendsBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("Track Extends Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class MovieFragmentBox : public Box
{
public:
    MovieFragmentBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Movie Fragment Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class MovieFragmentHeaderBox : public FullBox
{
public:
    MovieFragmentHeaderBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("Movie Fragment Header Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class TrackFragmentBox : public Box
{
public:
    TrackFragmentBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Track Fragment Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class TrackFragmentHeaderBox : public FullBox
{
public:
    TrackFragmentHeaderBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("Track Fragment Header Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class TrackRunBox : public FullBox
{
public:
    TrackRunBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("Track Run Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class MovieFragmentRandomAccessBox : public Box
{
public:
    MovieFragmentRandomAccessBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Movie Fragment Access Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class TrackFragmentRandomAccessBox : public FullBox
{
public:
    TrackFragmentRandomAccessBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("Track Fragment Random Access Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class MovieFragmentRandomAccessOffsetBox : public FullBox
{
public:
    MovieFragmentRandomAccessOffsetBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("Movie Fragment Random Access Offset Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SampleDependencyTypeBox : public FullBox
{
public:
    SampleDependencyTypeBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("Sample Dependency Type Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SampleToGroupBox : public FullBox
{
public:
    SampleToGroupBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("Sample To Group Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SampleGroupDescriptionBox : public FullBox
{
public:
    SampleGroupDescriptionBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("Sample Group Description Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SampleScaleBox : public FullBox
{
public:
    SampleScaleBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("sample Scale Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SubSampleInformationBox : public FullBox
{
public:
    SubSampleInformationBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("Sub Sample Information Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class ProgressiveDownloadInfoBox : public FullBox
{
public:
    ProgressiveDownloadInfoBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("Pogressive Donwload Info Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class MetaBox : public FullBox
{
public:
    MetaBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Meta Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class XMLBox : public FullBox
{
public:
    XMLBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("XML Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class BinaryXMLBox : public FullBox
{
public:
    BinaryXMLBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("Binary XML Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class ItemLocationBox : public FullBox
{
public:
    ItemLocationBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("Item Location Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class PrimaryItemBox : public FullBox
{
public:
    PrimaryItemBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("Primary Item Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class ItemProtectionBox : public FullBox
{
public:
    ItemProtectionBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Item Protection Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class ItemInfoEntry : public FullBox
{
public:
    ItemInfoEntry(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("Item Intfo Entry"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class ItemInfoBox : public FullBox
{
public:
    ItemInfoBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("Item Info Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class ProtectionSchemeInfoBox : public Box
{
public:
    ProtectionSchemeInfoBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Protection Scheme Info Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class OriginalFormatBox : public Box
{
public:
    OriginalFormatBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("Original Format Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class IPMPInfoBox : public FullBox
{
public:
    IPMPInfoBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("IPMP Info Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class IPMPControlBox : public FullBox
{
public:
    IPMPControlBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("IPMP Control Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SchemeTypeBox : public FullBox
{
public:
    SchemeTypeBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("Scheme Type Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SchemeInformationBox : public Box
{
public:
    SchemeInformationBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("Scheme Information Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class TimeScaleEntry : public Box
{
public:
    TimeScaleEntry(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("Time Scale Entry"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class TimeOffset : public Box
{
public:
    TimeOffset(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("Time Offset"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SequenceOffset : public Box
{
public:
    SequenceOffset(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("Sequence Offset"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class SRTPProcessBox : public FullBox
{
public:
    SRTPProcessBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("SRTP Process Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class MovieHintInformation : public Box
{
public:
    MovieHintInformation(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("Movie Hint Information"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class RTPMovieHintInformation : public Box
{
public:
    RTPMovieHintInformation(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("RTP Movie Hint Information"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class RTPTrackSDPHintInformation : public Box
{
public:
    RTPTrackSDPHintInformation(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("RTP Track SDP Hint Information"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class HintStatisticsBox : public Box
{
public:
    HintStatisticsBox(const int& s=0, const QString& t="", const long int& off=0, const int& e=0);
    virtual QString getFullName() { return QString("Hint Statistics Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // BOX_H

