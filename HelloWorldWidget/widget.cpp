/*--------------------------------Class cpp-------------------------------------------*/

#include "widget.h"
#include <QPushButton>
#include <QApplication>
#include <QLabel>

Widget::Widget(QWidget *parent) : QWidget(parent)
{

    // -------------------------------<사용자 정의 위젯>-----------------------------------------------
    // ------------------------<QPushButton 객체 : 버튼 GUI 생성, 누르면 이벤트 발생>--------------------
    quit = new QPushButton("&Quit",this);
        // QPushButton(QWidget *parent = nullptr)
        // QPushButton(const QString &text, QWidget *parent = nullptr)
        // QPushButton(const QIcon &icon, const QString &text, QWidget *parent = nullptr)
        // text : 버튼에 표시될 문자열(리치 텍스트 불가능)
        // parent : QPushButton이 들어가야할 부모 위젯 설정
        // shortcut key설정 : 문자앞에 & 붙임, 여기선 ALT+Q하면 버튼 실행, 단 버튼 GUI가 떠있을 경우만 해당
        // 동적 할당 : 생성자에서 만드므로 stack이 아닌 heap 만들어야 사라지지 않음
        // QPushButton 객체에서 별도의 위젯 창을 여는 것이 아닌, 사용자 정의 위젯인 Widget에서 열려야 하므로
        // Widget 클래스의 주소인 this로 설정

    quit -> move(0,0);       // QPushButton의 위치 설정
    quit -> resize(75,35);  // QPushButton(자식 윈도우) 위젯의 크기 설정

    // ----------------------<QLabel 객체 : 화면에 레이블을 만드는 GUI 객체>--------------------------
    label = new QLabel ("<font color = blue> Hello<i>Qt!</i></font>",this);
        // QLabel(const QString &text, QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags())
        // text : 화면에 표시될 문자열(HTML 사용한 리치 텍스트 사용 가능)
        // QLabel이 들어가야할 부모 위젯 설정, 자식 위젯은 부모 위젯의 공간 내에서 표시됨.
        // 별도의 창(top-level-widget)으로 열어야 하는 경우 부모 위젯을 지정할 수 없는데 이때 0 또는 nullptr 사용
        // 객체 생성시 메모리에만 존재 사용자에게 보이지 않음
    label->setGeometry(0,35,75,35);  // QLabel의 위치와 크기 설정
        // QWidget 클래스의 show()메소드 사용, 임베디드 장비의 경우 속성설정 완료 후 show() 메소드 사용

    // //----------------------------------<기본 슬롯>--------------------------------------
    QObject::connect(quit,SIGNAL(clicked()),qApp,SLOT(quit()));
        // qApp은 QApplication 클래스의 전역 인스턴스 #include <QApplication> 필요!
        //connect(quit,&QPushButton::clicked,[](){qApp -> quit();});
        // 사용자 정의 슬롯 대신 c++11의 람다 함수를 이용해서 처리 가능
        // QObject::connect(const QObject *sender, const char *signal,
        //                    const QObject *receiver, const char *method,
        //                    Qt::ConnectionType type = Qt::AutoConnection
        // signal : 이벤트가 발생함을 알리는 역할
        // slot : 특정 시그널과 연결되어서 사용자의 요구를 처리하는 역할
        // sender : 시그널을 발생시킬 객체의 포인터를 지정
        // signal : 첫번째 매개변수로 지정된 객체(sender)가 발생시키는 시그널을 지정, SIGNAL()매크로 사용
        // void clicked(bool checked = false)
        // void pressed()
        // void released()
        // void toggled(bool checked)
        // receiver : 시그널을 받을 객체의 포인터를 지정, this인 경우 생략 가능
        // method : 세 번째 매개변수에 지정된 객체(receiver)에 정의된 슬롯을 지정, SLOT()매크로 사용
        // QApplication class의 부모 클래스인 QCoreApplication class에서 애플리케이션을 종료하는 quit() 슬롯을 제공함.

}

//------------------사용자 정의 슬롯은 구현 필수!, 사용자 정의 시그널은 구현 안함!
//슬롯은 특정 시그널과 연결되어 사용자 요청을 처리하는 역할을 합니다.
void Widget::slotQuit()
{
    qDebug("slotQuit");  // 디버그 메시지를 출력합니다.
    qApp->quit();  // 애플리케이션을 종료합니다.
}

void Widget::emitSignalButtonOn(int i)
{
    qDebug("ButtonOn flag %d",i);  // 버튼이 눌릴 때 디버그 메시지를 출력합니다.
}
void Widget::emitSignalButtonOff(int i)
{
    qDebug("ButtonOff flag %d",i); // 버튼이 놓일 때 디버그 메시지를 출력합니다.
}
Widget::~Widget()
{}

