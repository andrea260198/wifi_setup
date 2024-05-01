#pragma once

#include <QObject>
#include <QMap>
#include <QStringList>
#include <QVariant>
#include <vector>
#include <algorithm>
#include <iostream>
#include "Wifi.h"


using wifiStatusMap_t = QVariantMap;


class Client : public QObject
{
	Q_OBJECT

    Q_PROPERTY(QStringList wifiList READ readWifiIds NOTIFY changeWifiList)
    Q_PROPERTY(wifiStatusMap_t wifiStatusMap READ readWifiStatusMap NOTIFY changeWifiList)

public:
    Client();

    void connectToServer();
    QStringList readWifiIds() const;
    wifiStatusMap_t readWifiStatusMap() const;
    void debug();


public:
    Q_SLOT void receiveMsgFromServer(Wifi msg);

    Q_SIGNAL void sendMsgToServer(Wifi msg);
    Q_SIGNAL void askWifiList();
    Q_SIGNAL void changeWifiList();

    Q_INVOKABLE void buttonPressed(const QString &wifi, const QString &password);

private:
    std::vector<Wifi> wifiList;
};
