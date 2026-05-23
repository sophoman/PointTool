#include "editabletextedit.h"

EditableTextEdit::EditableTextEdit(QWidget* parent):QTextEdit(parent) {}

void EditableTextEdit::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Enter||event->key()==Qt::Key_Tab){
        event->ignore();
        return;
    }
    QTextEdit::keyPressEvent(event);
}
