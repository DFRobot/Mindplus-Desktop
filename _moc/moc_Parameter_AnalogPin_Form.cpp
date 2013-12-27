/****************************************************************************
** Meta object code from reading C++ file 'Parameter_AnalogPin_Form.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Parameter_AnalogPin_Form.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Parameter_AnalogPin_Form.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Parameter_AnalogPin_Form_t {
    QByteArrayData data[13];
    char stringdata[249];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Parameter_AnalogPin_Form_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Parameter_AnalogPin_Form_t qt_meta_stringdata_Parameter_AnalogPin_Form = {
    {
QT_MOC_LITERAL(0, 0, 24),
QT_MOC_LITERAL(1, 25, 11),
QT_MOC_LITERAL(2, 37, 0),
QT_MOC_LITERAL(3, 38, 5),
QT_MOC_LITERAL(4, 44, 21),
QT_MOC_LITERAL(5, 66, 14),
QT_MOC_LITERAL(6, 81, 22),
QT_MOC_LITERAL(7, 104, 22),
QT_MOC_LITERAL(8, 127, 22),
QT_MOC_LITERAL(9, 150, 22),
QT_MOC_LITERAL(10, 173, 22),
QT_MOC_LITERAL(11, 196, 22),
QT_MOC_LITERAL(12, 219, 28)
    },
    "Parameter_AnalogPin_Form\0signalValue\0"
    "\0value\0on_pushButton_clicked\0"
    "slotTextEdited\0on_AnalogPin_0_clicked\0"
    "on_AnalogPin_1_clicked\0on_AnalogPin_2_clicked\0"
    "on_AnalogPin_3_clicked\0on_AnalogPin_4_clicked\0"
    "on_AnalogPin_5_clicked\0"
    "on_pushButtonMindkit_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Parameter_AnalogPin_Form[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       4,    0,   67,    2, 0x08,
       5,    1,   68,    2, 0x08,
       6,    0,   71,    2, 0x08,
       7,    0,   72,    2, 0x08,
       8,    0,   73,    2, 0x08,
       9,    0,   74,    2, 0x08,
      10,    0,   75,    2, 0x08,
      11,    0,   76,    2, 0x08,
      12,    0,   77,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Parameter_AnalogPin_Form::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Parameter_AnalogPin_Form *_t = static_cast<Parameter_AnalogPin_Form *>(_o);
        switch (_id) {
        case 0: _t->signalValue((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->slotTextEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_AnalogPin_0_clicked(); break;
        case 4: _t->on_AnalogPin_1_clicked(); break;
        case 5: _t->on_AnalogPin_2_clicked(); break;
        case 6: _t->on_AnalogPin_3_clicked(); break;
        case 7: _t->on_AnalogPin_4_clicked(); break;
        case 8: _t->on_AnalogPin_5_clicked(); break;
        case 9: _t->on_pushButtonMindkit_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Parameter_AnalogPin_Form::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Parameter_AnalogPin_Form::signalValue)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject Parameter_AnalogPin_Form::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Parameter_AnalogPin_Form.data,
      qt_meta_data_Parameter_AnalogPin_Form,  qt_static_metacall, 0, 0}
};


const QMetaObject *Parameter_AnalogPin_Form::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Parameter_AnalogPin_Form::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Parameter_AnalogPin_Form.stringdata))
        return static_cast<void*>(const_cast< Parameter_AnalogPin_Form*>(this));
    return QWidget::qt_metacast(_clname);
}

int Parameter_AnalogPin_Form::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Parameter_AnalogPin_Form::signalValue(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
