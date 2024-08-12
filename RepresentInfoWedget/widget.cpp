/*--------------------------------Class cpp-------------------------------------------*/
#include "widget.h"

#include <QLCDNumber>
#include <QProgressBar>
#include <QTimer>
#include <QTextBrowser>
#include <QUrl>

// Widget 생성자 정의
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    //-------------------------------------<LCDNumber Widget>-----------------------------------------------
    // QLCDNumber 위젯 초기화 및 설정
    QLCDNumber *lcd = new QLCDNumber(this); // LCD 숫자 디스플레이 위젯 생성
    //lcd->setBinMode(); // 이진수 모드 설정 (주석 처리됨)
    lcd->setSegmentStyle(QLCDNumber::Outline); // 세그먼트 스타일 설정
    lcd->setGeometry(0,0,200,30); // 위젯의 위치 및 크기 설정
    lcd->setDigitCount(8);  // 자릿수 설정
    lcd->display(127888);   // 초기 값 표시

    //-------------------------------------<QProgressBar Widget & QTimer>-----------------------------------------------
    // QProgressBar 및 QTimer 위젯 초기화 및 설정
    progBar = new QProgressBar(this); // 진행 바 위젯 생성
    progBar->setGeometry(0,30,200,30); // 위젯의 위치 및 크기 설정
    progBar->setRange(0,100); // 진행 바의 범위 설정
    progBar->setValue(0); // 초기 값 설정

    timer = new QTimer(this); // 타이머 객체 생성

    unsigned int n = 0; // 진행 바의 값을 위한 변수
    // 타이머의 timeout 시그널을 람다 함수와 연결하여 진행 바의 값을 업데이트
    connect(timer,&QTimer::timeout, [&]{progBar->setValue(++n%101); qDebug() << "ProgressBar Value:" << n % 101;});
    timer->start(10);    // 10ms 주기로 타이머 시작

    //-------------------------------------<QTextBrowser Widget>-----------------------------------------------
    // 여러줄의 문자열을 표시할때 사용, 하이퍼 텍스트 표시, 표나 프레임은 불가능, 리치 텍스트 가능
    // projects -> build&run -> run -> Working directory: -> 우클릭후 show in explorer 클릭 -> 2개의 html파일 넣기
    url = new QUrl("help.html"); // URL 객체 생성

    tb = new QTextBrowser(this); // 텍스트 브라우저 위젯 생성
    tb->setGeometry(0,60,200,200); // 위젯의 위치 및 크기 설정
    tb->setSource(QUrl("index.html")); // 초기 HTML 파일 설정

}

// Widget 소멸자 정의
Widget::~Widget() {}
