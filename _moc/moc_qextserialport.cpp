/****************************************************************************
** Meta object code from reading C++ file 'qextserialport.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../QExtserialport/qextserialport.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qextserialport.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QextSerialPort_t {
    QByteArrayData data[30];
    char stringdata[300];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_QextSerialPort_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_QextSerialPort_t qt_meta_stringdata_QextSerialPort = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 10),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 6),
QT_MOC_LITERAL(4, 34, 11),
QT_MOC_LITERAL(5, 46, 4),
QT_MOC_LITERAL(6, 51, 12),
QT_MOC_LITERAL(7, 64, 9),
QT_MOC_LITERAL(8, 74, 4),
QT_MOC_LITERAL(9, 79, 11),
QT_MOC_LITERAL(10, 91, 12),
QT_MOC_LITERAL(11, 104, 11),
QT_MOC_LITERAL(12, 116, 12),
QT_MOC_LITERAL(13, 129, 9),
QT_MOC_LITERAL(14, 139, 10),
QT_MOC_LITERAL(15, 150, 11),
QT_MOC_LITERAL(16, 162, 12),
QT_MOC_LITERAL(17, 175, 14),
QT_MOC_LITERAL(18, 190, 8),
QT_MOC_LITERAL(19, 199, 10),
QT_MOC_LITERAL(20, 210, 6),
QT_MOC_LITERAL(21, 217, 3),
QT_MOC_LITERAL(22, 221, 6),
QT_MOC_LITERAL(23, 228, 13),
QT_MOC_LITERAL(24, 242, 6),
QT_MOC_LITERAL(25, 249, 10),
QT_MOC_LITERAL(26, 260, 8),
QT_MOC_LITERAL(27, 269, 9),
QT_MOC_LITERAL(28, 279, 7),
QT_MOC_LITERAL(29, 287, 11)
    },
    "QextSerialPort\0dsrChanged\0\0status\0"
    "setPortName\0name\0setQueryMode\0QueryMode\0"
    "mode\0setBaudRate\0BaudRateType\0setDataBits\0"
    "DataBitsType\0setParity\0ParityType\0"
    "setStopBits\0StopBitsType\0setFlowControl\0"
    "FlowType\0setTimeout\0setDtr\0set\0setRts\0"
    "_q_onWinEvent\0HANDLE\0_q_canRead\0"
    "portName\0queryMode\0Polling\0EventDriven\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QextSerialPort[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       2,  128, // properties
       1,  134, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       4,    1,   92,    2, 0x0a,
       6,    1,   95,    2, 0x0a,
       9,    1,   98,    2, 0x0a,
      11,    1,  101,    2, 0x0a,
      13,    1,  104,    2, 0x0a,
      15,    1,  107,    2, 0x0a,
      17,    1,  110,    2, 0x0a,
      19,    1,  113,    2, 0x0a,
      20,    1,  116,    2, 0x0a,
      20,    0,  119,    2, 0x2a,
      22,    1,  120,    2, 0x0a,
      22,    0,  123,    2, 0x2a,
      23,    1,  124,    2, 0x08,
      25,    0,  127,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 10,    2,
    QMetaType::Void, 0x80000000 | 12,    2,
    QMetaType::Void, 0x80000000 | 14,    2,
    QMetaType::Void, 0x80000000 | 16,    2,
    QMetaType::Void, 0x80000000 | 18,    2,
    QMetaType::Void, QMetaType::Long,    2,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 24,    2,
    QMetaType::Void,

 // properties: name, type, flags
      26, QMetaType::QString, 0x00095103,
      27, 0x80000000 | 7, 0x0009510b,

 // enums: name, flags, count, data
       7, 0x0,    2,  138,

 // enum data: key, value
      28, uint(QextSerialPort::Polling),
      29, uint(QextSerialPort::EventDriven),

       0        // eod
};

void QextSerialPort::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QextSerialPort *_t = static_cast<QextSerialPort *>(_o);
        switch (_id) {
        case 0: _t->dsrChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->setPortName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->setQueryMode((*reinterpret_cast< QueryMode(*)>(_a[1]))); break;
        case 3: _t->setBaudRate((*reinterpret_cast< BaudRateType(*)>(_a[1]))); break;
        case 4: _t->setDataBits((*reinterpret_cast< DataBitsType(*)>(_a[1]))); break;
        case 5: _t->setParity((*reinterpret_cast< ParityType(*)>(_a[1]))); break;
        case 6: _t->setStopBits((*reinterpret_cast< StopBitsType(*)>(_a[1]))); break;
        case 7: _t->setFlowControl((*reinterpret_cast< FlowType(*)>(_a[1]))); break;
        case 8: _t->setTimeout((*reinterpret_cast< long(*)>(_a[1]))); break;
        case 9: _t->setDtr((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->setDtr(); break;
        case 11: _t->setRts((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->setRts(); break;
        case 13: _t->d_func()->_q_onWinEvent((*reinterpret_cast< HANDLE(*)>(_a[1]))); break;
        case 14: _t->d_func()->_q_canRead(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QextSerialPort::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QextSerialPort::dsrChanged)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject QextSerialPort::staticMetaObject = {
    { &QIODevice::staticMetaObject, qt_meta_stringdata_QextSerialPort.data,
      qt_meta_data_QextSerialPort,  qt_static_metacall, 0, 0}
};


const QMetaObject *QextSerialPort::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QextSerialPort::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QextSerialPort.stringdata))
        return static_cast<void*>(const_cast< QextSerialPort*>(this));
    return QIODevice::qt_metacast(_clname);
}

int QextSerialPort::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QIODevice::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = portName(); break;
        case 1: *reinterpret_cast< QueryMode*>(_v) = queryMode(); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setPortName(*reinterpret_cast< QString*>(_v)); break;
        case 1: setQueryMode(*reinterpret_cast< QueryMode*>(_v)); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QextSerialPort::dsrChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
