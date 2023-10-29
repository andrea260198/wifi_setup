#include <QApplication>
#include <QQmlApplicationEngine>
#include "Server.h"
#include "Client.h"



int main(int argc, char **argv)
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    engine.load(":/qml/main.qml");
	
	Server server;
	
    Client client;

    QObject::connect(&server, &Server::sendMsgToClient, &client, &Client::receiveMsgFromServer);
    QObject::connect(&client, &Client::sendMsgToServer, &server, &Server::receiveMsgFromClient);
    QObject::connect(&client, &Client::askWifiList, &server, &Server::sendWifiList);

    client.connectToServer();

	return app.exec();
}