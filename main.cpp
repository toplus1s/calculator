#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.setFixedSize(620, 580);
    w.move(1000,150);
    w.setAttribute(Qt::WA_TranslucentBackground, true);
    w.setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint|Qt::Tool);
    w.show();
    return a.exec();
}
