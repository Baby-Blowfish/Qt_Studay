#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVector>

class QLabel;
class QPushButton;
class QButtonGroup;

// 전방 참조, 헤더파일을 include 하는 것보다 가벼움
// 객체 선언까지만 가능 그 이외에 내부에 접근하려면 헤더파일을 include 해야함.

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    QLabel *m_label;    // 헝가리안 표기법 사용(클래스의 멤버 변수)
    QVector<QPushButton*> m_buttons;
    QString m_num1,m_op;
    bool m_isFirst;
    const qint32 WIDTH = 4; // q붙은것은 qt의 자료형임
    // 상수를 정의시 define문은 메모리을 잡지 않지만 컴파일라가 자료형을 특정하지 못하므로 에러를 잡지 못함.
    // const 문은 메모리에 잡히지만 컴파일러가 타입을 검사하므로 에러를 확인 할 수 있음.

    QButtonGroup *buttonGroup;
    QPushButton* button = nullptr;

public slots:
    void setNum();
    void setOp();
    void clear();
    void calculator();
    void click(int id);
};
#endif // WIDGET_H
