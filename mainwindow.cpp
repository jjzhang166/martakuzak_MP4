#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    createActions();
    createMenu();

    title = QString("MP4 ");
    setWindowTitle(title);

    setMinimumSize(160, 160);
    const int m_width = QApplication::desktop()->width();
    const int m_height = QApplication::desktop()->height();
    resize(0.8*m_width, 0.5*m_height);

    mainLayout = new QVBoxLayout();
    boxInfoLayout = new QHBoxLayout();
    searchBoxLayout = new QGridLayout();

    QWidget *window = new QWidget();
    //setWindowIcon(QIcon("icon2.png"));
    setCentralWidget(window);

    window->setLayout(mainLayout);
}
////////////////////////////////////////////////////////////////////////////////////////////
MainWindow::~MainWindow()
{
    delete fileMenu;
    delete treeView;
    delete openAct;
    delete exitAct;
    delete model;
    delete boxInfo;
    delete nextSearchButton;
    delete typeBoxType;
    delete searchLabel;
    delete searchBoxGroup;
    delete boxInfoGroupBox;
    delete hSplitter;
    delete vSplitter;
    delete mainLayout;
    delete boxInfoLayout;
    delete searchBoxLayout;
}
////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::createActions()
{
    openAct = new QAction(tr("&Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    connect(openAct, SIGNAL(triggered()), this, SLOT(openFile()));

    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

    searchBoxAct = new QAction(tr("&Search"), this);
    connect(searchBoxAct, SIGNAL(triggered()), this, SLOT(searchBox()));
}
////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::createMenu()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

}
////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::setSearchBoxSection() {

    searchBoxGroup = new QGroupBox();

    searchLabel = new QLabel("Type box type: ");
    searchLabel->setMaximumSize(200,40);

    typeBoxType = new QLineEdit();
    typeBoxType->setMaximumWidth(50);
    typeBoxType->setMaxLength(4);

    nextSearchButton = new QPushButton("Find");
    nextSearchButton->addAction(searchBoxAct);
    connect(nextSearchButton,
            SIGNAL(clicked()),
            this, SLOT(searchBox()));

    searchBoxGroup->setMaximumHeight(50);
    searchBoxGroup->setMinimumHeight(40);

    searchBoxLayout->addWidget(searchLabel, 1, 0);
    searchBoxLayout->addWidget(typeBoxType, 1, 1);
    searchBoxLayout->addWidget(nextSearchButton, 1, 2);
    searchBoxLayout->setColumnStretch(10, 1);
    searchBoxGroup->setLayout(searchBoxLayout);

    vSplitter = new QSplitter();
    vSplitter->addWidget(searchBoxGroup);
    mainLayout->addWidget(vSplitter);

}
////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::setBoxInfoSection(const QString& fileName) {


    if(!boxInfoLayout->count()) {
        boxInfoGroupBox = new QGroupBox(tr(""));
        treeView = new QTreeView(this);
        boxInfo = new QTextEdit();
        boxInfo->setReadOnly(true);
        hSplitter = new QSplitter();
    }


    model= new TreeModel(fileName);

    treeView->setModel(model);
    treeView->header()->setStretchLastSection(false);
    treeView->header()->setSectionResizeMode(0, QHeaderView::Stretch);
    treeView->setSizePolicy(QSizePolicy::Expanding,
                            QSizePolicy::Expanding);
    connect(treeView->selectionModel(),
            SIGNAL(selectionChanged(const QItemSelection &,
                                    const QItemSelection &)),
            this, SLOT(printSelectedBox()));

    boxInfo->setSizePolicy(QSizePolicy::Expanding,
                           QSizePolicy::Expanding);
    boxInfo->setText("");

    hSplitter->addWidget(treeView);
    hSplitter->addWidget(boxInfo);
    hSplitter->setOrientation(Qt::Horizontal);
    boxInfoLayout->addWidget(hSplitter);

    boxInfoGroupBox->setLayout(boxInfoLayout);
    boxInfoGroupBox->setSizePolicy(QSizePolicy::Expanding,
                                   QSizePolicy::Expanding);

    vSplitter->addWidget(boxInfoGroupBox);
    vSplitter->setOrientation(Qt::Vertical);

    mainLayout->update();
    setWindowTitle(title+fileName);
}

////////////////////////////////////////////////////////////////////////////////////////////
///Slots
////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::openFile()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::AnyFile);
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open File"), "/", tr("MP4 Files (*.mp4)"));
    if(fileName.length()) {
        if(!searchBoxLayout->count())
            setSearchBoxSection();
        setBoxInfoSection(fileName);
    }
}
////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::printSelectedBox() {
    QModelIndex index = treeView->selectionModel()->currentIndex();
    QModelIndex child = model->index(index.row(), 2, index.parent());
    QString text= model->getChild(model->data(child,
                                              Qt::DisplayRole).toInt())->fullName();
    if(text!=NULL)
        boxInfo->setText(text+"\n"+model->getChild(model->data(child,Qt::DisplayRole).toInt())->getInfo());
}
////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::searchBox() {
    QString boxType = typeBoxType->text();
    //if boxType hasn't 4 characters
    if(boxType.size()!=4) {
        QMessageBox *infoBox = new QMessageBox(this);
        infoBox->setIcon(QMessageBox::Warning);
        infoBox->setText("Box type should have 4 characters.");
        infoBox->show();
        boxInfo->clear();
        return;
    }
    //otherwise application looks for boxes
    QModelIndex index = treeView->selectionModel()->currentIndex();
    int row;
    int col;
    if(index.isValid()) {
        row = index.row();
        col = index.column();
    }
    else { //no selection
        row = 0;
        col = 0;
    }
    QModelIndexList Items = model->match(model->index(row,col),
                                         Qt::DisplayRole,
                                         QVariant::fromValue(QString(boxType)),
                                         -1,
                                         Qt::MatchRecursive);
    treeView->clearSelection();
    //no box found
    if(Items.size()==0) {
        treeView->clearSelection();
        QMessageBox *infoBox = new QMessageBox(this);
        infoBox->setIcon(QMessageBox::Warning);
        infoBox->setText("No box found");
        infoBox->show();
        treeView->clearSelection();
        boxInfo->clear();
        return;

    }
    //selects found boxes and expands their predecessors
    while (!Items.isEmpty()) {
        QModelIndex backId = Items.back();
        QModelIndex tmpId = backId;
        QModelIndex tmpParent = tmpId.parent();
        while(tmpParent.isValid()) {
            treeView->setExpanded(tmpParent, true);
            tmpParent = tmpParent.parent();
        }
        treeView->selectionModel()->select(backId, QItemSelectionModel::Select | QItemSelectionModel::Rows);
        Items.pop_back();
        boxInfo->clear();
    }
    mainLayout->update();

}


