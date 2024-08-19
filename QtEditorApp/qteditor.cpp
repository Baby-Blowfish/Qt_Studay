#include "qteditor.h"
#include <QTextEdit>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QApplication>
#include <QToolBar>
#include <QFontComboBox>
#include <QDoubleSpinBox>
#include <QStatusBar>
#include <QLabel>
#include <QDockWidget>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>
#include <QColorDialog>
#include <QFontDialog>
#include <QPrintDialog>
#include <QPrinter>
#include <QHash>
#include <QDial>
#include <QBoxLayout>

QtEditor::QtEditor(QWidget *parent)
    : QMainWindow(parent)
{

    //------------------------------<QMdiArea Widget>----------------------------------------------
    mdiArea = new QMdiArea(this);
    setCentralWidget(mdiArea);
    connect(mdiArea,SIGNAL(subWindowActivated(QMdiSubWindow*)),SLOT(setFontWidget()));
    //connect(mdiArea,QMdiArea::subWindowActivated(),this,QtEditor::setFontWidget);





    //------------------<QMainWindow>-----------------------------
    // QTextEdit *textedit = new QTextEdit(this);      // 여러 줄의 문자열 입력 위젯
    // setCentralWidget(textedit);     // 중앙 위젯 설정

    QMenuBar *menuBar = new QMenuBar(this);
    setMenuBar(menuBar);
        // QMenuBar 클래스의 인스턴스를 생성 후 QMainWindow 클래스의 setMenuBar()메소드를 호출해서 설정
        // QMenuBar *menubar = this->menuBar();
        // QMainWindow 클래스에서 제공하는 메뉴바를 반환받아 사용하는 방식 : QMainWindow::menuBar();
    QMenu *fileMenu = menuBar->addMenu("&File");



    //-----------------------<QAction >------------------------------
    // QMenuBar *menuBar = new QMenuBar(this);
    // setMenuBar(menuBar);

    // QAction *newAct = new QAction(QIcon("NEW.png"),"&New",this);
    //    // 확장자만 확인하지 말고 실제 파일 속성에 들어가서 png 파일인지 확인해 봐야한다.
    // newAct->setShortcut(tr("Ctrl+N"));
    // newAct -> setStatusTip(tr("make new file"));
    // connect(newAct,SIGNAL(triggered()),SLOT(newFile()));

    // QMenu *fileMenu = menuBar->addMenu("&File");
    // fileMenu->addAction(newAct);



    //-----------------------<Action 쉬운 구현>------------------------------

    // tr(QStirng st); 국제수행 메소드

    QAction *newAct = makeAction(":/images/new.png",tr("&New"),QKeySequence::New,
                                tr("Make new file"),this,SLOT(newFile()));
        // 템플릿 사용 - enum

    QAction *saveAct = makeAction(":/images/save.png",tr("&Save"),tr("Ctrl+S"),
                                  tr("Save this file"),this,SLOT(saveFile()));
        // 템플릿의 구체화 사용 - const char* 즉 문자열일 경우 동작 설정

    QAction *openAct = makeAction(":/images/open.png",tr("&Open"),tr("Ctrl+O"),
                                  tr("Open a file"),this,SLOT(openFile()));
        // 템플릿의 Functor를 사용하여 람다 함수 사용

    QAction *saveAsAct = makeAction(":/images/saveas.png",tr("Save&As"),tr("Ctrl+A"),
                                  tr("Save as a file"),this,SLOT(saveAsFile()));

    QAction *printAct = makeAction(":/images/print.png",tr("&Print"),tr("Ctrl+P"),
                                   tr("Print  file"),this,SLOT(printFile()));

    QAction *quitAct = makeAction(":/images/quit.png",tr("E&xit"),tr("Ctrl+Q"),
                                 tr("Quite this program"),qApp,SLOT(quit()));


    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    fileMenu->addAction(saveAsAct);
    fileMenu->addSeparator();
    fileMenu->addAction(printAct);
    fileMenu->addSeparator();
    fileMenu->addAction(quitAct);







    //-------------------------------<QToolBar Class>----------------------------------------
    // "File" 툴바를 추가합니다.
    QToolBar *fileToolBar = addToolBar("&File");

    // 툴바 버튼 스타일을 아이콘 옆에 텍스트가 표시되도록 설정합니다.
    fileToolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    // "newAct" 액션을 툴바에 추가합니다.
    fileToolBar->addAction(newAct);

    // 툴바에 구분자를 추가합니다.
    fileToolBar->addSeparator();

    // "quitAct" 액션을 툴바에 추가합니다.
    fileToolBar->addAction(quitAct);

    // "Window" 메뉴를 메뉴바에 추가합니다.
    windowMenu = menuBar->addMenu("&Window");

    // "Window" 메뉴에 "Toolbar" 서브 메뉴를 추가합니다.
    QMenu *toolbarMenu = windowMenu->addMenu("&Toolbar");

    // "Window" 메뉴에 구분자를 추가합니다.
    windowMenu->addSeparator();

    // "Toolbar" 서브 메뉴에 툴바의 표시/숨기기 토글 액션을 추가합니다.
    toolbarMenu->addAction(fileToolBar->toggleViewAction());




    //--------------------------<QToolBar에 Widget 추가>-------------------------------------
    //QTextEdit *textedit = new QTextEdit;

    // QFontComboBox *fontComboBox = new QFontComboBox(this);
    // connect(fontComboBox, SIGNAL(currentFontChanged(QFont)),
    //         textedit,SLOT(setCurrentFont(QFont)));

    // QDoubleSpinBox *sizeSpinBox = new QDoubleSpinBox(this);
    // connect(sizeSpinBox, SIGNAL(valueChanged(double)),
    //        textedit, SLOT(setFontPointSize(qreal)));

    //--------------------------<QToolBar에 Widget 추가 및 MDI 연동>-------------------------------------
    fontComboBox = new QFontComboBox(this);
    connect(fontComboBox, SIGNAL(currentFontChanged(QFont)),
            this,SLOT(setTextFont(QFont)));

    sizeSpinBox = new QDoubleSpinBox(this);
    connect(sizeSpinBox, SIGNAL(valueChanged(double)),
            this, SLOT(setTextSize(qreal)));

    addToolBarBreak();      // 생성될 tool bar 위치를 아래로 줄바꿈

    QToolBar *formatToolbar = addToolBar("&Format");

    formatToolbar->addWidget(fontComboBox);
    formatToolbar->addSeparator();
    formatToolbar->addWidget(sizeSpinBox);

    toolbarMenu->addAction(formatToolbar->toggleViewAction());







    //-------------------------------<QStatusBar>----------------------------------------
    // 상태바(StatusBar) 객체를 생성하고 가져옵니다.
    QStatusBar *statusbar = statusBar();

    // "Qt Editor"라는 텍스트를 가진 라벨(Label) 객체를 생성합니다.
    // 라벨은 상태바에 속하도록 설정됩니다.
    QLabel *statusLabel = new QLabel(tr("Qt Editor"), statusbar);

    // 라벨 객체의 이름을 "StatusLabel"로 설정합니다.
    // 이는 나중에 객체를 쉽게 참조할 수 있도록 하기 위함입니다.
    statusLabel->setObjectName("StatusLabel");

    // 상태바에 라벨을 영구적으로 추가합니다.
    // 이 라벨은 상태바의 우측에 항상 표시됩니다.
    statusbar->addPermanentWidget(statusLabel);

    // 상태바에 "started"라는 메시지를 1500밀리초(1.5초) 동안 표시합니다.
    statusbar->showMessage("started", 1500);




#if 0
    QTextEdit *textedit = new QTextEdit(this);
    mdiArea->addSubWindow(textedit);
#else
    QTextEdit *textedit = newFile();
#endif



    //-----------------------------<Edit menu>------------------------------------------
    // connect(fontComboBox, SIGNAL(currentFontChanged(QFont)),
    //         textedit,SLOT(setCurrentFont(QFont)));

    QMenu *editMenu = menuBar->addMenu("&Edit");

    // QAction *undoAct = makeAction("undo.png",tr("&Undo"),QKeySequence::Undo,
    //                               tr("Undo"),textedit,SLOT(undo()));
    QAction *undoAct = makeAction(":/images/undo.png",tr("&Undo"),QKeySequence::Undo,
                                  tr("Undo"),this,SLOT(undo()));

    QAction *RedoAct = makeAction(":/images/redo.png",tr("&Redo"),QKeySequence::Redo,
                                  tr("Redo"),this,SLOT(redo()));
    QAction *CopyAct = makeAction(":/images/copy.png",tr("&Copy"),QKeySequence::Copy,
                                  tr("Copy"),this,SLOT(copy()));
    QAction *CutAct = makeAction(":/images/cut.png",tr("&Cut"),QKeySequence::Cut,
                                 tr("Cut"),this,SLOT(cut()));
    QAction *PasteAct = makeAction(":/images/paste.png",tr("&Paste"),QKeySequence::Paste,
                                   tr("Paste"),this,SLOT(paste()));
    QAction *ZoomInAct = makeAction(":/images/zoomin.png",tr("&ZoomIn"),QKeySequence::ZoomIn,
                                    tr("Zoom In"),this,SLOT(zoomIn()));
    QAction *ZoomOutAct = makeAction(":/images/zoomout.png",tr("&ZoomOut"),QKeySequence::ZoomOut,
                                     tr("Zoom Out"),this,SLOT(zoomOut()));

    editMenu->addAction(undoAct);
    editMenu->addSeparator();
    editMenu->addAction(RedoAct);
    editMenu->addSeparator();
    editMenu->addAction(CopyAct);
    editMenu->addSeparator();
    editMenu->addAction(CutAct);
    editMenu->addSeparator();
    editMenu->addAction(PasteAct);
    editMenu->addSeparator();
    editMenu->addAction(ZoomInAct);
    editMenu->addSeparator();
    editMenu->addAction(ZoomOutAct);





    //-----------------------------<QTextEdit alignment>------------------------------------------

    QMenu *formatMenu = menuBar->addMenu("&Fomat");
    QMenu *alignMenu = new QMenu("&Align",this);
    alignMenu->setIcon(QIcon(":/images/aligncenter.png"));
    QAction *fontAct = new QAction(QIcon(":/images/font.png"),"&Font",this);
    QAction *colorAct = new QAction(QIcon(":/images/color.png"),"&Color",this);
    fontAct->setShortcut(tr("Ctrl+F"));
    colorAct->setShortcut(tr("Ctrl+C"));
    formatMenu->addAction(fontAct);
    formatMenu->addAction(colorAct);
    formatMenu->addMenu(alignMenu);

    QAction *alignCenterAct = new QAction(QIcon(":/images/aligncenter.png"),"&Center",this);
    QAction *alignLeftAct = new QAction(QIcon(":/images/alignleft.png"),"&Left",this);
    QAction *alignRightrAct = new QAction(QIcon(":/images/alignright.png"),"&Right",this);
    QAction *alignJustifyAct = new QAction(QIcon(":/images/justify.png"),"&Justify",this);
    alignCenterAct->setShortcut(tr("Ctrl+2"));
    alignLeftAct->setShortcut(tr("Ctrl+1"));
    alignRightrAct->setShortcut(tr("Ctrl+3"));
    alignJustifyAct->setShortcut(tr("Ctrl+4"));

    alignMenu->addAction(alignLeftAct);
    alignMenu->addAction(alignCenterAct);
    alignMenu->addAction(alignRightrAct);
    alignMenu->addAction(alignJustifyAct);

    connect(alignCenterAct, SIGNAL(triggered( )),this,SLOT(alignText( )));
    connect(alignLeftAct, SIGNAL(triggered( )),this,SLOT(alignText( )));
    connect(alignRightrAct, SIGNAL(triggered( )),this,SLOT(alignText( )));
    connect(alignJustifyAct, SIGNAL(triggered( )),this,SLOT(alignText( )));






    //-----------------------------<QDockWidget>------------------------------------------
    QWidget *w = new QWidget(this);
    QVBoxLayout *vboxlayout = new QVBoxLayout();
    QDial *dockdial = new QDial(w);
    QLabel *docklabel = new QLabel("label Widget",w);

    dockdial->setWrapping(true);
    dockdial->setNotchesVisible(true);
    dockdial->setNotchTarget(10);

    vboxlayout->addWidget(docklabel);
    vboxlayout->addWidget(dockdial);
    w->setLayout(vboxlayout);

    QDockWidget *dockWidget = new QDockWidget("Dock Widget",this);
    dockWidget->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
    addDockWidget(Qt::RightDockWidgetArea,dockWidget);
    dockWidget->setWidget(w);

    toolbarMenu->addAction(dockWidget->toggleViewAction());


    //------------------------------<QMdiArea Widget Slot>----------------------------------------------

    QAction *cascadeAct = makeAction(":/images/cascade.png",tr("&Cascade"),tr("Ctrl+cc"),
                                     tr("Cascade"),mdiArea,SLOT(cascadeSubWindows()));
    QAction *tileSubAct = makeAction(":/images/tile.png",tr("&TileSub"),tr("Ctrl+tt"),
                                     tr("tileSub"),mdiArea,SLOT(tileSubWindows()));
    QAction *activateNextSubAct = makeAction(":/images/next.png",tr("&ActivateNextSub"),tr("Ctrl+an"),
                                     tr("activateNextSub"),mdiArea,SLOT(activateNextSubWindow()));
    QAction *activatePreviousSubAct = makeAction(":/images/previous.png",tr("&ActivatePreviousSub"),tr("Ctrl+ap"),
                                     tr("activatePreviousSub"),mdiArea,SLOT(activatePreviousSubWindow()));
    windowMenu->addAction(cascadeAct);
    windowMenu->addSeparator();
    windowMenu->addAction(tileSubAct);
    windowMenu->addSeparator();
    windowMenu->addAction(activateNextSubAct);
    windowMenu->addSeparator();
    windowMenu->addAction(activatePreviousSubAct);
    windowMenu->addSeparator();


    //------------------------------<

    //-----------------------------<QMessageBox>--------------------------------------
    QMenu *helpMenu = menuBar->addMenu("&Help");


    QAction *aboutAct = makeAction(":/images/about.png",tr("&about"),tr("Ctrl+shift+a"),
                                   tr("about"),this,SLOT(about()));
    QAction *aboutQtAct = makeAction(":/images/aboutqt.png",tr("&aboutQt"),tr("Ctrl+shift+q"),
                                     tr("aboutQt"),qApp,SLOT(aboutQt()));
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);

    connect(aboutAct,SIGNAL(triggered()),this,SLOT(about()));




    //-----------------------------<QColorDialog>--------------------------------------

    //QColor color = QColorDialog::getColor(Qt::green,this);
    connect(colorAct,SIGNAL(triggered()),this,SLOT(setColor()));


    //-------------------------------<QFontDialog Class>-----------------------------
    connect(fontAct,SIGNAL(triggered()),this,SLOT(setFont()));


    //-------------------------------<QText Editor 위젯 관리>-----------------------------


}







