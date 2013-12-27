/****************************************************************************
** Meta object code from reading C++ file 'FunctionArea.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../FunctionArea.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FunctionArea.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FunctionArea_t {
    QByteArrayData data[6];
    char stringdata[87];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_FunctionArea_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_FunctionArea_t qt_meta_stringdata_FunctionArea = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 21),
QT_MOC_LITERAL(2, 35, 0),
QT_MOC_LITERAL(3, 36, 17),
QT_MOC_LITERAL(4, 54, 15),
QT_MOC_LITERAL(5, 70, 15)
    },
    "FunctionArea\0signalNewProjectClick\0\0"
    "signalUploadClick\0signalSaveClick\0"
    "signalOpenClick\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FunctionArea[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x05,
       3,    0,   35,    2, 0x05,
       4,    0,   36,    2, 0x05,
       5,    0,   37,    2, 0x05,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FunctionArea::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FunctionArea *_t = static_cast<FunctionArea *>(_o);
        switch (_id) {
        case 0: _t->signalNewProjectClick(); break;
        case 1: _t->signalUploadClick(); break;
        case 2: _t->signalSaveClick(); break;
        case 3: _t->signalOpenClick(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (FunctionArea::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FunctionArea::signalNewProjectClick)) {
                *result = 0;
            }
        }
        {
            typedef void (FunctionArea::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FunctionArea::signalUploadClick)) {
                *result = 1;
            }
        }
        {
            typedef void (FunctionArea::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FunctionArea::signalSaveClick)) {
                *result = 2;
            }
        }
        {
            typedef void (FunctionArea::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FunctionArea::signalOpenClick)) {
                *result = 3;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject FunctionArea::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_FunctionArea.data,
      qt_meta_data_FunctionArea,  qt_static_metacall, 0, 0}
};


const QMetaObject *FunctionArea::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FunctionArea::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FunctionArea.stringdata))
        return static_cast<void*>(const_cast< FunctionArea*>(this));
    return QWidget::qt_metacast(_clname);
}

int FunctionArea::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void FunctionArea::signalNewProjectClick()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void FunctionArea::signalUploadClick()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void FunctionArea::signalSaveClick()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void FunctionArea::signalOpenClick()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
