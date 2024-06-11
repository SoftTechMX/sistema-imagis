#include "flogin.h"
#include "ui_flogin.h"

fLogin::fLogin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::fLogin)
{
    ui->setupUi(this);

    qDebug() << QSqlDatabase::drivers();
}

fLogin::~fLogin()
{
    delete ui;
}


void fLogin::on_btnAcceder_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("BDSistemaLeonardo");
    db.setUserName("root");
    db.setPassword("12345678");

    if (db.open())
    {
        QMessageBox::information(this, "Conexión Satisfactoria...", "Conexión Satisfactoria");
    }
    else
    {
        // QMessageBox::critical(this, "Conexión Fallida", "Conexión Fallida");
        qDebug() << "Error: " << db.lastError().text();
    }

}

