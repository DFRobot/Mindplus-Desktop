/****************************************************************************
** Meta object code from reading C++ file 'Translate.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Uploader/Translate.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Translate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Translate_t {
    QByteArrayData data[12];
    char stringdata[150];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Translate_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Translate_t qt_meta_stringdata_Translate = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 20),
QT_MOC_LITERAL(2, 31, 0),
QT_MOC_LITERAL(3, 32, 21),
QT_MOC_LITERAL(4, 54, 7),
QT_MOC_LITERAL(5, 62, 5),
QT_MOC_LITERAL(6, 68, 3),
QT_MOC_LITERAL(7, 72, 20),
QT_MOC_LITERAL(8, 93, 11),
QT_MOC_LITERAL(9, 105, 14),
QT_MOC_LITERAL(10, 120, 9),
QT_MOC_LITERAL(11, 130, 18)
    },
    "Translate\0signalTranslateStart\0\0"
    "signalAdvanceProgress\0current\0total\0"
    "sec\0signalTranslateError\0signalError\0"
    "TranslateError\0errorType\0signalTranslateEnd\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Translate[] = {

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
       1,    0,   39,    2, 0x05,
       3,    3,   40,    2, 0x05,
       7,    0,   47,    2, 0x05,
       8,    1,   48,    2, 0x05,
      11,    0,   51,    2, 0x05,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Int,    4,    5,    6,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,

       0        // eod
};

void Translate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Translate *_t = static_cast<Translate *>(_o);
        switch (_id) {
        case 0: _t->signalTranslateStart(); break;
        case 1: _t->signalAdvanceProgress((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->signalTranslateError(); break;
        case 3: _t->signalError((*reinterpret_cast< TranslateError(*)>(_a[1]))); break;
        case 4: _t->signalTranslateEnd(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Translate::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Translate::signalTranslateStart)) {
                *result = 0;
            }
        }
        {
            typedef void (Translate::*_t)(float , float , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Translate::signalAdvanceProgress)) {
                *result = 1;
            }
        }
        {
            typedef void (Translate::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Translate::signalTranslateError)) {
                *result = 2;
            }
        }
        {
            typedef void (Translate::*_t)(TranslateError );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Translate::signalError)) {
                *result = 3;
            }
        }
        {
            typedef void (Translate::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Translate::signalTranslateEnd)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject Translate::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Translate.data,
      qt_meta_data_Translate,  qt_static_metacall, 0, 0}
};


const QMetaObject *Translate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Translate::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Translate.stringdata))
        return static_cast<void*>(const_cast< Translate*>(this));
    return QObject::qt_metacast(_clname);
}

int Translate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Translate::signalTranslateStart()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Translate::signalAdvanceProgress(float _t1, float _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Translate::signalTranslateError()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void Translate::signalError(TranslateError _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Translate::signalTranslateEnd()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}
QT_END_MOC_NAMESPACE
