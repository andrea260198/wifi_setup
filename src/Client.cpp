#include "Client.h"


Client::Client()
{
	emit askWifiList();
}


Client::receiveMsgFromServer(Msg msg)
{
	if (msg.wifi is in wifiMap) {
		wifiMap[msg.wifi].state = msg.state;
	} else {
		// new wifi
		wifiMap[msf.wifi] = {.password = "", .state = true};
	}
}
