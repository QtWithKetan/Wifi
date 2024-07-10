#include "wifi_manager.h"

Wifi_Manager::Wifi_Manager()
{

}

void Wifi_Manager::Scan_Wifi_NetWorks()
{
    QProcess Process;
    Process.start("netsh",QStringList() << "wlan" << "show" << "network"); // This windows command return all Available Wifi Networks
    Process.waitForFinished();

    QByteArray RawData = Process.readAllStandardOutput(); // Data With All Information Like SSID , Network type and etc..
    QString Data(RawData);

    // Now Let's Extract SSID Names From this Data
    Available_Wifi_NetWorks.clear();
    QStringList DataLines = Data.split('\n');
    for (const QString& line : DataLines)
    {
        if (line.trimmed().startsWith("SSID"))
        {
            QString SSID = line.section(':',1).trimmed();
            if (SSID.isEmpty() == false)
            {
                Available_Wifi_NetWorks.append(SSID);
            }
        }
    }
}

QStringList Wifi_Manager::Get_Available_Wifi_NetWorks()
{
    return Available_Wifi_NetWorks;
}
