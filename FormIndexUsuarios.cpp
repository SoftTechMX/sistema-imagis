#include "FormIndexUsuarios.h"
#include "ui_FormIndexUsuarios.h"

FormIndexUsuarios::FormIndexUsuarios(QWidget *parent) :
    QGroupBox(parent),
    ui(new Ui::FormIndexUsuarios)
{
    ui->setupUi(this);

    // Configuracion de la Tabla
    QStringList titulos_columnas;
    titulos_columnas << "Nombres"
                     << "Primer Apellido"
                     << "Segundo Apellido"
                     << "Fecha de Nacimiento"
                     << "Sexo";

    ui->tabla_usuarios->setColumnCount(5);
    ui->tabla_usuarios->setHorizontalHeaderLabels(titulos_columnas);
    ui->tabla_usuarios->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QSqlDatabase conexion = QSqlDatabase::addDatabase("QMYSQL");
    conexion.setHostName(this->config.DB_HOST);
    conexion.setDatabaseName(this->config.DB_NAME);
    conexion.setUserName(this->config.DB_USERNAME);
    conexion.setPassword(this->config.DB_PASSWORD);

    if(conexion.open())
    {
        QSqlQuery query;
        query.exec("SELECT * FROM usuarios");

        int fila = ui->tabla_usuarios->rowCount() - 1;

        while (query.next()) {

            fila++;

            QString nombres             = query.value(4).toString();
            QString primer_apellido     = query.value(5).toString();
            QString segundo_apellido    = query.value(6).toString();
            QString fecha_de_nacimiento = query.value(7).toString();
            QString sexo                = query.value(8).toString();

            ui->tabla_usuarios->insertRow(fila);
            ui->tabla_usuarios->setItem(fila, 0, new QTableWidgetItem(nombres));
            ui->tabla_usuarios->setItem(fila, 1, new QTableWidgetItem(primer_apellido));
            ui->tabla_usuarios->setItem(fila, 2, new QTableWidgetItem(segundo_apellido));
            ui->tabla_usuarios->setItem(fila, 3, new QTableWidgetItem(fecha_de_nacimiento));
            ui->tabla_usuarios->setItem(fila, 4, new QTableWidgetItem(sexo));
        }
    }
    else
    {
        QMessageBox::information(this, "Error", "");
    }
}

FormIndexUsuarios::~FormIndexUsuarios()
{
    delete ui;
}


void FormIndexUsuarios::on_btn_create_usuario_clicked()
{
    if(this->window_create_usuario != nullptr)
    {
        this->window_create_usuario = new FormCreateUsuario();
        this->window_create_usuario->show();
    }
}

