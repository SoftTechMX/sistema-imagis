#include <QGroupBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>

#ifndef FORMSHOWLICENCIA_H
#define FORMSHOWLICENCIA_H

namespace Ui {
class FormShowLicencia;
}

class FormShowLicencia : public QGroupBox
{
    Q_OBJECT

public:
    explicit FormShowLicencia(QWidget *parent = nullptr);
    ~FormShowLicencia();

private:
    Ui::FormShowLicencia *ui;
};

#endif // FORMSHOWLICENCIA_H
