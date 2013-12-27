/****************************************************************************
** Meta object code from reading C++ file 'IntroduceForm.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../IntroduceForm.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'IntroduceForm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_IntroduceForm_t {
    QByteArrayData data[8];
    char stringdata[110];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_IntroduceForm_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_IntroduceForm_t qt_meta_stringdata_IntroduceForm = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 20),
QT_MOC_LITERAL(2, 35, 0),
QT_MOC_LITERAL(3, 36, 20),
QT_MOC_LITERAL(4, 57, 26),
QT_MOC_LITERAL(5, 84, 13),
QT_MOC_LITERAL(6, 98, 5),
QT_MOC_LITERAL(7, 104, 4)
    },
    "IntroduceForm\0signalHideSubWindows\0\0"
    "signalShowSubWindows\0on_pushButtonClose_clicked\0"
    "slotIntroduce\0image\0text\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IntroduceForm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x05,
       3,    0,   35,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       4,    0,   36,    2, 0x08,
       5,    2,   37,    2, 0x08,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPixmap, QMetaType::QString,    6,    7,

       0        // eod
};

void IntroduceForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IntroduceForm *_t = static_cast<IntroduceForm *>(_o);
        switch (_id) {
        case 0: _t->signalHideSubWindows(); break;
        case 1: _t->signalShowSubWindows(); break;
        case 2: _t->on_pushButtonClose_clicked(); break;
        case 3: _t->slotIntroduce((*reinterpret_cast< const QPixmap(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (IntroduceForm::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IntroduceForm::signalHideSubWindows)) {
                *result = 0;
            }
        }
        {
            typedef void (IntroduceForm::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IntroduceForm::signalShowSubWindows)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject IntroduceForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_IntroduceForm.data,
      qt_meta_data_IntroduceForm,  qt_static_metacall, 0, 0}
};


const QMetaObject *IntroduceForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IntroduceForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_IntroduceForm.stringdata))
        return static_cast<void*>(const_cast< IntroduceForm*>(this));
    return QWidget::qt_metacast(_clname);
}

int IntroduceForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void IntroduceForm::signalHideSubWindows()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void IntroduceForm::signalShowSubWindows()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
