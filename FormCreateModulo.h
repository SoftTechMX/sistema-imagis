#include <QWidget>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

#include "Config.h"

#ifndef FORMCREATEMODULO_H
#define FORMCREATEMODULO_H

namespace Ui {
    class FormCreateModulo;
}

class FormCreateModulo : public QWidget
{
    Q_OBJECT

    private:
        Config config;
        Ui::FormCreateModulo *ui;

    public:
        explicit FormCreateModulo(QWidget *parent = nullptr);
        ~FormCreateModulo();

    private slots:
        void on_btn_save_clicked();
        void on_btn_cancel_clicked();
};

#endif // FORMCREATEMODULO_H
