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

}

void FormCreateRecurso::on_btn_cancel_clicked()
{
    this->close();
}
