#include "mywidget.h"
#include "ui_mywidget.h"

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    //dail的 tracking被设置为true,
    //导致拖动鼠标每移动一个刻度，都会发生 valueChanged()事件
    //notchesVisible
    //notchTarget  关于刻度
    ui->setupUi(this);
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::on_verticalSlider_valueChanged(int value)
{
    ui->dial->setValue(value);
    ui->horizontalSlider->setValue(value);
}

void MyWidget::on_dial_valueChanged(int value)
{

}
