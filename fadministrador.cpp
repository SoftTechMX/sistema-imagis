#include "fadministrador.h"
#include "ui_fadministrador.h"

fAdministrador::fAdministrador(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::fAdministrador)
{
    ui->setupUi(this);
}

fAdministrador::~fAdministrador()
{
    delete ui;
}
