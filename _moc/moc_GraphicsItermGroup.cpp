/****************************************************************************
** Meta object code from reading C++ file 'GraphicsItermGroup.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GraphicFramework/Item/GraphicsItermGroup.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GraphicsItermGroup.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GraphicsItermGroup_t {
    QByteArrayData data[15];
    char stringdata[177];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_GraphicsItermGroup_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_GraphicsItermGroup_t qt_meta_stringdata_GraphicsItermGroup = {
    {
QT_MOC_LITERAL(0, 0, 18),
QT_MOC_LITERAL(1, 19, 21),
QT_MOC_LITERAL(2, 41, 0),
QT_MOC_LITERAL(3, 42, 6),
QT_MOC_LITERAL(4, 49, 14),
QT_MOC_LITERAL(5, 64, 9),
QT_MOC_LITERAL(6, 74, 1),
QT_MOC_LITERAL(7, 76, 12),
QT_MOC_LITERAL(8, 89, 6),
QT_MOC_LITERAL(9, 96, 22),
QT_MOC_LITERAL(10, 119, 25),
QT_MOC_LITERAL(11, 145, 6),
QT_MOC_LITERAL(12, 152, 14),
QT_MOC_LITERAL(13, 167, 4),
QT_MOC_LITERAL(14, 172, 3)
    },
    "GraphicsItermGroup\0signalGroupCurrentPos\0"
    "\0offset\0slotDeleteLine\0FlowLine*\0p\0"
    "slotOldPoint\0oldPos\0slotMousePressedOffset\0"
    "slotSetHandlesChildEvents\0enable\0"
    "slotDeleteItem\0name\0pos\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GraphicsItermGroup[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       1,   62, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       4,    1,   47,    2, 0x0a,
       7,    1,   50,    2, 0x0a,
       9,    1,   53,    2, 0x0a,
      10,    1,   56,    2, 0x08,
      12,    1,   59,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::QPointF,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::QPointF,    8,
    QMetaType::Void, QMetaType::QPointF,    3,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::QString,   13,

 // properties: name, type, flags
      14, QMetaType::QPointF, 0x00095903,

       0        // eod
};

void GraphicsItermGroup::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GraphicsItermGroup *_t = static_cast<GraphicsItermGroup *>(_o);
        switch (_id) {
        case 0: _t->signalGroupCurrentPos((*reinterpret_cast< const QPointF(*)>(_a[1]))); break;
        case 1: _t->slotDeleteLine((*reinterpret_cast< FlowLine*(*)>(_a[1]))); break;
        case 2: _t->slotOldPoint((*reinterpret_cast< const QPointF(*)>(_a[1]))); break;
        case 3: _t->slotMousePressedOffset((*reinterpret_cast< const QPointF(*)>(_a[1]))); break;
        case 4: _t->slotSetHandlesChildEvents((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->slotDeleteItem((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GraphicsItermGroup::*_t)(const QPointF & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GraphicsItermGroup::signalGroupCurrentPos)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject GraphicsItermGroup::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GraphicsItermGroup.data,
      qt_meta_data_GraphicsItermGroup,  qt_static_metacall, 0, 0}
};


const QMetaObject *GraphicsItermGroup::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GraphicsItermGroup::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GraphicsItermGroup.stringdata))
        return static_cast<void*>(const_cast< GraphicsItermGroup*>(this));
    if (!strcmp(_clname, "QGraphicsItemGroup"))
        return static_cast< QGraphicsItemGroup*>(const_cast< GraphicsItermGroup*>(this));
    return QObject::qt_metacast(_clname);
}

int GraphicsItermGroup::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QPointF*>(_v) = pos(); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setPos(*reinterpret_cast< QPointF*>(_v)); break;
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
void GraphicsItermGroup::signalGroupCurrentPos(const QPointF & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
