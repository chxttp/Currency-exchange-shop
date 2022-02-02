/****************************************************************************
** Meta object code from reading C++ file 'Main.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../cppproject1/Main.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Main.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Main_t {
    QByteArrayData data[12];
    char stringdata0[73];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Main_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Main_t qt_meta_stringdata_Main = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Main"
QT_MOC_LITERAL(1, 5, 5), // "delay"
QT_MOC_LITERAL(2, 11, 0), // ""
QT_MOC_LITERAL(3, 12, 1), // "n"
QT_MOC_LITERAL(4, 14, 1), // "m"
QT_MOC_LITERAL(5, 16, 7), // "select0"
QT_MOC_LITERAL(6, 24, 7), // "select1"
QT_MOC_LITERAL(7, 32, 5), // "index"
QT_MOC_LITERAL(8, 38, 7), // "select2"
QT_MOC_LITERAL(9, 46, 7), // "select3"
QT_MOC_LITERAL(10, 54, 7), // "select4"
QT_MOC_LITERAL(11, 62, 10) // "dailyToday"

    },
    "Main\0delay\0\0n\0m\0select0\0select1\0index\0"
    "select2\0select3\0select4\0dailyToday"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Main[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x0a /* Public */,
       5,    0,   54,    2, 0x0a /* Public */,
       6,    1,   55,    2, 0x0a /* Public */,
       8,    1,   58,    2, 0x0a /* Public */,
       9,    0,   61,    2, 0x0a /* Public */,
      10,    0,   62,    2, 0x0a /* Public */,
      11,    0,   63,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Main::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Main *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->delay((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->select0(); break;
        case 2: _t->select1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->select2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->select3(); break;
        case 5: _t->select4(); break;
        case 6: _t->dailyToday(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Main::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_Main.data,
    qt_meta_data_Main,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Main::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Main::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Main.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Accessories"))
        return static_cast< Accessories*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Main::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