QtEditor::~QtEditor() {}


QTextEdit *QtEditor::newFile()
{
    qDebug("Mak New File");

    QString str = QString("&New file %1").arg(newfilenum+1);
    newfilenum++;
    QAction *newFileAct = makeAction(":/images/file.png",tr(str.toUtf8()),tr(""),
                                     tr("New File"),this,SLOT(selectWindow()));

    windowMenu->addAction(newFileAct);
    windowMenu->addSeparator();

    QTextEdit *textedit = new QTextEdit(tr(str.toUtf8()));
    mdiArea->addSubWindow(textedit);
    textedit->show();
    connect(textedit,SIGNAL(cursorPositionChanged()),SLOT(setFontWidget()));


    connect(textedit,SIGNAL(destroyed(QObject*)),textedit,SLOT(deleteLater()));
    connect(textedit,SIGNAL(destroyed(QObject*)),newFileAct,SLOT(deleteLater()));


    windowHash[newFileAct] = textedit;

    return textedit;

}

void QtEditor::selectWindow()
{
    QTextEdit *textedit = (QTextEdit*)windowHash[(QAction*)sender()];

    if(textedit != nullptr) {
        textedit->setFocus();
    }

    textedit->setFocus();

}

void QtEditor::openFile()
{
    qDebug("Open a File");
    QString fileName = QFileDialog::getOpenFileName(this,
    tr("Selet file to open"), ".", tr("Text files (*.txt *.html *.htm *.c *cpp *.h *.cs)"));

    qDebug()<<fileName;

    if(!fileName.length()) return;

    QFileInfo fileInfo(fileName);

    if(fileInfo.isReadable())
    {
        QFile file(fileName);
        file.open(QIODevice::ReadOnly|QIODevice::Text);
        QByteArray msg = file.readAll();
        file.close();

        QTextEdit *textedit = newFile();
        textedit->setWindowTitle(fileName);

        windowHash.key(textedit)->setText(fileName);

        if(fileInfo.suffix() == "htm"||fileInfo.suffix()=="html")
            textedit->setHtml(msg);
        else
            textedit->setPlainText(msg);
    } else
        QMessageBox::warning(this,"Error","Can't Read this file",QMessageBox::Ok);

}


