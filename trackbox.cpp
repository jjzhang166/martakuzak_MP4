#include "trackbox.h"
///////////////////
TrackBox::TrackBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int &  e): Box(s,t,off,e) {}
/////////////
TrackHeaderBox::TrackHeaderBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int &  e,
                               const unsigned  int& v, const QList<unsigned int>& f):
    FullBox(s,t,off,e, v, f) ,
    version(v),
    flags(f)
{}
/////////////
TrackReferenceBox::TrackReferenceBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int &  e): Box(s,t,off,e) {}
/////////////
HandlerBox::HandlerBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int &  e,
                       const unsigned  int& v, const QList<unsigned int>& f):
    FullBox(s,t,off,e, v, f) ,
    version(v),
    flags(f)
{}
/////////////
TrackExtendsBox::TrackExtendsBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int &  e,
                                 const unsigned  int& v, const QList<unsigned int>& f):
    FullBox(s,t,off,e, v, f) ,
    version(v),
    flags(f)
{}
///////////////
TrackFragmentBox::TrackFragmentBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int &  e): Box(s,t,off,e) {}
///////////////
TrackFragmentHeaderBox::TrackFragmentHeaderBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int &  e,
                                               const unsigned  int& v, const QList<unsigned int>& f):
    FullBox(s,t,off,e, v, f)
{}
///////////////
TrackRunBox::TrackRunBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int &  e,
                         const unsigned  int& v, const QList<unsigned int>& f):
    FullBox(s,t,off,e, v, f) ,
    version(v),
    flags(f)
{}
///////////////
TrackFragmentRandomAccessBox::TrackFragmentRandomAccessBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int &  e,
                                                           const unsigned  int& v, const QList<unsigned int>& f):
    FullBox(s,t,off,e, v, f)
{}
///////////////
TrackFragmentBaseMediaDecodeTimeBox::TrackFragmentBaseMediaDecodeTimeBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int &  e,
                                                                         const unsigned  int& v, const QList<unsigned int>& f):
    FullBox(s,t,off,e, v, f)
{}
