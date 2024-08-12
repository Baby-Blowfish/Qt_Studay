/*--------------------------------Class cpp-------------------------------------------*/
#include "widget.h"  // Widget 클래스 헤더 파일 포함

#include<QLabel>  // QLabel 클래스 포함
#include<QPushButton>  // QPushButton 클래스 포함

// Widget 클래스 생성자 정의
Widget::Widget(QWidget *parent)
    : QWidget(parent), m_isFirst(true)  // 초기화 리스트
{
    m_label = new QLabel("0", this);  // QLabel 객체 동적 할당 및 초기화
    m_label->setAlignment(Qt::AlignRight | Qt::AlignVCenter);  // 텍스트 정렬 설정
    m_label->setGeometry(10, 5, 230, 40);  // QLabel 위치 및 크기 설정

    // 버튼에 표시될 문자열 배열
    const char ButtonChar[16][2] = {
        "7", "8", "9", "/",
        "4", "5", "6", "x",
        "1", "2", "3", "-",
        "0", "C", "=", "+"
    };

    // 슬롯 함수 포인터 배열
    const char *methods[16] = {
        SLOT(setNum()), SLOT(setNum()), SLOT(setNum()), SLOT(setOp()),
        SLOT(setNum()), SLOT(setNum()), SLOT(setNum()), SLOT(setOp()),
        SLOT(setNum()), SLOT(setNum()), SLOT(setNum()), SLOT(setOp()),
        SLOT(setNum()), SLOT(clear()), SLOT(calculator()), SLOT(setOp()),
    };

    // 4 x 4 버튼 배열 생성 및 시그널-슬롯 연결
    for (int y = 0; y < WIDTH; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            int n = x + y * WIDTH;  // 2차원 인덱스를 1차원 인덱스로 변환
            m_buttons.append(new QPushButton(ButtonChar[n], this));  // 버튼 생성 및 추가
            m_buttons[n]->setGeometry(0 + x * 60, 45 + y * 60, 60, 60);  // 버튼 위치 및 크기 설정
            connect(m_buttons.at(n), SIGNAL(clicked()), methods[n]);  // 시그널-슬롯 연결
        }
    }

    setMinimumSize(250, 295);  // 윈도우 최소 크기 설정
    setMaximumSize(250, 295);  // 윈도우 최대 크기 설정
    setWindowTitle("Calculator");  // 윈도우 제목 설정
}

// Widget 클래스 소멸자 정의
Widget::~Widget() { delete m_label; m_buttons.clear(); }

// 숫자 버튼이 눌렸을 때 호출되는 슬롯 함수
void Widget::setNum()
{
    QPushButton *button = dynamic_cast<QPushButton*>(sender());  // 시그널을 보낸 객체를 QPushButton으로 캐스팅
    QString bStr;
    if (button != nullptr) bStr = button->text();  // 버튼의 텍스트 가져오기
    if (m_label != nullptr)
    {
        QString lStr = m_label->text();  // QLabel의 텍스트 가져오기
        m_label->setText((lStr == "0" || m_isFirst) ? bStr : lStr + bStr);  // 텍스트 갱신
        m_isFirst = false;  // 첫 번째 입력 여부 갱신
    }
}

// 연산자 버튼이 눌렸을 때 호출되는 슬롯 함수
void Widget::setOp()
{
    QPushButton *button = dynamic_cast<QPushButton*>(sender());  // 시그널을 보낸 객체를 QPushButton으로 캐스팅
    if (button != nullptr) m_op = button->text();  // 버튼의 텍스트 가져오기
    if (m_label != nullptr)
    {
        m_num1 = m_label->text();  // QLabel의 텍스트 가져오기
        m_isFirst = true;  // 첫 번째 입력 여부 갱신
    }
}

// 클리어 버튼이 눌렸을 때 호출되는 슬롯 함수
void Widget::clear()
{
    m_label->setText("0");  // QLabel의 텍스트를 "0"으로 설정
}

// 계산 버튼이 눌렸을 때 호출되는 슬롯 함수
void Widget::calculator()
{
    qreal result = 0;  // 결과를 저장할 변수, 실수형
    m_isFirst = true;  // 첫 번째 입력 여부 갱신
    switch (m_op[0].toLatin1())  // 연산자에 따라 분기
    {
    case '+':
        result = m_num1.toDouble() + m_label->text().toDouble();  // 덧셈
        break;
    case '-':
        result = m_num1.toDouble() - m_label->text().toDouble();  // 뺄셈
        break;
    case 'x':
        result = m_num1.toDouble() * m_label->text().toDouble();  // 곱셈
        break;
    case '/':
        if (m_label->text().toDouble() != 0)
        {
            result = m_num1.toDouble() / m_label->text().toDouble();  // 나눗셈
        }
        else
        {
            m_label->setText(" error : cannot divide by zero");  // 0으로 나누기 에러 메시지
            return;
        }
        break;
    }
    m_label->setText(QString::number(result));  // 결과를 문자열로 변환하여 QLabel에 설정
}

