#include "FormCreateRecurso.h"
#include "ui_FormCreateRecurso.h"

FormCreateRecurso::FormCreateRecurso(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormCreateRecurso)
{
    ui->setupUi(this);
}

FormCreateRecurso::~FormCreateRecurso()
{
    delete ui;
}

void FormCreateRecurso::on_btn_save_clicked()
{
    this->config.open_connection();

    QString recurso          = ui->txt_recurso->text();
    QString descripcion      = ui->txt_descripcion->text();

    if(this->config.db_conexion.open())
    {
        QSqlQuery query;
        query.prepare("INSERT INTO recursos (tipo_de_recurso, descripcion) "
                      "VALUES (:recurso, :descripcion)");

        query.bindValue(":recurso", recurso);
        query.bindValue(":descripcion", descripcion);

        if( query.exec() )
        {
            QString mensaje = "Se ha agregado el recurso a la base de datos.";
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

void FormCreateRecurso::on_btn_cancel_clicked()
{
    this->close();
}
