#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


#include "wifi_manager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void Timer_Wifi_Scan_Function();

private:
    Ui::MainWindow *ui;

    Wifi_Manager *Wifi_Mgr;
    QTimer *Timer_Wifi_Scan;

};

#endif // MAINWINDOW_H
