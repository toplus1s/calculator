#include "widget.h"
#include "ui_widget.h"
#include <QMouseEvent>
#include <QPoint>
#include <QDebug>
#include <QTimer>
#include <QTime>
#include <QPaintEvent>
#include <QPainter>
#include <QSystemTrayIcon>
#include <QAction>
#include <QMenu>
#include <QDialog>
#include <QMessageBox>
#include <QProcess>
#include <QSplashScreen>
#include <synchapi.h>
#include <QKeyEvent>
#include <QScrollBar>
#include <QLineEdit>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    startAnimation();
    myTrayIcon();
    ui->setupUi(this);
    ui->hourh->setIconSize(QSize(20,40));
    ui->hourl->setIconSize(QSize(20,40));
    ui->minh->setIconSize(QSize(20,40));
    ui->minl->setIconSize(QSize(20,40));
    ui->sech->setIconSize(QSize(20,40));
    ui->secl->setIconSize(QSize(20,40));
    ui->a->setStyleSheet("color:white");
    ui->b->setStyleSheet("color:white");
    ui->label->setStyleSheet("color:white");
    ui->input->setStyleSheet("background-color:rgba(255,255,255,30)");
    ui->help->setIconSize(QSize(41,41));
    ui->help->setIcon(QIcon("../icon/trayicon/wenhao.png"));
    ui->help->setStyleSheet("background-color:rgba(255,255,255,20)");
    connect(ui->help,SIGNAL(clicked()),this,SLOT(showInfoDlg()));
    ui->close->setIconSize(QSize(41,41));
    ui->close->setIcon(QIcon("../icon/trayicon/close.png"));
    ui->close->setStyleSheet("background-color:rgba(255,255,255,20)");
    connect(ui->close,SIGNAL(clicked()),qApp,SLOT(quit()));
    ui->x->setStyleSheet("background-color:rgba(255,255,255,20)");
    ui->enter->setStyleSheet("background-color:rgba(255,255,255,20)");
    ui->res->setStyleSheet("background-color:rgba(255,255,255,20)");
    ui->point->setStyleSheet("background-color:rgba(255,255,255,20)");
    ui->q0->setStyleSheet("background-color:rgba(255,255,255,20)");
    ui->q9->setStyleSheet("background-color:rgba(255,255,255,20)");
    ui->q8->setStyleSheet("background-color:rgba(255,255,255,20)");
    ui->q7->setStyleSheet("background-color:rgba(255,255,255,20)");
    ui->q6->setStyleSheet("background-color:rgba(255,255,255,20)");
    ui->q5->setStyleSheet("background-color:rgba(255,255,255,20)");
    ui->q4->setStyleSheet("background-color:rgba(255,255,255,20)");
    ui->q3->setStyleSheet("background-color:rgba(255,255,255,20)");
    ui->q2->setStyleSheet("background-color:rgba(255,255,255,20)");
    ui->q1->setStyleSheet("background-color:rgba(255,255,255,20)");
    ui->backspace->setStyleSheet("background-color:rgba(255,255,255,20)");
    ui->ax->setStyleSheet("background-color:rgba(255,255,255,20)");
    ui->amb->setStyleSheet("background-color:rgba(255,255,255,20)");
    ui->apb->setStyleSheet("background-color:rgba(255,255,255,20)");
    ui->clear->setStyleSheet("background-color:rgba(255,255,255,20)");
    ui->plus->setStyleSheet("background-color:rgba(255,255,255,20)");
    ui->minus->setStyleSheet("background-color:rgba(255,255,255,20)");
    ui->square->setStyleSheet("background-color:rgba(255,255,255,20)");
    ui->showa->setStyleSheet("background-color:rgba(255,255,255,30)");
    ui->showa->text() = "";
    ui->showb->setStyleSheet("background-color:rgba(255,255,255,30)");
    ui->showb->text() = "";
    ui->showc->setStyleSheet("background-color:rgba(255,255,255,30)");
    ui->showc->text() = "";
    ui->Ax->setStyleSheet("background-color:rgba(255,255,255,30)");
    ui->Bx->setStyleSheet("background-color:rgba(255,255,255,30)");
    ui->Cx->setStyleSheet("background-color:rgba(255,255,255,30)");

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start(1000);
    showTime();
}


