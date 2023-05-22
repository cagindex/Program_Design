#include <QtWidgets>
#include <mydialog1.h>
//本程序用来演示不用界面文件如何创建窗口
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 新建QWidget类对象，默认parent参数是0，所以它是个窗口
    //QWidget *widget = new QWidget(0,
    //Qt::Dialog | Qt::FramelessWindowHint);
    QWidget *widget = new QWidget();
    // 设置窗口标题
    widget->setWindowTitle(QObject::tr("我是widget"));
    // 新建QLabel对象，默认parent参数是0，所以它是个窗口
    QLabel *label = new QLabel(0, Qt::SplashScreen |
                               Qt::WindowStaysOnTopHint);
    label->setWindowTitle(QObject::tr("我是label"));
    // 设置要显示的信息
    label->setText(QObject::tr("label:我是个窗口"));
    // 改变部件大小，以便能显示出完整的内容
    label->resize(380, 80);
    // label2指定了父窗口为widget，所以不是窗口
    QLabel *label2 = new QLabel(widget);
    label2->setText(QObject::tr("label2:我不是独立窗口，只是widget的子部件"));
    label2->resize(350, 30);
    // 在屏幕上显示出来
    label->show();
    widget->show();  //widget默认大小：正好包含 label2
    //再加一个窗口，则两个带标题栏的窗口都关闭时，程序结束
    QWidget *widget2 = new QWidget();
    // 设置窗口标题
    widget2->setWindowTitle(QObject::tr("我是widget2"));
    widget2->show();
    MyDialog1 * dlg = new MyDialog1();
    dlg->show();


    //*/


    int ret = a.exec();
    delete label;
    delete widget;  //自动delete widget的子对象 label2
    delete widget2;
    return ret;
}




























