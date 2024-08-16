#include "qteditor.h"

#include <QMenuBar>
#include <QMenu>
#include <QToolBar>
#include <QStatusBar>
#include <QAction>
#include <QTextEdit>
#include <QApplication>
#include <QKeySequence>
#include <QFontComboBox>
#include <QDoubleSpinBox>
#include <QLabel>
#include <QDockWidget>
#include <QMdiArea>
#include <QMdiSubWindow>

QtEditor::QtEditor(QWidget *parent)
    : QMainWindow(parent)
{
    mdiArea = new QMdiArea(this);
    setCentralWidget(mdiArea);
#if 0				//  Edit 메뉴를 수정한 후 0으로 변경
    QTextEdit *textedit = new QTextEdit(this);
    setCentralWidget(textedit);
    mdiArea->addSubWindow(textedit);
#else
    QTextEdit *textedit = newFile( );	// 생성자의 제일 마지막으로 이동
#endif
    connect(mdiArea, SIGNAL(subWindowActivated(QMdiSubWindow*)),                                    SLOT(setFontWidget( )));

    fontComboBox = new QFontComboBox(this);
    connect(fontComboBox, SIGNAL(currentFontChanged(QFont)), SLOT(setTextFont(QFont)));
    sizeSpinBox = new QDoubleSpinBox(this);
    connect(sizeSpinBox, SIGNAL(valueChanged(double)), SLOT(setTextSize(qreal)));

    QMenuBar* menubar = this->menuBar();

    /* File Menu */
    QAction *newAct = makeAction(":/images/new.png", tr("&New"), QKeySequence::New, \
                                 tr("make new file"), this, SLOT(newFile( )));
    QAction *openAct = makeAction(":/images/open.png", tr("&Open"), QKeySequence::Open, \
                                 tr("open a file"), this, SLOT(openFile( )));
    QAction *saveAct = makeAction(":/images/save.png", tr("&Save"), QKeySequence::Save, \
                                 tr("save this file"), this, SLOT(saveFile( )));
    QAction *saveasAct = makeAction(":/images/saveas.png", tr("Save &As"), QKeySequence::SaveAs, \
                                 tr("save as a file"), this, SLOT(saveasFile( )));
    QAction *printAct = makeAction(":/images/print.png", tr("&Print"), QKeySequence::Print, \
                                 tr("print file"), this, SLOT(printFile( )));
    QAction *quitAct = makeAction(":/images/quit.png", tr("&Quit"), tr("Ctrl+Q"), \
                                  tr("Quit this program"), qApp, SLOT(quit( )));

    QMenu *fileMenu = menubar->addMenu("&File");
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    fileMenu->addAction(saveasAct);
    fileMenu->addSeparator();
    fileMenu->addAction(printAct);
    fileMenu->addSeparator();
    fileMenu->addAction(quitAct);

    QToolBar *fileToolBar = addToolBar("&File");
//    fileToolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    fileToolBar->addAction(newAct);
    fileToolBar->addAction(openAct);
    fileToolBar->addAction(saveAct);
    fileToolBar->addAction(saveasAct);
    fileToolBar->addSeparator();
    fileToolBar->addAction(printAct);
    fileToolBar->addSeparator();
    fileToolBar->addAction(quitAct);

    /* Edit Menu */
    QAction *undoAct = makeAction(":/images/undo.png", tr("&Undo"), QKeySequence::Undo, \
                                 tr("undo"), this, SLOT(undo( )));
    QAction *redoAct = makeAction(":/images/redo.png", tr("&Redo"), QKeySequence::Redo, \
                                  tr("redo"), this, SLOT(redo( )));
    QAction *copyAct = makeAction(":/images/copy.png", tr("&Copy"), QKeySequence::Copy, \
                                  tr("copy"), this, SLOT(copy( )));
    QAction *cutAct = makeAction(":/images/cut.png", tr("Cu&t"), QKeySequence::Cut, \
                                  tr("cut"), this, SLOT(cut( )));
    QAction *pasteAct = makeAction(":/images/paste.png", tr("&Paste"), QKeySequence::Paste, \
                                  tr("paste"), this, SLOT(paste( )));
    QAction *zoomInAct = makeAction(":/images/zoomin.png", tr("Zoom &in"), QKeySequence::ZoomIn, \
                                  tr("zoomin"), this, SLOT(zoomIn( )));
    QAction *zoomOutAct = makeAction(":/images/zoomout.png", tr("Zoom &out"), QKeySequence::ZoomOut, \
                                  tr("zoomout"), this, SLOT(zoomOut( )));

    QMenu *editMenu = menubar->addMenu("&Edit");
    editMenu->addAction(undoAct);
    editMenu->addAction(redoAct);
    editMenu->addSeparator();
    editMenu->addAction(copyAct);
    editMenu->addAction(cutAct);
    editMenu->addAction(pasteAct);
    editMenu->addSeparator();
    editMenu->addAction(zoomInAct);
    editMenu->addAction(zoomOutAct);

    QToolBar *editToolBar = addToolBar("&Edit");
//    editToolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    editToolBar->addAction(undoAct);
    editToolBar->addAction(redoAct);
    editToolBar->addSeparator();
    editToolBar->addAction(copyAct);
    editToolBar->addAction(cutAct);
    editToolBar->addAction(pasteAct);
    editToolBar->addSeparator();
    editToolBar->addAction(zoomInAct);
    editToolBar->addAction(zoomOutAct);

    addToolBarBreak( );      /* 다음 툴바는 아랫 줄로 위치 */

    QToolBar *formatToolbar = addToolBar("&Format");
    formatToolbar->addSeparator( );
    formatToolbar->addWidget(fontComboBox);
    formatToolbar->addWidget(sizeSpinBox);

    QWidget *w = new QWidget(this);
    QLabel *label = new QLabel("Dock Widget", w);
    QDockWidget *dock = new QDockWidget("Dock Widget", this);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    addDockWidget(Qt::RightDockWidgetArea, dock);
    dock->setWidget(w);

    QAction *tileAct = makeAction(":/images/tile.png", tr("&Tile"), "Ctrl+Shift+T", \
                                  tr("tile"), mdiArea, SLOT(tileSubWindows( )));
    QAction *cascateAct = makeAction(":/images/cascade.png", tr("&Cascade"), "Ctrl+Shift+C", \
                                  tr("cascade"), mdiArea, SLOT(cascadeSubWindows( )));
    QAction *previousAct = makeAction(":/images/previous.png", tr("&Previous"), QKeySequence::PreviousChild, \
                                  tr("previous"), mdiArea, SLOT(activatePreviousSubWindow( )));
    QAction *nextAct = makeAction(":/images/next.png", tr("&Next"), QKeySequence::NextChild, \
                                 tr("cut"), mdiArea, SLOT(activateNextSubWindow( )));

    QMenu *windowMenu = menubar->addMenu("&Window");
    windowMenu->addAction(tileAct);
    windowMenu->addAction(cascateAct);
    windowMenu->addSeparator( );
    windowMenu->addAction(previousAct);
    windowMenu->addAction(nextAct);

    formatToolbar->addSeparator( );
    formatToolbar->addAction(tileAct);
    formatToolbar->addAction(cascateAct);
    formatToolbar->addSeparator( );
    formatToolbar->addAction(previousAct);
    formatToolbar->addAction(nextAct);

    QMenu *toolbarMenu = windowMenu->addMenu("&Toolbar");
    toolbarMenu->addAction(fileToolBar->toggleViewAction( ));
    toolbarMenu->addAction(dock->toggleViewAction( ));

    QStatusBar *statusbar = statusBar( );
    QLabel *statusLabel = new QLabel(tr("Qt Editor"), statusbar);    statusLabel->setObjectName("StautsLabel");
    statusbar->addPermanentWidget(statusLabel);
    statusbar->showMessage("started", 1500);
}

