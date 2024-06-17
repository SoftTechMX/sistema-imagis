#include "FormCreateModulo.h"
#include "ui_FormCreateModulo.h"

FormCreateModulo::FormCreateModulo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormCreateModulo)
{
    ui->setupUi(this);
}

FormCreateModulo::~FormCreateModulo()
{
    delete ui;
}

void FormCreateModulo::on_btn_save_clicked()
{
    this->config.open_connection();

    QString modulo = ui->txt_modulo->text();

    if(this->config.db_conexion.open())
    {
        QSqlQuery query;
        query.prepare("INSERT INTO modulos (nombre_modulo) "
                      "VALUES (:nombre_modulo)");

        query.bindValue(":nombre_modulo", modulo);


        if( query.exec() )
        {
            QString mensaje = "Se ha agregado el modulo a la base de datos.";
            QMessageBox::information(this, "Success", mensaje);
        }
        else
        {
            QSqlError error = query.lastError();
            QMessageBox::critical(this, "Error", error.text());
        }
    }
    else
    {
        QMessageBox::critical(this, "Error", "No se puede conectar a la DB");
    }
}

void FormCreateModulo::on_btn_cancel_clicked()
{
    this->close();
}
