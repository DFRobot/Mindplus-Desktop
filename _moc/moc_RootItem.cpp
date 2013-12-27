/****************************************************************************
** Meta object code from reading C++ file 'RootItem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GraphicFramework/Item/RootItem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RootItem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RootItem_t {
    QByteArrayData data[11];
    char stringdata[141];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_RootItem_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_RootItem_t qt_meta_stringdata_RootItem = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 16),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 4),
QT_MOC_LITERAL(4, 32, 27),
QT_MOC_LITERAL(5, 60, 6),
QT_MOC_LITERAL(6, 67, 24),
QT_MOC_LITERAL(7, 92, 6),
QT_MOC_LITERAL(8, 99, 14),
QT_MOC_LITERAL(9, 114, 6),
QT_MOC_LITERAL(10, 121, 18)
    },
    "RootItem\0signalDeleteItem\0\0name\0"
    "signalSetHandlesChildEvents\0enable\0"
    "signalMousePressedOffset\0offset\0"
    "signalOldPoint\0oldPos\0signalFocusInGroup\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RootItem[] = {

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
       1,    1,   39,    2, 0x05,
       4,    1,   42,    2, 0x05,
       6,    1,   45,    2, 0x05,
       8,    1,   48,    2, 0x05,
      10,    1,   51,    2, 0x05,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::QPointF,    7,
    QMetaType::Void, QMetaType::QPointF,    9,
    QMetaType::Void, QMetaType::QString,    3,

       0        // eod
};

void RootItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RootItem *_t = static_cast<RootItem *>(_o);
        switch (_id) {
        case 0: _t->signalDeleteItem((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->signalSetHandlesChildEvents((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->signalMousePressedOffset((*reinterpret_cast< const QPointF(*)>(_a[1]))); break;
        case 3: _t->signalOldPoint((*reinterpret_cast< const QPointF(*)>(_a[1]))); break;
        case 4: _t->signalFocusInGroup((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (RootItem::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RootItem::signalDeleteItem)) {
                *result = 0;
            }
        }
        {
            typedef void (RootItem::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RootItem::signalSetHandlesChildEvents)) {
                *result = 1;
            }
        }
        {
            typedef void (RootItem::*_t)(const QPointF & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RootItem::signalMousePressedOffset)) {
                *result = 2;
            }
        }
        {
            typedef void (RootItem::*_t)(const QPointF & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RootItem::signalOldPoint)) {
                *result = 3;
            }
        }
        {
            typedef void (RootItem::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RootItem::signalFocusInGroup)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject RootItem::staticMetaObject = {
    { &GraphicsItemBase::staticMetaObject, qt_meta_stringdata_RootItem.data,
      qt_meta_data_RootItem,  qt_static_metacall, 0, 0}
};


const QMetaObject *RootItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RootItem::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RootItem.stringdata))
        return static_cast<void*>(const_cast< RootItem*>(this));
    return GraphicsItemBase::qt_metacast(_clname);
}

int RootItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GraphicsItemBase::qt_metacall(_c, _id, _a);
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
void RootItem::signalDeleteItem(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RootItem::signalSetHandlesChildEvents(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void RootItem::signalMousePressedOffset(const QPointF & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void RootItem::signalOldPoint(const QPointF & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void RootItem::signalFocusInGroup(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
