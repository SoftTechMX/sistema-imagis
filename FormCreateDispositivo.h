#include <QWidget>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

#include "Config.h"

#ifndef FORMCREATEDISPOSITIVO_H
#define FORMCREATEDISPOSITIVO_H

namespace Ui {
    class FormCreateDispositivo;
}

class FormCreateDispositivo : public QWidget
{
    Q_OBJECT

    private:
        Config config;
        Ui::FormCreateDispositivo *ui;

    public:
        explicit FormCreateDispositivo(QWidget *parent = nullptr);
        ~FormCreateDispositivo();

    private slots:
        void on_btn_save_clicked();
        void on_btn_cancel_clicked();
};

#endif // FORMCREATEDISPOSITIVO_H
