#ifndef WIDGET_H
#define WIDGET_H
#include <QPoint>
#include <QWidget>
#include <QSystemTrayIcon>
#include <QtGui>
#include <QPushButton>
#include <string>
#include "calculator.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class Widget;}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    QString getPngName(QChar x);
    void mykeyPress();
    QString a = "";
    //void mykeyPressEvent(QKeyEvent *event);

protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void paintEvent(QPaintEvent *e);
    void startAnimation();




public slots:
    //void slot_keyPressed(QKeyEvent *event);
    void quitWindowAnimation();
    void on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason);
    void showTime();
    void showaboutDlg();
    void showInfoDlg();
    //void Button_osu();
    //void showpicture1();


private slots:


    void on_q0_clicked();

    void on_x_clicked();

    void on_point_clicked();

    void on_q1_clicked();

    void on_q2_clicked();

    void on_q3_clicked();

    void on_q4_clicked();

    void on_q5_clicked();

    void on_q6_clicked();

    void on_q7_clicked();

    void on_q8_clicked();

    void on_q9_clicked();

    void on_plus_clicked();

    void on_minus_clicked();

    void on_square_clicked();

    void on_enter_clicked();

    void on_backspace_clicked();

    void on_clear_clicked();

    void on_res_clicked();

    void on_ax_clicked();

    void on_apb_clicked();

    void on_amb_clicked();

private:
    Ui::Widget *ui;
    QPoint m_point;
    QSystemTrayIcon *trayIcon;
    QMenu* trayIconMenu;
    QAction* quitAction;
    QAction* aboutAction;
    QAction* minAction;
    QAction* restoreAction;
    QAction*  configAction;
    calculator c;
    int m_i = 0;
    int queren = 0;

private:
    void myTrayIcon();

};

#endif // WIDGET_H
