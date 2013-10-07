#include "box.h"


Box::Box(const int &s, const QString &t, const long &off, const int & e): size(s),type(t),offset(off), extended_type(e) {}
/////////////
FullBox::FullBox(const int& s, const QString& t, const long int& off, const int &  e, const int& v, const QList<int>& f):
    Box(s,t,off,e),
    version(v),
    flags(f)
{}
QString FullBox::getInfo() {
    QString tmp("");
    tmp.append("Version\t\t");
    tmp.append(QString::number(version));
    tmp.append("\nFlags\t\t");
    tmp.append(QString::number(flags.at(0)));
    tmp.append(" | ");
    tmp.append(QString::number(flags.at(1)));
    tmp.append(" | ");
    tmp.append(QString::number(flags.at(2)));
    tmp.append(" | ");
    return tmp;
}
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
MovieHeaderBox::MovieHeaderBox(const int& s, const QString& t, const long int& off, const int &  e, const int &v, const QList<int> &f,
                               int ct, int mt, int ts, int d, int r, int vl, int r16,
                               int r32, QList<int> mx, QList<int> pr, int nid):
    FullBox(s,t,off,e, v, f) ,
    version(v),
    flags(f),
    creationTime(ct),
    modificationTime(mt),
    timeScale(ts),
    duration(d),
    rate(r),
    volume(vl),
    reserved16(r16),
    reserved32(r32),
    nextTrackId(nid),
    matrix(mx),
    predefined(pr)
{}
QString MovieHeaderBox::getInfo() {
    QString tmp("");
    tmp.append(FullBox::getInfo());
    tmp.append("\nCreation time\t\t");
    tmp.append(QString::number(creationTime));
    tmp.append("\nModification time\t");
    tmp.append(QString::number(modificationTime));
    tmp.append("\nTime scale\t\t");
    tmp.append(QString::number(timeScale));
    tmp.append("\nDuration\t\t");
    tmp.append(QString::number(duration));
    tmp.append("\nRate\t\t");
    tmp.append(QString::number(rate));
    tmp.append("\nVolume\t\t");
    tmp.append(QString::number(volume));
    tmp.append("\nReserved16\t\t");
    tmp.append(QString::number(reserved16));
    tmp.append("\nReserved32\t\t");
    tmp.append(QString::number(reserved32));
    tmp.append("\nMatrix\t\t");
    QList<int>::iterator i;
    for (i = matrix.begin(); i !=matrix.end(); ++i) {
        tmp.append(*i);
        tmp.append(" | ");
    }
    tmp.append("\nPredefined\t\t");
    QList<int>::iterator k;
    for (k = predefined.begin(); k !=predefined.end(); ++k) {
        tmp.append(*k);
        tmp.append(" | ");
    }
    tmp.append("\nNext track id\t\t");
    tmp.append(QString::number(nextTrackId));
    return tmp;
}
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
MovieFragmentBox::MovieFragmentBox(const int& s, const QString& t, const long int& off, const int &  e): Box(s,t,off,e) {}
///////////////
MovieFragmentHeaderBox::MovieFragmentHeaderBox(const int& s, const QString& t, const long int& off, const int &  e, const long &sn, const int& v, const QList<int>& f):
    FullBox(s,t,off,e, v, f),
    sequenceNumber(sn){}
QString MovieFragmentHeaderBox::getInfo() {
    QString tmp("");
    tmp.append(FullBox::getInfo());
    tmp.append("\n\tSequence number\t\t");
    tmp.append(QString::number(sequenceNumber));
    qDebug()<<sequenceNumber;
    return tmp;
}
///////////////
MovieFragmentRandomAccessBox::MovieFragmentRandomAccessBox(const int& s, const QString& t, const long int& off, const int &  e): Box(s,t,off,e) {}

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
LevelAssignmentBox::LevelAssignmentBox(const int& s, const QString& t, const long int& off, const int &  e, const int& v, const QList<int>& f): FullBox(s,t,off,e, v, f) {}
///////////////
SegmentIndexBox::SegmentIndexBox(const int& s, const QString& t, const long int& off, const int &  e, const int& v, const QList<int>& f,
                                 const int &ri, const int &ts, const int& myEarliestPresentationTime, const int& myFirstOffset,
                                 const int &myReserved, const QList<bool>& myReferenceType, const QList<int> myReferenceSize,
                                 const QList<int> & mySubsegmentDuration,const QList<bool> & myStartsWithSAP, const QList<int>& mySAPType,
                                 const QList<int>& mySAPDeltaTime):
    FullBox(s,t,off,e, v, f),
    version(v),
    flags(f),
    referenceId(ri),
    timescale(ts),
    earliestPresentationTime(myEarliestPresentationTime),
    firstOffset(myFirstOffset),
    reserved(myReserved),
    referenceType(myReferenceType),
    referenceSize(myReferenceSize),
    subsegmentDuration(mySubsegmentDuration),
    startsWithSAP(myStartsWithSAP),
    SAPType(mySAPType),
    SAPDeltaTime(mySAPDeltaTime)
{}
QString SegmentIndexBox::getInfo() {
    QString tmp;
    tmp.append(FullBox::getInfo());
    tmp.append("\nReference ID\t\t");
    tmp.append(QString::number(referenceId));
    tmp.append("\nTimescale\t\t");
    tmp.append(QString::number(timescale));
    tmp.append("\nEarliest presentation time\t");
    tmp.append(QString::number(earliestPresentationTime));
    tmp.append("\nFirst offset\t\t");
    tmp.append(QString::number(firstOffset));
    tmp.append("\nReserved\t\t");
    tmp.append(QString::number(reserved));
    int size = referenceType.size();
    if(size>0) {
        tmp.append("\nReference type\t\t");
        for(int i=0; i<size; i++) {
            tmp.append(QString::number(referenceType.at(i)));
            tmp.append(" |");
        }
        tmp.append("\nReference size\t\t");
        for(int i=0; i<size; i++) {
            tmp.append(QString::number(referenceSize.at(i)));
            tmp.append(" |");
        }
        tmp.append("\nSubsegment duration\t\t");
        for(int i=0; i<size; i++) {
            tmp.append(QString::number(subsegmentDuration.at(i)));
            tmp.append(" |");
        }
        tmp.append("\nStarts with SAP\t\t");
        for(int i=0; i<size; i++) {
            tmp.append(QString::number(startsWithSAP.at(i)));
            tmp.append(" |");
        }
        tmp.append("\nSAP type\t\t");
        for(int i=0; i<size; i++) {
            tmp.append(QString::number(SAPType.at(i)));
            tmp.append(" |");
        }
        tmp.append("\nSAP delta time\t\t");
        for(int i=0; i<size; i++) {
            tmp.append(QString::number(SAPDeltaTime.at(i)));
            tmp.append(" |");
        }
    }
    return tmp;
}

///////////////
SubsegmentIndexBox::SubsegmentIndexBox(const int& s, const QString& t, const long int& off, const int &  e, const int& v, const QList<int>& f): FullBox(s,t,off,e, v, f) {}
///////////////
ProducerReferenceTimeBox::ProducerReferenceTimeBox(const int& s, const QString& t, const long int& off, const int &  e, const int &v, const QList<int> &f): FullBox(s,t,off,e, v, f) {}
///////////////
