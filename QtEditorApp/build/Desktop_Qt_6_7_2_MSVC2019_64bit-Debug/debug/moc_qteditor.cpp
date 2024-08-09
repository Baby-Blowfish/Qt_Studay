/****************************************************************************
** Meta object code from reading C++ file 'qteditor.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../qteditor.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qteditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSQtEditorENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSQtEditorENDCLASS = QtMocHelpers::stringData(
    "QtEditor",
    "newFile",
    "QTextEdit*",
    "",
    "saveFile",
    "saveAsFile",
    "openFile",
    "printFile",
    "setTextFont",
    "font",
    "setTextSize",
    "size",
    "setFontWidget",
    "undo"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSQtEditorENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    3, 0x0a,    1 /* Public */,
       4,    0,   69,    3, 0x0a,    2 /* Public */,
       5,    0,   70,    3, 0x0a,    3 /* Public */,
       6,    0,   71,    3, 0x0a,    4 /* Public */,
       7,    0,   72,    3, 0x0a,    5 /* Public */,
       8,    1,   73,    3, 0x0a,    6 /* Public */,
      10,    1,   76,    3, 0x0a,    8 /* Public */,
      12,    0,   79,    3, 0x0a,   10 /* Public */,
      13,    0,   80,    3, 0x0a,   11 /* Public */,

 // slots: parameters
    0x80000000 | 2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QFont,    9,
    QMetaType::Void, QMetaType::QReal,   11,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject QtEditor::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSQtEditorENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSQtEditorENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSQtEditorENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QtEditor, std::true_type>,
        // method 'newFile'
        QtPrivate::TypeAndForceComplete<QTextEdit *, std::false_type>,
        // method 'saveFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'saveAsFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'openFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'printFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setTextFont'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QFont, std::false_type>,
        // method 'setTextSize'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qreal, std::false_type>,
        // method 'setFontWidget'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'undo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void QtEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QtEditor *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { QTextEdit* _r = _t->newFile();
            if (_a[0]) *reinterpret_cast< QTextEdit**>(_a[0]) = std::move(_r); }  break;
        case 1: _t->saveFile(); break;
        case 2: _t->saveAsFile(); break;
        case 3: _t->openFile(); break;
        case 4: _t->printFile(); break;
        case 5: _t->setTextFont((*reinterpret_cast< std::add_pointer_t<QFont>>(_a[1]))); break;
        case 6: _t->setTextSize((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 7: _t->setFontWidget(); break;
        case 8: _t->undo(); break;
        default: ;
        }
    }
}

const QMetaObject *QtEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSQtEditorENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int QtEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
