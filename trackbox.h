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
    TrackBox(const int& s, const QString& t, const long int& off, const int& e);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Track Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class TrackHeaderBox : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    TrackHeaderBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString("Track Header Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class TrackReferenceBox : public Box
{
public:
    TrackReferenceBox(const int& s, const QString& t, const long int& off, const int& e);
    virtual QString getFullName() { return QString("Track Reference Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class TrackExtendsBox : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    TrackExtendsBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString("Track Extends Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class TrackFragmentBox : public Box
{
public:
    TrackFragmentBox(const int& s, const QString& t, const long int& off, const int& e);
    virtual bool isContainer() { return true; }
    virtual QString getFullName() { return QString("Track Fragment Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class TrackFragmentHeaderBox : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    TrackFragmentHeaderBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString("Track Fragment Header Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class TrackRunBox : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    TrackRunBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString("Track Run Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class TrackFragmentRandomAccessBox : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    TrackFragmentRandomAccessBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString("Track Fragment Random Access Box"); }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class TrackFragmentBaseMediaDecodeTimeBox : public FullBox
{
private:
    int version;
    QList<int> flags;
public:
    TrackFragmentBaseMediaDecodeTimeBox(const int& s, const QString& t, const long int& off, const int& e, const int& v, const QList<int>& f);
    virtual QString getFullName() { return QString("Track Fragment Base Media Decode Time Box"); }
};

#endif // TRACKBOX_H
