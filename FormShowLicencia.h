#ifndef FORMSHOWLICENCIA_H
#define FORMSHOWLICENCIA_H

#include <QGroupBox>

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
