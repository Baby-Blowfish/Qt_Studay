/*-----------------------------------Class header-------------------------------------*/
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>  // QWidget 클래스 포함
#include <QVector>  // QVector 클래스 포함

class QLabel;  // QLabel 클래스 전방 선언
class QPushButton;  // QPushButton 클래스 전방 선언

// Widget 클래스 선언, QWidget을 상속받음
class Widget : public QWidget
{
    Q_OBJECT  // Qt의 시그널과 슬롯 매커니즘을 사용하기 위한 매크로

public:
    // 생성자와 소멸자 선언
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QLabel *m_label;  // QLabel 멤버 변수, 헝가리안 표기법 사용
    QVector<QPushButton*> m_buttons;  // QPushButton 포인터의 벡터
    QString m_num1, m_op;  // 첫 번째 숫자와 연산자 저장을 위한 QString
    bool m_isFirst;  // 첫 번째 입력 여부를 체크하는 불리언 변수
    const qint32 WIDTH = 4;  // 버튼 배열의 폭, 정수형 상수

public slots:
    void setNum();  // 숫자 버튼이 눌렸을 때 호출되는 슬롯
    void setOp();  // 연산자 버튼이 눌렸을 때 호출되는 슬롯
    void clear();  // 클리어 버튼이 눌렸을 때 호출되는 슬롯
    void calculator();  // 계산 버튼이 눌렸을 때 호출되는 슬롯
};
#endif // WIDGET_H