QtEditor::~QtEditor()
{
}

QTextEdit *QtEditor::newFile( ) {
    qDebug("Make New File");
    QTextEdit *textedit = new QTextEdit;
    connect(textedit, SIGNAL(cursorPositionChanged( )), SLOT(setFontWidget( )));
    mdiArea->addSubWindow(textedit);
    textedit->show( );
    return textedit;
}

void QtEditor::openFile( )
{
    qDebug("Open a file");
}

void QtEditor::saveFile( )
{
    qDebug("Save this file");
}

void QtEditor::saveasFile( )
{
    qDebug("Save as a file");
}

void QtEditor::printFile( )
{
    qDebug("Print this file");
}

void QtEditor::setFontWidget( )   /* QFontComboBox와 QDoubleSpinBox 설정 */
{
    QTextEdit *textedit = (QTextEdit*)mdiArea->currentSubWindow( )->widget( );
    QFont font = textedit->currentFont( );
    fontComboBox->blockSignals(true);
    sizeSpinBox->blockSignals(true);
    fontComboBox->setCurrentFont(font);   /* QFontComboBox와 QSpinBox를 */
    sizeSpinBox->setValue(font.pointSizeF( ));             /* 클래스의 멤버로 변경 */
    fontComboBox->blockSignals(false);
    sizeSpinBox->blockSignals(false);
}

