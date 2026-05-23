#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setStyle("windowsvista");
    Widget w;
    w.setWindowTitle("对点文件生成 v4.0");
    w.setWindowFlags(w.windowFlags() | Qt::WindowStaysOnTopHint);
    w.setWindowIcon(QIcon(":/image/icon.jpeg"));
    w.show();
    return a.exec();
}
