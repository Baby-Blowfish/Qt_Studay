/*-----------------------------------main cpp-----------------------------------------*/
#include <widget.h>
#include <QWidget>
#include <QApplication> // 헤더파일 이름은 클래스 이름과 동일
#include <QLabel>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);  // QApplication 객체를 생성
        // 클래스는 모두 파스칼 표기법 사용
        // 항상 하나의 QApplication 클래스 객체를 가지고 있어야함.
        // 다른 Qt의 객체들보다 먼저 선언되어야 함. 전역변수로 다른 클래스가 선언되는 경우 런타임 오류 발생!
        // Qt를 사용할 수 있도록 초기화 하고, 사용자의 명령행 인수를 처리
        // exec() 메소드로 애플리케이션이 종료되지 않도록 루프를 돌면서 이벤트를 처리

    // -----------------------<메인 윈도우>------------------------
    QWidget mainWidget;  // 메인 윈도우 객체 생성
    mainWidget.setGeometry(0,0,300,300);  // 메인 윈도우의 위치와 크기 설정

    // --------------------------<서브 윈도우>---------------------------------
    Widget w(&mainWidget);  // Widget 객체 생성, 부모 위젯으로 mainWidget을 지정
        // Widget을 QLabel과 QPushButton의 부모 윈도우로 사용
    w.move(0,0);
    w.resize(100,100);  // 사용자 정의 위젯인 Widget(자식 윈도우) 윈도우 크기 설정

    //--------------------------------<사용자 정의 시그널>----------------------------------------
    QPushButton signal("mainWindowButton", &mainWidget);  // 버튼 객체 생성, 부모는 mainWidget
    signal.setGeometry(0,100,200,35);  // 버튼의 위치와 크기 설정
    QLabel slgnalLabel("mainWindowLabel", &mainWidget);  // 라벨 객체 생성, 부모는 mainWidget
    slgnalLabel.setGeometry(0,135,200,35);  // 라벨의 위치와 크기 설정

    // 슬롯을 람다 함수로 표현
    QWidget::connect(&signal,&QPushButton::pressed,&slgnalLabel,[&](){slgnalLabel.setText("<b>Hello</b>"); w.emitSignalButtonOn(10);});
    QWidget::connect(&signal,&QPushButton::released,&slgnalLabel,[&](){slgnalLabel.setText("<b>Hi</b>"); w.emitSignalButtonOff(5);});
        // QPushButton이 눌린 상태일 때는 QLabel에 "Hello"를 설정하고, 버튼 온 시그널을 보냄
        // 뗀 상태일 때는 QLabel에 "Hi"를 설정하고, 버튼 오프 시그널을 보냄
    Widget::connect(&w,SIGNAL(mySignal(int)),&w,SLOT(emitSignal(int)));
        // 사용자 정의 시그널과 슬롯을 연결

    // 사용자 정의 슬롯 대신 c++11의 람다 함수를 이용해서 처리 가능

    mainWidget.show();  // 메인 윈도우를 화면에 표시

    return a.exec();  // 이벤트 루프를 실행
}

