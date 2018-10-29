/****************************************************************************
** Meta object code from reading C++ file 'qizleznismetkilista.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qizleznismetkilista.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qizleznismetkilista.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QIzlezniSmetkiLista[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x05,
      30,   20,   20,   20, 0x05,
      39,   20,   20,   20, 0x05,
      57,   48,   20,   20, 0x05,

 // slots: signature, parameters, type, tag, flags
     100,   86,   20,   20, 0x08,
     142,   20,   20,   20, 0x08,
     166,   20,   20,   20, 0x08,
     197,  192,   20,   20, 0x08,
     223,   20,   20,   20, 0x08,
     243,   20,   20,   20, 0x08,
     269,   20,   20,   20, 0x08,
     295,   20,   20,   20, 0x08,
     327,  321,   20,   20, 0x08,
     359,  321,   20,   20, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QIzlezniSmetkiLista[] = {
    "QIzlezniSmetkiLista\0\0closeW()\0procF2()\0"
    "procF3()\0listData\0sSmetkiToIzvod(QStringList&)\0"
    "modelX,modelY\0selectionChanged(QModelIndex,QModelIndex)\0"
    "on_pushButton_clicked()\0"
    "on_pushButton_2_clicked()\0text\0"
    "lineEdit7Pressed(QString)\0calcSelectedItems()\0"
    "on_pushButton_3_clicked()\0"
    "on_pushButton_4_clicked()\0"
    "on_pushButton_5_clicked()\0a,b,c\0"
    "procSectionResized(int,int,int)\0"
    "procSectionResized_detail(int,int,int)\0"
};

void QIzlezniSmetkiLista::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QIzlezniSmetkiLista *_t = static_cast<QIzlezniSmetkiLista *>(_o);
        switch (_id) {
        case 0: _t->closeW(); break;
        case 1: _t->procF2(); break;
        case 2: _t->procF3(); break;
        case 3: _t->sSmetkiToIzvod((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 4: _t->selectionChanged((*reinterpret_cast< QModelIndex(*)>(_a[1])),(*reinterpret_cast< QModelIndex(*)>(_a[2]))); break;
        case 5: _t->on_pushButton_clicked(); break;
        case 6: _t->on_pushButton_2_clicked(); break;
        case 7: _t->lineEdit7Pressed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->calcSelectedItems(); break;
        case 9: _t->on_pushButton_3_clicked(); break;
        case 10: _t->on_pushButton_4_clicked(); break;
        case 11: _t->on_pushButton_5_clicked(); break;
        case 12: _t->procSectionResized((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 13: _t->procSectionResized_detail((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QIzlezniSmetkiLista::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QIzlezniSmetkiLista::staticMetaObject = {
    { &QMyBaseFormWidget::staticMetaObject, qt_meta_stringdata_QIzlezniSmetkiLista,
      qt_meta_data_QIzlezniSmetkiLista, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QIzlezniSmetkiLista::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QIzlezniSmetkiLista::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QIzlezniSmetkiLista::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QIzlezniSmetkiLista))
        return static_cast<void*>(const_cast< QIzlezniSmetkiLista*>(this));
    return QMyBaseFormWidget::qt_metacast(_clname);
}

int QIzlezniSmetkiLista::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void QIzlezniSmetkiLista::closeW()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QIzlezniSmetkiLista::procF2()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void QIzlezniSmetkiLista::procF3()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void QIzlezniSmetkiLista::sSmetkiToIzvod(QStringList & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
