#ifndef EDITABLETEXTEDIT_H
#define EDITABLETEXTEDIT_H

#include <QObject>
#include <QTextEdit>
#include<QKeyEvent>
class EditableTextEdit : public QTextEdit
{
    Q_OBJECT
public:
    explicit EditableTextEdit(QWidget* parent = Q_NULLPTR);
private:
    void keyPressEvent(QKeyEvent*event)override;
};

#endif // EDITABLETEXTEDIT_H
