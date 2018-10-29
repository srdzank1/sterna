/****************************************************************************
** Meta object code from reading C++ file 'qpromenaceniwidget.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qpromenaceniwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qpromenaceniwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QPromenaCeniWidget[] = {

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
      20,   19,   19,   19, 0x05,
      86,   29,   19,   19, 0x05,

 // slots: signature, parameters, type, tag, flags
     155,   19,   19,   19, 0x08,
     189,   19,   19,   19, 0x08,
     236,  222,   19,   19, 0x08,
     278,   19,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QPromenaCeniWidget[] = {
    "QPromenaCeniWidget\0\0closeW()\0"
    "text,textName,textNameSaldo,textKomintentId,textProdCena\0"
    "sPromenaCeniToDokument(QString&,QString&,QString&,QString&,QString&)\0"
    "on_tableView_clicked(QModelIndex)\0"
    "on_lineEdit_textChanged(QString)\0"
    "modelX,modelY\0selectionChanged(QModelIndex,QModelIndex)\0"
    "copyToClipBoard()\0"
};

void QPromenaCeniWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QPromenaCeniWidget *_t = static_cast<QPromenaCeniWidget *>(_o);
        switch (_id) {
        case 0: _t->closeW(); break;
        case 1: _t->sPromenaCeniToDokument((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        case 2: _t->on_tableView_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 3: _t->on_lineEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->selectionChanged((*reinterpret_cast< QModelIndex(*)>(_a[1])),(*reinterpret_cast< QModelIndex(*)>(_a[2]))); break;
        case 5: _t->copyToClipBoard(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QPromenaCeniWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QPromenaCeniWidget::staticMetaObject = {
    { &QMyBaseFormWidget::staticMetaObject, qt_meta_stringdata_QPromenaCeniWidget,
      qt_meta_data_QPromenaCeniWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QPromenaCeniWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QPromenaCeniWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QPromenaCeniWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QPromenaCeniWidget))
        return static_cast<void*>(const_cast< QPromenaCeniWidget*>(this));
    return QMyBaseFormWidget::qt_metacast(_clname);
}

int QPromenaCeniWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMyBaseFormWidget::qt_metacall(_c, _id, _a);
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
void QPromenaCeniWidget::closeW()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QPromenaCeniWidget::sPromenaCeniToDokument(QString & _t1, QString & _t2, QString & _t3, QString & _t4, QString & _t5)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
