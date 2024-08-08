#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QSlider;
class QScrollBar;
class QLabel;
class QScrollArea;
class QDial;
class QSpinBox;

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
    QScrollArea *scrollArea;
    QDial *dial;
    QSpinBox *spinBox;
};
#endif // WIDGET_H
