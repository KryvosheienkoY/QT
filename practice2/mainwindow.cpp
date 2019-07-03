#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QResizeEvent>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::resizeEvent(QResizeEvent *e)
{
    QString text;
    text.append(QString::number(e->size().width())).append(", ").append(QString::number(e->size().height()));
    ui->label->setText(text);
    ui->label->move(QPoint(e->size().width()/2-(ui->label->size().width()/2), e->size().height()/2-(ui->label->size().height()/2)));
    QMainWindow::resizeEvent(e);
}