void QtEditor::saveFile()
{
    qDebug("Save this file");

    QMdiSubWindow *subWindow = mdiArea->currentSubWindow( );

    if(subWindow != nullptr) {
        QTextEdit *textedit = dynamic_cast<QTextEdit*>(subWindow->widget( ));

        QString fileName = textedit->windowTitle();

        if(!fileName.length())
        {
            QString fileName = QFileDialog::getSaveFileName(this, tr("Selet file to save"),
                 QDir::homePath(), tr("Text files (*.txt *.html *.htm *.c *cpp *.h *.cs)"));
            if(!fileName.length()) return;
            textedit->setWindowTitle(fileName);
            windowHash.key(textedit)->setText(fileName);
        }

        QFile file(fileName);
        file.open(QIODevice::WriteOnly|QIODevice::Text);
        QFileInfo fileInfo(fileName);
        if(fileInfo.isWritable()){
            QByteArray msg = textedit->toHtml().toUtf8();
            file.write(msg);
        }
        else
            QMessageBox::warning(this,"Error","Can't save this file",QMessageBox::Ok);
        file.close();
    }

}

void QtEditor::saveAsFile()
{
    qDebug("saveASFile");

    QMdiSubWindow *subWindow = mdiArea->currentSubWindow( );

    if(subWindow != nullptr)
    {
        QTextEdit *textedit = qobject_cast<QTextEdit*>(subWindow->widget( ));

        QString fileName = textedit->windowTitle();

        if(!fileName.length())
        {
            QString fileName = QFileDialog::getSaveFileName(this, tr("Selet file to save"),
                                                            QDir::homePath(), tr("Text files (*.txt *.html *.htm *.c *cpp *.h *.cs)"));
            if(!fileName.length()) return;
            textedit->setWindowTitle(fileName);
            windowHash.key(textedit)->setText(fileName);
        }

        QFile file(fileName);
        file.open(QIODevice::WriteOnly|QIODevice::Text);
        QFileInfo fileInfo(fileName);
        if(fileInfo.isWritable()){
            QByteArray msg = textedit->toHtml().toUtf8();
            file.write(msg);
        }
        else
            QMessageBox::warning(this,"Error","Can't save this file",QMessageBox::Ok);
        file.close();
    }



}
void QtEditor::printFile()
{
    QPrinter printer(QPrinter::HighResolution);
    printer.setFullPage(true);
    QPrintDialog printDialog(&printer, this);
    if(printDialog.exec()==QDialog::Accepted)
    {
        QTextEdit *textedit = (QTextEdit*)mdiArea->currentSubWindow()->widget();
        textedit->print(&printer);
    }
}










