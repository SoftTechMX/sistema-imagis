#include <QGroupBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <unistd.h>
#include <QProgressBar>
#include <QPushButton>
#include <QTimer>

#include "Config.h"

#ifndef FORMINDEXACTULIZAR_H
#define FORMINDEXACTULIZAR_H

namespace Ui {
    class FormIndexActulizar;
}

class FormIndexActulizar : public QGroupBox
{
    Q_OBJECT

    private:
        Config config;
        Ui::FormIndexActulizar *ui;

    public:
        explicit FormIndexActulizar(QWidget *parent = nullptr);
        ~FormIndexActulizar();
private slots:
        void on_pushButton_clicked();
};

#endif // FORMINDEXACTULIZAR_H
