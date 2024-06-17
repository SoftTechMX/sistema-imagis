#include <QGroupBox>
#include <QTableWidget>
#include <QString>
#include <QStringList>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>

#include "FormCreateUsuario.h"
#include "Config.h"

#ifndef FORMINDEXUSUARIOS_H
#define FORMINDEXUSUARIOS_H

namespace Ui {
    class FormIndexUsuarios;
}

class FormIndexUsuarios : public QGroupBox
{
    Q_OBJECT

    private:
        Config config;
        Ui::FormIndexUsuarios *ui;
        FormCreateUsuario *window_create_usuario;

    public:
        explicit FormIndexUsuarios(QWidget *parent = nullptr);
        ~FormIndexUsuarios();

        void refresh_table();

    private slots:
        void on_btn_add_usaurio_clicked();
        void on_btn_refresh_clicked();
};

#endif // FORMINDEXUSUARIOS_H
