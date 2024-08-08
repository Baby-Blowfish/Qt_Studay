#include "widget.h"
#include <QLineEdit>
#include <QCompleter>
#include <QComboBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //----------------------------------<QLineEdit>-------------------------------------------
    lineEdit = new QLineEdit(this);
    lineEdit->resize(300,30);
    //lineEdit->setEchoMode(QLineEdit::PasswordEchoOnEdit);
        // 입력받을때 정상 출력, 입력이 끝나면 즉 커서가 다른 위젯으로 이동한 경우 *기호로 표시됨
    //lineEdit->setInputMask("000.000.000.000;_");
    lineEdit->setPlaceholderText("input the number");

    QStringList wordList;
    wordList << "alpha" << "omega" << "omicron" << "zeta";

    QCompleter *completer = new QCompleter(wordList, this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);

    lineEdit->setCompleter(completer);


    //-----------------------------------<QComboBox>-----------------------------
    // comboBox = new QComboBox(this);
    // comboBox->addItem("KDE");
    // comboBox->addItem("Gnome");
    // comboBox->addItem("FVWM");
    // comboBox->addItem("CDE");
    // comboBox->setEditable(true);
}

Widget::~Widget() {}
