#include "widget.h"
#include <QFrame>
#include <QGroupBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QTabWidget>
#include <QDial>
#include <QCalendarWidget>
#include <QTextEdit>
#include <QLabel>
#include <QSplitter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //------------------------------------------<QFrame>-----------------------------------------------
    // plainLine = new QFrame(this);
    // plainLine->setGeometry(QRect(0,0,270,16));
    // plainLine->setLineWidth(2);
    // plainLine->setFrameStyle(QFrame::HLine|QFrame::Plain);

    // raisedLine = new QFrame(this);
    // raisedLine->setGeometry(QRect(0,10,270,16));
    // raisedLine->setLineWidth(2);
    // raisedLine->setFrameStyle(QFrame::HLine|QFrame::Raised);

    // sunkenLine = new QFrame(this);
    // sunkenLine->setGeometry(QRect(0,20,270,16));
    // sunkenLine->setLineWidth(2);
    // sunkenLine->setFrameStyle(QFrame::HLine|QFrame::Sunken);



    //------------------------------------------<QGroupBox>-----------------------------------------------
    // QStringList labels;
    // labels <<"&IP Address"<<"&Mac Address"<<"&Date";
    // QLineEdit* lineEdit[3];
    // QFormLayout *formLayout = new QFormLayout;
    // for(int i = 0; i< 3; i++)
    // {
    //     lineEdit[i] = new QLineEdit(this);
    //     formLayout->addRow(labels.at(i),lineEdit[i]);
    // }

    // QGroupBox *groupBox = new QGroupBox("&Widget Group",this);
    // groupBox->move(5,5);
    // groupBox->setLayout(formLayout);

    // resize(groupBox->sizeHint().width()+10,groupBox->sizeHint().height()+10);




    //------------------------------------------<QTabWidget>-----------------------------------------------
    // QDial *dial = new QDial(this);
    // QCalendarWidget *calendarWidget = new QCalendarWidget(this);
    // QTextEdit *textEdit = new QTextEdit("Stack 3",this);

    // QTabWidget *tabWidget = new QTabWidget(this);
    // tabWidget->addTab(dial,"Tab &1");
    // tabWidget->addTab(calendarWidget,"Tab &2");
    // tabWidget->addTab(textEdit,"Tab &3");

    // resize(tabWidget->sizeHint());





    //------------------------------------------<QSplitter>-----------------------------------------------
    // QLabel *label = new QLabel("&Value",this);
    // QDial *dial1 = new QDial(this);
    // QDial *dial2 = new QDial(this);
    // label->setBuddy(dial2);

    // QSplitter *splitter = new QSplitter(this);
    // splitter->addWidget(label);
    // splitter->addWidget(dial1);
    // splitter->addWidget(dial2);

    // resize(splitter->sizeHint());

}

Widget::~Widget() {}
