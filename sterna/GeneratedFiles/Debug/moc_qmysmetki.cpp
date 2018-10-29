/****************************************************************************
** Meta object code from reading C++ file 'qmysmetki.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qmysmetki.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qmysmetki.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QMySmetki[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,
      33,   31,   10,   10, 0x05,
      80,   31,   10,   10, 0x05,
     124,   10,   10,   10, 0x05,
     136,   31,   10,   10, 0x05,
     172,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
     191,   10,   10,   10, 0x0a,
     205,   10,   10,   10, 0x0a,
     214,   10,   10,   10, 0x0a,
     223,   10,   10,   10, 0x0a,
     233,   10,   10,   10, 0x0a,
     253,  242,   10,   10, 0x0a,
     286,  242,   10,   10, 0x0a,
     325,  316,   10,   10, 0x0a,
     361,  356,   10,   10, 0x0a,
     388,  382,   10,   10, 0x0a,
     418,  412,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QMySmetki[] = {
    "QMySmetki\0\0signCloseMyWidget()\0,\0"
    "signKomintentiFromIspratnica(QWidget*,QString)\0"
    "signArtikliFromIspratnica(QWidget*,QString)\0"
    "signPrint()\0eupdateNanigator(QWidget*,QWidget*)\0"
    "disablePrint(bool)\0closeWLista()\0"
    "procF2()\0procF3()\0procDel()\0closeW()\0"
    "myobj,text\0callKomintenti(QWidget*,QString)\0"
    "callArtikli(QWidget*,QString)\0listData\0"
    "retSmetkiToIzvod(QStringList&)\0text\0"
    "textChanged(QString)\0date1\0"
    "date1Changed(QDateTime)\0date2\0"
    "date2Changed(QDateTime)\0"
};

void QMySmetki::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QMySmetki *_t = static_cast<QMySmetki *>(_o);
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
        case 13: _t->retSmetkiToIzvod((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 14: _t->textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 15: _t->date1Changed((*reinterpret_cast< const QDateTime(*)>(_a[1]))); break;
        case 16: _t->date2Changed((*reinterpret_cast< const QDateTime(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QMySmetki::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QMySmetki::staticMetaObject = {
    { &QMyBaseWidget::staticMetaObject, qt_meta_stringdata_QMySmetki,
      qt_meta_data_QMySmetki, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QMySmetki::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QMySmetki::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QMySmetki::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QMySmetki))
        return static_cast<void*>(const_cast< QMySmetki*>(this));
    return QMyBaseWidget::qt_metacast(_clname);
}

int QMySmetki::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void QMySmetki::signCloseMyWidget()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QMySmetki::signKomintentiFromIspratnica(QWidget * _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QMySmetki::signArtikliFromIspratnica(QWidget * _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QMySmetki::signPrint()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void QMySmetki::eupdateNanigator(QWidget * _t1, QWidget * _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void QMySmetki::disablePrint(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
