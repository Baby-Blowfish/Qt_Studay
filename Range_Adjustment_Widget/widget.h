#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QSlider;
class QScrollBar;
class QLabel;
class QCscrollArea;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    QSlider *slider;
    QScrollBar *scrollBar;
    QLabel *label;
    QCscrollArea *scrollArea
};
#endif // WIDGET_H
