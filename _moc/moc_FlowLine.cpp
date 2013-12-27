/****************************************************************************
** Meta object code from reading C++ file 'FlowLine.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GraphicFramework/Item/FlowLine.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FlowLine.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FlowLine_t {
    QByteArrayData data[12];
    char stringdata[133];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_FlowLine_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_FlowLine_t qt_meta_stringdata_FlowLine = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 16),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 9),
QT_MOC_LITERAL(4, 37, 1),
QT_MOC_LITERAL(5, 39, 13),
QT_MOC_LITERAL(6, 53, 9),
QT_MOC_LITERAL(7, 63, 7),
QT_MOC_LITERAL(8, 71, 21),
QT_MOC_LITERAL(9, 93, 6),
QT_MOC_LITERAL(10, 100, 23),
QT_MOC_LITERAL(11, 124, 7)
    },
    "FlowLine\0signalDeleteLine\0\0FlowLine*\0"
    "p\0signalFocusIn\0startName\0endName\0"
    "slotEndItemMoveOffset\0offset\0"
    "slotStartItemMoveOffset\0opacity\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FlowLine[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       1,   50, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x05,
       5,    3,   37,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       8,    1,   44,    2, 0x0a,
      10,    1,   47,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, QMetaType::QString,    4,    6,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::QPointF,    9,
    QMetaType::Void, QMetaType::QPointF,    9,

 // properties: name, type, flags
      11, QMetaType::QReal, 0x00095903,

       0        // eod
};

void FlowLine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FlowLine *_t = static_cast<FlowLine *>(_o);
        switch (_id) {
        case 0: _t->signalDeleteLine((*reinterpret_cast< FlowLine*(*)>(_a[1]))); break;
        case 1: _t->signalFocusIn((*reinterpret_cast< FlowLine*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 2: _t->slotEndItemMoveOffset((*reinterpret_cast< const QPointF(*)>(_a[1]))); break;
        case 3: _t->slotStartItemMoveOffset((*reinterpret_cast< const QPointF(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< FlowLine* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< FlowLine* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (FlowLine::*_t)(FlowLine * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FlowLine::signalDeleteLine)) {
                *result = 0;
            }
        }
        {
            typedef void (FlowLine::*_t)(FlowLine * , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FlowLine::signalFocusIn)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject FlowLine::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_FlowLine.data,
      qt_meta_data_FlowLine,  qt_static_metacall, 0, 0}
};


const QMetaObject *FlowLine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FlowLine::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FlowLine.stringdata))
        return static_cast<void*>(const_cast< FlowLine*>(this));
    if (!strcmp(_clname, "QGraphicsPathItem"))
        return static_cast< QGraphicsPathItem*>(const_cast< FlowLine*>(this));
    return QObject::qt_metacast(_clname);
}

int FlowLine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< qreal*>(_v) = opacity(); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setOpacity(*reinterpret_cast< qreal*>(_v)); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void FlowLine::signalDeleteLine(FlowLine * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FlowLine::signalFocusIn(FlowLine * _t1, const QString & _t2, const QString & _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
