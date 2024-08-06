#include "widget.h"
#include "ui_widget.h"
#include <QApplication>
#include <QPushButton>
#include <QLabel>

// Widget::Widget(QWidget *parent)
//     : QWidget(parent)
//     , ui(new Ui::Widget)
// {
//     ui->setupUi(this);
// }

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    // 사용자 정의 위젯
    //QPushButton *quit = new QPushButton("Quit", this);
    //    // 생성자에서 만드므로 stack이 아닌 heap 만들어야 사라지지 않음
    //quit -> resize(75,35);
    // QObject::connect(quit,SIGNAL(clicked()),qApp,SLOT(quit()));

    // 부모 윈도우와 자식 위젯
    // QPushButton *quit = new QPushButton("Quit", this);
    // quit -> move(10,10);
    // quit -> resize(75,35);

    // QObject::connect(quit,SIGNAL(clicked()),qApp,SLOT(quit()));
    //     // qApp은 QApplication 클래스의 전역 인스턴스 #include <QApplication> 필요!

    // QLabel *label = new QLabel("<font color = blue> Hello Qt!</font>",this);
    // label->setGeometry(10,50,75,35);

    // 사용자 정의 슬롯
    QPushButton *quit = new QPushButton("&Quit", this);
    quit -> resize(75,35);
    connect(quit,SIGNAL(clicked()),this,SLOT(slotQuit())); // this 생략 가능
        //connect(quit,&QPushButton::clicked,[](){qApp -> quit();});
        // 사용자 정의 슬롯 대신 c++11의 람다 함수를 이용해서 처리 가능

}

// 사용자 정의 슬롯은 구현 필수!
void Widget::slotQuit()
{
    qDebug("slotQuit");
    qApp->quit();
    emit clicked();     // 시그널은 호출하는것이 아닌 emit키워드로 발생시킴
}

Widget::~Widget()
{
    delete ui;
}
