#include "box.h"


Box::Box(int s,QString t, long int off, int e): size(s),type(t),offset(off), extended_type(e) {}
/////////////
FullBox::FullBox(int s,QString t, long int off, int e):Box(s,t,off,e) {}
/////////////
FileTypeBox::FileTypeBox(int s, QString t, long off, int e): Box(s,t,off,e) {}
/////////////
MediaBox::MediaBox(int s,QString t, long int off, int e): Box(s,t,off,e) {}
/////////////
MediaDataBox::MediaDataBox(int s,QString t, long int off, int e):Box(s,t,off,e) {}
/////////////
MediaHeaderBox::MediaHeaderBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
/////////////
MovieBox::MovieBox(int s,QString t, long int off, int e):Box(s,t,off,e) {}
/////////////
MovieHeaderBox::MovieHeaderBox(int s,QString t, long int off, int e):FullBox(s,t,off,e) {}
/////////////
TrackBox::TrackBox(int s,QString t, long int off, int e): Box(s,t,off,e) {}
/////////////
TrackHeaderBox::TrackHeaderBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
/////////////
TrackReferenceBox::TrackReferenceBox(int s,QString t, long int off, int e): Box(s,t,off,e) {}
/////////////
HandlerBox::HandlerBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
/////////////
MediaInformationBox::MediaInformationBox(int s,QString t, long int off, int e): Box(s,t,off,e) {}
/////////////
VideoMediaHeaderBox::VideoMediaHeaderBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
/////////////
SoundMediaHeaderBox::SoundMediaHeaderBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
/////////////
HintMediaHeaderBox::HintMediaHeaderBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
/////////////
NullMediaHeaderBox::NullMediaHeaderBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
/////////////
DataInformationBox::DataInformationBox(int s,QString t, long int off, int e): Box(s,t,off,e) {}
/////////////
DataEntryUrnBox::DataEntryUrnBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
/////////////
DataEntryUrlBox::DataEntryUrlBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
/////////////
DataReferenceBox::DataReferenceBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
/////////////
SampleTableBox::SampleTableBox(int s,QString t, long int off, int e): Box(s,t,off,e) {}
/////////////
TimeToSampleBox::TimeToSampleBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
/////////////
CompositionOffsetBox::CompositionOffsetBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
/////////////
SampleDescriptionBox::SampleDescriptionBox(int s,QString t, long int off, int e): Box(s,t,off,e) {}
/////////////
SampleSizeBox::SampleSizeBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
/////////////
CompactSampleSizeBox::CompactSampleSizeBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
/////////////
SampleToChunkBox::SampleToChunkBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
/////////////
ChunkOffsetBox::ChunkOffsetBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
/////////////
ChunkLargeOffsetBox::ChunkLargeOffsetBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
/////////////
SyncSampleBox::SyncSampleBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
/////////////
DegradationPriorityBox::DegradationPriorityBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
///////////////
PaddingBitsBox::PaddingBitsBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
///////////////
FreeSpaceBox::FreeSpaceBox(bool c,int s,QString t, long int off, int e): Box(s,t,off,e), container(c) {}
///////////////
EditBox::EditBox(int s,QString t, long int off, int e): Box(s,t,off,e) {}
///////////////
EditListBox::EditListBox(int s,QString t, long int off, int e): Box(s,t,off,e) {}
///////////////
UserDataBox::UserDataBox(int s,QString t, long int off, int e): Box(s,t,off,e) {}
///////////////
CopyRightBox::CopyRightBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
///////////////
MovieExtendsBox::MovieExtendsBox(int s,QString t, long int off, int e): Box(s,t,off,e) {}
///////////////
MovieExtendsHeaderBox::MovieExtendsHeaderBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
///////////////
TrackExtendsBox::TrackExtendsBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
///////////////
MovieFragmentBox::MovieFragmentBox(int s,QString t, long int off, int e): Box(s,t,off,e) {}
///////////////
MovieFragmentHeaderBox::MovieFragmentHeaderBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
///////////////
TrackFragmentBox::TrackFragmentBox(int s,QString t, long int off, int e): Box(s,t,off,e) {}
///////////////
TrackFragmentHeaderBox::TrackFragmentHeaderBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
///////////////
TrackRunBox::TrackRunBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
///////////////
MovieFragmentRandomAccessBox::MovieFragmentRandomAccessBox(int s,QString t, long int off, int e): Box(s,t,off,e) {}
///////////////
TrackFragmentRandomAccessBox::TrackFragmentRandomAccessBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
///////////////
MovieFragmentRandomAccessOffsetBox::MovieFragmentRandomAccessOffsetBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
///////////////
SampleDependencyTypeBox::SampleDependencyTypeBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
///////////////
SampleToGroupBox::SampleToGroupBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
///////////////
SampleGroupDescriptionBox::SampleGroupDescriptionBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
///////////////
SampleScaleBox::SampleScaleBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
///////////////
SubSampleInformationBox::SubSampleInformationBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
///////////////
ProgressiveDownloadInfoBox::ProgressiveDownloadInfoBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
///////////////
MetaBox::MetaBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
///////////////
XMLBox::XMLBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
///////////////
BinaryXMLBox::BinaryXMLBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
///////////////
ItemLocationBox::ItemLocationBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
///////////////
PrimaryItemBox::PrimaryItemBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
///////////////
ItemProtectionBox::ItemProtectionBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
///////////////
ItemInfoEntry::ItemInfoEntry(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
///////////////
ItemInfoBox::ItemInfoBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
///////////////
ProtectionSchemeInfoBox::ProtectionSchemeInfoBox(int s,QString t, long int off, int e): Box(s,t,off,e) {}
///////////////
OriginalFormatBox::OriginalFormatBox(int s,QString t, long int off, int e): Box(s,t,off,e) {}
///////////////
IPMPInfoBox::IPMPInfoBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
///////////////
IPMPControlBox::IPMPControlBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
///////////////
SchemeTypeBox::SchemeTypeBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
///////////////
SchemeInformationBox::SchemeInformationBox(int s,QString t, long int off, int e): Box(s,t,off,e) {}
///////////////
TimeScaleEntry::TimeScaleEntry(int s,QString t, long int off, int e): Box(s,t,off,e) {}
///////////////
TimeOffset::TimeOffset(int s,QString t, long int off, int e): Box(s,t,off,e) {}
///////////////
SequenceOffset::SequenceOffset(int s,QString t, long int off, int e): Box(s,t,off,e) {}
///////////////
SRTPProcessBox::SRTPProcessBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
///////////////
MovieHintInformation::MovieHintInformation(int s,QString t, long int off, int e): Box(s,t,off,e) {}
///////////////
RTPMovieHintInformation::RTPMovieHintInformation(int s,QString t, long int off, int e): Box(s,t,off,e) {}
///////////////
RTPTrackSDPHintInformation::RTPTrackSDPHintInformation(int s,QString t, long int off, int e): Box(s,t,off,e) {}
///////////////
HintStatisticsBox::HintStatisticsBox(int s,QString t, long int off, int e): Box(s,t,off,e) {}
///////////////




