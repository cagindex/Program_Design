#include <QApplication>
#include <QWidget>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget widget;
    widget.resize(400, 300);       // 设置窗口大小，此大小不含边框
    widget.move(200, 100);         // 设置窗口位置,此位置包括边框
    widget.show();
    int x = widget.x();            //包括边框
    qDebug("x: %d", x);            // 输出x的值
    int y = widget.y();            //包括边框
    qDebug("y: %d", y);
    QRect geometry = widget.geometry();     //用户区，不含边框
    QRect frame = widget.frameGeometry();   //整个窗口，包含边框
    qDebug() << "geometry: " << geometry << "frame: " << frame;

    qDebug() << "width:" << widget.width() << endl; //用户区，不含边框
    qDebug() << "height:" << widget.height() << endl;  //用户区，不含边框
    qDebug() << "pos:" << widget.pos() << endl; //整个窗口，包含边框

    widget.resize(500,600) ; //重设宽和高。用户区，不含边框

    return a.exec();
}
