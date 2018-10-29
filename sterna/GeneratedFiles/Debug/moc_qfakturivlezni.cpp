/****************************************************************************
** Meta object code from reading C++ file 'qfakturivlezni.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qfakturivlezni.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qfakturivlezni.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QFakturiVlezni[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,
      36,   15,   15,   15, 0x05,
      66,   64,   15,   15, 0x05,
     112,   64,   15,   15, 0x05,
     155,   64,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
     191,   15,   15,   15, 0x0a,
     205,   15,   15,   15, 0x0a,
     214,   64,   15,   15, 0x0a,
     258,  247,   15,   15, 0x0a,
     288,   15,   15,   15, 0x0a,
     297,   15,   15,   15, 0x0a,
     306,   15,   15,   15, 0x0a,
     325,  316,   15,   15, 0x0a,
     374,  357,   15,   15, 0x0a,
     423,  417,   15,   15, 0x0a,
     453,  447,   15,   15, 0x0a,
     482,  477,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QFakturiVlezni[] = {
    "QFakturiVlezni\0\0signCloseMyWidget()\0"
    "signKomintentiFromFaktura()\0,\0"
    "signKomintentiFromPriemnica(QWidget*,QString)\0"
    "signArtikliFromPriemnica(QWidget*,QString)\0"
    "eupdateNanigator(QWidget*,QWidget*)\0"
    "closeWLista()\0closeW()\0"
    "callKomintenti(QWidget*,QString)\0"
    "myobj,text\0callArtikli(QWidget*,QString)\0"
    "procF2()\0procF3()\0procDel()\0listData\0"
    "retFakturiToIzvod(QStringList&)\0"
    "text,date1,date2\0"
    "textChanged(QString,QDateTime&,QDateTime&)\0"
    "date1\0date1Changed(QDateTime)\0date2\0"
    "date2Changed(QDateTime)\0text\0"
    "textChanged(QString)\0"
};

void QFakturiVlezni::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QFakturiVlezni *_t = static_cast<QFakturiVlezni *>(_o);
        switch (_id) {
        case 0: _t->signCloseMyWidget(); break;
        case 1: _t->signKomintentiFromFaktura(); break;
        case 2: _t->signKomintentiFromPriemnica((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->signArtikliFromPriemnica((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->eupdateNanigator((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QWidget*(*)>(_a[2]))); break;
        case 5: _t->closeWLista(); break;
        case 6: _t->closeW(); break;
        case 7: _t->callKomintenti((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 8: _t->callArtikli((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 9: _t->procF2(); break;
        case 10: _t->procF3(); break;
        case 11: _t->procDel(); break;
        case 12: _t->retFakturiToIzvod((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 13: _t->textChanged((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QDateTime(*)>(_a[2])),(*reinterpret_cast< QDateTime(*)>(_a[3]))); break;
        case 14: _t->date1Changed((*reinterpret_cast< const QDateTime(*)>(_a[1]))); break;
        case 15: _t->date2Changed((*reinterpret_cast< const QDateTime(*)>(_a[1]))); break;
        case 16: _t->textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QFakturiVlezni::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QFakturiVlezni::staticMetaObject = {
    { &QMyBaseWidget::staticMetaObject, qt_meta_stringdata_QFakturiVlezni,
      qt_meta_data_QFakturiVlezni, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QFakturiVlezni::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QFakturiVlezni::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QFakturiVlezni::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QFakturiVlezni))
        return static_cast<void*>(const_cast< QFakturiVlezni*>(this));
    return QMyBaseWidget::qt_metacast(_clname);
}

int QFakturiVlezni::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMyBaseWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void QFakturiVlezni::signCloseMyWidget()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QFakturiVlezni::signKomintentiFromFaktura()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void QFakturiVlezni::signKomintentiFromPriemnica(QWidget * _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QFakturiVlezni::signArtikliFromPriemnica(QWidget * _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QFakturiVlezni::eupdateNanigator(QWidget * _t1, QWidget * _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
