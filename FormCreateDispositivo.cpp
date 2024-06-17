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
    if(this->db_conexion != nullptr && this->db_conexion->open())
    {
        this->close();
        QMessageBox::information(this, "Success", "Se guardo la informacion correctamente.");
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


