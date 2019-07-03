#include "adddialog.h"
#include "ui_adddialog.h"
#include <iostream>
using namespace std;

AddDialog::AddDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDialog)
{
    ui->setupUi(this);
}

AddDialog::~AddDialog()
{
    delete ui;
}

void AddDialog::on_buttonBox_accepted()
{
    accept();
}

void AddDialog::on_buttonBox_rejected()
{
    reject();
}

QString AddDialog::getNameLine()
{
    return ui->nameLine->text();
}

QString AddDialog::getNumLine()
{
  return ui->numberLine->text();
}
