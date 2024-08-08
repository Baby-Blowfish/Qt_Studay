#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QLineEdit;
class QComboBox;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QLineEdit *lineEdit;
    QComboBox *comboBox;

};
#endif // WIDGET_H
