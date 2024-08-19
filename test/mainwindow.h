#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QApplication>
#include <QMainWindow>
#include <QToolBar>
#include <QToolButton>
#include <QAction>
#include <QMessageBox>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr) : QMainWindow(parent) {
        // "Open" 액션 생성
        QAction *openAction = new QAction(QIcon(":/icons/open.png"), tr("&Open"), this);
        connect(openAction, &QAction::triggered, this, &MainWindow::openFile);

        // 툴 버튼 생성 및 설정
        QToolButton *toolButton = new QToolButton(this);
        toolButton->setDefaultAction(openAction);

        // 툴바에 툴 버튼 추가
        QToolBar *toolBar = addToolBar(tr("File"));
        toolBar->addWidget(toolButton);
    }

    ~MainWindow();

private slots:
    void openFile() {
        QMessageBox::information(this, tr("Open"), tr("Open file action triggered"));
    }
};
#endif // MAINWINDOW_H
