#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QMenu>
#include <QTreeView>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QApplication>
#include <QDesktopWidget>
#include <QMenuBar>
#include <QFileDialog>
#include "treemodel.h"
#include "treeitem.h"
#include <QStringList>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QTextEdit>
#include <qDebug>
#include <QMessageBox>


/*!
 * \brief The MainWindow class defines a mind window of the application
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //!Constructor
    /*!
     * \param parent
     */
    explicit MainWindow(QWidget *parent = 0);
    //!Destructor
    ~MainWindow();
    void printResolution();
    /*void resizeEvent ( QResizeEvent * event )
        {
          QMessageBox* msg = new QMessageBox(this);
          msg->setText("Mainwindow has been resized!");
          msg->show();
        };*/


private slots:
    /*!
     * \brief openFile opens QFileDialog to choose file that is to analyzed
     */
    void openFile();

private:
    /*!
     * \brief createActions create actions and adds slots to the widgets
     */
    void createActions();
    /*!
     * \brief createMenu creates menu
     */
    void createMenu();
    /*!
     * \brief fileMenu
     */
    QMenu *fileMenu;
    /*!
     * \brief treeView
     */
    QTreeView *treeView;
    /*!
     * \brief openAct
     */
    QAction *openAct;
    /*!
     * \brief exitAct
     */
    QAction *exitAct;
    /*!
     * \brief model
     */
    TreeModel *model;
    /*!
     * \brief title
     */
    QString title;

    QHBoxLayout * layout;
    QTextEdit * edit;

};



#endif // MAINWINDOW_H
