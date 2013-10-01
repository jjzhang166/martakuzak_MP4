#ifndef TREEITEM_H
#define TREEITEM_H

#include <QList>
#include <QVariant>
#include <QStringList>
#include <QByteArray>
#include <iostream>
#include "box.h"
#include "boxfactory.h"
#include "exceptions.h"
//#include "analyzer.h"

class Analyzer;
/*!
 * \brief The TreeItem class represent single element of the tree model
 */
class TreeItem
{
public:
    /*!
     * \brief TreeItem
     *  constructor
     * \param data data of the parent item
     * \param parent parent of the item
     * \param off offset
     */
    explicit TreeItem(Analyzer *an,const QList<QVariant> &data, TreeItem *parent = 0, int off=0);
    //!Destructor
    ~TreeItem();
    /*!
     * \brief appendChild appends child item to the parent
     * \param child pointer to the child that is to be appended
     */
    void appendChild(TreeItem *child);
    /*!
     * \brief child
     * \param row
     * \return child from given row
     */
    TreeItem *child(int row);
    /*!
     * \brief childCount
     * \return number of children of the item
     */
    int childCount() const;
    /*!
     * \brief columnCount
     * \return number of columns
     */
    int columnCount() const;
    /*!
     * \brief data
     * \param column
     * \return data from given column
     */
    QVariant data(int column) const;
    /*!
     * \brief row
     * \return number of rows
     */
    int row() const;
    /*!
     * \brief parent
     * \return parent of the item
     */
    TreeItem *parent();
    /*!
     * \brief isContainer Tests if represented box is container
     * \return If box is container.
     */
    bool isContainer() {
        if(box) return box->isContainer();
        else return false;
    }
    /*!
     * \brief getOffset
     * \return
     */
    int unsigned getOffset() {
        if(box) return box->getOffset();
        else return 8;
    }
    /*!
     * \brief isNull
     * \return
     */
    bool isNull() {
        if(box) return false;
        else return true;
    }
    QString getType() {
        return box->getType();

    }
    QString fullName() {
        return box->getFullName();
    }
    QString getInfo() {
        return box->getInfo();
    }


private:
    /*!
     * \brief childItems children of the item
     */
    QList<TreeItem*> childItems;
    /*!
     * \brief itemData data of the item
     */
    QList<QVariant> itemData;
    /*!
     * \brief parentItem parent of the item
     */
    TreeItem *parentItem;
    /*!
     * \brief box corresponding box
     */
    std::shared_ptr<Box> box;
};

#endif // TREEITEM_H
