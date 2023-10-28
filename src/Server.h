#pragma once

#include <QObject>
#include <QMap>
#include "Msg.h"


class Server : public QObject
{
	Q_OBJECT

public:
	Server();
	
    QMap<QString, WifiProperties> getFromJson(QString file);
	
public slots:
	void receiveMsgFromClient(Msg msg);
	void sendWifiList();

signals:
	void sendMsgToClient(Msg);
	
private:
    QMap<QString, WifiProperties> wifiMap;  // Maps wifi properties (password, state) to every wifi name
};
