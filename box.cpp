#include "box.h"


Box::Box(const int &s, const QString &t, const long &off, const int & e): size(s),type(t),offset(off), extended_type(e) {}
/////////////
FullBox::FullBox(const int& s, const QString& t, const long int& off, const int &  e):Box(s,t,off,e) {}
/////////////
FileTypeBox::FileTypeBox(const int& s, const QString& t, const long int& off, const int & e, const QString& mb, const QString& mv, const QList<QString>& cb):
    Box(s,t,off,e),
    majorBrand(mb),
    minorVersion(mv),
    compatibleBrands(cb) {}

QString FileTypeBox::getInfo() {
    QString tmp("");
    tmp.append("\n\tMajor brand\t\t");
    tmp.append(majorBrand);
    tmp.append("\n\tMinor version\t\t");
    tmp.append(minorVersion);
    tmp.append("\n\tcompatibleBrands\t");
    QList<QString>::iterator i;
    for (i = compatibleBrands.begin(); i !=compatibleBrands.end(); ++i) {
        tmp.append(*i);
        tmp.append(" , ");
    }
    return tmp;
}
/////////////
MediaBox::MediaBox(const int& s, const QString& t, const long int& off, const int &  e): Box(s,t,off,e) {}
/////////////
MediaDataBox::MediaDataBox(const int& s, const QString& t, const long int& off, const int &  e):Box(s,t,off,e) {}
/////////////
MediaHeaderBox::MediaHeaderBox(const int& s, const QString& t, const long int& off, const int &  e): FullBox(s,t,off,e) {}
/////////////
MovieBox::MovieBox(const int& s, const QString& t, const long int& off, const int &  e):Box(s,t,off,e) {}
/////////////
MovieHeaderBox::MovieHeaderBox(const int& s, const QString& t, const long int& off, const int &  e):FullBox(s,t,off,e) {}
/////////////
TrackBox::TrackBox(const int& s, const QString& t, const long int& off, const int &  e): Box(s,t,off,e) {}
/////////////
TrackHeaderBox::TrackHeaderBox(const int& s, const QString& t, const long int& off, const int &  e): FullBox(s,t,off,e) {}
/////////////
TrackReferenceBox::TrackReferenceBox(const int& s, const QString& t, const long int& off, const int &  e): Box(s,t,off,e) {}
/////////////
HandlerBox::HandlerBox(const int& s, const QString& t, const long int& off, const int &  e): FullBox(s,t,off,e) {}
/////////////
MediaInformationBox::MediaInformationBox(const int& s, const QString& t, const long int& off, const int &  e): Box(s,t,off,e) {}
/////////////
VideoMediaHeaderBox::VideoMediaHeaderBox(const int& s, const QString& t, const long int& off, const int &  e): FullBox(s,t,off,e) {}
/////////////
SoundMediaHeaderBox::SoundMediaHeaderBox(const int& s, const QString& t, const long int& off, const int &  e): FullBox(s,t,off,e) {}
/////////////
HintMediaHeaderBox::HintMediaHeaderBox(const int& s, const QString& t, const long int& off, const int &  e): FullBox(s,t,off,e) {}
/////////////
NullMediaHeaderBox::NullMediaHeaderBox(const int& s, const QString& t, const long int& off, const int &  e): FullBox(s,t,off,e) {}
/////////////
DataInformationBox::DataInformationBox(const int& s, const QString& t, const long int& off, const int &  e): Box(s,t,off,e) {}
/////////////
DataEntryUrnBox::DataEntryUrnBox(const int& s, const QString& t, const long int& off, const int &  e): FullBox(s,t,off,e) {}
/////////////
DataEntryUrlBox::DataEntryUrlBox(const int& s, const QString& t, const long int& off, const int &  e): FullBox(s,t,off,e) {}
/////////////
DataReferenceBox::DataReferenceBox(const int& s, const QString& t, const long int& off, const int &  e): FullBox(s,t,off,e) {}
///////////////
FreeSpaceBox::FreeSpaceBox(bool c,const int& s, const QString& t, const long int& off, const int & e): Box(s,t,off,e), container(c) {}
///////////////
EditBox::EditBox(const int& s, const QString& t, const long int& off, const int &  e): Box(s,t,off,e) {}
///////////////
EditListBox::EditListBox(const int& s, const QString& t, const long int& off, const int &  e): Box(s,t,off,e) {}
///////////////
UserDataBox::UserDataBox(const int& s, const QString& t, const long int& off, const int &  e): Box(s,t,off,e) {}
///////////////
CopyRightBox::CopyRightBox(const int& s, const QString& t, const long int& off, const int &  e): FullBox(s,t,off,e) {}
///////////////
MovieExtendsBox::MovieExtendsBox(const int& s, const QString& t, const long int& off, const int &  e): Box(s,t,off,e) {}
///////////////
MovieExtendsHeaderBox::MovieExtendsHeaderBox(const int& s, const QString& t, const long int& off, const int &  e): FullBox(s,t,off,e) {}
///////////////
TrackExtendsBox::TrackExtendsBox(const int& s, const QString& t, const long int& off, const int &  e): FullBox(s,t,off,e) {}
///////////////
MovieFragmentBox::MovieFragmentBox(const int& s, const QString& t, const long int& off, const int &  e): Box(s,t,off,e) {}
///////////////
MovieFragmentHeaderBox::MovieFragmentHeaderBox(const int& s, const QString& t, const long int& off, const int &  e): FullBox(s,t,off,e) {}
///////////////
TrackFragmentBox::TrackFragmentBox(const int& s, const QString& t, const long int& off, const int &  e): Box(s,t,off,e) {}
///////////////
TrackFragmentHeaderBox::TrackFragmentHeaderBox(const int& s, const QString& t, const long int& off, const int &  e): FullBox(s,t,off,e) {}
///////////////
TrackRunBox::TrackRunBox(const int& s, const QString& t, const long int& off, const int &  e): FullBox(s,t,off,e) {}
///////////////
MovieFragmentRandomAccessBox::MovieFragmentRandomAccessBox(const int& s, const QString& t, const long int& off, const int &  e): Box(s,t,off,e) {}
///////////////
TrackFragmentRandomAccessBox::TrackFragmentRandomAccessBox(const int& s, const QString& t, const long int& off, const int &  e): FullBox(s,t,off,e) {}
///////////////
MovieFragmentRandomAccessOffsetBox::MovieFragmentRandomAccessOffsetBox(const int& s, const QString& t, const long int& off, const int &  e): FullBox(s,t,off,e) {}
///////////////
SampleDependencyTypeBox::SampleDependencyTypeBox(const int& s, const QString& t, const long int& off, const int &  e): FullBox(s,t,off,e) {}
///////////////
SampleToGroupBox::SampleToGroupBox(const int& s, const QString& t, const long int& off, const int &  e): FullBox(s,t,off,e) {}
///////////////
SampleGroupDescriptionBox::SampleGroupDescriptionBox(const int& s, const QString& t, const long int& off, const int &  e): FullBox(s,t,off,e) {}
///////////////
SampleScaleBox::SampleScaleBox(const int& s, const QString& t, const long int& off, const int &  e): FullBox(s,t,off,e) {}
///////////////
SubSampleInformationBox::SubSampleInformationBox(const int& s, const QString& t, const long int& off, const int &  e): FullBox(s,t,off,e) {}
///////////////
ProgressiveDownloadInfoBox::ProgressiveDownloadInfoBox(const int& s, const QString& t, const long int& off, const int &  e): FullBox(s,t,off,e) {}
///////////////
MetaBox::MetaBox(const int& s, const QString& t, const long int& off, const int &  e): FullBox(s,t,off,e) {}
///////////////
XMLBox::XMLBox(const int& s, const QString& t, const long int& off, const int &  e): FullBox(s,t,off,e) {}
///////////////
BinaryXMLBox::BinaryXMLBox(const int& s, const QString& t, const long int& off, const int &  e): FullBox(s,t,off,e) {}
///////////////
ItemLocationBox::ItemLocationBox(const int& s, const QString& t, const long int& off, const int &  e): FullBox(s,t,off,e) {}
///////////////
PrimaryItemBox::PrimaryItemBox(const int& s, const QString& t, const long int& off, const int &  e): FullBox(s,t,off,e) {}
///////////////
ItemProtectionBox::ItemProtectionBox(const int& s, const QString& t, const long int& off, const int &  e): FullBox(s,t,off,e) {}
///////////////
ItemInfoEntry::ItemInfoEntry(const int& s, const QString& t, const long int& off, const int &  e): FullBox(s,t,off,e) {}
///////////////
ItemInfoBox::ItemInfoBox(const int& s, const QString& t, const long int& off, const int &  e): FullBox(s,t,off,e) {}
///////////////
ProtectionSchemeInfoBox::ProtectionSchemeInfoBox(const int& s, const QString& t, const long int& off, const int &  e): Box(s,t,off,e) {}
///////////////
OriginalFormatBox::OriginalFormatBox(const int& s, const QString& t, const long int& off, const int &  e): Box(s,t,off,e) {}
///////////////
IPMPInfoBox::IPMPInfoBox(const int& s, const QString& t, const long int& off, const int &  e): FullBox(s,t,off,e) {}
///////////////
IPMPControlBox::IPMPControlBox(const int& s, const QString& t, const long int& off, const int &  e): FullBox(s,t,off,e) {}
///////////////
SchemeTypeBox::SchemeTypeBox(const int& s, const QString& t, const long int& off, const int &  e): FullBox(s,t,off,e) {}
///////////////
SchemeInformationBox::SchemeInformationBox(const int& s, const QString& t, const long int& off, const int &  e): Box(s,t,off,e) {}
///////////////
TimeScaleEntry::TimeScaleEntry(const int& s, const QString& t, const long int& off, const int &  e): Box(s,t,off,e) {}
///////////////
TimeOffset::TimeOffset(const int& s, const QString& t, const long int& off, const int &  e): Box(s,t,off,e) {}
///////////////
SequenceOffset::SequenceOffset(const int& s, const QString& t, const long int& off, const int &  e): Box(s,t,off,e) {}
///////////////
SRTPProcessBox::SRTPProcessBox(const int& s, const QString& t, const long int& off, const int &  e): FullBox(s,t,off,e) {}
///////////////
MovieHintInformation::MovieHintInformation(const int& s, const QString& t, const long int& off, const int &  e): Box(s,t,off,e) {}
///////////////
RTPMovieHintInformation::RTPMovieHintInformation(const int& s, const QString& t, const long int& off, const int &  e): Box(s,t,off,e) {}
///////////////
RTPTrackSDPHintInformation::RTPTrackSDPHintInformation(const int& s, const QString& t, const long int& off, const int &  e): Box(s,t,off,e) {}
///////////////
HintStatisticsBox::HintStatisticsBox(const int& s, const QString& t, const long int& off, const int &  e): Box(s,t,off,e) {}
///////////////
///mpeg dash
//////////////
SampleAuxiliaryInformationSizesBox::SampleAuxiliaryInformationSizesBox(const int& s, const QString& t, const long int& off, const int &  e): FullBox(s,t,off,e) {}
///////////////
SampleAuxiliaryInformationOffsetsBox::SampleAuxiliaryInformationOffsetsBox(const int& s, const QString& t, const long int& off, const int &  e): FullBox(s,t,off,e) {}
///////////////
TrackFragmentBaseMediaDecodeTimeBox::TrackFragmentBaseMediaDecodeTimeBox(const int& s, const QString& t, const long int& off, const int &  e): FullBox(s,t,off,e) {}
///////////////
LevelAssignmentBox::LevelAssignmentBox(const int& s, const QString& t, const long int& off, const int &  e): FullBox(s,t,off,e) {}
///////////////
SegmentIndexBox::SegmentIndexBox(const int& s, const QString& t, const long int& off, const int &  e): FullBox(s,t,off,e) {}
///////////////
SubsegmentIndexBox::SubsegmentIndexBox(const int& s, const QString& t, const long int& off, const int &  e): FullBox(s,t,off,e) {}
///////////////
ProducerReferenceTimeBox::ProducerReferenceTimeBox(const int& s, const QString& t, const long int& off, const int &  e): FullBox(s,t,off,e) {}
///////////////
