#ifndef REMOVEDIALOG_H
#define REMOVEDIALOG_H

#include <QDialog>

namespace Ui {
class RemoveDialog;
}

class RemoveDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RemoveDialog(QWidget *parent = 0);
    ~RemoveDialog();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::RemoveDialog *ui;
};

#endif // REMOVEDIALOG_H
