#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>
#include <memory>
namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    QRadioButton *rbStatus[3];
    QCheckBox *ckSports[3];
    //std::shared_ptr<QAction>  act[2];
    QAction  * act[2];

    explicit MyWidget(QWidget *parent = 0);
    ~MyWidget();

private slots:
    void on_pushBtn1_toggled(bool checked);

    void on_btSummary_clicked();

    void on_rbStatus_clicked();
    void on_ckSports_clicked(bool);


    void on_btCheck_clicked();

    void menuAction();


    void on_radioButton_5_clicked();

private:
    Ui::MyWidget *ui;
};

#endif // MYWIDGET_H
