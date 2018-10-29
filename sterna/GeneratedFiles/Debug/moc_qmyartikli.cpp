/****************************************************************************
** Meta object code from reading C++ file 'qmyartikli.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qmyartikli.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qmyartikli.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QMyArtikli[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      32,   11,   11,   11, 0x05,
      63,   61,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      99,   11,   11,   11, 0x0a,
     120,   11,   11,   11, 0x0a,
     134,   11,   11,   11, 0x0a,
     157,  143,   11,   11, 0x0a,
     198,   11,   11,   11, 0x0a,
     207,   11,   11,   11, 0x0a,
     216,   11,   11,   11, 0x0a,
     226,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QMyArtikli[] = {
    "QMyArtikli\0\0signCloseMyWidget()\0"
    "eCloseArtikliFromPriemnica()\0,\0"
    "eupdateNanigator(QWidget*,QWidget*)\0"
    "succesfulEntryData()\0closeWLista()\0"
    "closeW()\0text,textName\0"
    "retArtikliToPriemnica(QString&,QString&)\0"
    "procF2()\0procF3()\0procDel()\0"
    "textChanged(QString)\0"
};

void QMyArtikli::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QMyArtikli *_t = static_cast<QMyArtikli *>(_o);
        switch (_id) {
        case 0: _t->signCloseMyWidget(); break;
        case 1: _t->eCloseArtikliFromPriemnica(); break;
        case 2: _t->eupdateNanigator((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QWidget*(*)>(_a[2]))); break;
        case 3: _t->succesfulEntryData(); break;
        case 4: _t->closeWLista(); break;
        case 5: _t->closeW(); break;
        case 6: _t->retArtikliToPriemnica((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 7: _t->procF2(); break;
        case 8: _t->procF3(); break;
        case 9: _t->procDel(); break;
        case 10: _t->textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QMyArtikli::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QMyArtikli::staticMetaObject = {
    { &QMyBaseWidget::staticMetaObject, qt_meta_stringdata_QMyArtikli,
      qt_meta_data_QMyArtikli, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QMyArtikli::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QMyArtikli::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QMyArtikli::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QMyArtikli))
        return static_cast<void*>(const_cast< QMyArtikli*>(this));
    return QMyBaseWidget::qt_metacast(_clname);
}

int QMyArtikli::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMyBaseWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void QMyArtikli::signCloseMyWidget()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QMyArtikli::eCloseArtikliFromPriemnica()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void QMyArtikli::eupdateNanigator(QWidget * _t1, QWidget * _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
