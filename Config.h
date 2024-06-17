#include <QString>
#include <QSqlDatabase>

#ifndef CONFIG_H
#define CONFIG_H

class Config
{
public:
    QString DB_HOST;
    QString DB_NAME;
    QString DB_USERNAME;
    QString DB_PASSWORD;
    QSqlDatabase db_conexion;

public:
    Config();
    void open_connection();
};

#endif // CONFIG_H
