#include "FormIndexActulizar.h"
#include "ui_FormIndexActulizar.h"

FormIndexActulizar::FormIndexActulizar(QWidget *parent) :
    QGroupBox(parent),
    ui(new Ui::FormIndexActulizar)
{
    ui->setupUi(this);
}

FormIndexActulizar::~FormIndexActulizar()
{
    delete ui;
}
