#include "widget.h"
#include "ui_widget.h"
#include <QLabel>
#include <QPushButton>
#include <iostream>

class Calculator{
    int num1, num2;
    char op;

public :
    Calculator(int num1 = 0, char op =' ', int num2 = 0):num1(num1),op(op),num2(num2){}
    void input(){ std::cin >> num1>>op>>num2;}
    double doCalculator(){

        double result;

        switch(op)
        {
        case '+':
            result = num1+num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1*num2;
            break;
        case '/':
            result = num1/num2;
            break;
        }

        return result;
    }
};

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    const char ButtonChar[16][2] = {
        "7","8","9","/",
        "4","5","6","x",
        "1","2","3","-",
        "0","C","=","+"
    };

    label = new QLabel("0",this);
    label->setGeometry(10,5,230,40);
    label->setAlignment(Qt::AlignRight|Qt::AlignCenter);
    QPushButton *buttons[16];
    int WIDTH = 4;
    for(int  y = 0; y < WIDTH; y++)
    {
        for(int x = 0; x < WIDTH; x++)
        {
            buttons[x+y*WIDTH] = new QPushButton(ButtonChar[x+y*WIDTH],this);
            buttons[x+y*WIDTH]->setGeometry(5+60*x,50+60*y,60,60);
        }
    }
}

Widget::~Widget()
{
    delete ui;
}
