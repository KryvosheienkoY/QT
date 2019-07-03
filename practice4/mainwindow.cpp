#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    string names1 [] = {"Andrew", "Peter", "John", "Jake"};
    string names2 [] = {"Jessica", "Sara", "Eve", "Jane"};
    for (int i=0; i<4;i++) {
         ui->listWidget_1->addItem(QString::fromStdString(names1[i]));
    }
    for (int i=0; i<4;i++) {
         ui->listWidget_2->addItem(QString::fromStdString(names2[i]));
    }
    ui->listWidget_1->setSelectionMode(QAbstractItemView::SingleSelection);
            ui->listWidget_1->setDragEnabled(true);
            ui->listWidget_1->setDragDropMode(QAbstractItemView::DragDrop);
            ui->listWidget_1->viewport()->setAcceptDrops(true);
            ui->listWidget_1->setDropIndicatorShown(true);
            ui->listWidget_1->setDefaultDropAction(Qt::MoveAction);

            ui->listWidget_2->setSelectionMode(QAbstractItemView::SingleSelection);
            ui->listWidget_2->setDragEnabled(true);
            ui->listWidget_2->setDragDropMode(QAbstractItemView::DragDrop);
            ui->listWidget_2->viewport()->setAcceptDrops(true);
            ui->listWidget_2->setDropIndicatorShown(true);
            ui->listWidget_2->setDefaultDropAction(Qt::MoveAction);
}
MainWindow::~MainWindow()
{
    delete ui;
}
