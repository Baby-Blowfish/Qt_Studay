/*-----------------------------------main cpp-----------------------------------------*/
#include "widget.h"
#include <QApplication>

// 프로그램의 진입점
int main(int argc, char *argv[])
{
    QApplication a(argc, argv); // QApplication 객체 생성

    Widget w; // Widget 객체 생성
    w.show(); // 위젯 표시

    return a.exec(); // 이벤트 루프 실행
}
