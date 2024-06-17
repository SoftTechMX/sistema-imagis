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

}

void FormCreateUsuario::on_btn_cancel_clicked()
{
    this->close();
}

