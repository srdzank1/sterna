/****************************************************************************
** Meta object code from reading C++ file 'qddv.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qddv.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qddv.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QMyDdv[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x05,
      28,    7,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
      53,    7,    7,    7, 0x0a,
      74,    7,    7,    7, 0x0a,
      88,    7,    7,    7, 0x0a,
      99,   97,    7,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QMyDdv[] = {
    "QMyDdv\0\0signCloseMyWidget()\0"
    "eCloseDdvFromPriemnica()\0succesfulEntryData()\0"
    "closeWLista()\0closeW()\0,\0"
    "retKomintentToPriemnica(QString&,QString&)\0"
};

void QMyDdv::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QMyDdv *_t = static_cast<QMyDdv *>(_o);
        switch (_id) {
        case 0: _t->signCloseMyWidget(); break;
        case 1: _t->eCloseDdvFromPriemnica(); break;
        case 2: _t->succesfulEntryData(); break;
        case 3: _t->closeWLista(); break;
        case 4: _t->closeW(); break;
        case 5: _t->retKomintentToPriemnica((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QMyDdv::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QMyDdv::staticMetaObject = {
    { &QMyBaseWidget::staticMetaObject, qt_meta_stringdata_QMyDdv,
      qt_meta_data_QMyDdv, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QMyDdv::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QMyDdv::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QMyDdv::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QMyDdv))
        return static_cast<void*>(const_cast< QMyDdv*>(this));
    return QMyBaseWidget::qt_metacast(_clname);
}

int QMyDdv::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMyBaseWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void QMyDdv::signCloseMyWidget()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QMyDdv::eCloseDdvFromPriemnica()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
