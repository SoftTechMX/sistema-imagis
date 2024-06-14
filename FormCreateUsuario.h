#ifndef FORMCREATEUSUARIO_H
#define FORMCREATEUSUARIO_H

#include <QWidget>

namespace Ui {
    class FormCreateUsuario;
}

class FormCreateUsuario : public QWidget
{
    Q_OBJECT

public:
    explicit FormCreateUsuario(QWidget *parent = nullptr);
    ~FormCreateUsuario();

private:
    Ui::FormCreateUsuario *ui;
};

#endif // FORMCREATEUSUARIO_H
