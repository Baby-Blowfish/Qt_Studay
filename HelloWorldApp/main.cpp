#include "widget.h"

#include <QApplication> // 헤더파일 이름은 클래스 이름과 동일
#include <QLabel>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // 클래스는 모두 파스칼 표기법 사용
    // 항상 하나의 QApllication 클래스 객체를 가지고 있어야함.
    // 다른 Qt의 객체들보다 먼저 선언되어야 함. 전역변수로 다른 클래스가 선언되는 경우 런타임 오류 발생!
    // Qt를 사용할 있도록 초기화 하고, 사용자의 명령행 인수를 처리
    // exec() 메소드로 이벤트를 처리

    QLabel hello("<font color = blue> Hello<i>Qt!</i></font>",0);
    // GUI 객체, 화면에 lable을 만듬
    // 첫 인자 : 화면에 표시될 문자열(HTML 사용한 리치 텍스트 사용 가능)
    // 두번쨰 인자 :
    hello.show();
    return a.exec();
}


// int main(int argc, char *argv[])
// {

//     QApplication a(argc, argv);
//     Widget w;
//     w.show();
//     return a.exec();
// }
