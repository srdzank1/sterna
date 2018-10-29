/****************************************************************************
** Meta object code from reading C++ file 'qmykasa.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qmykasa.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qmykasa.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QMyKasa[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x05,
      31,   29,    8,    8, 0x05,
      78,   29,    8,    8, 0x05,
     122,    8,    8,    8, 0x05,
     134,   29,    8,    8, 0x05,
     170,    8,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
     189,    8,    8,    8, 0x0a,
     203,    8,    8,    8, 0x0a,
     212,    8,    8,    8, 0x0a,
     221,    8,    8,    8, 0x0a,
     231,    8,    8,    8, 0x0a,
     251,  240,    8,    8, 0x0a,
     284,  240,    8,    8, 0x0a,
     341,  314,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QMyKasa[] = {
    "QMyKasa\0\0signCloseMyWidget()\0,\0"
    "signKomintentiFromIspratnica(QWidget*,QString)\0"
    "signArtikliFromIspratnica(QWidget*,QString)\0"
    "signPrint()\0eupdateNanigator(QWidget*,QWidget*)\0"
    "disablePrint(bool)\0closeWLista()\0"
    "procF2()\0procF3()\0procDel()\0closeW()\0"
    "myobj,text\0callKomintenti(QWidget*,QString)\0"
    "callArtikli(QWidget*,QString)\0"
    "text6,text8,text9,textName\0"
    "retKasaToIzvod(QString&,QString&,QString&,QString&)\0"
};

void QMyKasa::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QMyKasa *_t = static_cast<QMyKasa *>(_o);
        switch (_id) {
        case 0: _t->signCloseMyWidget(); break;
        case 1: _t->signKomintentiFromIspratnica((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->signArtikliFromIspratnica((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->signPrint(); break;
        case 4: _t->eupdateNanigator((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QWidget*(*)>(_a[2]))); break;
        case 5: _t->disablePrint((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->closeWLista(); break;
        case 7: _t->procF2(); break;
        case 8: _t->procF3(); break;
        case 9: _t->procDel(); break;
        case 10: _t->closeW(); break;
        case 11: _t->callKomintenti((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 12: _t->callArtikli((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 13: _t->retKasaToIzvod((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QMyKasa::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QMyKasa::staticMetaObject = {
    { &QMyBaseWidget::staticMetaObject, qt_meta_stringdata_QMyKasa,
      qt_meta_data_QMyKasa, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QMyKasa::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QMyKasa::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QMyKasa::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QMyKasa))
        return static_cast<void*>(const_cast< QMyKasa*>(this));
    return QMyBaseWidget::qt_metacast(_clname);
}

int QMyKasa::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMyBaseWidget::qt_metacall(_c, _id, _a);
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
void QMyKasa::signCloseMyWidget()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QMyKasa::signKomintentiFromIspratnica(QWidget * _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QMyKasa::signArtikliFromIspratnica(QWidget * _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QMyKasa::signPrint()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void QMyKasa::eupdateNanigator(QWidget * _t1, QWidget * _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void QMyKasa::disablePrint(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
