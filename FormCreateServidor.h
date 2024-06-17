#include <QWidget>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

#include "Config.h"

#ifndef FORMCREATESERVIDOR_H
#define FORMCREATESERVIDOR_H

namespace Ui {
    class FormCreateServidor;
}

class FormCreateServidor : public QWidget
{
    Q_OBJECT

    private:
        Config config;
        Ui::FormCreateServidor *ui;

    public:
        explicit FormCreateServidor(QWidget *parent = nullptr);
        ~FormCreateServidor();

    private slots:
        void on_btn_save_clicked();
        void on_btn_cancel_clicked();
};

#endif // FORMCREATESERVIDOR_H
