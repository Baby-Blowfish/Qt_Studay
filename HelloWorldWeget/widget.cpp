#include "widget.h"
#include <QPushButton>
#include <QApplication>
#include <QLabel>



Widget::Widget(QWidget *parent) : QWidget(parent)
{
    // -------------------------------<사용자 정의 위젯>-----------------------------------------------
    // quit = new QPushButton("Quit", this);
    //     // 동적 할당 : 생성자에서 만드므로 stack이 아닌 heap 만들어야 사라지지 않음
    //     // QPushButton 객체에서 별도의 위젯 창을 여는 것이 아닌, 사용자 정의 위젯인 Widget에서 열려야 하므로
    //     // Widget 클래스의 주소인 this로 설정
    // quit -> resize(75,35);  // QPushButton 위젯의 크기 설정
    // this->resize(200,300);  // 사용자 정의 위젯인 Widget의 윈도우 크기 설정
    // move(300,300);          // this 생략 가능.
    // QObject::connect(quit,SIGNAL(clicked()),qApp,SLOT(quit()));
    //     // qApp은 QApplication 클래스의 전역 인스턴스 #include <QApplication> 필요!





    //---------------------------------<부모 윈도우와 자식 위젯>------------------------------------
    // quit = new QPushButton("Quit", this);
    // quit -> move(10,10);
    // quit -> resize(75,35);

    // QObject::connect(quit,SIGNAL(clicked()),qApp,SLOT(quit()));


    // label = new QLabel("<font color = blue> Hello Qt!</font>",this);
    // label->setGeometry(10,50,75,35);







    // //----------------------------------<사용자 정의 슬롯>--------------------------------------
    // quit = new QPushButton("&Quit", this);
    // quit -> resize(75,35);
    // connect(quit,SIGNAL(clicked()),this,SLOT(slotQuit())); // this 생략 가능
    //     //connect(quit,&QPushButton::clicked,[](){qApp -> quit();});
    //     // 사용자 정의 슬롯 대신 c++11의 람다 함수를 이용해서 처리 가능



    //----------------------------------<사용자 정의 시그널>--------------------------------------
    quit = new QPushButton("&Quit", this);
    quit -> resize(75,35);
    connect(quit,SIGNAL(clicked()),this,SLOT(slotQuit())); // this 생략 가능
        //connect(quit,&QPushButton::clicked,[](){qApp -> quit();});
        // 사용자 정의 슬롯 대신 c++11의 람다 함수를 이용해서 처리 가능

}

// ------------------사용자 정의 슬롯은 구현 필수!-------------------------------
// void Widget::slotQuit()
// {
//     qDebug("slotQuit");
//     qApp->quit();
// }

// ------------------사용자 정의 시그널은 구현 안함!----------------------------
// void Widget::slotQuit()
// {
//     qDebug("slotQuit");
//     emit clicked();     // 시그널은 호출하는것이 아닌 emit키워드로 발생시킴
// }

Widget::~Widget()
{}
