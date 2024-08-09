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
    m_label->setGeometry(10,5,230,40);  // 위젯 크기 설정
        //  void setGeometry(int x, int y, int w, int h)
        //  void setGeometry(const QRect &)
        //  QRect r1(100, 200, 11, 16);
        //  QRect r2(QPoint(100, 200), QSize(11, 16));


    // 버튼에 표시될 문자열, 버튼은 문자열만 표현 가능
    const char ButtonChar[16][2] = {
        "7","8","9","/",
        "4","5","6","x",
        "1","2","3","-",
        "0","C","=","+"
    };
    // QPushButton 생성자의 첫번째 인자는 문자열 or QString만 가능

    // 슬롯 매크로는 const char*형
    const char *methods[16] = {
        SLOT(setNum()),SLOT(setNum()),SLOT(setNum()),SLOT(setOp()),
        SLOT(setNum()),SLOT(setNum()),SLOT(setNum()),SLOT(setOp()),
        SLOT(setNum()),SLOT(setNum()),SLOT(setNum()),SLOT(setOp()),
        SLOT(setNum()),SLOT(clear()),SLOT(calculator()),SLOT(setOp()),
    };

    // 시그널과 슬롯 선언
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


    // 4 x 4로 배치, y가 행, x가 열
    for(int  y = 0; y < WIDTH; y++)
    {
        for(int x = 0; x < WIDTH; x++)
        {
            int n = x+y*WIDTH;  // 2차원을 1차원으로 바꾸는 공식
            m_buttons.append(new QPushButton(ButtonChar[n],this));
            m_buttons[n]->setGeometry(0+x*60,45+y*60,60,60);
            connect(m_buttons.at(n),SIGNAL(clicked()),methods[n]);
        }
    }

    // setMinimumSize(250,295);    // 윈도우의 최소 크기 설정
    // setMaximumSize(250,295);    // 윈도우의 최대 크기 설정
    setWindowTitle("Calculator");

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
        m_label->setText((lStr == "0"||m_isFirst)?bStr:lStr+bStr);
        m_isFirst =false;       //   기존의 값 뒤에 연겷래서 입력
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
    //Returns a string equivalent of the number n

}
