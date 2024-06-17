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

    this->refresh_table();
}

FormIndexUsuarios::~FormIndexUsuarios()
{
    delete ui;
}


void FormIndexUsuarios::on_btn_add_usaurio_clicked()
{
    this->window_create_usuario = new FormCreateUsuario();
    this->window_create_usuario->show();
}

void FormIndexUsuarios::refresh_table()
{
    this->config.open_connection();

    ui->tabla_usuarios->clearContents();
    ui->tabla_usuarios->setRowCount(0);

    if(this->config.db_conexion.open())
    {
        QSqlQuery query;
        query.exec("SELECT * FROM personal");

        int fila = ui->tabla_usuarios->rowCount() - 1;

        while (query.next()) {

            fila++;

            QString nombres             = query.value(6).toString();
            QString primer_apellido     = query.value(7).toString();
            QString segundo_apellido    = query.value(8).toString();
            QString fecha_de_nacimiento = query.value(13).toString();
            QString sexo                = query.value(9).toString();

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
        QMessageBox::information(this, "Error", "No se pudo establecer una conexion con la base de datos");
    }
}

void FormIndexUsuarios::on_btn_refresh_clicked()
{
    this->refresh_table();
}

