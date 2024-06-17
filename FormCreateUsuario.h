#include <QWidget>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

#include "Config.h"

#ifndef FORMCREATEUSUARIO_H
#define FORMCREATEUSUARIO_H

namespace Ui {
    class FormCreateUsuario;
}

class FormCreateUsuario : public QWidget
{
    Q_OBJECT

    private:
        Config config;
        Ui::FormCreateUsuario *ui;

    public:
        explicit FormCreateUsuario(QWidget *parent = nullptr);
        ~FormCreateUsuario();

    private slots:
        void on_btn_save_clicked();
        void on_btn_cancel_clicked();
};

#endif // FORMCREATEUSUARIO_H
