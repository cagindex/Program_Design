/********************************************************************************
** Form generated from reading UI file 'dialog2.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG2_H
#define UI_DIALOG2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog2
{
public:
    QPushButton *btOk;
    QPushButton *btCancel;

    void setupUi(QDialog *Dialog2)
    {
        if (Dialog2->objectName().isEmpty())
            Dialog2->setObjectName(QStringLiteral("Dialog2"));
        Dialog2->resize(400, 300);
        btOk = new QPushButton(Dialog2);
        btOk->setObjectName(QStringLiteral("btOk"));
        btOk->setGeometry(QRect(80, 140, 93, 28));
        btCancel = new QPushButton(Dialog2);
        btCancel->setObjectName(QStringLiteral("btCancel"));
        btCancel->setGeometry(QRect(260, 140, 93, 28));

        retranslateUi(Dialog2);
        QObject::connect(btOk, SIGNAL(clicked()), Dialog2, SLOT(accept()));
        QObject::connect(btCancel, SIGNAL(clicked()), Dialog2, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog2);
    } // setupUi

    void retranslateUi(QDialog *Dialog2)
    {
        Dialog2->setWindowTitle(QApplication::translate("Dialog2", "Dialog", 0));
        btOk->setText(QApplication::translate("Dialog2", "OK", 0));
        btCancel->setText(QApplication::translate("Dialog2", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog2: public Ui_Dialog2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG2_H
