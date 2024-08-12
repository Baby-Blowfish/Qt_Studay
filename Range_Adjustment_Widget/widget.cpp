/*--------------------------------Class cpp-------------------------------------------*/
#include "widget.h"
#include <QSlider>
#include <QStyleFactory>
#include <QScrollBar>
#include <QLabel>
#include <QScrollArea>
#include <QDial>
#include <QSpinBox>

// Widget 생성자 정의
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //---------------------------------------<QSlider>-----------------------------------------
    slider = new QSlider(this); // QSlider 인스턴스 생성
    slider->setOrientation(Qt::Horizontal); // 슬라이더를 수평으로 설정
    slider->setTickPosition(QSlider::TicksAbove); // 틱 마크를 슬라이더 위에 표시
    slider->setStyle(QStyleFactory::create("Fusion")); // 스타일을 Fusion으로 설정
    slider->setRange(0,150); // 슬라이더의 범위를 0에서 150으로 설정
    slider->setValue(50); // 초기 값을 50으로 설정
    slider->move(0,0); // 슬라이더의 위치 설정
    slider->resize(300,50); // 슬라이더의 크기 설정

    //-------------------------------<QScrollBar>--------------------------------------------
    label = new QLabel("1234567890123456789012345678901234567890",this); // QLabel 인스턴스 생성
    scrollArea = new QScrollArea(this); // QScrollArea 인스턴스 생성
    scrollArea->setBackgroundRole((QPalette::Light)); // 배경을 밝은 색으로 설정
    scrollArea->setWidget(label); // QLabel을 QScrollArea에 설정
    scrollArea->move(0,50); // QScrollArea 위치 설정
    scrollArea->show(); // QScrollArea 표시
    scrollArea->resize(200,50); // QScrollArea 크기 설정
    scrollBar = scrollArea->horizontalScrollBar(); // 수평 스크롤바 가져오기
    scrollBar->setValue(scrollBar->maximum()); // 스크롤바를 끝까지 이동

    //-------------------------------<QDial>--------------------------------------
    dial = new QDial(this); // QDial 인스턴스 생성
    dial->setGeometry(0,120,100,100); // QDial 위치 및 크기 설정
    dial->setWrapping(true); // 다이얼이 끝에서 다시 시작되도록 설정
    dial->setNotchesVisible(true); // 노치 표시
    dial->setNotchTarget(40); // 노치 간격 설정

    //--------------------------------<QSpinBox>-------------------------------------
    spinBox = new QSpinBox(this); // QSpinBox 인스턴스 생성
    spinBox-> move(120,120); // QSpinBox 위치 설정
    spinBox->resize(300,100); // QSpinBox 크기 설정
    spinBox->setRange(0,10); // 범위를 0에서 10으로 설정
    spinBox->setSuffix("%"); // 접미어를 %로 설정
    spinBox->setWrapping(true); // 값이 끝에서 다시 시작되도록 설정
    spinBox->setSpecialValueText("Percent"); // 초기값을 Percent로 설정
}

// Widget 소멸자 정의
Widget::~Widget() {}

