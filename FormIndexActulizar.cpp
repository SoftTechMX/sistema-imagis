#include "FormIndexActulizar.h"
#include "ui_FormIndexActulizar.h"

FormIndexActulizar::FormIndexActulizar(QWidget *parent) :
    QGroupBox(parent),
    ui(new Ui::FormIndexActulizar)
{
    ui->setupUi(this);

//    ui->progressbar->hide();
    ui->progressbar->setRange(0, 100);
    ui->progressbar->setValue(0);
}

FormIndexActulizar::~FormIndexActulizar()
{
    delete ui;
}

void FormIndexActulizar::on_pushButton_clicked()
{
    for(int i=0; i <= 100; i++)
    {
        ui->progressbar->setValue(i);
        usleep(500);
    }

    QMessageBox::information(this, "Success", "Se ha actualizado el Software");
}

