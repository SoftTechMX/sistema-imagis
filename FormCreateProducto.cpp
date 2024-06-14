#include "FormCreateProducto.h"
#include "ui_FormCreateProducto.h"

FormCreateProducto::FormCreateProducto(QWidget *parent) :
    QGroupBox(parent),
    ui(new Ui::FormCreateProducto)
{
    ui->setupUi(this);
}

FormCreateProducto::~FormCreateProducto()
{
    delete ui;
}

void FormCreateProducto::on_btn_create_producto_clicked()
{

}

