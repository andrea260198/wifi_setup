#include <QApplication>
#include <QQmlApplicationEngine>
#include "Server.h"
#include "Client.h"



int main(argc, **argv) 
{
	QApplication app(argc, argv);
	
	QQmlApplicationEngine engine("main.qml");
	
	Server server;
	
	Client client;
	
	QObject::connect(&server, &sendMsgToClient, &client, &receiveMsgFromServer);
	QObject::connect(&client, &sendMsgToServer, &server, &receiveMsgFromClient);
	QObject::connect(&client, &askWifiList, &server, &sendWifiList);
	
	return app.exec();
}
