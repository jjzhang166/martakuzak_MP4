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
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class TrackHeaderBox : public FullBox
{
private:
    unsigned int version;
    QList<unsigned int> flags;
public:
    TrackHeaderBox(const unsigned int& s, const QString& t, const unsigned long int& off, const unsigned int &  e, const unsigned int& v,
                   const QList<unsigned int>& f);
    virtual QString getFullName() { return QString("Track Header Box"); }
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
