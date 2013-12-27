/****************************************************************************
** Meta object code from reading C++ file 'AffirmForm.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../AffirmForm.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AffirmForm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AffirmForm_t {
    QByteArrayData data[5];
    char stringdata[49];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_AffirmForm_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_AffirmForm_t qt_meta_stringdata_AffirmForm = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 10),
QT_MOC_LITERAL(2, 22, 0),
QT_MOC_LITERAL(3, 23, 13),
QT_MOC_LITERAL(4, 37, 10)
    },
    "AffirmForm\0signalBack\0\0signalNotSave\0"
    "signalSave\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AffirmForm[] = {

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
       1,    0,   29,    2, 0x05,
       3,    0,   30,    2, 0x05,
       4,    0,   31,    2, 0x05,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AffirmForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AffirmForm *_t = static_cast<AffirmForm *>(_o);
        switch (_id) {
        case 0: _t->signalBack(); break;
        case 1: _t->signalNotSave(); break;
        case 2: _t->signalSave(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AffirmForm::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AffirmForm::signalBack)) {
                *result = 0;
            }
        }
        {
            typedef void (AffirmForm::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AffirmForm::signalNotSave)) {
                *result = 1;
            }
        }
        {
            typedef void (AffirmForm::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AffirmForm::signalSave)) {
                *result = 2;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject AffirmForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AffirmForm.data,
      qt_meta_data_AffirmForm,  qt_static_metacall, 0, 0}
};


const QMetaObject *AffirmForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AffirmForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AffirmForm.stringdata))
        return static_cast<void*>(const_cast< AffirmForm*>(this));
    return QWidget::qt_metacast(_clname);
}

int AffirmForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void AffirmForm::signalBack()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void AffirmForm::signalNotSave()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void AffirmForm::signalSave()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
