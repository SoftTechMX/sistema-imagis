#ifndef FORMINDEXDISPOSITIVOS_H
#define FORMINDEXDISPOSITIVOS_H

#include <QGroupBox>

namespace Ui {
class FormIndexDispositivos;
}

class FormIndexDispositivos : public QGroupBox
{
    Q_OBJECT

public:
    explicit FormIndexDispositivos(QWidget *parent = nullptr);
    ~FormIndexDispositivos();

private:
    Ui::FormIndexDispositivos *ui;
};

#endif // FORMINDEXDISPOSITIVOS_H
