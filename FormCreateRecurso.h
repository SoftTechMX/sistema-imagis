#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>

#ifndef FORMCREATERECURSO_H
#define FORMCREATERECURSO_H

namespace Ui {
    class FormCreateRecurso;
}

class FormCreateRecurso : public QWidget
{
    Q_OBJECT

    private:
        Ui::FormCreateRecurso *ui;

    public:
        explicit FormCreateRecurso(QWidget *parent = nullptr);
        ~FormCreateRecurso();

    private slots:
        void on_btn_save_clicked();
        void on_btn_cancel_clicked();
};

#endif // FORMCREATERECURSO_H
