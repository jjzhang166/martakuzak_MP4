#include "mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    createActions();
    createMenu();
    title=QString("MP4 ");
    setWindowTitle(title);
    setMinimumSize(160, 160);
    const int width = QApplication::desktop()->width();
    const int height = QApplication::desktop()->height();
    resize(0.9*width, 0.8*height);
}

MainWindow::~MainWindow()
{
    delete fileMenu;
    delete treeView;
    delete openAct;
    delete exitAct;
    delete model;
}

void MainWindow::createActions()
{

    openAct = new QAction(tr("&Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    connect(openAct, SIGNAL(triggered()), this, SLOT(openFile()));

    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));
}

void MainWindow::createMenu()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

}
void MainWindow::openFile()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::AnyFile);
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open File"), "/", tr("MP4 Files (*.mp4)"));
    model= new TreeModel(fileName);
    treeView = new QTreeView(this);
    setCentralWidget(treeView);
    treeView->setModel(model);
    setWindowTitle(title+fileName);
    printResolution();
}

void MainWindow::printResolution() {
    int number=model->getRootItem()->childCount();
    for(int i=0; i<number; i++) {
        if(model->getRootItem()->child(i)->getType()=="moov") {
            TreeItem *item= model->getRootItem()->child(i);
            int num=item->childCount();
            for(int k=0; k<num; k++) {
                if(item->child(k)->getType()=="trak") {
                    TreeItem *item1= item->child(k);
                    int num1=item->childCount();
                    for(int l=0; l<num; l++) {
                        if(item->child(l)->getType()=="mdia") {
                            TreeItem *item2= item->child(l);
                            int num2=item2->childCount();
                            for(int m=0; m<num2; m++) {
                                if(item->child(m)->getType()=="minf") {
                                    TreeItem *item3= item->child(m);
                                    int num3=item3->childCount();
                                    for(int n=0; n<num3; n++) {
                                        if(item->child(n)->getType()=="stbl") {
                                            TreeItem *item4= item->child(n);
                                            int num4=item4->childCount();
                                            for(int p=0; p<num4; p++) {
                                                if(item->child(p)->getType()=="stsd") {
                                                    TreeItem *item5= item->child(p);
                                                    int num5=item5->childCount();
                                                    TreeItem *itemWl= item5->child(0);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

