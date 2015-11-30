/****************************************************************************
** Meta object code from reading C++ file 'display.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "display.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'display.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Display_t {
    QByteArrayData data[10];
    char stringdata[116];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Display_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Display_t qt_meta_stringdata_Display = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 7),
QT_MOC_LITERAL(2, 16, 0),
QT_MOC_LITERAL(3, 17, 7),
QT_MOC_LITERAL(4, 25, 12),
QT_MOC_LITERAL(5, 38, 22),
QT_MOC_LITERAL(6, 61, 8),
QT_MOC_LITERAL(7, 70, 20),
QT_MOC_LITERAL(8, 91, 11),
QT_MOC_LITERAL(9, 103, 12)
    },
    "Display\0loadImg\0\0cv::Mat\0updateScreen\0"
    "slotGetBarcodeLocation\0cv::Rect\0"
    "slotIsBarcodeLocated\0cleanScrean\0"
    "startDisplay"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Display[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x0a /* Public */,
       4,    0,   47,    2, 0x0a /* Public */,
       5,    1,   48,    2, 0x0a /* Public */,
       7,    1,   51,    2, 0x0a /* Public */,
       8,    0,   54,    2, 0x0a /* Public */,
       9,    0,   55,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Display::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Display *_t = static_cast<Display *>(_o);
        switch (_id) {
        case 0: _t->loadImg((*reinterpret_cast< cv::Mat(*)>(_a[1]))); break;
        case 1: _t->updateScreen(); break;
        case 2: _t->slotGetBarcodeLocation((*reinterpret_cast< cv::Rect(*)>(_a[1]))); break;
        case 3: _t->slotIsBarcodeLocated((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->cleanScrean(); break;
        case 5: _t->startDisplay(); break;
        default: ;
        }
    }
}

const QMetaObject Display::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_Display.data,
      qt_meta_data_Display,  qt_static_metacall, 0, 0}
};


const QMetaObject *Display::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Display::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Display.stringdata))
        return static_cast<void*>(const_cast< Display*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int Display::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
