#include <QGroupBox>
#include <QTableWidget>
#include <QString>
#include <QStringList>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>

#include "Config.h"
#include "FormCreateModulo.h"

#ifndef FORMINDEXMODULO_H
#define FORMINDEXMODULO_H

namespace Ui {
    class FormIndexModulos;
}

class FormIndexModulos : public QGroupBox
{
    Q_OBJECT

    private:
        Ui::FormIndexModulos *ui;
        FormCreateModulo *window_create_modulo;
        Config config;

    public:
        explicit FormIndexModulos(QWidget *parent = nullptr);
        ~FormIndexModulos();

    private slots:
        void on_btn_add_modulo_clicked();
};

#endif // FORMINDEXMODULO_H
