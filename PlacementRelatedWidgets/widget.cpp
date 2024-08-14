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
#include <QDebug>
#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    vBoxLayout = new QVBoxLayout();


    //------------------------------------------<QFrame>-----------------------------------------------
    plainLine = new QFrame(this);
    plainLine->setGeometry(QRect(0,0,270,16));
    plainLine->setLineWidth(2);
    plainLine->setFrameStyle(QFrame::HLine|QFrame::Plain);

    raisedLine = new QFrame(this);
    raisedLine->setGeometry(QRect(0,10,270,16));
    raisedLine->setLineWidth(2);
    raisedLine->setFrameStyle(QFrame::HLine|QFrame::Raised);

    sunkenLine = new QFrame(this);
    sunkenLine->setGeometry(QRect(0,20,270,16));
    sunkenLine->setLineWidth(2);
    sunkenLine->setFrameStyle(QFrame::HLine|QFrame::Sunken);


    //------------------------------------------<QGroupBox>-----------------------------------------------
    QStringList labels;
    labels <<"&IP Address"<<"&Mac Address"<<"&Date";
    QLineEdit* lineEdit[3];
    QFormLayout *formLayout = new QFormLayout;
    for(int i = 0; i< 3; i++)
    {
        lineEdit[i] = new QLineEdit(this);
        formLayout->addRow(labels.at(i),lineEdit[i]);
    }

    QGroupBox *groupBox = new QGroupBox("&Widget Group",this);
    groupBox->setLayout(formLayout);

    // groupBox->move(5,30);
    // // qDebug()<<groupBox->sizeHint().width();     // 229  (+10필요)
    // // qDebug()<<groupBox->sizeHint().height();    // 111  (+10필요)


    //------------------------------------------<QTabWidget>-----------------------------------------------
    dial = new QDial(this);
    QCalendarWidget *calendarWidget = new QCalendarWidget(this);
    QTextEdit *textEdit = new QTextEdit("Stack 3",this);

    QTabWidget *tabWidget = new QTabWidget(this);
    tabWidget->addTab(dial,"Tab &1");
    tabWidget->addTab(calendarWidget,"Tab &2");
    tabWidget->addTab(textEdit,"Tab &3");

    // tabWidget->move(0,151);
    // // qDebug()<<tabWidget->sizeHint().width();     // 262  (+10필요)
    // // qDebug()<<tabWidget->sizeHint().height();    // 222  (+10필요)



    //------------------------------------------<QSplitter>-----------------------------------------------
    label1 = new QLabel("&Value",this);
    dial1 = new QDial(this);
    dial2 = new QDial(this);
    label1->setBuddy(dial2);

    QSplitter *splitter = new QSplitter(this);
    splitter->addWidget(label1);
    splitter->addWidget(dial1);
    splitter->addWidget(dial2);

    // splitter->move(0,383);
    // // qDebug()<<splitter->sizeHint().width();     // 230  (+10필요)
    // // qDebug()<<splitter->sizeHint().height();    // 100  (+10필요)
    // resize(280,383+splitter->sizeHint().height()+10);


}

Widget::~Widget() {}
