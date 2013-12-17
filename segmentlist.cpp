#include "segmentlist.h"

SegmentList::SegmentList(const unsigned int &ts, const unsigned long &dur, const Initialization &init, const QList<SegmentURL> surl):
    timescale(ts), duration(dur), initialization(init), segmentURLs(surl)
{
}

Initialization::Initialization(const QString& r, const QString &sURL): range(r), sourceURL(sURL) {}

SegmentURL::SegmentURL(const QString& med, const QString& mRange, const QString& iRange):
    media(med), mediaRange(mRange), indexRange(iRange) {}
