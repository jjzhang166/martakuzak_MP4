#ifndef BOX_H
#define BOX_H

#include <QString>

/*!
 * \brief The Box class
 * is represantion of MP4 Box
 */

class Box {
private:
    /*!
     * \brief size size of the box
     */
    int size;
    /*!
     * \brief type type of the box
     */
    QString type;
    /*!
     * \brief extended_type indicates whether the box has extended type (1) or not (0)
     */
    int extended_type;
    /*!
     * \brief offset bit offset of the box location
     */
    long int offset;
public:
    /*!
     * \brief Box
     * constructor
     * \param s size
     * \param t type
     * \param off offset
     * \param e extended_type (0 or 1)
     */
    Box(int s=0,QString t="", long int off=0, int e=0);
};
/////////////////////////////////////////////////////////////////////////////////////////////////
class FullBox : public Box
{
public:
    FullBox(int s=0,QString t="", long int off=0, int e=0);
};
//////////////////////////////////////////////////////////////////////////////////////////////////
class FileTypeBox : public Box
{
public:
    FileTypeBox(int s=0,QString t="", long int off=0, int e=0);
};
/////////////////////////////////////////////////////////////////////////////////////////////////////
class MediaBox : public Box
{
public:
    MediaBox(int s=0,QString t="", long int off=0, int e=0);
};
/////////////////////////////////////////////////////////////////////////////////////////////////////
class MediaDataBox : public Box
{
public:
    MediaDataBox(int s=0,QString t="", long int off=0, int e=0);
};
//////////////////////////////////////////////////////////////////////////////////////////////////////
class MediaHeaderBox : public FullBox
{
public:
    MediaHeaderBox(int s=0,QString t="", long int off=0, int e=0);
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class MovieBox : public Box
{
public:
    MovieBox(int s=0,QString t="", long int off=0, int e=0);
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class MovieHeaderBox : public FullBox
{
public:
    MovieHeaderBox(int s=0,QString t="", long int off=0, int e=0);
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class TrackBox : public Box
{
public:
    TrackBox(int s=0,QString t="", long int off=0, int e=0);
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class TrackHeaderBox : public FullBox
{
public:
    TrackHeaderBox(int s=0,QString t="", long int off=0, int e=0);
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////
class TrackReferenceBox : public Box
{
public:
    TrackReferenceBox(int s=0,QString t="", long int off=0, int e=0);
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // BOX_H

