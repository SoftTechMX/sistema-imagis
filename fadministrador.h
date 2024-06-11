#ifndef FADMINISTRADOR_H
#define FADMINISTRADOR_H

#include <QMainWindow>

namespace Ui {
class fAdministrador;
}

class fAdministrador : public QMainWindow
{
    Q_OBJECT

public:
    explicit fAdministrador(QWidget *parent = nullptr);
    ~fAdministrador();

private:
    Ui::fAdministrador *ui;
};

#endif // FADMINISTRADOR_H
