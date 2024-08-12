/*--------------------------------Class cpp-------------------------------------------*/
#include "widget.h"
#include <QLineEdit>
#include <QCompleter>
#include <QTextEdit>
#include <QComboBox>

// Widget 생성자 정의
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //----------------------------------<QLineEdit>-------------------------------------------
    lineEdit = new QLineEdit(this); // QLineEdit 인스턴스 생성
    lineEdit->resize(300,30); // QLineEdit 크기 설정
    //lineEdit->setEchoMode(QLineEdit::PasswordEchoOnEdit);
    // 입력받을때 정상 출력, 입력이 끝나면 즉 커서가 다른 위젯으로 이동한 경우 *기호로 표시됨
    //lineEdit->setInputMask("000.000.000.000;_");
    lineEdit->setPlaceholderText("input the number"); // 입력 필드에 자리 표시자 텍스트 설정

    //----------------------------------<QStringList>-------------------------------------------
    QStringList wordList; // 자동 완성에 사용할 문자열 목록 생성
    wordList << "Bryan" << "Bart" << "Kelvin" << "Beth" <<"Kelly"; // 목록에 이름 추가

    QCompleter *completer = new QCompleter(wordList, this); // QCompleter 인스턴스 생성
    completer->setCaseSensitivity(Qt::CaseInsensitive); // 대소문자 구분하지 않도록 설정

    lineEdit->setCompleter(completer); // QLineEdit에 자동 완성 설정

    //----------------------------------<QTextEdit>-------------------------------------------
    textEdit = new QTextEdit(this); // QTextEdit 인스턴스 생성
    textEdit->setGeometry(0,50,200,100); // QTextEdit 위치 및 크기 설정
    textEdit->setHtml("<h1>Hello, World!</h1><p>This is a QTextEdit example.</p>"); // HTML 형식 텍스트 설정
    //textEdit->setReadOnly(true);  // 읽기 전용 모드 설정

    //-----------------------------------<QComboBox>-------------------------------------------
    comboBox = new QComboBox(this); // QComboBox 인스턴스 생성
    comboBox->setGeometry(0,150,200,50); // QComboBox 위치 및 크기 설정
    comboBox->addItem("KDE"); // 항목 추가
    comboBox->addItem("Gnome");
    comboBox->addItem("FVWM");
    comboBox->addItem("CDE");
    comboBox->setEditable(true); // QComboBox를 편집 가능하도록 설정
}

// Widget 소멸자 정의
Widget::~Widget() {}

