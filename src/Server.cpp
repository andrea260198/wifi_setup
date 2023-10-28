#include "Server.h"


Sever::Server() 
{
	wifiPasswordMap = getFromJson("input.json");
	wifiOpenMap
}


void Server::receiveMsgFromClient(Msg msg)  // Msg with wifi and password
{
	if (wifiMap[msg.wifi].password == msg.password)
	{
		wifiMap[msg.wifi].state = true;
		
		Msg answer = msg;
		answer.wifi = msg.wifi;
		answer.state = true;
		
		emit sendMsgToClient(answer);
	}
}


void Server::sendWifiList()
{
	for (const auto &wifi : wifiMap)
	{
		Msg msg;
		msg.wifi = wifi;
		msg.state = wifiMap[wifi].state;
		emit sendMsgToClient(msg);
	}
}
