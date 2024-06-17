#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>

#ifndef FORMCREATESERVIDOR_H
#define FORMCREATESERVIDOR_H

namespace Ui {
    class FormCreateServidor;
}

class FormCreateServidor : public QWidget
{
    Q_OBJECT

    private:
        Ui::FormCreateServidor *ui;

    public:
        explicit FormCreateServidor(QWidget *parent = nullptr);
        ~FormCreateServidor();

    private slots:
        void on_btn_save_clicked();
        void on_btn_cancel_clicked();
};

#endif // FORMCREATESERVIDOR_H
