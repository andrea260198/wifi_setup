#include "Server.h"


Server::Server()
{
    wifiList = getFromJson("input.json");
}


std::vector<Wifi> Server::getFromJson(QString filename)
{
    // TODO
    decltype(wifiList) temp;

    temp.push_back(Wifi{.id = "wifi1", .auth = "123", .status=Wifi::INIT});
    temp.push_back(Wifi{.id = "wifi2", .auth = "456", .status=Wifi::INIT});

    return temp;
}


void Server::receiveMsgFromClient(Wifi msg)
{
    auto pWifi = std::find_if(wifiList.begin(), wifiList.end(), [&](Wifi wifi){return wifi.id == msg.id;});

    if (pWifi != wifiList.end())
    {
        if (pWifi->auth == msg.auth)
        {
            pWifi->status = Wifi::CONN_SUCC;

            Wifi answer = msg;
            answer.id = msg.id;
            answer.status = Wifi::CONN_SUCC;

            emit sendMsgToClient(answer);
        }
        else
        {
            pWifi->status = Wifi::CONN_FAIL;

            Wifi answer = msg;
            answer.id = msg.id;
            answer.status = Wifi::CONN_FAIL;

            emit sendMsgToClient(answer);
        }
    }
}


void Server::sendWifiList()
{
    for (const auto &wifi : wifiList)
	{
        Wifi msg;
        msg.id = wifi.id;
        msg.status = wifi.status;
        emit sendMsgToClient(msg);
	}
}
