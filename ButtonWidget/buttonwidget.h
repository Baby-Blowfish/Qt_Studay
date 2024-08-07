#ifndef BUTTONWIDGET_H
#define BUTTONWIDGET_H

#include <QWidget>

// class QRadioButton;
// class QButtonGroup;

class QCheckBox;
class QButtonGroup;

class ButtonWidget : public QWidget
{
    Q_OBJECT

public:
    ButtonWidget(QWidget *parent = nullptr);
    ~ButtonWidget();

private:
    // QRadioButton *radioButton[4];
    // QButtonGroup *buttonGroup;

    QCheckBox *checkBox[4];
    QButtonGroup *buttonGroup;

public slots:
    void selectButton(int id);
};
#endif // BUTTONWIDGET_H
