#include <QGroupBox>
#include <QTableWidget>
#include <QString>
#include <QStringList>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>

#include "FormCreateModulo.h"
#include "Config.h"

#ifndef FORMINDEXMODULO_H
#define FORMINDEXMODULO_H

namespace Ui {
    class FormIndexModulos;
}

class FormIndexModulos : public QGroupBox
{
    Q_OBJECT

    private:
        Config config;
        Ui::FormIndexModulos *ui;
        FormCreateModulo *window_create_modulo;

    public:
        explicit FormIndexModulos(QWidget *parent = nullptr);
        ~FormIndexModulos();
        void refresh_table();

    private slots:
        void on_btn_add_modulo_clicked();
        void on_btn_refresh_clicked();
};

#endif // FORMINDEXMODULO_H
