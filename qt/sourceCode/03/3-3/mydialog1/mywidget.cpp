#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDialog>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this); //必须照抄，建里窗口和界面的关系
    QDialog *dialog = new QDialog(this);

    dialog->setModal(true); //模态对话框，即关闭前不能和其他窗口交互的对话框
    //dialog->setModal(false); //非模态对话框，即关闭前可以和其他窗口交互的对话框
    dialog->show();  //导致MyWidget窗口显示后，立即弹出对话框。show函数立即返回，MyWidget窗口才可以显示

    /*
     setWindowModality()函数可以设置对话框要阻塞的窗口类型,可以为：

     Qt::NonModal     不阻塞任何窗口，即非模态
     Qt::WindowModal  阻塞所有祖先窗口及其子窗口
     Qt::ApplicationModal 阻塞整个应用程序所有窗口
      */

}

MyWidget::~MyWidget()
{
    delete ui;
}
