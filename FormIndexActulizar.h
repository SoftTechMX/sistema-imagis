#include <QGroupBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>

#ifndef FORMINDEXACTULIZAR_H
#define FORMINDEXACTULIZAR_H

namespace Ui {
class FormIndexActulizar;
}

class FormIndexActulizar : public QGroupBox
{
    Q_OBJECT

public:
    explicit FormIndexActulizar(QWidget *parent = nullptr);
    ~FormIndexActulizar();

private:
    Ui::FormIndexActulizar *ui;
};

#endif // FORMINDEXACTULIZAR_H
