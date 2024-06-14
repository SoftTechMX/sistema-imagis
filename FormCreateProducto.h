#ifndef FORMCREATEPRODUCTO_H
#define FORMCREATEPRODUCTO_H

#include <QGroupBox>

namespace Ui {
class FormCreateProducto;
}

class FormCreateProducto : public QGroupBox
{
    Q_OBJECT

public:
    explicit FormCreateProducto(QWidget *parent = nullptr);
    ~FormCreateProducto();

private slots:
    void on_btn_create_producto_clicked();

private:
    Ui::FormCreateProducto *ui;
};

#endif // FORMCREATEPRODUCTO_H
