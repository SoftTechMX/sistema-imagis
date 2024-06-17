#include <QGroupBox>
#include <QTableWidget>
#include <QString>
#include <QStringList>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>

#include "FormCreateRecurso.h"
#include "Config.h"

#ifndef FORMINDEXRECURSOS_H
#define FORMINDEXRECURSOS_H

namespace Ui {
    class FormIndexRecursos;
}

class FormIndexRecursos : public QGroupBox
{
    Q_OBJECT

    private:
        Config config;
        Ui::FormIndexRecursos *ui;
        FormCreateRecurso *window_create_recurso;

    public:
        explicit FormIndexRecursos(QWidget *parent = nullptr);
        ~FormIndexRecursos();
        void refresh();

    private slots:
        void on_btn_add_recurso_clicked();
        void on_btn_refresh_clicked();
};

#endif // FORMINDEXRECURSOS_H
