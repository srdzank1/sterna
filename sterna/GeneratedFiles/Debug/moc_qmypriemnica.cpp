/****************************************************************************
** Meta object code from reading C++ file 'qmypriemnica.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qmypriemnica.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qmypriemnica.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QMyPriemnica[] = {

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
      14,   13,   13,   13, 0x05,
      34,   13,   13,   13, 0x05,
      64,   62,   13,   13, 0x05,
     110,   62,   13,   13, 0x05,
     153,   13,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
     172,   13,   13,   13, 0x0a,
     186,   13,   13,   13, 0x0a,
     195,   62,   13,   13, 0x0a,
     239,  228,   13,   13, 0x0a,
     269,   13,   13,   13, 0x0a,
     278,   13,   13,   13, 0x0a,
     287,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QMyPriemnica[] = {
    "QMyPriemnica\0\0signCloseMyWidget()\0"
    "signKomintentiFromFaktura()\0,\0"
    "signKomintentiFromPriemnica(QWidget*,QString)\0"
    "signArtikliFromPriemnica(QWidget*,QString)\0"
    "disablePrint(bool)\0closeWLista()\0"
    "closeW()\0callKomintenti(QWidget*,QString)\0"
    "myobj,text\0callArtikli(QWidget*,QString)\0"
    "procF2()\0procF3()\0procDel()\0"
};

void QMyPriemnica::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QMyPriemnica *_t = static_cast<QMyPriemnica *>(_o);
        switch (_id) {
        case 0: _t->signCloseMyWidget(); break;
        case 1: _t->signKomintentiFromFaktura(); break;
        case 2: _t->signKomintentiFromPriemnica((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->signArtikliFromPriemnica((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->disablePrint((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->closeWLista(); break;
        case 6: _t->closeW(); break;
        case 7: _t->callKomintenti((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 8: _t->callArtikli((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 9: _t->procF2(); break;
        case 10: _t->procF3(); break;
        case 11: _t->procDel(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QMyPriemnica::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QMyPriemnica::staticMetaObject = {
    { &QMyBaseWidget::staticMetaObject, qt_meta_stringdata_QMyPriemnica,
      qt_meta_data_QMyPriemnica, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QMyPriemnica::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QMyPriemnica::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QMyPriemnica::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QMyPriemnica))
        return static_cast<void*>(const_cast< QMyPriemnica*>(this));
    return QMyBaseWidget::qt_metacast(_clname);
}

int QMyPriemnica::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMyBaseWidget::qt_metacall(_c, _id, _a);
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
void QMyPriemnica::signCloseMyWidget()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QMyPriemnica::signKomintentiFromFaktura()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void QMyPriemnica::signKomintentiFromPriemnica(QWidget * _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QMyPriemnica::signArtikliFromPriemnica(QWidget * _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QMyPriemnica::disablePrint(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
