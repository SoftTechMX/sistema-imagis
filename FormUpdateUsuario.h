#ifndef FORMUPDATEUSUARIO_H
#define FORMUPDATEUSUARIO_H

#include <QGroupBox>

namespace Ui {
class FormUpdateUsuario;
}

class FormUpdateUsuario : public QGroupBox
{
    Q_OBJECT

public:
    explicit FormUpdateUsuario(QWidget *parent = nullptr);
    ~FormUpdateUsuario();

private:
    Ui::FormUpdateUsuario *ui;
};

#endif // FORMUPDATEUSUARIO_H
