#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Wifi_Mgr = new Wifi_Manager();

    Timer_Wifi_Scan = new QTimer();
    connect(Timer_Wifi_Scan,SIGNAL(timeout()),this,SLOT(Timer_Wifi_Scan_Function()));
    Timer_Wifi_Scan->setInterval(1000); // 1 Second Inteval
    Timer_Wifi_Scan->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Timer_Wifi_Scan_Function()
{
    Wifi_Mgr->Scan_Wifi_NetWorks();
    QStringList WifiList = Wifi_Mgr->Get_Available_Wifi_NetWorks();
    ui->listWidget_Wifi_List->clear();
    ui->listWidget_Wifi_List->addItems(WifiList);
}
