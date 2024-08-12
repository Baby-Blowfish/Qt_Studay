/*-----------------------------------Class header-------------------------------------*/
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

// 전방 선언(Forward declaration): 클래스 정의 전에 클래스를 참조할 수 있도록 함
class QLineEdit;
class QComboBox;
class QTextEdit;

// Widget 클래스 정의
class Widget : public QWidget
{
    Q_OBJECT

public:
    // 생성자와 소멸자 선언
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    // 각 위젯에 대한 포인터 멤버 변수 선언
    QLineEdit *lineEdit;
    QTextEdit *textEdit;
    QComboBox *comboBox;
};
#endif // WIDGET_H

