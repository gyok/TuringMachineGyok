#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    myGUI = new programInterface();
    createMenus();

    ui->graphicLayout->addWidget(myGUI);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::createMenus(){
    QMenu* mnFile = new QMenu("File");
    QAction *openFileAction = new QAction("Open File", mnFile);
    QAction *exitAction = new QAction("Exit", mnFile);
    connect(openFileAction, SIGNAL(triggered(bool)), this, SLOT(ShowMessage()));
    connect(exitAction, SIGNAL(triggered(bool)), this, SLOT(ExitTuringMachine()));
    mnFile->addAction(openFileAction);
    mnFile->addAction(exitAction);

    ui->menuBar->addMenu(mnFile);


    return 0;
}

void MainWindow::ShowMessage(){
    qDebug()<<"menu Clicked";
}

void MainWindow::ExitTuringMachine(){
    this->close();
}
