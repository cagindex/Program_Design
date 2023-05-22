#include "mywidget.h"
#include "ui_mywidget.h"

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    // 设置时间为现在的系统时间
    ui->dateTimeEdit->setDateTime
            (QDateTime::currentDateTime());
    // 设置时间的显示格式
    ui->dateTimeEdit->setDisplayFormat
            (tr("yyyy年MM月dd日ddd HH时mm分ss秒"));
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::on_spinBox_valueChanged(int arg1)
{
    ui->lbInfo->setText(QString::number(arg1));
}



void MyWidget::on_btSummary_clicked()
{
    QString s = QString("spinBox:") +
            QString::number(ui->spinBox->value()) + "\n";
    s += "timeEdit:" + ui->timeEdit->text() + "\n";
    QDateTime tm = ui->timeEdit->dateTime();
    s += "timeEdit:" + QString::number(tm.time().hour()) + "\n";
    tm = ui->dateEdit->dateTime();
    s += "dateEdit:" + QString::number(tm.date().month()) + "\n";
    ui->lbInfo->setText(s);


}

void MyWidget::on_spinBox_editingFinished()
{

}
