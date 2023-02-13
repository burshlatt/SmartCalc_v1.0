/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../SmartCalc/mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_MainWindow_t {
    uint offsetsAndSizes[24];
    char stringdata0[11];
    char stringdata1[19];
    char stringdata2[1];
    char stringdata3[18];
    char stringdata4[19];
    char stringdata5[18];
    char stringdata6[22];
    char stringdata7[21];
    char stringdata8[12];
    char stringdata9[7];
    char stringdata10[16];
    char stringdata11[13];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MainWindow_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 18),  // "on_subFunc_clicked"
        QT_MOC_LITERAL(30, 0),  // ""
        QT_MOC_LITERAL(31, 17),  // "on_dotSym_clicked"
        QT_MOC_LITERAL(49, 18),  // "on_delElem_clicked"
        QT_MOC_LITERAL(68, 17),  // "on_delAll_clicked"
        QT_MOC_LITERAL(86, 21),  // "on_resultFunc_clicked"
        QT_MOC_LITERAL(108, 20),  // "on_showGraph_clicked"
        QT_MOC_LITERAL(129, 11),  // "print_graph"
        QT_MOC_LITERAL(141, 6),  // "result"
        QT_MOC_LITERAL(148, 15),  // "symbols_clicked"
        QT_MOC_LITERAL(164, 12)   // "func_clicked"
    },
    "MainWindow",
    "on_subFunc_clicked",
    "",
    "on_dotSym_clicked",
    "on_delElem_clicked",
    "on_delAll_clicked",
    "on_resultFunc_clicked",
    "on_showGraph_clicked",
    "print_graph",
    "result",
    "symbols_clicked",
    "func_clicked"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x08,    1 /* Private */,
       3,    0,   69,    2, 0x08,    2 /* Private */,
       4,    0,   70,    2, 0x08,    3 /* Private */,
       5,    0,   71,    2, 0x08,    4 /* Private */,
       6,    0,   72,    2, 0x08,    5 /* Private */,
       7,    0,   73,    2, 0x08,    6 /* Private */,
       8,    1,   74,    2, 0x08,    7 /* Private */,
      10,    0,   77,    2, 0x08,    9 /* Private */,
      11,    0,   78,    2, 0x08,   10 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    9,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSizes,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'on_subFunc_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_dotSym_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_delElem_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_delAll_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_resultFunc_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_showGraph_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'print_graph'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'symbols_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'func_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_subFunc_clicked(); break;
        case 1: _t->on_dotSym_clicked(); break;
        case 2: _t->on_delElem_clicked(); break;
        case 3: _t->on_delAll_clicked(); break;
        case 4: _t->on_resultFunc_clicked(); break;
        case 5: _t->on_showGraph_clicked(); break;
        case 6: _t->print_graph((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 7: _t->symbols_clicked(); break;
        case 8: _t->func_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
