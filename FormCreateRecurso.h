#include <QWidget>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

#include "Config.h"

#ifndef FORMCREATERECURSO_H
#define FORMCREATERECURSO_H

namespace Ui {
    class FormCreateRecurso;
}

class FormCreateRecurso : public QWidget
{
    Q_OBJECT

    private:
        Config config;
        Ui::FormCreateRecurso *ui;

    public:
        explicit FormCreateRecurso(QWidget *parent = nullptr);
        ~FormCreateRecurso();

    private slots:
        void on_btn_save_clicked();
        void on_btn_cancel_clicked();
};

#endif // FORMCREATERECURSO_H
