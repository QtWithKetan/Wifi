#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H

#include <QtNetwork>
#include <QtCore>
#include <QtGui>
#include <QtWidgets>

class Wifi_Manager
{
public:
    Wifi_Manager();

public:
    void Scan_Wifi_NetWorks();

    QStringList Get_Available_Wifi_NetWorks();
private:
    QStringList Available_Wifi_NetWorks;
};

#endif // WIFI_MANAGER_H
