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
