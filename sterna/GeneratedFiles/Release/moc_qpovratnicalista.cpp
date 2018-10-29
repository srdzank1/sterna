/****************************************************************************
** Meta object code from reading C++ file 'qpovratnicalista.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qpovratnicalista.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qpovratnicalista.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QPovratnicaLista[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x05,
      27,   17,   17,   17, 0x05,
      36,   17,   17,   17, 0x05,
      72,   45,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
     142,  128,   17,   17, 0x08,
     184,   17,   17,   17, 0x08,
     208,   17,   17,   17, 0x08,
     239,  234,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QPovratnicaLista[] = {
    "QPovratnicaLista\0\0closeW()\0procF2()\0"
    "procF3()\0text6,text8,text9,textName\0"
    "sPovratnicaToIzvod(QString&,QString&,QString&,QString&)\0"
    "modelX,modelY\0selectionChanged(QModelIndex,QModelIndex)\0"
    "on_pushButton_clicked()\0"
    "on_pushButton_2_clicked()\0text\0"
    "lineEdit7Pressed(QString)\0"
};

void QPovratnicaLista::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QPovratnicaLista *_t = static_cast<QPovratnicaLista *>(_o);
        switch (_id) {
        case 0: _t->closeW(); break;
        case 1: _t->procF2(); break;
        case 2: _t->procF3(); break;
        case 3: _t->sPovratnicaToIzvod((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 4: _t->selectionChanged((*reinterpret_cast< QModelIndex(*)>(_a[1])),(*reinterpret_cast< QModelIndex(*)>(_a[2]))); break;
        case 5: _t->on_pushButton_clicked(); break;
        case 6: _t->on_pushButton_2_clicked(); break;
        case 7: _t->lineEdit7Pressed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QPovratnicaLista::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QPovratnicaLista::staticMetaObject = {
    { &QMyBaseFormWidget::staticMetaObject, qt_meta_stringdata_QPovratnicaLista,
      qt_meta_data_QPovratnicaLista, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QPovratnicaLista::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QPovratnicaLista::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QPovratnicaLista::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QPovratnicaLista))
        return static_cast<void*>(const_cast< QPovratnicaLista*>(this));
    return QMyBaseFormWidget::qt_metacast(_clname);
}

int QPovratnicaLista::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMyBaseFormWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void QPovratnicaLista::closeW()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QPovratnicaLista::procF2()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void QPovratnicaLista::procF3()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void QPovratnicaLista::sPovratnicaToIzvod(QString & _t1, QString & _t2, QString & _t3, QString & _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
