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

    this->refresh();
}

FormIndexRecursos::~FormIndexRecursos()
{
    delete ui;
}

void FormIndexRecursos::refresh()
{
    this->config.open_connection();

    ui->tabla_recursos->clearContents();
    ui->tabla_recursos->setRowCount(0);

    if(this->config.db_conexion.open())
    {
        QSqlQuery query;
        query.exec("SELECT * FROM recursos");

        int fila = ui->tabla_recursos->rowCount() - 1;

        while (query.next()) {

            fila++;

            QString tipo        = query.value(1).toString();
            QString descripcion = query.value(2).toString();

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

void FormIndexRecursos::on_btn_add_recurso_clicked()
{
    this->window_create_recurso = new FormCreateRecurso();
    this->window_create_recurso->show();
}


void FormIndexRecursos::on_btn_refresh_clicked()
{
    this->refresh();
}

