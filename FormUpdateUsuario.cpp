#include "FormUpdateUsuario.h"
#include "ui_FormUpdateUsuario.h"

FormUpdateUsuario::FormUpdateUsuario(QWidget *parent) :
    QGroupBox(parent),
    ui(new Ui::FormUpdateUsuario)
{
    ui->setupUi(this);
}

FormUpdateUsuario::~FormUpdateUsuario()
{
    delete ui;
}
