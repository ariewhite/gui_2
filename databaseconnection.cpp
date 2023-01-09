#include "databaseconnection.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

DatabaseConnection::DatabaseConnection()
{

}
// create connection to database
void DatabaseConnection::connect_to_db()
{
    // select driver for db. PSQL - postgres
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");

    db.setDatabaseName(DB_NAME);
    db.setHostName(DB_HOST);
    db.setUserName(DB_USER);
    db.setPassword(DB_PASS);

    if (!db.open()){
        qDebug() << "Error connection to db";
    }
    else {
        qDebug() << "Succeful connection";
    }
}


