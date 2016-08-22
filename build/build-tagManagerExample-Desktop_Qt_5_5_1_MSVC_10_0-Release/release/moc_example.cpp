/****************************************************************************
** Meta object code from reading C++ file 'example.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../example/tagManager/example.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'example.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_example_t {
    QByteArrayData data[10];
    char stringdata0[108];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_example_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_example_t qt_meta_stringdata_example = {
    {
QT_MOC_LITERAL(0, 0, 7), // "example"
QT_MOC_LITERAL(1, 8, 10), // "paintEvent"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 12), // "QPaintEvent*"
QT_MOC_LITERAL(4, 33, 1), // "e"
QT_MOC_LITERAL(5, 35, 13), // "updateTagItem"
QT_MOC_LITERAL(6, 49, 5), // "tagID"
QT_MOC_LITERAL(7, 55, 13), // "removeTagItem"
QT_MOC_LITERAL(8, 69, 17), // "on_PB_add_clicked"
QT_MOC_LITERAL(9, 87, 20) // "on_PB_delete_clicked"

    },
    "example\0paintEvent\0\0QPaintEvent*\0e\0"
    "updateTagItem\0tagID\0removeTagItem\0"
    "on_PB_add_clicked\0on_PB_delete_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_example[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x0a /* Public */,
       5,    1,   42,    2, 0x08 /* Private */,
       7,    1,   45,    2, 0x08 /* Private */,
       8,    0,   48,    2, 0x08 /* Private */,
       9,    0,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void example::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        example *_t = static_cast<example *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->paintEvent((*reinterpret_cast< QPaintEvent*(*)>(_a[1]))); break;
        case 1: _t->updateTagItem((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->removeTagItem((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->on_PB_add_clicked(); break;
        case 4: _t->on_PB_delete_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject example::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_example.data,
      qt_meta_data_example,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *example::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *example::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_example.stringdata0))
        return static_cast<void*>(const_cast< example*>(this));
    return QWidget::qt_metacast(_clname);
}

int example::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
