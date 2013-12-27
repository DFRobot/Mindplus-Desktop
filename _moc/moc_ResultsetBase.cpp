/****************************************************************************
** Meta object code from reading C++ file 'ResultsetBase.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Other/Data/ResultsetBase.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ResultsetBase.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ResultsetBase_t {
    QByteArrayData data[7];
    char stringdata[105];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ResultsetBase_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ResultsetBase_t qt_meta_stringdata_ResultsetBase = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 11),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 14),
QT_MOC_LITERAL(4, 42, 9),
QT_MOC_LITERAL(5, 52, 23),
QT_MOC_LITERAL(6, 76, 27)
    },
    "ResultsetBase\0signalError\0\0ResultsetError\0"
    "errorType\0signalOpenDataFileError\0"
    "signalTraverseDataFileError\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ResultsetBase[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x05,
       5,    0,   32,    2, 0x05,
       6,    0,   33,    2, 0x05,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ResultsetBase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ResultsetBase *_t = static_cast<ResultsetBase *>(_o);
        switch (_id) {
        case 0: _t->signalError((*reinterpret_cast< ResultsetError(*)>(_a[1]))); break;
        case 1: _t->signalOpenDataFileError(); break;
        case 2: _t->signalTraverseDataFileError(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ResultsetBase::*_t)(ResultsetError );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ResultsetBase::signalError)) {
                *result = 0;
            }
        }
        {
            typedef void (ResultsetBase::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ResultsetBase::signalOpenDataFileError)) {
                *result = 1;
            }
        }
        {
            typedef void (ResultsetBase::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ResultsetBase::signalTraverseDataFileError)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject ResultsetBase::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ResultsetBase.data,
      qt_meta_data_ResultsetBase,  qt_static_metacall, 0, 0}
};


const QMetaObject *ResultsetBase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ResultsetBase::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ResultsetBase.stringdata))
        return static_cast<void*>(const_cast< ResultsetBase*>(this));
    return QObject::qt_metacast(_clname);
}

int ResultsetBase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void ResultsetBase::signalError(ResultsetError _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ResultsetBase::signalOpenDataFileError()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void ResultsetBase::signalTraverseDataFileError()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
