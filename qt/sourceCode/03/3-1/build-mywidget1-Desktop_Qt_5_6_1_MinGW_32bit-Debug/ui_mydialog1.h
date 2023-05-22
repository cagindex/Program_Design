/********************************************************************************
** Form generated from reading UI file 'mydialog1.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYDIALOG1_H
#define UI_MYDIALOG1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_MyDialog1
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *MyDialog1)
    {
        if (MyDialog1->objectName().isEmpty())
            MyDialog1->setObjectName(QStringLiteral("MyDialog1"));
        MyDialog1->resize(400, 300);
        buttonBox = new QDialogButtonBox(MyDialog1);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(250, 30, 81, 241));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(MyDialog1);
        QObject::connect(buttonBox, SIGNAL(accepted()), MyDialog1, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), MyDialog1, SLOT(reject()));

        QMetaObject::connectSlotsByName(MyDialog1);
    } // setupUi

    void retranslateUi(QDialog *MyDialog1)
    {
        MyDialog1->setWindowTitle(QApplication::translate("MyDialog1", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class MyDialog1: public Ui_MyDialog1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYDIALOG1_H
