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

    std::vector<Wifi> getFromJson(QString filename);
	
public slots:
    void receiveMsgFromClient(Wifi msg);
	void sendWifiList();

signals:
    void sendMsgToClient(Wifi msg);
	
private:
    std::vector<Wifi> wifiList;  // Maps wifi properties (password, state) to every wifi name
};
