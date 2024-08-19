#ifndef QTEDITOR_H
#define QTEDITOR_H

#include <QMainWindow>
#include <QList>
#include <QHash>

class QAction;
class QMdiArea;
class QTextEdit;
class QFontComboBox;
class QDoubleSpinBox;
class QMdiSubWindow;

class QtEditor : public QMainWindow
{
    Q_OBJECT

public:
    QtEditor(QWidget *parent = nullptr);
    ~QtEditor();


public slots:
    // c언어와 다르게 c++은 멤버함수를 선언한 후에 구현하지 않으면 error 발생!

    /* File Menu */
    QTextEdit *newFile();
    void openFile( );
    void saveFile( );
    void saveAsFile( );
    void printFile( );

    /* Edit Menu */
    void undo( );
    void redo( );
    void copy( );
    void cut( );
    void paste( );
    void zoomIn( );
    void zoomOut( );

    /* Format Menu */
    void setFont( );
    void setColor( );
    void alignText( );

    void setTextFont(QFont font);
    void setTextSize(qreal size);

    void setFontWidget( );
    void selectWindow( );
    //void closeWindow( );

    /* Help Menu */
    void about( );

private:
    template <typename T>
    QAction *makeAction(QString icon, QString text, T shortCut, QString toolTip,
                        QObject* recv, const char* slot);
    // 테플릿의 특수화
    template <>
    QAction *makeAction(QString icon, QString text, const char* shortCut, QString toolTip,
                        QObject* recv, const char* slot);

    // 람다 함수의 사용
    template <typename T, typename Functor>
    QAction *makeAction(QString icon, QString text, T shortCut, QString toolTip,
                         Functor lambda);
    QMdiArea *mdiArea;

    int newfilenum = 0;

    QFontComboBox *fontComboBox;
    QDoubleSpinBox *sizeSpinBox;

    QList<QAction*> actions;
    QTextEdit *prevTextEdit = nullptr;

    QMenu *windowMenu;

    QHash<QAction*,QWidget*> windowHash;

};
#endif // QTEDITOR_H
