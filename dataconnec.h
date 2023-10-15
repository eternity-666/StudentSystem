#ifndef DATACONNEC_H
#define DATACONNEC_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class DataConnec
{
public:
    DataConnec();

public:
   void connectionMysql();
private:
    QSqlDatabase db;
};

#endif // DATACONNEC_H
