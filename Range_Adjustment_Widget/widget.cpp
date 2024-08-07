#include "widget.h"
#include <QSlider>
#include <QStyleFactory>
#include <QScrollBar>
#include <QLabel>
#include <QCscrollArea>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    // slider = new QSlider(this);
    // slider->setOrientation(Qt::Horizontal);
    // slider->setTickPosition(QSlider::TicksAbove);
    // slider->setStyle(QStyleFactory::create("Fusion"));
    // slider->setRange(0,150);
    // slider->setValue(50);
    // slider->resize(300,50);

    label = new QLabel("1234567890123456789012345678901234567890");
    scrollArea = new QCscrollArea;
}

Widget::~Widget() {}
