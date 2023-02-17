/****************************************************************************
** Meta object code from reading C++ file 'depositwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../SmartCalc/depositwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'depositwindow.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_DepositWindow_t {
    uint offsetsAndSizes[28];
    char stringdata0[14];
    char stringdata1[12];
    char stringdata2[1];
    char stringdata3[13];
    char stringdata4[15];
    char stringdata5[8];
    char stringdata6[8];
    char stringdata7[10];
    char stringdata8[22];
    char stringdata9[22];
    char stringdata10[22];
    char stringdata11[25];
    char stringdata12[20];
    char stringdata13[23];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_DepositWindow_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_DepositWindow_t qt_meta_stringdata_DepositWindow = {
    {
        QT_MOC_LITERAL(0, 13),  // "DepositWindow"
        QT_MOC_LITERAL(14, 11),  // "firstWindow"
        QT_MOC_LITERAL(26, 0),  // ""
        QT_MOC_LITERAL(27, 12),  // "check_period"
        QT_MOC_LITERAL(40, 14),  // "converted_time"
        QT_MOC_LITERAL(55, 7),  // "double*"
        QT_MOC_LITERAL(63, 7),  // "add_sum"
        QT_MOC_LITERAL(71, 9),  // "waste_sum"
        QT_MOC_LITERAL(81, 21),  // "on_calculator_clicked"
        QT_MOC_LITERAL(103, 21),  // "on_showResult_clicked"
        QT_MOC_LITERAL(125, 21),  // "on_addPayment_clicked"
        QT_MOC_LITERAL(147, 24),  // "on_deletePayment_clicked"
        QT_MOC_LITERAL(172, 19),  // "on_addWaste_clicked"
        QT_MOC_LITERAL(192, 22)   // "on_deleteWaste_clicked"
    },
    "DepositWindow",
    "firstWindow",
    "",
    "check_period",
    "converted_time",
    "double*",
    "add_sum",
    "waste_sum",
    "on_calculator_clicked",
    "on_showResult_clicked",
    "on_addPayment_clicked",
    "on_deletePayment_clicked",
    "on_addWaste_clicked",
    "on_deleteWaste_clicked"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_DepositWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    3,   63,    2, 0x08,    2 /* Private */,
       8,    0,   70,    2, 0x08,    6 /* Private */,
       9,    0,   71,    2, 0x08,    7 /* Private */,
      10,    0,   72,    2, 0x08,    8 /* Private */,
      11,    0,   73,    2, 0x08,    9 /* Private */,
      12,    0,   74,    2, 0x08,   10 /* Private */,
      13,    0,   75,    2, 0x08,   11 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 5, 0x80000000 | 5,    4,    6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject DepositWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_DepositWindow.offsetsAndSizes,
    qt_meta_data_DepositWindow,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_DepositWindow_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<DepositWindow, std::true_type>,
        // method 'firstWindow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'check_period'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<double *, std::false_type>,
        QtPrivate::TypeAndForceComplete<double *, std::false_type>,
        // method 'on_calculator_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_showResult_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_addPayment_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_deletePayment_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_addWaste_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_deleteWaste_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void DepositWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DepositWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->firstWindow(); break;
        case 1: _t->check_period((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double*>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<double*>>(_a[3]))); break;
        case 2: _t->on_calculator_clicked(); break;
        case 3: _t->on_showResult_clicked(); break;
        case 4: _t->on_addPayment_clicked(); break;
        case 5: _t->on_deletePayment_clicked(); break;
        case 6: _t->on_addWaste_clicked(); break;
        case 7: _t->on_deleteWaste_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DepositWindow::*)();
            if (_t _q_method = &DepositWindow::firstWindow; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *DepositWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DepositWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DepositWindow.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int DepositWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void DepositWindow::firstWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
