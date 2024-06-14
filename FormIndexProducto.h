#include <QGroupBox>

#include "FormCreateProducto.h"

#ifndef FORMINDEXPRODUCTO_H
#define FORMINDEXPRODUCTO_H

namespace Ui {
    class FormIndexProducto;
}

class FormIndexProducto : public QGroupBox
{
    Q_OBJECT

    private:
        Ui::FormIndexProducto *ui;
        FormCreateProducto *window_create_producto;

    public:
        explicit FormIndexProducto(QWidget *parent = nullptr);
        ~FormIndexProducto();

    private slots:
        void on_btn_create_producto_clicked();
};

#endif // FORMINDEXPRODUCTO_H
