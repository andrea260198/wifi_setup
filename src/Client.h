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
    int n() const;

    Client();

    void connectToServer();
    QStringList readWifiIds() const;
    void debug();


public slots:
    void receiveMsgFromServer(Wifi msg);

signals:
    void sendMsgToServer(Wifi msg);
    void askWifiList();
    void changeWifiList();

private:
    std::vector<Wifi> wifiList;
};
