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

private slots:
    void on_spinBox_valueChanged(int arg1);


    void on_btSummary_clicked();

    void on_spinBox_editingFinished();

private:
    Ui::MyWidget *ui;
};

#endif // MYWIDGET_H