template <typename T>
QAction *QtEditor::makeAction(QString icon, QString text, T shortCut, QString toolTip,
                    QObject* recv, const char* slot)
{
    QAction *act = new QAction(text, this);
    if(icon.length())
        act->setIcon(QIcon(icon));
    act->setShortcut(shortCut);
    act->setStatusTip(toolTip);
    connect(act,SIGNAL(triggered()),recv,slot);
    return act;
}

// 템플릿의 특수화
template <>
QAction *QtEditor::makeAction(QString icon, QString text, const char* shortCut, QString toolTip,
                              QObject* recv, const char* slot)
{
    QAction *act = new QAction(text, this);
    if(icon.length())
        act->setIcon(QIcon(icon));
    act->setShortcut(QString(shortCut));
    act->setStatusTip(toolTip);
    connect(act,SIGNAL(triggered()),recv,slot);
    return act;
}


// // 람다 함수 사용
template <typename T, typename Functor>
QAction *QtEditor::makeAction(QString icon, QString text, T shortCut, QString toolTip,
                    Functor lambda)
{
    QAction *act = new QAction(text, this);
    if(icon.length())
        act->setIcon(QIcon(icon));
    QKeySequence keySequence(shortCut);
    act->setShortcut(keySequence);
    act->setStatusTip(toolTip);
    connect(act,&QAction::triggered,this,lambda);
    return act;
}

