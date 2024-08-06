#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT        // 사용자 정의 시그널과 슬롯을 사용한다고 명시, Meta-Oject Code라고 부름
                    // moc라는 컴파일러가 qmake명령어를 다시 수행해서 moc명령어가 사용되도록 makefile을 재생성한다.

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

// 사용자 정의 슬롯 :  moc명령어에 의해서 자동으로 관련 코드가 생성됨
public slots:
    void slotQuit();        // 사용자 정의 슬롯, 일반적으로 void형의 반환형 사용

// 사용자 정의 시그널 :  선언만 하고 구현하지 않는다., void 반환형 사용, identifier을 과거형으로 선언한다.
signals:
    void clicked();

};
#endif // WIDGET_H
