#ifndef ADDDIALOG_H
#define ADDDIALOG_H
#include<iostream>
#include <QDialog>
using namespace std;

namespace Ui {
class AddDialog;
}

class AddDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddDialog(QWidget *parent = 0);
    ~AddDialog();
    QString getNameLine();
    QString getNumLine();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::AddDialog *ui;
};

#endif // ADDDIALOG_H
