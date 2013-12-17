#ifndef PERIOD_H
#define PERIOD_H

#include "segmentlist.h"

class Period
{
private:
    unsigned int id;
    QString duration;
    QString start;
public:
    Period(const unsigned int& i, const QString& dur, const QString& st);
};
///////////////////////////////////////////////////////////////////////////////////
class BaseURL {
private:
    QString content;
    //attrs
    QString serviceLocation;
    QString byteRange;
public:
    BaseURL(const QString& con, const QString& sl, const QString& br);

};
///////////////////////////////////////////////////////////////////////////////////
class Representation {
private:
    unsigned int id;
    QString mimeType;
    QString codecs;
    unsigned int width;
    unsigned int height;
    unsigned int frameRate;
    QString sar;
    unsigned short int startsWithSAP;
    unsigned int bandwidth;
    //
    BaseURL baseurl;
    SegmentList segmentList;
public:
    Representation(const unsigned int& i, const QString& mime, const QString& cod, const unsigned int& w, const unsigned int& h,
                   const unsigned int& fr, const QString& sar, const unsigned short int& swSAP, const unsigned int& band,
                   const BaseURL& burl, const SegmentList& slist);
};
///////////////////////////////////////////////////////////////////////////////////
/// \brief The AdaptationSet class
///
///
class AdaptationSet {
private:
    //attrs
    bool segmentAlignment;
    bool subsegmentAlignment;
    bool bitstreamSwitching;
    unsigned int maxWidth;
    unsigned int maxHeight;
    unsigned int maxFrameRate;
    unsigned short int startsWithSAP;
    unsigned short int subsegmentStartsWithSAP;
    QString par;
    QString mimeType;
    QString codecs;
    QString frameRate;
    QString lang;
    //
    QList<Representation> representations;
public:
    AdaptationSet(const bool& segAlig, const bool& subsegAlig, const bool& bitsSwit, const unsigned int& maxW, const unsigned int& maxH,
                  const unsigned int& maxFR, const unsigned short int& swSAP, const unsigned short int& subsswSAP, const QString& p,
                  const QString& mimeT, const QString& cod, const QString& fr, const QString& lan, const QList<Representation> rep);

};

#endif // PERIOD_H
