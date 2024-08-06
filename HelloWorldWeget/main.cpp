#include "widget.h"

#include <QApplication> // 헤더파일 이름은 클래스 이름과 동일
#include <QLabel>
#include <QPushButton>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
        // 클래스는 모두 파스칼 표기법 사용
        // 항상 하나의 QApllication 클래스 객체를 가지고 있어야함.
        // 다른 Qt의 객체들보다 먼저 선언되어야 함. 전역변수로 다른 클래스가 선언되는 경우 런타임 오류 발생!
        // Qt를 사용할 있도록 초기화 하고, 사용자의 명령행 인수를 처리
        // exec() 메소드로 애플리케이션이 종료되지 않도록 루프르 돌면서 이벤트를 처리

    //QLabel hello("<font color = blue> Hello<i>Qt!</i></font>",0);
        // GUI 객체, 화면에 lable을 만듬
        // 첫 인자 : 화면에 표시될 문자열(HTML 사용한 리치 텍스트 사용 가능)
        // 두번쨰 인자 : QLabel이 들어가야할 부모 위젯 설정, 별도의 창으로 열어야 하는 경우 0 또는 nullptr
    // hello.resize(75,35);
    // hello.move(800,100);
    // hello.show();

    //QPushButton quit("Quit",0);
        // 첫인자 : 버튼에 표시될 문자열(리치 텍트스 불가능)
        // signal : 이벤트가 발생함을 알리는 역할
        // slot : 특정 시그널과 연결되어서 사용자의 요구를 처리하는 역할
        // 두번쨰 인자 : QPushButton이 들어가야할 부모 위젯 설정

    // quit.resize(75,35);
    // quit.move(300,300);
    // QObject::connect(&quit,SIGNAL(clicked()),&a,SLOT(quit()));
        // QObject::connect(const QObject *sender, const char *signal,
        //                    const QObject *receiver, const char *method,
        //                    Qt::ConnectionType type = Qt::AutoConnection
        // sender : 시그널을 발생시킬 객체의 포인터를 지정
        // signal : 첫번째 매개변수로 지정된 객체(sender)가 발생싴니는 시그널을 지정
        // void clicked(bool checked = false)
        // void pressed()
        // void released()
        // void toggled(bool checked)
        // receiver : 시그널을 받을 객체의 포인터를 지정
        // method : 세 번째 매개변수에 지정된 객체(receiver)에 정의된 슬롯을 지정
    // QApplication class의 부모 클래스인 QCoreApplication class에서 어플리케이션을 종료하는 quit() 슬롯을 제공함.
    // quit.show();



    // Qlabel과 QPushButton의 혼용
    // QWidget w;
    // QLabel hello("<font color = blue> Hello<i>Qt!</i></font>",&w);
    // hello.resize(75,35);

    // QPushButton quit("Quit",0);
    // quit.move(10,40);
    // quit.resize(75,35);
    // //quit.setGeometry(10,40,75,35);
    // QObject::connect(&quit,&QPushButton::clicked,&hello,[&](){hello.setText("<b>Hi</b>");});
    //     // 람다함수 식 쓴거임.
    // quit.show();
    // w.show();


    // 사용자 정의 위젯
    // Widget w;
    // w.show();

    // 부모 윈도우와 자식 위젯
    // Widget w;
    // QLabel *label = new QLabel("<font size = 20>Hello,World!</font>",&w);
    // label->setGeometry(10,90,75,35);
    // w.show();


    // 사용자 정의 슬롯
    Widget *w = new Widget(0);
    QObject::connect(w,SIGNAL(clicked()),&a,SLOT(quit()));
    w->show();


    return a.exec();
}


// int main(int argc, char *argv[])
// {

//     QApplication a(argc, argv);
//     Widget w;
//     w.show();
//     return a.exec();
// }
