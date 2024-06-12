#include "flogin.h"
#include "MainWindow.h"


#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication aplicacion(argc, argv);

    MainWindow ventanaLogin;
    ventanaLogin.show();

    return aplicacion.exec();
}
