/*-----------------------------------Class header-------------------------------------*/
#ifndef BUTTONWIDGET_H
#define BUTTONWIDGET_H

#include <QWidget>

// 버튼과 관련된 위젯들을 전방 선언합니다.
class QPushButton;
class QRadioButton;
class QCheckBox;
class QButtonGroup;
class QLabel;

// widget 클래스 정의, QWidget을 상속받습니다.
class widget : public QWidget
{
    Q_OBJECT

public:
    widget(QWidget *parent = nullptr); // 생성자 선언
    ~widget(); // 소멸자 선언

private:
    // QPushButton, QRadioButton, QCheckBox, QButtonGroup, QLabel 멤버 변수 선언
    QPushButton *pushButton;

    QRadioButton *radioButton[4];
    QButtonGroup *buttonGroupRadio;

    QCheckBox *checkBoxButton[4];
    QButtonGroup *buttonGroupCheck;

    QLabel *label;

public slots:
    void selectButton(int id); // 슬롯 함수 선언
};
#endif // BUTTONWIDGET_H

