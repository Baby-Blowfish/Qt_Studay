/*-----------------------------------Class header-------------------------------------*/
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

// 전방 선언: 필요한 클래스들을 미리 선언하여 컴파일 속도를 높임
class QFrame;
class QGroupBox;
class QFormLayout;

class QHBoxLayout;
class QVBoxLayout;
class QGridLayout;

class QLabel;
class QDial;

class QVBoxLayout;

// Widget 클래스 정의
class Widget : public QWidget
{
    Q_OBJECT

public:
    // 생성자와 소멸자 선언
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    // QFrame 위젯에 대한 포인터 멤버 변수 선언
    QFrame *plainLine; // 평범한 선
    QFrame *raisedLine; // 돌출된 선
    QFrame *sunkenLine; // 움푹 들어간 선

    // QLabel 위젯에 대한 포인터 멤버 변수 선언
    QLabel *label; // 일반 라벨
    QLabel *label1; // 다른 라벨

    // QDial 위젯에 대한 포인터 멤버 변수 선언
    QDial *dial; // 다이얼 1
    QDial *dial1; // 다이얼 2
    QDial *dial2; // 다이얼 3

    // QVBoxLayout 위젯에 대한 포인터 멤버 변수 선언
    QVBoxLayout *vBoxLayout; // 수직 레이아웃
};
#endif // WIDGET_H

