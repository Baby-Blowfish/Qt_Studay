#ifndef WIDGET_H  // 이 파일이 중복 포함되지 않도록 하는 전처리기 지시문
#define WIDGET_H  // 이 파일이 중복 포함되지 않도록 하는 전처리기 지시문

#include <QWidget>  // QWidget 클래스를 포함하는 헤더 파일
#include <QVector>  // QVector 클래스를 포함하는 헤더 파일

class QLabel;  // QLabel 클래스에 대한 전방 선언
class QPushButton;  // QPushButton 클래스에 대한 전방 선언
class QButtonGroup;  // QButtonGroup 클래스에 대한 전방 선언

// Widget 클래스 정의, QWidget을 상속받음
class Widget : public QWidget
{
    Q_OBJECT  // Qt의 시그널과 슬롯 메커니즘을 사용하기 위한 매크로

public:
    Widget(QWidget *parent = nullptr);  // 생성자 선언, 기본 인수는 nullptr
    ~Widget();  // 소멸자 선언

private:
    QLabel *m_label;  // QLabel 객체에 대한 포인터, 헝가리안 표기법 사용
    QVector<QPushButton*> m_buttons;  // QPushButton 객체에 대한 포인터를 저장하는 QVector
    QString m_num1, m_op;  // 첫 번째 숫자와 연산자를 저장할 QString 변수
    bool m_isFirst;  // 첫 번째 입력 여부를 저장할 bool 변수
    const qint32 WIDTH = 4;  // 상수로 정의된 너비, qint32는 Qt의 정수형

    QButtonGroup *buttonGroup;  // QButtonGroup 객체에 대한 포인터
    QPushButton* button = nullptr;  // 현재 클릭된 버튼을 저장할 포인터, 초기값은 nullptr

public slots:
    void setNum();  // 숫자를 설정하는 슬롯 함수
    void setOp();  // 연산자를 설정하는 슬롯 함수
    void clear();  // 계산기를 초기 상태로 리셋하는 슬롯 함수
    void calculator();  // 계산을 수행하는 슬롯 함수
    void click(int id);  // 버튼 클릭 시 호출되는 슬롯 함수, 클릭된 버튼의 id를 인수로 받음
};

#endif // WIDGET_H  // 파일의 끝을 알리는 전처리기 지시문
