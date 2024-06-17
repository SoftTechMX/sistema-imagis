#include "FormIndexRecursos.h"
#include "ui_FormIndexRecursos.h"

FormIndexRecursos::FormIndexRecursos(QWidget *parent) :
    QGroupBox(parent),
    ui(new Ui::FormIndexRecursos)
{
    ui->setupUi(this);

    // Configuracion de la Tabla
    QStringList titulos_columnas;
    titulos_columnas << "Tipo de Recurso"
                     << "Descripcion";

    ui->tabla_recursos->setColumnCount(2);
    ui->tabla_recursos->setHorizontalHeaderLabels(titulos_columnas);
    ui->tabla_recursos->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QSqlDatabase conexion = QSqlDatabase::addDatabase("QMYSQL");
    conexion.setHostName(this->config.DB_HOST);
    conexion.setDatabaseName(this->config.DB_NAME);
    conexion.setUserName(this->config.DB_USERNAME);
    conexion.setPassword(this->config.DB_PASSWORD);

    if(conexion.open())
    {
        QSqlQuery query;
        query.exec("SELECT * FROM recursos");

        int fila = ui->tabla_recursos->rowCount() - 1;

        while (query.next()) {

            fila++;

            QString tipo        = query.value(0).toString();
            QString descripcion = query.value(1).toString();

            ui->tabla_recursos->insertRow(fila);
            ui->tabla_recursos->setItem(fila, 0, new QTableWidgetItem(tipo));
            ui->tabla_recursos->setItem(fila, 1, new QTableWidgetItem(descripcion));
        }
    }
    else
    {
        QMessageBox::information(this, "Error", "No se pudo establecer una conexion con la base de datos");
    }
}

FormIndexRecursos::~FormIndexRecursos()
{
    delete ui;
}

void FormIndexRecursos::on_btn_add_recurso_clicked()
{
    if(this->window_create_recurso != nullptr)
    {
        this->window_create_recurso = new FormCreateRecurso();
        this->window_create_recurso->show();
    }
}

