/****************************************************************************
** Meta object code from reading C++ file 'qAnalitikaKomintentiwidget.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qAnalitikaKomintentiwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qAnalitikaKomintentiwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QAnalitikaKomintentiWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      28,   27,   27,   27, 0x05,
      65,   37,   27,   27, 0x05,

 // slots: signature, parameters, type, tag, flags
     124,   27,   27,   27, 0x08,
     158,   27,   27,   27, 0x08,
     205,  191,   27,   27, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QAnalitikaKomintentiWidget[] = {
    "QAnalitikaKomintentiWidget\0\0closeW()\0"
    "text,textName,textNameSaldo\0"
    "sAnalitikaKomintentiToDokument(QString&,QString&,QString&)\0"
    "on_tableView_clicked(QModelIndex)\0"
    "on_lineEdit_textChanged(QString)\0"
    "modelX,modelY\0selectionChanged(QModelIndex,QModelIndex)\0"
};

void QAnalitikaKomintentiWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QAnalitikaKomintentiWidget *_t = static_cast<QAnalitikaKomintentiWidget *>(_o);
        switch (_id) {
        case 0: _t->closeW(); break;
        case 1: _t->sAnalitikaKomintentiToDokument((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 2: _t->on_tableView_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 3: _t->on_lineEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->selectionChanged((*reinterpret_cast< QModelIndex(*)>(_a[1])),(*reinterpret_cast< QModelIndex(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QAnalitikaKomintentiWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QAnalitikaKomintentiWidget::staticMetaObject = {
    { &QMyBaseFormWidget::staticMetaObject, qt_meta_stringdata_QAnalitikaKomintentiWidget,
      qt_meta_data_QAnalitikaKomintentiWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QAnalitikaKomintentiWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QAnalitikaKomintentiWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QAnalitikaKomintentiWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QAnalitikaKomintentiWidget))
        return static_cast<void*>(const_cast< QAnalitikaKomintentiWidget*>(this));
    return QMyBaseFormWidget::qt_metacast(_clname);
}

int QAnalitikaKomintentiWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMyBaseFormWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void QAnalitikaKomintentiWidget::closeW()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QAnalitikaKomintentiWidget::sAnalitikaKomintentiToDokument(QString & _t1, QString & _t2, QString & _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
