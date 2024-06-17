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
}

void FormCreateModulo::on_btn_cancel_clicked()
{
    this->close();
}
