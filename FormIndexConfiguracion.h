#include <QGroupBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>

#include "Config.h"

#ifndef FORMINDEXCONFIGURACION_H
#define FORMINDEXCONFIGURACION_H

namespace Ui {
    class FormIndexConfiguracion;
}

class FormIndexConfiguracion : public QGroupBox
{
    Q_OBJECT

    private:
        Config config;
        Ui::FormIndexConfiguracion *ui;

    public:
        explicit FormIndexConfiguracion(QWidget *parent = nullptr);
        ~FormIndexConfiguracion();
};

#endif // FORMINDEXCONFIGURACION_H
