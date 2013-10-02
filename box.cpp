#include "box.h"


Box::Box(const int &s, const QString &t, const long &off, const int & e): size(s),type(t),offset(off), extended_type(e) {}
/////////////
FullBox::FullBox(const int& s, const QString& t, const long int& off, const int &  e, const int& v, const QList<int>& f):
    Box(s,t,off,e),
    version(v),
    flags(f)
{}
/////////////
FileTypeBox::FileTypeBox(const int& s, const QString& t, const long int& off, const int & e, const QString& mb, const QString& mv, const QList<QString>& cb):
    Box(s,t,off,e),
    majorBrand(mb),
    minorVersion(mv),
    compatibleBrands(cb) {}

QString FileTypeBox::getInfo() {
    QString tmp("");
    tmp.append("Major brand\t\t");
    tmp.append(majorBrand);
    tmp.append("\nMinor version\t\t");
    tmp.append(minorVersion);
    tmp.append("\ncompatibleBrands\t");
    QList<QString>::iterator i;
    for (i = compatibleBrands.begin(); i !=compatibleBrands.end(); ++i) {
        tmp.append(*i);
        tmp.append(" | ");
    }
    return tmp;
}
/////////////
MediaBox::MediaBox(const int& s, const QString& t, const long int& off, const int &  e): Box(s,t,off,e) {}
/////////////
MediaDataBox::MediaDataBox(const int& s, const QString& t, const long int& off, const int &  e):Box(s,t,off,e) {}
/////////////
MediaHeaderBox::MediaHeaderBox(const int& s, const QString& t, const long int& off, const int &  e, const int& v, const QList<int>& f):
    FullBox(s,t,off,e, v, f) ,
    version(v),
    flags(f)
{}
/////////////
MovieBox::MovieBox(const int& s, const QString& t, const long int& off, const int &  e):Box(s,t,off,e) {}
/////////////
MovieHeaderBox::MovieHeaderBox(const int& s, const QString& t, const long int& off, const int &  e, const int &v, const QList<int> &f):
    FullBox(s,t,off,e, v, f) ,
    version(v),
    flags(f)
{}
/////////////
TrackBox::TrackBox(const int& s, const QString& t, const long int& off, const int &  e): Box(s,t,off,e) {}
/////////////
TrackHeaderBox::TrackHeaderBox(const int& s, const QString& t, const long int& off, const int &  e, const int& v, const QList<int>& f):
    FullBox(s,t,off,e, v, f) ,
    version(v),
    flags(f)
{}
/////////////
TrackReferenceBox::TrackReferenceBox(const int& s, const QString& t, const long int& off, const int &  e): Box(s,t,off,e) {}
/////////////
HandlerBox::HandlerBox(const int& s, const QString& t, const long int& off, const int &  e, const int& v, const QList<int>& f):
    FullBox(s,t,off,e, v, f) ,
    version(v),
    flags(f)
{}
/////////////
MediaInformationBox::MediaInformationBox(const int& s, const QString& t, const long int& off, const int &  e): Box(s,t,off,e) {}
/////////////
VideoMediaHeaderBox::VideoMediaHeaderBox(const int& s, const QString& t, const long int& off, const int &  e, const int& v, const QList<int>& f): FullBox(s,t,off,e, v, f) {}
/////////////
SoundMediaHeaderBox::SoundMediaHeaderBox(const int& s, const QString& t, const long int& off, const int &  e, const int& v, const QList<int>& f): FullBox(s,t,off,e, v, f) {}
/////////////
HintMediaHeaderBox::HintMediaHeaderBox(const int& s, const QString& t, const long int& off, const int &  e, const int& v, const QList<int>& f): FullBox(s,t,off,e, v, f) {}
/////////////
NullMediaHeaderBox::NullMediaHeaderBox(const int& s, const QString& t, const long int& off, const int &  e, const int& v, const QList<int>& f): FullBox(s,t,off,e, v, f) {}
/////////////
DataInformationBox::DataInformationBox(const int& s, const QString& t, const long int& off, const int &  e): Box(s,t,off,e) {}
/////////////
DataEntryUrnBox::DataEntryUrnBox(const int& s, const QString& t, const long int& off, const int &  e, const int& v, const QList<int>& f):
    FullBox(s,t,off,e, v, f),
    version(v),
    flags(f)
{}
/////////////
DataEntryUrlBox::DataEntryUrlBox(const int& s, const QString& t, const long int& off, const int &  e, const int& v, const QList<int>& f):
    FullBox(s,t,off,e, v, f),
    version(v),
    flags(f)
{}
/////////////
DataReferenceBox::DataReferenceBox(const int& s, const QString& t, const long int& off, const int &  e, const int& v, const QList<int>& f):
    FullBox(s,t,off,e, v, f),
    version(v),
    flags(f)
{}
///////////////
FreeSpaceBox::FreeSpaceBox(bool c,const int& s, const QString& t, const long int& off, const int & e): Box(s,t,off,e), container(c) {}
///////////////
EditBox::EditBox(const int& s, const QString& t, const long int& off, const int &  e): Box(s,t,off,e) {}
///////////////
EditListBox::EditListBox(const int& s, const QString& t, const long int& off, const int &  e): Box(s,t,off,e) {}
///////////////
UserDataBox::UserDataBox(const int& s, const QString& t, const long int& off, const int &  e): Box(s,t,off,e) {}
///////////////
CopyRightBox::CopyRightBox(const int& s, const QString& t, const long int& off, const int &  e, const int& v, const QList<int>& f):
    FullBox(s,t,off,e, v, f) ,
    version(v),
    flags(f)
{}
///////////////
MovieExtendsBox::MovieExtendsBox(const int& s, const QString& t, const long int& off, const int &  e): Box(s,t,off,e) {}
///////////////
MovieExtendsHeaderBox::MovieExtendsHeaderBox(const int& s, const QString& t, const long int& off, const int &  e, const int& v, const QList<int>& f): FullBox(s,t,off,e, v, f) {}
///////////////
TrackExtendsBox::TrackExtendsBox(const int& s, const QString& t, const long int& off, const int &  e, const int& v, const QList<int>& f):
    FullBox(s,t,off,e, v, f) ,
    version(v),
    flags(f)
{}
///////////////
MovieFragmentBox::MovieFragmentBox(const int& s, const QString& t, const long int& off, const int &  e): Box(s,t,off,e) {}
///////////////
MovieFragmentHeaderBox::MovieFragmentHeaderBox(const int& s, const QString& t, const long int& off, const int &  e, const long &sn, const int& v, const QList<int>& f):
    FullBox(s,t,off,e, v, f),
    sequenceNumber(sn){}