void QtEditor::setTextFont(QFont font)
{
    QMdiSubWindow *subWindow  = mdiArea->currentSubWindow();
    if(subWindow != nullptr)
    {
        QTextEdit *textedit = dynamic_cast<QTextEdit*>(subWindow->widget());
        textedit->setCurrentFont(font);
    }

}

void QtEditor::setTextSize(qreal size)
{

    QMdiSubWindow *subWindow  = mdiArea->currentSubWindow();
    if(subWindow != nullptr)
    {
        QTextEdit *textedit = dynamic_cast<QTextEdit*>(subWindow->widget());
        QFont font = textedit -> currentFont();
        font.setPointSizeF(size);
        textedit->setCurrentFont(font);
    }

}
void QtEditor::setFontWidget()
{
    QMdiSubWindow *subWindow  = mdiArea->currentSubWindow();
    if(subWindow != nullptr)
    {
        QTextEdit *textedit = dynamic_cast<QTextEdit*>(subWindow->widget());
        QFont font = textedit ->currentFont();
        fontComboBox->setCurrentFont(font);
        sizeSpinBox->setValue(font.pointSizeF());
    }

}

void QtEditor::undo()
{
    QMdiSubWindow *subWindow  = mdiArea->currentSubWindow();
    if(subWindow != nullptr)
    {
        QTextEdit *textedit = dynamic_cast<QTextEdit*>(subWindow->widget());
        textedit->undo();
    }
}

