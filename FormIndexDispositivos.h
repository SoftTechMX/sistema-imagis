#include <QGroupBox>
#include <QTableWidget>
#include <QString>
#include <QStringList>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>

#include "Config.h"
#include "FormCreateDispositivo.h"

#ifndef FORMINDEXDISPOSITIVOS_H
#define FORMINDEXDISPOSITIVOS_H

namespace Ui {
    class FormIndexDispositivos;
}

class FormIndexDispositivos : public QGroupBox
{
    Q_OBJECT

    public:
        QSqlDatabase *db_conexion;

    private:
        Ui::FormIndexDispositivos *ui;
        FormCreateDispositivo *window_create_dispositivo;
        Config config;

    public:
        explicit FormIndexDispositivos(QWidget *parent = nullptr);
        ~FormIndexDispositivos();

    private slots:
        void on_btn_agragar_dispositivo_clicked();
};

#endif // FORMINDEXDISPOSITIVOS_H
