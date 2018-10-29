/****************************************************************************
** Meta object code from reading C++ file 'qmyispratnici.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qmyispratnici.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qmyispratnici.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QMyIspratnici[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,
      37,   35,   14,   14, 0x05,
      84,   35,   14,   14, 0x05,
     128,   35,   14,   14, 0x05,
     161,   14,   14,   14, 0x05,
     173,   35,   14,   14, 0x05,
     209,   14,   14,   14, 0x05,
     228,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
     249,   14,   14,   14, 0x0a,
     263,   14,   14,   14, 0x0a,
     272,   14,   14,   14, 0x0a,
     281,   14,   14,   14, 0x0a,
     291,   14,   14,   14, 0x0a,
     311,  300,   14,   14, 0x0a,
     344,  300,   14,   14, 0x0a,
     383,  374,   14,   14, 0x0a,
     423,  418,   14,   14, 0x0a,
     450,  444,   14,   14, 0x0a,
     480,  474,   14,   14, 0x0a,
     504,  300,   14,   14, 0x0a,
     537,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QMyIspratnici[] = {
    "QMyIspratnici\0\0signCloseMyWidget()\0,\0"
    "signKomintentiFromIspratnica(QWidget*,QString)\0"
    "signArtikliFromIspratnica(QWidget*,QString)\0"
    "signIspratnica(QWidget*,QString)\0"
    "signPrint()\0eupdateNanigator(QWidget*,QWidget*)\0"
    "disablePrint(bool)\0signCallSearchForm()\0"
    "closeWLista()\0procF2()\0procF3()\0"
    "procDel()\0closeW()\0myobj,text\0"
    "callKomintenti(QWidget*,QString)\0"
    "callArtikli(QWidget*,QString)\0listData\0"
    "retIspratniciToIzvod(QStringList&)\0"
    "text\0textChanged(QString)\0date1\0"
    "date1Changed(QDateTime)\0date2\0"
    "date2Changed(QDateTime)\0"
    "callIspratnici(QWidget*,QString)\0"
    "procCallSearchFormA()\0"
};

void QMyIspratnici::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QMyIspratnici *_t = static_cast<QMyIspratnici *>(_o);
        switch (_id) {
        case 0: _t->signCloseMyWidget(); break;
        case 1: _t->signKomintentiFromIspratnica((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->signArtikliFromIspratnica((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->signIspratnica((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->signPrint(); break;
        case 5: _t->eupdateNanigator((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QWidget*(*)>(_a[2]))); break;
        case 6: _t->disablePrint((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->signCallSearchForm(); break;
        case 8: _t->closeWLista(); break;
        case 9: _t->procF2(); break;
        case 10: _t->procF3(); break;
        case 11: _t->procDel(); break;
        case 12: _t->closeW(); break;
        case 13: _t->callKomintenti((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 14: _t->callArtikli((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 15: _t->retIspratniciToIzvod((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 16: _t->textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 17: _t->date1Changed((*reinterpret_cast< const QDateTime(*)>(_a[1]))); break;
        case 18: _t->date2Changed((*reinterpret_cast< const QDateTime(*)>(_a[1]))); break;
        case 19: _t->callIspratnici((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 20: _t->procCallSearchFormA(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QMyIspratnici::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QMyIspratnici::staticMetaObject = {
    { &QMyBaseWidget::staticMetaObject, qt_meta_stringdata_QMyIspratnici,
      qt_meta_data_QMyIspratnici, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QMyIspratnici::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QMyIspratnici::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QMyIspratnici::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QMyIspratnici))
        return static_cast<void*>(const_cast< QMyIspratnici*>(this));
    return QMyBaseWidget::qt_metacast(_clname);
}

int QMyIspratnici::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMyBaseWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    }
    return _id;
}

// SIGNAL 0
void QMyIspratnici::signCloseMyWidget()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QMyIspratnici::signKomintentiFromIspratnica(QWidget * _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QMyIspratnici::signArtikliFromIspratnica(QWidget * _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QMyIspratnici::signIspratnica(QWidget * _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QMyIspratnici::signPrint()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void QMyIspratnici::eupdateNanigator(QWidget * _t1, QWidget * _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void QMyIspratnici::disablePrint(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void QMyIspratnici::signCallSearchForm()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}
QT_END_MOC_NAMESPACE