template <typename T>
QAction *QtEditor::makeAction(QString icon, QString text, \
                              T shortCut, QString toolTip, \
                              QObject* recv, const char* slot)
{
    QAction *act = new QAction(text, this);
    if(icon.length( ))
        act->setIcon(QIcon(icon));
    act->setShortcut(shortCut);
    act->setStatusTip(toolTip);
    act->setToolTip(toolTip);
    connect(act, SIGNAL(triggered( )), recv, slot);
    return act;
}

template <>
QAction *QtEditor::makeAction(QString icon, QString text, \
                              const char* shortCut, QString toolTip, \
                              QObject* recv, const char* slot)
{
    QAction *act = new QAction(text, this);
    if(icon.length( ))
        act->setIcon(QIcon(icon));
    act->setShortcut(QString(shortCut));
    act->setStatusTip(toolTip);
    act->setToolTip(toolTip);
    connect(act, SIGNAL(triggered( )), recv, slot);
    return act;
}

template <typename T, typename Functor>
QAction *QtEditor::makeAction(QString icon, QString text, T shortCut,
                              QString toolTip, Functor lambda)
{
    QAction *act = new QAction(text, this);
    if(icon.length( ))
        act->setIcon(QIcon(icon));
    QKeySequence keySequence(shortCut);
    act->setShortcut(keySequence);
    act->setStatusTip(toolTip);
    act->setToolTip(toolTip);
    connect(act, &QAction::triggered, this, lambda);
    return act;
}


void QtEditor::setTextFont(QFont font)                 /* QTextEdit에 폰트 설정 */
{
    qDebug("setTextFont");
    QTextEdit *textedit = (QTextEdit*)mdiArea->currentSubWindow( )->widget( );
    textedit->setCurrentFont(font);
}

void QtEditor::setTextSize(qreal size)            /* QTextEdit에 폰트 크기 설정 */
{
    qDebug("setTextSize");
    QTextEdit *textedit = (QTextEdit*)mdiArea->currentSubWindow( )->widget( );
    QFont font = textedit->currentFont( );
    font.setPointSizeF(size);
    textedit->setCurrentFont(font);           /* textedit->setFontPointSize(size); */
}

void QtEditor::undo( ) {
    QMdiSubWindow *subWindow = mdiArea->currentSubWindow( );
    if(subWindow != nullptr) {
        QTextEdit *textedit = dynamic_cast<QTextEdit*>(subWindow->widget( ));
        textedit->undo( );
    }
}

void QtEditor::redo( ) {
    QMdiSubWindow *subWindow = mdiArea->currentSubWindow( );
    if(subWindow != nullptr) {
        QTextEdit *textedit = dynamic_cast<QTextEdit*>(subWindow->widget( ));
        textedit->redo( );
    }
}

void QtEditor::copy( ) {
    QMdiSubWindow *subWindow = mdiArea->currentSubWindow( );
    if(subWindow != nullptr) {
        QTextEdit *textedit = dynamic_cast<QTextEdit*>(subWindow->widget( ));
        textedit->copy( );
    }
}

void QtEditor::cut( ) {
    QMdiSubWindow *subWindow = mdiArea->currentSubWindow( );
    if(subWindow != nullptr) {
        QTextEdit *textedit = dynamic_cast<QTextEdit*>(subWindow->widget( ));
        textedit->cut( );
    }
}

void QtEditor::paste( ) {
    QMdiSubWindow *subWindow = mdiArea->currentSubWindow( );
    if(subWindow != nullptr) {
        QTextEdit *textedit = dynamic_cast<QTextEdit*>(subWindow->widget( ));
        textedit->paste( );
    }
}

void QtEditor::zoomIn( ) {
    QMdiSubWindow *subWindow = mdiArea->currentSubWindow( );
    if(subWindow != nullptr) {
        QTextEdit *textedit = dynamic_cast<QTextEdit*>(subWindow->widget( ));
        textedit->zoomIn( );
    }
}

void QtEditor::zoomOut( ) {
    QMdiSubWindow *subWindow = mdiArea->currentSubWindow( );
    if(subWindow != nullptr) {
        QTextEdit *textedit = dynamic_cast<QTextEdit*>(subWindow->widget( ));
        textedit->zoomOut( );
    }
}
