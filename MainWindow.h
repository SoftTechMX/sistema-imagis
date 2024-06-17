#include <QApplication>
#include <QMainWindow>
#include <QDesktopWidget>
#include <QScreen>
#include <QMessageBox>

#include <QVBoxLayout>
#include <QDebug>

#include "FormIndexUsuarios.h"
#include "FormIndexDispositivos.h"
#include "FormIndexRecursos.h"
#include "FormIndexServidores.h"
#include "FormIndexModulo.h"
#include "FormIndexConfiguracion.h"
#include "FormIndexActulizar.h"

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

private slots:
        void on_action_gestion_de_usuarios_triggered();
        void on_action_gestion_de_dispositivo_triggered();
        void on_action_gestion_de_recursos_triggered();
        void on_action_modulos_imagis_triggered();
        void on_action_configuracion_imagis_triggered();
        void on_action_servidores_triggered();
        void on_action_registrar_licencia_triggered();
        void on_action_consultar_estatus_triggered();

        void on_action_reporte_general_triggered();
        void on_action_reporte_especifico_triggered();
        void on_action_documentacion_triggered();
        void on_action_actualizar_software_triggered();

private:
        void limpiar_vista_actual();
};

#endif // MAINWINDOW_H
