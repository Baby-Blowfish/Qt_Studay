#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QPushButton;
class QHBoxLayout;
class QVBoxLayout;
class QGridLayout;
class QDial;
class QLabel;
class QCalendarWidget;
class QTextEdit;


#define NO_OF_ROW 3
#define NO_OF_colum 5

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QPushButton *pushbuttonVBoxLayout[3];
    QPushButton *pushbuttonHBoxLayout[3];
    QPushButton *pushButtonGridLayout[NO_OF_ROW*NO_OF_colum];

    QHBoxLayout *hBoxLayout;
    QVBoxLayout *vBoxLayout;
    QGridLayout *gridLayout;

    QDial *dial;
    QLabel *label;
    QCalendarWidget *calendarWidget;
    QTextEdit *textEdit;

};
#endif // WIDGET_H