QString MovieFragmentHeaderBox::getInfo() {
    QString tmp("");
    tmp.append("\n\tSequence number\t\t");
    tmp.append(QString::number(sequenceNumber));
    qDebug()<<sequenceNumber;
    return tmp;
}

///////////////

TrackFragmentBox::TrackFragmentBox(const int& s, const QString& t, const long int& off, const int &  e): Box(s,t,off,e) {}
///////////////
TrackFragmentHeaderBox::TrackFragmentHeaderBox(const int& s, const QString& t, const long int& off, const int &  e, const int& v, const QList<int>& f): FullBox(s,t,off,e, v, f) {}
///////////////
TrackRunBox::TrackRunBox(const int& s, const QString& t, const long int& off, const int &  e, const int& v, const QList<int>& f):
    FullBox(s,t,off,e, v, f) ,
    version(v),
    flags(f)
{}
///////////////
MovieFragmentRandomAccessBox::MovieFragmentRandomAccessBox(const int& s, const QString& t, const long int& off, const int &  e): Box(s,t,off,e) {}
///////////////
TrackFragmentRandomAccessBox::TrackFragmentRandomAccessBox(const int& s, const QString& t, const long int& off, const int &  e, const int& v, const QList<int>& f): FullBox(s,t,off,e, v, f) {}
///////////////
MovieFragmentRandomAccessOffsetBox::MovieFragmentRandomAccessOffsetBox(const int& s, const QString& t, const long int& off, const int &  e, const int& v, const QList<int>& f): FullBox(s,t,off,e, v, f) {}
///////////////
SampleDependencyTypeBox::SampleDependencyTypeBox(const int& s, const QString& t, const long int& off, const int &  e, const int& v, const QList<int>& f): FullBox(s,t,off,e, v, f) {}
///////////////
SampleToGroupBox::SampleToGroupBox(const int& s, const QString& t, const long int& off, const int &  e, const int& v, const QList<int>& f):
    FullBox(s,t,off,e, v, f),
    version(v),
    flags(f)
{}
///////////////
SampleGroupDescriptionBox::SampleGroupDescriptionBox(const int& s, const QString& t, const long int& off, const int &  e, const int& v, const QList<int>& f): FullBox(s,t,off,e, v, f) {}
///////////////
SampleScaleBox::SampleScaleBox(const int& s, const QString& t, const long int& off, const int &  e, const int& v, const QList<int>& f):
    FullBox(s,t,off,e, v, f),
    version(v),
    flags(f)
{}
///////////////
SubSampleInformationBox::SubSampleInformationBox(const int& s, const QString& t, const long int& off, const int &  e, const int& v, const QList<int>& f): FullBox(s,t,off,e, v, f) {}
///////////////
ProgressiveDownloadInfoBox::ProgressiveDownloadInfoBox(const int& s, const QString& t, const long int& off, const int &  e, const int& v, const QList<int>& f): FullBox(s,t,off,e, v, f) {}
///////////////
MetaBox::MetaBox(const int& s, const QString& t, const long int& off, const int &  e, const int& v, const QList<int>& f):
    FullBox(s,t,off,e, v, f),
    version(v),
    flags(f)
{}
///////////////
XMLBox::XMLBox(const int& s, const QString& t, const long int& off, const int &  e, const int& v, const QList<int>& f):
    FullBox(s,t,off,e, v, f),
    version(v),
    flags(f)
{}
///////////////
BinaryXMLBox::BinaryXMLBox(const int& s, const QString& t, const long int& off, const int &  e, const int& v, const QList<int>& f):
    FullBox(s,t,off,e, v, f),
    version(v),
    flags(f)
{}
///////////////
ItemLocationBox::ItemLocationBox(const int& s, const QString& t, const long int& off, const int &  e, const int& v, const QList<int>& f):
    FullBox(s,t,off,e, v, f),
    version(v),
    flags(f)
{}
///////////////
PrimaryItemBox::PrimaryItemBox(const int& s, const QString& t, const long int& off, const int &  e, const int& v, const QList<int>& f):
    FullBox(s,t,off,e, v, f),
    version(v),
    flags(f)
{}
///////////////
ItemProtectionBox::ItemProtectionBox(const int& s, const QString& t, const long int& off, const int &  e, const int& v, const QList<int>& f): FullBox(s,t,off,e, v, f) {}
///////////////
ItemInfoEntry::ItemInfoEntry(const int& s, const QString& t, const long int& off, const int &  e, const int& v, const QList<int>& f):
    FullBox(s,t,off,e, v, f) ,
    version(v),
    flags(f)
{}
///////////////
ItemInfoBox::ItemInfoBox(const int& s, const QString& t, const long int& off, const int &  e, const int& v, const QList<int>& f):
    FullBox(s,t,off,e, v, f) ,
    version(v),
    flags(f)
{}
///////////////
ProtectionSchemeInfoBox::ProtectionSchemeInfoBox(const int& s, const QString& t, const long int& off, const int &  e): Box(s,t,off,e) {}
///////////////
OriginalFormatBox::OriginalFormatBox(const int& s, const QString& t, const long int& off, const int &  e): Box(s,t,off,e) {}
///////////////
IPMPInfoBox::IPMPInfoBox(const int& s, const QString& t, const long int& off, const int &  e, const int& v, const QList<int>& f):
    FullBox(s,t,off,e, v, f) ,
    version(v),
    flags(f)
{}
///////////////
IPMPControlBox::IPMPControlBox(const int& s, const QString& t, const long int& off, const int &  e, const int& v, const QList<int>& f):
    FullBox(s,t,off,e, v, f),
    version(v),
    flags(f)
{}
///////////////
SchemeTypeBox::SchemeTypeBox(const int& s, const QString& t, const long int& off, const int &  e, const int& v, const QList<int>& f):
    FullBox(s,t,off,e, v, f),
    version(v),
    flags(f)
{}
///////////////
SchemeInformationBox::SchemeInformationBox(const int& s, const QString& t, const long int& off, const int &  e): Box(s,t,off,e) {}
///////////////
TimeScaleEntry::TimeScaleEntry(const int& s, const QString& t, const long int& off, const int &  e): Box(s,t,off,e) {}
///////////////
TimeOffset::TimeOffset(const int& s, const QString& t, const long int& off, const int &  e): Box(s,t,off,e) {}
///////////////
SequenceOffset::SequenceOffset(const int& s, const QString& t, const long int& off, const int &  e): Box(s,t,off,e) {}
///////////////
SRTPProcessBox::SRTPProcessBox(const int& s, const QString& t, const long int& off, const int &  e, const int& v, const QList<int>& f):
    FullBox(s,t,off,e, v, f),
    version(v),
    flags(f)
{}
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
SampleAuxiliaryInformationSizesBox::SampleAuxiliaryInformationSizesBox(const int& s, const QString& t, const long int& off, const int &  e, const int& v, const QList<int>& f): FullBox(s,t,off,e, v, f) {}
///////////////
SampleAuxiliaryInformationOffsetsBox::SampleAuxiliaryInformationOffsetsBox(const int& s, const QString& t, const long int& off, const int &  e, const int& v, const QList<int>& f): FullBox(s,t,off,e, v, f) {}
///////////////
TrackFragmentBaseMediaDecodeTimeBox::TrackFragmentBaseMediaDecodeTimeBox(const int& s, const QString& t, const long int& off, const int &  e, const int& v, const QList<int>& f): FullBox(s,t,off,e, v, f) {}
///////////////
LevelAssignmentBox::LevelAssignmentBox(const int& s, const QString& t, const long int& off, const int &  e, const int& v, const QList<int>& f): FullBox(s,t,off,e, v, f) {}
///////////////
SegmentIndexBox::SegmentIndexBox(const int& s, const QString& t, const long int& off, const int &  e, const int& v, const QList<int>& f):
    FullBox(s,t,off,e, v, f),
    version(v),
    flags(f)
{}
///////////////
SubsegmentIndexBox::SubsegmentIndexBox(const int& s, const QString& t, const long int& off, const int &  e, const int& v, const QList<int>& f): FullBox(s,t,off,e, v, f) {}
///////////////
ProducerReferenceTimeBox::ProducerReferenceTimeBox(const int& s, const QString& t, const long int& off, const int &  e, const int &v, const QList<int> &f): FullBox(s,t,off,e, v, f) {}
///////////////
