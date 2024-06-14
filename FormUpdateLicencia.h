#ifndef FORMUPDATELICENCIA_H
#define FORMUPDATELICENCIA_H

#include <QGroupBox>

namespace Ui {
class FormUpdateLicencia;
}

class FormUpdateLicencia : public QGroupBox
{
    Q_OBJECT

public:
    explicit FormUpdateLicencia(QWidget *parent = nullptr);
    ~FormUpdateLicencia();

private slots:
    void on_btn_actualizar_licencia_clicked();

private:
    Ui::FormUpdateLicencia *ui;
};

#endif // FORMUPDATELICENCIA_H
