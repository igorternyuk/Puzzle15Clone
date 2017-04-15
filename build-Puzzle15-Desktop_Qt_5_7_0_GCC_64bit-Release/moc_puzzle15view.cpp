/****************************************************************************
** Meta object code from reading C++ file 'puzzle15view.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Puzzle15/puzzle15view.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'puzzle15view.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Puzzle15View_t {
    QByteArrayData data[13];
    char stringdata0[137];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Puzzle15View_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Puzzle15View_t qt_meta_stringdata_Puzzle15View = {
    {
QT_MOC_LITERAL(0, 0, 12), // "Puzzle15View"
QT_MOC_LITERAL(1, 13, 4), // "init"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 9), // "isPicture"
QT_MOC_LITERAL(4, 29, 8), // "QPixmap*"
QT_MOC_LITERAL(5, 38, 7), // "picture"
QT_MOC_LITERAL(6, 46, 10), // "complexity"
QT_MOC_LITERAL(7, 57, 6), // "update"
QT_MOC_LITERAL(8, 64, 17), // "showInfoAboutGame"
QT_MOC_LITERAL(9, 82, 19), // "showInfoAboutAuthor"
QT_MOC_LITERAL(10, 102, 8), // "showHelp"
QT_MOC_LITERAL(11, 111, 15), // "fillGridByCells"
QT_MOC_LITERAL(12, 127, 9) // "tryToMove"

    },
    "Puzzle15View\0init\0\0isPicture\0QPixmap*\0"
    "picture\0complexity\0update\0showInfoAboutGame\0"
    "showInfoAboutAuthor\0showHelp\0"
    "fillGridByCells\0tryToMove"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Puzzle15View[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   49,    2, 0x0a /* Public */,
       7,    0,   56,    2, 0x0a /* Public */,
       8,    0,   57,    2, 0x0a /* Public */,
       9,    0,   58,    2, 0x0a /* Public */,
      10,    0,   59,    2, 0x0a /* Public */,
      11,    0,   60,    2, 0x08 /* Private */,
      12,    0,   61,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 4, QMetaType::Int,    3,    5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Puzzle15View::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Puzzle15View *_t = static_cast<Puzzle15View *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->init((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QPixmap*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->update(); break;
        case 2: _t->showInfoAboutGame(); break;
        case 3: _t->showInfoAboutAuthor(); break;
        case 4: _t->showHelp(); break;
        case 5: _t->fillGridByCells(); break;
        case 6: _t->tryToMove(); break;
        default: ;
        }
    }
}

const QMetaObject Puzzle15View::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Puzzle15View.data,
      qt_meta_data_Puzzle15View,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Puzzle15View::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Puzzle15View::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Puzzle15View.stringdata0))
        return static_cast<void*>(const_cast< Puzzle15View*>(this));
    return QWidget::qt_metacast(_clname);
}

int Puzzle15View::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
