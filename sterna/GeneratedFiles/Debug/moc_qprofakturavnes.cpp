/****************************************************************************
** Meta object code from reading C++ file 'qprofakturavnes.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qprofakturavnes.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qprofakturavnes.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QProFakturiVnes[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x05,
      26,   16,   16,   16, 0x05,
      57,   16,   16,   16, 0x05,
      83,   16,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
     106,   16,   16,   16, 0x08,
     132,   16,   16,   16, 0x08,
     158,   16,   16,   16, 0x08,
     184,   16,   16,   16, 0x08,
     210,   16,   16,   16, 0x08,
     236,   16,   16,   16, 0x08,
     262,  260,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QProFakturiVnes[] = {
    "QProFakturiVnes\0\0closeW()\0"
    "callListOfKomintenti(QWidget*)\0"
    "scallKomintenti(QWidget*)\0"
    "scallArtikli(QWidget*)\0on_pushButton_5_clicked()\0"
    "on_pushButton_4_clicked()\0"
    "on_pushButton_6_clicked()\0"
    "on_pushButton_3_clicked()\0"
    "on_pushButton_2_clicked()\0"
    "on_pushButton_clicked()\0,\0"
    "selectionChanged(QModelIndex,QModelIndex)\0"
};

void QProFakturiVnes::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QProFakturiVnes *_t = static_cast<QProFakturiVnes *>(_o);
        switch (_id) {
        case 0: _t->closeW(); break;
        case 1: _t->callListOfKomintenti((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 2: _t->scallKomintenti((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 3: _t->scallArtikli((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 4: _t->on_pushButton_5_clicked(); break;
        case 5: _t->on_pushButton_4_clicked(); break;
        case 6: _t->on_pushButton_6_clicked(); break;
        case 7: _t->on_pushButton_3_clicked(); break;
        case 8: _t->on_pushButton_2_clicked(); break;
        case 9: _t->on_pushButton_clicked(); break;
        case 10: _t->selectionChanged((*reinterpret_cast< QModelIndex(*)>(_a[1])),(*reinterpret_cast< QModelIndex(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QProFakturiVnes::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QProFakturiVnes::staticMetaObject = {
    { &QMyBaseFormWidget::staticMetaObject, qt_meta_stringdata_QProFakturiVnes,
      qt_meta_data_QProFakturiVnes, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QProFakturiVnes::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QProFakturiVnes::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QProFakturiVnes::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QProFakturiVnes))
        return static_cast<void*>(const_cast< QProFakturiVnes*>(this));
    return QMyBaseFormWidget::qt_metacast(_clname);
}

int QProFakturiVnes::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMyBaseFormWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void QProFakturiVnes::closeW()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QProFakturiVnes::callListOfKomintenti(QWidget * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QProFakturiVnes::scallKomintenti(QWidget * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QProFakturiVnes::scallArtikli(QWidget * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
