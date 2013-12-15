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
                             ////////////////////////////////////////////////////////////////////////////////////////////
                             //unsigned long int TreeModel::mdatSize(const unsigned long int& firstSample, const unsigned int& sampleNumber, std::shared_ptr<Box>& stsz,
                             //                           Analyzer* an) {
                             //    return an->mdatSize(firstSample, sampleNumber, stsz);
                             //}
                             //////////////////////////////////////////////////////////////////////////////////////////////
                             //unsigned int TreeModel::writeMdat(const unsigned long int& firstSample, const unsigned int& sampleNumber, std::shared_ptr<Box>& stsz, QFile* dashFile,
                             //               Analyzer* an) {
                             //    return an->writeMdat(firstSample, sampleNumber, stsz, dashFile);
                             //}
                             //////////////////////////////////////////////////////////////////////////////////////////////
                             //unsigned int TreeModel::writeMoof(const unsigned long int& sequenceNumber, const unsigned int& trackID,
                             //                                  const unsigned long &baseMediaDecodeTime, const unsigned int& trunFlag2, const unsigned int& trunFlag3,
                             //                                  const unsigned int& sampleCount, const signed int& dataOffset, const unsigned int& firstSampleFlags,
                             //                                  const unsigned long int& firstSample, std::shared_ptr<Box>& stsz,
                             //                                  QFile* dashFile, Analyzer* an) {
                             //    return an->writeMoof(sequenceNumber, trackID, baseMediaDecodeTime, trunFlag2, trunFlag3, sampleCount, dataOffset, firstSampleFlags,
                             //                         firstSample, stsz, dashFile);
                             //}
                             //////////////////////////////////////////////////////////////////////////////////////////////
                             //unsigned int TreeModel::writeMfhd(const unsigned long int& sn, QFile* dashFile, Analyzer* an) {
                             //    return an->writeMfhd(sn, dashFile);
                             //}
                             //////////////////////////////////////////////////////////////////////////////////////////////
                             //unsigned int TreeModel::writeTfhd(const unsigned int& tid, QFile* dashFile, Analyzer* an) {
                             //    return an->writeTfhd(tid, dashFile);
                             //}
                             //////////////////////////////////////////////////////////////////////////////////////////////
                             //unsigned int TreeModel::writeTfdt(const unsigned long &baseMediaDecodeTime, QFile* dashFile, Analyzer* an) {
                             //    return an->writeTfdt(baseMediaDecodeTime, dashFile);
                             //}
                             //////////////////////////////////////////////////////////////////////////////////////////////
                             //unsigned int TreeModel::writeTrun(const unsigned int& flag2, const unsigned int& flag3, const unsigned int& sampleCount,
                             //                       const signed int& dataOffset, const unsigned int& firstSampleFlags, const unsigned long int& firstSample,
                             //                       std::shared_ptr<Box>& stsz, QFile* dashFile, Analyzer* an) {
                             //    return an->writeTrun(flag2, flag3, sampleCount, dataOffset, firstSampleFlags, firstSample, stsz, dashFile);
                             //}
                             //////////////////////////////////////////////////////////////////////////////////////////////
                             //unsigned int TreeModel::writeTraf(const unsigned int& trackID, const unsigned long &baseMediaDecodeTime, const unsigned int& trunFlag2,
                             //                       const unsigned int& trunFlag3, const unsigned int& sampleCount, const signed int& dataOffset,
                             //                       const unsigned int& firstSampleFlags, const unsigned long int& firstSample,
                             //                       std::shared_ptr<Box>& stsz, QFile* dashFile, Analyzer *an) {
                             //    return an->writeTraf(trackID, baseMediaDecodeTime, trunFlag2, trunFlag3, sampleCount, dataOffset, firstSampleFlags, firstSample,
                             //                         stsz, dashFile);
                             //}

                             /*void TreeModel::setupModelData(const QStringList &lines, TreeItem *parent)
                             {
                                 QList<TreeItem*> parents;
                                 QList<int> indentations;
                                 parents << parent;
                                 indentations << 0;
                                 int number = 0;

                                 while (number < lines.count()) {
                                     int position = 0;
                                     while (position < lines[number].length()) {
                                         if (lines[number].mid(position, 1) != " ")
                                             break;
                                         position++;
                                     }
                                     QString lineData = lines[number].mid(position).trimmed();
                                     if (!lineData.isEmpty()) {
                                         // Read the column data from the rest of the line.
                                         QStringList columnStrings = lineData.split("\t", QString::SkipEmptyParts);
                                         QList<QVariant> columnData;
                                         for (int column = 0; column < columnStrings.count(); ++column)
                                             columnData << columnStrings[column];

                                         if (position > indentations.last()) {
                                             // The last child of the current parent is now the new parent
                                             // unless the current parent has no children.

                                             if (parents.last()->childCount() > 0) {
                                                 parents << parents.last()->child(parents.last()->childCount()-1);
                                                 indentations << position;
                                             }
                                         } else {
                                             while (position < indentations.last() && parents.count() > 0) {
                                                 parents.pop_back();
                                                 indentations.pop_back();
                                             }
                                         }

                                         // Append a new item to the current parent's list of children.
                                         parents.last()->appendChild(new TreeItem(columnData, parents.last()));
                                     }

                                     ++number;
                                 }
                             }
                             */
