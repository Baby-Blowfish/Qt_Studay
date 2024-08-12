/*-----------------------------------main cpp-----------------------------------------*/

#include "widget.h"
#include <QApplication>

// 프로그램의 진입점
int main(int argc, char *argv[])
{
    QApplication a(argc, argv); // QApplication 객체를 생성합니다.
    widget w; // widget 객체를 생성합니다.
    w.resize(500,500); // 위젯의 크기를 설정합니다.
    w.show(); // 위젯을 화면에 표시합니다.
    return a.exec(); // 이벤트 루프를 실행합니다.
}
