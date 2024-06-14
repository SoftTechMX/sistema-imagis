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
