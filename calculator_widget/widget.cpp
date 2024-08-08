#include "widget.h"

#include<QLabel>
#include<QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent),m_isFirst(true)
{
    m_label = new QLabel("0",this);     // 레이블 객체 동적 할당, Widget윈도우에 자식 위젯으로 설정
    m_label->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
        // void setAlignment(Qt::Alignment)
        // This property holds the alignment of the label's contents
        // default, left-aligned and vertically-centered
    m_label->setGeometry(10,5,230,40);
        //  void setGeometry(int x, int y, int w, int h)
        //  void setGeometry(const QRect &)
        //  QRect r1(100, 200, 11, 16);
        //  QRect r2(QPoint(100, 200), QSize(11, 16));




    // 함수 포인터 사용
    const char *methods[16] = {
        SLOT(setNum()),SLOT(setNum()),SLOT(setNum()),SLOT(setOp()),
        SLOT(setNum()),SLOT(setNum()),SLOT(setNum()),SLOT(setOp()),
        SLOT(setNum()),SLOT(setNum()),SLOT(setNum()),SLOT(setOp()),
        SLOT(setNum()),SLOT(clear()),SLOT(calculator()),SLOT(setOp()),
    };


    const char ButtonChar[16][2] = {
        "7","8","9","/",
        "4","5","6","x",
        "1","2","3","-",
        "0","C","=","+"
    };

    QGridLayout *gridLayout = new QGridLayout();

    for(int  y = 0; y < WIDTH; y++)
    {
        for(int x = 0; x < WIDTH; x++)
        {
            int n = x+y*WIDTH;
            m_buttons.append(new QPushButton(ButtonChar[x+y*WIDTH],this));
            gridLayout->addWidget(m_buttons.at(n),n/WIDTH,n%WIDTH);
            connect(m_buttons.at(n),SIGNAL(clicked()),methods[n]);
        }
    }

    // connect(m_buttons.at(0),SIGNAL(clicked()),SLOT(setNum()));
    // connect(m_buttons.at(1),SIGNAL(clicked()),SLOT(setNum()));
    // connect(m_buttons.at(2),SIGNAL(clicked()),SLOT(setNum()));
    // connect(m_buttons.at(4),SIGNAL(clicked()),SLOT(setNum()));
    // connect(m_buttons.at(5),SIGNAL(clicked()),SLOT(setNum()));
    // connect(m_buttons.at(6),SIGNAL(clicked()),SLOT(setNum()));
    // connect(m_buttons.at(8),SIGNAL(clicked()),SLOT(setNum()));
    // connect(m_buttons.at(9),SIGNAL(clicked()),SLOT(setNum()));
    // connect(m_buttons.at(10),SIGNAL(clicked()),SLOT(setNum()));
    // connect(m_buttons.at(12),SIGNAL(clicked()),SLOT(setNum()));

    // connect(m_buttons.at(3),SIGNAL(clicked()),SLOT(setOp()));
    // connect(m_buttons.at(7),SIGNAL(clicked()),SLOT(setOp()));
    // connect(m_buttons.at(11),SIGNAL(clicked()),SLOT(setOp()));
    // connect(m_buttons.at(15),SIGNAL(clicked()),SLOT(setOp()));


    // connect(m_buttons.at(13),SIGNAL(clicked()),SLOT(clear()));
    // //clear

    // connect(m_buttons.at(14),SIGNAL(clicked()),SLOT(calculator()));
    // // =

    QVBoxLayout *vBoxLayout = new QVBoxLayout(this);
    vBoxLayout->setContentsMargins(6,6,6,6);
    vBoxLayout->addWidget(m_label);
    vBoxLayout->addLayout(gridLayout);
    setLayout(vBoxLayout);


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
    case 'x':
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


    setWindowTitle("Calculator");
}
