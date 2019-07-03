#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "adddialog.h"
#include "removedialog.h"
#include "QMessageBox"
#include <iostream>
#include <vector>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Phone Book");
    ui->table->setColumnCount(2);
    QStringList colTitles;
    colTitles<<"Name"<<"Number";
    ui->table->setHorizontalHeaderLabels(colTitles);
    QHeaderView* header = ui->table ->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_addButton_clicked()
{
    AddDialog addD(this);
    addD.setWindowTitle("Adding contact");
    int res =addD.exec();
    // if cancel button was pushed
    if(res ==QDialog::Rejected)
    {
        return;
    }
    QString name =addD.getNameLine();
    QString num = addD.getNumLine();
    // checking that fields where filled correctly
    QRegExp re("\\d*");
    if ((!re.exactMatch(num) )|| num=="" || name==""){
        //open error window
        QMessageBox::warning(this, "Error","Invalid contact info! ");
        return;
    }
    //adding new contact
    phBook.addContact(Contact(name.toStdString(),num.toStdString()));
    ui->table->insertRow(ui->table->rowCount());
    int row = ui->table->rowCount()-1;
    ui->table->setItem(row,NAME,new QTableWidgetItem(name));
    ui->table->setItem(row,NUMBER,new QTableWidgetItem(num));
}

void MainWindow::on_removeButton_clicked()
{
    RemoveDialog removeD (this);
    removeD.setWindowTitle("Removing contact");
    int res =removeD.exec();
    // if cancel button was pushed
    if(res ==QDialog::Rejected)
    {
        return;
    }
    //removing selected row
    int current = ui->table->currentRow();
    if(current>-1){
        QString name= ui->table->itemAt(0,current)->text();
        QString num= ui->table->itemAt(1,current)->text();
        phBook.removeContact(Contact(name.toStdString(),num.toStdString()));
        ui->table->removeRow(current);
    }
}

void MainWindow::showFoundContacts(QString query)
{
    vector<Contact> res;
    //if query is empty, show all contacts
    if(query!="")
        res=phBook.findContact(query.toStdString());
    else
        res = phBook.getAllContacts();
    //clean table
    ui->table->clear();
    ui->table->setRowCount(0);
    QStringList colTitles;
    colTitles<<"Name"<<"Number";
    ui->table->setHorizontalHeaderLabels(colTitles);
    //fill table with results
    for (std::vector<Contact>::iterator it = res.begin() ; it != res.end(); ++it)
    {
        ui->table->insertRow(ui->table->rowCount());
        int row = ui->table->rowCount()-1;
        Contact c = *it;
        ui->table->setItem(row,NAME,new QTableWidgetItem(QString::fromStdString(c._name)));
        ui->table->setItem(row,NUMBER,new QTableWidgetItem(QString::fromStdString(c._number)));

    }
}

void MainWindow::on_searchButton_clicked()
{
    QString query = ui->searchBar->text();
    showFoundContacts(query);
}

void MainWindow::on_showAllButton_clicked()
{
    showFoundContacts("");
}
