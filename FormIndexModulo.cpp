#include "FormIndexModulo.h"
#include "ui_FormIndexModulos.h"

FormIndexModulos::FormIndexModulos(QWidget *parent) :
    QGroupBox(parent),
    ui(new Ui::FormIndexModulos)
{
    ui->setupUi(this);

    // Configuracion de la Tabla
    QStringList titulos_columnas;
    titulos_columnas << "# Modulo"
                     << "Nombre del Modulo"
                     << "Licencia";

    ui->tabla_modulos->setColumnCount(3);
    ui->tabla_modulos->setHorizontalHeaderLabels(titulos_columnas);
    ui->tabla_modulos->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QSqlDatabase conexion = QSqlDatabase::addDatabase("QMYSQL");
    conexion.setHostName(this->config.DB_HOST);
    conexion.setDatabaseName(this->config.DB_NAME);
    conexion.setUserName(this->config.DB_USERNAME);
    conexion.setPassword(this->config.DB_PASSWORD);

    if(conexion.open())
    {
        QSqlQuery query;
        query.exec("SELECT * FROM modulos");

        int fila = ui->tabla_modulos->rowCount() - 1;

        while (query.next()) {

            fila++;

            QString id       = query.value(0).toString();
            QString nombre   = query.value(1).toString();
            QString licencia = query.value(2).toString();

            ui->tabla_modulos->insertRow(fila);
            ui->tabla_modulos->setItem(fila, 0, new QTableWidgetItem(id));
            ui->tabla_modulos->setItem(fila, 1, new QTableWidgetItem(nombre));
            ui->tabla_modulos->setItem(fila, 2, new QTableWidgetItem(licencia));
        }
    }
    else
    {
        QMessageBox::information(this, "Error", "No se pudo establecer una conexion con la base de datos");
    }
}

FormIndexModulos::~FormIndexModulos()
{
    delete ui;
}

void FormIndexModulos::on_btn_add_modulo_clicked()
{
    if(this->window_create_modulo != nullptr)
    {
        this->window_create_modulo = new FormCreateModulo();
        this->window_create_modulo->show();
    }
}
