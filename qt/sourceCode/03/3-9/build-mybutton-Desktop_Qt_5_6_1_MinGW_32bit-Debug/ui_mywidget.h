/********************************************************************************
** Form generated from reading UI file 'mywidget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYWIDGET_H
#define UI_MYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyWidget
{
public:
    QPushButton *pushBtn1;
    QPushButton *pushBtn2;
    QPushButton *pushBtn3;
    QGroupBox *groupBox;
    QCheckBox *ckRun;
    QCheckBox *ckSocer;
    QCheckBox *ckSwim;
    QGroupBox *groupBox_2;
    QRadioButton *rbStatusGood;
    QRadioButton *rbStatusSoso;
    QRadioButton *rbStatusBad;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_5;
    QPushButton *btSummary;
    QLabel *lbInfo;
    QPushButton *btCheck;

    void setupUi(QWidget *MyWidget)
    {
        if (MyWidget->objectName().isEmpty())
            MyWidget->setObjectName(QStringLiteral("MyWidget"));
        MyWidget->resize(510, 454);
        pushBtn1 = new QPushButton(MyWidget);
        pushBtn1->setObjectName(QStringLiteral("pushBtn1"));
        pushBtn1->setGeometry(QRect(30, 20, 75, 23));
        pushBtn1->setCheckable(true);
        pushBtn2 = new QPushButton(MyWidget);
        pushBtn2->setObjectName(QStringLiteral("pushBtn2"));
        pushBtn2->setGeometry(QRect(150, 20, 101, 23));
        pushBtn2->setFlat(true);
        pushBtn3 = new QPushButton(MyWidget);
        pushBtn3->setObjectName(QStringLiteral("pushBtn3"));
        pushBtn3->setGeometry(QRect(270, 20, 121, 23));
        groupBox = new QGroupBox(MyWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 120, 141, 151));
        ckRun = new QCheckBox(groupBox);
        ckRun->setObjectName(QStringLiteral("ckRun"));
        ckRun->setGeometry(QRect(30, 30, 71, 16));
        ckRun->setTristate(true);
        ckSocer = new QCheckBox(groupBox);
        ckSocer->setObjectName(QStringLiteral("ckSocer"));
        ckSocer->setGeometry(QRect(30, 70, 71, 16));
        ckSwim = new QCheckBox(groupBox);
        ckSwim->setObjectName(QStringLiteral("ckSwim"));
        ckSwim->setGeometry(QRect(30, 110, 71, 16));
        groupBox_2 = new QGroupBox(MyWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(190, 120, 161, 151));
        rbStatusGood = new QRadioButton(groupBox_2);
        rbStatusGood->setObjectName(QStringLiteral("rbStatusGood"));
        rbStatusGood->setGeometry(QRect(30, 30, 89, 16));
        rbStatusSoso = new QRadioButton(groupBox_2);
        rbStatusSoso->setObjectName(QStringLiteral("rbStatusSoso"));
        rbStatusSoso->setGeometry(QRect(30, 70, 89, 16));
        rbStatusBad = new QRadioButton(groupBox_2);
        rbStatusBad->setObjectName(QStringLiteral("rbStatusBad"));
        rbStatusBad->setGeometry(QRect(30, 110, 89, 16));
        radioButton_4 = new QRadioButton(MyWidget);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));
        radioButton_4->setGeometry(QRect(120, 70, 89, 16));
        radioButton_5 = new QRadioButton(MyWidget);
        radioButton_5->setObjectName(QStringLiteral("radioButton_5"));
        radioButton_5->setGeometry(QRect(240, 70, 89, 16));
        btSummary = new QPushButton(MyWidget);
        btSummary->setObjectName(QStringLiteral("btSummary"));
        btSummary->setGeometry(QRect(30, 70, 75, 23));
        btSummary->setCheckable(false);
        lbInfo = new QLabel(MyWidget);
        lbInfo->setObjectName(QStringLiteral("lbInfo"));
        lbInfo->setGeometry(QRect(20, 280, 461, 151));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\260\345\256\213\344\275\223"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        lbInfo->setFont(font);
        lbInfo->setWordWrap(true);
        btCheck = new QPushButton(MyWidget);
        btCheck->setObjectName(QStringLiteral("btCheck"));
        btCheck->setGeometry(QRect(360, 80, 75, 23));

        retranslateUi(MyWidget);

        QMetaObject::connectSlotsByName(MyWidget);
    } // setupUi

    void retranslateUi(QWidget *MyWidget)
    {
        MyWidget->setWindowTitle(QApplication::translate("MyWidget", "MyWidget", 0));
        pushBtn1->setText(QApplication::translate("MyWidget", "PushButton", 0));
        pushBtn2->setText(QApplication::translate("MyWidget", "PushButton", 0));
        pushBtn3->setText(QApplication::translate("MyWidget", "menu button", 0));
        groupBox->setTitle(QApplication::translate("MyWidget", "\345\244\215\351\200\211\346\241\206", 0));
        ckRun->setText(QApplication::translate("MyWidget", "\350\267\221\346\255\245", 0));
        ckSocer->setText(QApplication::translate("MyWidget", "\350\270\242\347\220\203", 0));
        ckSwim->setText(QApplication::translate("MyWidget", "\346\270\270\346\263\263", 0));
        groupBox_2->setTitle(QApplication::translate("MyWidget", "\345\215\225\351\200\211\346\241\206", 0));
        rbStatusGood->setText(QApplication::translate("MyWidget", "\345\276\210\345\245\275", 0));
        rbStatusSoso->setText(QApplication::translate("MyWidget", "\344\270\200\350\210\254", 0));
        rbStatusBad->setText(QApplication::translate("MyWidget", "\344\270\215\345\245\275", 0));
        radioButton_4->setText(QApplication::translate("MyWidget", "RadioButton", 0));
        radioButton_5->setText(QApplication::translate("MyWidget", "RadioButton", 0));
        btSummary->setText(QApplication::translate("MyWidget", "Summary", 0));
        lbInfo->setText(QApplication::translate("MyWidget", "TextLabel", 0));
        btCheck->setText(QApplication::translate("MyWidget", "Check", 0));
    } // retranslateUi

};

namespace Ui {
    class MyWidget: public Ui_MyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWIDGET_H
