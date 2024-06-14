#include <QMainWindow>
#include <QApplication>
#include <QDesktopWidget>
#include <QScreen>
#include <QSqlDatabase>
#include <QSql>
#include <QSqlQuery>
#include <QSqlDriver>
#include <QMessageBox>
#include <QLineEdit>

#include "Config.h"
#include "MainWindow.h"

#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

namespace Ui {
    class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT

    private:
        Ui::LoginWindow *ui;
        Config config;

    public:
        explicit LoginWindow(QWidget *parent = nullptr);
        ~LoginWindow();

    private slots:
        void on_btn_iniciar_sesion_clicked();
};
#endif // LOGINWINDOW_H
