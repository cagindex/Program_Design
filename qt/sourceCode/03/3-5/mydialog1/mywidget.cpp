#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDialog>
#include "dialog2.h"

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::on_showChildButton_clicked()
{
    QDialog *dialog = new QDialog(this);
    dialog->show();
}

void MyWidget::on_btModify_clicked()
{
    ui->myLabel->setText("改了!");
    Dialog2 dlg2;
    if(dlg2.exec() == QDialog:: Accepted)
        close();

}
