/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[16];
    char stringdata0[393];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 31), // "on_exposure_slider_valueChanged"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 5), // "value"
QT_MOC_LITERAL(4, 50, 28), // "on_apply_bloom_check_clicked"
QT_MOC_LITERAL(5, 79, 7), // "checked"
QT_MOC_LITERAL(6, 87, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(7, 109, 43), // "on_gravitational_constant_spi..."
QT_MOC_LITERAL(8, 153, 4), // "arg1"
QT_MOC_LITERAL(9, 158, 37), // "on_softening_factor_spin_valu..."
QT_MOC_LITERAL(10, 196, 29), // "on_exposure_spin_valueChanged"
QT_MOC_LITERAL(11, 226, 34), // "on_red_threshold_spin_valueCh..."
QT_MOC_LITERAL(12, 261, 36), // "on_green_threshold_spin_value..."
QT_MOC_LITERAL(13, 298, 35), // "on_blue_threshold_spin_valueC..."
QT_MOC_LITERAL(14, 334, 34), // "on_particle_size_spin_valueCh..."
QT_MOC_LITERAL(15, 369, 23) // "on_pushButton_2_clicked"

    },
    "MainWindow\0on_exposure_slider_valueChanged\0"
    "\0value\0on_apply_bloom_check_clicked\0"
    "checked\0on_pushButton_clicked\0"
    "on_gravitational_constant_spin_valueChanged\0"
    "arg1\0on_softening_factor_spin_valueChanged\0"
    "on_exposure_spin_valueChanged\0"
    "on_red_threshold_spin_valueChanged\0"
    "on_green_threshold_spin_valueChanged\0"
    "on_blue_threshold_spin_valueChanged\0"
    "on_particle_size_spin_valueChanged\0"
    "on_pushButton_2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x08 /* Private */,
       4,    1,  102,    2, 0x08 /* Private */,
       6,    0,  105,    2, 0x08 /* Private */,
       7,    1,  106,    2, 0x08 /* Private */,
       7,    1,  109,    2, 0x08 /* Private */,
       9,    1,  112,    2, 0x08 /* Private */,
       9,    1,  115,    2, 0x08 /* Private */,
      10,    1,  118,    2, 0x08 /* Private */,
      11,    1,  121,    2, 0x08 /* Private */,
      11,    1,  124,    2, 0x08 /* Private */,
      12,    1,  127,    2, 0x08 /* Private */,
      12,    1,  130,    2, 0x08 /* Private */,
      13,    1,  133,    2, 0x08 /* Private */,
      13,    1,  136,    2, 0x08 /* Private */,
      14,    1,  139,    2, 0x08 /* Private */,
      14,    1,  142,    2, 0x08 /* Private */,
      15,    0,  145,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::Double,    8,
    QMetaType::Void, QMetaType::Double,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::Double,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::Double,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::Double,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::Double,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::Double,    8,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_exposure_slider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_apply_bloom_check_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_pushButton_clicked(); break;
        case 3: _t->on_gravitational_constant_spin_valueChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_gravitational_constant_spin_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->on_softening_factor_spin_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->on_softening_factor_spin_valueChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_exposure_spin_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->on_red_threshold_spin_valueChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->on_red_threshold_spin_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->on_green_threshold_spin_valueChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->on_green_threshold_spin_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 12: _t->on_blue_threshold_spin_valueChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: _t->on_blue_threshold_spin_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 14: _t->on_particle_size_spin_valueChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 15: _t->on_particle_size_spin_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 16: _t->on_pushButton_2_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
