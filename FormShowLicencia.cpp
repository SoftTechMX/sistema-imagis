#include "FormShowLicencia.h"
#include "ui_FormShowLicencia.h"

FormShowLicencia::FormShowLicencia(QWidget *parent) :
    QGroupBox(parent),
    ui(new Ui::FormShowLicencia)
{
    ui->setupUi(this);
}

FormShowLicencia::~FormShowLicencia()
{
    delete ui;
}
