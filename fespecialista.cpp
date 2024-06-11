#include "fespecialista.h"
#include "ui_fespecialista.h"

fEspecialista::fEspecialista(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::fEspecialista)
{
    ui->setupUi(this);
}

fEspecialista::~fEspecialista()
{
    delete ui;
}
