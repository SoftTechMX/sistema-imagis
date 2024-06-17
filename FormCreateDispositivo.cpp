#include "FormCreateDispositivo.h"
#include "ui_FormCreateDispositivo.h"

FormCreateDispositivo::FormCreateDispositivo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormCreateDispositivo)
{
    ui->setupUi(this);
}

FormCreateDispositivo::~FormCreateDispositivo()
{
    delete ui;
}

void FormCreateDispositivo::on_btn_save_clicked()
{
    this->config.open_connection();

    QString marca   = ui->txt_marca->text();
    QString modelo  = ui->txt_modelo->text();
    QString tipo    = ui->txt_tipo_de_dispositivo->text();

    if(this->config.db_conexion.open())
    {
        QSqlQuery query;
        query.prepare("INSERT INTO dispositivos (tipo, marca, modelo) "
                      "VALUES (:tipo, :marca, :modelo)");
        query.bindValue(":tipo", tipo);
        query.bindValue(":marca", marca);
        query.bindValue(":modelo", modelo);

        if( query.exec() )
        {
            QString mensaje = "Se ha agregado el dispositivo a la base de datos.";
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
        QMessageBox::critical(this, "Error", "No se pudo establecer una conexion con la base de datos.");
    }
}

void FormCreateDispositivo::on_btn_cancel_clicked()
{
    this->close();
}


