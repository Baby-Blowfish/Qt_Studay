#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QFrame;
class QGroupBox;
class QFormLayout;

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
    QFrame *plainLine;
    QFrame *raisedLine;
    QFrame *sunkenLine;

    QHBoxLayout *hBoxLayout;
    QVBoxLayout *vBoxLayout;
    QGridLayout *gridLayout;
};
#endif // WIDGET_H
