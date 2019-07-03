/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAdd;
    QWidget *centralWidget;
    QPushButton *addButton;
    QPushButton *removeButton;
    QLineEdit *searchBar;
    QPushButton *searchButton;
    QTableWidget *table;
    QPushButton *showAllButton;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(541, 519);
        actionAdd = new QAction(MainWindow);
        actionAdd->setObjectName(QStringLiteral("actionAdd"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        addButton = new QPushButton(centralWidget);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setGeometry(QRect(390, 100, 112, 34));
        removeButton = new QPushButton(centralWidget);
        removeButton->setObjectName(QStringLiteral("removeButton"));
        removeButton->setGeometry(QRect(390, 150, 112, 34));
        searchBar = new QLineEdit(centralWidget);
        searchBar->setObjectName(QStringLiteral("searchBar"));
        searchBar->setGeometry(QRect(20, 40, 341, 31));
        searchBar->setAutoFillBackground(false);
        searchBar->setClearButtonEnabled(false);
        searchButton = new QPushButton(centralWidget);
        searchButton->setObjectName(QStringLiteral("searchButton"));
        searchButton->setGeometry(QRect(390, 40, 112, 34));
        table = new QTableWidget(centralWidget);
        table->setObjectName(QStringLiteral("table"));
        table->setEnabled(true);
        table->setGeometry(QRect(20, 100, 341, 361));
        table->setAutoScroll(true);
        showAllButton = new QPushButton(centralWidget);
        showAllButton->setObjectName(QStringLiteral("showAllButton"));
        showAllButton->setGeometry(QRect(390, 200, 112, 34));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionAdd->setText(QApplication::translate("MainWindow", "Add", 0));
        addButton->setText(QApplication::translate("MainWindow", "Add", 0));
        removeButton->setText(QApplication::translate("MainWindow", "Remove", 0));
        searchButton->setText(QApplication::translate("MainWindow", "Search", 0));
        showAllButton->setText(QApplication::translate("MainWindow", "Show all", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
