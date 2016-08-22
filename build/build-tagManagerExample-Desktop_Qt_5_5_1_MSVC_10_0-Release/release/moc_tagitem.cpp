/****************************************************************************
** Meta object code from reading C++ file 'tagitem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../lib/tagManager/tagitem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tagitem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_tagItem_t {
    QByteArrayData data[8];
    char stringdata0[82];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_tagItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_tagItem_t qt_meta_stringdata_tagItem = {
    {
QT_MOC_LITERAL(0, 0, 7), // "tagItem"
QT_MOC_LITERAL(1, 8, 17), // "msgTagItemChanged"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 8), // "tagItem*"
QT_MOC_LITERAL(4, 36, 4), // "item"
QT_MOC_LITERAL(5, 41, 22), // "msgTagItemValueChanged"
QT_MOC_LITERAL(6, 64, 8), // "setValue"
QT_MOC_LITERAL(7, 73, 8) // "newValue"

    },
    "tagItem\0msgTagItemChanged\0\0tagItem*\0"
    "item\0msgTagItemValueChanged\0setValue\0"
    "newValue"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_tagItem[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       5,    1,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QVariant,    7,

       0        // eod
};

void tagItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        tagItem *_t = static_cast<tagItem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->msgTagItemChanged((*reinterpret_cast< tagItem*(*)>(_a[1]))); break;
        case 1: _t->msgTagItemValueChanged((*reinterpret_cast< tagItem*(*)>(_a[1]))); break;
        case 2: _t->setValue((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< tagItem* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< tagItem* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (tagItem::*_t)(tagItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&tagItem::msgTagItemChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (tagItem::*_t)(tagItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&tagItem::msgTagItemValueChanged)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject tagItem::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_tagItem.data,
      qt_meta_data_tagItem,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *tagItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *tagItem::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_tagItem.stringdata0))
        return static_cast<void*>(const_cast< tagItem*>(this));
    if (!strcmp(_clname, "iLoadSave"))
        return static_cast< iLoadSave*>(const_cast< tagItem*>(this));
    if (!strcmp(_clname, "iTagItemCommon"))
        return static_cast< iTagItemCommon*>(const_cast< tagItem*>(this));
    if (!strcmp(_clname, "iTagItemUpdate"))
        return static_cast< iTagItemUpdate*>(const_cast< tagItem*>(this));
    if (!strcmp(_clname, "iTagItemSelfCheck"))
        return static_cast< iTagItemSelfCheck*>(const_cast< tagItem*>(this));
    return QObject::qt_metacast(_clname);
}

int tagItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void tagItem::msgTagItemChanged(tagItem * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void tagItem::msgTagItemValueChanged(tagItem * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
