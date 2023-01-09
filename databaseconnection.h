#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H

#include "config.h"

class DatabaseConnection
{
public:
    DatabaseConnection();

public:
    static void connect_to_db();
};

#endif // DATABASECONNECTION_H
