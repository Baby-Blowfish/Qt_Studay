/*-----------------------------------Class header-------------------------------------*/
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

// -------------------------------<사용자 정의 위젯>-----------------------------------------------
// QWidget를 상속 받아야함!
// 이 클래스는 QWidget을 상속받아 사용자의 요구에 맞게 커스터마이징된 위젯을 만듭니다.
class QPushButton;
class QLabel;

class Widget:public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);    // 생성자의 인자로 부모 클래스를 지정
    // 생성자는 QWidget을 부모로 받아들여 필요 시 부모 위젯에 접근할 수 있도록 합니다.
    ~Widget();   // 소멸자, 동적으로 할당된 메모리를 해제하거나 리소스를 정리하는 역할을 합니다.

private:
    QPushButton *quit;  // Quit 버튼을 나타내는 포인터
    QLabel *label;      // 라벨을 나타내는 포인터

public slots:
    void slotQuit();  // 사용자 정의 슬롯 함수, 버튼 클릭 시 호출
    void emitSignalButtonOn(int i);  // 버튼이 눌릴 때 발생하는 시그널을 보내는 함수
    void emitSignalButtonOff(int i); // 버튼이 놓일 때 발생하는 시그널을 보내는 함수

signals:
    void mySignal(int n);   // 사용자 정의 시그널, 특정 조건에서 발생

};

#endif // WIDGET_H

