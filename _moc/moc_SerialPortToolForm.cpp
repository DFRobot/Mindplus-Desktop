/****************************************************************************
** Meta object code from reading C++ file 'SerialPortToolForm.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SerialPortToolForm.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SerialPortToolForm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SerialPortToolForm_t {
    QByteArrayData data[8];
    char stringdata[155];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_SerialPortToolForm_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_SerialPortToolForm_t qt_meta_stringdata_SerialPortToolForm = {
    {
QT_MOC_LITERAL(0, 0, 18),
QT_MOC_LITERAL(1, 19, 25),
QT_MOC_LITERAL(2, 45, 0),
QT_MOC_LITERAL(3, 46, 23),
QT_MOC_LITERAL(4, 70, 7),
QT_MOC_LITERAL(5, 78, 34),
QT_MOC_LITERAL(6, 113, 4),
QT_MOC_LITERAL(7, 118, 35)
    },
    "SerialPortToolForm\0on_pushButtonSend_clicked\0"
    "\0on_checkBoxMind_clicked\0checked\0"
    "on_comboBoxBaud_currentTextChanged\0"
    "arg1\0on_comboBoxPort_currentIndexChanged\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SerialPortToolForm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08,
       3,    1,   35,    2, 0x08,
       5,    1,   38,    2, 0x08,
       7,    1,   41,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,

       0        // eod
};

void SerialPortToolForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SerialPortToolForm *_t = static_cast<SerialPortToolForm *>(_o);
        switch (_id) {
        case 0: _t->on_pushButtonSend_clicked(); break;
        case 1: _t->on_checkBoxMind_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_comboBoxBaud_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_comboBoxPort_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject SerialPortToolForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SerialPortToolForm.data,
      qt_meta_data_SerialPortToolForm,  qt_static_metacall, 0, 0}
};


const QMetaObject *SerialPortToolForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SerialPortToolForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SerialPortToolForm.stringdata))
        return static_cast<void*>(const_cast< SerialPortToolForm*>(this));
    return QWidget::qt_metacast(_clname);
}

int SerialPortToolForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
