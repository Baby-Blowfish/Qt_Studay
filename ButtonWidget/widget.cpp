/*--------------------------------Class cpp-------------------------------------------*/
#include "widget.h"
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QRadioButton>
#include <QCheckBox>
#include <QButtonGroup>

widget::widget(QWidget *parent)
    : QWidget(parent) // 부모 클래스의 생성자를 호출하여 초기화합니다.
{
    // --------------------------<QPushButton 위젯>------------------------------------------------
    pushButton = new QPushButton("PushButton", this); // QPushButton 객체를 생성하고 초기화합니다.
    pushButton->setGeometry(0, 0, 100, 20); // 버튼의 위치와 크기를 설정합니다.
    pushButton->setCheckable(true); // 버튼을 체크 가능한 상태로 설정합니다.
    QObject::connect(pushButton, &QPushButton::toggled,
                     [&](bool flag) { // 버튼이 토글될 때 호출되는 람다 함수입니다.
                         qDebug() << "toggled"; // 디버그 메시지를 출력합니다.
                         if (!flag) qApp->quit(); // 버튼이 체크 해제되면 애플리케이션을 종료합니다.
                     });

    // ---------------------------<QRadioButton 위젯>------------------------------------------------
    buttonGroupRadio = new QButtonGroup(this); // QButtonGroup 객체를 생성합니다.
    for (int i = 0; i < 4; i++)
    {
        QString str = QString("RadioButton %1").arg(i + 1); // 각 라디오 버튼의 텍스트를 설정합니다.
        radioButton[i] = new QRadioButton(str, this); // 라디오 버튼 객체를 생성하고 초기화합니다.
        radioButton[i]->setGeometry(0, 20 + 20 * i, 100, 20); // 라디오 버튼의 위치와 크기를 설정합니다.
        buttonGroupRadio->addButton(radioButton[i]); // 라디오 버튼을 버튼 그룹에 추가합니다.
    }
    // `arg()` 함수는 문자열 내의 자리 표시자를 다른 값으로 교체하는 함수입니다. 자리 표시자는 "%1", "%2" 형식으로 사용되며, `arg()` 함수는 이를 순서대로 바꿉니다. 이는 코드의 가독성을 높이고, 다국어 지원 및 에러 방지에 유용합니다.
    // 1. 자리 표시자를 사용하여 문자열을 정의합니다.
    // 2. `arg()` 함수를 호출하여 자리 표시자를 실제 값으로 교체합니다.
    // 3. 다국어 메시지 지원, 반복된 자리 표시자 처리, 가독성 향상, 에러 방지 등의 이점이 있습니다.

    // ---------------------------<QCheckBox 위젯>------------------------------------------------
    label = new QLabel(this); // QLabel 객체를 생성하고 초기화합니다.
    label->setGeometry(0, 100, 400, 20); // 라벨의 위치와 크기를 설정합니다.
    buttonGroupCheck = new QButtonGroup(this); // QButtonGroup 객체를 생성합니다.
    buttonGroupCheck->setExclusive(false); // 버튼 그룹을 비독점적으로 설정합니다.
    //connect(buttonGroupCheck,SIGNAL(idClicked(int)),SLOT(selectButton(int))); // 신호와 슬롯을 연결합니다. (현재는 주석 처리됨)
    connect(buttonGroupCheck,&QButtonGroup::idToggled,[=](int id, bool check) // 버튼 그룹의 idToggled 신호와 람다 함수를 연결합니다.
            {
                QString str = QString("CheckBox %1 is selected and check attribute is %2").arg(QString::number(id + 1)).arg((check) ? "on" : "off"); // 체크박스의 상태를 문자열로 작성합니다.
                // str = "CheckBox "+QString::number(id+1)+" is selected and checked attribute is "+((check)?"on":"off"); // 위와 동일한 기능을 합니다.
                label->setText(str); // 라벨에 문자열을 설정합니다.
            });
    for (int i = 0; i < 4; i++)
    {
        QString str = QString("Checkbox %1").arg(i + 1); // 각 체크박스의 텍스트를 설정합니다.
        checkBoxButton[i] = new QCheckBox(str, this); // 체크박스 객체를 생성하고 초기화합니다.
        checkBoxButton[i]->move(0, 120 + 20 * i); // 체크박스의 위치를 설정합니다.
        buttonGroupCheck->addButton(checkBoxButton[i], i); // 체크박스를 버튼 그룹에 추가합니다.
    }
}

// selectButton 슬롯 함수 정의
void widget::selectButton(int id)
{
    QButtonGroup *buttonGroup = (QButtonGroup*)sender(); // 신호를 보낸 객체를 버튼 그룹으로 캐스팅합니다.
    QCheckBox *button = (QCheckBox*)buttonGroup->button(id); // 버튼 그룹에서 id에 해당하는 버튼을 가져옵니다.
    qDebug("CheckBox %d is selected(%s)", id + 1, (button->isChecked()) ? "on" : "off"); // 체크박스의 상태를 디버그 메시지로 출력합니다.
}

// widget 클래스 소멸자 정의
widget::~widget()
{
    // 소멸자에서는 별도의 해제 작업이 필요 없습니다. Qt가 자동으로 자원을 관리합니다.
}

