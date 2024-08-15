#include "widget.h"  // Widget 클래스 헤더 파일 포함
#include<QLabel>  // QLabel 클래스 포함
#include<QPushButton>  // QPushButton 클래스 포함
#include<QVBoxLayout>  // QVBoxLayout 클래스 포함
#include<QGridLayout>  // QGridLayout 클래스 포함
#include<QButtonGroup>  // QButtonGroup 클래스 포함

// Widget 클래스 생성자 정의
Widget::Widget(QWidget *parent)
    : QWidget(parent), m_isFirst(true)  // 초기화 리스트, 부모 클래스 생성자 호출 및 m_isFirst 초기화
{
    m_label = new QLabel("0", this);  // QLabel 객체 동적 할당 및 초기화, 초기 텍스트는 "0"
    m_label->setAlignment(Qt::AlignRight | Qt::AlignVCenter);  // 텍스트 정렬 설정 (우측 및 수직 가운데)
    m_label ->setFrameShape(QFrame::Box);  // QLabel을 박스 형태로 설정
    m_label->setMaximumHeight(30);  // QLabel의 최대 높이 설정

    const char ButtonChar[16][2] = {  // 버튼에 표시될 문자열 배열
        "7","8","9","/",
        "4","5","6","x",
        "1","2","3","-",
        "0","C","=","+"
    };

    QGridLayout *gridLayout = new QGridLayout();  // QGridLayout 객체 생성, 그리드 레이아웃
    buttonGroup = new QButtonGroup(this);  // QButtonGroup 객체 생성 및 부모 설정

    for(int y = 0; y < WIDTH; y++)  // 4x4 그리드 생성
    {
        for(int x = 0; x < WIDTH; x++)
        {
            int n = x + y * WIDTH;  // 2차원 인덱스를 1차원 인덱스로 변환
            m_buttons.append(new QPushButton(ButtonChar[n], this));  // 버튼 생성 및 추가
            gridLayout->addWidget(m_buttons.at(n), n / WIDTH, n % WIDTH);  // 버튼을 그리드 레이아웃에 추가
            buttonGroup->addButton(m_buttons.at(n), n);  // 버튼을 버튼 그룹에 추가, id는 n
        }
    }

    connect(buttonGroup, SIGNAL(idClicked(int)), SLOT(click(int)));  // 버튼 그룹의 idClicked 시그널을 click 슬롯에 연결

    setWindowTitle("Calculator");  // 윈도우 제목 설정

    QVBoxLayout *vBoxLayout = new QVBoxLayout(this);  // QVBoxLayout 객체 생성, 수직 박스 레이아웃
    vBoxLayout->setContentsMargins(6, 6, 6, 6);  // 레이아웃의 여백 설정
    vBoxLayout->addWidget(m_label);  // QLabel을 레이아웃에 추가
    vBoxLayout->addLayout(gridLayout);  // 그리드 레이아웃을 수직 박스 레이아웃에 추가

    setLayout(vBoxLayout);  // 수직 박스 레이아웃을 위젯의 레이아웃으로 설정
}

// Widget 클래스 소멸자 정의
Widget::~Widget() {
    delete m_label;  // QLabel 객체 삭제
    m_buttons.clear();  // 버튼 벡터 비우기
}

// 숫자 버튼이 눌렸을 때 호출되는 슬롯 함수
void Widget::setNum()
{
    QString bStr;  // 버튼의 텍스트를 저장할 문자열
    if(button != nullptr) bStr = button->text();  // 버튼이 nullptr이 아니면 텍스트 가져오기
    if(m_label != nullptr)
    {
        QString lStr = m_label->text();  // QLabel의 텍스트 가져오기
        m_label->setText((lStr == "0" || m_isFirst) ? bStr : lStr + bStr);  // 첫 번째 입력이거나 QLabel 텍스트가 "0"이면 버튼 텍스트로 설정, 그렇지 않으면 기존 텍스트에 버튼 텍스트 추가
        m_isFirst = false;  // 첫 번째 입력 여부 갱신
    }
}

// 연산자 버튼이 눌렸을 때 호출되는 슬롯 함수
void Widget::setOp()
{
    if(button != nullptr) m_op = button->text();  // 버튼이 nullptr이 아니면 텍스트 가져오기
    if(m_label != nullptr)
    {
        m_num1 = m_label->text();  // QLabel의 텍스트를 첫 번째 숫자로 저장
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
    switch(m_op[0].toLatin1())  // 연산자에 따라 분기
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
        if(m_label->text().toDouble() != 0)
        {
            result = m_num1.toDouble() / m_label->text().toDouble();  // 나눗셈
        }
        else
        {
            m_label->setText("error: cannot divide by zero");  // 0으로 나누기 에러 메시지
            return;
        }
        break;
    }
    m_label->setText(QString::number(result));  // 결과를 문자열로 변환하여 QLabel에 설정
}

// 버튼 클릭 시 호출되는 슬롯 함수
void Widget::click(int id)
{
    button = dynamic_cast<QPushButton*>(buttonGroup->button(id));  // 클릭된 버튼을 QPushButton으로 캐스팅
    switch(id) {
    case 0: case 1: case 2:  // 숫자 버튼
    case 4: case 5: case 6:
    case 8: case 9: case 10:
    case 12:
        setNum(); break;  // 숫자 설정 함수 호출
    case 3: case 7: case 11: case 15:  // 연산자 버튼
        setOp(); break;  // 연산자 설정 함수 호출
    case 13: clear(); break;  // 클리어 버튼
    case 14: calculator(); break;  // 계산 버튼
    }
}
