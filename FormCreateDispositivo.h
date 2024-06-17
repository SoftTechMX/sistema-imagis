#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>

#ifndef FORMCREATEDISPOSITIVO_H
#define FORMCREATEDISPOSITIVO_H

namespace Ui {
    class FormCreateDispositivo;
}

class FormCreateDispositivo : public QWidget
{
    Q_OBJECT

    public:
        QSqlDatabase *db_conexion;

    private:
        Ui::FormCreateDispositivo *ui;

    public:
        explicit FormCreateDispositivo(QWidget *parent = nullptr);
        ~FormCreateDispositivo();

    private slots:
        void on_btn_save_clicked();
        void on_btn_cancel_clicked();
};

#endif // FORMCREATEDISPOSITIVO_H
