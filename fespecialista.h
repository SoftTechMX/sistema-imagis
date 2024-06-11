#ifndef FESPECIALISTA_H
#define FESPECIALISTA_H

#include <QMainWindow>

namespace Ui {
class fEspecialista;
}

class fEspecialista : public QMainWindow
{
    Q_OBJECT

public:
    explicit fEspecialista(QWidget *parent = nullptr);
    ~fEspecialista();

private:
    Ui::fEspecialista *ui;
};

#endif // FESPECIALISTA_H
