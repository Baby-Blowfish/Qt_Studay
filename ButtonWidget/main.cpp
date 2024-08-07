/*
    버튼관련 위젯

    마우스 버튼의 release 입력이나 옵션 선택과 같은 입력으로 사용되는 GUI 객체
    클릭 이벤트 처리
        QPushButton
        QToolButton
    옵션 선택 이벤트 처리
        QRadioButton: 한번에 하나의 옵션만 선택가능, 동그란 원
        QCheckBox   : 동시에 여러 옵션들을 선택 가능, 사각형

    모든 버튼 위젯은 QAbstractButton라는 추상 클래스를 상속받음, 그림 문자 등을 이용하여 정보를 표시하는 메소드를 제공
    autoRepeat 속성 : 버튼을 누르고 있으면 주기적으로 시그널 발생
    토글과 푸시 버튼 모두 제공
 */

#include "buttonwidget.h"

#include <QApplication>
#include <QPushButton>
#include <Qwidget>
#include <QRadioButton>
#include <QButtonGroup>
#include <QCheckBox>
#include <QButtonGroup>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ButtonWidget w;
    w.show();

    // QPushButton 위젯
    // 푸시버튼 형태, command button, 푸시 버튼 클릭하여 사용자가 request하면 애플리케이션은 미리 정해진 response 수행
    // OK, No, Help등과 같은 문자열 뿐만 아니라 아이콘을 표시하는 것도 가능

    // QPushButton *pushButton = new QPushButton("Push&BUtton",0);
    // pushButton->setCheckable(true);
    // QObject::connect(pushButton,&QPushButton::toggled,[&](bool flag){qDebug()<<"toggled"; if(!flag) a.quit();});
    //     //qDebug("Items in list: %d", myList.size());
    //     //qDebug() << "Brush:" << myQBrush << "Other value:" << i;
    // pushButton->show();


    // QRadioButton 위젯
    // 복수의 옵션 중 하나만 선택할 때 사용,다른 버튼 선택시 기존 버튼의 선택 해제됨
    // QButtonGroup 클래스로 하나의 그룹으로 묶어서 사용



    // QWidget *widget = new QWidget(0);
    // QButtonGroup *bg = new QButtonGroup(widget);

    // QRadioButton *rb1 = new QRadioButton("Option &1",widget);
    // rb1->move(10,10);
    // bg->addButton(rb1);

    // QRadioButton *rb2 = new QRadioButton("Option &2",widget);
    // rb2->move(10,30);
    // bg->addButton(rb2);

    // QRadioButton *rb3 = new QRadioButton("Option &3",widget);
    // rb3->move(10,50);
    // bg->addButton(rb3);

    // QRadioButton *rb4 = new QRadioButton("Option &4",widget);
    // rb4->move(10,70);
    // bg->addButton(rb4);

    // widget->resize(140,110);
    // widget->show();



    return a.exec();
}
