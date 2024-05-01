#pragma once

#include <QObject>
#include <QMap>
#include <QStringList>
#include <vector>
#include <algorithm>
#include <iostream>
#include "Wifi.h"


class Client : public QObject
{
	Q_OBJECT

    Q_PROPERTY(QStringList wifiList READ readWifiIds NOTIFY changeWifiList)

public:
    Client();

    void connectToServer();
    QStringList readWifiIds() const;
    void debug();


public:
    Q_SLOT void receiveMsgFromServer(Wifi msg);

    Q_SIGNAL void sendMsgToServer(Wifi msg);
    Q_SIGNAL void askWifiList();
    Q_SIGNAL void changeWifiList();

private:
    std::vector<Wifi> wifiList;
};
