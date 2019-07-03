#include "removedialog.h"
#include "ui_removedialog.h"

RemoveDialog::RemoveDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RemoveDialog)
{
    ui->setupUi(this);
}

RemoveDialog::~RemoveDialog()
{
    delete ui;
}

void RemoveDialog::on_buttonBox_accepted()
{
    accept();
}

void RemoveDialog::on_buttonBox_rejected()
{
    reject();
}
