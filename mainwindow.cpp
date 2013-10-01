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
    resize(0.8*m_width, 0.5*m_height);
    mainLayout = new QVBoxLayout();
    boxInfoLayout = new QHBoxLayout();
    searchBoxLayout = new QGridLayout();
    QWidget *window = new QWidget();
    //window->setStyleSheet(" background-image: url(./icon.png);background-repeat: no-repeat;");
    setWindowIcon(QIcon("icon2.png"));
    //setPalette( QPalette( Qt::green));
    //setStyleSheet("MainWindow {background-color: rgb(209,231,219); }");
    //setStyleSheet("MainWindow {background-color: rgb(208,218,230); }");
    setCentralWidget(window);
    window->setLayout(mainLayout);
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

    tmp= new QAction(tr("&TMP"),this);

    //connect(tmp, SIGNAL(QItemSelectionModel::selectionChanged(const QItemSelection & selected, const QItemSelection & deselected) ),this, SLOT(printResolution()));
    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));
    searchBoxAct = new QAction(tr("OK"), this);
}

void MainWindow::createMenu()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openAct);
    //fileMenu->addAction(tmp);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

}
void MainWindow::openFile()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::AnyFile);
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open File"), "/", tr("MP4 Files (*.mp4)"));
    //QString fileName("F:/Uczelnia/Samples/Euro 2012.mp4" );
    if(fileName.length()) {
        if(!searchBoxLayout->count()) {

            searchBoxGroup = new QGroupBox();

            searchLabel = new QLabel("Find box: ");
            searchLabel->setMaximumSize(200,40);
            lineEdit = new QLineEdit();
            lineEdit->setMaximumWidth(50);
            lineEdit->setMaxLength(4);
            nextSearchButton = new QPushButton("Next");
            nextSearchButton->addAction(searchBoxAct);
            connect(nextSearchButton,
                    SIGNAL(clicked()),
                    this, SLOT(searchBox()));
            searchBoxLayout->addWidget(searchLabel, 1, 0);
            searchBoxLayout->addWidget(lineEdit, 1, 1);
            searchBoxLayout->addWidget(nextSearchButton, 1, 2);
            searchBoxGroup->setLayout(searchBoxLayout);
            searchBoxLayout->setColumnStretch(10, 1);
            vSplitter = new QSplitter();
            vSplitter->addWidget(searchBoxGroup);
            mainLayout->addWidget(vSplitter);

        }

        if(!boxInfoLayout->count()) {
            boxInfoGroupBox = new QGroupBox(tr(""));
            treeView = new QTreeView(this);
            boxInfo = new QTextEdit();
            boxInfo->setReadOnly(true);
            hSplitter = new QSplitter();
           // boxInfo->setFixedSize((centralWidget()->geometry().width()/5)*2,centralWidget()->geometry().height());
        }


        model= new TreeModel(fileName);

        treeView->setModel(model);
        //treeView->expandAll();
        treeView->setSizePolicy(QSizePolicy::Expanding,
                                QSizePolicy::Expanding);
        boxInfo->setSizePolicy(QSizePolicy::Expanding,
                               QSizePolicy::Expanding);
        boxInfo->setText("");
        hSplitter->addWidget(treeView);
        hSplitter->addWidget(boxInfo);
        boxInfoLayout->addWidget(hSplitter);

        boxInfoGroupBox->setLayout(boxInfoLayout);
        boxInfoGroupBox->setSizePolicy(QSizePolicy::Expanding,
                                       QSizePolicy::Expanding);

        vSplitter->addWidget(boxInfoGroupBox);

        connect(treeView->selectionModel(),
                SIGNAL(selectionChanged(const QItemSelection &,
                                        const QItemSelection &)),
                this, SLOT(printSelectedBox()));
        vSplitter->setOrientation(Qt::Vertical);
        hSplitter->setOrientation(Qt::Horizontal);
        mainLayout->update();
        setWindowTitle(title+fileName);
    }
}

void MainWindow::printSelectedBox() {
    QModelIndex index = treeView->selectionModel()->currentIndex();
    //treeView->setCurrentIndex(treeView->topLe);
    QModelIndex child = model->index(index.row(), 2, index.parent());
    QString text= model->getChild(model->data(child,
                                              Qt::DisplayRole).toInt())->fullName();
    if(text!=NULL)
        boxInfo->setFont(QFont( "Calibri", 13 ) );
        //edit->setStyleSheet("h1{font-size: 1px; color: rgb(209,205,121); } h2{font-size: 14px color: rgb(149,25,121); }");
        //edit->setHtml("<body><font color=\"DeepPink\">"+text+"</font></body>");
        //edit->setText("<h1> "+text+"</h1> <h2> Aaaa </h2>");
        //edit->setText("<head><title>Moja pierwsza strona ze stylami</title><style type=\"text/css\">body {color: purple;background-color: #d8da3d }</style> </head><body>"+text+"</body>");
        boxInfo->setText(text+"\n"+model->getChild(model->data(child,Qt::DisplayRole).toInt())->getInfo());
}

void MainWindow::searchBox() {
    QString boxType = lineEdit->text();
    QModelIndex index = treeView->selectionModel()->currentIndex();
    int row;
    int col;
    if(index.isValid()) {
        row = index.row();
        col = index.column();
    }
    else {
        row = 0;
        col = 0;
    }
    QModelIndexList Items = model->match(model->index(row,col),
                                         Qt::DisplayRole,
                                         QVariant::fromValue(QString(boxType)),
                                         -1,
                                         Qt::MatchRecursive);

    treeView->clearSelection();
    if(Items.size()==0) {
        treeView->clearSelection();
        QMessageBox *infoBox = new QMessageBox(this);
        infoBox->setIcon(QMessageBox::Warning);
        infoBox->setText("No box found");
        infoBox->show();
        return;

    }
    while (!Items.isEmpty()) {
        //treeView->setExpanded(Items.back(), true);
        QModelIndex backId = Items.back();
        treeView->selectionModel()->select(backId, QItemSelectionModel::Select | QItemSelectionModel::Rows);
        boxInfo->clear();
        mainLayout->update();
        Items.pop_back();
    }

    //model->getChild(boxType);
    //QModelIndex index = treewView->selectionModel()->
    //treeView->setExpanded(QModelIndex(5), true);
    //idx = treeview->model()->index(0);
    //selection->select(idx, QItemSelectionModel::Select | QItemSelectionModel::Rows);
    //QModelIndex child = model->index(id.row(), 1, id.parent());
    //QString text= model->getChild(model->data(child,Qt::DisplayRole).toInt())->fullName();
    //qDebug()<<text;
}
