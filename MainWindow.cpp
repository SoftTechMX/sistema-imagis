#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QRect screenGeometry = QGuiApplication::primaryScreen()->geometry();
    int x = (screenGeometry.width() - width()) / 2;
    int y = (screenGeometry.height() - height()) / 2;
    move(x, y);

    // Asegúrate de que widgets_frame tenga un layout
    if (!ui->widgets_frame->layout()) {
        QVBoxLayout *layout = new QVBoxLayout(ui->widgets_frame);
        ui->widgets_frame->setLayout(layout);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::limpiar_vista_actual()
{
    QLayout* layout = ui->widgets_frame->layout();
    QLayoutItem* item;
    while ((item = layout->takeAt(0)) != nullptr) {
        delete item->widget();                          // Elimina el widget asociado
        delete item;                                    // Elimina el layout item
    }
}

void MainWindow::on_action_gestion_de_usuarios_triggered()
{
    this->limpiar_vista_actual();

    QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(ui->widgets_frame->layout());
    this->vista = new FormIndexUsuarios(ui->widgets_frame);
    layout->addWidget(vista);
}


void MainWindow::on_action_gestion_de_dispositivo_triggered()
{
    this->limpiar_vista_actual();

    QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(ui->widgets_frame->layout());
    this->vista = new FormIndexDispositivos(ui->widgets_frame);
    layout->addWidget(vista);
}


void MainWindow::on_action_gestion_de_recursos_triggered()
{
    this->limpiar_vista_actual();

    QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(ui->widgets_frame->layout());
    this->vista = new FormIndexRecursos(ui->widgets_frame);
    layout->addWidget(vista);
}


void MainWindow::on_action_modulos_imagis_triggered()
{
    this->limpiar_vista_actual();

    QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(ui->widgets_frame->layout());
    this->vista = new FormIndexModulos(ui->widgets_frame);
    layout->addWidget(vista);
}


void MainWindow::on_action_configuracion_imagis_triggered()
{
    this->limpiar_vista_actual();

    QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(ui->widgets_frame->layout());
    this->vista = new FormIndexConfiguracion(ui->widgets_frame);
    layout->addWidget(vista);
}


void MainWindow::on_action_servidores_triggered()
{
    this->limpiar_vista_actual();

    QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(ui->widgets_frame->layout());
    this->vista = new FormIndexServidores(ui->widgets_frame);
    layout->addWidget(vista);
}


void MainWindow::on_action_registrar_licencia_triggered()
{
    this->limpiar_vista_actual();

    QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(ui->widgets_frame->layout());
    this->vista = new FormUpdateLicencia(ui->widgets_frame);
    layout->addWidget(vista);
}


void MainWindow::on_action_consultar_estatus_triggered()
{
    this->limpiar_vista_actual();

    QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(ui->widgets_frame->layout());
    this->vista = new FormShowLicencia(ui->widgets_frame);
    layout->addWidget(vista);
}


void MainWindow::on_action_reporte_general_triggered()
{

}


void MainWindow::on_action_reporte_especifico_triggered()
{

}


void MainWindow::on_action_documentacion_triggered()
{

}


void MainWindow::on_action_actualizar_software_triggered()
{
    this->limpiar_vista_actual();

    QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(ui->widgets_frame->layout());
    this->vista = new FormIndexActulizar(ui->widgets_frame);
    layout->addWidget(vista);
}

