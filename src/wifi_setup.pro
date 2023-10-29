TEMPLATE = app

QT_VERSION = 5

CONFIG += c++17

QT += widgets
QT += quick

DESTDIR = ../bin


HEADERS = \
	Client.h \
	Server.h \
        Wifi.h


SOURCES = \
	main.cpp \
	Client.cpp \
	Server.cpp


RESOURCES = myresources.qrc
