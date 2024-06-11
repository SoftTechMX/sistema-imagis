#include "mainwindow.h"
#include "flogin.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication aplicacion(argc, argv);

    fLogin ventanaLogin;
    ventanaLogin.show();

    return aplicacion.exec();
}
