#include "editablecombobox.h"

EditableComboBox::EditableComboBox(QWidget* parent):QComboBox(parent) {}

void EditableComboBox::wheelEvent(QWheelEvent *event)
{
    event->ignore();
}

void EditableComboBox::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Up || event->key() == Qt::Key_Down) {
        event->ignore();  // 忽略上下键
        return;
    }
    QComboBox::keyPressEvent(event);
}