Widget::~Widget()
{
    delete ui;
}



void Widget::mousePressEvent(QMouseEvent *e)
{

    if(e->button() == Qt::LeftButton)
    {
        m_point = e->globalPos() - pos();
        e->accept();
    }
}



void Widget::mouseMoveEvent(QMouseEvent *e)
{
    if(e->buttons() & Qt::LeftButton)
    {
        move(e->globalPos() - m_point);
        e->accept();
    }
}






void Widget::showTime()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm:ss");
    ui->hourh->setIcon(QPixmap(this->getPngName(text[0])));
    ui->hourl->setIcon(QPixmap(this->getPngName(text[1])));
    ui->minh->setIcon(QPixmap(this->getPngName(text[3])));
    ui->minl->setIcon(QPixmap(this->getPngName(text[4])));
    ui->sech->setIcon(QPixmap(this->getPngName(text[6])));
    ui->secl->setIcon(QPixmap(this->getPngName(text[7])));
}

QString Widget::getPngName(QChar x)
{
     return "../icon/time/"+(x+QString(".png") );
}


void Widget::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.fillRect(this->rect(), QColor(255, 255, 255, 50));
}





void Widget::myTrayIcon()
{
        //创建并设置动作
    minAction = new QAction(this);
    minAction->setText("最小化");
    minAction->setIcon(QIcon("../icon/trayicon/min.png"));
    connect(minAction,SIGNAL(triggered()),this,SLOT(hide()));


    restoreAction = new QAction(this);
    restoreAction->setText("恢复");
    restoreAction->setIcon(QIcon("../icon/trayicon/restore.png"));
    connect(restoreAction,SIGNAL(triggered()),this,SLOT(showNormal()));


    aboutAction = new QAction(this);
    aboutAction->setText("关于");
    aboutAction->setIcon(QIcon("../icon/trayicon/about.png"));
    connect(aboutAction,SIGNAL(triggered()),this,SLOT(showaboutDlg()));


    configAction = new QAction(this);
    configAction->setText("帮助");
    configAction->setIcon(QIcon("../icon/trayicon/help.ico"));
    connect(configAction,SIGNAL(triggered()),this,SLOT(showInfoDlg()));


    quitAction = new QAction(this);
    quitAction->setText("退出");
    quitAction->setIcon(QIcon("../icon/trayicon/quit.png"));
    connect(quitAction,SIGNAL(triggered()),this,SLOT(quitWindowAnimation()));



    trayIconMenu = new QMenu(this);
    trayIconMenu->addAction(restoreAction);
    trayIconMenu->addAction(minAction);
    trayIconMenu->addSeparator();
    trayIconMenu->addAction(configAction);
    trayIconMenu->addAction(aboutAction);
    trayIconMenu->addSeparator();
    trayIconMenu->addAction(quitAction);



    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setContextMenu(trayIconMenu);
    trayIcon->setIcon(QIcon("../icon/myicon.ico"));
    trayIcon->show();
    trayIcon->showMessage("你好！","欢迎使用一元稀疏多项式计算器。",QSystemTrayIcon::Information,2000);
    trayIcon->setToolTip("一元稀疏多项式计算器");
    connect(trayIcon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(trayIconActivated(QSystemTrayIcon::ActivationReason)));
    connect(trayIcon, SIGNAL(messageClicked()), this, SLOT(trayIconMsgClicked()));
    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason)));

}





void Widget::quitWindowAnimation() //关闭窗口效果
{
    QPropertyAnimation *animation = new QPropertyAnimation(this,"windowOpacity");
    animation->setDuration(1000);
    animation->setStartValue(1);
    animation->setEndValue(0);
    animation->start();
    QTimer::singleShot(1000,qApp,SLOT(quit()));

}

void Widget::startAnimation()
{
    QPropertyAnimation *animation = new QPropertyAnimation(this,"windowOpacity");
    animation->setDuration(500);
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->start();

}





void Widget::on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason){
    case QSystemTrayIcon::Trigger:
    {
        startAnimation();
        this->showNormal();
        break;
    }
    case QSystemTrayIcon::DoubleClick:
    {
        //双击后显示主程序窗口
        this->showNormal();
        break;
    }
    default:
        break;
    }
}






