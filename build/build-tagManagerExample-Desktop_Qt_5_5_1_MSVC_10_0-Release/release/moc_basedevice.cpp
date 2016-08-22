/****************************************************************************
** Meta object code from reading C++ file 'basedevice.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Qt.711.2016.common/lib/common/basedevice.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'basedevice.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_baseDevice_t {
    QByteArrayData data[10];
    char stringdata0[107];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_baseDevice_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_baseDevice_t qt_meta_stringdata_baseDevice = {
    {
QT_MOC_LITERAL(0, 0, 10), // "baseDevice"
QT_MOC_LITERAL(1, 11, 15), // "msgStateChanged"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 5), // "state"
QT_MOC_LITERAL(4, 34, 11), // "msgErrorSet"
QT_MOC_LITERAL(5, 46, 9), // "errorCode"
QT_MOC_LITERAL(6, 56, 13), // "msgErrorReset"
QT_MOC_LITERAL(7, 70, 14), // "msgNameChanged"
QT_MOC_LITERAL(8, 85, 4), // "name"
QT_MOC_LITERAL(9, 90, 16) // "msgDeviceChanged"

    },
    "baseDevice\0msgStateChanged\0\0state\0"
    "msgErrorSet\0errorCode\0msgErrorReset\0"
    "msgNameChanged\0name\0msgDeviceChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_baseDevice[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    1,   42,    2, 0x06 /* Public */,
       6,    1,   45,    2, 0x06 /* Public */,
       7,    1,   48,    2, 0x06 /* Public */,
       9,    1,   51,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::ULongLong,    3,
    QMetaType::Void, QMetaType::ULongLong,    5,
    QMetaType::Void, QMetaType::ULongLong,    5,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,

       0        // eod
};

void baseDevice::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        baseDevice *_t = static_cast<baseDevice *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->msgStateChanged((*reinterpret_cast< quint64(*)>(_a[1]))); break;
        case 1: _t->msgErrorSet((*reinterpret_cast< quint64(*)>(_a[1]))); break;
        case 2: _t->msgErrorReset((*reinterpret_cast< quint64(*)>(_a[1]))); break;
        case 3: _t->msgNameChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->msgDeviceChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (baseDevice::*_t)(quint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&baseDevice::msgStateChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (baseDevice::*_t)(quint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&baseDevice::msgErrorSet)) {
                *result = 1;
            }
        }
        {
            typedef void (baseDevice::*_t)(quint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&baseDevice::msgErrorReset)) {
                *result = 2;
            }
        }
        {
            typedef void (baseDevice::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&baseDevice::msgNameChanged)) {
                *result = 3;
            }
        }
        {
            typedef void (baseDevice::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&baseDevice::msgDeviceChanged)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject baseDevice::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_baseDevice.data,
      qt_meta_data_baseDevice,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *baseDevice::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *baseDevice::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_baseDevice.stringdata0))
        return static_cast<void*>(const_cast< baseDevice*>(this));
    if (!strcmp(_clname, "iErrMsg"))
        return static_cast< iErrMsg*>(const_cast< baseDevice*>(this));
    if (!strcmp(_clname, "iStateMsg"))
        return static_cast< iStateMsg*>(const_cast< baseDevice*>(this));
    if (!strcmp(_clname, "iLoadSave"))
        return static_cast< iLoadSave*>(const_cast< baseDevice*>(this));
    return QObject::qt_metacast(_clname);
}

int baseDevice::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void baseDevice::msgStateChanged(quint64 _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void baseDevice::msgErrorSet(quint64 _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void baseDevice::msgErrorReset(quint64 _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void baseDevice::msgNameChanged(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void baseDevice::msgDeviceChanged(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
