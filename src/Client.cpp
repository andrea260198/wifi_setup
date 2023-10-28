#include "Client.h"


Client::Client()
{
	emit askWifiList();
}


void Client::receiveMsgFromServer(Msg msg)
{
	// TODO: Uncomment
    //if (msg.wifi is in wifiMap) {
    //	wifiMap[msg.wifi].state = msg.state;
    //} else {
    //	// new wifi
    //	wifiMap[msf.wifi] = {.password = "", .state = true};
    //}
}
