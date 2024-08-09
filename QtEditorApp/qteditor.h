#ifndef QTEDITOR_H
#define QTEDITOR_H

#include <QMainWindow>

class QAction;
class QMdiArea;
class QTextEdit;
class QFontComboBox;
class QDoubleSpinBox;

class QtEditor : public QMainWindow
{
    Q_OBJECT

public:
    QtEditor(QWidget *parent = nullptr);
    ~QtEditor();


public slots:
    QTextEdit *newFile();
    void saveFile();
    void saveAsFile();
    void openFile();
    void printFile();
    void setTextFont(QFont font);
    void setTextSize(qreal size);
    void setFontWidget();
    void undo();

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

    QFontComboBox *fontComboBox;
    QDoubleSpinBox *sizeSpinBox;
};
#endif // QTEDITOR_H
