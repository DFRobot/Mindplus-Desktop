/****************************************************************************
** Meta object code from reading C++ file 'MindKitForm.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MindKitForm.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MindKitForm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MindKitForm_t {
    QByteArrayData data[7];
    char stringdata[119];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MindKitForm_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MindKitForm_t qt_meta_stringdata_MindKitForm = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 30),
QT_MOC_LITERAL(2, 43, 0),
QT_MOC_LITERAL(3, 44, 18),
QT_MOC_LITERAL(4, 63, 7),
QT_MOC_LITERAL(5, 71, 27),
QT_MOC_LITERAL(6, 99, 18)
    },
    "MindKitForm\0signalMindKitPushButtonPointer\0"
    "\0MindKitPushButton*\0pointer\0"
    "on_pushButtonReturn_clicked\0"
    "slotInitPushbutton\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MindKitForm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       5,    0,   32,    2, 0x08,
       6,    0,   33,    2, 0x08,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MindKitForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MindKitForm *_t = static_cast<MindKitForm *>(_o);
        switch (_id) {
        case 0: _t->signalMindKitPushButtonPointer((*reinterpret_cast< MindKitPushButton*(*)>(_a[1]))); break;
        case 1: _t->on_pushButtonReturn_clicked(); break;
        case 2: _t->slotInitPushbutton(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
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
            typedef void (MindKitForm::*_t)(MindKitPushButton * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MindKitForm::signalMindKitPushButtonPointer)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject MindKitForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MindKitForm.data,
      qt_meta_data_MindKitForm,  qt_static_metacall, 0, 0}
};


const QMetaObject *MindKitForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MindKitForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MindKitForm.stringdata))
        return static_cast<void*>(const_cast< MindKitForm*>(this));
    return QWidget::qt_metacast(_clname);
}

int MindKitForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void MindKitForm::signalMindKitPushButtonPointer(MindKitPushButton * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
