#include "trackbox.h"
///////////////////
TrackBox::TrackBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int &  e): Box(s,t,off,e) {}
/////////////
TrackHeaderBox::TrackHeaderBox(const unsigned  int& s, const QString& t, const unsigned long int& off, const unsigned  int &  e,
                               const unsigned  int& v, const QList<unsigned int>& f, const unsigned long &ct, const unsigned long &mt,
                               const unsigned int &tid, const unsigned int &r1, const unsigned long &dur, const QList<unsigned int> &r2,
                               const unsigned int &lay, const unsigned int &ag, const unsigned int &vol, const unsigned int &r3,
                               const QList<unsigned long> mx, const unsigned int &wdth, const unsigned int &hght):
    FullBox(s,t,off,e, v, f) ,
    version(v),
    flags(f),
    creationTime(ct),
    modificationTime(mt),
    trackID(tid),
    duration(dur),
    volume(vol),
    reserved1(r1),
    reserved2(r2),
    reserved3(r3),
    layer(lay),
    alternateGroup(ag),
    width(wdth),
    height(hght),
    matrix(mx)
{}
QString TrackHeaderBox::getInfo() {
    QString tmp("");
    tmp.append(FullBox::getInfo());
    tmp.append("\nCreation time\t\t");
    tmp.append(QString::number(creationTime));
    tmp.append("\nModification time\t");
    tmp.append(QString::number(modificationTime));
    tmp.append("\nTrack ID\t\t");
    tmp.append(QString::number(trackID));
    tmp.append("\nReserved1\t\t");
    tmp.append(QString::number(reserved1));
    tmp.append("\nDuration\t\t");
    tmp.append(QString::number(duration));
    tmp.append("\nReserved2\t\t");
    int reserved2Size = reserved2.size();
    for (int i = 0; i<reserved2Size; ++i) {
        tmp.append(QString::number(reserved2.at(i)));
        tmp.append(" | ");
    }
    tmp.append("\nLayer\t\t");
    tmp.append(QString::number(layer));
    tmp.append("\nAlternate group\t\t");
    tmp.append(QString::number(alternateGroup));
    tmp.append("\nVolume\t\t");
    tmp.append(QString::number(volume));
    tmp.append("\nReserved3\t\t");
    tmp.append(QString::number(reserved3));
    tmp.append("\nMatrix\t\t");
    int matrixSize = matrix.size();
    for (int i = 0; i<matrixSize; ++i) {
        tmp.append(QString::number(matrix.at(i)));
        tmp.append(" | ");
    }
    tmp.append("\nWidth\t\t");
    tmp.append(QString::number(width));
    tmp.append("\nHeight\t\t");
    tmp.append(QString::number(height));
    return tmp;
}

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
