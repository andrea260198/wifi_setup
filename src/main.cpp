#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "Server.h"
#include "Client.h"


int main(int argc, char **argv)
{
    QGuiApplication app(argc, argv);


    Server server;

    Client client;

    QQmlApplicationEngine engine;

    engine.load(":/qml/main.qml");


    // To include C++ object in qml:
    // https://scythe-studio.com/en/blog/how-to-integrate-qml-and-c-expose-object-and-register-c-class-to-qml
    engine.rootContext()->setContextProperty("client", &client);

    QObject::connect(&server, &Server::sendMsgToClient, &client, &Client::receiveMsgFromServer);
    QObject::connect(&client, &Client::sendMsgToServer, &server, &Server::receiveMsgFromClient);
    QObject::connect(&client, &Client::askWifiList, &server, &Server::sendWifiList);

    client.connectToServer();

    return app.exec();
}
