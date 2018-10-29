/****************************************************************************
** Meta object code from reading C++ file 'qdnevenpromet.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qdnevenpromet.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qdnevenpromet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QDnevenpromet[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,
      35,   14,   14,   14, 0x05,
      69,   67,   14,   14, 0x05,
     105,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
     124,   14,   14,   14, 0x0a,
     166,  138,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QDnevenpromet[] = {
    "QDnevenpromet\0\0signCloseMyWidget()\0"
    "eCloseKomintentiFromPriemnica()\0,\0"
    "eupdateNanigator(QWidget*,QWidget*)\0"
    "disablePrint(bool)\0closeWLista()\0"
    "text,textName,textNameSaldo\0"
    "callretDnevenprometToDokument(QString&,QString&,QString&)\0"
};

void QDnevenpromet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QDnevenpromet *_t = static_cast<QDnevenpromet *>(_o);
        switch (_id) {
        case 0: _t->signCloseMyWidget(); break;
        case 1: _t->eCloseKomintentiFromPriemnica(); break;
        case 2: _t->eupdateNanigator((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QWidget*(*)>(_a[2]))); break;
        case 3: _t->disablePrint((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->closeWLista(); break;
        case 5: _t->callretDnevenprometToDokument((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QDnevenpromet::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QDnevenpromet::staticMetaObject = {
    { &QMyBaseWidget::staticMetaObject, qt_meta_stringdata_QDnevenpromet,
      qt_meta_data_QDnevenpromet, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QDnevenpromet::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QDnevenpromet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QDnevenpromet::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QDnevenpromet))
        return static_cast<void*>(const_cast< QDnevenpromet*>(this));
    return QMyBaseWidget::qt_metacast(_clname);
}

int QDnevenpromet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMyBaseWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void QDnevenpromet::signCloseMyWidget()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QDnevenpromet::eCloseKomintentiFromPriemnica()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void QDnevenpromet::eupdateNanigator(QWidget * _t1, QWidget * _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QDnevenpromet::disablePrint(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
