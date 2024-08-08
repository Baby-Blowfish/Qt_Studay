#include "widget.h"

#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#define NO_OF_ROW 3
#define NO_OF_colum 5

#include <QStackedLayout>
#include <QLabel>
#include <QDial>
#include <QCalendarWidget>
#include <QTextEdit>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //------------------------------------<QHBoxLayout>--------------------------------------------
    // pushbutton1 = new QPushButton("Button 1",this);
    // pushbutton2 = new QPushButton("Button 2",this);
    // pushbutton3 = new QPushButton("Button 3",this);

    //     // hBoxLayout = new QHBoxLayout(this);
    //     // hBoxLayout -> setSpacing(6);
    //     // hBoxLayout ->setContentsMargins(0,0,0,0);
    //     // hBoxLayout -> addWidget(pushbutton1);
    //     // hBoxLayout -> addWidget(pushbutton2);
    //     // hBoxLayout -> addWidget(pushbutton3);
    //     // setLayout(hBoxLayout);

    // vBoxLayout = new QVBoxLayout(this);
    // vBoxLayout -> setSpacing(6);
    // vBoxLayout ->setContentsMargins(0,0,0,0);
    // vBoxLayout -> addWidget(pushbutton1);
    // vBoxLayout -> addWidget(pushbutton2);
    // vBoxLayout -> addWidget(pushbutton3);
    // setLayout(vBoxLayout);



    //------------------------------------<QGridLayout>--------------------------------------------
    // gridLayout = new QGridLayout(this);
    // //pushButton = new QPushButton[NO_OF_ROW*NO_OF_ROW];
    // QPushButton *pushButton[NO_OF_ROW*NO_OF_colum];
    // for(int y = 0; y <NO_OF_ROW;y++)
    // {
    //     for(int x = 0; x <NO_OF_ROW;x++)
    //     {
    //         int p = x+y*NO_OF_ROW;
    //         QString str = QString("Button%1").arg(p+1);
    //         pushButton[p] = new QPushButton(str,this);
    //         gridLayout->addWidget(pushButton[p],x,y);
    //     }
    // }
    //  //void QGridLayout::addWidget(QWidget *widget, int fromRow, int fromColumn, int rowSpan, \
    //             int columnSpan, Qt::Alignment alignment = Qt::Alignment())

    // setLayout(gridLayout);


    //------------------------------------<QStackedLayout>--------------------------------------------
    // QDial *dial = new QDial(this);
    // dial -> setRange(0,2);

    // QLabel *label = new QLabel("Stack1",this);
    // QCalendarWidget *calendarWidget = new QCalendarWidget(this);
    // QTextEdit *textEdit = new QTextEdit("Stack 3",this);

    // QStackedLayout *stackedLayout = new QStackedLayout();
    // stackedLayout->addWidget(label);
    // stackedLayout->addWidget(calendarWidget);
    // stackedLayout->addWidget(textEdit);

    // connect(dial,&QDial::valueChanged,stackedLayout,&QStackedLayout::setCurrentIndex);

    // hBoxLayout = new QHBoxLayout(this);
    // hBoxLayout->addWidget(dial);
    // hBoxLayout->addLayout(stackedLayout);

    // setLayout(hBoxLayout);


}

Widget::~Widget() {}
