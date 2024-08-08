#include "widget.h"
#include <QSlider>
#include <QStyleFactory>
#include <QScrollBar>
#include <QLabel>
#include <QScrollArea>
#include <QDial>
#include <QSpinBox>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //---------------------------------------<QSlider>-----------------------------------------
    // slider = new QSlider(this);
    // slider->setOrientation(Qt::Horizontal);
    // slider->setTickPosition(QSlider::TicksAbove);
    // slider->setStyle(QStyleFactory::create("Fusion"));
    // slider->setRange(0,150);
    // slider->setValue(50);
    // slider->resize(300,50);


    //-------------------------------<QScrollBar>--------------------------------------------
    // label = new QLabel("1234567890123456789012345678901234567890",this);
    // scrollArea = new QScrollArea(this);
    // scrollArea->setBackgroundRole((QPalette::Dark));
    // scrollArea->setWidget(label);
    // scrollArea->resize(60,30);
    // scrollArea->show();
    // scrollBar = scrollArea->horizontalScrollBar();
    // scrollBar->setValue(scrollBar->maximum());


    //-------------------------------<QDial>--------------------------------------
    // dial = new QDial(this);
    // dial->setWrapping(true);
    // dial->setNotchesVisible(true);
    // dial->setNotchTarget(10);   // 10등분

    //--------------------------------<QSpinBox>-------------------------------------
    // spinBox = new QSpinBox(this);
    // spinBox->resize(300,20);
    // spinBox->setRange(0,10);
    // spinBox->setSuffix("%");
    // spinBox->setWrapping(true);
    // spinBox->setSpecialValueText("Percent");




}

Widget::~Widget() {}
