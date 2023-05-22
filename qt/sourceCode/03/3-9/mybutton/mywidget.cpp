#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDebug>
#include <QMenu>
#include <string>
#include <QMessageBox>


MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{


    ui->setupUi(this);

    ui->pushBtn1->setText(tr("&nihao"));
    // 这样便指定了Alt+N为加速键

    ui->pushBtn2->setText(tr("帮助(&H)"));
    ui->pushBtn2->setIcon(
      QIcon("../mybutton/images/help.png"));

    rbStatus[0] = ui->rbStatusGood;
    rbStatus[1] = ui->rbStatusSoso;
    rbStatus[2] = ui->rbStatusBad;
    for(int i = 0;i < 3; ++i)
        connect(rbStatus[i],SIGNAL(clicked()),this,SLOT(on_rbStatus_clicked()));

    ckSports[0] = ui->ckRun;
    ckSports[1] = ui->ckSocer;
    ckSports[2] = ui->ckSwim;
    for(int i = 0;i < 3; ++i)
        connect(ckSports[i],SIGNAL(clicked(bool)),this,SLOT(on_ckSports_clicked(bool)));


    ui->pushBtn3->setText(tr("z&oom"));
    QMenu *menu = new QMenu(this);

    act[0] = new QAction(QIcon("../mybutton/images/zoom-in.png"), tr("放大"),this);
    act[0]->setShortcut(tr("Ctrl+Q"));
    act[0]->setStatusTip(tr("放大一下"));

    act[1]= new QAction(QIcon("../mybutton/images/zoom-in.png"), tr("缩小"),this);
    act[1]->setShortcut(tr("Ctrl+M"));
    act[1]->setStatusTip(tr("缩小一下"));

    for(int i = 0;i < 2; ++i) {
        menu->addAction(act[i]);
        connect(act[i], SIGNAL(triggered()), this, SLOT(menuAction()));
    }

    //menu->addAction(QIcon("../mybutton/images/zoom-in.png"), tr("缩小"));
    ui->pushBtn3->setMenu(menu);




}

MyWidget::~MyWidget()
{
    delete ui;

    for(int i = 0;i < 2; ++i)
        delete act[i];
}

void MyWidget::on_pushBtn1_toggled(bool checked)
{
    qDebug() << tr("按钮是否按下：") << checked;
}

void MyWidget::on_btSummary_clicked()
{
    QString s = "选中的checkbox:";
    for(int i = 0;i < 3; ++i)
        if( ckSports[i]->isChecked())
            s += ckSports[i]->objectName()+" ";
    s+= "\n选中的radiobutton:";
    for(int i = 0;i < 3; ++i)
        if( rbStatus[i]->isChecked())
            s += rbStatus[i]->objectName() + " ";
    ui->lbInfo->setText(s);



}

void MyWidget::on_rbStatus_clicked()
{
//QList<QCheckBox *> allCheckboxs= parentWidget.findChildren<QCheckBox *>();
    QRadioButton * rb = (QRadioButton*)
            this->sender();
    std::string objName =
            rb->objectName().toStdString();
    QString str =QString::fromStdString(objName);
    qDebug()<<str; //打印事件源头对象名称

    for(int i = 0;i < 3; ++i) {
        if( rb == rbStatus[i])
            ui->lbInfo->
                    setText(QString("第") + QString::number(i) + "个radiobutton:" + rb->objectName() + "选中");
    }
}

void MyWidget::on_ckSports_clicked(bool checked)
{
    QCheckBox * ck = (QCheckBox*) this->sender();
    for(int i = 0;i < 3; ++i) {
        if( ck == ckSports[i]) {
            if( checked )
                ui->lbInfo->setText(QString("第") + QString::number(i) + "个checkbox:" + ck->objectName() + "选中");
            else
                ui->lbInfo->setText(QString("第") + QString::number(i) + "个checkbox:" + ck->objectName() + "未选中");
        }
    }
}

void MyWidget::on_btCheck_clicked()
{
    if (ui->ckRun->checkState() ==
            Qt::PartiallyChecked )
        ui->ckRun->setCheckState(Qt::Checked);
}

void MyWidget::menuAction()
{
    QAction * act = (QAction * ) this->sender();
    QMessageBox::information(this, tr("提示对话框"),
     act->iconText(), QMessageBox::Ok);

}
