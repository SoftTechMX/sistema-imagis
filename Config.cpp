#include "Config.h"

Config::Config()
{
    this->DB_HOST = "localhost";
    this->DB_NAME = "imagis";
    this->DB_PASSWORD = "imagis";
    this->DB_USERNAME = "imagis";
}

void Config::open_connection()
{
    this->db_conexion = QSqlDatabase::addDatabase("QMYSQL");
    this->db_conexion.setHostName(this->DB_HOST);
    this->db_conexion.setDatabaseName(this->DB_NAME);
    this->db_conexion.setUserName(this->DB_USERNAME);
    this->db_conexion.setPassword(this->DB_PASSWORD);
}
