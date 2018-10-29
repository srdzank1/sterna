/****************************************************************************
** Meta object code from reading C++ file 'qmykalkulacija.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qmykalkulacija.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qmykalkulacija.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QMyKalkulacija[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,
      36,   15,   15,   15, 0x05,
      66,   64,   15,   15, 0x05,
     114,   64,   15,   15, 0x05,
     159,   64,   15,   15, 0x05,
     210,   15,   15,   15, 0x05,
     229,   64,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
     265,   15,   15,   15, 0x0a,
     279,   15,   15,   15, 0x0a,
     288,   64,   15,   15, 0x0a,
     332,  321,   15,   15, 0x0a,
     362,  321,   15,   15, 0x0a,
     394,   15,   15,   15, 0x0a,
     403,   15,   15,   15, 0x0a,
     412,   15,   15,   15, 0x0a,
     431,  422,   15,   15, 0x0a,
     468,  463,   15,   15, 0x0a,
     495,  489,   15,   15, 0x0a,
     525,  519,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QMyKalkulacija[] = {
    "QMyKalkulacija\0\0signCloseMyWidget()\0"
    "signKomintentiFromFaktura()\0,\0"
    "signKomintentiFromKalkulacija(QWidget*,QString)\0"
    "signArtikliFromKalkulacija(QWidget*,QString)\0"
    "signImportArtikliFromKalkulacija(QWidget*,QString)\0"
    "disablePrint(bool)\0"
    "eupdateNanigator(QWidget*,QWidget*)\0"
    "closeWLista()\0closeW()\0"
    "callKomintenti(QWidget*,QString)\0"
    "myobj,text\0callArtikli(QWidget*,QString)\0"
    "callPriemnici(QWidget*,QString)\0"
    "procF2()\0procF3()\0procDel()\0listData\0"
    "retFakturiToIzvod(QStringList&)\0text\0"
    "textChanged(QString)\0date1\0"
    "date1Changed(QDateTime)\0date2\0"
    "date2Changed(QDateTime)\0"
};

void QMyKalkulacija::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QMyKalkulacija *_t = static_cast<QMyKalkulacija *>(_o);
        switch (_id) {
        case 0: _t->signCloseMyWidget(); break;
        case 1: _t->signKomintentiFromFaktura(); break;
        case 2: _t->signKomintentiFromKalkulacija((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->signArtikliFromKalkulacija((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->signImportArtikliFromKalkulacija((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->disablePrint((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->eupdateNanigator((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QWidget*(*)>(_a[2]))); break;
        case 7: _t->closeWLista(); break;
        case 8: _t->closeW(); break;
        case 9: _t->callKomintenti((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 10: _t->callArtikli((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 11: _t->callPriemnici((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 12: _t->procF2(); break;
        case 13: _t->procF3(); break;
        case 14: _t->procDel(); break;
        case 15: _t->retFakturiToIzvod((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 16: _t->textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 17: _t->date1Changed((*reinterpret_cast< const QDateTime(*)>(_a[1]))); break;
        case 18: _t->date2Changed((*reinterpret_cast< const QDateTime(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QMyKalkulacija::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QMyKalkulacija::staticMetaObject = {
    { &QMyBaseWidget::staticMetaObject, qt_meta_stringdata_QMyKalkulacija,
      qt_meta_data_QMyKalkulacija, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QMyKalkulacija::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QMyKalkulacija::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QMyKalkulacija::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QMyKalkulacija))
        return static_cast<void*>(const_cast< QMyKalkulacija*>(this));
    return QMyBaseWidget::qt_metacast(_clname);
}

int QMyKalkulacija::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMyBaseWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void QMyKalkulacija::signCloseMyWidget()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QMyKalkulacija::signKomintentiFromFaktura()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void QMyKalkulacija::signKomintentiFromKalkulacija(QWidget * _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QMyKalkulacija::signArtikliFromKalkulacija(QWidget * _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QMyKalkulacija::signImportArtikliFromKalkulacija(QWidget * _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void QMyKalkulacija::disablePrint(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void QMyKalkulacija::eupdateNanigator(QWidget * _t1, QWidget * _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE
