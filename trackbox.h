/*!
 * \file TrackBox
 * \details
 * TrackBox
 * TrackExtendsBox
 * TrackFragmentBaseMediaDecodeTimeBox
 * TrackFragmentBox
 * TrackFragmentHeaderBox
 * TrackFragmentRandomAccessBox
 * TrackHeaderBox
 * TrackReferenceBox
 * TrackRunBox
 */
#ifndef TRACKBOX_H
#define TRACKBOX_H

#include "box.h"

class TrackBox : public Box
{
public:
    TrackBox(const unsigned int& s, const QString& t, const unsigned long int& off, const unsigned int &  e);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Track Box"); }
    virtual QString getInfo() {
        return QString("Track Box is a box container for a single track of presentation.");
    }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class TrackHeaderBox : public FullBox
{
private:
    unsigned int version;
    QList<unsigned int> flags;
    unsigned long int creationTime;
    unsigned long int modificationTime;
    unsigned int trackID;
    unsigned int reserved1;
    unsigned int long duration;
    QList<unsigned int> reserved2;
    unsigned int layer;
    unsigned int alternateGroup;
    unsigned int volume;
    unsigned int reserved3;
    QList<unsigned long int> matrix;
    unsigned int width;
    unsigned int height;
public:
    TrackHeaderBox(const unsigned int& s, const QString& t, const unsigned long int& off, const unsigned int &  e, const unsigned int& v,
                   const QList<unsigned int>& f, const unsigned long int& ct, const unsigned long int & mt, const unsigned int & tid,
                   const unsigned int & r1, const unsigned long int & dur, const QList<unsigned int> & r2, const unsigned int & lay,
                   const unsigned int & ag, const unsigned int & vol, const unsigned int & r3, const QList<unsigned long int> mx,
                   const unsigned int & wdth, const unsigned int & hght);
    virtual QString getFullName() { return QString("Track Header Box"); }
    virtual QString getInfo();
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class TrackReferenceBox : public Box
{
public:
    TrackReferenceBox(const unsigned int& s, const QString& t, const unsigned long int& off, const unsigned int &  e);
    virtual QString getFullName() { return QString("Track Reference Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class TrackExtendsBox : public FullBox
{
private:
    unsigned int version;
    QList<unsigned int> flags;
public:
    TrackExtendsBox(const unsigned int& s, const QString& t, const unsigned long int& off, const unsigned int &  e, const unsigned int& v,
                    const QList<unsigned int>& f);
    virtual QString getFullName() { return QString("Track Extends Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class TrackFragmentBox : public Box
{
public:
    TrackFragmentBox(const unsigned int& s, const QString& t, const unsigned long int& off, const unsigned int &  e);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Track Fragment Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class TrackFragmentHeaderBox : public FullBox
{
private:
    unsigned int version;
    QList<unsigned int> flags;
public:
    TrackFragmentHeaderBox(const unsigned int& s, const QString& t, const unsigned long int& off, const unsigned int &  e, const unsigned int& v, const QList<unsigned int>& f);
    virtual QString getFullName() { return QString("Track Fragment Header Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class TrackRunBox : public FullBox
{
private:
    unsigned int version;
    QList<unsigned int> flags;
public:
    TrackRunBox(const unsigned int& s, const QString& t, const unsigned long int& off, const unsigned int &  e, const unsigned int& v, const QList<unsigned int>& f);
    virtual QString getFullName() { return QString("Track Run Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class TrackFragmentRandomAccessBox : public FullBox
{
private:
    unsigned int version;
    QList<unsigned int> flags;
public:
    TrackFragmentRandomAccessBox(const unsigned int& s, const QString& t, const unsigned long int& off, const unsigned int &  e, const unsigned int& v, const QList<unsigned int>& f);
    virtual QString getFullName() { return QString("Track Fragment Random Access Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class TrackFragmentBaseMediaDecodeTimeBox : public FullBox
{
private:
    unsigned int version;
    QList<unsigned int> flags;
public:
    TrackFragmentBaseMediaDecodeTimeBox(const unsigned int& s, const QString& t, const unsigned long int& off, const unsigned int &  e, const unsigned int& v, const QList<unsigned int>& f);
    virtual QString getFullName() { return QString("Track Fragment Base Media Decode Time Box"); }
};

#endif // TRACKBOX_H
