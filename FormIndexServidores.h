#include <QGroupBox>
#include <QTableWidget>
#include <QString>
#include <QStringList>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>

#include "Config.h"
#include "FormCreateServidor.h"

#ifndef FORMINDEXSERVIDORES_H
#define FORMINDEXSERVIDORES_H

namespace Ui {
    class FormIndexServidores;
}

class FormIndexServidores : public QGroupBox
{
    Q_OBJECT

    private:
        Ui::FormIndexServidores *ui;
        FormCreateServidor *window_create_servidor;
        Config config;

    public:
        explicit FormIndexServidores(QWidget *parent = nullptr);
        ~FormIndexServidores();
private slots:
        void on_btn_add_servidor_clicked();
};

#endif // FORMINDEXSERVIDORES_H
