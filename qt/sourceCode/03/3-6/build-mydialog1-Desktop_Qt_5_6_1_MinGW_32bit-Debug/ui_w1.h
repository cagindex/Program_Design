/********************************************************************************
** Form generated from reading UI file 'w1.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_W1_H
#define UI_W1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_w1
{
public:

    void setupUi(QWidget *w1)
    {
        if (w1->objectName().isEmpty())
            w1->setObjectName(QStringLiteral("w1"));
        w1->resize(400, 300);

        retranslateUi(w1);

        QMetaObject::connectSlotsByName(w1);
    } // setupUi

    void retranslateUi(QWidget *w1)
    {
        w1->setWindowTitle(QApplication::translate("w1", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class w1: public Ui_w1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_W1_H
