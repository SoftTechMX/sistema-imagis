#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>

#ifndef FORMCREATEMODULO_H
#define FORMCREATEMODULO_H

namespace Ui {
    class FormCreateModulo;
}

class FormCreateModulo : public QWidget
{
    Q_OBJECT

    public:
        QSqlDatabase *db_conexion;

    private:
        Ui::FormCreateModulo *ui;

    public:
        explicit FormCreateModulo(QWidget *parent = nullptr);
        ~FormCreateModulo();

    private slots:
        void on_btn_save_clicked();
        void on_btn_cancel_clicked();
};

#endif // FORMCREATEMODULO_H
