/*-----------------------------------Class header-------------------------------------*/
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

// 전방 선언(Forward declaration): 클래스 정의 전에 클래스를 참조할 수 있도록 함
class QPushButton;
class QHBoxLayout;
class QVBoxLayout;
class QGridLayout;
class QDial;
class QLabel;
class QCalendarWidget;
class QTextEdit;

// 행과 열의 개수를 정의
#define NO_OF_ROW 3
#define NO_OF_colum 5

// Widget 클래스 정의
class Widget : public QWidget
{
    Q_OBJECT

public:
    // 생성자와 소멸자 선언
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    // 각 버튼과 레이아웃에 대한 포인터 멤버 변수 선언
    QPushButton *pushbuttonVBoxLayout[3]; // 수직 레이아웃에 있는 버튼
    QPushButton *pushbuttonHBoxLayout[3]; // 수평 레이아웃에 있는 버튼
    QPushButton *pushButtonGridLayout[NO_OF_ROW*NO_OF_colum]; // 그리드 레이아웃에 있는 버튼

    QHBoxLayout *hBoxLayout; // 수평 레이아웃
    QVBoxLayout *vBoxLayout; // 수직 레이아웃
    QGridLayout *gridLayout; // 그리드 레이아웃

    QDial *dial; // 다이얼
    QLabel *label; // 레이블
    QCalendarWidget *calendarWidget; // 캘린더 위젯
    QTextEdit *textEdit; // 텍스트 편집기
};
#endif // WIDGET_H

