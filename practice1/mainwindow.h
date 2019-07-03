#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "phonebook.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    PhoneBook phBook;

private slots:
    void on_addButton_clicked();
    void on_removeButton_clicked();
    void on_searchButton_clicked();
    void on_showAllButton_clicked();

private:
    Ui::MainWindow *ui;
    enum Columns{
        NAME, NUMBER
    };
    void showFoundContacts(QString query);
};

#endif // MAINWINDOW_H
