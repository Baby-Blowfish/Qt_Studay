#include "qteditor.h"
#include <QTextEdit>
#include <QMenuBar>
#include <QMenu>

QtEditor::QtEditor(QWidget *parent)
    : QMainWindow(parent)
{
    QTextEdit *textedit = new QTextEdit(this);      // 여러 줄의 문자열 입력 위젯
    setCentralWidget(textedit);     // 중앙 위젯 설정

    QMenuBar *menuBar = new QMenuBar(this);
    setMenuBar(menuBar);
        // QMenuBar 클래스의 인스턴스를 생성 후 QMainWindow 클래스의 setMenuBar()메소드를 호출해서 설정
    // QMenuBar *menubar = this->menuBar();
    //     // QMainWindow 클래스에서 제공하는 메뉴바를 반환받아 사용하는 방식 : QMainWindow::menuBar();

    QMenu *fileMenu = menuBar->addMenu("&File");




}

QtEditor::~QtEditor() {}
