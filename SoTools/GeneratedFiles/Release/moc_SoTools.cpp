/****************************************************************************
** Meta object code from reading C++ file 'SoTools.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SoTools.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SoTools.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SoTools_t {
    QByteArrayData data[11];
    char stringdata0[98];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SoTools_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SoTools_t qt_meta_stringdata_SoTools = {
    {
QT_MOC_LITERAL(0, 0, 7), // "SoTools"
QT_MOC_LITERAL(1, 8, 7), // "sigTodo"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 8), // "sendData"
QT_MOC_LITERAL(4, 26, 5), // "char*"
QT_MOC_LITERAL(5, 32, 11), // "Elf32_Shdr*"
QT_MOC_LITERAL(6, 44, 8), // "openFile"
QT_MOC_LITERAL(7, 53, 16), // "phTableClickItem"
QT_MOC_LITERAL(8, 70, 16), // "shTableClickItem"
QT_MOC_LITERAL(9, 87, 3), // "row"
QT_MOC_LITERAL(10, 91, 6) // "column"

    },
    "SoTools\0sigTodo\0\0sendData\0char*\0"
    "Elf32_Shdr*\0openFile\0phTableClickItem\0"
    "shTableClickItem\0row\0column"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SoTools[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       3,    3,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   49,    2, 0x08 /* Private */,
       7,    2,   50,    2, 0x08 /* Private */,
       8,    2,   55,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 4, QMetaType::QString, 0x80000000 | 5,    2,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    9,   10,

       0        // eod
};

void SoTools::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SoTools *_t = static_cast<SoTools *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigTodo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->sendData((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< Elf32_Shdr*(*)>(_a[3]))); break;
        case 2: _t->openFile(); break;
        case 3: _t->phTableClickItem((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->shTableClickItem((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SoTools::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SoTools::sigTodo)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (SoTools::*_t)(char * , QString , Elf32_Shdr * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SoTools::sendData)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject SoTools::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_SoTools.data,
      qt_meta_data_SoTools,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SoTools::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SoTools::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SoTools.stringdata0))
        return static_cast<void*>(const_cast< SoTools*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int SoTools::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void SoTools::sigTodo(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SoTools::sendData(char * _t1, QString _t2, Elf32_Shdr * _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
