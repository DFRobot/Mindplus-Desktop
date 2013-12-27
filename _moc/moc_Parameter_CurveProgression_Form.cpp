/****************************************************************************
** Meta object code from reading C++ file 'Parameter_CurveProgression_Form.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Parameter_CurveProgression_Form.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Parameter_CurveProgression_Form.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Parameter_CurveProgression_Form_t {
    QByteArrayData data[12];
    char stringdata[214];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Parameter_CurveProgression_Form_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Parameter_CurveProgression_Form_t qt_meta_stringdata_Parameter_CurveProgression_Form = {
    {
QT_MOC_LITERAL(0, 0, 31),
QT_MOC_LITERAL(1, 32, 11),
QT_MOC_LITERAL(2, 44, 0),
QT_MOC_LITERAL(3, 45, 5),
QT_MOC_LITERAL(4, 51, 17),
QT_MOC_LITERAL(5, 69, 20),
QT_MOC_LITERAL(6, 90, 21),
QT_MOC_LITERAL(7, 112, 27),
QT_MOC_LITERAL(8, 140, 4),
QT_MOC_LITERAL(9, 145, 27),
QT_MOC_LITERAL(10, 173, 18),
QT_MOC_LITERAL(11, 192, 20)
    },
    "Parameter_CurveProgression_Form\0"
    "signalValue\0\0value\0signalValueChange\0"
    "signalPressCtrlPoint\0on_pushButton_clicked\0"
    "on_currentPosX_valueChanged\0arg1\0"
    "on_currentPosY_valueChanged\0"
    "slotPressCtrlPoint\0slotReleaseCtrlPoint\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Parameter_CurveProgression_Form[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x05,
       4,    1,   57,    2, 0x05,
       5,    0,   60,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       6,    0,   61,    2, 0x08,
       7,    1,   62,    2, 0x08,
       9,    1,   65,    2, 0x08,
      10,    0,   68,    2, 0x08,
      11,    0,   69,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    8,
    QMetaType::Void, QMetaType::Double,    8,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Parameter_CurveProgression_Form::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Parameter_CurveProgression_Form *_t = static_cast<Parameter_CurveProgression_Form *>(_o);
        switch (_id) {
        case 0: _t->signalValue((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->signalValueChange((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->signalPressCtrlPoint(); break;
        case 3: _t->on_pushButton_clicked(); break;
        case 4: _t->on_currentPosX_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->on_currentPosY_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->slotPressCtrlPoint(); break;
        case 7: _t->slotReleaseCtrlPoint(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Parameter_CurveProgression_Form::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Parameter_CurveProgression_Form::signalValue)) {
                *result = 0;
            }
        }
        {
            typedef void (Parameter_CurveProgression_Form::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Parameter_CurveProgression_Form::signalValueChange)) {
                *result = 1;
            }
        }
        {
            typedef void (Parameter_CurveProgression_Form::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Parameter_CurveProgression_Form::signalPressCtrlPoint)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject Parameter_CurveProgression_Form::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Parameter_CurveProgression_Form.data,
      qt_meta_data_Parameter_CurveProgression_Form,  qt_static_metacall, 0, 0}
};


const QMetaObject *Parameter_CurveProgression_Form::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Parameter_CurveProgression_Form::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Parameter_CurveProgression_Form.stringdata))
        return static_cast<void*>(const_cast< Parameter_CurveProgression_Form*>(this));
    return QWidget::qt_metacast(_clname);
}

int Parameter_CurveProgression_Form::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Parameter_CurveProgression_Form::signalValue(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Parameter_CurveProgression_Form::signalValueChange(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Parameter_CurveProgression_Form::signalPressCtrlPoint()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
