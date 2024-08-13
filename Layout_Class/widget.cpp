#include "widget.h"

#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QStackedLayout>

#include <QLabel>
#include <QDial>
#include <QCalendarWidget>
#include <QTextEdit>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //------------------------------------<QHBoxLayout>--------------------------------------------
    pushbuttonVBoxLayout[0] = new QPushButton("VBox Button 1",this);
    pushbuttonVBoxLayout[1] = new QPushButton("VBox Button 2",this);
    pushbuttonVBoxLayout[2] = new QPushButton("VBox Button 3",this);

    pushbuttonHBoxLayout[0] = new QPushButton("HBox Button 4",this);
    pushbuttonHBoxLayout[1] = new QPushButton("HBox Button 5",this);
    pushbuttonHBoxLayout[2] = new QPushButton("HBox Button 6",this);

    vBoxLayout = new QVBoxLayout();
    vBoxLayout -> setSpacing(6);
    vBoxLayout ->setContentsMargins(10,10,10,10);
    vBoxLayout -> addWidget(pushbuttonVBoxLayout[0]);
    vBoxLayout -> addWidget(pushbuttonVBoxLayout[1]);
    vBoxLayout -> addWidget(pushbuttonVBoxLayout[2]);


    hBoxLayout = new QHBoxLayout();
    hBoxLayout -> setSpacing(6);
    hBoxLayout ->setContentsMargins(0,0,0,0);
    hBoxLayout -> addWidget(pushbuttonHBoxLayout[0]);
    hBoxLayout -> addWidget(pushbuttonHBoxLayout[1]);
    hBoxLayout -> addWidget(pushbuttonHBoxLayout[2]);

    // Now combine the layouts
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(vBoxLayout);  // Add the vertical layout
    mainLayout->addLayout(hBoxLayout);  // Add the horizontal layout





    //------------------------------------<QGridLayout>--------------------------------------------
    gridLayout = new QGridLayout(this);
    for(int y = 0; y <NO_OF_ROW;y++)
    {
        for(int x = 0; x <NO_OF_colum;x++)
        {
            int p = x+y*NO_OF_colum;
            QString str = QString("Grid Button %1").arg(p+1);
            pushButtonGridLayout[p] = new QPushButton(str,this);
            gridLayout->addWidget(pushButtonGridLayout[p],y,x);
        }
    }
    mainLayout->addLayout(gridLayout);



    //------------------------------------<QStackedLayout>--------------------------------------------

    dial = new QDial(this);
    dial -> setRange(0,2);

    label = new QLabel("Stack label 1",this);
    calendarWidget = new QCalendarWidget(this);
    textEdit = new QTextEdit("Stack textedit  3",this);

    QStackedLayout *stackedLayout = new QStackedLayout();
    stackedLayout->addWidget(label);
    stackedLayout->addWidget(calendarWidget);
    stackedLayout->addWidget(textEdit);

    connect(dial,&QDial::valueChanged,stackedLayout,&QStackedLayout::setCurrentIndex);

    hBoxLayout = new QHBoxLayout(this);
    hBoxLayout->addWidget(dial);
    hBoxLayout->addLayout(stackedLayout);

    setLayout(hBoxLayout);



    setLayout(mainLayout);  // Set the combined layout on the widget



}

Widget::~Widget() {}
