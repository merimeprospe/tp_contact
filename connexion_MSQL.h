#ifndef CONNEXION_MSQL_H
#define CONNEXION_MSQL_H


#include "QSqlDatabase"
#include "QSqlQuery"

    static bool vraiconnexionBD()
    {
        QSqlDatabase conn=QSqlDatabase::addDatabase("QMYSQL");
        conn.setHostName("127.0.0.1");
        conn.setUserName("root");
        conn.setDatabaseName("contact");
        conn.setPort(3306);

        if(conn.open()){
            return true;
        } else
        {
           return false;
        }
    }

#endif // CONNEXION_MSQL_H
