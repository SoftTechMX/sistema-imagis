#include <QGroupBox>
#include <QTableWidget>
#include <QString>
#include <QStringList>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>

#include "Config.h"
#include "FormCreateUsuario.h"

#ifndef FORMINDEXUSUARIOS_H
#define FORMINDEXUSUARIOS_H

namespace Ui {
    class FormIndexUsuarios;
}

class FormIndexUsuarios : public QGroupBox
{
    Q_OBJECT

    private:
        Ui::FormIndexUsuarios *ui;
        FormCreateUsuario *window_create_usuario;
        Config config;

    public:
        explicit FormIndexUsuarios(QWidget *parent = nullptr);
        ~FormIndexUsuarios();

    private slots:
        void on_btn_add_usaurio_clicked();
};

#endif // FORMINDEXUSUARIOS_H
