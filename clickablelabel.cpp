#include "clickablelabel.h"

ClickableLabel::ClickableLabel(QWidget* parent, Qt::WindowFlags f):QLabel(parent,f){
    setCursor(Qt::PointingHandCursor);
}
void ClickableLabel::mousePressEvent(QMouseEvent* event)
{
    // 当鼠标左键被按下时，发出clicked()信号
    if (event->button() == Qt::LeftButton) {
        emit clicked();
    }
    // 将事件传递给父类QLabel，确保其原有的行为（如显示文本）不受影响
    QLabel::mousePressEvent(event);
}
