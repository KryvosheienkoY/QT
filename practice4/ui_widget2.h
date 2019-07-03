/********************************************************************************
** Form generated from reading UI file 'widget2.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET2_H
#define UI_WIDGET2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget2
{
public:
    QLabel *label;

    void setupUi(QWidget *Widget2)
    {
        if (Widget2->objectName().isEmpty())
            Widget2->setObjectName(QStringLiteral("Widget2"));
        Widget2->resize(400, 300);
        label = new QLabel(Widget2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 100, 68, 19));

        retranslateUi(Widget2);

        QMetaObject::connectSlotsByName(Widget2);
    } // setupUi

    void retranslateUi(QWidget *Widget2)
    {
        Widget2->setWindowTitle(QApplication::translate("Widget2", "Form", 0));
        label->setText(QApplication::translate("Widget2", "YULIA2", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget2: public Ui_Widget2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET2_H
