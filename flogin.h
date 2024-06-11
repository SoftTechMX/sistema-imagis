#ifndef FLOGIN_H
#define FLOGIN_H

#include <QMainWindow>

#include <QtSql>
#include <QtCore>
#include <QDebug>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>


#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>


#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class fLogin; }
QT_END_NAMESPACE

class fLogin : public QMainWindow
{
    Q_OBJECT

public:
    fLogin(QWidget *parent = nullptr);
    ~fLogin();

private slots:
    void on_btnAcceder_clicked();

private:
    Ui::fLogin *ui;
};
#endif // FLOGIN_H
