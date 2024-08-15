/*--------------------------------Class cpp-------------------------------------------*/
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

// Widget 생성자 정의
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // QVBoxLayout 인스턴스 생성 및 초기화
    vBoxLayout = new QVBoxLayout();

    //------------------------------------------<QFrame>-----------------------------------------------
    // QFrame 인스턴스 생성 및 속성 설정
    plainLine = new QFrame(this);
    plainLine->setGeometry(QRect(0,0,270,16)); // 위치 및 크기 설정
    plainLine->setLineWidth(2); // 선의 두께 설정
    plainLine->setFrameStyle(QFrame::HLine|QFrame::Plain); // 선의 스타일 설정

    raisedLine = new QFrame(this);
    raisedLine->setGeometry(QRect(0,10,270,16)); // 위치 및 크기 설정
    raisedLine->setLineWidth(2); // 선의 두께 설정
    raisedLine->setFrameStyle(QFrame::HLine|QFrame::Raised); // 선의 스타일 설정

    sunkenLine = new QFrame(this);
    sunkenLine->setGeometry(QRect(0,20,270,16)); // 위치 및 크기 설정
    sunkenLine->setLineWidth(2); // 선의 두께 설정
    sunkenLine->setFrameStyle(QFrame::HLine|QFrame::Sunken); // 선의 스타일 설정

    // QVBoxLayout에 QFrame 위젯 추가
    vBoxLayout->addWidget(plainLine);
    vBoxLayout->addWidget(raisedLine);
    vBoxLayout->addWidget(sunkenLine);

    //------------------------------------------<QGroupBox>-----------------------------------------------
    // QGroupBox 인스턴스 생성 및 설정
    QStringList labels;
    labels <<"&IP Address"<<"&Mac Address"<<"&Date";
    QLineEdit* lineEdit[3];
    QFormLayout *formLayout = new QFormLayout;
    for(int i = 0; i< 3; i++)
    {
        lineEdit[i] = new QLineEdit(this); // QLineEdit 인스턴스 생성
        formLayout->addRow(labels.at(i),lineEdit[i]); // QFormLayout에 QLineEdit 추가
    }

    QGroupBox *groupBox = new QGroupBox("&Widget Group",this); // QGroupBox 인스턴스 생성
    groupBox->setLayout(formLayout); // QGroupBox에 QFormLayout 설정

    // QVBoxLayout에 QGroupBox 추가
    vBoxLayout->addWidget(groupBox);

    //------------------------------------------<QTabWidget>-----------------------------------------------
    // QTabWidget 인스턴스 생성 및 설정
    dial = new QDial(this); // QDial 인스턴스 생성
    QCalendarWidget *calendarWidget = new QCalendarWidget(this); // QCalendarWidget 인스턴스 생성
    QTextEdit *textEdit = new QTextEdit("Stack 3",this); // QTextEdit 인스턴스 생성

    QTabWidget *tabWidget = new QTabWidget(this); // QTabWidget 인스턴스 생성
    tabWidget->addTab(dial,"Tab &1"); // QTabWidget에 QDial 추가
    tabWidget->addTab(calendarWidget,"Tab &2"); // QTabWidget에 QCalendarWidget 추가
    tabWidget->addTab(textEdit,"Tab &3"); // QTabWidget에 QTextEdit 추가

    // QVBoxLayout에 QTabWidget 추가
    vBoxLayout->addWidget(tabWidget);

    //------------------------------------------<QSplitter>-----------------------------------------------
    // QSplitter 인스턴스 생성 및 설정
    label1 = new QLabel("&Value",this); // QLabel 인스턴스 생성
    dial1 = new QDial(this); // QDial 인스턴스 생성
    dial2 = new QDial(this); // QDial 인스턴스 생성
    label1->setBuddy(dial2); // QLabel과 QDial 연결

    QSplitter *splitter = new QSplitter(this); // QSplitter 인스턴스 생성
    splitter->addWidget(label1); // QSplitter에 QLabel 추가
    splitter->addWidget(dial1); // QSplitter에 QDial 추가
    splitter->addWidget(dial2); // QSplitter에 QDial 추가

    // QVBoxLayout에 QSplitter 추가
    vBoxLayout->addWidget(splitter);
    setLayout(vBoxLayout); // QVBoxLayout을 위젯의 레이아웃으로 설정
}

// Widget 소멸자 정의
Widget::~Widget() {}

