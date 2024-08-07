/********************************************************************************
** Form generated from reading UI file 'buttonwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUTTONWIDGET_H
#define UI_BUTTONWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ButtonWidget
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ButtonWidget)
    {
        if (ButtonWidget->objectName().isEmpty())
            ButtonWidget->setObjectName("ButtonWidget");
        ButtonWidget->resize(800, 600);
        centralwidget = new QWidget(ButtonWidget);
        centralwidget->setObjectName("centralwidget");
        ButtonWidget->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ButtonWidget);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        ButtonWidget->setMenuBar(menubar);
        statusbar = new QStatusBar(ButtonWidget);
        statusbar->setObjectName("statusbar");
        ButtonWidget->setStatusBar(statusbar);

        retranslateUi(ButtonWidget);

        QMetaObject::connectSlotsByName(ButtonWidget);
    } // setupUi

    void retranslateUi(QMainWindow *ButtonWidget)
    {
        ButtonWidget->setWindowTitle(QCoreApplication::translate("ButtonWidget", "ButtonWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ButtonWidget: public Ui_ButtonWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUTTONWIDGET_H
