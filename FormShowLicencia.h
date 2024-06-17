#include <QGroupBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>

#include "Config.h"

#ifndef FORMSHOWLICENCIA_H
#define FORMSHOWLICENCIA_H

namespace Ui {
    class FormShowLicencia;
}

class FormShowLicencia : public QGroupBox
{
    Q_OBJECT

    private:
        Config config;
        Ui::FormShowLicencia *ui;

    public:
        explicit FormShowLicencia(QWidget *parent = nullptr);
        ~FormShowLicencia();
};

#endif // FORMSHOWLICENCIA_H
