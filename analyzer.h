#ifndef ANALYZER_H
#define ANALYZER_H
#include <QString>
#include <QString>
#include <QByteArray>
#include <QFile>
#include <QVariant>
#include <qDebug>
#include "treemodel.h"
#include "treeitem.h"


class TreeItem;
class TreeModel;
/*!
 * \brief The Analyzer class - provides with tools to analyze MP4 file.
 */
class Analyzer
{
public:
    Analyzer();
    /*!
     * \brief Analyzer - constructor
     * \param fileName name of the file to be analyzed
     */
    Analyzer(const QString& fileName);
    ~Analyzer();
    /*!
     * \brief setData adds children to the parent.
     * \param parent parent of the tree fragment that children are to be analyzed.
     */
    void setData(TreeItem* parent, QHash<long,TreeItem*>* items);

    /*!
     * \brief valueOfGroupOfFields converts subarray of QByteArray to unsigned long int
     * \param array array which fragment is to be converted
     * \param begin number of the first element of subarray
     * \param end number of the last element of subarray
     * \return unsigned long int value of the subarray
     */
    unsigned long int valueOfGroupOfFields(const int & length, const unsigned long int& offset = 0);
    /*!
     * \brief bitValue
     * \param byteId id of byte in the array
     * \param bitId id of bit in the given byte
     * \return value of given bit
     */
    bool bitValue(int byteId, int bitId);
    /*!
     * \brief valueOfBits
     * \param begin number of the first element of subarray
     * \param end number of the last element of subarray
     * \param pattern unsigned long int value of the subarray
     * \return
     */
    //unsigned long int valueOfBits(const int& begin, const int& end);
    /*!
     * \brief toQString
     *  converts unsigned int to QString
     * \param num value to be converted
     * \param bytes number of bytes the unsigned int has been created from
     * \return converted QString object
     */
    QString toQString(unsigned int num,int bytes);
    /*!
     * \brief set
     * private method is called inside setData method. It adds children to the parent.
     * \param arr QByteArray of analyzed bytes
     * \param parent parent of the tree fragment that children are to be analyzed.
     * \param off offset
     */
private:
    void setData(TreeItem* &parent, QHash<long,TreeItem*>* items, const unsigned long int &off, unsigned long int maxOff = 0L);
    /*!
     * \brief fileName
     *  name of the analyzed file
     */
    QString fileName;
    /*!
     * \brief tempArray
     */
    QByteArray tempArray;
    QFile* file;
    /*!
     * \brief arraySize
     */
    unsigned long int fileSize;
    unsigned long int maxTempOff; //rozmiar tymczasowo analizowanego boxu
    QByteArray smiec;
public:
    QByteArray getTempArray() {
        return tempArray;
    }

};


#endif // ANALYZER_H
