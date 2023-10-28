#include <QObject>


class Client : public QObject
{
	Q_OBJECT
public:
	Client();
	
signals:
	void sendMsgToServer(Msg msg);
	void askWifiList(); 
	
private slots:
	void receiveMsgFromServer(Msg msg);

private:
	QMap<QString, WifiProperties> wifiMap;  // Maps wifi properties (password, state) to every wifi name
}