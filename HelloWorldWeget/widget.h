#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>


// -------------------------------<사용자 정의 위젯>-----------------------------------------------
// QWidget를 상속 받아야함!
class QPushButton;
class QLabel;

class Widget:public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);    // 생성자의 인자로 부모 클래스를 지정
    ~Widget();

private:
    QPushButton *quit;
    QLabel *label;

public slots:
    void slotQuit();

signals:
    void clicked();
};

#endif // WIDGET_H
