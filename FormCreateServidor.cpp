#include "FormCreateServidor.h"
#include "ui_FormCreateServidor.h"

FormCreateServidor::FormCreateServidor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormCreateServidor)
{
    ui->setupUi(this);
}

FormCreateServidor::~FormCreateServidor()
{
    delete ui;
}

void FormCreateServidor::on_btn_save_clicked()
{
    this->config.open_connection();

    QString aet    = ui->txt_aet->text();
    QString host   = ui->txt_host->text();
    QString puerto = ui->txt_puerto->text();
    QString tipo   = ui->combobox_tipo->currentText();
    QString descripcion = ui->txt_descripcion->text();

    if(this->config.db_conexion.open())
    {
        QSqlQuery query;
        query.prepare("INSERT INTO servidores (aet, host, puerto, tipo_servidor, descripcion) "
                      "VALUES (:aet, :host, :puerto, :tipo_servidor, :descripcion)");

        query.bindValue(":aet", aet);
        query.bindValue(":host", host);
        query.bindValue(":puerto", puerto);
        query.bindValue(":tipo_servidor", tipo);
        query.bindValue(":descripcion", descripcion);

        if( query.exec() )
        {
            QString mensaje = "Se ha agregado el servidor a la base de datos.";
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

void FormCreateServidor::on_btn_cancel_clicked()
{
    this->close();
}


