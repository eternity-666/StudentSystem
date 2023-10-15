#include "deldialog.h"
#include "ui_deldialog.h"

delDialog::delDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::delDialog)
{
    ui->setupUi(this);
}

delDialog::~delDialog()
{
    delete ui;
}
