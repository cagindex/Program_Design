#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>
//生成项目的时候指定从QDialog派生，就会这样
namespace Ui {
class MyDialog;
}

class MyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MyDialog(QWidget *parent = 0);
    ~MyDialog();

private:
    Ui::MyDialog *ui;
};

#endif // MYDIALOG_H
