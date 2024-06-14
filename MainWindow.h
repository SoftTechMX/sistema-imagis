#include <QApplication>
#include <QMainWindow>
#include <QDesktopWidget>
#include <QScreen>
#include <QMessageBox>

#include <QVBoxLayout>
#include <QDebug>

#include "FormIndexUsuarios.h"
#include "FormIndexProducto.h"
#include "FormUpdateLicencia.h"
#include "FormShowLicencia.h"

#include "Config.h"

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    private:
        Ui::MainWindow *ui;
        QGroupBox *vista = nullptr;
        Config config;

    public:
        explicit MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    private:
        void limpiar_vista_actual();

    private slots:
        void on_action_gestion_de_usuarios_triggered();
        void on_action_reporte_triggered();
        void on_action_actualizar_software_triggered();
        void on_action_documentacion_triggered();
        void on_action_registrar_licencia_triggered();
        void on_action_consultar_estatus_triggered();
        void on_action_servidores_triggered();
        void on_action_configuracion_imagis_triggered();
        void on_action_modulos_imagis_triggered();
        void on_action_gestion_de_productos_triggered();
};

#endif // MAINWINDOW_H
