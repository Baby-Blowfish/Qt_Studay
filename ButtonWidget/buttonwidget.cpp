#include "buttonwidget.h"
#include <QRadioButton>
#include <QButtonGroup>
#include <QCheckBox>


ButtonWidget::ButtonWidget(QWidget *parent)
    : QWidget(parent)
{
    // QRadioButton
    // resize(140,110);
    // buttonGroup = new QButtonGroup(this);
    // for(int i = 0; i < 4; i++)
    // {
    //     QString str = QString("RadioButton %1").arg(i+1);
    //     radioButton[i] = new QRadioButton(str,this);
    //     radioButton[i]->move(10,10+20*i);
    //     buttonGroup->addButton(radioButton[i]);
    // }

    //QCheckBox 위젯
    resize(140,110);
    buttonGroup = new QButtonGroup(this);
    buttonGroup->setExclusive(false);
    connect(buttonGroup,SIGNAL(idClicked(int)),SLOT(selectButton(int)));
    for(int i = 0; i< 4;i++)
    {
        QString str = QString("Checkbox %1").arg(i+1);
        checkBox[i] = new QCheckBox(str,this);
        checkBox[i]->move(10,10+20*i);
        buttonGroup->addButton(checkBox[i],i);
    }

}
void ButtonWidget::selectButton(int id)
{
    QButtonGroup *buttonGroup = (QButtonGroup*)sender();
    QCheckBox *button = (QCheckBox*)buttonGroup->button(id);
    qDebug("CheckBox%d is selected(%s)",id+1,(button->isChecked())?"on":"off");
}

ButtonWidget::~ButtonWidget()
{

}
