#include "widget.h"

#include <QApplication>
#include <QLCDNumber>
#include <QProgressBar>>
#include <QTimer>
#include <QTextBrowser>
#include <QUrl>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // Widget w;
    // w.show();

    // QLCDNumber 위젯

    // QLCDNumber *lcd = new QLCDNumber();
    // //lcd->setBinMode();
    // lcd->setSegmentStyle(QLCDNumber::Flat);
    // //lcd->display(12);
    // lcd->setDigitCount(15);
    // lcd->show();


    //QProgressBar

    // QProgressBar *progBar = new QProgressBar();
    // progBar->setRange(0,50);
    // progBar->setValue(20);
    // progBar->show();


    //QProgressBar & QTimer : 간단하 일을 할 때 사용 ex) 시계 표시

    // QProgressBar *progBar = new QProgressBar();
    // progBar->show();
    // QTimer timer;
    // int n = 0;
    // QObject::connect(&timer,&QTimer::timeout, [&]{progBar->setValue(++n%101);});
    //     // 시그널과 람다 함수를 연결
    // timer.start(10);    // 10ms 주기로 QTimer 객체를 연속 실행


    // QTextBrowser : 여러줄의 문자열을 표시할때 사용, 하이퍼 텍스트 표시 표나 프레임음 불가능, 리치 텍스트 가능
    // 2개의 html 파일은 working directory에 넣어야함.
    // projects -> build&run -> run -> Working directory: -> 우클릭후 show in explorer 클릭 -> 2개의 html파일 넣기

    // QUrl url("help.html");
    // QTextBrowser *tb = new QTextBrowser();
    // tb->setSource(QUrl("index.html"));
    // tb->show();


    return a.exec();
}
