/****************************************************************************
** Meta object code from reading C++ file 'UploadSettingForm.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../UploadSettingForm.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UploadSettingForm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_UploadSettingForm_t {
    QByteArrayData data[17];
    char stringdata[284];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_UploadSettingForm_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_UploadSettingForm_t qt_meta_stringdata_UploadSettingForm = {
    {
QT_MOC_LITERAL(0, 0, 17),
QT_MOC_LITERAL(1, 18, 21),
QT_MOC_LITERAL(2, 40, 0),
QT_MOC_LITERAL(3, 41, 9),
QT_MOC_LITERAL(4, 51, 10),
QT_MOC_LITERAL(5, 62, 17),
QT_MOC_LITERAL(6, 80, 5),
QT_MOC_LITERAL(7, 86, 18),
QT_MOC_LITERAL(8, 105, 10),
QT_MOC_LITERAL(9, 116, 10),
QT_MOC_LITERAL(10, 127, 27),
QT_MOC_LITERAL(11, 155, 25),
QT_MOC_LITERAL(12, 181, 18),
QT_MOC_LITERAL(13, 200, 3),
QT_MOC_LITERAL(14, 204, 23),
QT_MOC_LITERAL(15, 228, 24),
QT_MOC_LITERAL(16, 253, 29)
    },
    "UploadSettingForm\0signalSelectBoardType\0"
    "\0boardName\0boardIndex\0signalSelectBoard\0"
    "board\0signalSelectSerial\0serialName\0"
    "signalDone\0on_pushButtonUpload_clicked\0"
    "on_pushButtonBack_clicked\0slotBoardActivated\0"
    "str\0slotSerialPortActivated\0"
    "on_pushButtonUno_clicked\0"
    "on_pushButtonLeonardo_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UploadSettingForm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   64,    2, 0x05,
       5,    1,   69,    2, 0x05,
       7,    1,   72,    2, 0x05,
       9,    0,   75,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
      10,    0,   76,    2, 0x08,
      11,    0,   77,    2, 0x08,
      12,    1,   78,    2, 0x08,
      14,    1,   81,    2, 0x08,
      15,    0,   84,    2, 0x08,
      16,    0,   85,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void UploadSettingForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UploadSettingForm *_t = static_cast<UploadSettingForm *>(_o);
        switch (_id) {
        case 0: _t->signalSelectBoardType((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->signalSelectBoard((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->signalSelectSerial((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->signalDone(); break;
        case 4: _t->on_pushButtonUpload_clicked(); break;
        case 5: _t->on_pushButtonBack_clicked(); break;
        case 6: _t->slotBoardActivated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->slotSerialPortActivated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->on_pushButtonUno_clicked(); break;
        case 9: _t->on_pushButtonLeonardo_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (UploadSettingForm::*_t)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UploadSettingForm::signalSelectBoardType)) {
                *result = 0;
            }
        }
        {
            typedef void (UploadSettingForm::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UploadSettingForm::signalSelectBoard)) {
                *result = 1;
            }
        }
        {
            typedef void (UploadSettingForm::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UploadSettingForm::signalSelectSerial)) {
                *result = 2;
            }
        }
        {
            typedef void (UploadSettingForm::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UploadSettingForm::signalDone)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject UploadSettingForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_UploadSettingForm.data,
      qt_meta_data_UploadSettingForm,  qt_static_metacall, 0, 0}
};


const QMetaObject *UploadSettingForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UploadSettingForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_UploadSettingForm.stringdata))
        return static_cast<void*>(const_cast< UploadSettingForm*>(this));
    return QWidget::qt_metacast(_clname);
}

int UploadSettingForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void UploadSettingForm::signalSelectBoardType(const QString & _t1, const QString & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void UploadSettingForm::signalSelectBoard(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void UploadSettingForm::signalSelectSerial(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void UploadSettingForm::signalDone()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
