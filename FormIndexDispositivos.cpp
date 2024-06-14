#include "FormIndexDispositivos.h"
#include "ui_FormIndexDispositivos.h"

FormIndexDispositivos::FormIndexDispositivos(QWidget *parent) :
    QGroupBox(parent),
    ui(new Ui::FormIndexDispositivos)
{
    ui->setupUi(this);
}

FormIndexDispositivos::~FormIndexDispositivos()
{
    delete ui;
}
