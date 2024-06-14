#include "FormUpdateLicencia.h"
#include "ui_FormUpdateLicencia.h"

FormUpdateLicencia::FormUpdateLicencia(QWidget *parent) :
    QGroupBox(parent),
    ui(new Ui::FormUpdateLicencia)
{
    ui->setupUi(this);
}

FormUpdateLicencia::~FormUpdateLicencia()
{
    delete ui;
}


void FormUpdateLicencia::on_btn_actualizar_licencia_clicked()
{

}

