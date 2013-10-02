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
/*!
 * \brief The Analyzer class - provides with tools to analyze MP4 file.
 */
class Analyzer
{
public:
    /*!
     * \brief Analyzer - constructor
     * \param fileName name of the file to be analyzed
     */
    Analyzer(const QString& fileName);
    /*!
     * \brief getData
     * \return QString object that contains data for the treeView.
     */
    //QString getData();
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
    unsigned long int valueOfGroupOfFields(int begin, int end, QByteArray array= QByteArray());
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
    void setData(QByteArray arr, TreeItem* &parent, QHash<long,TreeItem*>* items, long off=0);
    /*!
     * \brief fileName
     *  name of the analyzed file
     */
    QString fileName;
    /*!
     * \brief list
     * QString that contains data formatted in a way suitable for treemodel
     */
    QString list;
    /*!
     * \brief tempArray
     */
    QByteArray tempArray;
    /*!
     * \brief arraySize
     */
    int arraySize;
};


#endif // ANALYZER_H
