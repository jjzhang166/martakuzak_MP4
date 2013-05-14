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

}
