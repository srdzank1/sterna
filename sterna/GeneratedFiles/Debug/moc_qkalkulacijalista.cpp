/****************************************************************************
** Meta object code from reading C++ file 'qkalkulacijalista.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qkalkulacijalista.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qkalkulacijalista.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QKalkulacijaLista[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x05,
      28,   18,   18,   18, 0x05,
      37,   18,   18,   18, 0x05,
      46,   18,   18,   18, 0x05,
      61,   56,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
     105,   91,   18,   18, 0x08,
     147,   18,   18,   18, 0x08,
     171,   18,   18,   18, 0x08,
     197,   18,   18,   18, 0x08,
     217,   18,   18,   18, 0x08,
     241,  235,   18,   18, 0x08,
     273,  235,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QKalkulacijaLista[] = {
    "QKalkulacijaLista\0\0closeW()\0procF2()\0"
    "procF3()\0procDel()\0data\0"
    "sFakturiToIzvod(QStringList&)\0"
    "modelX,modelY\0selectionChanged(QModelIndex,QModelIndex)\0"
    "on_pushButton_clicked()\0"
    "on_pushButton_2_clicked()\0calcSelectedItems()\0"
    "copyToClipBoard()\0a,b,c\0"
    "procSectionResized(int,int,int)\0"
    "procSectionResized_detail(int,int,int)\0"
};

void QKalkulacijaLista::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QKalkulacijaLista *_t = static_cast<QKalkulacijaLista *>(_o);
        switch (_id) {
        case 0: _t->closeW(); break;
        case 1: _t->procF2(); break;
        case 2: _t->procF3(); break;
        case 3: _t->procDel(); break;
        case 4: _t->sFakturiToIzvod((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 5: _t->selectionChanged((*reinterpret_cast< QModelIndex(*)>(_a[1])),(*reinterpret_cast< QModelIndex(*)>(_a[2]))); break;
        case 6: _t->on_pushButton_clicked(); break;
        case 7: _t->on_pushButton_2_clicked(); break;
        case 8: _t->calcSelectedItems(); break;
        case 9: _t->copyToClipBoard(); break;
        case 10: _t->procSectionResized((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 11: _t->procSectionResized_detail((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QKalkulacijaLista::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QKalkulacijaLista::staticMetaObject = {
    { &QMyBaseFormWidget::staticMetaObject, qt_meta_stringdata_QKalkulacijaLista,
      qt_meta_data_QKalkulacijaLista, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QKalkulacijaLista::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QKalkulacijaLista::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QKalkulacijaLista::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QKalkulacijaLista))
        return static_cast<void*>(const_cast< QKalkulacijaLista*>(this));
    return QMyBaseFormWidget::qt_metacast(_clname);
}

int QKalkulacijaLista::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMyBaseFormWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void QKalkulacijaLista::closeW()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QKalkulacijaLista::procF2()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void QKalkulacijaLista::procF3()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void QKalkulacijaLista::procDel()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void QKalkulacijaLista::sFakturiToIzvod(QStringList & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
