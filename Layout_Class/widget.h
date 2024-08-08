#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QPushButton;
class QHBoxLayout;
class QVBoxLayout;
class QGridLayout;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QPushButton *pushbutton1;
    QPushButton *pushbutton2;
    QPushButton *pushbutton3;
    //QPushButton **pushButton;

    QHBoxLayout *hBoxLayout;
    QVBoxLayout *vBoxLayout;
    QGridLayout *gridLayout;


};
#endif // WIDGET_H
