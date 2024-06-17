#include "FormIndexServidores.h"
#include "ui_FormIndexServidores.h"

FormIndexServidores::FormIndexServidores(QWidget *parent) :
    QGroupBox(parent),
    ui(new Ui::FormIndexServidores)
{
    ui->setupUi(this);

    // Configuracion de la Tabla
    QStringList titulos_columnas;
    titulos_columnas << "AET"
                     << "Host"
                     << "Puerto"
                     << "Tipo de Servidor"
                     << "Descripcion";

    ui->tabla_servidores->setColumnCount(5);
    ui->tabla_servidores->setHorizontalHeaderLabels(titulos_columnas);
    ui->tabla_servidores->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


    this->refresh_table();
}

FormIndexServidores::~FormIndexServidores()
{
    delete ui;
}

void FormIndexServidores::refresh_table()
{
    this->config.open_connection();

    ui->tabla_servidores->clearContents();
    ui->tabla_servidores->setRowCount(0);

    if(this->config.db_conexion.open())
    {
        QSqlQuery query;
        query.exec("SELECT * FROM servidores");

        int fila = ui->tabla_servidores->rowCount() - 1;

        while (query.next()) {

            fila++;

            QString aet              = query.value(1).toString();
            QString host             = query.value(2).toString();
            QString puerto           = query.value(3).toString();
            QString tipo_de_servidor = query.value(4).toString();
            QString descripcion      = query.value(5).toString();

            ui->tabla_servidores->insertRow(fila);
            ui->tabla_servidores->setItem(fila, 0, new QTableWidgetItem(aet));
            ui->tabla_servidores->setItem(fila, 1, new QTableWidgetItem(host));
            ui->tabla_servidores->setItem(fila, 2, new QTableWidgetItem(puerto));
            ui->tabla_servidores->setItem(fila, 3, new QTableWidgetItem(tipo_de_servidor));
            ui->tabla_servidores->setItem(fila, 4, new QTableWidgetItem(descripcion));
        }
    }
    else
    {
        QMessageBox::information(this, "Error", "No se pudo establecer una conexion con la base de datos");
    }
}

void FormIndexServidores::on_btn_add_servidor_clicked()
{
    this->window_create_servidor = new FormCreateServidor();
    this->window_create_servidor->show();
}


void FormIndexServidores::on_btn_refresh_clicked()
{
    this->refresh_table();
}

