/********************************************************************************
** Form generated from reading UI file 'widget1.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET1_H
#define UI_WIDGET1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget1
{
public:
    QLabel *label;

    void setupUi(QWidget *Widget1)
    {
        if (Widget1->objectName().isEmpty())
            Widget1->setObjectName(QStringLiteral("Widget1"));
        Widget1->resize(400, 300);
        label = new QLabel(Widget1);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(90, 90, 71, 41));

        retranslateUi(Widget1);

        QMetaObject::connectSlotsByName(Widget1);
    } // setupUi

    void retranslateUi(QWidget *Widget1)
    {
        Widget1->setWindowTitle(QApplication::translate("Widget1", "Form", 0));
        label->setText(QApplication::translate("Widget1", "YULIA1", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget1: public Ui_Widget1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET1_H
