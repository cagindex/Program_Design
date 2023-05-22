/********************************************************************************
** Form generated from reading UI file 'mydialog1.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYDIALOG1_H
#define UI_MYDIALOG1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_MyDialog1
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *MyDialog1)
    {
        if (MyDialog1->objectName().isEmpty())
            MyDialog1->setObjectName("MyDialog1");
        MyDialog1->resize(400, 300);
        buttonBox = new QDialogButtonBox(MyDialog1);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(250, 30, 81, 241));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(MyDialog1);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, MyDialog1, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, MyDialog1, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(MyDialog1);
    } // setupUi

    void retranslateUi(QDialog *MyDialog1)
    {
        MyDialog1->setWindowTitle(QCoreApplication::translate("MyDialog1", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyDialog1: public Ui_MyDialog1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYDIALOG1_H
