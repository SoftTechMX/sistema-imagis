#include "FormIndexConfiguracion.h"
#include "ui_FormIndexConfiguracion.h"

FormIndexConfiguracion::FormIndexConfiguracion(QWidget *parent) :
    QGroupBox(parent),
    ui(new Ui::FormIndexConfiguracion)
{
    ui->setupUi(this);
}

FormIndexConfiguracion::~FormIndexConfiguracion()
{
    delete ui;
}
