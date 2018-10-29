/****************************************************************************
** Meta object code from reading C++ file 'qizlezniispratnicilista.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qizlezniispratnicilista.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qizlezniispratnicilista.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QIzlezniIspratniciLista[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      25,   24,   24,   24, 0x05,
      34,   24,   24,   24, 0x05,
      43,   24,   24,   24, 0x05,
      61,   52,   24,   24, 0x05,
      94,   24,   24,   24, 0x05,

 // slots: signature, parameters, type, tag, flags
     125,  111,   24,   24, 0x08,
     167,   24,   24,   24, 0x08,
     191,   24,   24,   24, 0x08,
     217,   24,   24,   24, 0x08,
     243,   24,   24,   24, 0x08,
     274,  269,   24,   24, 0x08,
     300,   24,   24,   24, 0x08,
     326,  320,   24,   24, 0x08,
     358,  320,   24,   24, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QIzlezniIspratniciLista[] = {
    "QIzlezniIspratniciLista\0\0closeW()\0"
    "procF2()\0procF3()\0listData\0"
    "sIspratniciToIzvod(QStringList&)\0"
    "callSearchForm()\0modelX,modelY\0"
    "selectionChanged(QModelIndex,QModelIndex)\0"
    "on_pushButton_clicked()\0"
    "on_pushButton_2_clicked()\0"
    "on_pushButton_3_clicked()\0"
    "on_pushButton_4_clicked()\0text\0"
    "lineEdit7Pressed(QString)\0calcSelectedItems()\0"
    "a,b,c\0procSectionResized(int,int,int)\0"
    "procSectionResized_detail(int,int,int)\0"
};

void QIzlezniIspratniciLista::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QIzlezniIspratniciLista *_t = static_cast<QIzlezniIspratniciLista *>(_o);
        switch (_id) {
        case 0: _t->closeW(); break;
        case 1: _t->procF2(); break;
        case 2: _t->procF3(); break;
        case 3: _t->sIspratniciToIzvod((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 4: _t->callSearchForm(); break;
        case 5: _t->selectionChanged((*reinterpret_cast< QModelIndex(*)>(_a[1])),(*reinterpret_cast< QModelIndex(*)>(_a[2]))); break;
        case 6: _t->on_pushButton_clicked(); break;
        case 7: _t->on_pushButton_2_clicked(); break;
        case 8: _t->on_pushButton_3_clicked(); break;
        case 9: _t->on_pushButton_4_clicked(); break;
        case 10: _t->lineEdit7Pressed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->calcSelectedItems(); break;
        case 12: _t->procSectionResized((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 13: _t->procSectionResized_detail((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QIzlezniIspratniciLista::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QIzlezniIspratniciLista::staticMetaObject = {
    { &QMyBaseFormWidget::staticMetaObject, qt_meta_stringdata_QIzlezniIspratniciLista,
      qt_meta_data_QIzlezniIspratniciLista, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QIzlezniIspratniciLista::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QIzlezniIspratniciLista::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QIzlezniIspratniciLista::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QIzlezniIspratniciLista))
        return static_cast<void*>(const_cast< QIzlezniIspratniciLista*>(this));
    return QMyBaseFormWidget::qt_metacast(_clname);
}

int QIzlezniIspratniciLista::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMyBaseFormWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void QIzlezniIspratniciLista::closeW()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QIzlezniIspratniciLista::procF2()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void QIzlezniIspratniciLista::procF3()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void QIzlezniIspratniciLista::sIspratniciToIzvod(QStringList & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QIzlezniIspratniciLista::callSearchForm()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}
QT_END_MOC_NAMESPACE
