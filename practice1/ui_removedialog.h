/********************************************************************************
** Form generated from reading UI file 'removedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REMOVEDIALOG_H
#define UI_REMOVEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_RemoveDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;

    void setupUi(QDialog *RemoveDialog)
    {
        if (RemoveDialog->objectName().isEmpty())
            RemoveDialog->setObjectName(QStringLiteral("RemoveDialog"));
        RemoveDialog->resize(503, 173);
        buttonBox = new QDialogButtonBox(RemoveDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(140, 110, 233, 34));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(RemoveDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 40, 461, 51));
        QFont font;
        font.setPointSize(11);
        label->setFont(font);

        retranslateUi(RemoveDialog);

        QMetaObject::connectSlotsByName(RemoveDialog);
    } // setupUi

    void retranslateUi(QDialog *RemoveDialog)
    {
        RemoveDialog->setWindowTitle(QApplication::translate("RemoveDialog", "Dialog", 0));
        label->setText(QApplication::translate("RemoveDialog", "Are you sure you want to remove this contact?", 0));
    } // retranslateUi

};

namespace Ui {
    class RemoveDialog: public Ui_RemoveDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMOVEDIALOG_H
