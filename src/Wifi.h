#pragma once

#include <QString>


struct Wifi
{
    enum Status {
        INIT,
        CONN_SUCC,
        CONN_FAIL
    };

    QString id;
    QString auth;
    Status status = INIT;
};
