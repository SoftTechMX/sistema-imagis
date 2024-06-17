#include "FormCreateUsuario.h"
#include "ui_FormCreateUsuario.h"

FormCreateUsuario::FormCreateUsuario(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormCreateUsuario)
{
    ui->setupUi(this);
}

FormCreateUsuario::~FormCreateUsuario()
{
    delete ui;
}

void FormCreateUsuario::on_btn_save_clicked()
{
    this->config.open_connection();

    QString usuario          = ui->txt_usuario->text();
    QString password         = ui->txt_password->text();
    QString nombres          = ui->txt_nombres->text();
    QString primer_apellido  = ui->txt_primer_apellido->text();
    QString segundo_apellido = ui->txt_segundo_apeillido->text();
    QString carne            = ui->txt_ci->text();
    QString telefono         = ui->txt_telefono->text();
    QString sexo             = ui->combobox_sexo->currentText();
    QString fecha_nacimiento = ui->txt_fehca_nacimeinto->date().toString("yyyy-MM-dd");

    if(this->config.db_conexion.open())
    {
        QSqlQuery query_usuario;
        query_usuario.prepare("INSERT INTO usuarios (username, password) "
                      "VALUES (:username, :password)");

        query_usuario.bindValue(":username", usuario);
        query_usuario.bindValue(":password", password);

        if( !query_usuario.exec() )
        {
            QSqlError error = query_usuario.lastError();
            QMessageBox::critical(this, "Error", error.text());
            return;
        }

        QString id_usuario = query_usuario.lastInsertId().toString();

        QSqlQuery query_persona;
        query_persona.prepare("INSERT INTO personal (nombre, primer_apellido, segundo_apellido, sexo, telefono, carne_de_identidad, fecha_de_nacimiento, id_usuario) "
                      "VALUES (:nombre, :primer_apellido, :segundo_apellido, :sexo, :telefono, :ci, :fecha_de_nacimiento, :id_usuario)");
        query_persona.bindValue(":id_usuario", id_usuario);
        query_persona.bindValue(":nombre", nombres);
        query_persona.bindValue(":primer_apellido", primer_apellido);
        query_persona.bindValue(":segundo_apellido", segundo_apellido);
        query_persona.bindValue(":sexo", sexo);
        query_persona.bindValue(":fecha_de_nacimiento", fecha_nacimiento);
        query_persona.bindValue(":ci", carne);
        query_persona.bindValue(":telefono", telefono);

        if( query_persona.exec() )
        {
            QString mensaje = "Se ha agregado a la persona "+ nombres + " " + primer_apellido + " a la base de datos.";
            QMessageBox::information(this, "Success", mensaje);
        }
        else
        {
            QSqlError error = query_persona.lastError();
            QMessageBox::critical(this, "Error", error.text());
        }
    }
    else
    {
        QMessageBox::critical(this, "Error", "No se puede conectar a la DB");
    }
}

void FormCreateUsuario::on_btn_cancel_clicked()
{
    this->close();
}

