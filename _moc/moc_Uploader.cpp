/****************************************************************************
** Meta object code from reading C++ file 'Uploader.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Uploader/Uploader.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Uploader.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Uploader_t {
    QByteArrayData data[25];
    char stringdata[384];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Uploader_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Uploader_t qt_meta_stringdata_Uploader = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 20),
QT_MOC_LITERAL(2, 30, 0),
QT_MOC_LITERAL(3, 31, 18),
QT_MOC_LITERAL(4, 50, 19),
QT_MOC_LITERAL(5, 70, 20),
QT_MOC_LITERAL(6, 91, 18),
QT_MOC_LITERAL(7, 110, 11),
QT_MOC_LITERAL(8, 122, 19),
QT_MOC_LITERAL(9, 142, 18),
QT_MOC_LITERAL(10, 161, 16),
QT_MOC_LITERAL(11, 178, 17),
QT_MOC_LITERAL(12, 196, 21),
QT_MOC_LITERAL(13, 218, 8),
QT_MOC_LITERAL(14, 227, 3),
QT_MOC_LITERAL(15, 231, 25),
QT_MOC_LITERAL(16, 257, 5),
QT_MOC_LITERAL(17, 263, 15),
QT_MOC_LITERAL(18, 279, 16),
QT_MOC_LITERAL(19, 296, 9),
QT_MOC_LITERAL(20, 306, 21),
QT_MOC_LITERAL(21, 328, 7),
QT_MOC_LITERAL(22, 336, 5),
QT_MOC_LITERAL(23, 342, 19),
QT_MOC_LITERAL(24, 362, 20)
    },
    "Uploader\0signalTranslateStart\0\0"
    "signalCompileStart\0signalWriteProStart\0"
    "signalTranslateError\0signalCompileError\0"
    "errorString\0signalWriteProError\0"
    "signalTranslateEnd\0signalCompileEnd\0"
    "signalWriteProEnd\0signalCurrentProgress\0"
    "progress\0sec\0signalTypeConversionError\0"
    "error\0signalPortError\0signalBoardError\0"
    "slotStart\0slotTranslateProgress\0current\0"
    "total\0slotCompileProgress\0"
    "slotWriteProProgress\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Uploader[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      13,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x05,
       3,    0,  100,    2, 0x05,
       4,    0,  101,    2, 0x05,
       5,    0,  102,    2, 0x05,
       6,    1,  103,    2, 0x05,
       8,    0,  106,    2, 0x05,
       9,    0,  107,    2, 0x05,
      10,    0,  108,    2, 0x05,
      11,    0,  109,    2, 0x05,
      12,    2,  110,    2, 0x05,
      15,    1,  115,    2, 0x05,
      17,    1,  118,    2, 0x05,
      18,    1,  121,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
      19,    0,  124,    2, 0x0a,
      20,    3,  125,    2, 0x0a,
      23,    3,  132,    2, 0x0a,
      24,    3,  139,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float, QMetaType::Int,   13,   14,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, QMetaType::QString,   16,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Int,   21,   22,   14,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Int,   21,   22,   14,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Int,   21,   22,   14,

       0        // eod
};

void Uploader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Uploader *_t = static_cast<Uploader *>(_o);
        switch (_id) {
        case 0: _t->signalTranslateStart(); break;
        case 1: _t->signalCompileStart(); break;
        case 2: _t->signalWriteProStart(); break;
        case 3: _t->signalTranslateError(); break;
        case 4: _t->signalCompileError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->signalWriteProError(); break;
        case 6: _t->signalTranslateEnd(); break;
        case 7: _t->signalCompileEnd(); break;
        case 8: _t->signalWriteProEnd(); break;
        case 9: _t->signalCurrentProgress((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: _t->signalTypeConversionError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->signalPortError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->signalBoardError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: _t->slotStart(); break;
        case 14: _t->slotTranslateProgress((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 15: _t->slotCompileProgress((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 16: _t->slotWriteProProgress((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Uploader::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Uploader::signalTranslateStart)) {
                *result = 0;
            }
        }
        {
            typedef void (Uploader::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Uploader::signalCompileStart)) {
                *result = 1;
            }
        }
        {
            typedef void (Uploader::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Uploader::signalWriteProStart)) {
                *result = 2;
            }
        }
        {
            typedef void (Uploader::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Uploader::signalTranslateError)) {
                *result = 3;
            }
        }
        {
            typedef void (Uploader::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Uploader::signalCompileError)) {
                *result = 4;
            }
        }
        {
            typedef void (Uploader::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Uploader::signalWriteProError)) {
                *result = 5;
            }
        }
        {
            typedef void (Uploader::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Uploader::signalTranslateEnd)) {
                *result = 6;
            }
        }
        {
            typedef void (Uploader::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Uploader::signalCompileEnd)) {
                *result = 7;
            }
        }
        {
            typedef void (Uploader::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Uploader::signalWriteProEnd)) {
                *result = 8;
            }
        }
        {
            typedef void (Uploader::*_t)(float , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Uploader::signalCurrentProgress)) {
                *result = 9;
            }
        }
        {
            typedef void (Uploader::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Uploader::signalTypeConversionError)) {
                *result = 10;
            }
        }
        {
            typedef void (Uploader::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Uploader::signalPortError)) {
                *result = 11;
            }
        }
        {
            typedef void (Uploader::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Uploader::signalBoardError)) {
                *result = 12;
            }
        }
    }
}

const QMetaObject Uploader::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Uploader.data,
      qt_meta_data_Uploader,  qt_static_metacall, 0, 0}
};


const QMetaObject *Uploader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Uploader::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Uploader.stringdata))
        return static_cast<void*>(const_cast< Uploader*>(this));
    return QObject::qt_metacast(_clname);
}

int Uploader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void Uploader::signalTranslateStart()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Uploader::signalCompileStart()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Uploader::signalWriteProStart()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void Uploader::signalTranslateError()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void Uploader::signalCompileError(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Uploader::signalWriteProError()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void Uploader::signalTranslateEnd()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void Uploader::signalCompileEnd()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}

// SIGNAL 8
void Uploader::signalWriteProEnd()
{
    QMetaObject::activate(this, &staticMetaObject, 8, 0);
}

// SIGNAL 9
void Uploader::signalCurrentProgress(float _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void Uploader::signalTypeConversionError(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void Uploader::signalPortError(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void Uploader::signalBoardError(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}
QT_END_MOC_NAMESPACE
