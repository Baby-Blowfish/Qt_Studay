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






    // ----------------------<QLabel 객체 : 화면에 레이블을 만드는 GUI 객체>--------------------------
    // QLabel hello("<font color = blue> Hello<i>Qt!</i></font>",0);
    //     // QLabel(const QString &text, QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags())
    //     // text : 화면에 표시될 문자열(HTML 사용한 리치 텍스트 사용 가능)
    //     // f : QLabel이 들어가야할 부모 위젯 설정, 자식 위젯은 부모 위젯의 공간 내에서 표시됨.
    //     // 별도의 창(top-level-widget)으로 열어야 하는 경우 부모 위젯을 지정할 수 없는데 이때 0 또는 nullptr 사용
    //     // 객체 생성시 메모리에만 존재 사용자에게 보이지 않음
    // hello.resize(75,35);
    // hello.move(250,100);
    // hello.show();
    //     // QWidget 클래스의 show()메소드 사용, 임베디드 장비의 경우 속성설정 완료 후 show() 메소드 사용






    // ------------------------<QPushButton 객체 : 버튼 gui 생성, 누르면 이벤트 발생>--------------------
    // QPushButton quit("&Quit",0);
    //     // QPushButton(QWidget *parent = nullptr)
    //     // QPushButton(const QString &text, QWidget *parent = nullptr)
    //     // QPushButton(const QIcon &icon, const QString &text, QWidget *parent = nullptr)
    //     // text : 버튼에 표시될 문자열(리치 텍스트 불가능)
    //     // parent : QPushButton이 들어가야할 부모 위젯 설정
    //     // shortcut key설정 : 문자앞에 & 붙임, 여기선 ALT+Q하면 버튼 실행, 단 버튼 GUI가 떠있을 경우만 해당
    // quit.resize(75,35);
    // quit.move(250,100);
    // QObject::connect(&quit,SIGNAL(clicked()),&a,SLOT(quit()));
    //     // QObject::connect(const QObject *sender, const char *signal,
    //     //                    const QObject *receiver, const char *method,
    //     //                    Qt::ConnectionType type = Qt::AutoConnection
    //     // signal : 이벤트가 발생함을 알리는 역할
    //     // slot : 특정 시그널과 연결되어서 사용자의 요구를 처리하는 역할
    //     // sender : 시그널을 발생시킬 객체의 포인터를 지정
    //     // signal : 첫번째 매개변수로 지정된 객체(sender)가 발생시키는 시그널을 지정, SIGNAL()매크로 사용
    //         // void clicked(bool checked = false)
    //         // void pressed()
    //         // void released()
    //         // void toggled(bool checked)
    //     // receiver : 시그널을 받을 객체의 포인터를 지정, this인 경우 생략 가능
    //     // method : 세 번째 매개변수에 지정된 객체(receiver)에 정의된 슬롯을 지정, SLOT()매크로 사용
    //     // QApplication class의 부모 클래스인 QCoreApplication class에서 어플리케이션을 종료하는 quit() 슬롯을 제공함.
    // quit.show();







    // --------------------------<Qlabel과 QPushButton의 혼용>---------------------------------
    // QWidget w;
    //     // 2개 이상의 위젯을 하나의 윈도우에 올리려면 새로운 위젯이 필요
    //     // QWidget를 윈도우로 사용하고 QLabel과 QPushButton의 부모 위젯으로 설정
    // QLabel hello("<font color = blue> Hello<i>Qt!</i></font>",&w);
    //     // 부모위젯의 주소를 적어야함.
    // hello.move(10,10);
    // hello.resize(75,35);
    // QPushButton quit("Quit",&w);
    // quit.move(100,10);
    // quit.resize(75,35);
    //     //quit.setGeometry(10,40,75,35);
    // QObject::connect(&quit,&QPushButton::pressed,&hello,[&](){hello.setText("<b>Hi</b>");});
    //     // 눌린 상태일 때는 Hi, 슬롯을 람다 함수로 표현
    // QObject::connect(&quit,&QPushButton::released,&hello,[&](){hello.setText("<b>hello</b>");});
    //     // 뗀 상태일 때는 hello
    // quit.show();
    // w.show();





    // -------------------------------- <사용자 정의 위젯>-----------------------------------------
    // Widget w;
    // w.show();





    //------------------------------- <부모 윈도우와 자식 위젯>---------------------------------
    // Widget w;
    // QLabel *label = new QLabel("<font size = 20>Hello,World!</font>",&w);
    // label->setGeometry(10,90,75,35);
    // w.show();


    //--------------------------------<사용자 정의 슬롯>----------------------------------------
    // Widget *w = new Widget(0);
    // w->show();




    //--------------------------------<사용자 정의 시그널>----------------------------------------
    // Widget *w = new Widget(0);
    // QObject::connect(w,SIGNAL(clicked()),&a,SLOT(quit()));
    // w->show();


    return a.exec();
}



