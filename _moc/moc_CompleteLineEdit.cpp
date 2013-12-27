/****************************************************************************
** Meta object code from reading C++ file 'CompleteLineEdit.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CompleteLineEdit.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CompleteLineEdit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CompleteLineEdit_t {
    QByteArrayData data[9];
    char stringdata[107];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_CompleteLineEdit_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_CompleteLineEdit_t qt_meta_stringdata_CompleteLineEdit = {
    {
QT_MOC_LITERAL(0, 0, 16),
QT_MOC_LITERAL(1, 17, 16),
QT_MOC_LITERAL(2, 34, 0),
QT_MOC_LITERAL(3, 35, 4),
QT_MOC_LITERAL(4, 40, 9),
QT_MOC_LITERAL(5, 50, 22),
QT_MOC_LITERAL(6, 73, 9),
QT_MOC_LITERAL(7, 83, 16),
QT_MOC_LITERAL(8, 100, 5)
    },
    "CompleteLineEdit\0signalSelectItem\0\0"
    "name\0signalEsc\0slotCompleterInputText\0"
    "inputText\0slotCompleteText\0index\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CompleteLineEdit[] = {

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
       1,    1,   34,    2, 0x05,
       4,    0,   37,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       5,    1,   38,    2, 0x0a,
       7,    1,   41,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QModelIndex,    8,

       0        // eod
};

void CompleteLineEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CompleteLineEdit *_t = static_cast<CompleteLineEdit *>(_o);
        switch (_id) {
        case 0: _t->signalSelectItem((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->signalEsc(); break;
        case 2: _t->slotCompleterInputText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->slotCompleteText((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CompleteLineEdit::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CompleteLineEdit::signalSelectItem)) {
                *result = 0;
            }
        }
        {
            typedef void (CompleteLineEdit::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CompleteLineEdit::signalEsc)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject CompleteLineEdit::staticMetaObject = {
    { &QLineEdit::staticMetaObject, qt_meta_stringdata_CompleteLineEdit.data,
      qt_meta_data_CompleteLineEdit,  qt_static_metacall, 0, 0}
};


const QMetaObject *CompleteLineEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CompleteLineEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CompleteLineEdit.stringdata))
        return static_cast<void*>(const_cast< CompleteLineEdit*>(this));
    return QLineEdit::qt_metacast(_clname);
}

int CompleteLineEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLineEdit::qt_metacall(_c, _id, _a);
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
void CompleteLineEdit::signalSelectItem(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CompleteLineEdit::signalEsc()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
