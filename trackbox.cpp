#include "trackbox.h"

TrackBox::TrackBox(const int& s, const QString& t, const long int& off, const int &  e): Box(s,t,off,e) {}
/////////////
TrackHeaderBox::TrackHeaderBox(const int& s, const QString& t, const long int& off, const int &  e,
                               const int& v, const QList<int>& f):
    FullBox(s,t,off,e, v, f) ,
    version(v),
    flags(f)
{}
/////////////
TrackReferenceBox::TrackReferenceBox(const int& s, const QString& t, const long int& off, const int &  e): Box(s,t,off,e) {}
/////////////
HandlerBox::HandlerBox(const int& s, const QString& t, const long int& off, const int &  e,
                       const int& v, const QList<int>& f):
    FullBox(s,t,off,e, v, f) ,
    version(v),
    flags(f)
{}
/////////////
TrackExtendsBox::TrackExtendsBox(const int& s, const QString& t, const long int& off, const int &  e,
                                 const int& v, const QList<int>& f):
    FullBox(s,t,off,e, v, f) ,
    version(v),
    flags(f)
{}
///////////////
TrackFragmentBox::TrackFragmentBox(const int& s, const QString& t, const long int& off, const int &  e): Box(s,t,off,e) {}
///////////////
TrackFragmentHeaderBox::TrackFragmentHeaderBox(const int& s, const QString& t, const long int& off, const int &  e,
                                               const int& v, const QList<int>& f):
    FullBox(s,t,off,e, v, f)
{}
///////////////
TrackRunBox::TrackRunBox(const int& s, const QString& t, const long int& off, const int &  e,
                         const int& v, const QList<int>& f):
    FullBox(s,t,off,e, v, f) ,
    version(v),
    flags(f)
{}
///////////////
TrackFragmentRandomAccessBox::TrackFragmentRandomAccessBox(const int& s, const QString& t, const long int& off, const int &  e,
                                                           const int& v, const QList<int>& f):
    FullBox(s,t,off,e, v, f)
{}
///////////////
TrackFragmentBaseMediaDecodeTimeBox::TrackFragmentBaseMediaDecodeTimeBox(const int& s, const QString& t, const long int& off, const int &  e,
                                                                         const int& v, const QList<int>& f):
    FullBox(s,t,off,e, v, f)
{}
