#include <QObject>


struct WifiProperties
{
	QString password;
	bool state;
};


class Server : public QObject
{
	Q_OBJECT
public:
	Server();
	
	getFromJson();
	
private slots:
	void receiveMsgFromClient(Msg msg);
	void sendWifiList();

signals:
	void sendMsgToClient(Msg);
	
private:
	QMap<QString, WifiProperties> wifiMap;  // Maps wifi properties (password, state) to every wifi name
};