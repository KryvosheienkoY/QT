/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *removeButton;
    QScrollBar *scrollBar;
    QPushButton *addButton;
    QLineEdit *searchBar;
    QPushButton *searchButton;
    QTableWidget *table;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(513, 489);
        removeButton = new QPushButton(Widget);
        removeButton->setObjectName(QStringLiteral("removeButton"));
        removeButton->setGeometry(QRect(380, 170, 112, 34));
        scrollBar = new QScrollBar(Widget);
        scrollBar->setObjectName(QStringLiteral("scrollBar"));
        scrollBar->setGeometry(QRect(330, 90, 21, 361));
        scrollBar->setMouseTracking(false);
        scrollBar->setOrientation(Qt::Vertical);
        scrollBar->setInvertedControls(true);
        addButton = new QPushButton(Widget);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setGeometry(QRect(380, 110, 112, 34));
        searchBar = new QLineEdit(Widget);
        searchBar->setObjectName(QStringLiteral("searchBar"));
        searchBar->setGeometry(QRect(10, 40, 341, 31));
        searchBar->setAutoFillBackground(false);
        searchBar->setClearButtonEnabled(false);
        searchButton = new QPushButton(Widget);
        searchButton->setObjectName(QStringLiteral("searchButton"));
        searchButton->setGeometry(QRect(380, 40, 112, 34));
        table = new QTableWidget(Widget);
        table->setObjectName(QStringLiteral("table"));
        table->setGeometry(QRect(10, 90, 321, 361));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Form", 0));
        removeButton->setText(QApplication::translate("Widget", "Remove", 0));
        addButton->setText(QApplication::translate("Widget", "Add", 0));
        searchButton->setText(QApplication::translate("Widget", "Search", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
