#include "sampleentry.h"

/////////////
SampleEntry::SampleEntry(int s, QString t, long int off, int e):
    Box(s,t,off,e)
{
}
/////////////
VisualSampleEntry::VisualSampleEntry(int s,QString t, long int off, int e): SampleEntry(s,t,off,e) {}
/////////////
AudioSampleEntry::AudioSampleEntry(int s,QString t, long int off, int e): SampleEntry(s,t,off,e) {}
/////////////
HintSampleEntry::HintSampleEntry(int s,QString t, long int off, int e): SampleEntry(s,t,off,e) {}
/////////////
MP4VisualSampleEntry::MP4VisualSampleEntry(int s,QString t, long int off, int e): VisualSampleEntry(s,t,off,e) {}
///////////////
MP4AudioSampleEntry::MP4AudioSampleEntry(int s,QString t, long int off, int e): AudioSampleEntry(s,t,off,e) {}
///////////////
MpegSampleEntry::MpegSampleEntry(int s,QString t, long int off, int e): SampleEntry(s,t,off,e) {}
///////////////
/////MP4///////
ObjectDescriptorBox::ObjectDescriptorBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
///////////////
ESDBox::ESDBox(int s,QString t, long int off, int e): FullBox(s,t,off,e) {}
///////////////

