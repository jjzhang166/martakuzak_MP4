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
    const int m_width = QApplication::desktop()->width();
    const int m_height = QApplication::desktop()->height();
    resize(0.9*m_width, 0.8*m_height);
    layout = new QHBoxLayout();
    QWidget *window = new QWidget();
    setCentralWidget(window);
    window->setLayout(layout);
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
    /*QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open File"), "/", tr("MP4 Files (*.mp4)"));*/
    QString fileName("F:/Uczelnia/Samples/Euro 2012.mp4" );
    model= new TreeModel(fileName);
    treeView = new QTreeView(this);
    treeView->setModel(model);
    layout->addWidget(treeView);


    QTextEdit * edit = new QTextEdit();
    edit->setReadOnly(true);
    edit->setFixedSize((centralWidget()->geometry().width()/5)*2,centralWidget()->geometry().height());
    layout->addWidget(edit);
    edit->setText("TEST");


    setWindowTitle(title+fileName);
    printResolution();
}

void MainWindow::printResolution() {
    TreeItem *moov= model->getChild(model->getRootItem(), QString("moov"));
    TreeItem *trak= model->getChild(moov, QString("trak"));
    TreeItem *mdia= model->getChild(trak, QString("mdia"));
    TreeItem *minf= model->getChild(mdia, QString("minf"));
    TreeItem *stbl= model->getChild(minf, QString("stbl"));
    TreeItem *stsd= model->getChild(stbl, QString("stsd"));
    TreeItem *itemWl= stsd->child(0);
}

