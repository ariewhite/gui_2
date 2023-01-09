#ifndef CONFIG_H
#define CONFIG_H

#include "qdebug.h"
#include <QString>
#include <QCryptographicHash>

static QString DB_NAME = "pr8";
static QString DB_HOST = "localhost";
static QString DB_USER = "postgres";
static QString DB_PASS = "4560";

static QString hashing(QString pass) {
    QByteArray y = pass.toUtf8();
    auto x =  QCryptographicHash::hash(y, QCryptographicHash::Md5).toHex();
    return x;
}


#endif // CONFIG_H
