#include <QDebug>
#include <QFile>
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "Server.h"


Server::Server()
{
    wifiList = getWifiListFromJson(":/json/input.json");
}


//std::vector<Wifi> Server::getFromJson(QString filename)
//{
//    decltype(wifiList) temp;
//
//    temp.push_back(Wifi{.id = "wifi1", .auth = "123", .status=Wifi::INIT});
//    temp.push_back(Wifi{.id = "wifi2", .auth = "456", .status=Wifi::INIT});
//
//    return temp;
//}



std::vector<Wifi> Server::getWifiListFromJson(QString filename)
{
    std::vector<Wifi> tempList;

    QFile file(filename);  // File exists

    file.open(QIODevice::ReadOnly);//QIODevice::ReadOnly | QIODevice::Text);  // File opened

    QString jsonData = file.readAll();

    qDebug() << jsonData.toUtf8();

    file.close();

    QJsonDocument document = QJsonDocument::fromJson(jsonData.toUtf8());

    QJsonObject object = document.object();

    QJsonValue value = object.value("wifi_params");

    QJsonArray array = value.toArray();

    for (const QJsonValue &val : array)
    {
        Wifi wifi = {.id = val.toObject().value("id").toString(),
                     .auth = val.toObject().value("auth").toString(),
                     .status = Wifi::INIT};

        tempList.push_back(wifi);
    }

    return tempList;
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
