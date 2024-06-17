#include <QGroupBox>
#include <QTableWidget>
#include <QString>
#include <QStringList>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>

#include "Config.h"
#include "FormCreateRecurso.h"

#ifndef FORMINDEXRECURSOS_H
#define FORMINDEXRECURSOS_H

namespace Ui {
    class FormIndexRecursos;
}

class FormIndexRecursos : public QGroupBox
{
    Q_OBJECT

    private:
        Ui::FormIndexRecursos *ui;
        FormCreateRecurso *window_create_recurso;
        Config config;

    public:
        explicit FormIndexRecursos(QWidget *parent = nullptr);
        ~FormIndexRecursos();
private slots:
        void on_btn_add_recurso_clicked();
};

#endif // FORMINDEXRECURSOS_H
