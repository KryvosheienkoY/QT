/********************************************************************************
** Form generated from reading UI file 'adddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDDIALOG_H
#define UI_ADDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_AddDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *nameLine;
    QLineEdit *numberLine;

    void setupUi(QDialog *AddDialog)
    {
        if (AddDialog->objectName().isEmpty())
            AddDialog->setObjectName(QStringLiteral("AddDialog"));
        AddDialog->resize(497, 234);
        buttonBox = new QDialogButtonBox(AddDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(20, 180, 451, 34));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(AddDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 50, 91, 31));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label_2 = new QLabel(AddDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 110, 121, 31));
        label_2->setFont(font);
        nameLine = new QLineEdit(AddDialog);
        nameLine->setObjectName(QStringLiteral("nameLine"));
        nameLine->setGeometry(QRect(170, 50, 231, 31));
        numberLine = new QLineEdit(AddDialog);
        numberLine->setObjectName(QStringLiteral("numberLine"));
        numberLine->setGeometry(QRect(170, 114, 231, 31));

        retranslateUi(AddDialog);

        QMetaObject::connectSlotsByName(AddDialog);
    } // setupUi

    void retranslateUi(QDialog *AddDialog)
    {
        AddDialog->setWindowTitle(QApplication::translate("AddDialog", "Dialog", 0));
        label->setText(QApplication::translate("AddDialog", "Name: ", 0));
        label_2->setText(QApplication::translate("AddDialog", "Number: ", 0));
    } // retranslateUi

};

namespace Ui {
    class AddDialog: public Ui_AddDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDDIALOG_H
