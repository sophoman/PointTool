#ifndef EDITABLECOMBOBOX_H
#define EDITABLECOMBOBOX_H

#include <QComboBox>
#include<QWheelEvent>
#include<QKeyEvent>
class EditableComboBox : public QComboBox
{
    Q_OBJECT
public:
    explicit EditableComboBox(QWidget* parent = Q_NULLPTR);
    void wheelEvent(QWheelEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // EDITABLECOMBOBOX_H
