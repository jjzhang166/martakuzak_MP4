#ifndef SEGMENTLIST_H
#define SEGMENTLIST_H

#include <QString>
#include <QList>

class SegmentList {
private:
    //attrs
    unsigned int timescale;
    unsigned long int duration;
    Initialization initialization;
    QList<SegmentURL> segmentURLs;
public:
    SegmentList(const unsigned int& ts, const unsigned long int& dur, const Initialization& init, const QList<SegmentURL> surl);
};

class Initialization {
private:
    //attrs
    QString range;
    QString sourceURL;
public:
    Initialization(const QString& range, const QString& sURL);
};

class SegmentURL {
private:
    //attrs
    QString media;
    QString mediaRange;
    QString indexRange;
    //QString index;
public:
    SegmentURL(const QString& media, const QString& mediaRange, const QString& indexRange);
};

#endif // SEGMENTLIST_H
