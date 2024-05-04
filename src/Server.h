#pragma once

#include <QObject>
#include <QMap>
#include <vector>
#include <algorithm>
#include "Wifi.h"


class Server : public QObject
{
	Q_OBJECT

public:
    Server();

    std::vector<Wifi> getWifiListFromJson(QString filename);
	
public:
    Q_SLOT void receiveMsgFromClient(Wifi msg);
    Q_SLOT void sendWifiList();
    Q_SIGNAL void sendMsgToClient(Wifi msg);
	
private:
    std::vector<Wifi> wifiList;  // Maps wifi properties (password, state) to every wifi name
};
