#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
//生成项目的时候指定从QWidet派生，就会这样
namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = 0);
    ~MyWidget();

private:
    Ui::MyWidget *ui;
};

#endif // MYWIDGET_H
