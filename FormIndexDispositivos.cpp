#include "FormIndexDispositivos.h"
#include "ui_FormIndexDispositivos.h"

FormIndexDispositivos::FormIndexDispositivos(QWidget *parent) :
    QGroupBox(parent),
    ui(new Ui::FormIndexDispositivos)
{
    ui->setupUi(this);

    // Configuracion de la Tabla
    QStringList titulos_columnas;
    titulos_columnas << "# Dispositivo"
                     << "Modulo"
                     << "Marca"
                     << "Modelo";

    ui->tabla_dispositivos->setColumnCount(4);
    ui->tabla_dispositivos->setHorizontalHeaderLabels(titulos_columnas);
    ui->tabla_dispositivos->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    this->refresh_table();
}

FormIndexDispositivos::~FormIndexDispositivos()
{
    delete ui;
}

void FormIndexDispositivos::refresh_table()
{
    this->config.open_connection();

    ui->tabla_dispositivos->clearContents();
    ui->tabla_dispositivos->setRowCount(0);

    if(this->config.db_conexion.open())
    {
        QSqlQuery query;
        query.exec("SELECT * FROM dispositivos");

        int fila = ui->tabla_dispositivos->rowCount() - 1;

        while (query.next()) {

            fila++;

            QString id     = query.value(0).toString();
            QString modulo = query.value(1).toString();
            QString marca  = query.value(2).toString();
            QString modelo = query.value(3).toString();

            ui->tabla_dispositivos->insertRow(fila);
            ui->tabla_dispositivos->setItem(fila, 0, new QTableWidgetItem(id));
            ui->tabla_dispositivos->setItem(fila, 1, new QTableWidgetItem(modulo));
            ui->tabla_dispositivos->setItem(fila, 2, new QTableWidgetItem(marca));
            ui->tabla_dispositivos->setItem(fila, 3, new QTableWidgetItem(modelo));
        }
    }
    else
    {
        QMessageBox::information(this, "Error", "No se pudo establecer una conexion con la base de datos");
    }
}

void FormIndexDispositivos::on_btn_agragar_dispositivo_clicked()
{
    this->window_create_dispositivo = new FormCreateDispositivo();
    this->window_create_dispositivo->show();
}


void FormIndexDispositivos::on_btn_refresh_clicked()
{
    this->refresh_table();
}

