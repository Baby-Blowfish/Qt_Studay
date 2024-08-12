/*-----------------------------------Class header-------------------------------------*/
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

// QLCDNumber, QProgressBar, QTimer, QUrl, QTextBrowser 클래스 전방 선언
class QLCDNumber;
class QProgressBar;
class QTimer;
class QUrl;
class QTextBrowser;

// Widget 클래스 정의, QWidget을 상속받음
class Widget : public QWidget
{
    Q_OBJECT

    // 위젯 멤버 변수 선언
    QLCDNumber *lcd;           // LCD 숫자 디스플레이 위젯
    QProgressBar *progBar;     // 진행 바 위젯
    QTimer *timer;             // 타이머 객체
    QUrl *url;                 // URL 객체
    QTextBrowser *tb;          // 텍스트 브라우저 위젯

public:
    // 생성자와 소멸자 선언
    Widget(QWidget *parent = nullptr);
    ~Widget();
};

#endif // WIDGET_H
