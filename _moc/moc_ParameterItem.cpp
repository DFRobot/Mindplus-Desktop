/****************************************************************************
** Meta object code from reading C++ file 'ParameterItem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GraphicFramework/Item/ParameterItem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ParameterItem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ParameterItem_t {
    QByteArrayData data[8];
    char stringdata[85];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ParameterItem_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ParameterItem_t qt_meta_stringdata_ParameterItem = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 22),
QT_MOC_LITERAL(2, 37, 0),
QT_MOC_LITERAL(3, 38, 4),
QT_MOC_LITERAL(4, 43, 8),
QT_MOC_LITERAL(5, 52, 9),
QT_MOC_LITERAL(6, 62, 15),
QT_MOC_LITERAL(7, 78, 5)
    },
    "ParameterItem\0signalParamValueChange\0"
    "\0type\0newValue\0paramName\0slotValueChange\0"
    "value\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ParameterItem[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   24,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       6,    1,   31,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    7,

       0        // eod
};

void ParameterItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ParameterItem *_t = static_cast<ParameterItem *>(_o);
        switch (_id) {
        case 0: _t->signalParamValueChange((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 1: _t->slotValueChange((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ParameterItem::*_t)(const QString & , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ParameterItem::signalParamValueChange)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject ParameterItem::staticMetaObject = {
    { &GraphicsItemBase::staticMetaObject, qt_meta_stringdata_ParameterItem.data,
      qt_meta_data_ParameterItem,  qt_static_metacall, 0, 0}
};


const QMetaObject *ParameterItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ParameterItem::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ParameterItem.stringdata))
        return static_cast<void*>(const_cast< ParameterItem*>(this));
    return GraphicsItemBase::qt_metacast(_clname);
}

int ParameterItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GraphicsItemBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ParameterItem::signalParamValueChange(const QString & _t1, const QString & _t2, const QString & _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
