/****************************************************************************
** Meta object code from reading C++ file 'ToolBase.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Uploader/ToolBase.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ToolBase.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ToolBase_t {
    QByteArrayData data[26];
    char stringdata[379];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ToolBase_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ToolBase_t qt_meta_stringdata_ToolBase = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 16),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 18),
QT_MOC_LITERAL(4, 46, 19),
QT_MOC_LITERAL(5, 66, 16),
QT_MOC_LITERAL(6, 83, 16),
QT_MOC_LITERAL(7, 100, 18),
QT_MOC_LITERAL(8, 119, 11),
QT_MOC_LITERAL(9, 131, 19),
QT_MOC_LITERAL(10, 151, 16),
QT_MOC_LITERAL(11, 168, 14),
QT_MOC_LITERAL(12, 183, 16),
QT_MOC_LITERAL(13, 200, 17),
QT_MOC_LITERAL(14, 218, 11),
QT_MOC_LITERAL(15, 230, 9),
QT_MOC_LITERAL(16, 240, 9),
QT_MOC_LITERAL(17, 250, 21),
QT_MOC_LITERAL(18, 272, 7),
QT_MOC_LITERAL(19, 280, 5),
QT_MOC_LITERAL(20, 286, 3),
QT_MOC_LITERAL(21, 290, 22),
QT_MOC_LITERAL(22, 313, 25),
QT_MOC_LITERAL(23, 339, 5),
QT_MOC_LITERAL(24, 345, 15),
QT_MOC_LITERAL(25, 361, 16)
    },
    "ToolBase\0signalSetupStart\0\0"
    "signalCompileStart\0signalWriteProStart\0"
    "signalClearStart\0signalSetupError\0"
    "signalCompileError\0errorString\0"
    "signalWriteProError\0signalClearError\0"
    "signalSetupEnd\0signalCompileEnd\0"
    "signalWriteProEnd\0signalError\0ToolError\0"
    "errorType\0signalCompileProgress\0current\0"
    "total\0sec\0signalWriteProProgress\0"
    "signalTypeConversionError\0error\0"
    "signalPortError\0signalBoardError\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ToolBase[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      17,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x05,
       3,    0,  100,    2, 0x05,
       4,    0,  101,    2, 0x05,
       5,    0,  102,    2, 0x05,
       6,    0,  103,    2, 0x05,
       7,    1,  104,    2, 0x05,
       9,    0,  107,    2, 0x05,
      10,    0,  108,    2, 0x05,
      11,    0,  109,    2, 0x05,
      12,    0,  110,    2, 0x05,
      13,    0,  111,    2, 0x05,
      14,    1,  112,    2, 0x05,
      17,    3,  115,    2, 0x05,
      21,    3,  122,    2, 0x05,
      22,    1,  129,    2, 0x05,
      24,    1,  132,    2, 0x05,
      25,    1,  135,    2, 0x05,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Int,   18,   19,   20,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Int,   18,   19,   20,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void, QMetaType::QString,   23,

       0        // eod
};

void ToolBase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ToolBase *_t = static_cast<ToolBase *>(_o);
        switch (_id) {
        case 0: _t->signalSetupStart(); break;
        case 1: _t->signalCompileStart(); break;
        case 2: _t->signalWriteProStart(); break;
        case 3: _t->signalClearStart(); break;
        case 4: _t->signalSetupError(); break;
        case 5: _t->signalCompileError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->signalWriteProError(); break;
        case 7: _t->signalClearError(); break;
        case 8: _t->signalSetupEnd(); break;
        case 9: _t->signalCompileEnd(); break;
        case 10: _t->signalWriteProEnd(); break;
        case 11: _t->signalError((*reinterpret_cast< ToolError(*)>(_a[1]))); break;
        case 12: _t->signalCompileProgress((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 13: _t->signalWriteProProgress((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 14: _t->signalTypeConversionError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 15: _t->signalPortError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 16: _t->signalBoardError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ToolBase::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ToolBase::signalSetupStart)) {
                *result = 0;
            }
        }
        {
            typedef void (ToolBase::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ToolBase::signalCompileStart)) {
                *result = 1;
            }
        }
        {
            typedef void (ToolBase::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ToolBase::signalWriteProStart)) {
                *result = 2;
            }
        }
        {
            typedef void (ToolBase::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ToolBase::signalClearStart)) {
                *result = 3;
            }
        }
        {
            typedef void (ToolBase::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ToolBase::signalSetupError)) {
                *result = 4;
            }
        }
        {
            typedef void (ToolBase::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ToolBase::signalCompileError)) {
                *result = 5;
            }
        }
        {
            typedef void (ToolBase::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ToolBase::signalWriteProError)) {
                *result = 6;
            }
        }
        {
            typedef void (ToolBase::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ToolBase::signalClearError)) {
                *result = 7;
            }
        }
        {
            typedef void (ToolBase::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ToolBase::signalSetupEnd)) {
                *result = 8;
            }
        }
        {
            typedef void (ToolBase::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ToolBase::signalCompileEnd)) {
                *result = 9;
            }
        }
        {
            typedef void (ToolBase::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ToolBase::signalWriteProEnd)) {
                *result = 10;
            }
        }
        {
            typedef void (ToolBase::*_t)(ToolError );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ToolBase::signalError)) {
                *result = 11;
            }
        }
        {
            typedef void (ToolBase::*_t)(float , float , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ToolBase::signalCompileProgress)) {
                *result = 12;
            }
        }
        {
            typedef void (ToolBase::*_t)(float , float , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ToolBase::signalWriteProProgress)) {
                *result = 13;
            }
        }
        {
            typedef void (ToolBase::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ToolBase::signalTypeConversionError)) {
                *result = 14;
            }
        }
        {
            typedef void (ToolBase::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ToolBase::signalPortError)) {
                *result = 15;
            }
        }
        {
            typedef void (ToolBase::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ToolBase::signalBoardError)) {
                *result = 16;
            }
        }
    }
}

const QMetaObject ToolBase::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ToolBase.data,
      qt_meta_data_ToolBase,  qt_static_metacall, 0, 0}
};


const QMetaObject *ToolBase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ToolBase::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ToolBase.stringdata))
        return static_cast<void*>(const_cast< ToolBase*>(this));
    return QObject::qt_metacast(_clname);
}

int ToolBase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ToolBase::signalSetupStart()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ToolBase::signalCompileStart()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void ToolBase::signalWriteProStart()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void ToolBase::signalClearStart()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void ToolBase::signalSetupError()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void ToolBase::signalCompileError(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void ToolBase::signalWriteProError()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void ToolBase::signalClearError()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}

// SIGNAL 8
void ToolBase::signalSetupEnd()
{
    QMetaObject::activate(this, &staticMetaObject, 8, 0);
}

// SIGNAL 9
void ToolBase::signalCompileEnd()
{
    QMetaObject::activate(this, &staticMetaObject, 9, 0);
}

// SIGNAL 10
void ToolBase::signalWriteProEnd()
{
    QMetaObject::activate(this, &staticMetaObject, 10, 0);
}

// SIGNAL 11
void ToolBase::signalError(ToolError _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void ToolBase::signalCompileProgress(float _t1, float _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void ToolBase::signalWriteProProgress(float _t1, float _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void ToolBase::signalTypeConversionError(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void ToolBase::signalPortError(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void ToolBase::signalBoardError(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}
QT_END_MOC_NAMESPACE
