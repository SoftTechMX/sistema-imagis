#include <QString>

#ifndef CONFIG_H
#define CONFIG_H

class Config
{
public:
    QString DB_HOST;
    QString DB_NAME;
    QString DB_USERNAME;
    QString DB_PASSWORD;
public:
    Config();
};

#endif // CONFIG_H
