#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QFrame;
class QGroupBox;
class QFormLayout;

class QHBoxLayout;
class QVBoxLayout;
class QGridLayout;

class QLabel;
class QDial;

class QVBoxLayout;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QFrame *plainLine;
    QFrame *raisedLine;
    QFrame *sunkenLine;

    QLabel *label;
    QLabel *label1;

    QDial *dial;
    QDial *dial1;
    QDial *dial2;

    QVBoxLayout *vBoxLayout; // 수직 레이아웃
};
#endif // WIDGET_H
