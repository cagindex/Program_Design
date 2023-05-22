#include "mywidget.h"
#include "ui_mywidget.h"
#include <QPixmap>
#include <QMovie>
/*toolbox用法
http://blog.csdn.net/liang19890820/article/details/52439711
*/
MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    ui->frame->setFrameShape(QFrame::Box);
    ui->frame->setFrameShadow(QFrame::Sunken);
    // 以上两个函数可以使用setFrameStyle(QFrame::Box | QFrame::Sunken)代替
    ui->frame->setLineWidth(5);
    ui->frame->setMidLineWidth(10);

    QFont font;
    font.setFamily("华文行楷");
    font.setPointSize(20);
    font.setBold(true);
    font.setItalic(true);

    ui->label->setFont(font);

    QString string = "标题太长，需要进行省略！";
    QString str = ui->label->
fontMetrics().elidedText(string, Qt::ElideRight, 180);
    ui->label->setText(str);


    QLabel * pLabel = new QLabel();
    pLabel->setText ("good");
    ui->toolBox->addItem(pLabel,"hello");



    /*
    ui->label->setPixmap(QPixmap("E:/logo.png"));

    QMovie *movie = new QMovie("E:/donghua.gif");
    ui->label->setMovie(movie);                  // 在标签中添加动画
    movie->start();
    */

}

MyWidget::~MyWidget()
{
    delete ui;
}
