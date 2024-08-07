#include "widget.h"
#include<QLabel>
#include<QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent),m_isFirst(true)
{
    m_label = new QLabel("0",this);
    m_label->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
    m_label->setGeometry(10,5,230,40);

    connect(m_buttons.at(0),SIGNAL(clicked()),SLOT(setNum()));
    connect(m_buttons.at(1),SIGNAL(clicked()),SLOT(setNum()));
    connect(m_buttons.at(2),SIGNAL(clicked()),SLOT(setNum()));
    connect(m_buttons.at(4),SIGNAL(clicked()),SLOT(setNum()));
    connect(m_buttons.at(5),SIGNAL(clicked()),SLOT(setNum()));
    connect(m_buttons.at(6),SIGNAL(clicked()),SLOT(setNum()));
    connect(m_buttons.at(8),SIGNAL(clicked()),SLOT(setNum()));
    connect(m_buttons.at(9),SIGNAL(clicked()),SLOT(setNum()));
    connect(m_buttons.at(10),SIGNAL(clicked()),SLOT(setNum()));
    connect(m_buttons.at(12),SIGNAL(clicked()),SLOT(setNum()));

    connect(m_buttons.at(3),SIGNAL(clicked()),SLOT(setOp()));
    connect(m_buttons.at(7),SIGNAL(clicked()),SLOT(setOp()));
    connect(m_buttons.at(11),SIGNAL(clicked()),SLOT(setOp()));
    connect(m_buttons.at(15),SIGNAL(clicked()),SLOT(setOp()));


    connect(m_buttons.at(13),SIGNAL(clicked()),SLOT(clear()));
    //clear

    connect(m_buttons.at(14),SIGNAL(clicked()),SLOT(calculator()));
    // =

    // 함수 포인터 사용
    // const char *methods[16] = {
    //     SLOT(setNum()),SLOT(setNum()),SLOT(setNum()),SLOT(setOp()),
    //     SLOT(setNum()),SLOT(setNum()),SLOT(setNum()),SLOT(setOp()),
    //     SLOT(setNum()),SLOT(setNum()),SLOT(setNum()),SLOT(setOp()),
    //     SLOT(setNum()),SLOT(clear()),SLOT(calculator()),SLOT(setOp()),
    // }


    const char ButtonChar[16][2] = {
        "7","8","9","/",
        "4","5","6","x",
        "1","2","3","-",
        "0","C","=","+"
    };
    for(int  y = 0; y < WIDTH; y++)
    {
        for(int x = 0; x < WIDTH; x++)
        {
            int n = x+y*WIDTH;
            m_buttons.append(new QPushButton(ButtonChar[x+y*WIDTH],this));
            m_buttons.at(x+y*WIDTH)->setGeometry(5+60*x,50+60*y,60,60);
            //connect(m_buttons.at(n),SIGNAL(clicked()),methods[n]);
        }
    }



}

Widget::~Widget() { delete m_label; m_buttons.clear();}

void Widget::setNum()
{
    QPushButton *button = dynamic_cast<QPushButton*>(sender());
    QString bStr;
    if(button != nullptr) bStr = button->text();
    if(m_label != nullptr)
    {
        QString lStr = m_label->text();
        m_label->setText((lStr == "0"|m_isFirst)?bStr:lStr+bStr);
        m_isFirst =false;
    }
}
void Widget::setOp()
{
    QPushButton *button = dynamic_cast<QPushButton*>(sender());
    if(button!=nullptr)m_op = button->text();
    if(m_label!=nullptr)
    {
        m_num1 = m_label->text();
        m_isFirst = true;
    }
}
void Widget::clear()
{
    m_label->setText("0");
}

void Widget::calculator()
{
    qreal result = 0;   // double 형
    m_isFirst = true;
    switch(m_op[0].toLatin1())
    {
    case '+':
        result = m_num1.toDouble()+m_label->text().toDouble();
        break;
    case '-':
        result = m_num1.toDouble()-m_label->text().toDouble();
        break;
    case '*':
        result = m_num1.toDouble()*m_label->text().toDouble();
        break;
    case '/':
        if(m_label->text().toDouble() != 0)
        {
            result = m_num1.toDouble()/m_label->text().toDouble();
        }
        else
        {
            m_label->setText(" error : connot divide by zero");
            return ;
        }
        break;
    }
    m_label->setText(QString::number(result));

    setMinimumSize(250,295);
    setMaximumSize(250,295);
    setWindowTitle("Calculator");
}
