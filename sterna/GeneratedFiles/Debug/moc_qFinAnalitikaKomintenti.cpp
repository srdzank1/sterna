/****************************************************************************
** Meta object code from reading C++ file 'qFinAnalitikaKomintenti.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qFinAnalitikaKomintenti.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qFinAnalitikaKomintenti.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QFinAnalitKomintenti[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   21,   21,   21, 0x05,
      42,   21,   21,   21, 0x05,
      76,   74,   21,   21, 0x05,

 // slots: signature, parameters, type, tag, flags
     112,   21,   21,   21, 0x0a,
     154,  126,   21,   21, 0x0a,
     224,  219,   21,   21, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QFinAnalitKomintenti[] = {
    "QFinAnalitKomintenti\0\0signCloseMyWidget()\0"
    "eCloseKomintentiFromPriemnica()\0,\0"
    "eupdateNanigator(QWidget*,QWidget*)\0"
    "closeWLista()\0text,textName,textNameSaldo\0"
    "callretFinAnalitKomintentiToDokument(QString&,QString&,QString&)\0"
    "text\0textChanged(QString)\0"
};

void QFinAnalitKomintenti::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QFinAnalitKomintenti *_t = static_cast<QFinAnalitKomintenti *>(_o);
        switch (_id) {
        case 0: _t->signCloseMyWidget(); break;
        case 1: _t->eCloseKomintentiFromPriemnica(); break;
        case 2: _t->eupdateNanigator((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QWidget*(*)>(_a[2]))); break;
        case 3: _t->closeWLista(); break;
        case 4: _t->callretFinAnalitKomintentiToDokument((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 5: _t->textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QFinAnalitKomintenti::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QFinAnalitKomintenti::staticMetaObject = {
    { &QMyBaseWidget::staticMetaObject, qt_meta_stringdata_QFinAnalitKomintenti,
      qt_meta_data_QFinAnalitKomintenti, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QFinAnalitKomintenti::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QFinAnalitKomintenti::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QFinAnalitKomintenti::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QFinAnalitKomintenti))
        return static_cast<void*>(const_cast< QFinAnalitKomintenti*>(this));
    return QMyBaseWidget::qt_metacast(_clname);
}

int QFinAnalitKomintenti::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void QFinAnalitKomintenti::signCloseMyWidget()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QFinAnalitKomintenti::eCloseKomintentiFromPriemnica()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void QFinAnalitKomintenti::eupdateNanigator(QWidget * _t1, QWidget * _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
