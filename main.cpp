#include "LoginWindow.h"
#include "MainWindow.h"

#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication aplicacion(argc, argv);

    MainWindow ventanaLogin;
    ventanaLogin.show();

    return aplicacion.exec();
}
