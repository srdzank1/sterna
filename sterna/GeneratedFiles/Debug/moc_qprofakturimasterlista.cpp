/****************************************************************************
** Meta object code from reading C++ file 'qprofakturimasterlista.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qprofakturimasterlista.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qprofakturimasterlista.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QIzlezniprofakturimasterLista[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      31,   30,   30,   30, 0x05,
      40,   30,   30,   30, 0x05,
      49,   30,   30,   30, 0x05,
      67,   58,   30,   30, 0x05,

 // slots: signature, parameters, type, tag, flags
     120,  106,   30,   30, 0x08,
     162,   30,   30,   30, 0x08,
     186,   30,   30,   30, 0x08,
     217,  212,   30,   30, 0x08,
     243,   30,   30,   30, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QIzlezniprofakturimasterLista[] = {
    "QIzlezniprofakturimasterLista\0\0closeW()\0"
    "procF2()\0procF3()\0listData\0"
    "sprofakturimasterToIzvod(QStringList&)\0"
    "modelX,modelY\0selectionChanged(QModelIndex,QModelIndex)\0"
    "on_pushButton_clicked()\0"
    "on_pushButton_2_clicked()\0text\0"
    "lineEdit7Pressed(QString)\0calcSelectedItems()\0"
};

void QIzlezniprofakturimasterLista::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QIzlezniprofakturimasterLista *_t = static_cast<QIzlezniprofakturimasterLista *>(_o);
        switch (_id) {
        case 0: _t->closeW(); break;
        case 1: _t->procF2(); break;
        case 2: _t->procF3(); break;
        case 3: _t->sprofakturimasterToIzvod((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 4: _t->selectionChanged((*reinterpret_cast< QModelIndex(*)>(_a[1])),(*reinterpret_cast< QModelIndex(*)>(_a[2]))); break;
        case 5: _t->on_pushButton_clicked(); break;
        case 6: _t->on_pushButton_2_clicked(); break;
        case 7: _t->lineEdit7Pressed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->calcSelectedItems(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QIzlezniprofakturimasterLista::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QIzlezniprofakturimasterLista::staticMetaObject = {
    { &QMyBaseFormWidget::staticMetaObject, qt_meta_stringdata_QIzlezniprofakturimasterLista,
      qt_meta_data_QIzlezniprofakturimasterLista, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QIzlezniprofakturimasterLista::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QIzlezniprofakturimasterLista::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QIzlezniprofakturimasterLista::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QIzlezniprofakturimasterLista))
        return static_cast<void*>(const_cast< QIzlezniprofakturimasterLista*>(this));
    return QMyBaseFormWidget::qt_metacast(_clname);
}

int QIzlezniprofakturimasterLista::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMyBaseFormWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void QIzlezniprofakturimasterLista::closeW()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QIzlezniprofakturimasterLista::procF2()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void QIzlezniprofakturimasterLista::procF3()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void QIzlezniprofakturimasterLista::sprofakturimasterToIzvod(QStringList & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
