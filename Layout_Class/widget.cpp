/*--------------------------------Class cpp-------------------------------------------*/
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

// Widget 생성자 정의
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //------------------------------------<QVBoxLayout>--------------------------------------------
    // 수직 레이아웃에 버튼 추가
    pushbuttonVBoxLayout[0] = new QPushButton("VBox Button 1", this);
    pushbuttonVBoxLayout[1] = new QPushButton("VBox Button 2", this);
    pushbuttonVBoxLayout[2] = new QPushButton("VBox Button 3", this);

    // 수평 레이아웃에 버튼 추가
    pushbuttonHBoxLayout[0] = new QPushButton("HBox Button 4", this);
    pushbuttonHBoxLayout[1] = new QPushButton("HBox Button 5", this);
    pushbuttonHBoxLayout[2] = new QPushButton("HBox Button 6", this);

    // 수직 레이아웃 설정
    vBoxLayout = new QVBoxLayout();
    vBoxLayout->setSpacing(6); // 간격 설정
    vBoxLayout->setContentsMargins(10, 10, 10, 10); // 여백 설정
    vBoxLayout->addWidget(pushbuttonVBoxLayout[0]);
    vBoxLayout->addWidget(pushbuttonVBoxLayout[1]);
    vBoxLayout->addWidget(pushbuttonVBoxLayout[2]);

    // 수평 레이아웃 설정
    hBoxLayout = new QHBoxLayout();
    hBoxLayout->setSpacing(6); // 간격 설정
    hBoxLayout->setContentsMargins(0, 0, 0, 0); // 여백 설정
    hBoxLayout->addWidget(pushbuttonHBoxLayout[0]);
    hBoxLayout->addWidget(pushbuttonHBoxLayout[1]);
    hBoxLayout->addWidget(pushbuttonHBoxLayout[2]);

    // 두 레이아웃을 메인 레이아웃에 추가
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(vBoxLayout);
    mainLayout->addLayout(hBoxLayout);

    //------------------------------------<QGridLayout>--------------------------------------------
    // 그리드 레이아웃 설정
    gridLayout = new QGridLayout(this);
    for (int y = 0; y < NO_OF_ROW; y++)
    {
        for (int x = 0; x < NO_OF_colum; x++)
        {
            int p = x + y * NO_OF_colum;
            QString str = QString("Grid Button %1").arg(p + 1);
            pushButtonGridLayout[p] = new QPushButton(str, this);
            gridLayout->addWidget(pushButtonGridLayout[p], y, x);
        }
    }
    mainLayout->addLayout(gridLayout);

    //------------------------------------<QStackedLayout>--------------------------------------------
    // 스택 레이아웃 설정
    dial = new QDial(this);
    dial->setRange(0, 2); // 다이얼 범위 설정

    label = new QLabel("Stack label 1", this);
    calendarWidget = new QCalendarWidget(this);
    textEdit = new QTextEdit("Stack textedit  3", this);

    QStackedLayout* stackedLayout = new QStackedLayout();
    stackedLayout->addWidget(label);
    stackedLayout->addWidget(calendarWidget);
    stackedLayout->addWidget(textEdit);

    // 다이얼 값이 변경될 때 스택의 인덱스를 변경
    connect(dial, &QDial::valueChanged, stackedLayout, &QStackedLayout::setCurrentIndex);

    hBoxLayout = new QHBoxLayout(this);
    hBoxLayout->addWidget(dial);
    hBoxLayout->addLayout(stackedLayout);

    mainLayout->addLayout(hBoxLayout);

    // 메인 레이아웃을 위젯에 설정
    setLayout(mainLayout);
}

// Widget 소멸자 정의
Widget::~Widget() {}

