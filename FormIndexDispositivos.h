#include <QGroupBox>
#include <QTableWidget>
#include <QString>
#include <QStringList>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>

#include "FormCreateDispositivo.h"
#include "Config.h"

#ifndef FORMINDEXDISPOSITIVOS_H
#define FORMINDEXDISPOSITIVOS_H

namespace Ui {
    class FormIndexDispositivos;
}

class FormIndexDispositivos : public QGroupBox
{
    Q_OBJECT

    private:
        Config config;
        Ui::FormIndexDispositivos *ui;
        FormCreateDispositivo *window_create_dispositivo;

    public:
        explicit FormIndexDispositivos(QWidget *parent = nullptr);
        ~FormIndexDispositivos();
        void refresh_table();

    private slots:
        void on_btn_agragar_dispositivo_clicked();
        void on_btn_refresh_clicked();
};

#endif // FORMINDEXDISPOSITIVOS_H
