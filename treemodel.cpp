#include "treemodel.h"

TreeModel::TreeModel(Analyzer *analyzer, QObject *parent)
    : QAbstractItemModel(parent) {
    QList<QVariant> rootData;
    rootData << "Name" << "Size"<<"Offset";
    rootItem = new TreeItem(analyzer,rootData);
    treeItems= new QHash<long,TreeItem*>();
    analyzer->setData(rootItem, treeItems);
}
////////////////////////////////////////////////////////////////////////////////////////////

TreeModel::~TreeModel() {
    treeItems->clear();
    delete treeItems;
    delete rootItem;
}
////////////////////////////////////////////////////////////////////////////////////////////
int TreeModel::columnCount(const QModelIndex &parent) const {
    if (parent.isValid())
        return static_cast<TreeItem*>(parent.internalPointer())->columnCount();
    else
        return rootItem->columnCount();
}
////////////////////////////////////////////////////////////////////////////////////////////
QVariant TreeModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid())
        return QVariant();

    if (role != Qt::DisplayRole)
        return QVariant();

    TreeItem *item = static_cast<TreeItem*>(index.internalPointer());

    return item->data(index.column());
}
////////////////////////////////////////////////////////////////////////////////////////////
Qt::ItemFlags TreeModel::flags(const QModelIndex &index) const {
    if (!index.isValid())
        return 0;

    return QAbstractItemModel::flags(index);
}
////////////////////////////////////////////////////////////////////////////////////////////
QVariant TreeModel::headerData(int section, Qt::Orientation orientation,
                               int role) const {
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return rootItem->data(section);

    return QVariant();
}
////////////////////////////////////////////////////////////////////////////////////////////
QModelIndex TreeModel::index(int row, int column, const QModelIndex &parent) const {
    if (!hasIndex(row, column, parent))
        return QModelIndex();

    TreeItem *parentItem;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<TreeItem*>(parent.internalPointer());

    TreeItem *childItem = parentItem->child(row);
    if (childItem)
        return createIndex(row, column, childItem);
    else
        return QModelIndex();
}
////////////////////////////////////////////////////////////////////////////////////////////

QModelIndex TreeModel::parent(const QModelIndex &index) const {
    if (!index.isValid())
        return QModelIndex();

    TreeItem *childItem = static_cast<TreeItem*>(index.internalPointer());
    TreeItem *parentItem = childItem->parent();

    if (parentItem == rootItem)
        return QModelIndex();

    return createIndex(parentItem->row(), 0, parentItem);
}
////////////////////////////////////////////////////////////////////////////////////////////
int TreeModel::rowCount(const QModelIndex &parent) const {
    TreeItem *parentItem;
    if (parent.column() > 0)
        return 0;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<TreeItem*>(parent.internalPointer());

    return parentItem->childCount();
}
////////////////////////////////////////////////////////////////////////////////////////////
TreeItem* TreeModel:: getChild(TreeItem *parent, QString type) {
    int number= parent->childCount();
    for(int i=0; i<number; i++) {
        if(parent->child(i)->getType()==type) {
            return parent->child(i);
        }
    }
    return NULL;
}
////////////////////////////////////////////////////////////////////////////////////////////
TreeItem * TreeModel::getChild(int offset) {
    try {
        return treeItems->value(offset);
    }
    catch(QException) {
        return NULL;
    }
}
////////////////////////////////////////////////////////////////////////////////////////////
QList <std::shared_ptr<Box>> TreeModel::getBoxes(const QString& type) {
                             QList <std::shared_ptr<Box>> boxes;
                             int row = 0;
                             int col = 0;
                             QModelIndexList Items = match(index(row,col),
                                                           Qt::DisplayRole,
                                                           QVariant::fromValue(QString(type)),
                                                           -1,
                                                           Qt::MatchRecursive);
                             while (!Items.isEmpty()) {
                                QModelIndex backId = Items.back();
                                QModelIndex child = index(backId.row(), 2, (backId.parent()));
                                boxes.append(getChild(data(child,Qt::DisplayRole).toInt())->getBox());
                                Items.pop_back();
                             }
                             return boxes;
                             }
