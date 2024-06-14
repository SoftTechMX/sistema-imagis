#include "FormIndexProducto.h"
#include "ui_FormIndexProducto.h"

FormIndexProducto::FormIndexProducto(QWidget *parent) :
    QGroupBox(parent),
    ui(new Ui::FormIndexProducto)
{
    ui->setupUi(this);
}

FormIndexProducto::~FormIndexProducto()
{
    delete ui;
}

void FormIndexProducto::on_btn_create_producto_clicked()
{
    if(this->window_create_producto != nullptr)
    {
        this->window_create_producto = new FormCreateProducto();
        this->window_create_producto->show();
    }
}

