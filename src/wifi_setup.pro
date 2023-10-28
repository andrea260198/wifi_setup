TEMPLATE = app

QT_VERSION = 5

CONFIG += c++17

QT += widgets

DESTDIR = ../bin


HEADERS =
	Client.h \
	Server.h


SOURCES =
	main.cpp \
	Client.cpp \
	Server.cpp
