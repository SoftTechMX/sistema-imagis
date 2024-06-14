#include "LoginWindow.h"
#include "ui_LoginWindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    // Centrar la ventana en la pantalla
    QRect screenGeometry = QGuiApplication::primaryScreen()->geometry();
    int x = (screenGeometry.width() - width()) / 2;
    int y = (screenGeometry.height() - height()) / 2;
    move(x, y);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_btn_iniciar_sesion_clicked()
{
    QSqlDatabase conexion = QSqlDatabase::addDatabase("QMYSQL");
    conexion.setHostName(this->config.DB_HOST);
    conexion.setDatabaseName(this->config.DB_NAME);
    conexion.setUserName(this->config.DB_USERNAME);
    conexion.setPassword(this->config.DB_PASSWORD);

    QString usuario  = ui->usuario->text();
    QString password = ui->password->text();

    if(conexion.open())
    {
        QSqlQuery query;
        query.prepare("SELECT * FROM usuarios WHERE username = :usuario AND password = :password");
        query.bindValue(":usuario", usuario);
        query.bindValue(":password", password);

        if(query.exec() && query.next())
        {
            MainWindow *ventana = new MainWindow();
            ventana->show();

            this->close();
        }
        else
        {
            QMessageBox::warning(this, "Error", "Nombre de usuario o contraseña incorrectos");
        }
    }
    else
    {
        QMessageBox::information(this, "Error", "");
    }
}

