/****************************************************************************
** Meta object code from reading C++ file 'UploadWaitForm.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../UploadWaitForm.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UploadWaitForm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_UploadWaitForm_t {
    QByteArrayData data[13];
    char stringdata[184];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_UploadWaitForm_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_UploadWaitForm_t qt_meta_stringdata_UploadWaitForm = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 12),
QT_MOC_LITERAL(2, 28, 0),
QT_MOC_LITERAL(3, 29, 23),
QT_MOC_LITERAL(4, 53, 5),
QT_MOC_LITERAL(5, 59, 13),
QT_MOC_LITERAL(6, 73, 14),
QT_MOC_LITERAL(7, 88, 14),
QT_MOC_LITERAL(8, 103, 27),
QT_MOC_LITERAL(9, 131, 19),
QT_MOC_LITERAL(10, 151, 8),
QT_MOC_LITERAL(11, 160, 3),
QT_MOC_LITERAL(12, 164, 18)
    },
    "UploadWaitForm\0signalCancel\0\0"
    "SlotTypeConversionError\0error\0"
    "SlotPortError\0SlotBoardError\0"
    "SlotCompileEnd\0on_pushButtonCancel_clicked\0"
    "slotAdvanceProgress\0progress\0sec\0"
    "slotRemoveTempFile\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UploadWaitForm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       3,    1,   55,    2, 0x0a,
       5,    1,   58,    2, 0x0a,
       6,    1,   61,    2, 0x0a,
       7,    0,   64,    2, 0x0a,
       8,    0,   65,    2, 0x08,
       9,    2,   66,    2, 0x08,
      12,    0,   71,    2, 0x08,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float, QMetaType::Int,   10,   11,
    QMetaType::Void,

       0        // eod
};

void UploadWaitForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UploadWaitForm *_t = static_cast<UploadWaitForm *>(_o);
        switch (_id) {
        case 0: _t->signalCancel(); break;
        case 1: _t->SlotTypeConversionError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->SlotPortError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->SlotBoardError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->SlotCompileEnd(); break;
        case 5: _t->on_pushButtonCancel_clicked(); break;
        case 6: _t->slotAdvanceProgress((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->slotRemoveTempFile(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (UploadWaitForm::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UploadWaitForm::signalCancel)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject UploadWaitForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_UploadWaitForm.data,
      qt_meta_data_UploadWaitForm,  qt_static_metacall, 0, 0}
};


const QMetaObject *UploadWaitForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UploadWaitForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_UploadWaitForm.stringdata))
        return static_cast<void*>(const_cast< UploadWaitForm*>(this));
    return QWidget::qt_metacast(_clname);
}

int UploadWaitForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void UploadWaitForm::signalCancel()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
