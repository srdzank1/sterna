/****************************************************************************
** Meta object code from reading C++ file 'qizleznifaktmasterlista.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qizleznifaktmasterlista.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qizleznifaktmasterlista.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QIzleznifaktmasterLista[] = {

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
      25,   24,   24,   24, 0x05,
      34,   24,   24,   24, 0x05,
      43,   24,   24,   24, 0x05,
      61,   52,   24,   24, 0x05,

 // slots: signature, parameters, type, tag, flags
     108,   94,   24,   24, 0x08,
     150,   24,   24,   24, 0x08,
     174,   24,   24,   24, 0x08,
     205,  200,   24,   24, 0x08,
     231,   24,   24,   24, 0x08,
     257,  251,   24,   24, 0x08,
     289,  251,   24,   24, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QIzleznifaktmasterLista[] = {
    "QIzleznifaktmasterLista\0\0closeW()\0"
    "procF2()\0procF3()\0listData\0"
    "sfaktmasterToIzvod(QStringList&)\0"
    "modelX,modelY\0selectionChanged(QModelIndex,QModelIndex)\0"
    "on_pushButton_clicked()\0"
    "on_pushButton_2_clicked()\0text\0"
    "lineEdit7Pressed(QString)\0calcSelectedItems()\0"
    "a,b,c\0procSectionResized(int,int,int)\0"
    "procSectionResized_detail(int,int,int)\0"
};

void QIzleznifaktmasterLista::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QIzleznifaktmasterLista *_t = static_cast<QIzleznifaktmasterLista *>(_o);
        switch (_id) {
        case 0: _t->closeW(); break;
        case 1: _t->procF2(); break;
        case 2: _t->procF3(); break;
        case 3: _t->sfaktmasterToIzvod((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 4: _t->selectionChanged((*reinterpret_cast< QModelIndex(*)>(_a[1])),(*reinterpret_cast< QModelIndex(*)>(_a[2]))); break;
        case 5: _t->on_pushButton_clicked(); break;
        case 6: _t->on_pushButton_2_clicked(); break;
        case 7: _t->lineEdit7Pressed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->calcSelectedItems(); break;
        case 9: _t->procSectionResized((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 10: _t->procSectionResized_detail((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QIzleznifaktmasterLista::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QIzleznifaktmasterLista::staticMetaObject = {
    { &QMyBaseFormWidget::staticMetaObject, qt_meta_stringdata_QIzleznifaktmasterLista,
      qt_meta_data_QIzleznifaktmasterLista, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QIzleznifaktmasterLista::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QIzleznifaktmasterLista::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QIzleznifaktmasterLista::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QIzleznifaktmasterLista))
        return static_cast<void*>(const_cast< QIzleznifaktmasterLista*>(this));
    return QMyBaseFormWidget::qt_metacast(_clname);
}

int QIzleznifaktmasterLista::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void QIzleznifaktmasterLista::closeW()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QIzleznifaktmasterLista::procF2()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void QIzleznifaktmasterLista::procF3()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void QIzleznifaktmasterLista::sfaktmasterToIzvod(QStringList & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
