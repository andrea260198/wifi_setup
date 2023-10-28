#pragma once

#include <QObject>
#include <QMap>
#include "Msg.h"


class Client : public QObject
{
	Q_OBJECT

public:
    Client();

public slots:
    void receiveMsgFromServer(Msg msg);

signals:
	void sendMsgToServer(Msg msg);
    void askWifiList();

private:
	QMap<QString, WifiProperties> wifiMap;  // Maps wifi properties (password, state) to every wifi name
};
