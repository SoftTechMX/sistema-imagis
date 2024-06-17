#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>

#ifndef FORMCREATEUSUARIO_H
#define FORMCREATEUSUARIO_H

namespace Ui {
    class FormCreateUsuario;
}

class FormCreateUsuario : public QWidget
{
    Q_OBJECT

    private:
        Ui::FormCreateUsuario *ui;

    public:
        explicit FormCreateUsuario(QWidget *parent = nullptr);
        ~FormCreateUsuario();

    private slots:
        void on_btn_save_clicked();
        void on_btn_cancel_clicked();
};

#endif // FORMCREATEUSUARIO_H
