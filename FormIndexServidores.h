#include <QGroupBox>
#include <QTableWidget>
#include <QString>
#include <QStringList>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>

#include "FormCreateServidor.h"
#include "Config.h"

#ifndef FORMINDEXSERVIDORES_H
#define FORMINDEXSERVIDORES_H

namespace Ui {
    class FormIndexServidores;
}

class FormIndexServidores : public QGroupBox
{
    Q_OBJECT

    private:
        Config config;
        Ui::FormIndexServidores *ui;
        FormCreateServidor *window_create_servidor;

    public:
        explicit FormIndexServidores(QWidget *parent = nullptr);
        ~FormIndexServidores();
        void refresh_table();

    private slots:
        void on_btn_add_servidor_clicked();
        void on_btn_refresh_clicked();
};

#endif // FORMINDEXSERVIDORES_H
