/****************************************************************************
** Meta object code from reading C++ file 'MindKitPushButton.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MindKitPushButton.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MindKitPushButton.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MindKitPushButton_t {
    QByteArrayData data[6];
    char stringdata[96];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MindKitPushButton_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MindKitPushButton_t qt_meta_stringdata_MindKitPushButton = {
    {
QT_MOC_LITERAL(0, 0, 17),
QT_MOC_LITERAL(1, 18, 17),
QT_MOC_LITERAL(2, 36, 0),
QT_MOC_LITERAL(3, 37, 30),
QT_MOC_LITERAL(4, 68, 18),
QT_MOC_LITERAL(5, 87, 7)
    },
    "MindKitPushButton\0signalHideMindKit\0"
    "\0signalMindKitPushButtonPointer\0"
    "MindKitPushButton*\0pointer\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MindKitPushButton[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x05,
       3,    1,   25,    2, 0x05,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,

       0        // eod
};

void MindKitPushButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MindKitPushButton *_t = static_cast<MindKitPushButton *>(_o);
        switch (_id) {
        case 0: _t->signalHideMindKit(); break;
        case 1: _t->signalMindKitPushButtonPointer((*reinterpret_cast< MindKitPushButton*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MindKitPushButton* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MindKitPushButton::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MindKitPushButton::signalHideMindKit)) {
                *result = 0;
            }
        }
        {
            typedef void (MindKitPushButton::*_t)(MindKitPushButton * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MindKitPushButton::signalMindKitPushButtonPointer)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject MindKitPushButton::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_MindKitPushButton.data,
      qt_meta_data_MindKitPushButton,  qt_static_metacall, 0, 0}
};


const QMetaObject *MindKitPushButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MindKitPushButton::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MindKitPushButton.stringdata))
        return static_cast<void*>(const_cast< MindKitPushButton*>(this));
    return QPushButton::qt_metacast(_clname);
}

int MindKitPushButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void MindKitPushButton::signalHideMindKit()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MindKitPushButton::signalMindKitPushButtonPointer(MindKitPushButton * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
