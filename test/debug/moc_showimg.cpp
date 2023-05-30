/****************************************************************************
** Meta object code from reading C++ file 'showimg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../showimg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'showimg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ShowImg_t {
    QByteArrayData data[16];
    char stringdata0[115];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ShowImg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ShowImg_t qt_meta_stringdata_ShowImg = {
    {
QT_MOC_LITERAL(0, 0, 7), // "ShowImg"
QT_MOC_LITERAL(1, 8, 8), // "drawLine"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 2), // "x1"
QT_MOC_LITERAL(4, 21, 2), // "y1"
QT_MOC_LITERAL(5, 24, 2), // "x2"
QT_MOC_LITERAL(6, 27, 2), // "y2"
QT_MOC_LITERAL(7, 30, 1), // "r"
QT_MOC_LITERAL(8, 32, 1), // "g"
QT_MOC_LITERAL(9, 34, 1), // "b"
QT_MOC_LITERAL(10, 36, 1), // "t"
QT_MOC_LITERAL(11, 38, 9), // "smoothing"
QT_MOC_LITERAL(12, 48, 5), // "thick"
QT_MOC_LITERAL(13, 54, 12), // "SaveSettings"
QT_MOC_LITERAL(14, 67, 21), // "on_lineDraw_triggered"
QT_MOC_LITERAL(15, 89, 25) // "on_lineSettings_triggered"

    },
    "ShowImg\0drawLine\0\0x1\0y1\0x2\0y2\0r\0g\0b\0"
    "t\0smoothing\0thick\0SaveSettings\0"
    "on_lineDraw_triggered\0on_lineSettings_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ShowImg[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,   10,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    6,   55,    2, 0x0a /* Public */,
      14,    0,   68,    2, 0x08 /* Private */,
      15,    0,   69,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Double, QMetaType::Bool, QMetaType::Int,    3,    4,    5,    6,    7,    8,    9,   10,   11,   12,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Double, QMetaType::Bool, QMetaType::Int,    7,    8,    9,   10,   11,   12,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ShowImg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ShowImg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->drawLine((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< double(*)>(_a[8])),(*reinterpret_cast< bool(*)>(_a[9])),(*reinterpret_cast< int(*)>(_a[10]))); break;
        case 1: _t->SaveSettings((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6]))); break;
        case 2: _t->on_lineDraw_triggered(); break;
        case 3: _t->on_lineSettings_triggered(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ShowImg::*)(int , int , int , int , int , int , int , double , bool , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ShowImg::drawLine)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ShowImg::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_ShowImg.data,
    qt_meta_data_ShowImg,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ShowImg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ShowImg::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ShowImg.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int ShowImg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void ShowImg::drawLine(int _t1, int _t2, int _t3, int _t4, int _t5, int _t6, int _t7, double _t8, bool _t9, int _t10)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t7))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t8))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t9))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t10))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
