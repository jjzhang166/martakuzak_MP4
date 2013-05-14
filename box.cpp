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
