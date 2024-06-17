#include <QGroupBox>
#include <QSqlDatabase>
#include <QSqlQuery>

#include "Config.h"

#ifndef FORMUPDATELICENCIA_H
#define FORMUPDATELICENCIA_H

namespace Ui {
    class FormUpdateLicencia;
}

class FormUpdateLicencia : public QGroupBox
{
    Q_OBJECT

    private:
        Config config;
        Ui::FormUpdateLicencia *ui;

    public:
        explicit FormUpdateLicencia(QWidget *parent = nullptr);
        ~FormUpdateLicencia();

    private slots:
        void on_btn_actualizar_licencia_clicked();
};

#endif // FORMUPDATELICENCIA_H
