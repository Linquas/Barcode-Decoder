/****************************************************************************
** Meta object code from reading C++ file 'process.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "process.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'process.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Process_t {
    QByteArrayData data[11];
    char stringdata[113];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Process_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Process_t qt_meta_stringdata_Process = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 7),
QT_MOC_LITERAL(2, 16, 0),
QT_MOC_LITERAL(3, 17, 8),
QT_MOC_LITERAL(4, 26, 14),
QT_MOC_LITERAL(5, 41, 14),
QT_MOC_LITERAL(6, 56, 7),
QT_MOC_LITERAL(7, 64, 11),
QT_MOC_LITERAL(8, 76, 16),
QT_MOC_LITERAL(9, 93, 6),
QT_MOC_LITERAL(10, 100, 12)
    },
    "Process\0sendLoc\0\0cv::Rect\0sendIsBarcaode\0"
    "sendBarcodeImg\0cv::Mat\0sendBarcode\0"
    "getImgAndProcess\0getLoc\0getIsBarcode"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Process[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    1,   52,    2, 0x06 /* Public */,
       5,    1,   55,    2, 0x06 /* Public */,
       7,    1,   58,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   61,    2, 0x0a /* Public */,
       9,    1,   64,    2, 0x0a /* Public */,
      10,    1,   67,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void Process::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Process *_t = static_cast<Process *>(_o);
        switch (_id) {
        case 0: _t->sendLoc((*reinterpret_cast< cv::Rect(*)>(_a[1]))); break;
        case 1: _t->sendIsBarcaode((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->sendBarcodeImg((*reinterpret_cast< cv::Mat(*)>(_a[1]))); break;
        case 3: _t->sendBarcode((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->getImgAndProcess((*reinterpret_cast< cv::Mat(*)>(_a[1]))); break;
        case 5: _t->getLoc((*reinterpret_cast< cv::Rect(*)>(_a[1]))); break;
        case 6: _t->getIsBarcode((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Process::*_t)(cv::Rect );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Process::sendLoc)) {
                *result = 0;
            }
        }
        {
            typedef void (Process::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Process::sendIsBarcaode)) {
                *result = 1;
            }
        }
        {
            typedef void (Process::*_t)(cv::Mat );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Process::sendBarcodeImg)) {
                *result = 2;
            }
        }
        {
            typedef void (Process::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Process::sendBarcode)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject Process::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Process.data,
      qt_meta_data_Process,  qt_static_metacall, 0, 0}
};


const QMetaObject *Process::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Process::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Process.stringdata))
        return static_cast<void*>(const_cast< Process*>(this));
    return QObject::qt_metacast(_clname);
}

int Process::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Process::sendLoc(cv::Rect _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Process::sendIsBarcaode(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Process::sendBarcodeImg(cv::Mat _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Process::sendBarcode(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