void QtEditor::redo( )
{
    QMdiSubWindow *subWindow = mdiArea->currentSubWindow( );
    if(subWindow != nullptr) {
        QTextEdit *textedit = dynamic_cast<QTextEdit*>(subWindow->widget( ));
        textedit->redo( );
    }
}

void QtEditor::copy( )
{
    QMdiSubWindow *subWindow = mdiArea->currentSubWindow( );
    if(subWindow != nullptr) {
        QTextEdit *textedit = dynamic_cast<QTextEdit*>(subWindow->widget( ));
        textedit->copy( );
    }
}

void QtEditor::cut( )
{
    QMdiSubWindow *subWindow = mdiArea->currentSubWindow( );
    if(subWindow != nullptr) {
        QTextEdit *textedit = dynamic_cast<QTextEdit*>(subWindow->widget( ));
        textedit->cut( );
    }
}

void QtEditor::paste( )
{
    QMdiSubWindow *subWindow = mdiArea->currentSubWindow( );
    if(subWindow != nullptr) {
        QTextEdit *textedit = dynamic_cast<QTextEdit*>(subWindow->widget( ));
        textedit->paste( );
    }
}

void QtEditor::zoomIn( )
{
    QMdiSubWindow *subWindow = mdiArea->currentSubWindow( );
    if(subWindow != nullptr) {
        QTextEdit *textedit = dynamic_cast<QTextEdit*>(subWindow->widget( ));
        textedit->zoomIn( );
    }
}

void QtEditor::zoomOut( )
{
    QMdiSubWindow *subWindow = mdiArea->currentSubWindow( );
    if(subWindow != nullptr) {
        QTextEdit *textedit = dynamic_cast<QTextEdit*>(subWindow->widget( ));
        textedit->zoomOut( );
    }
}
void QtEditor::about()
{
    QMessageBox::question(this,"QMessageBox::showQuestion()","Question Message",
                          QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel);
}

void QtEditor::setColor()
{
    QTextEdit *textedit = (QTextEdit*)mdiArea->currentSubWindow()->widget();
    QColor color = QColorDialog::getColor(textedit->textColor(),this);
    if(color.isValid()) textedit->setTextColor(color);
}

void QtEditor::setFont()
{
    bool ok;
    QTextEdit *textedit = (QTextEdit*)mdiArea->currentSubWindow()->widget();
    QFont font = QFontDialog::getFont(&ok, QFont("Helvetica [Cronyx]", 10), this);
    if (ok) {
        textedit->setCurrentFont(font);
    } else {
        // the user canceled the dialog; font is set to the initial
        // value, in this case Helvetica [Cronyx], 10
    }

}

void QtEditor::alignText( )
{
    QMdiSubWindow *subWindow = mdiArea->currentSubWindow( );
    if(subWindow != nullptr) {
        QTextEdit *textedit = dynamic_cast<QTextEdit*>(subWindow->widget( ));
        QAction *action = static_cast<QAction*>(sender( ));
        if(action->text( ) == "&Left")
            textedit->setAlignment(Qt::AlignLeft);
        else if(action->text( ) == "&Center")
            textedit->setAlignment(Qt::AlignCenter);
        else if(action->text( ) == "&Right")
            textedit->setAlignment(Qt::AlignRight);
        else if(action->text( ).contains("Justify", Qt::CaseInsensitive))
            textedit->setAlignment(Qt::AlignJustify);
    }
}
