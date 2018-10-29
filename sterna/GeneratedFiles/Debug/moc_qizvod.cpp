/****************************************************************************
** Meta object code from reading C++ file 'qizvod.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qizvod.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qizvod.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QMyIzvod[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,
      32,   30,    9,    9, 0x05,
      77,   74,    9,    9, 0x05,
     120,   30,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
     167,    9,    9,    9, 0x0a,
     181,    9,    9,    9, 0x0a,
     201,  190,    9,    9, 0x0a,
     249,  234,    9,    9, 0x0a,
     283,    9,    9,    9, 0x0a,
     292,    9,    9,    9, 0x0a,
     301,    9,    9,    9, 0x0a,
     322,  311,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QMyIzvod[] = {
    "QMyIzvod\0\0signCloseMyWidget()\0,\0"
    "signZiroSmetkiFromIzvod(QWidget*,QString)\0"
    ",,\0signFakturiFromIzvod(QWidget*,QString,int)\0"
    "signKomintentiFromIspratnica(QWidget*,QString)\0"
    "closeWLista()\0closeW()\0myobj,ziro\0"
    "callZiroSmetki(QWidget*,QString)\0"
    "myobj,ziro,tip\0callFakturi(QWidget*,QString,int)\0"
    "procF2()\0procF3()\0procDel()\0myobj,text\0"
    "callKomintenti(QWidget*,QString)\0"
};

void QMyIzvod::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QMyIzvod *_t = static_cast<QMyIzvod *>(_o);
        switch (_id) {
        case 0: _t->signCloseMyWidget(); break;
        case 1: _t->signZiroSmetkiFromIzvod((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->signFakturiFromIzvod((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 3: _t->signKomintentiFromIspratnica((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->closeWLista(); break;
        case 5: _t->closeW(); break;
        case 6: _t->callZiroSmetki((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 7: _t->callFakturi((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 8: _t->procF2(); break;
        case 9: _t->procF3(); break;
        case 10: _t->procDel(); break;
        case 11: _t->callKomintenti((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QMyIzvod::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QMyIzvod::staticMetaObject = {
    { &QMyBaseWidget::staticMetaObject, qt_meta_stringdata_QMyIzvod,
      qt_meta_data_QMyIzvod, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QMyIzvod::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QMyIzvod::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QMyIzvod::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QMyIzvod))
        return static_cast<void*>(const_cast< QMyIzvod*>(this));
    return QMyBaseWidget::qt_metacast(_clname);
}

int QMyIzvod::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void QMyIzvod::signCloseMyWidget()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QMyIzvod::signZiroSmetkiFromIzvod(QWidget * _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QMyIzvod::signFakturiFromIzvod(QWidget * _t1, QString _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QMyIzvod::signKomintentiFromIspratnica(QWidget * _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
