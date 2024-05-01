#include "Client.h"


Client::Client()
{

}


void Client::connectToServer()
{
    emit askWifiList();
}


void Client::receiveMsgFromServer(Wifi msg)
{
    auto pWifi = std::find_if(wifiList.begin(), wifiList.end(), [&](Wifi wifi){return wifi.id == msg.id;});

    if (pWifi == wifiList.end())
    {
        // New wifi
        wifiList.push_back(msg);
    }
    else
    {
        // Old wifi
        pWifi->status = msg.status;
    }

    emit changeWifiList();

    debug();
}


QStringList Client::readWifiIds() const
{
    QStringList tempList;

    for (const auto &wifi : wifiList)
    {
        tempList.push_back(wifi.id);
    }

    return tempList;
}


int Client::n() const
{
    return 1234;
}


void Client::debug()
{
    for (const auto &wifi : wifiList)
    {
        std::cout << "id: "     << wifi.id.toStdString()   << std::endl
                  << "auth: "   << wifi.auth.toStdString() << std::endl
                  << "status: " << (int)wifi.status        << std::endl;
        std::cout << std::endl;
    }
}
