#pragma once

#include <QObject>
#include <QMap>
#include <vector>
#include <algorithm>
#include <iostream>
#include "Wifi.h"


class Client : public QObject
{
	Q_OBJECT

public:
    Client();

    void connectToServer();
    void debug();

public slots:
    void receiveMsgFromServer(Wifi msg);

signals:
    void sendMsgToServer(Wifi msg);
    void askWifiList();

private:
    std::vector<Wifi> wifiList;
};
