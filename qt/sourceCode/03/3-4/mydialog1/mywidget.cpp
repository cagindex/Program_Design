#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDialog>
#include "mydialog.h"

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    connect(ui->showChildButton, &QPushButton::clicked,
            this, &MyWidget::showChildDialog);
    //connect是QObject成员函数 各种类都继承 QObject
    //手动关联信号和槽
    //指定 ui->showChildButton按钮上面的 clicked事件，
    //将由本对象的 showChildDialog响应
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::showChildDialog()
{
    QDialog *dialog = new QDialog(this);
    dialog->show();  //弹出非模态对话框
}

void MyWidget::on_pushButton_clicked()
{
    ui->label->setText("ok");
}

void MyWidget::on_mybutton_clicked()
{
     MyDialog * pd = new MyDialog(this);
     pd->show();
}

void MyWidget::on_btNewy_clicked()
{
    ui->label->setText("btnew clicked");
}

