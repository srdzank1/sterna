/****************************************************************************
** Meta object code from reading C++ file 'qkomintentianalitikawidget.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qkomintentianalitikawidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qkomintentianalitikawidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QKomintentiAnalitikaWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      28,   27,   27,   27, 0x05,
      65,   37,   27,   27, 0x05,

 // slots: signature, parameters, type, tag, flags
     110,   27,   27,   27, 0x08,
     144,   27,   27,   27, 0x08,
     191,  177,   27,   27, 0x08,
     233,   27,   27,   27, 0x08,
     249,   27,   27,   27, 0x08,
     266,   27,   27,   27, 0x08,
     283,   27,   27,   27, 0x08,
     300,   27,   27,   27, 0x08,
     317,   27,   27,   27, 0x08,
     334,   27,   27,   27, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QKomintentiAnalitikaWidget[] = {
    "QKomintentiAnalitikaWidget\0\0closeW()\0"
    "text,textName,textNameSaldo\0"
    "sLagerToDokument(QString&,QString&,QString&)\0"
    "on_tableView_clicked(QModelIndex)\0"
    "on_lineEdit_textChanged(QString)\0"
    "modelX,modelY\0selectionChanged(QModelIndex,QModelIndex)\0"
    "buttonClicked()\0button2Clicked()\0"
    "button3Clicked()\0button4Clicked()\0"
    "button5Clicked()\0button6Clicked()\0"
    "button7Clicked()\0"
};

void QKomintentiAnalitikaWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QKomintentiAnalitikaWidget *_t = static_cast<QKomintentiAnalitikaWidget *>(_o);
        switch (_id) {
        case 0: _t->closeW(); break;
        case 1: _t->sLagerToDokument((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 2: _t->on_tableView_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 3: _t->on_lineEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->selectionChanged((*reinterpret_cast< QModelIndex(*)>(_a[1])),(*reinterpret_cast< QModelIndex(*)>(_a[2]))); break;
        case 5: _t->buttonClicked(); break;
        case 6: _t->button2Clicked(); break;
        case 7: _t->button3Clicked(); break;
        case 8: _t->button4Clicked(); break;
        case 9: _t->button5Clicked(); break;
        case 10: _t->button6Clicked(); break;
        case 11: _t->button7Clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QKomintentiAnalitikaWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QKomintentiAnalitikaWidget::staticMetaObject = {
    { &QMyBaseFormWidget::staticMetaObject, qt_meta_stringdata_QKomintentiAnalitikaWidget,
      qt_meta_data_QKomintentiAnalitikaWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QKomintentiAnalitikaWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QKomintentiAnalitikaWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QKomintentiAnalitikaWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QKomintentiAnalitikaWidget))
        return static_cast<void*>(const_cast< QKomintentiAnalitikaWidget*>(this));
    return QMyBaseFormWidget::qt_metacast(_clname);
}

int QKomintentiAnalitikaWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMyBaseFormWidget::qt_metacall(_c, _id, _a);
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
void QKomintentiAnalitikaWidget::closeW()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QKomintentiAnalitikaWidget::sLagerToDokument(QString & _t1, QString & _t2, QString & _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
