#include "period.h"

Period::Period(const unsigned int &i, const QString &dur, const QString &st): id(i), duration(dur), starts(st)
{
}

BaseURL::BaseURL(const QString& con, const QString &sl, const QString &br):
    content(con), serviceLocation(sl), byteRange(br) {

}


Representation::Representation(const unsigned int& i, const QString& mime, const QString& cod, const unsigned int& w, const unsigned int& h,
                               const unsigned int& fr, const QString& sa, const unsigned short int& swSAP, const unsigned int& band,
                               const BaseURL &burl, const SegmentList &slist):
    id(i), mimeType(mime), codecs(cod), width(w), height(h), frameRate(fr), sar(sa), startsWithSAP(swSAP), bandwith(band), baseurl(burl),
    segmentList(slist)
{

}

AdaptationSet::AdaptationSet(const bool& segAlig, const bool& subsegAlig, const bool& bitsSwit, const unsigned int& maxW,
                             const unsigned int& maxH, const unsigned int& maxFR, const unsigned short int& swSAP,
                             const unsigned short int& subsswSAP, const QString& p, const QString& mimeT, const QString& cod,
                             const QString& fr, const QString& lan, const QList<Representation> rep):
    segmentAlignment(segAlig), subsegmentAlignment(subsegAlig), bitstreamSwitching(bitsSwit), maxWidth(maxW), maxHeight(maxH),
    maxFrameRate(maxFR), startsWithSAP(swSAP), subsegmentStartsWithSAP(subsswSAP), par(p), mimeType(mimeT), codecs(cod),
    frameRate(fr), lang(lan), representations(rep)
{

}
