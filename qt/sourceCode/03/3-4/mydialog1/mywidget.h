#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

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

//下面这些函数都是自己手动写的
public slots:
    void showChildDialog(); //槽，即事件响应函数
    void on_pushButton_clicked();

private slots:
    void on_mybutton_clicked();
    void on_btNewy_clicked();
};

#endif // MYWIDGET_H
