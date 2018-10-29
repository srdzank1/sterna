/****************************************************************************
** Meta object code from reading C++ file 'qpromenaceni.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qpromenaceni.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qpromenaceni.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QPromenaCeni[] = {

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
      14,   13,   13,   13, 0x05,
      34,   13,   13,   13, 0x05,
      68,   66,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
     104,   13,   13,   13, 0x0a,
     174,  118,   13,   13, 0x0a,
     254,  249,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QPromenaCeni[] = {
    "QPromenaCeni\0\0signCloseMyWidget()\0"
    "eCloseKomintentiFromPriemnica()\0,\0"
    "eupdateNanigator(QWidget*,QWidget*)\0"
    "closeWLista()\0"
    "text,textName,textNameSaldo,textKomintentId,strProdCena\0"
    "callretPromenaCeniToDokument(QString&,QString&,QString&,QString&,QStri"
    "ng&)\0"
    "text\0textChanged(QString)\0"
};

void QPromenaCeni::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QPromenaCeni *_t = static_cast<QPromenaCeni *>(_o);
        switch (_id) {
        case 0: _t->signCloseMyWidget(); break;
        case 1: _t->eCloseKomintentiFromPriemnica(); break;
        case 2: _t->eupdateNanigator((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QWidget*(*)>(_a[2]))); break;
        case 3: _t->closeWLista(); break;
        case 4: _t->callretPromenaCeniToDokument((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        case 5: _t->textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QPromenaCeni::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QPromenaCeni::staticMetaObject = {
    { &QMyBaseWidget::staticMetaObject, qt_meta_stringdata_QPromenaCeni,
      qt_meta_data_QPromenaCeni, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QPromenaCeni::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QPromenaCeni::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QPromenaCeni::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QPromenaCeni))
        return static_cast<void*>(const_cast< QPromenaCeni*>(this));
    return QMyBaseWidget::qt_metacast(_clname);
}

int QPromenaCeni::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void QPromenaCeni::signCloseMyWidget()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QPromenaCeni::eCloseKomintentiFromPriemnica()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void QPromenaCeni::eupdateNanigator(QWidget * _t1, QWidget * _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