void Widget::showaboutDlg()
{
    QString dlgTitle="一元稀疏多项式计算器 v1.0";
    QString strInfo="\n版本信息：一元稀疏多项式计算器 v1.0\n\n制作者：徐芷菡\n\n欢迎交流!邮箱：\n2083643604@qq.com";
    QMessageBox *box = new QMessageBox(QMessageBox::Information, dlgTitle, strInfo, QMessageBox::Ok);
    box->setModal(false);
    box->setWindowIcon(QIcon("../icon/myicon.ico"));
    box->setFixedSize(400,400);
    box->setIconPixmap(QPixmap(""));
    box->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);
    box->setStyleSheet("color:green");
    QApplication::setQuitOnLastWindowClosed(false);
    box->show();
}



void Widget::showInfoDlg()
{
    QString dlgTitle="帮助";
    QString strInfo="使用说明：\n主要就是不要乱点。\n本软件制作匆忙，\n没时间测试。\n非正常使用会出现bug是很正常的。";
    QMessageBox *box = new QMessageBox(QMessageBox::Warning, dlgTitle, strInfo, QMessageBox::Ok);
    box->setModal(false);
    box->setWindowIcon(QIcon("../icon/myicon.ico"));
    box->setIconPixmap(QPixmap(""));
    box->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);
    box->setStyleSheet("color:blue");
    QApplication::setQuitOnLastWindowClosed(false);
    box->show();
}







void Widget::on_q0_clicked()
{
    a+="0";
    ui->input->setText(a);
}

void Widget::on_x_clicked()
{
    a+="x";
    ui->input->setText(a);
}

void Widget::on_point_clicked()
{
    a+=".";
    ui->input->setText(a);
}

void Widget::on_q1_clicked()
{
    a+="1";
    ui->input->setText(a);
}

void Widget::on_q2_clicked()
{
    a+="2";
    ui->input->setText(a);
}

void Widget::on_q3_clicked()
{
    a+="3";
    ui->input->setText(a);
}

void Widget::on_q4_clicked()
{
    a+="4";
    ui->input->setText(a);
}

void Widget::on_q5_clicked()
{
    a+="5";
    ui->input->setText(a);
}

void Widget::on_q6_clicked()
{
    a+="6";
    ui->input->setText(a);
}

void Widget::on_q7_clicked()
{
    a+="7";
    ui->input->setText(a);
}

void Widget::on_q8_clicked()
{
    a+="8";
    ui->input->setText(a);
}

void Widget::on_q9_clicked()
{
    a+="9";
    ui->input->setText(a);
}

void Widget::on_plus_clicked()
{
    a+="+";
    ui->input->setText(a);
}

void Widget::on_minus_clicked()
{
    a+="-";
    ui->input->setText(a);
}

void Widget::on_square_clicked()
{
    a+="^";
    ui->input->setText(a);
}

void Widget::on_enter_clicked()
{
    if(m_i == 1||m_i == 0)
    {
        ui->showa->setText(c.Build(a,1));
        m_i = 2;
    }
    else if(m_i == 2)
    {
        ui->showb->setText(c.Build(a,2));
        m_i = 1;
    }
    ui->input->clear();
    a = "";
}

void Widget::on_backspace_clicked()
{
    if(a!= "")
    {
        a= a.left(a.length()-1);
        ui->input->setText(a);
    }
}

void Widget::on_clear_clicked()
{
    ui->showa->clear();
    ui->showb->clear();
    ui->showc->clear();
    ui->Ax->clear();
    ui->Bx->clear();
    ui->Cx->clear();
    c.clear();
}

void Widget::on_res_clicked()
{
    if(queren && a != "")
    {
        ui->Ax->setText(c.revalue(1,a.toDouble()));
        ui->Bx->setText(c.revalue(2,a.toDouble()));
        ui->Cx->setText(c.revalue(3,a.toDouble()));
        ui->input->clear();
        a = "";
    }
}

void Widget::on_ax_clicked()
{
    queren = 1;
        ui->Ax->setText("x=");
        ui->Bx->setText("x=");
        ui->Cx->setText("x=");
}

void Widget::on_apb_clicked()
{
    ui->showc->setText(c.algorithm(1));
    m_i = 3;
}

void Widget::on_amb_clicked()
{
    ui->showc->setText(c.algorithm(2));
    m_i = 3;
}
