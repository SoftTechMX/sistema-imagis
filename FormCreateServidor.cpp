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

}

void FormCreateServidor::on_btn_cancel_clicked()
{
    this->close();
}


