/****************************************************************************
** Meta object code from reading C++ file 'qmyfakturi.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qmyfakturi.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qmyfakturi.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QMyFakturi[] = {

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
      12,   11,   11,   11, 0x05,
      34,   32,   11,   11, 0x05,
      81,   32,   11,   11, 0x05,
     125,   32,   11,   11, 0x05,
     158,   11,   11,   11, 0x05,
     170,   32,   11,   11, 0x05,
     206,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
     225,   11,   11,   11, 0x0a,
     239,   11,   11,   11, 0x0a,
     248,   11,   11,   11, 0x0a,
     257,   11,   11,   11, 0x0a,
     267,   11,   11,   11, 0x0a,
     287,  276,   11,   11, 0x0a,
     320,  276,   11,   11, 0x0a,
     359,  350,   11,   11, 0x0a,
     396,  391,   11,   11, 0x0a,
     423,  417,   11,   11, 0x0a,
     453,  447,   11,   11, 0x0a,
     477,  276,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QMyFakturi[] = {
    "QMyFakturi\0\0signCloseMyWidget()\0,\0"
    "signKomintentiFromIspratnica(QWidget*,QString)\0"
    "signArtikliFromIspratnica(QWidget*,QString)\0"
    "signIspratnica(QWidget*,QString)\0"
    "signPrint()\0eupdateNanigator(QWidget*,QWidget*)\0"
    "disablePrint(bool)\0closeWLista()\0"
    "procF2()\0procF3()\0procDel()\0closeW()\0"
    "myobj,text\0callKomintenti(QWidget*,QString)\0"
    "callArtikli(QWidget*,QString)\0listData\0"
    "retFakturiToIzvod(QStringList&)\0text\0"
    "textChanged(QString)\0date1\0"
    "date1Changed(QDateTime)\0date2\0"
    "date2Changed(QDateTime)\0"
    "callIspratnici(QWidget*,QString)\0"
};

void QMyFakturi::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QMyFakturi *_t = static_cast<QMyFakturi *>(_o);
        switch (_id) {
        case 0: _t->signCloseMyWidget(); break;
        case 1: _t->signKomintentiFromIspratnica((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->signArtikliFromIspratnica((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->signIspratnica((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->signPrint(); break;
        case 5: _t->eupdateNanigator((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QWidget*(*)>(_a[2]))); break;
        case 6: _t->disablePrint((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->closeWLista(); break;
        case 8: _t->procF2(); break;
        case 9: _t->procF3(); break;
        case 10: _t->procDel(); break;
        case 11: _t->closeW(); break;
        case 12: _t->callKomintenti((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 13: _t->callArtikli((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 14: _t->retFakturiToIzvod((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 15: _t->textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 16: _t->date1Changed((*reinterpret_cast< const QDateTime(*)>(_a[1]))); break;
        case 17: _t->date2Changed((*reinterpret_cast< const QDateTime(*)>(_a[1]))); break;
        case 18: _t->callIspratnici((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QMyFakturi::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QMyFakturi::staticMetaObject = {
    { &QMyBaseWidget::staticMetaObject, qt_meta_stringdata_QMyFakturi,
      qt_meta_data_QMyFakturi, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QMyFakturi::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QMyFakturi::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QMyFakturi::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QMyFakturi))
        return static_cast<void*>(const_cast< QMyFakturi*>(this));
    return QMyBaseWidget::qt_metacast(_clname);
}

int QMyFakturi::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void QMyFakturi::signCloseMyWidget()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QMyFakturi::signKomintentiFromIspratnica(QWidget * _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QMyFakturi::signArtikliFromIspratnica(QWidget * _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QMyFakturi::signIspratnica(QWidget * _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QMyFakturi::signPrint()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void QMyFakturi::eupdateNanigator(QWidget * _t1, QWidget * _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void QMyFakturi::disablePrint(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE
