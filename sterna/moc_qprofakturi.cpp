/****************************************************************************
** Meta object code from reading C++ file 'qprofakturi.h'
**
** Created: Sat Mar 17 08:42:27 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qprofakturi.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qprofakturi.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QMyProFakturi[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,
      35,   14,   14,   14, 0x05,
      74,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
     110,   14,   14,   14, 0x0a,
     124,   14,   14,   14, 0x0a,
     139,  133,   14,   14, 0x0a,
     164,  133,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QMyProFakturi[] = {
    "QMyProFakturi\0\0signCloseMyWidget()\0"
    "signKomintentiFromProFaktura(QWidget*)\0"
    "signArtikliFromProFaktura(QWidget*)\0"
    "closeWLista()\0closeW()\0myobj\0"
    "callKomintenti(QWidget*)\0callArtikli(QWidget*)\0"
};

void QMyProFakturi::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QMyProFakturi *_t = static_cast<QMyProFakturi *>(_o);
        switch (_id) {
        case 0: _t->signCloseMyWidget(); break;
        case 1: _t->signKomintentiFromProFaktura((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 2: _t->signArtikliFromProFaktura((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 3: _t->closeWLista(); break;
        case 4: _t->closeW(); break;
        case 5: _t->callKomintenti((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 6: _t->callArtikli((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QMyProFakturi::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QMyProFakturi::staticMetaObject = {
    { &QMyBaseWidget::staticMetaObject, qt_meta_stringdata_QMyProFakturi,
      qt_meta_data_QMyProFakturi, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QMyProFakturi::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QMyProFakturi::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QMyProFakturi::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QMyProFakturi))
        return static_cast<void*>(const_cast< QMyProFakturi*>(this));
    return QMyBaseWidget::qt_metacast(_clname);
}

int QMyProFakturi::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMyBaseWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void QMyProFakturi::signCloseMyWidget()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QMyProFakturi::signKomintentiFromProFaktura(QWidget * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QMyProFakturi::signArtikliFromProFaktura(QWidget * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
