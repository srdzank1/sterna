/****************************************************************************
** Meta object code from reading C++ file 'qEmployelista.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qEmployelista.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qEmployelista.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QEmployeLista[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,
      26,   24,   14,   14, 0x05,
      67,   14,   14,   14, 0x05,
      76,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      85,   14,   14,   14, 0x08,
     119,   14,   14,   14, 0x08,
     153,   14,   14,   14, 0x08,
     200,  186,   14,   14, 0x08,
     242,   14,   14,   14, 0x08,
     266,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QEmployeLista[] = {
    "QEmployeLista\0\0closeW()\0,\0"
    "sKomintentToPriemnica(QString&,QString&)\0"
    "procF2()\0procF3()\0on_tableView_pressed(QModelIndex)\0"
    "on_tableView_clicked(QModelIndex)\0"
    "on_lineEdit_textChanged(QString)\0"
    "modelX,modelY\0selectionChanged(QModelIndex,QModelIndex)\0"
    "on_pushButton_clicked()\0"
    "on_pushButton_2_clicked()\0"
};

void QEmployeLista::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QEmployeLista *_t = static_cast<QEmployeLista *>(_o);
        switch (_id) {
        case 0: _t->closeW(); break;
        case 1: _t->sKomintentToPriemnica((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->procF2(); break;
        case 3: _t->procF3(); break;
        case 4: _t->on_tableView_pressed((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 5: _t->on_tableView_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 6: _t->on_lineEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->selectionChanged((*reinterpret_cast< QModelIndex(*)>(_a[1])),(*reinterpret_cast< QModelIndex(*)>(_a[2]))); break;
        case 8: _t->on_pushButton_clicked(); break;
        case 9: _t->on_pushButton_2_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QEmployeLista::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QEmployeLista::staticMetaObject = {
    { &QMyBaseFormWidget::staticMetaObject, qt_meta_stringdata_QEmployeLista,
      qt_meta_data_QEmployeLista, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QEmployeLista::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QEmployeLista::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QEmployeLista::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QEmployeLista))
        return static_cast<void*>(const_cast< QEmployeLista*>(this));
    return QMyBaseFormWidget::qt_metacast(_clname);
}

int QEmployeLista::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMyBaseFormWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void QEmployeLista::closeW()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QEmployeLista::sKomintentToPriemnica(QString & _t1, QString & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QEmployeLista::procF2()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void QEmployeLista::procF3()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
