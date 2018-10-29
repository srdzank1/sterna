/****************************************************************************
** Meta object code from reading C++ file 'qmyizjava.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qmyizjava.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qmyizjava.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QMyIzjava[] = {

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
      11,   10,   10,   10, 0x05,
      31,   10,   10,   10, 0x05,
      61,   59,   10,   10, 0x05,
     104,   59,   10,   10, 0x05,
     144,   10,   10,   10, 0x05,
     163,   59,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
     199,   10,   10,   10, 0x0a,
     213,   10,   10,   10, 0x0a,
     222,   59,   10,   10, 0x0a,
     266,  255,   10,   10, 0x0a,
     296,   10,   10,   10, 0x0a,
     305,   10,   10,   10, 0x0a,
     314,   10,   10,   10, 0x0a,
     351,  324,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QMyIzjava[] = {
    "QMyIzjava\0\0signCloseMyWidget()\0"
    "signKomintentiFromFaktura()\0,\0"
    "signKomintentiFromIzjava(QWidget*,QString)\0"
    "signArtikliFromIzjava(QWidget*,QString)\0"
    "disablePrint(bool)\0"
    "eupdateNanigator(QWidget*,QWidget*)\0"
    "closeWLista()\0closeW()\0"
    "callKomintenti(QWidget*,QString)\0"
    "myobj,text\0callArtikli(QWidget*,QString)\0"
    "procF2()\0procF3()\0procDel()\0"
    "text6,text8,text9,textName\0"
    "retIzjavaToIzvod(QString&,QString&,QString&,QString&)\0"
};

void QMyIzjava::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QMyIzjava *_t = static_cast<QMyIzjava *>(_o);
        switch (_id) {
        case 0: _t->signCloseMyWidget(); break;
        case 1: _t->signKomintentiFromFaktura(); break;
        case 2: _t->signKomintentiFromIzjava((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->signArtikliFromIzjava((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->disablePrint((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->eupdateNanigator((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QWidget*(*)>(_a[2]))); break;
        case 6: _t->closeWLista(); break;
        case 7: _t->closeW(); break;
        case 8: _t->callKomintenti((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 9: _t->callArtikli((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 10: _t->procF2(); break;
        case 11: _t->procF3(); break;
        case 12: _t->procDel(); break;
        case 13: _t->retIzjavaToIzvod((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QMyIzjava::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QMyIzjava::staticMetaObject = {
    { &QMyBaseWidget::staticMetaObject, qt_meta_stringdata_QMyIzjava,
      qt_meta_data_QMyIzjava, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QMyIzjava::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QMyIzjava::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QMyIzjava::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QMyIzjava))
        return static_cast<void*>(const_cast< QMyIzjava*>(this));
    return QMyBaseWidget::qt_metacast(_clname);
}

int QMyIzjava::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void QMyIzjava::signCloseMyWidget()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QMyIzjava::signKomintentiFromFaktura()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void QMyIzjava::signKomintentiFromIzjava(QWidget * _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QMyIzjava::signArtikliFromIzjava(QWidget * _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QMyIzjava::disablePrint(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void QMyIzjava::eupdateNanigator(QWidget * _t1, QWidget * _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
