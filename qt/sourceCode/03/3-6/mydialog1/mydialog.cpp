#include "mydialog.h"
#include "ui_mydialog.h"
#include "newdialog.h"

MyDialog::MyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyDialog)
{
    ui->setupUi(this);
}

MyDialog::~MyDialog()
{
    delete ui;
}

void MyDialog::on_pushButton_clicked()
{
    accept();
    //也可以通过 按F4进入信号和槽编辑状态，拖动 pushButton到对话框窗体，
    //然后添加 clicked() - accept槽
}

void MyDialog::on_pushButton_2_clicked()
{
    ui->pushButton_2->setText("fasfsdf");
    close();
}

void MyDialog::on_btShowNewDialog_clicked()
{
    NewDialog dlg;

    dlg.exec();
}
